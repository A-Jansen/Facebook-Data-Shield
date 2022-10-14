void outerrimLEDS() {
  speedLight = int(map(active, 31, 0, 200,6 ));
  // Serial.println(active);
  //lager is sneller
  EVERY_N_MILLISECONDS(speedLight) {
    brightnessOverall = active / 31 * 255;  //calculate based on active/total number
    leds_OUTERRIM[0] = CHSV(160, random8(), brightnessOverall);
    for (int i = NUM_LEDS_OUTERRIM - 1; i > 0; i--) {
      leds_OUTERRIM[i] = leds_OUTERRIM[i - 1];
    }
  }
}