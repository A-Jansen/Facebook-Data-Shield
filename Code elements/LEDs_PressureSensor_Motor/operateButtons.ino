void coreButtonsFunction() {
  //Serial.println("Core button");


  int but1;
  int but2;
  //checking if one of the core buttons is pressed and sending the ledstrip it should turn on or off
  for (int i = 0; i < numCoreButtons; i++) {
    //Serial.println(coreButtons[i].pressedButton());
    //    switchCoreButtons(i);
      switch (i) {

        case 0:
       //   Serial.println("switch core buttons");
          coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader1, ader1Len, activeCoreGroup1, numComplex1);
          // if(coreButtons[i].checkState()==0){
          //   turnComplexOff();
          // } else
          break;
        case 1:
         // Serial.println("switch core buttons");
          coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader2, ader2Len, activeCoreGroup2, numComplex2);
          break;
        case 2:
          coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader3, ader3Len, activeCoreGroup3, numComplex3);
          break;
        case 3:
          coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader4, ader4Len, activeCoreGroup4, numComplex4);
          break;
        case 4:
          coreButtons[i].coreButtonPress(leds_CORE, leds_COMPLEX, active, ader5, ader5Len, activeCoreGroup5, numComplex5);
          break;
      }
    

    if (coreButtons[i].pressedButton()) {

      // Serial.println("Pressed button core buttons");
      // Serial.println(twobuttons);
      //code at the start for checking if two buttons are pressed together for the id
      if (twobuttons) {
        Serial.println("check for delay");
        if (counter == 0) {
          firstButtonMillis = millis();
          counter = 1;
          but1 = i;

        } else if ((millis() - firstButtonMillis) < 2000) {
          counter = 2;
          skipSwitchOnce =true;
          but2 = i;
          startTwoMillis = millis();
          twobuttons = false;
          twoButtonsChecked = true;
          fill_solid(leds_CORE, 37, CHSV(96, 200, 250));
          for (int i = 78; i <= 83; i++) {
            leds_CORE[i] = CHSV(96, 200, 250);
          }
        } else {
          // Serial.println(millis()-firstButtonMillis);
          twobuttons = false;
        }
        Serial.print("counter: ");
        Serial.println(counter);
        if (counter == 2) {
          switchCoreButtons(but1);
          switchCoreButtons(but2);
          button1ID = but1 + 1;  //+1 so counting starts at 1
          button2ID = but2 + 1;  //,,
        
          // Serial.print("Button1: ");
          // Serial.println(button1ID);
          // Serial.print("button 2: ");
          // Serial.println(button2ID);
        }
      }

      int state = coreButtons[i].checkState();
      int buttonID = i + 1;
      Serial.println(state);
      if (state == 1) {
        turnCompOn(i);

      } else {
        turnCompOff(i);
      }

      sendInteraction(ID, buttonID, state);
      coreButtons[i].dePressButton();
    }
  }
  if (((millis() - startTwoMillis) > 2000) && (twoButtonsChecked)) {
    fill_solid(leds_CORE, 37, CHSV(160, 200, 250));
    for (int i = 78; i <= 83; i++) {
      leds_CORE[i] = CHSV(160, 200, 250);
    }
      turnCoreOnAgain(but1, but2);
    twoButtonsChecked = false;
      skipSwitchOnce =false;
  }
}

void turnCoreOnAgain(int b1, int b2){
  coreButtons[b1].turnComplexOn(leds_CORE);
  coreButtons[b2].turnComplexOn(leds_CORE);

}

void switchCoreButtons(int i) {
  Serial.print("Switch core buttons: ");
  Serial.println(i);
  //  coreButtons[i].reset();
 // turnCompOn(i);
  switch (i) {
    case 0:
      coreButtons[i].turnCoreOn(leds_CORE, leds_COMPLEX, active, ader1, ader1Len, activeCoreGroup1);
      break;
    case 1:
      coreButtons[i].turnCoreOn(leds_CORE, leds_COMPLEX, active, ader2, ader2Len, activeCoreGroup2);
      break;
    case 2:
      coreButtons[i].turnCoreOn(leds_CORE, leds_COMPLEX, active, ader3, ader3Len, activeCoreGroup3);
      break;
    case 3:
      coreButtons[i].turnCoreOn(leds_CORE, leds_COMPLEX, active, ader4, ader4Len, activeCoreGroup4);
      break;
    case 4:
      coreButtons[i].turnCoreOn(leds_CORE, leds_COMPLEX, active, ader5, ader5Len, activeCoreGroup5);
      break;
  }
}


void turnCompOn(int core) {
  Serial.println("switch complex on");
  switch (core) {
    case 0:
      for (int i = 0; i < numComplex1; i++) {
        complexButtonsCore1[i].turnComplexOn(leds_COMPLEX);
      }
      break;
    case 1:
      for (int i = 0; i < numComplex2; i++) {
        complexButtonsCore2[i].turnComplexOn(leds_COMPLEX);
      }
      break;
    case 2:
      for (int i = 0; i < numComplex3; i++) {
        complexButtonsCore3[i].turnComplexOn(leds_COMPLEX);
      }
      break;
    case 3:
      for (int i = 0; i < numComplex4; i++) {
        complexButtonsCore4[i].turnComplexOn(leds_COMPLEX);
      }
      break;
    case 4:
      for (int i = 0; i < numComplex5; i++) {
        complexButtonsCore5[i].turnComplexOn(leds_COMPLEX);
      }
      break;
  }
}

void turnCompOff(int core) {
  Serial.println("switch complex off");
  switch (core) {
    case 0:
      for (int i = 0; i < numComplex1; i++) {
        complexButtonsCore1[i].turnComplexOff(leds_COMPLEX);
      }
      break;
    case 1:
      for (int i = 0; i < numComplex2; i++) {
        complexButtonsCore2[i].turnComplexOff(leds_COMPLEX);
      }
      break;
    case 2:
      for (int i = 0; i < numComplex3; i++) {
        complexButtonsCore3[i].turnComplexOff(leds_COMPLEX);
      }
      break;
    case 3:
      for (int i = 0; i < numComplex4; i++) {
        complexButtonsCore4[i].turnComplexOff(leds_COMPLEX);
      }
      break;
    case 4:
      for (int i = 0; i < numComplex5; i++) {
        complexButtonsCore5[i].turnComplexOff(leds_COMPLEX);
      }
      break;
  }
}

void complexButtons() {
  //Serial.println("complex buttons");
  // Serial.print("Numactive group1: ");
  // Serial.println(activeCoreGroup1);
  // //for loop over all the buttons in the complex layer and saying they should change the leds in the leds_COMPLEX
  // after this check if the number of active buttons in that group changed and if yes, updated the brightness of the "ader" and button in the core
  for (int i = 0; i < numComplex1; i++) {
    complexButtonsCore1[i].complexButtonPress(leds_COMPLEX, active, activeCoreGroup1);
    coreButtons[0].changeGroupBrightness(leds_CORE, leds_COMPLEX, activeCoreGroup1, ader1, ader1Len);
    if (complexButtonsCore1[i].pressedButton()) {
      int state = complexButtonsCore1[i].checkState();
      int buttonID = 11 + i;
      sendInteraction(ID, buttonID, state);
      complexButtonsCore1[i].dePressButton();
    }
  }
  for (int i = 0; i < numComplex2; i++) {
    complexButtonsCore2[i].complexButtonPress(leds_COMPLEX, active, activeCoreGroup2);
    coreButtons[1].changeGroupBrightness(leds_CORE, leds_COMPLEX, activeCoreGroup2, ader2, ader2Len);
    if (complexButtonsCore2[i].pressedButton()) {
      int state = complexButtonsCore2[i].checkState();
      int buttonID = 21 + i;
      sendInteraction(ID, buttonID, state);
      complexButtonsCore2[i].dePressButton();
    }
  }
  for (int i = 0; i < numComplex3; i++) {
    complexButtonsCore3[i].complexButtonPress(leds_COMPLEX, active, activeCoreGroup3);
    coreButtons[2].changeGroupBrightness(leds_CORE, leds_COMPLEX, activeCoreGroup3, ader3, ader3Len);
    if (complexButtonsCore3[i].pressedButton()) {
      int state = complexButtonsCore3[i].checkState();
      int buttonID = 31 + i;
      sendInteraction(ID, buttonID, state);
      complexButtonsCore3[i].dePressButton();
    }
  }
  for (int i = 0; i < numComplex4; i++) {
    complexButtonsCore4[i].complexButtonPress(leds_COMPLEX, active, activeCoreGroup4);
    coreButtons[3].changeGroupBrightness(leds_CORE, leds_COMPLEX, activeCoreGroup4, ader4, ader4Len);
    if (complexButtonsCore4[i].pressedButton()) {
      int state = complexButtonsCore4[i].checkState();
      int buttonID = 41 + i;
      // Serial.print("buttonID: ");
      // Serial.println(buttonID);
      sendInteraction(ID, buttonID, state);
      complexButtonsCore4[i].dePressButton();
    }
  }
  for (int i = 0; i < numComplex5; i++) {
    complexButtonsCore5[i].complexButtonPress(leds_COMPLEX, active, activeCoreGroup5);
    coreButtons[4].changeGroupBrightness(leds_CORE, leds_COMPLEX, activeCoreGroup5, ader5, ader5Len);
    if (complexButtonsCore5[i].pressedButton()) {
      int state = complexButtonsCore5[i].checkState();
      int buttonID = 51 + i;
      sendInteraction(ID, buttonID, state);
      complexButtonsCore5[i].dePressButton();
    }
  }
  //  Serial.print("Complex active changed: ");
  //  Serial.println(active);
}