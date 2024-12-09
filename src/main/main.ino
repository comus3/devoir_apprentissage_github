#include <Arduino.h>
#include "fsm/FSM.h"         // Include the FSM logic
#include "motor/MotorControl.h"  // Include motor control
#include "sensor/Sensor.h"      // Include sensor functions
#include "bluetooth/Bluetooth.h"  // Include Bluetooth functions
#include "config.h"             // Include configuration settings (pins, timeouts, etc.)

FSM fsm;
volatile unsigned long timerMillis = 0;
int count;

void setup() {
  Serial.begin(115200);
  initUltrason();
  initializeMotor();
  fsm.transitionTo(INIT);  // Start with the INIT state in FSM
  
  noInterrupts();
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerISR);
  interrupts();
}

void loop() {

  count = fsm.mainLoop();
  if (timerMillis >= 30000 || count >= 5) {
    fsm.setState(FINAL);
  }

}

void timerISR() {
  timerMillis++;
}