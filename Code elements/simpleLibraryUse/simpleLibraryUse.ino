#include <DataButton.h>

//DataButton name(pin, startValue, endValue) start and end of LED
DataButton uploadButton(32, 0, 1);


DataButton coreButtons[] = {
  DataButton(22, 0, 170),
  DataButton(24, 0, 150),
  DataButton(26, 0, 120),
  DataButton(28, 0, 70),
  DataButton(30, 0, 50),
};

DataButton complexButtons[] = {
  DataButton(42, 0, 12), DataButton(44, 13, 18), DataButton(46, 19, 30), DataButton(48, 31, 54),  //31>33
  DataButton(50, 55, 69), DataButton(23, 70, 85), DataButton(25, 86, 93), DataButton(27, 94, 114), DataButton(29, 115, 127),
  DataButton(31, 128, 140), DataButton(33, 141, 148), DataButton(35, 149, 163), DataButton(37, 164, 176), DataButton(39, 177, 182),
  DataButton(41, 183, 192), DataButton(43, 193, 212), DataButton(47, 213, 228), DataButton(49, 229, 236), DataButton(51, 237, 246),
  DataButton(52, 247, 258), DataButton(53, 259, 284), DataButton(2, 285, 300), DataButton(3, 301, 314), DataButton(4, 315, 335),
  DataButton(5, 336, 367), DataButton(5, 368, 383)
};


void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  // put your setup code here, to run once:
}

void loop() {
  for (int i = 0; i < sizeof(coreButtons); i++) {
    coreButtons[i].coreButtonPress();
  }
  for (int i = 0; i < sizeof(complexButtons); i++) {
    complexButtons[i].complexButtonPress();
  }
}