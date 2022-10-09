#include <DataButton.h>
#include <FastLED.h>

//LED strips -----------------------------
#define LED_PIN_OUTSIDE 9
#define LED_PIN_CIRCLE1 45
#define LED_PIN_CIRCLE2 34
#define LED_PIN_CIRCLE3 36
#define LED_PIN_CIRCLE4 38
#define LED_PIN_CIRCLE5 40
#define LED_PIN_FAT 12
#define LED_PIN_BIG 10

#define NUM_LEDS_OUTSIDE 500  //leds in complex layer?
#define NUM_LEDS_CIRCLE1 170
#define NUM_LEDS_CIRCLE2 150
#define NUM_LEDS_CIRCLE3 120
#define NUM_LEDS_CIRCLE4 70
#define NUM_LEDS_CIRCLE5 50
#define NUM_LEDS_BIG 300  //outer rim
#define NUM_LEDS_FAT 120

CRGB leds_OUTSIDE[NUM_LEDS_OUTSIDE];
CRGB leds_CIRCLE1[NUM_LEDS_CIRCLE1];
CRGB leds_CIRCLE2[NUM_LEDS_CIRCLE2];
CRGB leds_CIRCLE3[NUM_LEDS_CIRCLE3];
CRGB leds_CIRCLE4[NUM_LEDS_CIRCLE4];
CRGB leds_CIRCLE5[NUM_LEDS_CIRCLE5];
CRGB leds_FAT[NUM_LEDS_FAT];
CRGB leds_BIG[NUM_LEDS_BIG];
//---------------------------------------

//------ DataButton objects
//DataButton name(pin, startValue, endValue) start and end of LED
DataButton uploadButton(32, 0, 1);


DataButton coreButtons[] = {
  DataButton(22, 0, 170),
  DataButton(24, 0, 150),
  DataButton(26, 0, 120),
  DataButton(28, 0, 70),
  DataButton(30, 0, 50)
};


DataButton complexButtons[] = {
  DataButton(42, 0, 12), DataButton(44, 13, 18), DataButton(46, 19, 30), DataButton(48, 31, 54),  //31>33
  DataButton(50, 55, 69), DataButton(23, 70, 85), DataButton(25, 86, 93), DataButton(27, 94, 114), DataButton(29, 115, 127),
  DataButton(31, 128, 140), DataButton(33, 141, 148), DataButton(35, 149, 163), DataButton(37, 164, 176), DataButton(39, 177, 182),
  DataButton(41, 183, 192), DataButton(43, 193, 212), DataButton(47, 213, 228), DataButton(49, 229, 236), DataButton(51, 237, 246),
  DataButton(52, 247, 258), DataButton(53, 259, 284), DataButton(2, 285, 300), DataButton(3, 301, 314), DataButton(4, 315, 335),
  DataButton(5, 336, 367), DataButton(5, 368, 383)
};
//---------------------------



//--------------------------------------
//Variables sketch
int speedLight=60; 
int brightness = 255;
float adjuster =1; //multiplier for speedLight and Brightness based on how much is on/off --> 0 if all off, 1 all on
int active=31;

void setup() {
  Serial.begin(9600);
 Serial.println("Starting");
  FastLED.addLeds<WS2812B, LED_PIN_OUTSIDE, GRB>(leds_OUTSIDE, NUM_LEDS_OUTSIDE);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE1, GRB>(leds_CIRCLE1, NUM_LEDS_CIRCLE1);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE2, GRB>(leds_CIRCLE2, NUM_LEDS_CIRCLE2);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE3, GRB>(leds_CIRCLE3, NUM_LEDS_CIRCLE3);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE4, GRB>(leds_CIRCLE4, NUM_LEDS_CIRCLE4);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE5, GRB>(leds_CIRCLE5, NUM_LEDS_CIRCLE5);
  FastLED.addLeds<WS2812B, LED_PIN_FAT, GRB>(leds_FAT, NUM_LEDS_FAT);
  FastLED.addLeds<WS2812B, LED_PIN_BIG, GRB>(leds_BIG, NUM_LEDS_BIG);
   
}

void loop() {
Serial.println(adjuster);
   fill_solid(leds_FAT, NUM_LEDS_FAT, CHSV(170, 200, 50));

  speedLight=active/31*60;
  EVERY_N_MILLISECONDS(speedLight) {
    brightness= active/31*255;//calculate based on active/total number
    leds_BIG[0] = CHSV(160, random8(), brightness);//random8(100, 255)
    for (int i = NUM_LEDS_BIG - 1; i > 0; i--) {
      leds_BIG[i] = leds_BIG[i - 1];
    }
  }

  //checking if one of the core buttons is pressed and sending the ledstrip it should turn on or off
  coreButtons[0].coreButtonPress(leds_CIRCLE1, active,6); //adjust the number for how many variables are connected to it
  Serial.println(adjuster);
  coreButtons[1].coreButtonPress(leds_CIRCLE2, active,7);
  coreButtons[2].coreButtonPress(leds_CIRCLE3, active, 9);
  coreButtons[3].coreButtonPress(leds_CIRCLE4, active,2);
  coreButtons[4].coreButtonPress(leds_CIRCLE5, active,3);

//for loop over all the buttons in the complex layer and saying they should change the leds in the leds_OUTSIDE
  for (int i = 0; i < sizeof(complexButtons); i++) {
    complexButtons[i].complexButtonPress(leds_OUTSIDE, active);
  }
}