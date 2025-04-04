
#include "mainHeader.h"


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
        return NULL;
    }
    return err;
}


//
// FUNCTION : closeFile
// DESCRIPTION : This function closed the already opened file. 
// PARAMETERS : file, the refernce file that the file pointer is pointing to. 
// RETURNS : none.
//
void closeFile(FILE* file) {
    if (file) {
        fclose(file);
    }
}

//
// FUNCTION : getFilePath
// DESCRIPTION : This function prompts the user for a file path and returns it as a dynamically allocated string.
// PARAMETERS : None.
// RETURNS : A pointer to the dynamically allocated string containing the file path.
char* getFilePath() {

	//Allocate memory for the file path. I did this in case anyone else needs to use it in their functions.
    char* path = (char*)malloc(MAX_PATH_LEN);
    if (!path) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

	//Prompt the user for the file path.
    printf("Enter the file path for the datbase files (relative or absolute): ");
    if (fgets(path, MAX_PATH_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        free(path);
        return NULL;
    }

    //Remove the newline and add the null terminator instead from fgets.
    size_t len = strlen(path);
    if (len > 0 && path[len - 1] == '\n') {
        path[len - 1] = '\0';
    }

    return path;
}

//
// FUNCTION : loadOrderDB
// DESCRIPTION : Prompts the user for a file path, opens the file, reads each line, and processes it.
// PARAMETERS : None currently?
// RETURNS : None.
//
void loadOrderDB() {
	printf("Loading Order Database...\n");
	//Open the file for reading
    FILE* file = NULL;
    if (openFile(&file,"orders.db", "r") != 0 || !file) {
        return;
    }

	//Read the file line by line
    char lineBuffer[300]; 
    while (fgets(lineBuffer, sizeof(lineBuffer), file)) {

        //Stripping the newline for my colleagues for strtok because I am a nice guy
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
        }

        //WHOEVER IS DOING THE ORDER DB, ADD YOUR STRTOK CODE HERE TO TOKENIZE
        printf("Line: %s\n", lineBuffer);

    }

    closeFile(file);
}

//
// FUNCTION : loadCustomerDB
// DESCRIPTION : Prompts user for a customer database file, opens it, reads line by line, and processes each line.
// PARAMETERS : None currently?
// RETURNS : None.
//
void loadCustomerDB() {
	printf("Loading Customer Database...\n");
    
	//Open the file for reading
    FILE* file = NULL;
    if (openFile(&file, "customers.db", "r") != 0 || !file) {
        return;
    }

	//Read the file line by line
    char lineBuffer[300];
    while (fgets(lineBuffer, sizeof(lineBuffer), file)) {

        //Remvoing the newline off the end of the input once again for strtok use.
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
        }

		//WHOEVER IS DOING THE CUSTOMER DB, ADD YOUR STRTOK CODE HERE TO TOKENIZE
        printf("Customer Line: %s\n", lineBuffer);

    }

	// Close the file
    closeFile(file);
}


//
// FUNCTION : loadPartsDB
// DESCRIPTION : Prompts user for the parts database file, opens it, and reads line by line for processing.
// PARAMETERS : None.
// RETURNS : None.
//
void loadPartsDB() {
    printf("Loading Parts Database...\n");

	//Open the file for reading.
   //Open the file for reading
    FILE* file = NULL;
    if (openFile(&file, "parts.db", "r") != 0 || !file) {
        return;
    }


    //Read the file line by line.
    char lineBuffer[300];
    while (fgets(lineBuffer, sizeof(lineBuffer), file)) {
        
		//Stripping the newline for my colleagues for strtok because I am a nice guy.
        size_t len = strlen(lineBuffer);
        if (len > 0 && lineBuffer[len - 1] == '\n') {
            lineBuffer[len - 1] = '\0';
        }

		//WHOEVER IS DOING THE PARTS DB, ADD YOUR STRTOK CODE HERE TO TOKENIZE
        printf("Part Line: %s\n", lineBuffer);
    }

    closeFile(file);
}

//
// FUNCTION : loadAllDatabases
// DESCRIPTION : Calls the load functions for all databases.
// PARAMETERS : None.
// RETURNS : None.
//
void loadAllDatabases() {
	loadOrderDB();
	loadCustomerDB();
	loadPartsDB();
}

