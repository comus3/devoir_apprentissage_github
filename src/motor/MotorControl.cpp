#include "MotorControl.h"
#include <Arduino.h>

// Global variables to track the motor state
bool isMotorRunning = false;       
bool isClockwise = true;           
int directionChangeCount = 0;      
unsigned long startTime = 0;      

// Motor initialization
void initializeMotor() {
    pinMode(MOTOR_PIN1, OUTPUT);
    pinMode(MOTOR_PIN2, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);

    stopMotor();
}

// Clockwise rotation
void startMotorClockwise() {
    if (!isMotorRunning) {
        startTime = millis(); 
        isMotorRunning = true;
    }

    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
    analogWrite(ENABLE_PIN, 255); 

    isClockwise = true;
    Serial.println("Motor running clockwise."); // Message for Bluetooth
}

// Counterclockwise rotation
void startMotorCounterClockwise() {
    if (!isMotorRunning) {
        startTime = millis(); 
        isMotorRunning = true;
    }

    digitalWrite(MOTOR_PIN1, LOW); 
    digitalWrite(MOTOR_PIN2, HIGH);
    analogWrite(ENABLE_PIN, 255); 

    isClockwise = false;
    Serial.println("Motor running counterclockwise."); // message for Bluetooth
}

// Complete stop
void stopMotor() {
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
    analogWrite(ENABLE_PIN, 0);

    isMotorRunning = false;
    Serial.println("Motor stopped."); // message for Bluetooth
}

// Change motor direction
void toggleMotorDirection() {
    if (isClockwise) {
        startMotorCounterClockwise();
    } else {
        startMotorClockwise();
    }

    directionChangeCount++; 
}
