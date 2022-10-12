#ifndef DataButton_h
#define DataButton_h
#include "Arduino.h"

#include <FastLED.h>



class DataButton {
public:
  DataButton(int pin, int startLED, int endLED, int associatedVars);
  void coreButtonPress(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[]);
  void complexButtonPress(CRGB *ledstrip, int &numActive);
  void uploadButtonPress(CRGB *ledstrip, int &numActive);
  bool checkFinalState();

private:
  int _pin;
  int _startLED;
  int _endLED;
  int _numLEDs;
  int _oldState;
  int _newState;
  int _associatedVars;
  bool _value;
};

#endif