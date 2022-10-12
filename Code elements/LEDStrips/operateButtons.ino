void complexButtons() {
  //complexButtonsCore1[0].complexButtonPress(leds_COMPLEX,active);
  // //for loop over all the buttons in the complex layer and saying they should change the leds in the leds_COMPLEX
  for (int i = 0; i < sizeof(complexButtonsCore1); i++) {
    complexButtonsCore1[i].complexButtonPress(leds_COMPLEX, active);
  }
  for (int i = 0; i < sizeof(complexButtonsCore2); i++) {
    complexButtonsCore2[i].complexButtonPress(leds_COMPLEX, active);
  }
  for (int i = 0; i < sizeof(complexButtonsCore3); i++) {
    complexButtonsCore3[i].complexButtonPress(leds_COMPLEX, active);
  }
  for (int i = 0; i < sizeof(complexButtonsCore4); i++) {
    complexButtonsCore4[i].complexButtonPress(leds_COMPLEX, active);
  }
  for (int i = 0; i < sizeof(complexButtonsCore5); i++) {
    complexButtonsCore5[i].complexButtonPress(leds_COMPLEX, active);
  }
}


void coreButtonsFunction() {

  //checking if one of the core buttons is pressed and sending the ledstrip it should turn on or off
  for (int i = 0; i < sizeof(coreButtons); i++) {

    switch (i) {
      Serial.print("core button: ");
      Serial.println(i);
      case 0:
       coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader1);

        // if (digitalRead(corebutton1) == LOW) {
        //   for (int i = 0; i <= sizeof(ader1); i++) {
        //     int j = ader1[i];
        //     leds_COMPLEX[j] = CHSV(160, 200, 200);
        //     FastLED.show();
        //   }
        // } else {
        //   for (int i = 0; i <= sizeof(ader1); i++) {
        //     int j = ader1[i];
        //     leds_COMPLEX[j] = CHSV(160, 200, 0);
        //     FastLED.show();
        //   }
        // }
        break;
      case 1:
        coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader2);
        // if (digitalRead(corebutton1) == LOW && prevRead == HIGH) {
        //   prevRead=digitalRead(corebutton1);
        //   if (value == 0) {
        //     value=1;
        //     for (int i = 0; i <= sizeof(ader2); i++) {
        //       int j = ader2[i];
        //       leds_COMPLEX[j] = CHSV(160, 200, 200);
        //       FastLED.show();
        //     }

        //   } else {
        //     value=0;
        //     for (int i = 0; i <= sizeof(ader2); i++) {
        //       int j = ader2[i];
        //       leds_COMPLEX[j] = CHSV(160, 200, 0);
        //       FastLED.show();
        //     }
        //   }

       // }
        break;
      case 2:
        coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX,active, ader3);
        break;
      case 3:
        coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader4);
        break;
      case 4:
        coreButtons[i].coreButtonPress(leds_CORE,leds_COMPLEX, active, ader5);
        break;
    }
  }
}



// void changeAder(int[] ader, int brightness) {
//   for (int i = 0; i <= sizeof(ader); i++) {
//     leds_COMPLEX[i] = CHSV(160, 200, brightness);
//     FastLED.show();
//   }
// }