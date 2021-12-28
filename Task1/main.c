/************************************************************************************
 *
 * [FILE NAME] : main.c
 *
 * [AUTHOR(S)] : Ahmed Hassan.
 *
 * [DATE CREATED] :	DEC 22, 2021
 *
 * [DESCRIPTION] :	This Project is to design X - O game between two players
 *
 ************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PLAYER1 1
#define PLAYER2 2
#define TRUE 1
#define FALSE 0

/************************************************************************************
 *                                GLOBAL VARIABLES                                  *
 ************************************************************************************/

char player1[20];
char player2[20];
char board[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8'};

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void create_board(void);
int draw_userChoice(int choice, char pattern);
int check_winner(void);

/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

int main(void)
{
    int player_turn = PLAYER1;
    int choice, winner, result;
    char pattern;


    printf("\n-----------------------------------------\n");
    printf("|\t\t X - O Game\t\t|");
    printf("\n-----------------------------------------\n");

    printf("\nPlease enter Player1 name: ");
    gets(player1);
    printf("Please enter Player2 name: ");
    gets(player2);

    printf("\n%s => 'X'\n", player1);
    printf("\n%s => 'O'\n", player2);

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
        scanf("%d", &choice);

        result = draw_userChoice(choice, pattern);

        if(result == FALSE)
        {
            player_turn--;
            getch();
        }

        winner = check_winner();

        player_turn++;

    }while (winner ==  - 1);


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

/************************************************************************************
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

void create_board(void)
{
    system("cls");
    printf("\n---------------------------------\n");
    printf("|\t X - O Game\t\t|");
    printf("\n---------------------------------\n");

    printf("\n   %s (X)  -  %s (O)\n\n\n", player1, player2);

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c \n", board[6], board[7], board[8]);

    printf("\t     |     |     \n\n");
}


int check_winner(void)
{
    if (board[0] == board[1] && board[1] == board[2])
    {
        return 1;
    }
    else if (board[3] == board[4] && board[4] == board[5])
    {
        return 1;
    }
    else if (board[6] == board[7] && board[7] == board[8])
    {
        return 1;
    }
    else if (board[0] == board[3] && board[3] == board[6])
    {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    else if (board[0] == board[4] && board[4] == board[8])
    {
        return 1;
    }
    else if (board[2] == board[4] && board[4] == board[6])
    {
        return 1;
    }
    else if (board[0] != '0' && board[1] != '1' && board[2] != '2' &&
             board[3] != '3' && board[4] != '4' && board[5] != '5' &&
             board[6] != '6' && board[7] != '7' && board[8] != '8')
    {
        return 0;   /* No empty place to play, please restart the game */
    }
    else
    {
        return  - 1;    /* Game in progress */
    }
}

int draw_userChoice(int choice, char pattern)
{
    if (choice == 0 && board[0] == '0')
    {
        board[0] = pattern;
    }
    else if (choice == 1 && board[1] == '1')
    {
        board[1] = pattern;
    }
    else if (choice == 2 && board[2] == '2')
    {
        board[2] = pattern;
    }
    else if (choice == 3 && board[3] == '3')
    {
        board[3] = pattern;
    }
    else if (choice == 4 && board[4] == '4')
    {
        board[4] = pattern;
    }
    else if (choice == 5 && board[5] == '5')
    {
        board[5] = pattern;
    }
    else if (choice == 6 && board[6] == '6')
    {
        board[6] = pattern;
    }
    else if (choice == 7 && board[7] == '7')
    {
        board[7] = pattern;
    }
    else if (choice == 8 && board[8] == '8')
    {
        board[8] = pattern;
    }
    else
    {
        printf("Invalid move !!!, Press any key to continue\n");
        return 0;
    }
    return 1;
}
