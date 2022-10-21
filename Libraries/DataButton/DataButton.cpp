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
  _value = 1;
  _groupBrightness;
  _oldNumActiveGroup;
  _maxActive;
  _reading;
  _buttonState;
  _lastButtonState = HIGH;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
  _pressed = false;
}

void DataButton::setNumActiveGroup(int numActiveGroup) {
  _oldNumActiveGroup = numActiveGroup;
  _maxActive = numActiveGroup;
}

void DataButton::reset() {
  _lastButtonState = HIGH;
  _lastDebounceTime = 0;
  _value = 1;
}


void DataButton::coreButtonPress(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[], int aderLen, int &numActiveGroup, int maxGroup) {
  _reading = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (_reading != _buttonState) {
      _buttonState = _reading;

      if (_buttonState == LOW) {
        //if all the subgroups are turned off, the core button should as be considered off and hence turn on when pressed/
        //to achieve this, switch the state of the button
        if ((numActiveGroup != maxGroup) && (numActiveGroup != 0)) {
          _value = 1;
          // if (_value == 0) {
          //   _value = 1;
          // } else {
          //   _value = 0;
          // }
        }
        //if it was off, turn it on and reverse
        if (_value == 0) {
          _value = 1;
          _pressed = true;
          numActiveGroup = maxGroup;
          numActive = numActive + _associatedVars + 1;  //add the number of variables in complex layer to number of active variables
          for (int i = _startLED; i <= _endLED; i++) {
            // brightnessOverall=int(map(active, 0, 31, 0, 255));
            ledstrip[i] = CHSV(160, 200, 250);
            FastLED.show();
          }
          for (int i = 0; i < aderLen; i++) {
            int j = ader[i];
            ledstrip2[j] = CHSV(160, 200, 250);
            FastLED.show();
          }

        } else {
          _value = 0;
          _pressed = true;
          numActiveGroup = 0;
          numActive = numActive - _associatedVars - 1;  //substract
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 0);
            FastLED.show();
          }
          for (int i = 0; i < aderLen; i++) {
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


void DataButton::complexButtonPress(CRGB *ledstrip, int &numActive, int &numActiveGroup) {
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
          _pressed = true;
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 250);
            FastLED.show();
          }
          numActive = numActive + 1;  //add the number of variables in complex layer to number of active variables
          numActiveGroup = numActiveGroup + 1;
        } else {
          _value = 0;
          _pressed = true;
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 0);
            FastLED.show();
          }
          numActive = numActive - 1;  //substract
          numActiveGroup = numActiveGroup - 1;
        }
      }
    }
  }
  _lastButtonState = _reading;
}


void DataButton::turnComplexOn(CRGB ledstrip[]) {
  for (int i = _startLED; i <= _endLED; i++) {
    ledstrip[i] = CHSV(160, 200, 250);
    FastLED.show();
  }
  _value = 1;
}

void DataButton::turnCoreOn(CRGB ledstrip[], CRGB *ledstrip2, int &numActive, int ader[], int aderLen, int &numActiveGroup) {
  _value = 1;
  // _pressed = true;
  numActive = numActive + _associatedVars + 1;  //add the number of variables in complex layer to number of active variables
  for (int i = _startLED; i <= _endLED; i++) {
    // brightnessOverall=int(map(active, 0, 31, 0, 255));
    ledstrip[i] = CHSV(160, 200, 250);
    FastLED.show();
  }
  for (int i = 0; i < aderLen; i++) {
    int j = ader[i];
    ledstrip2[j] = CHSV(160, 200, 250);
    FastLED.show();
  }
}


void DataButton::turnComplexOff(CRGB ledstrip[]) {
  for (int i = _startLED; i <= _endLED; i++) {
    ledstrip[i] = CHSV(160, 200, 00);
    FastLED.show();
  }
  _value = 0;
}

void DataButton::changeGroupBrightness(CRGB ledstrip[], CRGB *ledstrip2, int &numActiveGroup, int ader[], int aderLen) {
  if (numActiveGroup != _oldNumActiveGroup) {
    _groupBrightness = int(map(numActiveGroup, 0, _maxActive, 0, 250));
    if (_value == 1) {
      for (int i = _startLED; i <= _endLED; i++) {
        // brightnessOverall=int(map(active, 0, 31, 0, 255));
        ledstrip[i] = CHSV(160, 200, _groupBrightness);
        FastLED.show();
      }
      for (int i = 0; i < aderLen; i++) {
        int j = ader[i];
        ledstrip2[j] = CHSV(160, 200, _groupBrightness);
        FastLED.show();
      }
    } else {
      for (int i = _startLED; i <= _endLED; i++) {
        // brightnessOverall=int(map(active, 0, 31, 0, 255));
        ledstrip[i] = CHSV(160, 200, _groupBrightness);
        FastLED.show();
      }
      for (int i = 0; i < aderLen; i++) {
        int j = ader[i];
        ledstrip2[j] = CHSV(160, 200, _groupBrightness);
        FastLED.show();
      }
    }
    _oldNumActiveGroup = numActiveGroup;
  }
}


void DataButton::uploadButtonPress(CRGB *ledstrip, int &numActive, bool &upload) {
  _reading = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (_reading != _buttonState) {
      _buttonState = _reading;

      if (_buttonState == LOW) {
        upload = true;
        fill_solid(ledstrip, 37, CHSV(96, 200, 250));
        for (int i = 78; i <= 83; i++) {
          ledstrip[i] = CHSV(96, 200, 200);
        }
        //set shortly off and slowly turn it on
        for (int j = 0; j < 5; j++) {
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 00);
            FastLED.show();
          }
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 00);
            FastLED.show();
          }
          for (int i = _startLED; i <= _endLED; i++) {
            ledstrip[i] = CHSV(160, 200, 250);
            FastLED.show();
          }
        }
        fill_solid(ledstrip, 37, CHSV(160, 200, 250));
        for (int i = 78; i <= 83; i++) {
          ledstrip[i] = CHSV(160, 200, 200);
        }
      }
    }
  }
  _lastButtonState = _reading;
}

void DataButton::turn(bool &turning, bool &firstTurn) {
  _reading = digitalRead(_pin);
  //check if state changed, e.g. if it is pressed
  if (_reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (_reading != _buttonState) {
      _buttonState = _reading;

      if (_buttonState == LOW) {
        //button is pressed for sure
        turning = true;
        firstTurn = true;
      }
    }
  }
  _lastButtonState = _reading;
}

bool DataButton::pressedButton() {
  return _pressed;
}

void DataButton::dePressButton() {
  _pressed = false;
}

int DataButton::checkState() {
  return _value;
}