#include "mainHeader.h"

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