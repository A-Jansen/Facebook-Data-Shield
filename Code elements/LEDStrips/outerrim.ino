void outerrimLEDS() {
 // speedLight = active / 31 * 60;

  Serial.println(active);
  EVERY_N_MILLISECONDS(60) {
    brightness = active / 31 * 255;  //calculate based on active/total number
    leds_OUTERRIM[0] = CHSV(160, random8(), random8(100, 255));
    for (int i = NUM_LEDS_OUTERRIM - 1; i > 0; i--) {
      leds_OUTERRIM[i] = leds_OUTERRIM[i - 1];
    }
  }
}