#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "config.h"

class Bluetooth {
private:
    SoftwareSerial bluetoothSerial; // SoftwareSerial object for Bluetooth communication

public:
    // Constructor
    Bluetooth();

    // Initialize the Bluetooth module
    void init();

    // Send a message via Bluetooth
    void sendMessage(const String& message);
};

#endif // BLUETOOTH_H