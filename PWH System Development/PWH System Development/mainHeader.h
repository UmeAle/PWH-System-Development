#pragma once

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>

//Constants
#define MAX_PATH_LEN 260

//Structs


//Prototypes
errno_t openFile(FILE** file, const char* filename, const char* mode);
void closeFile(FILE* file);
char* getFilePath();
void loadOrderDB();
void loadPartsDB();
void loadCustomerDB();
void loadAllDatabases();