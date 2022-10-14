//function for checking if someone is standing in front of the installation on the pressure mat
void checkPresence() {
  //only check if it is not turning --> give people the chance to take a step back
  if (!turning) {
    thisState = digitalRead(pin_pressureSensor);
    // Serial.print("This state: ");
    // Serial.println(thisState);

    //if someone steps on the mat, set time of last low(high) reading --> used to check if at least XXX ms high as to not trigger it with just 1 high reading
    if (thisState == LOW && lastState != thisState) {
      lastState = thisState;
      lastLowMillis = millis();
      changeDetected = 1;
    }
    //if someone steps off the mat, set time of last high reading --> at least certain time low before possible to detect new participant
    else if (thisState == HIGH && lastState != thisState) {
      lastState = thisState;
      lastHighMillis = millis();
    }
    // keep the lastLowMillis up to date when no change is detected
    else if (!changeDetected) {
      lastLowMillis = millis();
    }

    //if the state is low, check for how long and if longer than threshold, make it possible to detect new particpants (longPause)
    if (thisState == HIGH) {
      if (millis() - lastHighMillis > intervalMillisLow) {
        longPause = 1;
        // Serial.println("Longpause");
        if (!resetOnce) {
          resetInstallation();
        }
        lastLowMillis = millis();

      } else {
        longPause = 0;
        // Serial.println(" no Longpause");
      }
    }

    //if at least intervalMillisHigh ms a high reading, and before at least intervalMillisLow ms no reading --> increase the ID and set change detected back to 0
    if (millis() - lastLowMillis > intervalMillisHigh && longPause) {
      resetOnce=0;
      ID++;
      Serial.print("ID: ");
      Serial.println(ID);
      changeDetected = 0;
    }
    //  delay(200);
  }
}