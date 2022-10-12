#include "Arduino.h"
#include "DataButton.h"

DataButton::DataButton(int pin, int startLED, int endLED, int associatedVars) {
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _startLED = startLED;
  _endLED = endLED;
  _numLEDs = _endLED - _startLED;
  _associatedVars = associatedVars;
  _oldState = 1;
  _newState;
  _value = 0;
  _lastDebounceTime =0;;
  _debounceDelay=50;
}

void DataButton::coreButtonPress(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[]) {
  _newState = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_oldState == 1 && _newState == 0) {

    //if it was off, turn it on and reverse
    if (_value == 0) {
      _value = 1;
    } else {
      _value = 0;
    }

    //_oldState = _newState;
    switch (_value) {
      case 0:
        for (int i = _startLED; i <= _endLED; i++) {
          ledstrip[i] = CHSV(160, 200, 200);
          FastLED.show();
          numActive += _associatedVars;  //add the number of variables in complex layer to number of active variables
        }
        for (int i = 0; i <= sizeof(ader); i++) {
          int j = ader[i];
          ledstrip2[j] = CHSV(160, 200, 200);
          FastLED.show();
        }
        break;
      case 1:
        for (int i = _startLED; i <= _endLED; i++) {
          ledstrip[i] = CHSV(160, 200, 0);
          FastLED.show();
          numActive -= _associatedVars;  //substract
        }
        for (int i = 0; i <= sizeof(ader); i++) {
          int j = ader[i];
          ledstrip2[j] = CHSV(160, 200, 0);
          FastLED.show();
        }
        break;
    }
  }
}

void DataButton::complexButtonPress(CRGB *ledstrip, int &numActive) {
  _newState = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_oldState == 1 && _newState == 0) {
    //if it was off, turn it on and reverse
    if (_value == 0) {
      _value = 1;
    } else {
      _value = 0;
    }

    switch (_value) {
      case 0:
        for (int i = _startLED; i <= _endLED; i++) {
          ledstrip[i] = CHSV(160, 200, 200);
          FastLED.show();
          numActive++;  //add one to active variables
        }
        break;
      case 1:
        for (int i = _startLED; i <= _endLED; i++) {
          ledstrip[i] = CHSV(160, 200, 0);
          FastLED.show();
          numActive--;  //minus 1 for number of active variables
        }
        break;
    }
 //     _oldState = _newState;
  }
}

void DataButton::uploadButtonPress(CRGB *ledstrip, int &numActive) {
  _newState = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_oldState == 0 && _newState == 1) {
    //if it was off, turn it on and reverse
    if (_value == 0) {
      _value = 1;
    } else {
      _value = 0;
    }

    switch (_value) {
      case 0:
        for (int i = _startLED; i <= _endLED; i++) {
          ledstrip[i] = CHSV(160, 200, 200);
          FastLED.show();
          numActive++;  //add one to active variables
        }
        break;
      case 1:
        for (int i = _startLED; i <= _endLED; i++) {
          ledstrip[i] = CHSV(160, 200, 0);
          FastLED.show();
          numActive--;  //minus 1 for number of active variables
        }
        break;
    }
  }
}


bool DataButton::checkFinalState() {
  _newState = digitalRead(_pin);
  return (_newState == HIGH);
}