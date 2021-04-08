#include "MillisFx.h"

BlinkCustom::BlinkCustom(byte pin)
{
          _pin = pin;
          pinMode(_pin, OUTPUT);
}

void BlinkCustom::setBlink(unsigned long interValOn, unsigned long interValOff)
{
          _interValOn = interValOn;
          _interValOff = interValOn + interValOff;

          _currentTime = millis();

          if(_currentTime - _prevousTime >= _interValOn)
          {
                    digitalWrite(_pin, HIGH);
                    if(_currentTime - _prevousTime >= _interValOff)
                    {
                              digitalWrite(_pin, LOW);
                              _prevousTime = _currentTime;
                    }
          }
}

void Sleep::setTime(void Fx(void), unsigned long interVal)
{
         _interVal = interVal;
         _currentTime = millis();

          if(_currentTime - _prevousTime >= _interVal)
          {
                    Fx();
                    _prevousTime = _currentTime;
          }
}