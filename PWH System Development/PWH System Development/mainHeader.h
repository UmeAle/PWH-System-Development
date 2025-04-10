#pragma once

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <direct.h>
#include <time.h>

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


//Structs


//Prototypes

errno_t openFile(FILE** file, const char* filename, const char* mode);
void closeFile(FILE* file);
char* getFilePath();
char** loadOrderDB();
char** loadPartsDB();
char** loadCustomerDB();
void ValidateAndPrintOrders(const char* lineBuffer);
void ValidateAndPrintParts(const char* lineBuffer);
void ValidateAndPrintCustomers(const char* lineBuffer);
void logEvent(const char* logLevel, const char* message);
void mainMenu(void);
int getValidIntegerInput(int max_choice);
void displayMainMenu(void);