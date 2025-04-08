#pragma once

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include <direct.h>

//Constants
#define MAX_PATH_LEN 260
#define _CRT_SECURE_NO_WARNINGS

//Structs


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

