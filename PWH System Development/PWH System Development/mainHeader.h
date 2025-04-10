#pragma once

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <direct.h>
#include <time.h>

//CPP libraries
#include <iostream>
#include <regex>

//Constants
#define MAX_PATH_LEN 260
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LOG_LENGTH 256

//ENUMS
typedef enum {
	LOAD_DATABASE = 1,
	LIST_CUSTOMER,
	LIST_PART,
	LIST_ORDER,
	EXIT,
} menuOptions;


//Regex Pattern
static const char* RX_NAME = R"(^.{1,50}$)";      
static const char* RX_ADDRESS = R"(^.{1,100}$)";    
static const char* RX_CITY = R"(^.{1,100}$)";
static const char* RX_PROVINCE = R"(^[A-Z]{2}$)";
static const char* RX_POSTAL = R"(^[A-Za-z]\d[A-Za-z]\d[A-Za-z]\d$)";
static const char* RX_PHONE = R"(^\d{3}-\d{3}-\d{4}$)";
static const char* RX_EMAIL = R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)";
static const char* RX_ID = R"(^(?:[1-9]\d*)$)";
static const char* RX_MONEY_POS = R"(^(?:\d+(?:\.\d{1,2})?)$)";
static const char* RX_MONEY_NONNEG = R"(^(?:\d+(?:\.\d{1,2})?)$)";
static const char* RX_DATE = R"(^(?:\d{4}-\d{2}-\d{2})$)";
static const char* RX_DATE_OPT = R"(^$|^\d{4}-\d{2}-\d{2}$)";

//regex too
static const char* RX_PART_COST = R"(^(?!0+(?:\.0+)?$)\d+(\.\d{1,2})?$)";
static const char* RX_PART_QUANTITY = R"(^(0|[1-9][0-9]*)$)";
static const char* RX_PART_STATUS = R"(^-?\d+$)";

//more regex
static const char* RX_OR_STATUS = R"(^[0-9]+$)";
static const char* RX_OR_TOTAL = R"(^[0-9]+(\.[0-9]{1,2})?$)";
static const char* RX_PARTS = R"(^[1-9][0-9]*$)";

//Prototypes

errno_t openFile(FILE** file, const char* filename, const char* mode);
void closeFile(FILE* file);
char** loadOrderDB();
char** loadPartsDB();
char** loadCustomerDB();
void ValidateAndPrintOrder(char** lineBuffer);
void ValidateAndPrintPart(char** lineBuffer);
void ValidateAndPrintCustomer(char** lineBuffer);
void logEvent(const char* logLevel, const char* message);
void mainMenu(void);
int getValidIntegerInput(int max_choice);
void displayMainMenu(void);
int matchesRegex(const char* pattern, const char* str);