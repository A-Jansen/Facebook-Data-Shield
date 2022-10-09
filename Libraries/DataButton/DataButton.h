#ifndef DataButton_h
#define DataButton_h
#include "Arduino.h"

#include <FastLED.h>



class DataButton{
  public:
    DataButton(int pin, int startLED, int endLED);
    void coreButtonPress(CRGB ledstrip[], int &numActive, int numVar);
    void complexButtonPress(CRGB *ledstrip , int &numActive);
    
  private:
    int _pin;
    int _startLED;
    int _endLED;
    int _numLEDs;
    int _oldState;
    int _newState;
    bool _value;

};

#endif