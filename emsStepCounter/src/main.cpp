#include <Arduino.h>
#include "temp.h"
#include "PDALib.h"
#include "BreadLib.h"

accelerometerData accelData;


#define ButtonOutput1 13
#define ButtonOutput2 12
#define ButtonOutput3 11
#define ButtonInput1 10
#define ButtonInput2 9
#define ButtonInput3 8

float backlight = 1; //0 - 1
int threshold  = 50; //0 - 100
int expectedChange = 0; //Decided by the calibration function, determine magnitude of force needed for a step to count
bool calibrateNow = false;
bool calibrating = false;
bool datacollected = false;
int stepCounter = 0;

Timer timer1;

void calibrate(){
  if(calibrateNow) {
    timer1.Restart();
    calibrateNow = false;
    calibrating = true;
  }
  if (calibrating){
    if(!timer1.Read(10000)){ //For 10 seconds
      if(timer1.Elapsed() % 100 == 0){ //10 Time a Second
        accelData.collect();
      }
    } else {
      datacollected = true;
      calibrating = false;
    }
  }
  if(datacollected){
    accelData.computeVectors(); //Find the direction and magnitude of each data point
    accelData.determineAverageDirectionChangeMagnitude(); //Determine average angle and force of each movement and then determine significant changes in those features to find average of a step
    accelData.saveCallibrationData();
    timer1.Restart();
    datacollected = false;
  }
}

Timer timer2;

void determineStep(){
  if(timer2.Elapsed() % 100 == 0){ //10 times a second
    accelData.collect(); //Collect in array in class
  }
  if(accelData.stepCheck()){ //Step Check, computes vectors for current raw data, then determines, using calibration values, if there is a change of direction significant enough to count as a step
    stepCounter+=1;
    accelData.dataClear(); //clear data, search for new step
  }
}


//Control for Menu Display
void menu(int, int);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
}

