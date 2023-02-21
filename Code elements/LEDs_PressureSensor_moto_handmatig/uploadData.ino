void sendInteraction(int ID, int buttonID, int activated) {
  //Serial.print("ID: ");
  //Serial.println(ID);
  //send first some indicator that it is just one interaction data
  //send: ID, which button pressed, if it is turned on or off
  //format: r ID(4) button(2) 0/1
  //"r0001010" => id =0001 and button=01 and it is off (0)
  Serial1.print('r');
  if (ID < 1000) Serial1.print('0');
  if (ID < 100) Serial1.print('0');
  if (ID < 10) Serial1.print('0');
  Serial1.print(ID);
  if (buttonID < 10) Serial1.print('0');
  Serial1.print(buttonID);           //int 01,02,03,04,05 for the core and 11,12,... 21, 21, ... for buttons in complex layer
  Serial1.println(activated);  //int 0 or 1
  // Serial.print("Send interaction: ");
  // Serial.print(ID);
  // Serial.print(", ");
  // Serial.println(activated);
  Serial.print('r');
 if (ID < 1000) Serial.print('0');
  if (ID < 100) Serial.print('0');
  if (ID < 10) Serial.print('0');
  Serial.print(ID);
  if (buttonID < 10) Serial.print('0');
  Serial.print(buttonID);           //int 01,02,03,04,05 for the core and 11,12,... 21, 21, ... for buttons in complex layer
  Serial.println(activated);  //int 0 or 1
}

void sendUpload(int ID) {
  //send: ID, button1, button2, final states of all buttons (31): all 0 or 1
  //format: u ID(4) button1(1)  button2(1)  0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,....
  //Serial.println("Send upload");
  Serial1.print('u');
  if (ID < 1000) Serial1.print('0');
  if (ID < 100) Serial1.print('0');
  if (ID < 10) Serial1.print('0');
  Serial1.print(ID);
  Serial1.print(button1ID);
  Serial1.print(button2ID);
  for (int i = 0; i < numCoreButtons; i++) {
    Serial1.print(coreButtons[i].checkState());
    Serial1.print(',');
  }
  for (int i = 0; i < numComplex1; i++) {
    Serial1.print(complexButtonsCore1[i].checkState());
    Serial1.print(',');
  }
  for (int i = 0; i < numComplex2; i++) {
    Serial1.print(complexButtonsCore2[i].checkState());
    Serial1.print(',');
  }
  for (int i = 0; i < numComplex3; i++) {
    Serial1.print(complexButtonsCore3[i].checkState());
    Serial1.print(',');
  }
  for (int i = 0; i < numComplex4; i++) {
    Serial1.print(complexButtonsCore4[i].checkState());
    Serial1.print(',');
  }
  for (int i = 0; i < numComplex5; i++) {
    Serial1.print(complexButtonsCore5[i].checkState());
    Serial1.print(',');
  }

    Serial.print('u');
  if (ID < 1000) Serial.print('0');
  if (ID < 100) Serial.print('0');
  if (ID < 10) Serial.print('0');
  Serial.print(ID);
  Serial.print(button1ID);
  Serial.print(button2ID);
  for (int i = 0; i < numCoreButtons; i++) {
    Serial.print(coreButtons[i].checkState());
    Serial.print(',');
  }
  for (int i = 0; i < numComplex1; i++) {
    Serial.print(complexButtonsCore1[i].checkState());
    Serial.print(',');
  }
  for (int i = 0; i < numComplex2; i++) {
    Serial.print(complexButtonsCore2[i].checkState());
    Serial.print(',');
  }
  for (int i = 0; i < numComplex3; i++) {
    Serial.print(complexButtonsCore3[i].checkState());
    Serial.print(',');
  }
  for (int i = 0; i < numComplex4; i++) {
    Serial.print(complexButtonsCore4[i].checkState());
    Serial.print(',');
  }
  for (int i = 0; i < numComplex5; i++) {
    Serial.print(complexButtonsCore5[i].checkState());
    Serial.print(',');
  }
}