// FILE        : ammarStuff..cpp
// DESCRIPTION : Contains the logging functionality for the application.
//               Implements the logEvent function to write log messages with a
//               timestamp and log level to logfile.txt.
// AUTHOR      : Ammar Alkhatib
// DATE        : 04/09/2025


#include "mainHeader.h" 


// FUNCTION    : logEvent
// DESCRIPTION : Logs a message to logfile.txt with a timestamp and log level.
//               Opens the logfile in append mode, writes the log entry in the
//               format: [YYYY-MM-DD HH:MM:SS] [logLevel]: message, and then closes the file.
// PARAMETERS  : const char* logLevel - The level of the log (e.g., "INFO", "ERROR", "WARNING").
//               const char* message  - The message to log.
// RETURNS     : None

void logEvent(const char* logLevel, const char* message) {
    FILE* logFile = NULL;


    
    // Open logfile.txt in append mode 
    if (openFile(&logFile, "logfile.txt", "a") == 0 && logFile != NULL) {
        
        // Get the current timestamp
        time_t currentTime = time(NULL);
        struct tm localTime;
        localtime_s(&localTime, &currentTime);
        char timeString[50];
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", &localTime);

        // Write the formatted log entry
        fprintf(logFile, "[%s] [%s]: %s\n", timeString, logLevel, message);

        // Close logfile after writing
        closeFile(logFile);
    }
    else 
    {
        perror("Unable to open log file");
    }
}
