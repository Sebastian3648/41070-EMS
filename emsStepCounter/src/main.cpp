#include <Arduino.h>
#include <ADXL335.h>
#include "PDALib.h"

ADXL335 accel;

//Control for Menu Display
void menu(int, int);

void setup() {
  // put your setup code here, to run once:
  accel.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
}

