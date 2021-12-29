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

char player1[20];
char player2[20];
uint8 board[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8'};

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


sint8 check_winner(void)
{
    if (board[0] == board[1] && board[1] == board[2])
    {
        return WINNING_PLAYER;
    }
    else if (board[3] == board[4] && board[4] == board[5])
    {
        return WINNING_PLAYER;
    }
    else if (board[6] == board[7] && board[7] == board[8])
    {
        return WINNING_PLAYER;
    }
    else if (board[0] == board[3] && board[3] == board[6])
    {
        return WINNING_PLAYER;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return WINNING_PLAYER;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return WINNING_PLAYER;
    }
    else if (board[0] == board[4] && board[4] == board[8])
    {
        return WINNING_PLAYER;
    }
    else if (board[2] == board[4] && board[4] == board[6])
    {
        return WINNING_PLAYER;
    }
    else if (board[0] != '0' && board[1] != '1' && board[2] != '2' &&
             board[3] != '3' && board[4] != '4' && board[5] != '5' &&
             board[6] != '6' && board[7] != '7' && board[8] != '8')
    {
        return NO_EMPTY_PLACE;   /* No empty place to play, please restart the game */
    }
    else
    {
        return  IN_PROGRESS;    /* Game in progress */
    }
}

uint8 draw_userChoice(uint16 choice, uint8 pattern)
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
        return NO_EMPTY_PLACE;
    }
    return TRUE;
}
