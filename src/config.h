#ifndef CONFIG_H
#define CONFIG_H

// === Pin Assignments ===
// Motor pins
#define MOTOR_PIN1 9  
#define MOTOR_PIN2 10 
#define ENABLE_PIN 11 // pin to enable the motor (PWM)

// Sensor pins
#define SENSOR_LEFT_PIN A0  // Analog pin for the left obstacle sensor
#define SENSOR_RIGHT_PIN A1 // Analog pin for the right obstacle sensor

// Bluetooth pins
#define BLUETOOTH_RX_PIN 2  // RX pin for Bluetooth module
#define BLUETOOTH_TX_PIN 3  // TX pin for Bluetooth module

// === Configuration Constants ===
// Motor control
#define DEFAULT_SPEED 150   // Default motor speed (0-255)
#define TURN_SPEED 120      // Speed during turns

// Sensor thresholds
#define SENSOR_THRESHOLD 500 // Threshold for obstacle detection

// Bluetooth settings
#define BLUETOOTH_BAUDRATE 9600 // Baud rate for Bluetooth communication

// Debug settings
#define DEBUG true           // Set to false to disable debug messages

// Utility macros
#define LOG(msg) if (DEBUG) { Serial.println(msg); }

#endif // CONFIG_H
