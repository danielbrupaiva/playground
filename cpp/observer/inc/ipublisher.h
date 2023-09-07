#ifndef IPUBLISHER_H
#define IPUBLISHER_H

#include "isubscriber.h"

#include <list>

class IPublisher {
public:
    virtual ~IPublisher(){};
    virtual bool attach(ISubscriber *observer) = 0;
    virtual bool detach(ISubscriber *observer) = 0;
    virtual void notify() = 0;
};

#endif // IPUBLISHER_H
