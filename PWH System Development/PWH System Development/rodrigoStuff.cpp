#include "mainHeader.h"


// FUNCTION    : ValidateAndPrintCustomer
// DESCRIPTION : Checks if a single customer record has exactly 9 fields
//               (separated by '|') and prints it if valid.
// PARAMETERS  : const char* lineBuffer - The raw line from customers.db
// RETURNS     : None
void ValidateAndPrintCustomer(const char* lineBuffer)
{
	const int EXPECTED_FIELDS = 12; //12, not 9 =)
    int fieldCount = 0;
	char* tokens[EXPECTED_FIELDS];
    char tempLine[300];
    char* context = NULL;

    //Make a copy of the original line to avoid modifying it directly
    strncpy_s(tempLine, lineBuffer, sizeof(tempLine));
    tempLine[sizeof(tempLine) - 1] = '\0';

	//Tokenize using the pipes (' | ')
    char* token = strtok_s(tempLine, "|", &context);
    while (token != NULL && fieldCount < EXPECTED_FIELDS) {
        tokens[fieldCount++] = token;
        token = strtok_s(NULL, "|", &context);
    }

    //If it has exactly 12 fields, it's considered valid
    if (fieldCount == EXPECTED_FIELDS) {
        printf("===== Valid Customer =====\n");
        printf("Name: %s\n", tokens[0]);
        printf("Address: %s, %s - %s (%s)\n",
            tokens[1],  //Streat
            tokens[2],  //City
            tokens[3],  //Procince
            tokens[4]); //Postal code
        printf("Phone: %s\n", tokens[5]);
        printf("Email: %s\n", tokens[6]);
        printf("ID: %s\n", tokens[7]);
        printf("Credit Limit: %s\n", tokens[8]);
        printf("Account Ballance: %s\n", tokens[9]); 
        printf("Last Payment Made: %s\n", tokens[10]);
        printf("Join Date: %s\n", tokens[11]);
        printf("========================\n\n");
        
        
        //log message
        logEvent("INFO", "Customer record processed successfully.");
      
    }
    else 
    {
        printf("Invalid Customer: %s (Fields found: %d)\n", lineBuffer, fieldCount);
    
        // log message
        logEvent("WARNING", "Customer record invalid - incorrect field count.");
    }
}
