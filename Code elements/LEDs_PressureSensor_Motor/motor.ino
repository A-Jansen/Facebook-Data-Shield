// turn only once and turn back during reset!!!!

void turnShield() {

  if (turning) {
    Serial.println("turning");
    fill_solid(leds_OUTERRIM, NUM_LEDS_OUTERRIM, CHSV(128, 200, 250));
    turnCounterclockwise();
    //delay(1000);
    Serial.println(turning);
  }
}

void turnCounterclockwise() {
  endstop1 = digitalRead(pin_endstop1);

  if (endstop1 == HIGH) {
    myStepper.step(-1);
    Serial.println("Turning counter clockwise");
   } else {
   //when the end stop is hit it is LOW
    clockwise = 1;
    turning = false;
    Serial.println("Endstop 1 hit, change direction");
  }
}

void turnClockwise() {
  endstop2 = digitalRead(pin_endstop2);
  if (endstop2 == HIGH) {
    myStepper.step(1);
    Serial.println("Turning clockwise");
  } else {
    clockwise = 0;
    turning = false;
    turningBack = false;
    Serial.println("Endstop 2 hit, change direction");
  }
}