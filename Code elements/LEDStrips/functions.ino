void checkTwoHighs() {
  //if two highs, save them to button1 and button2 and use them as unique identifiers
  // can only be in the core + upload button
  int counter = 0;
  int button1ID;
  int button2ID;
  if (uploadButton.checkFinalState()) {
    counter++;
    button1ID = 6;
  }
  for (int i = 0; i < sizeof(coreButtons); i++) {
    if (coreButtons[i].checkFinalState()) {
      counter++;
      if (counter == 0) {
        button1ID = i;
      } else {
        button2ID = i;
      }
    }
  }
  if (counter == 2) {
    button1 = button1ID;
    button2 = button2ID;
  }
}