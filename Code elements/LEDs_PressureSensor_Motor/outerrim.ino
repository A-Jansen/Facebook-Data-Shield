void outerrimLEDS() {
  speedLight = int(map(active, 0, 31, 200, 6));
  // Serial.println(active);
  //lager is sneller
  EVERY_N_MILLISECONDS(speedLight) {
    leds_OUTERRIM[0] = CHSV(160, random8(), brightnessOverall);
    for (int i = NUM_LEDS_OUTERRIM - 1; i > 0; i--) {
      leds_OUTERRIM[i] = leds_OUTERRIM[i - 1];
      //leds_OUTERRIM[i].nscale8(brightnessOverall); //nscale beteween - 256
    }
  }
}

void outerrimLEDSsetup() {
  //start from black
  fill_solid(leds_OUTERRIM, NUM_LEDS_OUTERRIM, CHSV(160, 200, 0));
  //setup an array with different saturation levels so you can see the movement.
  //brigthness is set to full 255
  for (int i = NUM_LEDS_OUTERRIM - 1; i > 0; i--) {
    OUTERRIM_SAT[i] = random8();
    OUTERRIM_COLORS[i] = CHSV(160, OUTERRIM_SAT[i], 255);
  }
}

void outerrimLEDS2() {
  speedLight = int(map(active, 0, 31, 200, 6));
  //lager is sneller
  if (active != oldActive) {
    oldActive = active;
    for (int i = NUM_LEDS_OUTERRIM - 1; i > 0; i--) {
      OUTERRIM_COLORS[i] = CHSV(160, OUTERRIM_SAT[i], brightnessOverall);
      leds_OUTERRIM[i] = OUTERRIM_COLORS[i];
    }
  }
  EVERY_N_MILLISECONDS(speedLight) {
    for (int i = NUM_LEDS_OUTERRIM - 1; i > 0; i--) {
      leds_OUTERRIM[i] = leds_OUTERRIM[i - 1];
      OUTERRIM_COLORS[i] = OUTERRIM_COLORS[i - 1];  //shift the colors accordingly
    }
  }
}