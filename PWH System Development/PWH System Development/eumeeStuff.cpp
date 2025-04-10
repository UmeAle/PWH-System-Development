#include "mainHeader.h"


//
// FUNCTION	   : ValidateOrder
// DESCRIPTION : Validates Orders, ensuring it has 11 fields. The line is
//				 tokenized using strtok, and the number of fields is counted
//				 to validate the order. Prints the valid orders.
// PARAMETERS  : const char* lineBuffer - The order line (string) to be validated.
// RETURNS     : NONE
//
void ValidateAndPrintOrder(char** lineBuffer)
{
	const int EXPECTED_FIELDS = 11;
	int i = 0;

	while (lineBuffer[i] != NULL) {
	int fieldCount = 0;
	char tempLine[300];
	char* token;
	char* tokens[EXPECTED_FIELDS];
	char* context = NULL;
	char log_message[MAX_LOG_LENGTH];
	
	//Copies the original line to avoid changes directly
	strncpy_s(tempLine, lineBuffer[i], sizeof(tempLine));
	tempLine[sizeof(tempLine) - 1] = '\0';

	//Tokenize the line based on the '|' delimeter to separate fields
	token = strtok_s(tempLine, "|", &context);

	//Loop through all tokens to count the fields
	while (tokens != NULL && fieldCount < EXPECTED_FIELDS) {
		tokens[fieldCount++] = token;
		token = strtok_s(NULL, "|", &context);
	}

	if (fieldCount != EXPECTED_FIELDS)
	{
		logEvent("WARNING", "Order record invalid - incorrect token count");
		return;
	}

	//Validating with regex
	if (!matchesRegex(RX_ID, tokens[0]) ||
		!matchesRegex(RX_DATE, tokens[1]) || 
		!matchesRegex(RX_OR_STATUS, tokens[2]) ||
		!matchesRegex(RX_ID, tokens[3]) ||
		!matchesRegex(RX_OR_TOTAL, tokens[4]) ||
		!matchesRegex(RX_PARTS, tokens[5]) ||
		!matchesRegex(RX_PARTS, tokens[6]) ||
		!matchesRegex(RX_ID, tokens[7]) ||
		!matchesRegex(RX_PARTS, tokens[8]) ||
		!matchesRegex(RX_ID, tokens[9]) ||
		!matchesRegex(RX_PARTS, tokens[10]))
	{
		//log message
		logEvent("WARNING", "Order record invalid - incorrect token count.");
		return;
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
		snprintf(log_message, sizeof(log_message), "Order '%s' record processed successfully", tokens[0]);
		logEvent("INFO", log_message);
	}
	else 
	{
		//log message
		logEvent("WARNING", "Order record invalid - incorrect token count.");
	}
	i++;
	}  // Process next record in the array
}