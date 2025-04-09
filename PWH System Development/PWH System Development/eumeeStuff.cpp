#include "mainHeader.h"


//
// FUNCTION	   : ValidateOrder
// DESCRIPTION : Validates Orders, ensuring it has 11 fields. The line is
//				 tokenized using strtok, and the number of fields is counted
//				 to validate the order. Prints the valid orders.
// PARAMETERS  : const char* lineBuffer - The order line (string) to be validated.
// RETURNS     : NONE
//
void ValidateAndPrintOrder(const char* lineBuffer)
{
	const int EXPECTED_FIELDS = 11;
	int fieldCount = 0;
	char tempLine[300];
	char* token;
	char* tokens[EXPECTED_FIELDS];
	char* context = NULL;
	
	//Copies the original line to avoid changes directly
	strncpy_s(tempLine, lineBuffer, sizeof(tempLine));
	tempLine[sizeof(tempLine) - 1] = '\0';

	//Tokenize the line based on the '|' delimeter to separate fields
	token = strtok_s(tempLine, "|", &context);

	//Loop through all tokens to count the fields
	while (tokens != NULL && fieldCount < EXPECTED_FIELDS) {
		tokens[fieldCount++] = token;
		token = strtok_s(NULL, "|", &context);
	}

	//Only prints the valid orders
	if (fieldCount == EXPECTED_FIELDS) {
		printf("\n===== Valid Order =====\n");
		printf("Order ID: %s\n", tokens[0]);
		printf("Date: %s \n", tokens[1]); 
		printf("Status: %s\n", tokens[2]);
		printf("Customer ID: %s\n", tokens[3]);
		printf("Order Total: $%s\n", tokens[4]);
		printf("----- Order Parts-----\n");
		printf("Distinct Parts: %s\n", tokens[5]);
		printf("Total Parts: %s\n", tokens[6]);
		printf("Part 1 ID: %s\n", tokens[7]);
		printf("Part 1 Qty: %s\n", tokens[8]);
		printf("Part 2 ID: %s\n", tokens[9]);
		printf("Part 2 Qty: %s\n", tokens[10]);
		printf("========================\n\n");
	
		//log message
		logEvent("INFO", "Order record processed successfully.");;
	}
	else 
	{
		//log message
		logEvent("WARNING", "Order record invalid - incorrect token count.");
	}
}