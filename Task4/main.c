/************************************************************************************
 *
 * [FILE NAME] : main.c
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
    uint8 choice;
    uint8 result;
    uint8 answer;
    uint8 terminal_status;
    terminal_Data.maxTransAmount = MAX_AMOUNT_PER_DATE;

	/********************************************************************************
	 *                         APPLICATION	(SUPER LOOP)			        *
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
                answer = send_DataToServer();

                if(answer == APPROVED)
                {
                    printf("\nThe transaction is APPROVED.\n");
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

    printf("\nDo you want to continue (y/n)?: ");

    }while( (choice = getchar()) != '\n' && choice != 'n');

	return 0;
}
