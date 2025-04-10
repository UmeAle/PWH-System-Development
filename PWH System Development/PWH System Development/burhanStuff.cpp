#include "mainHeader.h" 


//
// FUNCTION    : listValidParts
// DESCRIPTION : Accepts a line from the parts database, tokenizes it using strtok_s with the pipe ('|') delimiter,
//               counts the fields, and prints the record if exactly 7 fields are found.
// PARAMETERS  : const char* lineBuffer
// RETURNS     : None
//
void ValidateAndPrintPart(char** lineBuffer)
{
    const int EXPECTED_FIELDS = 7;
    int i = 0;
   
    while (lineBuffer[i] != NULL) {
        int fieldCount = 0;
        int tokenCount = 0;
        char tempLine[300];
        char* context = NULL;
        char* tokens[7];
        char log_message[MAX_LOG_LENGTH];

        //Makes a copy of the line because strtok_s will change it.
        strncpy_s(tempLine, lineBuffer[i], sizeof(tempLine));
        tempLine[sizeof(tempLine) - 1] = '\0';

        //Breaks the line into pieces using '|'
        char* token = strtok_s(tempLine, "|", &context);
        while (token != NULL && tokenCount < 7) {
            tokens[tokenCount++] = token;
            token = strtok_s(NULL, "|", &context); // Get the next token.
        }

        if (fieldCount != EXPECTED_FIELDS)
        {
            logEvent("WARNING", "Order record invalid - incorrect token count");
            return;
        }

        if (!matchesRegex(RX_NAME, tokens[0]) ||
            !matchesRegex(RX_NAME, tokens[1]) ||
            !matchesRegex(RX_NAME, tokens[2]) ||
            !matchesRegex(RX_PART_COST, tokens[3]) ||
            !matchesRegex(RX_PART_QUANTITY, tokens[4]) ||
            !matchesRegex(RX_PART_STATUS, tokens[5]) ||
            !matchesRegex(RX_ID, tokens[6]))
        {
            logEvent("ERROR", "Customer record invalid - field format error.");
            return;
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
            printf("Invalid Part: %s (Token Count: %d)\n", lineBuffer[i], tokenCount);

            //Log Message
            logEvent("Error", "Part record invalid");
        }
        i++;
    }  // Process next record in the array
}