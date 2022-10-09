int pin_pressureMat = 3;

int pressureMat;
int thisState = 0;
int lastState = 0;
bool changeDetected = 0;
bool longPause = 1;


int ID = 0;

unsigned long lastLowMillis;
unsigned long lastHighMillis;
int intervalMillisLow = 2000;  //at least 2 seconds low before possible to register second one
int intervalMillisHigh = 500; //at least 500 ms high before adding new ID

void setup() {
  pinMode(pin_pressureMat, INPUT);  //INPUT_PULLUP did not work with my Arduino Uno, via 10k to gnd instead

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  checkPresence();
}

void checkPresence() {
  thisState = digitalRead(pin_pressureMat);
  if (thisState == HIGH && lastState != thisState) {
    lastState = thisState;
    lastLowMillis = millis();
    changeDetected = 1;
  } else if (thisState == LOW && lastState != thisState) {
    lastState = thisState;
    lastHighMillis = millis();
  } else if (!changeDetected) {
    lastLowMillis = millis();
  }

  if (thisState == LOW) {
    if (millis() - lastHighMillis > intervalMillisLow) {
      longPause = 1;
      // Serial.println("Longpause");
      lastLowMillis= millis();
    } else {
      longPause = 0;
      // Serial.println(" no Longpause");
    }
  }
  if (millis() - lastLowMillis > intervalMillisHigh && longPause) {
    ID++;
    Serial.print("ID: ");
    Serial.println(ID);
    changeDetected = 0;
  }
  delay(200);
}