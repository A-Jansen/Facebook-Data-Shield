#ifndef DataButton_h
#define DataButton_h
#include "Arduino.h"

#include <FastLED.h>



class DataButton {
public:
  DataButton(int pin, int startLED, int endLED, int associatedVars);
  void coreButtonPress(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[], int aderLen, int &numActiveGroup, int maxGroup);
  void complexButtonPress(CRGB *ledstrip, int &numActive, int &numActiveGroup);
  void uploadButtonPress(CRGB *ledstrip, int &numActive, bool &upload);
  void setNumActiveGroup(int numActiveGroup);
  void changeGroupBrightness(CRGB ledstrip[], CRGB *ledstrip2, int &numActiveGroup, int ader[], int aderLen);
  void reset();
  void turn(bool &turning);
  bool pressedButton();
  void dePressButton();
  void turnComplexOn(CRGB ledstrip[]);
  void turnComplexOff(CRGB ledstrip[]);
  void turnCoreOn(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[], int aderLen, int &numActiveGroup);

  int checkState();


private:
  int _pin;
  int _startLED;
  int _endLED;
  int _numLEDs;
  int _oldState;
  int _newState;
  int _associatedVars;
  int _reading;
  int _buttonState;
  int _lastButtonState;
  int _groupBrightness;
  int _oldNumActiveGroup;
  int _maxActive;
  unsigned long _lastDebounceTime = 0;
  unsigned long _debounceDelay = 50;
  bool _value;
  bool _pressed;
};

#endif