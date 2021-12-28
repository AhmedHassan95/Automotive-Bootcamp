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
#include <string.h>
#include <stdlib.h>
#include "std_types.h"

#define MAX_AMOUNT_PER_DATE 5000
#define MAX_USERS           10
#define OK                  1
#define N_OK                0
#define FOUND               1
#define NOT_FOUND           0
#define IDENTICAL           0

/************************************************************************************
 *                                  DATA TYPES                                      *
 ************************************************************************************/

 typedef enum EN_transStat_t
{
	DECLINED,
	APPROVED
}EN_transStat_t;


typedef struct ST_cardData_t
{
	uint8 cardHolderName[25];
	uint8 primaryAccountNumber[20];
	uint8 cardExpirationDate[6];
}ST_cardData_t;


typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
	uint8 transAmountDate[11];
}ST_terminalData_t;


typedef struct ST_accountBalance_t
{
	float balance;
	uint8 primaryAccountNumber[20];
}ST_accountBalance_t;


typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t transData;
	EN_transStat_t transStat;
}ST_transaction_t;


/************************************************************************************
 *                                GLOBAL VARIABLES                                  *
 ************************************************************************************/

extern EN_transStat_t tras_state;

extern ST_cardData_t user_cardData;

extern ST_terminalData_t terminal_Data;

extern ST_transaction_t transaction_Data;

extern ST_accountBalance_t accountBalance[10];

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void get_userInput(void);
bool get_terminalInput(void);
bool check_cardValidity(void);
bool send_DataToServer(void);
bool Linear_Search(uint8 * account_number, float amount);

#endif /* APPLICATION_FUNCTIONS_H_ */
