// turn only once and turn back during reset!!!!

void turnShield() {
  if (turning) {
    fill_solid(leds_OUTERRIM, NUM_LEDS_OUTERRIM, CHSV(128, 200, brightnessOverall));
    //myStepper.step(stepsPerRevolution);
    delay(1000);
    turning = false;
  }
}