void turnAllOn() {
  //rechte stukje naar core button1
  for (int i = 78; i <= 83; i++) {
    leds_CORE[i] = CHSV(60, 200, 200);
  }

  for (int i = 0; i < NUM_LEDS_CORE; i++) {
    leds_CORE[i] = CHSV(160, 200, 200);
  }
  for (int i = 0; i < NUM_LEDS_COMPLEX; i++) {
    leds_COMPLEX[i] = CHSV(160, 200, 200);
  }
  coreButtons[0].setNumActiveGroup(7);
  coreButtons[1].setNumActiveGroup(6);
  coreButtons[2].setNumActiveGroup(4);
  coreButtons[3].setNumActiveGroup(7);
  coreButtons[4].setNumActiveGroup(2);

  //inner circle of the core
  fill_solid(leds_CORE, 37, CHSV(160, 200, brightnessOverall));
}

void resetInstallation() {
  resetOnce = 1;
  Serial.println("Reset");
  turnAllOn();
  speedLight = 60;
  fullSpeed = 6;
  brightnessOverall = 255;

  activeCoreGroup1 = 7;
  activeCoreGroup2 = 6;
  activeCoreGroup3 = 4;
  activeCoreGroup4 = 7;
  activeCoreGroup5 = 1;
  active = 31;

  twobuttons = true;
  counter=0;
}

// void checkTwoHighs() {
//   //if two highs, save them to button1 and button2 and use them as unique identifiers
//   // can only be in the core + upload button
//   int counter = 0;
//   int but1;
//   int but2;
//  // Serial.println("check point check two highs");
//   for (int i = 0; i < numCoreButtons; i++) {
//     if (coreButtons[i].pressedButton()) {
//       Serial.println("Button pressed check two hihgs");
//       // counter++;
//       // if (counter == 0) {
//       //   but1 = i;
//       // } else {
//       //   but2 = i;
//       // }
//     }
//   }
//   // if (counter == 2) {
//   //   startTwoMillis = millis();
//   //   button1ID = but1;
//   //   button2ID = but2;
//   //   twobuttons = false;
//   //   Serial.println(button1ID);
//   //   Serial.println(button2ID);

//   //   if ((millis() - startTwoMillis) < 500) {
//   //     fill_solid(leds_CORE, 37, CHSV(96, 200, brightnessOverall));
//   //   } else {
//   //     fill_solid(leds_CORE, 37, CHSV(160, 200, brightnessOverall));
//   //   }
//   // }
// }