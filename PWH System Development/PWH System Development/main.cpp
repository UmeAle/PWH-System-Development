#include "mainHeader.h"
// FILE        : main.cpp
// DESCRIPTION : Runs the program.
// DATE        : 04/09/2025
//

void logEvent(const char* logLevel, const char* message);



int main(void) {

	//program starts
	logEvent("INFO", "Program started.");
	
	//The program is going to be runned here
	mainMenu();

	// program ends
	logEvent("INFO", "Program finished.");
	return 0;
}