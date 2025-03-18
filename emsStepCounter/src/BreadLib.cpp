#include "Arduino.h"
#include "BreadLib.h"

Bread::Bread(){
  Serial.println("Bread v0.0 Loaded! (DATE)");
}

Timer::Timer(){
  _done = false;
  _start = false;
  _timeStart = millis();
}

bool Timer::Read(unsigned long wait){
  if(_start == true){
    if(millis() - _timeStart > wait){
      _done = true;
    } else {
      _done = false;
    }
    return _done;
  } else {
    return false;
  }
}

unsigned long Timer::Elapsed(){
  return(millis() - _timeStart);
}

void Timer::Start(){
  if(_start == false) {
    _timeStart = millis();
    _start = true;
  }
}

void Timer::Reset(){
  _timeStart = millis();
  _start = false;
}

void Timer::Restart(){
  Reset();
  Start();
}

RBGLED::RBGLED(int r, int b, int g){
  _r = r;
  _g = g;
  _b = b;
  _colour = 'O';
}

void RBGLED::Begin(){
  pinMode(_r, OUTPUT);
  pinMode(_b, OUTPUT);
  pinMode(_g, OUTPUT);
}

void RBGLED::Write(char col){
  switch(col){
    case 'B':
      pinSet(0, 1, 0);
      _colour = 'B';
      break;      
    case 'G':
      pinSet(0, 0, 1);
      _colour = 'G';
      break;      
    case 'R':
      pinSet(1, 0, 0);
      _colour = 'R';
      break;      
    case 'Y':
      pinSet(1, 0, 1);
      _colour = 'Y';
      break;      
    case 'W':
      pinSet(1, 1, 1);
      _colour = 'W';
      break;      
    case 'O':
      pinSet(0, 0, 0);
      _colour = 'O';
      break;
    default:
      pinSet(0, 0, 0);
      _colour = 'O';
      break;
  }
}


void RBGLED::pinSet(int r, int b, int g){
  digitalWrite(_r, r);
  digitalWrite(_b, g);
  digitalWrite(_g, b);
}

char RBGLED::Colour(){
  return(_colour);
}
