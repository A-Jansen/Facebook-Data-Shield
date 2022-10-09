#include "Arduino.h"
#include "DataButton.h"

DataButton::DataButton(int pin, int startLED, int endLED) {
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _startLED = startLED;
  _endLED = endLED;
  _numLEDs = _endLED - _startLED;
  _oldState = 1;
  _newState;
  _value = 0;
}

void DataButton::coreButtonPress(CRGB ledstrip[], int &numActive, int numVar) {
  _newState = digitalRead(_pin);
    //check if state changed, e.g. if it is pressed
  if (_oldState == 0 && _newState == 1) {
    //if it was off, turn it on and reverse
    if (_value == 0) {
      _value = 1;
    } else {
      _value = 0;
    }
  }
  _oldState = _newState;
  switch (_value) {
    case 0:
      for (int i = 0; i < _numLEDs; i++) {
        ledstrip[i] = CHSV(160, 200, 200);
        FastLED.show();
        numActive+=numVar; //add the number of variables in complex layer to number of active variables
      }
      break;
    case 1:
      for (int i = 0; i < _numLEDs; i++) {
        ledstrip[i] = CHSV(160, 200, 0);
        FastLED.show();
        numActive-=numVar;//substract
      }
      break;
  }
}

void DataButton::complexButtonPress(CRGB *ledstrip, int &numActive) {
  _newState = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_oldState == 0 && _newState == 1) {
    //if it was off, turn it on and reverse
    if (_value == 0) {
      _value = 1;
    } else {
      _value = 0;
    }
  }
  switch (_value) {
    case 0:
      for (int i = _startLED; i <= _endLED; i++) {
        ledstrip[i] = CHSV(160, 200, 200);
        FastLED.show();
        numActive++; //add one to active variables
      }
      break;
    case 1:
      for (int i = _startLED; i <= _endLED; i++) {
        ledstrip[i] = CHSV(160, 200, 0);
        FastLED.show();
        numActive--; //minus 1 for number of active variables
      }
      break;
  }
}