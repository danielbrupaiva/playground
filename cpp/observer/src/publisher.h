#pragma once

#include "filelogger.h"
#include "ipublisher.h"
#include <list>

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */
class Publisher : public IPublisher
{
public:
    virtual ~Publisher(){
        print("Publisher destructed");
    }
    Publisher(){
        print("Publisher created");
    }

 /*
 * ISubject interface
 */
public:
    bool attach(ISubscriber *observer) override{
        m_obserserList.push_back(observer);
        return true;
    }
    bool detach(ISubscriber *observer) override{
        m_obserserList.remove(observer);
        return true;
    }
    void notify() override {

        std::list<ISubscriber *>::iterator iterator = this->m_obserserList.begin();

        while(iterator != this->m_obserserList.end() ){
            (*iterator)->update(m_message);
            ++iterator;
        }
    }

/*
 * Business logics
 */
public:
    void logicBusiness(){
        print("Logic business here");
        m_message = "Logic business here";
        notify();
    }
    void CreateMessage(std::string message = "Empty") {
        m_message = message;
        notify();
    }
/*
 * Getter and setters
 */
public:
    int getNumberOfObservers(){
        return m_obserserList.size();
    }

 /*
  * Members parameters
  */
private:
    std::list<ISubscriber *> m_obserserList;
    std::string m_message;
};

