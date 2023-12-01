#include <iostream>
#include "filelogger.h"

int main()
{
    const std::string TAG = "MAIN";
    Logger::Instance().SetFileName("FileLogger.txt");
    Logger::Instance().LOG(Logger::Level::WARNING, TAG, "Message here");
    Logger::Instance().LOG("Message here");
    return 0;
}
