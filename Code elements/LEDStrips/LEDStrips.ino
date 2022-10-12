#include <DataButton.h>
#include <FastLED.h>

//LED strips -----------------------------
#define LED_PIN_CORE 8
#define LED_PIN_COMPLEX 9
#define LED_PIN_OUTERRIM 10

#define NUM_LEDS_CORE 86
#define NUM_LEDS_COMPLEX 232   //leds in complex layer
#define NUM_LEDS_OUTERRIM 277  //outer rim

CRGB leds_CORE[NUM_LEDS_CORE];
CRGB leds_COMPLEX[NUM_LEDS_COMPLEX];
CRGB leds_OUTERRIM[NUM_LEDS_OUTERRIM];
//---------------------------------------

//define buttonpins, met de klok mee
#define uploadbuttonpin 5

#define corebutton1 7
#define corebutton2 2
#define corebutton3 6
#define corebutton4 4
#define corebutton5 3

#define complexbutton1_1 39
#define complexbutton1_2 25
#define complexbutton1_3 35
#define complexbutton1_4 38
#define complexbutton1_5 16
#define complexbutton1_6 32
#define complexbutton1_7 31

#define complexbutton2_1 34
#define complexbutton2_2 30
#define complexbutton2_3 17
#define complexbutton2_4 33
#define complexbutton2_5 27
#define complexbutton2_6 13

#define complexbutton3_1 28
#define complexbutton3_2 12
#define complexbutton3_3 15
#define complexbutton3_4 22

#define complexbutton4_1 37
#define complexbutton4_2 40
#define complexbutton4_3 24
#define complexbutton4_4 23
#define complexbutton4_5 36
#define complexbutton4_6 29
#define complexbutton4_7 26

#define complexbutton5_1 11
#define complexbutton5_2 14

#define matpin 41  //voor de pressure sensor voetmat

/////// Aders connecting core and complex layer
int ader1[] = { 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106 };
int ader2[] = { 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 72, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
int ader3[] = { 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54 };
int ader4[] = { 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37 };
int ader5[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

int prevRead=1;
int value=0;

//------ DataButton objects
//DataButton name(buttonpin, startValue, endValue) start and end of LED
DataButton uploadButton(uploadbuttonpin, 64, 76, 1);  // check this one!!!


DataButton coreButtons[] = {
  DataButton(corebutton1, 84, 86, 7),
  DataButton(corebutton2, 57, 62, 6),  //check this one!!!!
  DataButton(corebutton3, 51, 56, 4),
  DataButton(corebutton4, 44, 50, 7),
  DataButton(corebutton5, 37, 43, 2)
};

char *coreNames[] = { "yourBehavior", "yourTechnologicalSetup", "YourDemographicInformation", "Post-RelatedInformation" };


DataButton complexButtonsCore1[] = {
  DataButton(complexbutton1_1, 107, 111, 1), DataButton(complexbutton1_2, 111, 116, 1), DataButton(complexbutton1_3, 117, 121, 1), DataButton(complexbutton1_4, 122, 126, 1),
  DataButton(complexbutton1_5, 127, 131, 1), DataButton(complexbutton1_6, 132, 136, 1), DataButton(complexbutton1_7, 137, 141, 1)
};


DataButton complexButtonsCore2[] = {
  DataButton(complexbutton2_1, 142, 146, 1), DataButton(complexbutton2_2, 147, 151, 1), DataButton(complexbutton2_3, 152, 156, 1), DataButton(complexbutton2_4, 157, 161, 1),
  DataButton(complexbutton2_5, 162, 166, 1), DataButton(complexbutton2_6, 167, 171, 1)
};

DataButton complexButtonsCore3[] = {
  DataButton(complexbutton3_1, 172, 177, 1), DataButton(complexbutton3_2, 178, 182, 1), DataButton(complexbutton3_3, 183, 187, 1), DataButton(complexbutton3_4, 188, 191, 1)
};


DataButton complexButtonsCore4[] = {
  DataButton(complexbutton4_1, 192, 196, 1), DataButton(complexbutton4_2, 197, 201, 1), DataButton(complexbutton4_3, 202, 206, 1), DataButton(complexbutton4_4, 207, 211, 1),
  DataButton(complexbutton4_5, 212, 216, 1), DataButton(complexbutton4_6, 217, 221, 1), DataButton(complexbutton4_7, 222, 226, 1)
};

DataButton complexButtonsCore5[] = {
  DataButton(complexbutton5_1, 227, 231, 1), DataButton(complexbutton5_2, 232, 232, 1)
};
//---------------------------



//--------------------------------------
//Variables sketch
int speedLight = 60;
int brightness = 255;
float adjuster = 1;  //multiplier for speedLight and Brightness based on how much is on/off --> 0 if all off, 1 all on
int active = 31;

//Variables for logging data
int button1;
int button2;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  FastLED.addLeds<WS2812B, LED_PIN_COMPLEX, GRB>(leds_COMPLEX, NUM_LEDS_COMPLEX);
  FastLED.addLeds<WS2812B, LED_PIN_CORE, GRB>(leds_CORE, NUM_LEDS_CORE);
  FastLED.addLeds<WS2812B, LED_PIN_OUTERRIM, GRB>(leds_OUTERRIM, NUM_LEDS_OUTERRIM);
  pinMode(corebutton1, INPUT_PULLUP);
  pinMode(corebutton2, INPUT_PULLUP);
  pinMode(corebutton3, INPUT_PULLUP);
  pinMode(corebutton4, INPUT_PULLUP);
  pinMode(corebutton5, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(corebutton1));
  // Serial.println(adjuster);
  // outerrimLEDS();
  uploadButton.uploadButtonPress(leds_CORE, active);
  coreButtonsFunction();
  complexButtons();
  fill_solid(leds_CORE, 37, CRGB::Red);
  for (int i = 78; i<=83;i++){
    leds_CORE[i] = CHSV(60, 200, 200);
  }

    for (int i = 84; i<=87;i++){
    leds_CORE[i] = CHSV(60, 200, 200);
  }
  fill_solid(leds_OUTERRIM, NUM_LEDS_OUTERRIM, CRGB::Blue);
  FastLED.show();
}