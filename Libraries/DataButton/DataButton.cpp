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
  _reading;
  _buttonState;
  _lastButtonState = HIGH;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
}

void DataButton::coreButtonPress(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[]) {
  _reading = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (_reading != _buttonState) {
      _buttonState = _reading;

      if (_buttonState == LOW) {

        //if it was off, turn it on and reverse
        if (_value == 0) {
          _value = 1;
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
        } else {
          _value = 0;
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
        }
      }
    }
  }
  _lastButtonState = _reading;
}


void DataButton::complexButtonPress(CRGB *ledstrip, int &numActive) {
  _reading = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (_reading != _buttonState) {
      _buttonState = _reading;

      if (_buttonState == LOW) {

        //if it was off, turn it on and reverse
        if (_value == 0) {
          _value = 1;
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 200);
            FastLED.show();
            numActive++;  //add the number of variables in complex layer to number of active variables
          }
        } else {
          _value = 0;
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 0);
            FastLED.show();
            numActive--;  //substract
          }
        }
      }
    }
  }
  _lastButtonState = _reading;
}


void DataButton::uploadButtonPress(CRGB *ledstrip, int &numActive) {
  _reading = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (_reading != _buttonState) {
      _buttonState = _reading;

      if (_buttonState == LOW) {

        //if it was off, turn it on and reverse
        if (_value == 0) {
          _value = 1;
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 200);
            FastLED.show();
            numActive++;  //add the number of variables in complex layer to number of active variables
          }
        } else {
          _value = 0;
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 0);
            FastLED.show();
            numActive--;  //substract
          }
        }
      }
    }
  }
  _lastButtonState = _reading;
}


bool DataButton::checkFinalState() {
  _newState = digitalRead(_pin);
  return (_newState == HIGH);
}