#include "mainHeader.h"


// FUNCTION    : ValidateAndPrintCustomer
// DESCRIPTION : Checks if a single customer record has exactly 9 fields
//               (separated by '|') and prints it if valid.
// PARAMETERS  : const char* lineBuffer - The raw line from customers.db
// RETURNS     : None
void ValidateAndPrintCustomer(const char* lineBuffer)
{
    int fieldCount = 0;
    char tempLine[300];
    char* context = NULL;

    //Make a copy of the original line to avoid modifying it directly
    strncpy_s(tempLine, lineBuffer, sizeof(tempLine));
    tempLine[sizeof(tempLine) - 1] = '\0';

    //Tokenize using the '|' thing (Pipe, I guess)
    char* token = strtok_s(tempLine, "|", &context);
    while (token != NULL) {
        fieldCount++;
        token = strtok_s(NULL, "|", &context);
    }

    //If it has exactly 9 fields, it's considered valid
    if (fieldCount == 9) {
        printf("Valid Customer: %s\n", lineBuffer);
    }
    else {
        printf("Invalid Customer: %s (Fields found: %d)\n", lineBuffer, fieldCount);
    }
}
