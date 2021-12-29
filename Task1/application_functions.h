/******************************************************************************
 *
 * [MODULE]: APPLICATION
 *
 * [FILE NAME]: application_functions.h
 *
 * [DESCRIPTION]: Header file for the Application Functions
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef APPLICATION_FUNCTIONS_H_
#define APPLICATION_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "std_types.h"

#define PLAYER1         1
#define PLAYER2         2
#define WINNING_PLAYER  1
#define IN_PROGRESS    -1
#define NO_EMPTY_PLACE  0

/************************************************************************************
 *                                GLOBAL VARIABLES                                  *
 ************************************************************************************/

extern char player1[20];
extern char player2[20];
extern uint8 board[9];

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void create_board(void);
uint8 draw_userChoice(uint16 choice, uint8 pattern);
sint8 check_winner(void);

#endif /* APPLICATION_FUNCTIONS_H_ */
