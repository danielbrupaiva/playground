#include <iostream>
#include <vector>
#include "filelogger.h"
#include "publisher.h"
#include "subscriber.h"
/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 *
 * https://refactoring.guru/design-patterns/observer/cpp/example#example-0--main-cc
 */


int main()
{

    const char* TAG = "MAIN";
    print(TAG);
/*  FileLogger fileLogger("LogFile.txt");
    fileLogger.LOG("Daniel");
    fileLogger.LOG( LogLevel::INFO, TAG, "FILE NAME: " + std::string(__FILE_NAME__));
    fileLogger.LOG( "LINE: " + std::to_string(__LINE__) );
*/
    auto publisher(std::make_shared<Publisher>());

    auto subscriber1 = std::make_shared<Subscriber>(*publisher);
    auto subscriber2 = std::make_shared<Subscriber>(*publisher);
    auto subscriber3 = std::make_shared<Subscriber>(*publisher);

    publisher->CreateMessage("Publisher here");




    return 0;
}
