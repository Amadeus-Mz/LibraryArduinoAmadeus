#ifndef MillisFx_h
#define MillisFx_h
#include "Arduino.h"

class BlinkCustom
{
private:
          unsigned long _interValOn, _interValOff;
          unsigned long _currentTime;
          unsigned long _prevousTime;
public:
          int _pin;

          BlinkCustom(byte pin);
          void setBlink(unsigned long interValOn, unsigned long interValOff);
};

class Sleep
{
private:
          unsigned long _interVal;
          unsigned long _currentTime;
          unsigned long _prevousTime;
public:
          void setTime(void (*)(void),unsigned long interVal);
          void Fx(void (*)(void));
};

#endif