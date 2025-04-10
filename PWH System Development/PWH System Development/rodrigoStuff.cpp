#include "mainHeader.h"


// FUNCTION    : ValidateAndPrintCustomer
// DESCRIPTION : Checks if a single customer record has exactly 9 fields
//               (separated by '|') and prints it if valid.
// PARAMETERS  : const char* lineBuffer - The raw line from customers.db
// RETURNS     : None
void ValidateAndPrintCustomer(char* lineBuffer)
{
	const int EXPECTED_FIELDS = 12; //12, not 9 =)
    int fieldCount = 0;
	char* tokens[EXPECTED_FIELDS];
    char tempLine[300];
    char* context = NULL;
	char log_message[MAX_LOG_LENGTH];

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
        printf("\n===== Valid Customer =====\n");
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
        snprintf(log_message, sizeof(log_message), "Custumer '%s' record processed successfully", tokens[0]);
        logEvent("INFO", log_message);
      
    }
    else 
    {
        printf("Invalid Customer: %s (Fields found: %d)\n", lineBuffer, fieldCount);
    
        // log message
        logEvent("Error", "Customer record invalid - incorrect field count.");
    }
}


// FUNCTION    : mainMenu
// DESCRIPTION : Displays the main menu and handles user input
// PARAMETERS  : None
// RETURNS     : None
void mainMenu(void) {
    menuOptions choice;
    printf("======================================\n");
    printf("      Welcome to the PWH System!      \n");
    printf("======================================\n");
    do {
		//Display the menu
		displayMainMenu();
        choice = (menuOptions)getValidIntegerInput(5);
        switch (choice) {
        case LOAD_DATABASE:
			logEvent("INFO", "Starting to load all databases.");
			order = loadOrderDB();
			part = loadPartsDB();
			customer = loadCustomerDB();
            break;
        case LIST_CUSTOMER:
            logEvent("INFO", "Starting to load custumer Database.");
			ValidateAndPrintCustomers(customer); //custumerhere
            break;
        case LIST_PART:
            logEvent("INFO", "Starting to load parts Database.");
			ValidateAndPrintParts(part); //
            break;
        case LIST_ORDER:
            logEvent("INFO", "Starting to load order Database.");
			ValidateAndPrintOrders(order); //custumer here
			break;
		case EXIT:
			printf("Exiting...\n");
			break;
        default:
            printf("Please only enter the valid integer options (1,5)\n");
        }
    } while (choice != EXIT);
}

// FUNCTION    : displayMainMenu
// DESCRIPTION : Displays the options
// PARAMETERS  : None
// RETURNS     : None
void displayMainMenu(void) {
	printf("\n1. Load Database\n");
	printf("2. Load Order Database\n");
	printf("3. Load Parts Database\n");
	printf("4. Load Customer Database\n");
	printf("5. Exit\n");
    printf("Please select an option: ");
}


//FUNCTION   : GetValidIntegerInput     
//DESCRIPTION: Makes sure that the input read from keyboard is based on just the range from 1 to the max_choice
//PARAMETERS : none     
//RETURNS    : The valid integer
int getValidIntegerInput(int max_choice)
{
    int value;
    char buffer[100];

    while (1)
    {
        //Prompt for input
        if (fgets(buffer, sizeof(buffer), stdin))
        {
            //Remove trailing newline
            if (sscanf_s(buffer, "%d", &value) == 1)
            {
                char* extra_char = buffer;

                //Skip the number
                while (*extra_char >= '0' && *extra_char <= '9')
                {
                    extra_char++;
                }

                //Skip spaces and newlines
                while (*extra_char == ' ' || *extra_char == '\n')
                {
                    extra_char++;
                }

                //Verifying range
                if (value >= 1 && value <= max_choice && *extra_char == '\0')
                {
                    return value;
                }
            }
        }
        printf("Invalid input! Please enter a number from 1 to %d: \n", max_choice);
    }
}