#pragma once

#include "filelogger.h"
#include "publisher.h"

class Subscriber : public ISubscriber
{

public:
    virtual ~Subscriber(){
        this->detach();
        print("Subscriber detached and destructed");
    };
    Subscriber(Publisher &subject) : m_subject(subject){
        this->attach();
        print("Subscriber created and attached to publisher");
    }
    // IObserver interface
public:
    void attach() {
        this->m_subject.attach(this);
    }
    void detach() {
        this->m_subject.detach(this);
    }

    void update(const std::string &message_from_subject) override{
        print(message_from_subject);
    }


private:
    Publisher &m_subject;
    std::string m_message;
};
