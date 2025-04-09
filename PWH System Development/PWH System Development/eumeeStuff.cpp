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
	int fieldCount = 0;
	char tempLine[300];
	char* context = NULL;

	strncpy_s(tempLine, lineBuffer, sizeof(tempLine));
	tempLine[sizeof(tempLine) - 1] = '\0';

	//Tokenize the line based on the '|' delimeter to separate fields
	char* token = strtok_s(tempLine, "|", &context);

	//Loop through all tokens to count the fields
	while (token != NULL) {
		fieldCount++;
		token = strtok_s(NULL, "|", &context);
	}

	//Only prints the valid orders
	if (fieldCount == 11) {
		printf("Valid Order: %s\n", lineBuffer);
	
		//log message
		logEvent("INFO", "Order record processed successfully.");;
	}
	else 
	{
		//log message
		logEvent("WARNING", "Order record invalid - incorrect token count.");
	}
}