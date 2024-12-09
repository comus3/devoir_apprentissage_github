#ifndef FSM_H
#define FSM_H

enum State {
    INIT,
    FORWARD,
    BACKWARD,
    FINAL
};

enum Event {
    SENSOR_DETECTED,
    TIMEOUT,
    MAX_DIRECTION_CHANGE
};

class FSM {
public:
    FSM();
    int mainLoop();
    State getState();
    void setState(State state);

private:
    State currentState;
    int directionChangeCount;
    unsigned long startTime;
    int distance;
    void transitionTo(State newState);
};

#endif
