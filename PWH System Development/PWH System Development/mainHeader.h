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
	LOAD_ORDER,
	LOAD_PARTS,
	LOAD_CUSTOMER,
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


//Prototypes

errno_t openFile(FILE** file, const char* filename, const char* mode);
void closeFile(FILE* file);
char* getFilePath();
void loadOrderDB();
void loadPartsDB();
void loadCustomerDB();
void loadAllDatabases();
void ValidateAndPrintOrder(const char* lineBuffer);
void listValidParts(const char* lineBuffer);
void ValidateAndPrintCustomer(const char* lineBuffer);
void logEvent(const char* logLevel, const char* message);
void mainMenu(void);
int getValidIntegerInput(int max_choice);
void displayMainMenu(void);
int matchesRegex(const char* pattern, const char* str);