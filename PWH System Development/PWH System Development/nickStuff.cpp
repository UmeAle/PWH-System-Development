#include "mainHeader.h"
// FILE        : nickStuff.cpp
// DESCRIPTION : Contains the functions to open, load, and close files.
// AUTHOR      : Nick Reilly
// DATE        : 04/09/2025



//
// FUNCTION : openFile
// DESCRIPTION : This function finds the assigned file it needs to open and opens it. 
// PARAMETERS : The file pointer to the address of the file pointer, the name of the file (const char array pointer), and the mode it will be opening it in (const char pointer).
// RETURNS : err, a constant error value, that will the be evaluated in main for errors.
//
errno_t openFile(FILE** file, const char* filename, const char* mode) {
    errno_t err = fopen_s(file, filename, mode);
    if (err != 0 || *file == NULL) {
        perror("Error opening file");
        logEvent("ERROR", "Error opening file.");
        return NULL;
    }
    return err;
}

//
// FUNCTION : closeFile
// DESCRIPTION : This function closes the already opened file. 
// PARAMETERS : file, the reference file that the file pointer is pointing to. 
// RETURNS : none.
//
void closeFile(FILE* file) {
    if (file) {
        fclose(file);
    }
}

//
// FUNCTION : loadOrderDB
// DESCRIPTION : Prompts the user for a file path, opens the file, reads each line, and processes it.
// PARAMETERS : None
// RETURNS : char** (pointer to an array of strings).
//
char** loadOrderDB(void) {
    printf("Loading Order Database...\n");
    logEvent("INFO", "Loading Order Database: Started.");

    //Open the file
    FILE* file = NULL;
    if (openFile(&file, "orders.db", "r") != 0 || !file) {
        logEvent("ERROR", "Failed to open orders.db file.");
        return NULL;
    }

    //Initliaze variables for appending the line buffer into array
    int capacity = 10;
    int count = 0;
    char** lines = (char**)malloc(capacity * sizeof(char*));
    char lineBuffer[300];

    //Read the file line by line
    while (fgets(lineBuffer, sizeof(lineBuffer), file)) {
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
        }

        if (count >= capacity) {
            capacity *= 2;
            lines = (char**)realloc(lines, capacity * sizeof(char*));
        }

        lines[count] = (char*)malloc(strlen(lineBuffer) + 1);
        strcpy_s(lines[count], strlen(lineBuffer) + 1, lineBuffer);
        count++;
    }

    //Close it
    closeFile(file);
    logEvent("INFO", "Loading Order Database: Completed.");

    //Null termiante the index and the array
    lines = (char**)realloc(lines, (count + 1) * sizeof(char*));
    lines[count] = NULL;
    return lines;
}

//
// FUNCTION : loadCustomerDB
// DESCRIPTION : Prompts user for a customer database file, opens it, reads line by line, and processes each line.
// PARAMETERS : None currently?
// RETURNS : char** (pointer to an array of strings).
//
char** loadCustomerDB(void) {
    printf("Loading Customer Database...\n");
    logEvent("INFO", "Loading Customer Database: Started.");

    //Open the file
    FILE* file = NULL;
    if (openFile(&file, "customers.db", "r") != 0 || !file) {
        logEvent("ERROR", "Failed to open customers.db file.");
        return NULL;
    }

    //Initialize variables for appending the line buffer into array
    int capacity = 10;
    int count = 0;
    char** lines = (char**)malloc(capacity * sizeof(char*));
    char lineBuffer[300];

    //Read the file line by line
    while (fgets(lineBuffer, sizeof(lineBuffer), file)) {
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
        }

        if (count >= capacity) {
            capacity *= 2;
            lines = (char**)realloc(lines, capacity * sizeof(char*));
        }

        lines[count] = (char*)malloc(strlen(lineBuffer) + 1);
        strcpy_s(lines[count], strlen(lineBuffer) + 1, lineBuffer);
        count++;
    }

    //Close it
    closeFile(file);
    logEvent("INFO", "Loading Customer Database: Completed.");

    //Null terminate the index and the array
    lines = (char**)realloc(lines, (count + 1) * sizeof(char*));
    lines[count] = NULL;
    return lines;
}

//
// FUNCTION : loadPartsDB
// DESCRIPTION : Prompts user for the parts database file, opens it, and reads line by line for processing.
// PARAMETERS : None.
// RETURNS : char** (pointer to an array of strings).
//
char** loadPartsDB(void) {
    printf("Loading Parts Database...\n");
    logEvent("INFO", "Loading Parts Database: Started.");

    //Open the file
    FILE* file = NULL;
    if (openFile(&file, "parts.db", "r") != 0 || !file) {
        logEvent("ERROR", "Failed to open parts.db file.");
        return NULL;
    }

    //Initialize variables for appending the line buffer into array
    int capacity = 10;
    int count = 0;
    char** lines = (char**)malloc(capacity * sizeof(char*));
    char lineBuffer[300];

    //Read the file line by line
    while (fgets(lineBuffer, sizeof(lineBuffer), file)) {
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
        }

        if (count >= capacity) {
            capacity *= 2;
            lines = (char**)realloc(lines, capacity * sizeof(char*));
        }

        lines[count] = (char*)malloc(strlen(lineBuffer) + 1);
        strcpy_s(lines[count], strlen(lineBuffer) + 1, lineBuffer);
        count++;
    }

    //Close it
    closeFile(file);
    logEvent("INFO", "Loading Parts Database: Completed.");

    //Null terminate the index and the array
    lines = (char**)realloc(lines, (count + 1) * sizeof(char*)); // Ensure null-termination
    lines[count] = NULL; // Null-terminate the array
    return lines;
}

//
// FUNCTION : freeLines
// DESCRIPTION : Frees the memory allocated for the lines array.
// PARAMETERS : lines, the array of strings to be freed, and count, the number of lines.
// RETURNS : None.
void freeLines(char** lines, int count) {
    for (int i = 0; i < count; ++i) {
        free(lines[i]);
    }
    free(lines);
}
