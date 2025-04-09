#include "mainHeader.h" 


//
// FUNCTION    : listValidParts
// DESCRIPTION : Accepts a line from the parts database, tokenizes it using strtok_s with the pipe ('|') delimiter,
//               counts the fields, and prints the record if exactly 7 fields are found.
// PARAMETERS  : const char* lineBuffer
// RETURNS     : None
//
void listValidParts(const char* lineBuffer)
{
    int tokenCount = 0;
    char tempLine[300];
    char* context = NULL;

    //Makes a copy of the line because strtok_s will change it.
    strncpy_s(tempLine, lineBuffer, sizeof(tempLine));
    tempLine[sizeof(tempLine) - 1] = '\0';

    //Breaks the line into pieces using '|'
    char* token = strtok_s(tempLine, "|", &context);
    while (token != NULL) {
        tokenCount++;

        token = strtok_s(NULL, "|", &context);
    }

    // Check if the record has exactly 7 fields so that it passes as valid, if not its invalid.
    if (tokenCount == 7) {
        printf("Valid Part: %s\n", lineBuffer);

        //log message
        logEvent("INFO", "Part record processed successfully.");
    }
    else {
        printf("Invalid Part: %s (Token Count: %d)\n", lineBuffer, tokenCount);
        
        //log message
        logEvent("WARNING", "Part record invalid - incorrect token count.");
    }
}