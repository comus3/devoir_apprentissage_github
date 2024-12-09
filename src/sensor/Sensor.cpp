#include "sensor.h"
#include <Arduino.h>
#include "config.h"

// Définition des pins
const int trig_pin = SENSOR_LEFT_PIN;
const int echo_pin = SENSOR_RIGHT_PIN;
const int button_pin = 7;  // Nouveau : bouton connecté à la pin 7

// Définition des variables
long duration;
int distance;
bool mesureActive = true;  // Nouveau : état pour activer/désactiver le capteur
unsigned long lastDebounceTime = 0; // Nouveau : temps pour le debounce
const unsigned long debounceDelay = 50; // Nouveau : délai de debounce

void initUltrason() {
  pinMode(trig_pin, OUTPUT);   // trig_pin comme sortie
  pinMode(echo_pin, INPUT);    // echo_pin comme entrée
  pinMode(button_pin, INPUT_PULLUP); // Nouveau : bouton avec résistance pull-up
}

int lireDistance() {
  if (!mesureActive) {
    return -1;  // Retourne -1 si la mesure est désactivée
  }

  // Clear le trig_pin
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  // Met le trig_pin à HIGH pendant 10 microsecondes
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // Lire le temps du signal écho
  duration = pulseIn(echo_pin, HIGH);

  // Calculer la distance en centimètres
  distance = duration * 0.034 / 2;

  return distance;
}

void gererBouton() {
  static int lastButtonState = HIGH;  // État précédent du bouton
  int buttonState = digitalRead(button_pin);  // Lecture de l'état actuel du bouton

  // Vérifie si l'état du bouton a changé
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();  // Réinitialise le temps de debounce
  }

  // Si le délai de debounce est écoulé
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si l'état a réellement changé après le délai
    if (buttonState == LOW && lastButtonState == HIGH) {
      // Inverse l'état de mesureActive
      mesureActive = !mesureActive;
    }
  }

  lastButtonState = buttonState;  // Met à jour l'état précédent
}
