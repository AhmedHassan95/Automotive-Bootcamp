/******************************************************************************
 *
 * [MODULE]: APPLICATION
 *
 * [FILE NAME]: application_functions.h
 *
 * [DESCRIPTION]: Source file for the Application Functions
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "application_functions.h"

/************************************************************************************
 *                                GLOBAL VARIABLES                                  *
 ************************************************************************************/

EN_transStat_t tras_state;

ST_cardData_t user_cardData;

ST_terminalData_t terminal_Data;

ST_transaction_t transaction_Data;

ST_accountBalance_t accountBalance[10] = {{100.00, "123456789"}, {6000.00, "234567891"},
					  {3250.25, "567891234"}, {1500.12, "456789123"}, 
					  {500.00, "258649173"}, {2100.00, "654823719"}, 
					  {0.00, "971362485"}, {1.00, "793148625"}, 
					  {10.12, "123123456"}, {0.55, "456789321"}
                                          };

/************************************************************************************
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

void get_userInput(void)
{
    fflush(stdin);
    system("cls");

    printf("\n-----------------------------------------\n");
    printf("|\tWelcome to ATM Banking\t\t|");
    printf("\n-----------------------------------------\n");

    printf("\nPlease Enter Card Data: \n\n");

    printf("Please Enter the Card Holder Name: ");
    gets((char *)user_cardData.cardHolderName);
    printf("Please Enter the Primary Account Number: ");
    gets((char *)user_cardData.primaryAccountNumber);
    printf("Please Enter Card Expiry Date in Formate MM/YY: ");
    gets((char *)user_cardData.cardExpirationDate);
}


bool get_terminalInput(void)
{
    printf("\n\nPlease Enter Terminal Data: \n\n");

    printf("Please Enter the transaction Amount: ");
    scanf("%f", &terminal_Data.transAmount);
    getchar();

    /* Check is the amount exceeded the maximum amount limit per day or not */
    if(terminal_Data.maxTransAmount >= terminal_Data.transAmount)
    {
        printf("Please Enter transaction Date in Formate DD/MM/YY: ");
        gets((char *)terminal_Data.transAmountDate);
        return OK;
    }
    return N_OK;
}


bool check_cardValidity(void)
{
    uint8 result;
    uint8 Date[6];

    Date[0] = terminal_Data.transAmountDate[3];
    Date[1] = terminal_Data.transAmountDate[4];
    Date[2] = '/';
    Date[3] = terminal_Data.transAmountDate[8];
    Date[4] = terminal_Data.transAmountDate[9];
    Date[5] = '\0';

    result = strcmp((char *)user_cardData.cardExpirationDate, (char *)Date);

    if(result >= IDENTICAL)
    {
        return OK;
    }
    return N_OK;
}


bool send_DataToServer(void)
{
    uint8 result;

    /*
     * First, Send the data taken from the user to the server:
     *  - User Account Name
     *  - Card Expiration Date
     *  - Card Holder Name
     */

    /* Send the user primary account number to the server */
    strcpy((char *)transaction_Data.cardHolderData.primaryAccountNumber,
           (char *)user_cardData.primaryAccountNumber);

    /* Send the card expiration date to the server */
    strcpy((char *)transaction_Data.cardHolderData.cardExpirationDate,
           (char *)user_cardData.cardExpirationDate);

    /* Send the user name to the server */
    strcpy((char *)transaction_Data.cardHolderData.cardHolderName,
           (char *)user_cardData.cardHolderName);

    /*
     * Second, Send the data taken from the terminal to the server:
     *  - Transaction date
     *  - Transaction Amount
     */

    /* Send the terminal transaction date to the server */
    strcpy((char *)transaction_Data.transData.transAmountDate,
           (char *)terminal_Data.transAmountDate);

    /* Send the terminal transaction amount to the server */
    transaction_Data.transData.transAmount = terminal_Data.transAmount;


    /*
     * Then, Search for these data in the server, and return the result of search
     */
    result = Linear_Search(transaction_Data.cardHolderData.primaryAccountNumber,
                           transaction_Data.transData.transAmount);

    if(result == TRUE)
    {
        return APPROVED;
    }
    return DECLINED;
}


bool Linear_Search(uint8 * account_number, float amount)
{
   uint8 index;
   uint8 result;

   for(index = 0; index < MAX_USERS ;index++)
   {
       result = strcmp((char *)accountBalance[index].primaryAccountNumber, (char *)account_number);

       if(result == IDENTICAL)
       {
           if((int)accountBalance[index].balance >= (int)amount)
           {
               /* PAN is found in the database, and the balance is larger than the Amount */
		   return FOUND; 
           }
           /* PAN is found in the database, but the balance is smaller than the Amount */
	       return NOT_FOUND;	
       }
   }
    return NOT_FOUND;	/* PAN is not found in the database */
}

