/************************************************************************************
 *
 * [FILE NAME] : Payment_System.c
 *
 * [AUTHOR(S)] : Ahmed Hassan
 *
 * [DATE CREATED] : DEC 22, 2021
 *
 * [DESCRIPTION] : This Project is to design an ATM application
 *
 ************************************************************************************/

 #include "application_functions.h"

/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

int main(void)
{
    uint8_t choice; /* Local variable to store user choice */
    uint8_t result; /* Local variable to store card validity status */
    uint8_t answer; /* Local variable to store server response */
    uint8_t terminal_status;    /* Local variable to store terminal status */
    terminal_Data.maxTransAmount = MAX_AMOUNT_PER_DATE;     /* Define Maximum Amount per day */

	/********************************************************************************
	 *                          APPLICATION	(SUPER LOOP)			        *
	 ********************************************************************************/

    do
    {
        get_userInput();
        terminal_status = get_terminalInput();

        if(terminal_status == APPROVED)
        {
            printf("\nVerifying Data from the server.....\n");

            /* Check is the card is expired or not */
            result = check_cardValidity();

            if(result == APPROVED)
            {
                /* Send transaction data to the server */
                /* Check if the Account number is found or not */
                /* Check the amount is less than the balance */
                answer = send_dataToServer();

                if(answer == APPROVED)
                {
                    printf("\nThe transaction is APPROVED.\n");
                    printf("Your Balance Now Is : %0.2f L.E\n", accountBalance[g8_Index].balance);
                }
                else
                {
                    printf("\nThe transaction is DECLINED!!!\n");
                }
            }
            else
            {
                printf("\nThe transaction is DECLINED!!!\n");
            }
        }
        else
        {
            printf("\nThe transaction is DECLINED!!!\n");
        }

    /* Ask user if he/she needed to perform another process */
    printf("\nDo you want to continue (y/n)?: ");

    }while( ((choice = getchar()) != '\n') && (choice != 'n') && (choice != 'N'));

	return 0;
}
