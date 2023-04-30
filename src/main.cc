#include <Arduino.h>
#include <BleKeyboard.h>
#include "button.hpp"

#define PIN_LEFT 18
#define PIN_RIGHT 19

BleKeyboard bleKeyboard("Foot Switch", "The manufacturer", 100);

Button arrowLeft(&bleKeyboard, PIN_LEFT, KEY_LEFT_ARROW, INPUT_PULLDOWN);
Button arrowRight(&bleKeyboard, PIN_RIGHT, KEY_RIGHT_ARROW, INPUT_PULLDOWN);

void setup()
{
  Serial.begin(9600);
  bleKeyboard.begin();
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    arrowLeft.update();
    arrowRight.update();
  }
  else
  {
    Serial.println("Not connected, waiting 0.5 seconds!");
    delay(500);
  }
}
