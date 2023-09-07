#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

#include <string>

class ISubscriber
{
public:
    virtual ~ISubscriber(){};
    virtual void update(const std::string &message_from_subject) = 0;

};

#endif // ISUBSCRIBER_H
