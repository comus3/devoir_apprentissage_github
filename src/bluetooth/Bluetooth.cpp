#include "Bluetooth.h"

// Constructor
Bluetooth::Bluetooth() : bluetoothSerial(RX_PIN, TX_PIN) {}

// Initialize the Bluetooth module
void Bluetooth::init() {
    bluetoothSerial.begin(9600); // HC-06 default baud rate
    Serial.println("Bluetooth initialized");
}

// Send a message via Bluetooth
void Bluetooth::sendMessage(const String& message) {
    if (bluetoothSerial) {
        bluetoothSerial.println(message); // Send message to connected device
        Serial.println("Bluetooth message sent: " + message); // Debugging on Serial Monitor
    } else {
        Serial.println("Error: Bluetooth module not connected"); // Debug message
    }
}