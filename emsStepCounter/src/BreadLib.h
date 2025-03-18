#ifndef BREADLIB_h
#define BREADLIB_h

#include "Arduino.h"

class Bread{
  public:
    Bread();
  protected:
  private:
};

class Timer : public Bread {
  public:
    Timer();
    bool Read(unsigned long wait);
    void Start();
    void Reset();
    void Restart();
    unsigned long Elapsed();
  private:
    unsigned long _timeStart;
    bool _start;
    bool _done;
};

class RBGLED : public Bread {
  public: 
    RBGLED(int r, int b, int g);
    void Write(char col);
    void pinSet(int r, int b, int g);
    char Colour();
    void Begin();
  private:
    int _r;
    int _g;
    int _b;
    char _colour;
};

#endif