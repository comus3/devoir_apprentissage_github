#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
#include "config.h"

extern bool isMotorRunning;       
extern bool isClockwise;          
extern int directionChangeCount;  
extern unsigned long startTime;   

/**
 * @brief Initializes the motor pins and variables.
 *        Stops the motor and prepares the system to start.
 */
void initializeMotor();

/**
 * @brief Rotates the motor clockwise.
 *        Updates the global state and sends a Bluetooth message.
 */
void startMotorClockwise();

/**
 * @brief Rotates the motor counterclockwise.
 *        Updates the global state and sends a Bluetooth message.
 */
void startMotorCounterClockwise();

/**
 * @brief Completely stops the motor and cuts off the power.
 *        Updates the global state and sends a Bluetooth message.
 */
void stopMotor();

/**
 * @brief Toggles between rotation directions (clockwise and counterclockwise).
 *        Increments the direction change counter.
 */
void toggleMotorDirection();

/**
 * @brief Monitors time and direction change limits.
 *        Automatically stops the motor if a limit is reached.
 */
void checkMotorTimeout();

#endif 
