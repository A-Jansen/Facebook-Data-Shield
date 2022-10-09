int pin_pressureMat = 3;

int thisState = 0;  //current state of the pressure mat
int lastState = 0;  //last state of the pressure mat
bool changeDetected = 0;
bool longPause = 1;  //ensuring that there is at least intervalMillisLow between reading the first low and the first high --> otherwise on low reading could increase the ID number


int ID = 0;  //id of the current interaction, will be reset when disconnected

unsigned long lastLowMillis;   // stores the millis() of when it first becomes high
unsigned long lastHighMillis;  //stores the millis() of when it first becomes low
int intervalMillisLow = 2000;  //at least 2 seconds low before possible to register second one
int intervalMillisHigh = 500;  //at least 500 ms high before adding new ID

void setup() {
  pinMode(pin_pressureMat, INPUT);  //INPUT_PULLUP did not work with my Arduino Uno, via 10k to gnd instead
  Serial.begin(9600);
}

void loop() {
  checkPresence();
}


//function for checking if someone is standing in front of the installation on the pressure mat
void checkPresence() {
  thisState = digitalRead(pin_pressureMat);

  //if someone steps on the mat, set time of last low reading --> used to check if at least XXX ms high as to not trigger it with just 1 high reading
  if (thisState == HIGH && lastState != thisState) {
    lastState = thisState;
    lastLowMillis = millis();
    changeDetected = 1;
  }
  //if someone steps off the mat, set time of last high reading --> at least certain time low before possible to detect new participant
  else if (thisState == LOW && lastState != thisState) {
    lastState = thisState;
    lastHighMillis = millis();
  }
  // keep the lastLowMillis up to date when no change is detected
  else if (!changeDetected) {
    lastLowMillis = millis();
  }

  //if the state is low, check for how long and if longer than threshold, make it possible to detect new particpants (longPause)
  if (thisState == LOW) {
    if (millis() - lastHighMillis > intervalMillisLow) {
      longPause = 1;
      // Serial.println("Longpause");
      lastLowMillis = millis();
    } else {
      longPause = 0;
      // Serial.println(" no Longpause");
    }
  }

  //if at least intervalMillisHigh ms a high reading, and before at least intervalMillisLow ms no reading --> increase the ID and set change detected back to 0
  if (millis() - lastLowMillis > intervalMillisHigh && longPause) {
    ID++;
    Serial.print("ID: ");
    Serial.println(ID);
    changeDetected = 0;
  }
  delay(200);
}