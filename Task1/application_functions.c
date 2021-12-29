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

uint8_t player1[20];
uint8_t player2[20];
uint8_t gau8_board[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8'};

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
    printf("\t  %c  |  %c  |  %c \n", gau8_board[0], gau8_board[1], gau8_board[2]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c \n", gau8_board[3], gau8_board[4], gau8_board[5]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c \n", gau8_board[6], gau8_board[7], gau8_board[8]);

    printf("\t     |     |     \n\n");
}


sint8_t check_winner(void)
{
    if (gau8_board[0] == gau8_board[1] && gau8_board[1] == gau8_board[2])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[3] == gau8_board[4] && gau8_board[4] == gau8_board[5])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[6] == gau8_board[7] && gau8_board[7] == gau8_board[8])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[0] == gau8_board[3] && gau8_board[3] == gau8_board[6])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[1] == gau8_board[4] && gau8_board[4] == gau8_board[7])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[2] == gau8_board[5] && gau8_board[5] == gau8_board[8])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[0] == gau8_board[4] && gau8_board[4] == gau8_board[8])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[2] == gau8_board[4] && gau8_board[4] == gau8_board[6])
    {
        return WINNING_PLAYER;
    }
    else if (gau8_board[0] != '0' && gau8_board[1] != '1' && gau8_board[2] != '2' &&
             gau8_board[3] != '3' && gau8_board[4] != '4' && gau8_board[5] != '5' &&
             gau8_board[6] != '6' && gau8_board[7] != '7' && gau8_board[8] != '8')
    {
        return NO_EMPTY_PLACE;   /* No empty place to play, please restart the game */
    }
    else
    {
        return  IN_PROGRESS;    /* Game in progress */
    }
}

uint8_t draw_userChoice(uint16_t choice, uint8_t pattern)
{
    if (choice == 0 && gau8_board[0] == '0')
    {
        gau8_board[0] = pattern;
    }
    else if (choice == 1 && gau8_board[1] == '1')
    {
        gau8_board[1] = pattern;
    }
    else if (choice == 2 && gau8_board[2] == '2')
    {
        gau8_board[2] = pattern;
    }
    else if (choice == 3 && gau8_board[3] == '3')
    {
        gau8_board[3] = pattern;
    }
    else if (choice == 4 && gau8_board[4] == '4')
    {
        gau8_board[4] = pattern;
    }
    else if (choice == 5 && gau8_board[5] == '5')
    {
        gau8_board[5] = pattern;
    }
    else if (choice == 6 && gau8_board[6] == '6')
    {
        gau8_board[6] = pattern;
    }
    else if (choice == 7 && gau8_board[7] == '7')
    {
        gau8_board[7] = pattern;
    }
    else if (choice == 8 && gau8_board[8] == '8')
    {
        gau8_board[8] = pattern;
    }
    else
    {
        printf("Invalid move !!!, Press any key to continue\n");
        return NO_EMPTY_PLACE;
    }
    return TRUE;
}
