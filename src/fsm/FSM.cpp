#include "FSM.h"
#include "Arduino.h"
#include "MotorControl.h"
#include "Bluetooth.h"
#include "Sensor.h"

FSM::FSM() {
    currentState = INIT;
    directionChangeCount = 0;
}

int FSM::mainLoop() {
    switch (currentState) {
        case INIT:
            distance = lireDistance();
            directionChangeCount = 0;
            if (distance < 3) {
                startTime = millis();
                initializeMotor();
                startMotorClockwise();
                directionChangeCount++;
                transitionTo(FORWARD);
                Bluetooth::sendMessage("Motor rotating counterclockwise");
            }
            break;

        case FORWARD:
            distance = lireDistance();
            if (distance < 3) {
                startMotorCounterClockwise();
                directionChangeCount++;
                Bluetooth::sendMessage("Motor rotating counterclockwise");
                transitionTo(BACKWARD);
            }
            break;

        case BACKWARD:            
            distance = lireDistance();
            if (distance < 3) {
                startMotorClockwise();
                directionChangeCount++;
                Bluetooth::sendMessage("Motor rotating clockwise");
                transitionTo(FORWARD);
            }
            break;

        case FINAL:
                stopMotor();
            // No transitions; system must reboot to reactivate.
            break;
    }
    return directionChangeCount;
}

State FSM::getState() {
    return currentState;
}

void FSM::setState(State state) {
    currentState = state;
}

void FSM::transitionTo(State newState) {
    currentState = newState;
}
