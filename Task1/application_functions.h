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

extern uint8_t player1[20];
extern uint8_t player2[20];
extern uint8_t gau8_board[9];

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void create_board(void);
uint8_t draw_userChoice(uint16_t choice, uint8_t pattern);
sint8_t check_winner(void);

#endif /* APPLICATION_FUNCTIONS_H_ */
