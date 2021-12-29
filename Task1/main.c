/************************************************************************************
 *
 * [FILE NAME] : main.c
 *
 * [AUTHOR(S)] : Ahmed Hassan.
 *
 * [DATE CREATED] : DEC 22, 2021
 *
 * [DESCRIPTION] : This Project is to design X - O game between two players
 *
 ************************************************************************************/

#include "application_functions.h"

/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

int main(void)
{
    uint8 player_turn = PLAYER1;
    uint8 result, pattern;
    sint8 winner;
    uint16 choice;

    printf("\n-----------------------------------------\n");
    printf("|\t\t X - O Game\t\t|");
    printf("\n-----------------------------------------\n");

    printf("\nPlease enter Player1 name: ");
    gets(player1);
    printf("Please enter Player2 name: ");
    gets(player2);

    printf("\n%s => 'X'\n", player1);
    printf("\n%s => 'O'\n", player2);

	/********************************************************************************
	 *                         APPLICATION	(SUPER LOOP)				*
	 ********************************************************************************/

    do
    {
        create_board();

        if(player_turn % 2)
        {
            player_turn = PLAYER1;
            pattern = 'X';
        }
        else
        {
            player_turn = PLAYER2;
            pattern = 'O';
        }

        printf("\nPlease enter a number,  ");
        scanf("%hu", &choice);

        result = draw_userChoice(choice, pattern);

        if(result == FALSE)
        {
            player_turn--;
            getch();
        }

        winner = check_winner();

        player_turn++;

    }while (winner == IN_PROGRESS);


    create_board();

    if (winner == TRUE)
    {
        player_turn--;

        if(player_turn == PLAYER1)
        {
            printf("\aCongratulations, %s win the Game\n", player1);
        }
        else
        {
            printf("\aCongratulations, %s win the Game\n", player2);
        }
    }
    else
    {
        printf("No empty place to play, Please restart the game.\n");
    }

    getch();

	return 0;
}

