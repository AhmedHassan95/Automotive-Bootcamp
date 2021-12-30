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

uint8_t g8_Index;

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
    printf("\nThe Maximum Amount per Day is 5000 L.E");
    return N_OK;
}


bool check_cardValidity(void)
{
    sint8_t result;
    uint8_t Date[6];

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
    printf("\nCARD IS EXPIRED");
    return N_OK;
}


bool send_dataToServer(void)
{
    uint8_t result;

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
    result = Linear_search(transaction_Data.cardHolderData.primaryAccountNumber,
                           transaction_Data.transData.transAmount);

    if(result == TRUE)
    {
        return APPROVED;
    }
    return DECLINED;
}


bool Linear_search(uint8_t * account_number, float32_t amount)
{
   uint8_t index;
   uint8_t result;

   for(index = 0; index < MAX_USERS ;index++)
   {
       result = strcmp((char *)accountBalance[index].primaryAccountNumber, (char *)account_number);

       if(result == IDENTICAL)
       {
           if(accountBalance[index].balance >= amount)
           {
               /* Update the user account balance after discount the amount */
               accountBalance[index].balance = accountBalance[index].balance - amount;
               /* Store the address of the card found in the database in a global Index */
               g8_Index = index;
               /* PAN is found in the database, and the balance is larger than the Amount */
               return FOUND;
           }
           /* PAN is found in the database, but the balance is smaller than the Amount */
	       printf("\nInsufficient balance...");
	       return NOT_FOUND;
       }
   }
    printf("\nThere are no Data for your Card, Please Contact the Bank.");
    return NOT_FOUND;	/* PAN is not found in the database */
}

