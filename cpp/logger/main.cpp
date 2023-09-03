#include <iostream>
#include "filelogger.h"


int main()
{
    const char* TAG = "MAIN";

    FileLogger fileLogger("LogFile.txt");

    fileLogger.LOG("Daniel");

    fileLogger.LOG( LogLevel::INFO, TAG, "FILE NAME: " + std::string(__FILE_NAME__));

    fileLogger.LOG( "LINE: " + std::to_string(__LINE__) );

    return 0;
}
