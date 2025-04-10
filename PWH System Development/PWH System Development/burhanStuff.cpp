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
    char* tokens[7]; 
	char log_message[MAX_LOG_LENGTH];

    //Makes a copy of the line because strtok_s will change it.
    strncpy_s(tempLine, lineBuffer, sizeof(tempLine));
    tempLine[sizeof(tempLine) - 1] = '\0';

    //Breaks the line into pieces using '|'
    char* token = strtok_s(tempLine, "|", &context);
    while (token != NULL && tokenCount < 7) {
        tokens[tokenCount++] = token;  
        token = strtok_s(NULL, "|", &context); // Get the next token.
    }

    // Check if the record has exactly 7 fields so that it passes as valid, if not its invalid.
    if (tokenCount == 7) {
        printf("\n");
        printf("=============Valid Part=============\n");
        printf("Part Name: %s\n", tokens[0]);      
        printf("Part Number: %s\n", tokens[1]);    
        printf("Part Location: %s\n", tokens[2]);  
        printf("Part Cost: $%s\n", tokens[3]);      
        printf("Quantity On Hand: %s\n", tokens[4]);
        printf("Part Status: %s\n", tokens[5]);      
        printf("Part ID: %s\n", tokens[6]);
        printf("====================================\n");
        
       //Log Message
        snprintf(log_message, sizeof(log_message), "Part '%s' record processed successfully", tokens[0]);
        logEvent("INFO", log_message);
    }
    else {
        printf("Invalid Part: %s (Token Count: %d)\n", lineBuffer, tokenCount);
        
		//Log Message
        logEvent("Error","Part record invalid");
    }
}