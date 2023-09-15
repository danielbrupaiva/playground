#include <iostream>

#define print(x) std::cout << x << std::endl;

using namespace std;

typedef enum _systemState
{
    HOME,
    IDLE,
    RUN,
    END,
    SAFETY
} systemState_t;

/*FSM STRUCT*/
typedef struct _FSM
{
    systemState_t currentState;
    void (*pfHandler)(void);
    bool (*transition);
    uint32_t waitTime;
    systemState_t nextState[2];
} FSM_t;

void home_handler(void){
    print("Home handler");
}
void idle_handler(void){
    print("Idle handler");
}
void run_handler(void){
    print("Run handler");
}
void end_handler(void){
    print("End handler");
}
void safety_handler(void){
    print("Safety handler");
}
bool isSafety = true;
bool isTransition[6] = {false,false,false,false,false,false};
/*SYSTEM STATE MACHINE LOCKUP TABLE*/
FSM_t fsm[5] = {
    [HOME] = {  HOME,   &home_handler,   &isTransition[HOME],   0U, {SAFETY,IDLE}},
    [IDLE] = {  IDLE,   &idle_handler,   &isTransition[IDLE],   0U, {SAFETY, RUN}},
    [RUN] = {   RUN,    &idle_handler,   &isTransition[RUN],    0U, {SAFETY, END}},
    [END] = {   END,    &end_handler,    &isTransition[END],    0U, {SAFETY, HOME}},
    [SAFETY] = {SAFETY, &safety_handler, &isTransition[SAFETY], 0U, {SAFETY, HOME}}
};


int main()
{
    cout << "State Machine with lockup table" << endl;

    /*INITIAL STATE*/
    systemState_t currentState = HOME;

    while (1)
    {

        fsm[currentState].pfHandler();
        while (isSafety && !(*fsm[currentState].transition))
        {
        }
        //k_msleep(fsm[currentState].waitTime);
        currentState = fsm[currentState].nextState[isSafety];

    }
    return 0;
}
