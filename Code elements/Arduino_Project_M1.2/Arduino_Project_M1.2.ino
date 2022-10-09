#include <FastLED.h>
//#include <OneButton.h>
#define LED_PIN_OUTSIDE 9
#define LED_PIN_CIRCLE1 45
#define LED_PIN_CIRCLE2 34
#define LED_PIN_CIRCLE3 36
#define LED_PIN_CIRCLE4 38
#define LED_PIN_CIRCLE5 40
#define LED_PIN_FAT 12
#define LED_PIN_BIG 10

#define NUM_LEDS_OUTSIDE 500  //what is the difference with big?
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



int dt = 50;

int LEDPin = 13;

boolean V_LED_A1 = 0;
int B_A1 = 22;
int V_B_A1_NEW;
int V_B_A1_OLD = 1;
boolean V_LED_A2 = 0;
int B_A2 = 24;
int V_B_A2_NEW;
int V_B_A2_OLD = 1;
boolean V_LED_A3 = 0;
int B_A3 = 26;
int V_B_A3_NEW;
int V_B_A3_OLD = 1;
boolean V_LED_A4 = 0;
int B_A4 = 28;
int V_B_A4_NEW;
int V_B_A4_OLD = 1;
boolean V_LED_A5 = 0;
int B_A5 = 30;
int V_B_A5_NEW;
int V_B_A5_OLD = 1;
boolean V_LED_A6 = 0;
int B_A6 = 32;
int V_B_A6_NEW;
int V_B_A6_OLD = 1;

boolean V_LED_B1 = 0;
int B_B1 = 42;
int V_B_B1_NEW;
int V_B_B1_OLD = 1;
boolean V_LED_B2 = 0;
int B_B2 = 44;
int V_B_B2_NEW;
int V_B_B2_OLD = 1;
boolean V_LED_B3 = 0;
int B_B3 = 46;
int V_B_B3_NEW;
int V_B_B3_OLD = 1;
boolean V_LED_B4 = 0;
int B_B4 = 48;
int V_B_B4_NEW;
int V_B_B4_OLD = 1;
boolean V_LED_B5 = 0;
int B_B5 = 50;
int V_B_B5_NEW;
int V_B_B5_OLD = 1;
boolean V_LED_B6 = 0;
int B_B6 = 23;
int V_B_B6_NEW;
int V_B_B6_OLD = 1;
boolean V_LED_B7 = 0;
int B_B7 = 25;
int V_B_B7_NEW;
int V_B_B7_OLD = 1;
boolean V_LED_B8 = 0;
int B_B8 = 27;
int V_B_B8_NEW;
int V_B_B8_OLD = 1;
boolean V_LED_B9 = 0;
int B_B9 = 29;
int V_B_B9_NEW;
int V_B_B9_OLD = 1;
boolean V_LED_B10 = 0;
int B_B10 = 31;
int V_B_B10_NEW;
int V_B_B10_OLD = 1;
boolean V_LED_B11 = 0;
int B_B11 = 33;
int V_B_B11_NEW;
int V_B_B11_OLD = 1;
boolean V_LED_B12 = 0;
int B_B12 = 35;
int V_B_B12_NEW;
int V_B_B12_OLD = 1;
boolean V_LED_B13 = 0;
int B_B13 = 37;
int V_B_B13_NEW;
int V_B_B13_OLD = 1;
boolean V_LED_B14 = 0;
int B_B14 = 39;
int V_B_B14_NEW;
int V_B_B14_OLD = 1;
boolean V_LED_B15 = 0;
int B_B15 = 41;
int V_B_B15_NEW;
int V_B_B15_OLD = 1;
boolean V_LED_B16 = 0;
int B_B16 = 43;
int V_B_B16_NEW;
int V_B_B16_OLD = 1;
boolean V_LED_B17 = 0;
int B_B17 = 47;
int V_B_B17_NEW;
int V_B_B17_OLD = 1;
boolean V_LED_B18 = 0;
int B_B18 = 49;
int V_B_B18_NEW;
int V_B_B18_OLD = 1;
boolean V_LED_B19 = 0;
int B_B19 = 51;
int V_B_B19_NEW;
int V_B_B19_OLD = 1;
boolean V_LED_B20 = 0;
int B_B20 = 52;
int V_B_B20_NEW;
int V_B_B20_OLD = 1;
boolean V_LED_B21 = 0;
int B_B21 = 53;
int V_B_B21_NEW;
int V_B_B21_OLD = 1;
boolean V_LED_B22 = 0;
int B_B22 = 2;
int V_B_B22_NEW;
int V_B_B22_OLD = 1;
boolean V_LED_B23 = 0;
int B_B23 = 3;
int V_B_B23_NEW;
int V_B_B23_OLD = 1;
boolean V_LED_B24 = 0;
int B_B24 = 4;
int V_B_B24_NEW;
int V_B_B24_OLD = 1;
boolean V_LED_B25 = 0;
int B_B25 = 5;
int V_B_B25_NEW;
int V_B_B25_OLD = 1;
boolean V_LED_B26 = 0;
int B_B26 = 6;
int V_B_B26_NEW;
int V_B_B26_OLD = 1;



void setup() {

  pinMode(LEDPin, OUTPUT);

  Serial.begin(9600);

  FastLED.addLeds<WS2812B, LED_PIN_OUTSIDE, GRB>(leds_OUTSIDE, NUM_LEDS_OUTSIDE);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE1, GRB>(leds_CIRCLE1, NUM_LEDS_CIRCLE1);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE2, GRB>(leds_CIRCLE2, NUM_LEDS_CIRCLE2);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE3, GRB>(leds_CIRCLE3, NUM_LEDS_CIRCLE3);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE4, GRB>(leds_CIRCLE4, NUM_LEDS_CIRCLE4);
  FastLED.addLeds<WS2812B, LED_PIN_CIRCLE5, GRB>(leds_CIRCLE5, NUM_LEDS_CIRCLE5);
  FastLED.addLeds<WS2812B, LED_PIN_FAT, GRB>(leds_FAT, NUM_LEDS_FAT);
  FastLED.addLeds<WS2812B, LED_PIN_BIG, GRB>(leds_BIG, NUM_LEDS_BIG);

  FastLED.setBrightness(200);


  pinMode(B_A1, INPUT_PULLUP);
  pinMode(B_A2, INPUT_PULLUP);
  pinMode(B_A3, INPUT_PULLUP);
  pinMode(B_A4, INPUT_PULLUP);
  pinMode(B_A5, INPUT_PULLUP);
  pinMode(B_A6, INPUT_PULLUP);

  pinMode(B_B1, INPUT_PULLUP);
  pinMode(B_B2, INPUT_PULLUP);
  pinMode(B_B3, INPUT_PULLUP);
  pinMode(B_B4, INPUT_PULLUP);
  pinMode(B_B5, INPUT_PULLUP);
  pinMode(B_B6, INPUT_PULLUP);
  pinMode(B_B7, INPUT_PULLUP);
  pinMode(B_B8, INPUT_PULLUP);
  pinMode(B_B9, INPUT_PULLUP);
  pinMode(B_B10, INPUT_PULLUP);
  pinMode(B_B11, INPUT_PULLUP);
  pinMode(B_B12, INPUT_PULLUP);
  pinMode(B_B13, INPUT_PULLUP);
  pinMode(B_B14, INPUT_PULLUP);
  pinMode(B_B15, INPUT_PULLUP);
  pinMode(B_B16, INPUT_PULLUP);
  pinMode(B_B17, INPUT_PULLUP);
  pinMode(B_B18, INPUT_PULLUP);
  pinMode(B_B19, INPUT_PULLUP);
  pinMode(B_B20, INPUT_PULLUP);
  pinMode(B_B21, INPUT_PULLUP);
  pinMode(B_B22, INPUT_PULLUP);
  pinMode(B_B23, INPUT_PULLUP);
  pinMode(B_B24, INPUT_PULLUP);
  pinMode(B_B25, INPUT_PULLUP);
  pinMode(B_B26, INPUT_PULLUP);
}

void loop() {




  fill_solid(leds_FAT, NUM_LEDS_FAT, CHSV(170, 200, 50));

  EVERY_N_MILLISECONDS(60) {
    leds_BIG[0] = CHSV(160, random8(), random8(100, 255));
    for (int i = NUM_LEDS_BIG - 1; i > 0; i--) {
      leds_BIG[i] = leds_BIG[i - 1];
    }
  }




  V_B_A1_NEW = digitalRead(B_A1);
  if (V_B_A1_OLD == 0 && V_B_A1_NEW == 1) {
    if (V_LED_A1 == 0) {
      V_LED_A1 = 1;
    } else {
      V_LED_A1 = 0;
    }
  }
  V_B_A1_OLD = V_B_A1_NEW;
  switch (V_LED_A1) {
    case 0:
      for (int i = 0; i < 170; i++) {
        leds_CIRCLE1[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 0; i < 170; i++) {
        leds_CIRCLE1[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_A2_NEW = digitalRead(B_A2);
  if (V_B_A2_OLD == 0 && V_B_A2_NEW == 1) {
    if (V_LED_A2 == 0) {
      V_LED_A2 = 1;
    } else {
      V_LED_A2 = 0;
    }
  }
  V_B_A2_OLD = V_B_A2_NEW;
  switch (V_LED_A2) {
    case 0:
      for (int i = 0; i < 100; i++) {
        leds_CIRCLE2[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 0; i < 100; i++) {
        leds_CIRCLE2[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_A3_NEW = digitalRead(B_A3);
  if (V_B_A3_OLD == 0 && V_B_A3_NEW == 1) {
    if (V_LED_A3 == 0) {
      V_LED_A3 = 1;
    } else {
      V_LED_A3 = 0;
    }
  }
  V_B_A3_OLD = V_B_A3_NEW;
  switch (V_LED_A3) {
    case 0:
      for (int i = 0; i < 85; i++) {
        leds_CIRCLE3[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 0; i < 85; i++) {
        leds_CIRCLE3[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_A4_NEW = digitalRead(B_A4);
  if (V_B_A4_OLD == 0 && V_B_A4_NEW == 1) {
    if (V_LED_A4 == 0) {
      V_LED_A4 = 1;
    } else {
      V_LED_A4 = 0;
    }
  }
  V_B_A4_OLD = V_B_A4_NEW;
  switch (V_LED_A4) {
    case 0:
      for (int i = 0; i < 70; i++) {
        leds_CIRCLE4[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 0; i < 70; i++) {
        leds_CIRCLE4[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_A5_NEW = digitalRead(B_A5);
  if (V_B_A5_OLD == 0 && V_B_A5_NEW == 1) {
    if (V_LED_A5 == 0) {
      V_LED_A5 = 1;
    } else {
      V_LED_A5 = 0;
    }
  }
  V_B_A5_OLD = V_B_A5_NEW;
  switch (V_LED_A5) {
    case 0:
      for (int i = 0; i < 50; i++) {
        leds_CIRCLE5[i] = CHSV(160, 200, 200);
      }
      //  V_LED_B1=0;
      break;
    case 1:
      for (int i = 0; i < 50; i++) {
        leds_CIRCLE5[i] = CHSV(160, 200, 0);
      }
      //  V_LED_B1=1;
      break;
  }


  //Which buttons are this? And what are the outside LEDS?
  V_B_B1_NEW = digitalRead(B_B1);
  if (V_B_B1_OLD == 0 && V_B_B1_NEW == 1) {
    if (V_LED_B1 == 0) {
      V_LED_B1 = 1;
    } else {
      V_LED_B1 = 0;
    }
  }
  V_B_B1_OLD = V_B_B1_NEW;

  switch (V_LED_B1) {
    case 0:

      for (int i = 0; i < 12; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 0; i < 12; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_B2_NEW = digitalRead(B_B2);
  if (V_B_B2_OLD == 0 && V_B_B2_NEW == 1) {
    if (V_LED_B2 == 0) {
      V_LED_B2 = 1;
    } else {
      V_LED_B2 = 0;
    }
  }
  V_B_B2_OLD = V_B_B2_NEW;
  switch (V_LED_B2) {
    case 0:
      for (int i = 13; i < 19; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 13; i < 19; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_B3_NEW = digitalRead(B_B3);
  if (V_B_B3_OLD == 0 && V_B_B3_NEW == 1) {
    if (V_LED_B3 == 0) {
      V_LED_B3 = 1;
    } else {
      V_LED_B3 = 0;
    }
  }
  V_B_B3_OLD = V_B_B3_NEW;
  switch (V_LED_B3) {
    case 0:
      for (int i = 19; i < 31; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 19; i < 31; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_B4_NEW = digitalRead(B_B4);
  if (V_B_B4_OLD == 0 && V_B_B4_NEW == 1) {
    if (V_LED_B4 == 0) {
      V_LED_B4 = 1;
    } else {
      V_LED_B4 = 0;
    }
  }
  V_B_B4_OLD = V_B_B4_NEW;
  switch (V_LED_B4) {
    case 0:
      for (int i = 33; i < 55; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 33; i < 55; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 0);
      }
      break;
  }


  V_B_B5_NEW = digitalRead(B_B5);
  if (V_B_B5_OLD == 0 && V_B_B5_NEW == 1) {
    if (V_LED_B5 == 0) {
      V_LED_B5 = 1;
    } else {
      V_LED_B5 = 0;
    }
  }
  V_B_B5_OLD = V_B_B5_NEW;
  switch (V_LED_B5) {
    case 0:
      for (int i = 55; i < 70; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 55; i < 70; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_B6_NEW = digitalRead(B_B6);
  if (V_B_B6_OLD == 0 && V_B_B6_NEW == 1) {
    if (V_LED_B6 == 0) {
      V_LED_B6 = 1;
    } else {
      V_LED_B6 = 0;
    }
  }
  V_B_B6_OLD = V_B_B6_NEW;
  switch (V_LED_B6) {
    case 0:
      for (int i = 70; i < 86; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 200);
      }
      break;
    case 1:
      for (int i = 70; i < 86; i++) {
        leds_OUTSIDE[i] = CHSV(160, 200, 0);
      }
      break;
  }

  V_B_B7_NEW = digitalRead(B_B7);
  if (V_B_B7_OLD == 0 && V_B_B7_NEW == 1) {
    if (V_LED_B7 == 0) {
      V_LED_B7 = 1;
    } else {
      V_LED_B7 = 0;
    }
  }
  V_B_B7_OLD = V_B_B7_NEW;
  switch (V_LED_B7) {
    case 0:
      leds_OUTSIDE[86] = CHSV(160, 200, 200);
      leds_OUTSIDE[87] = CHSV(160, 200, 200);
      leds_OUTSIDE[88] = CHSV(160, 200, 200);
      leds_OUTSIDE[89] = CHSV(160, 200, 200);
      leds_OUTSIDE[90] = CHSV(160, 200, 200);
      leds_OUTSIDE[91] = CHSV(160, 200, 200);
      leds_OUTSIDE[92] = CHSV(160, 200, 200);
      leds_OUTSIDE[93] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[86] = CHSV(160, 200, 0);
      leds_OUTSIDE[87] = CHSV(160, 200, 0);
      leds_OUTSIDE[88] = CHSV(160, 200, 0);
      leds_OUTSIDE[89] = CHSV(160, 200, 0);
      leds_OUTSIDE[90] = CHSV(160, 200, 0);
      leds_OUTSIDE[91] = CHSV(160, 200, 0);
      leds_OUTSIDE[92] = CHSV(160, 200, 0);
      leds_OUTSIDE[93] = CHSV(160, 200, 0);
      break;
  }

  V_B_B8_NEW = digitalRead(B_B8);
  if (V_B_B8_OLD == 0 && V_B_B8_NEW == 1) {
    if (V_LED_B8 == 0) {
      V_LED_B8 = 1;
    } else {
      V_LED_B8 = 0;
    }
  }
  V_B_B8_OLD = V_B_B8_NEW;
  switch (V_LED_B8) {
    case 0:
      leds_OUTSIDE[94] = CHSV(160, 200, 200);
      leds_OUTSIDE[95] = CHSV(160, 200, 200);
      leds_OUTSIDE[96] = CHSV(160, 200, 200);
      leds_OUTSIDE[97] = CHSV(160, 200, 200);
      leds_OUTSIDE[98] = CHSV(160, 200, 200);
      leds_OUTSIDE[99] = CHSV(160, 200, 200);
      leds_OUTSIDE[200] = CHSV(160, 200, 200);
      leds_OUTSIDE[101] = CHSV(160, 200, 200);
      leds_OUTSIDE[102] = CHSV(160, 200, 200);
      leds_OUTSIDE[103] = CHSV(160, 200, 200);
      leds_OUTSIDE[104] = CHSV(160, 200, 200);
      leds_OUTSIDE[105] = CHSV(160, 200, 200);
      leds_OUTSIDE[106] = CHSV(160, 200, 200);
      leds_OUTSIDE[107] = CHSV(160, 200, 200);
      leds_OUTSIDE[108] = CHSV(160, 200, 200);
      leds_OUTSIDE[109] = CHSV(160, 200, 200);
      leds_OUTSIDE[110] = CHSV(160, 200, 200);
      leds_OUTSIDE[111] = CHSV(160, 200, 200);
      leds_OUTSIDE[112] = CHSV(160, 200, 200);
      leds_OUTSIDE[113] = CHSV(160, 200, 200);
      leds_OUTSIDE[114] = CHSV(160, 200, 200);


      break;
    case 1:
      leds_OUTSIDE[94] = CHSV(160, 200, 0);
      leds_OUTSIDE[95] = CHSV(160, 200, 0);
      leds_OUTSIDE[96] = CHSV(160, 200, 0);
      leds_OUTSIDE[97] = CHSV(160, 200, 0);
      leds_OUTSIDE[98] = CHSV(160, 200, 0);
      leds_OUTSIDE[99] = CHSV(160, 200, 0);
      leds_OUTSIDE[200] = CHSV(160, 200, 0);
      leds_OUTSIDE[101] = CHSV(160, 200, 0);
      leds_OUTSIDE[102] = CHSV(160, 200, 0);
      leds_OUTSIDE[103] = CHSV(160, 200, 0);
      leds_OUTSIDE[104] = CHSV(160, 200, 0);
      leds_OUTSIDE[105] = CHSV(160, 200, 0);
      leds_OUTSIDE[106] = CHSV(160, 200, 0);
      leds_OUTSIDE[107] = CHSV(160, 200, 0);
      leds_OUTSIDE[108] = CHSV(160, 200, 0);
      leds_OUTSIDE[109] = CHSV(160, 200, 0);
      leds_OUTSIDE[110] = CHSV(160, 200, 0);
      leds_OUTSIDE[111] = CHSV(160, 200, 0);
      leds_OUTSIDE[112] = CHSV(160, 200, 0);
      leds_OUTSIDE[113] = CHSV(160, 200, 0);
      leds_OUTSIDE[114] = CHSV(160, 200, 0);
      break;
  }

  V_B_B9_NEW = digitalRead(B_B9);
  if (V_B_B9_OLD == 0 && V_B_B9_NEW == 1) {
    if (V_LED_B9 == 0) {
      V_LED_B9 = 1;
    } else {
      V_LED_B9 = 0;
    }
  }
  V_B_B9_OLD = V_B_B9_NEW;
  switch (V_LED_B9) {
    case 0:
      leds_OUTSIDE[115] = CHSV(160, 200, 200);
      leds_OUTSIDE[116] = CHSV(160, 200, 200);
      leds_OUTSIDE[117] = CHSV(160, 200, 200);
      leds_OUTSIDE[118] = CHSV(160, 200, 200);
      leds_OUTSIDE[119] = CHSV(160, 200, 200);
      leds_OUTSIDE[120] = CHSV(160, 200, 200);
      leds_OUTSIDE[121] = CHSV(160, 200, 200);
      leds_OUTSIDE[121] = CHSV(160, 200, 200);
      leds_OUTSIDE[122] = CHSV(160, 200, 200);
      leds_OUTSIDE[123] = CHSV(160, 200, 200);
      leds_OUTSIDE[124] = CHSV(160, 200, 200);
      leds_OUTSIDE[125] = CHSV(160, 200, 200);
      leds_OUTSIDE[126] = CHSV(160, 200, 200);
      leds_OUTSIDE[127] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[115] = CHSV(160, 200, 0);
      leds_OUTSIDE[116] = CHSV(160, 200, 0);
      leds_OUTSIDE[117] = CHSV(160, 200, 0);
      leds_OUTSIDE[118] = CHSV(160, 200, 0);
      leds_OUTSIDE[119] = CHSV(160, 200, 0);
      leds_OUTSIDE[120] = CHSV(160, 200, 0);
      leds_OUTSIDE[121] = CHSV(160, 200, 0);
      leds_OUTSIDE[121] = CHSV(160, 200, 0);
      leds_OUTSIDE[122] = CHSV(160, 200, 0);
      leds_OUTSIDE[123] = CHSV(160, 200, 0);
      leds_OUTSIDE[124] = CHSV(160, 200, 0);
      leds_OUTSIDE[125] = CHSV(160, 200, 0);
      leds_OUTSIDE[126] = CHSV(160, 200, 0);
      leds_OUTSIDE[127] = CHSV(160, 200, 0);
      break;
  }

  V_B_B10_NEW = digitalRead(B_B10);
  if (V_B_B10_OLD == 0 && V_B_B10_NEW == 1) {
    if (V_LED_B10 == 0) {
      V_LED_B10 = 1;
    } else {
      V_LED_B10 = 0;
    }
  }
  V_B_B10_OLD = V_B_B10_NEW;
  switch (V_LED_B10) {
    case 0:
      leds_OUTSIDE[128] = CHSV(160, 200, 200);
      leds_OUTSIDE[129] = CHSV(160, 200, 200);
      leds_OUTSIDE[130] = CHSV(160, 200, 200);
      leds_OUTSIDE[131] = CHSV(160, 200, 200);
      leds_OUTSIDE[132] = CHSV(160, 200, 200);
      leds_OUTSIDE[133] = CHSV(160, 200, 200);
      leds_OUTSIDE[134] = CHSV(160, 200, 200);
      leds_OUTSIDE[135] = CHSV(160, 200, 200);
      leds_OUTSIDE[136] = CHSV(160, 200, 200);
      leds_OUTSIDE[137] = CHSV(160, 200, 200);
      leds_OUTSIDE[138] = CHSV(160, 200, 200);
      leds_OUTSIDE[139] = CHSV(160, 200, 200);
      leds_OUTSIDE[140] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[128] = CHSV(160, 200, 0);
      leds_OUTSIDE[129] = CHSV(160, 200, 0);
      leds_OUTSIDE[130] = CHSV(160, 200, 0);
      leds_OUTSIDE[131] = CHSV(160, 200, 0);
      leds_OUTSIDE[132] = CHSV(160, 200, 0);
      leds_OUTSIDE[133] = CHSV(160, 200, 0);
      leds_OUTSIDE[134] = CHSV(160, 200, 0);
      leds_OUTSIDE[135] = CHSV(160, 200, 0);
      leds_OUTSIDE[136] = CHSV(160, 200, 0);
      leds_OUTSIDE[137] = CHSV(160, 200, 0);
      leds_OUTSIDE[138] = CHSV(160, 200, 0);
      leds_OUTSIDE[139] = CHSV(160, 200, 0);
      leds_OUTSIDE[140] = CHSV(160, 200, 0);
      break;
  }

  V_B_B11_NEW = digitalRead(B_B11);
  if (V_B_B11_OLD == 0 && V_B_B11_NEW == 1) {
    if (V_LED_B11 == 0) {
      V_LED_B11 = 1;
    } else {
      V_LED_B11 = 0;
    }
  }
  V_B_B11_OLD = V_B_B11_NEW;
  switch (V_LED_B11) {
    case 0:
      leds_OUTSIDE[141] = CHSV(160, 200, 200);
      leds_OUTSIDE[142] = CHSV(160, 200, 200);
      leds_OUTSIDE[143] = CHSV(160, 200, 200);
      leds_OUTSIDE[144] = CHSV(160, 200, 200);
      leds_OUTSIDE[145] = CHSV(160, 200, 200);
      leds_OUTSIDE[146] = CHSV(160, 200, 200);
      leds_OUTSIDE[147] = CHSV(160, 200, 200);
      leds_OUTSIDE[148] = CHSV(160, 200, 200);
      break;
    case 1:

      leds_OUTSIDE[141] = CHSV(160, 200, 0);
      leds_OUTSIDE[142] = CHSV(160, 200, 0);
      leds_OUTSIDE[143] = CHSV(160, 200, 0);
      leds_OUTSIDE[144] = CHSV(160, 200, 0);
      leds_OUTSIDE[145] = CHSV(160, 200, 0);
      leds_OUTSIDE[146] = CHSV(160, 200, 0);
      leds_OUTSIDE[147] = CHSV(160, 200, 0);
      leds_OUTSIDE[148] = CHSV(160, 200, 0);
      break;
  }

  V_B_B12_NEW = digitalRead(B_B12);
  if (V_B_B12_OLD == 0 && V_B_B12_NEW == 1) {
    if (V_LED_B12 == 0) {
      V_LED_B12 = 1;
    } else {
      V_LED_B12 = 0;
    }
  }
  V_B_B12_OLD = V_B_B12_NEW;
  switch (V_LED_B12) {
    case 0:
      leds_OUTSIDE[149] = CHSV(160, 200, 200);
      leds_OUTSIDE[150] = CHSV(160, 200, 200);
      leds_OUTSIDE[151] = CHSV(160, 200, 200);
      leds_OUTSIDE[152] = CHSV(160, 200, 200);
      leds_OUTSIDE[153] = CHSV(160, 200, 200);
      leds_OUTSIDE[154] = CHSV(160, 200, 200);
      leds_OUTSIDE[155] = CHSV(160, 200, 200);
      leds_OUTSIDE[156] = CHSV(160, 200, 200);
      leds_OUTSIDE[157] = CHSV(160, 200, 200);
      leds_OUTSIDE[158] = CHSV(160, 200, 200);
      leds_OUTSIDE[159] = CHSV(160, 200, 200);
      leds_OUTSIDE[160] = CHSV(160, 200, 200);
      leds_OUTSIDE[161] = CHSV(160, 200, 200);
      leds_OUTSIDE[162] = CHSV(160, 200, 200);
      leds_OUTSIDE[163] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[149] = CHSV(160, 200, 0);
      leds_OUTSIDE[150] = CHSV(160, 200, 0);
      leds_OUTSIDE[151] = CHSV(160, 200, 0);
      leds_OUTSIDE[152] = CHSV(160, 200, 0);
      leds_OUTSIDE[153] = CHSV(160, 200, 0);
      leds_OUTSIDE[154] = CHSV(160, 200, 0);
      leds_OUTSIDE[155] = CHSV(160, 200, 0);
      leds_OUTSIDE[156] = CHSV(160, 200, 0);
      leds_OUTSIDE[157] = CHSV(160, 200, 0);
      leds_OUTSIDE[158] = CHSV(160, 200, 0);
      leds_OUTSIDE[159] = CHSV(160, 200, 0);
      leds_OUTSIDE[160] = CHSV(160, 200, 0);
      leds_OUTSIDE[161] = CHSV(160, 200, 0);
      leds_OUTSIDE[162] = CHSV(160, 200, 0);
      leds_OUTSIDE[163] = CHSV(160, 200, 0);
      break;
  }

  V_B_B13_NEW = digitalRead(B_B13);
  if (V_B_B13_OLD == 0 && V_B_B13_NEW == 1) {
    if (V_LED_B13 == 0) {
      V_LED_B13 = 1;
    } else {
      V_LED_B13 = 0;
    }
  }
  V_B_B13_OLD = V_B_B13_NEW;
  switch (V_LED_B13) {
    case 0:
      leds_OUTSIDE[164] = CHSV(160, 200, 200);
      leds_OUTSIDE[165] = CHSV(160, 200, 200);
      leds_OUTSIDE[166] = CHSV(160, 200, 200);
      leds_OUTSIDE[167] = CHSV(160, 200, 200);
      leds_OUTSIDE[168] = CHSV(160, 200, 200);
      leds_OUTSIDE[169] = CHSV(160, 200, 200);
      leds_OUTSIDE[170] = CHSV(160, 200, 200);
      leds_OUTSIDE[171] = CHSV(160, 200, 200);
      leds_OUTSIDE[172] = CHSV(160, 200, 200);
      leds_OUTSIDE[173] = CHSV(160, 200, 200);
      leds_OUTSIDE[174] = CHSV(160, 200, 200);
      leds_OUTSIDE[175] = CHSV(160, 200, 200);
      leds_OUTSIDE[176] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[164] = CHSV(160, 200, 0);
      leds_OUTSIDE[165] = CHSV(160, 200, 0);
      leds_OUTSIDE[166] = CHSV(160, 200, 0);
      leds_OUTSIDE[167] = CHSV(160, 200, 0);
      leds_OUTSIDE[168] = CHSV(160, 200, 0);
      leds_OUTSIDE[169] = CHSV(160, 200, 0);
      leds_OUTSIDE[170] = CHSV(160, 200, 0);
      leds_OUTSIDE[171] = CHSV(160, 200, 0);
      leds_OUTSIDE[172] = CHSV(160, 200, 0);
      leds_OUTSIDE[173] = CHSV(160, 200, 0);
      leds_OUTSIDE[174] = CHSV(160, 200, 0);
      leds_OUTSIDE[175] = CHSV(160, 200, 0);
      leds_OUTSIDE[176] = CHSV(160, 200, 0);

      break;
  }


  V_B_B14_NEW = digitalRead(B_B14);
  if (V_B_B14_OLD == 0 && V_B_B14_NEW == 1) {
    if (V_LED_B14 == 0) {
      V_LED_B14 = 1;
    } else {
      V_LED_B14 = 0;
    }
  }
  V_B_B14_OLD = V_B_B14_NEW;
  switch (V_LED_B14) {
    case 0:
      leds_OUTSIDE[178] = CHSV(160, 200, 200);
      leds_OUTSIDE[179] = CHSV(160, 200, 200);
      leds_OUTSIDE[180] = CHSV(160, 200, 200);
      leds_OUTSIDE[181] = CHSV(160, 200, 200);
      leds_OUTSIDE[182] = CHSV(160, 200, 200);
      leds_OUTSIDE[177] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[177] = CHSV(160, 200, 0);
      leds_OUTSIDE[178] = CHSV(160, 200, 0);
      leds_OUTSIDE[179] = CHSV(160, 200, 0);
      leds_OUTSIDE[180] = CHSV(160, 200, 0);
      leds_OUTSIDE[181] = CHSV(160, 200, 0);
      leds_OUTSIDE[182] = CHSV(160, 200, 0);
      break;
  }
  V_B_B15_NEW = digitalRead(B_B15);
  if (V_B_B15_OLD == 0 && V_B_B15_NEW == 1) {
    if (V_LED_B15 == 0) {
      V_LED_B15 = 1;
    } else {
      V_LED_B15 = 0;
    }
  }
  V_B_B15_OLD = V_B_B15_NEW;
  switch (V_LED_B15) {
    case 0:
      leds_OUTSIDE[183] = CHSV(160, 200, 200);
      leds_OUTSIDE[184] = CHSV(160, 200, 200);
      leds_OUTSIDE[185] = CHSV(160, 200, 200);
      leds_OUTSIDE[186] = CHSV(160, 200, 200);
      leds_OUTSIDE[187] = CHSV(160, 200, 200);
      leds_OUTSIDE[188] = CHSV(160, 200, 200);
      leds_OUTSIDE[189] = CHSV(160, 200, 200);
      leds_OUTSIDE[190] = CHSV(160, 200, 200);
      leds_OUTSIDE[191] = CHSV(160, 200, 200);
      leds_OUTSIDE[192] = CHSV(160, 200, 200);
      leds_OUTSIDE[192] = CHSV(160, 200, 200);

      break;
    case 1:
      leds_OUTSIDE[183] = CHSV(160, 200, 0);
      leds_OUTSIDE[184] = CHSV(160, 200, 0);
      leds_OUTSIDE[185] = CHSV(160, 200, 0);
      leds_OUTSIDE[186] = CHSV(160, 200, 0);
      leds_OUTSIDE[187] = CHSV(160, 200, 0);
      leds_OUTSIDE[188] = CHSV(160, 200, 0);
      leds_OUTSIDE[189] = CHSV(160, 200, 0);
      leds_OUTSIDE[190] = CHSV(160, 200, 0);
      leds_OUTSIDE[191] = CHSV(160, 200, 0);
      leds_OUTSIDE[192] = CHSV(160, 200, 0);
      leds_OUTSIDE[192] = CHSV(160, 200, 0);
      break;
  }
  V_B_B16_NEW = digitalRead(B_B16);
  if (V_B_B16_OLD == 0 && V_B_B16_NEW == 1) {
    if (V_LED_B16 == 0) {
      V_LED_B16 = 1;
    } else {
      V_LED_B16 = 0;
    }
  }
  V_B_B16_OLD = V_B_B16_NEW;
  switch (V_LED_B16) {
    case 0:
      leds_OUTSIDE[193] = CHSV(160, 200, 200);
      leds_OUTSIDE[194] = CHSV(160, 200, 200);
      leds_OUTSIDE[195] = CHSV(160, 200, 200);
      leds_OUTSIDE[196] = CHSV(160, 200, 200);
      leds_OUTSIDE[197] = CHSV(160, 200, 200);
      leds_OUTSIDE[198] = CHSV(160, 200, 200);
      leds_OUTSIDE[199] = CHSV(160, 200, 200);
      leds_OUTSIDE[200] = CHSV(160, 200, 200);
      leds_OUTSIDE[201] = CHSV(160, 200, 200);
      leds_OUTSIDE[202] = CHSV(160, 200, 200);
      leds_OUTSIDE[203] = CHSV(160, 200, 200);
      leds_OUTSIDE[204] = CHSV(160, 200, 200);
      leds_OUTSIDE[205] = CHSV(160, 200, 200);
      leds_OUTSIDE[206] = CHSV(160, 200, 200);
      leds_OUTSIDE[207] = CHSV(160, 200, 200);
      leds_OUTSIDE[208] = CHSV(160, 200, 200);
      leds_OUTSIDE[209] = CHSV(160, 200, 200);
      leds_OUTSIDE[210] = CHSV(160, 200, 200);
      leds_OUTSIDE[211] = CHSV(160, 200, 200);
      leds_OUTSIDE[212] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[193] = CHSV(160, 200, 0);
      leds_OUTSIDE[194] = CHSV(160, 200, 0);
      leds_OUTSIDE[195] = CHSV(160, 200, 0);
      leds_OUTSIDE[196] = CHSV(160, 200, 0);
      leds_OUTSIDE[197] = CHSV(160, 200, 0);
      leds_OUTSIDE[198] = CHSV(160, 200, 0);
      leds_OUTSIDE[199] = CHSV(160, 200, 0);
      leds_OUTSIDE[200] = CHSV(160, 200, 0);
      leds_OUTSIDE[201] = CHSV(160, 200, 0);
      leds_OUTSIDE[202] = CHSV(160, 200, 0);
      leds_OUTSIDE[203] = CHSV(160, 200, 0);
      leds_OUTSIDE[204] = CHSV(160, 200, 0);
      leds_OUTSIDE[205] = CHSV(160, 200, 0);
      leds_OUTSIDE[206] = CHSV(160, 200, 0);
      leds_OUTSIDE[207] = CHSV(160, 200, 0);
      leds_OUTSIDE[208] = CHSV(160, 200, 0);
      leds_OUTSIDE[209] = CHSV(160, 200, 0);
      leds_OUTSIDE[210] = CHSV(160, 200, 0);
      leds_OUTSIDE[211] = CHSV(160, 200, 0);
      leds_OUTSIDE[212] = CHSV(160, 200, 0);
      break;
  }

  V_B_B17_NEW = digitalRead(B_B17);
  if (V_B_B17_OLD == 0 && V_B_B17_NEW == 1) {
    if (V_LED_B17 == 0) {
      V_LED_B17 = 1;
    } else {
      V_LED_B17 = 0;
    }
  }
  V_B_B17_OLD = V_B_B17_NEW;
  switch (V_LED_B17) {
    case 0:
      leds_OUTSIDE[213] = CHSV(160, 200, 200);
      leds_OUTSIDE[214] = CHSV(160, 200, 200);
      leds_OUTSIDE[215] = CHSV(160, 200, 200);
      leds_OUTSIDE[216] = CHSV(160, 200, 200);
      leds_OUTSIDE[217] = CHSV(160, 200, 200);
      leds_OUTSIDE[218] = CHSV(160, 200, 200);
      leds_OUTSIDE[219] = CHSV(160, 200, 200);
      leds_OUTSIDE[220] = CHSV(160, 200, 200);
      leds_OUTSIDE[221] = CHSV(160, 200, 200);
      leds_OUTSIDE[222] = CHSV(160, 200, 200);
      leds_OUTSIDE[223] = CHSV(160, 200, 200);
      leds_OUTSIDE[224] = CHSV(160, 200, 200);
      leds_OUTSIDE[225] = CHSV(160, 200, 200);
      leds_OUTSIDE[226] = CHSV(160, 200, 200);
      leds_OUTSIDE[227] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[213] = CHSV(160, 200, 0);
      leds_OUTSIDE[214] = CHSV(160, 200, 0);
      leds_OUTSIDE[215] = CHSV(160, 200, 0);
      leds_OUTSIDE[216] = CHSV(160, 200, 0);
      leds_OUTSIDE[217] = CHSV(160, 200, 0);
      leds_OUTSIDE[218] = CHSV(160, 200, 0);
      leds_OUTSIDE[219] = CHSV(160, 200, 0);
      leds_OUTSIDE[220] = CHSV(160, 200, 0);
      leds_OUTSIDE[221] = CHSV(160, 200, 0);
      leds_OUTSIDE[222] = CHSV(160, 200, 0);
      leds_OUTSIDE[223] = CHSV(160, 200, 0);
      leds_OUTSIDE[214] = CHSV(160, 200, 0);
      leds_OUTSIDE[225] = CHSV(160, 200, 0);
      leds_OUTSIDE[226] = CHSV(160, 200, 0);
      leds_OUTSIDE[227] = CHSV(160, 200, 0);
      leds_OUTSIDE[228] = CHSV(160, 200, 0);
      break;
  }

  V_B_B18_NEW = digitalRead(B_B18);
  if (V_B_B18_OLD == 0 && V_B_B18_NEW == 1) {
    if (V_LED_B18 == 0) {
      V_LED_B18 = 1;
    } else {
      V_LED_B18 = 0;
    }
  }
  V_B_B18_OLD = V_B_B18_NEW;
  switch (V_LED_B18) {
    case 0:
      leds_OUTSIDE[229] = CHSV(160, 200, 200);
      leds_OUTSIDE[230] = CHSV(160, 200, 200);
      leds_OUTSIDE[231] = CHSV(160, 200, 200);
      leds_OUTSIDE[232] = CHSV(160, 200, 200);
      leds_OUTSIDE[233] = CHSV(160, 200, 200);
      leds_OUTSIDE[234] = CHSV(160, 200, 200);
      leds_OUTSIDE[235] = CHSV(160, 200, 200);
      leds_OUTSIDE[236] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[229] = CHSV(160, 200, 0);
      leds_OUTSIDE[230] = CHSV(160, 200, 0);
      leds_OUTSIDE[231] = CHSV(160, 200, 0);
      leds_OUTSIDE[232] = CHSV(160, 200, 0);
      leds_OUTSIDE[233] = CHSV(160, 200, 0);
      leds_OUTSIDE[234] = CHSV(160, 200, 0);
      leds_OUTSIDE[235] = CHSV(160, 200, 0);
      leds_OUTSIDE[236] = CHSV(160, 200, 0);
      break;
  }

  V_B_B19_NEW = digitalRead(B_B19);
  if (V_B_B19_OLD == 0 && V_B_B19_NEW == 1) {
    if (V_LED_B19 == 0) {
      V_LED_B19 = 1;
    } else {
      V_LED_B19 = 0;
    }
  }
  V_B_B19_OLD = V_B_B19_NEW;
  switch (V_LED_B19) {
    case 0:
      leds_OUTSIDE[237] = CHSV(160, 200, 200);
      leds_OUTSIDE[238] = CHSV(160, 200, 200);
      leds_OUTSIDE[239] = CHSV(160, 200, 200);
      leds_OUTSIDE[240] = CHSV(160, 200, 200);
      leds_OUTSIDE[241] = CHSV(160, 200, 200);
      leds_OUTSIDE[242] = CHSV(160, 200, 200);
      leds_OUTSIDE[243] = CHSV(160, 200, 200);
      leds_OUTSIDE[244] = CHSV(160, 200, 200);
      leds_OUTSIDE[245] = CHSV(160, 200, 200);
      leds_OUTSIDE[246] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[237] = CHSV(160, 200, 0);
      leds_OUTSIDE[238] = CHSV(160, 200, 0);
      leds_OUTSIDE[239] = CHSV(160, 200, 0);
      leds_OUTSIDE[240] = CHSV(160, 200, 0);
      leds_OUTSIDE[241] = CHSV(160, 200, 0);
      leds_OUTSIDE[242] = CHSV(160, 200, 0);
      leds_OUTSIDE[243] = CHSV(160, 200, 0);
      leds_OUTSIDE[244] = CHSV(160, 200, 0);
      leds_OUTSIDE[245] = CHSV(160, 200, 0);
      leds_OUTSIDE[246] = CHSV(160, 200, 0);
      break;
  }
  V_B_B20_NEW = digitalRead(B_B20);
  if (V_B_B20_OLD == 0 && V_B_B20_NEW == 1) {
    if (V_LED_B20 == 0) {
      V_LED_B20 = 1;
    } else {
      V_LED_B20 = 0;
    }
  }
  V_B_B20_OLD = V_B_B20_NEW;
  switch (V_LED_B20) {
    case 0:

      leds_OUTSIDE[247] = CHSV(160, 200, 200);
      leds_OUTSIDE[248] = CHSV(160, 200, 200);
      leds_OUTSIDE[249] = CHSV(160, 200, 200);
      leds_OUTSIDE[250] = CHSV(160, 200, 200);
      leds_OUTSIDE[251] = CHSV(160, 200, 200);
      leds_OUTSIDE[252] = CHSV(160, 200, 200);
      leds_OUTSIDE[253] = CHSV(160, 200, 200);
      leds_OUTSIDE[254] = CHSV(160, 200, 200);
      leds_OUTSIDE[255] = CHSV(160, 200, 200);
      leds_OUTSIDE[256] = CHSV(160, 200, 200);
      leds_OUTSIDE[257] = CHSV(160, 200, 200);
      leds_OUTSIDE[258] = CHSV(160, 200, 200);
      break;
    case 1:

      leds_OUTSIDE[247] = CHSV(160, 200, 0);
      leds_OUTSIDE[248] = CHSV(160, 200, 0);
      leds_OUTSIDE[249] = CHSV(160, 200, 0);
      leds_OUTSIDE[250] = CHSV(160, 200, 0);
      leds_OUTSIDE[251] = CHSV(160, 200, 0);
      leds_OUTSIDE[252] = CHSV(160, 200, 0);
      leds_OUTSIDE[253] = CHSV(160, 200, 0);
      leds_OUTSIDE[254] = CHSV(160, 200, 0);
      leds_OUTSIDE[255] = CHSV(160, 200, 0);
      leds_OUTSIDE[256] = CHSV(160, 200, 0);
      leds_OUTSIDE[257] = CHSV(160, 200, 0);
      leds_OUTSIDE[258] = CHSV(160, 200, 0);
      break;
  }

  V_B_B21_NEW = digitalRead(B_B21);
  if (V_B_B21_OLD == 0 && V_B_B21_NEW == 1) {
    if (V_LED_B21 == 0) {
      V_LED_B21 = 1;
    } else {
      V_LED_B21 = 0;
    }
  }
  V_B_B21_OLD = V_B_B21_NEW;
  switch (V_LED_B21) {
    case 0:
      leds_OUTSIDE[259] = CHSV(160, 200, 200);
      leds_OUTSIDE[260] = CHSV(160, 200, 200);
      leds_OUTSIDE[261] = CHSV(160, 200, 200);
      leds_OUTSIDE[262] = CHSV(160, 200, 200);
      leds_OUTSIDE[263] = CHSV(160, 200, 200);
      leds_OUTSIDE[264] = CHSV(160, 200, 200);
      leds_OUTSIDE[265] = CHSV(160, 200, 200);
      leds_OUTSIDE[266] = CHSV(160, 200, 200);
      leds_OUTSIDE[267] = CHSV(160, 200, 200);
      leds_OUTSIDE[268] = CHSV(160, 200, 200);
      leds_OUTSIDE[269] = CHSV(160, 200, 200);
      leds_OUTSIDE[270] = CHSV(160, 200, 200);
      leds_OUTSIDE[271] = CHSV(160, 200, 200);
      leds_OUTSIDE[272] = CHSV(160, 200, 200);
      leds_OUTSIDE[273] = CHSV(160, 200, 200);
      leds_OUTSIDE[274] = CHSV(160, 200, 200);
      leds_OUTSIDE[275] = CHSV(160, 200, 200);
      leds_OUTSIDE[276] = CHSV(160, 200, 200);
      leds_OUTSIDE[277] = CHSV(160, 200, 200);
      leds_OUTSIDE[278] = CHSV(160, 200, 200);
      leds_OUTSIDE[279] = CHSV(160, 200, 200);
      leds_OUTSIDE[280] = CHSV(160, 200, 200);
      leds_OUTSIDE[281] = CHSV(160, 200, 200);
      leds_OUTSIDE[282] = CHSV(160, 200, 200);
      leds_OUTSIDE[283] = CHSV(160, 200, 200);
      leds_OUTSIDE[284] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[259] = CHSV(160, 200, 0);
      leds_OUTSIDE[260] = CHSV(160, 200, 0);
      leds_OUTSIDE[261] = CHSV(160, 200, 0);
      leds_OUTSIDE[262] = CHSV(160, 200, 0);
      leds_OUTSIDE[263] = CHSV(160, 200, 0);
      leds_OUTSIDE[264] = CHSV(160, 200, 0);
      leds_OUTSIDE[265] = CHSV(160, 200, 0);
      leds_OUTSIDE[266] = CHSV(160, 200, 0);
      leds_OUTSIDE[267] = CHSV(160, 200, 0);
      leds_OUTSIDE[268] = CHSV(160, 200, 0);
      leds_OUTSIDE[269] = CHSV(160, 200, 0);
      leds_OUTSIDE[270] = CHSV(160, 200, 0);
      leds_OUTSIDE[271] = CHSV(160, 200, 0);
      leds_OUTSIDE[272] = CHSV(160, 200, 0);
      leds_OUTSIDE[273] = CHSV(160, 200, 0);
      leds_OUTSIDE[274] = CHSV(160, 200, 0);
      leds_OUTSIDE[275] = CHSV(160, 200, 0);
      leds_OUTSIDE[276] = CHSV(160, 200, 0);
      leds_OUTSIDE[277] = CHSV(160, 200, 0);
      leds_OUTSIDE[278] = CHSV(160, 200, 0);
      leds_OUTSIDE[279] = CHSV(160, 200, 0);
      leds_OUTSIDE[280] = CHSV(160, 200, 0);
      leds_OUTSIDE[281] = CHSV(160, 200, 0);
      leds_OUTSIDE[282] = CHSV(160, 200, 0);
      leds_OUTSIDE[283] = CHSV(160, 200, 0);
      leds_OUTSIDE[284] = CHSV(160, 200, 0);
      break;
  }
  V_B_B22_NEW = digitalRead(B_B22);
  if (V_B_B22_OLD == 0 && V_B_B22_NEW == 1) {
    if (V_LED_B22 == 0) {
      V_LED_B22 = 1;
    } else {
      V_LED_B22 = 0;
    }
  }
  V_B_B22_OLD = V_B_B22_NEW;
  switch (V_LED_B22) {
    case 0:
      leds_OUTSIDE[285] = CHSV(160, 200, 200);
      leds_OUTSIDE[286] = CHSV(160, 200, 200);
      leds_OUTSIDE[287] = CHSV(160, 200, 200);
      leds_OUTSIDE[288] = CHSV(160, 200, 200);
      leds_OUTSIDE[289] = CHSV(160, 200, 200);
      leds_OUTSIDE[290] = CHSV(160, 200, 200);
      leds_OUTSIDE[291] = CHSV(160, 200, 200);
      leds_OUTSIDE[292] = CHSV(160, 200, 200);
      leds_OUTSIDE[293] = CHSV(160, 200, 200);
      leds_OUTSIDE[294] = CHSV(160, 200, 200);
      leds_OUTSIDE[295] = CHSV(160, 200, 200);
      leds_OUTSIDE[296] = CHSV(160, 200, 200);
      leds_OUTSIDE[297] = CHSV(160, 200, 200);
      leds_OUTSIDE[298] = CHSV(160, 200, 200);
      leds_OUTSIDE[299] = CHSV(160, 200, 200);
      leds_OUTSIDE[300] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[285] = CHSV(160, 200, 0);
      leds_OUTSIDE[286] = CHSV(160, 200, 0);
      leds_OUTSIDE[287] = CHSV(160, 200, 0);
      leds_OUTSIDE[288] = CHSV(160, 200, 0);
      leds_OUTSIDE[289] = CHSV(160, 200, 0);
      leds_OUTSIDE[290] = CHSV(160, 200, 0);
      leds_OUTSIDE[291] = CHSV(160, 200, 0);
      leds_OUTSIDE[292] = CHSV(160, 200, 0);
      leds_OUTSIDE[293] = CHSV(160, 200, 0);
      leds_OUTSIDE[294] = CHSV(160, 200, 0);
      leds_OUTSIDE[295] = CHSV(160, 200, 0);
      leds_OUTSIDE[296] = CHSV(160, 200, 0);
      leds_OUTSIDE[297] = CHSV(160, 200, 0);
      leds_OUTSIDE[298] = CHSV(160, 200, 0);
      leds_OUTSIDE[299] = CHSV(160, 200, 0);
      leds_OUTSIDE[300] = CHSV(160, 200, 0);
      break;
  }
  V_B_B23_NEW = digitalRead(B_B23);
  if (V_B_B23_OLD == 0 && V_B_B23_NEW == 1) {
    if (V_LED_B23 == 0) {
      V_LED_B23 = 1;
    } else {
      V_LED_B23 = 0;
    }
  }
  V_B_B23_OLD = V_B_B23_NEW;
  switch (V_LED_B23) {
    case 0:
      leds_OUTSIDE[301] = CHSV(160, 200, 200);
      leds_OUTSIDE[302] = CHSV(160, 200, 200);
      leds_OUTSIDE[303] = CHSV(160, 200, 200);
      leds_OUTSIDE[304] = CHSV(160, 200, 200);
      leds_OUTSIDE[305] = CHSV(160, 200, 200);
      leds_OUTSIDE[306] = CHSV(160, 200, 200);
      leds_OUTSIDE[307] = CHSV(160, 200, 200);
      leds_OUTSIDE[308] = CHSV(160, 200, 200);
      leds_OUTSIDE[309] = CHSV(160, 200, 200);
      leds_OUTSIDE[310] = CHSV(160, 200, 200);
      leds_OUTSIDE[311] = CHSV(160, 200, 200);
      leds_OUTSIDE[312] = CHSV(160, 200, 200);
      leds_OUTSIDE[313] = CHSV(160, 200, 200);
      leds_OUTSIDE[314] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[301] = CHSV(160, 200, 0);
      leds_OUTSIDE[302] = CHSV(160, 200, 0);
      leds_OUTSIDE[303] = CHSV(160, 200, 0);
      leds_OUTSIDE[304] = CHSV(160, 200, 0);
      leds_OUTSIDE[305] = CHSV(160, 200, 0);
      leds_OUTSIDE[306] = CHSV(160, 200, 0);
      leds_OUTSIDE[307] = CHSV(160, 200, 0);
      leds_OUTSIDE[308] = CHSV(160, 200, 0);
      leds_OUTSIDE[309] = CHSV(160, 200, 0);
      leds_OUTSIDE[310] = CHSV(160, 200, 0);
      leds_OUTSIDE[311] = CHSV(160, 200, 0);
      leds_OUTSIDE[312] = CHSV(160, 200, 0);
      leds_OUTSIDE[313] = CHSV(160, 200, 0);
      leds_OUTSIDE[314] = CHSV(160, 200, 0);
      break;
  }
  V_B_B24_NEW = digitalRead(B_B24);
  if (V_B_B24_OLD == 0 && V_B_B24_NEW == 1) {
    if (V_LED_B24 == 0) {
      V_LED_B24 = 1;
    } else {
      V_LED_B24 = 0;
    }
  }
  V_B_B24_OLD = V_B_B24_NEW;
  switch (V_LED_B24) {
    case 0:
      leds_OUTSIDE[314] = CHSV(160, 200, 200);
      leds_OUTSIDE[315] = CHSV(160, 200, 200);
      leds_OUTSIDE[316] = CHSV(160, 200, 200);
      leds_OUTSIDE[317] = CHSV(160, 200, 200);
      leds_OUTSIDE[318] = CHSV(160, 200, 200);
      leds_OUTSIDE[319] = CHSV(160, 200, 200);
      leds_OUTSIDE[320] = CHSV(160, 200, 200);
      leds_OUTSIDE[321] = CHSV(160, 200, 200);
      leds_OUTSIDE[322] = CHSV(160, 200, 200);
      leds_OUTSIDE[323] = CHSV(160, 200, 200);
      leds_OUTSIDE[324] = CHSV(160, 200, 200);
      leds_OUTSIDE[325] = CHSV(160, 200, 200);
      leds_OUTSIDE[326] = CHSV(160, 200, 200);
      leds_OUTSIDE[327] = CHSV(160, 200, 200);
      leds_OUTSIDE[328] = CHSV(160, 200, 200);
      leds_OUTSIDE[329] = CHSV(160, 200, 200);
      leds_OUTSIDE[330] = CHSV(160, 200, 200);
      leds_OUTSIDE[331] = CHSV(160, 200, 200);
      leds_OUTSIDE[332] = CHSV(160, 200, 200);
      leds_OUTSIDE[333] = CHSV(160, 200, 200);
      leds_OUTSIDE[334] = CHSV(160, 200, 200);
      leds_OUTSIDE[335] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[314] = CHSV(160, 200, 0);
      leds_OUTSIDE[315] = CHSV(160, 200, 0);
      leds_OUTSIDE[316] = CHSV(160, 200, 0);
      leds_OUTSIDE[317] = CHSV(160, 200, 0);
      leds_OUTSIDE[318] = CHSV(160, 200, 0);
      leds_OUTSIDE[319] = CHSV(160, 200, 0);
      leds_OUTSIDE[320] = CHSV(160, 200, 0);
      leds_OUTSIDE[321] = CHSV(160, 200, 0);
      leds_OUTSIDE[322] = CHSV(160, 200, 0);
      leds_OUTSIDE[323] = CHSV(160, 200, 0);
      leds_OUTSIDE[324] = CHSV(160, 200, 0);
      leds_OUTSIDE[325] = CHSV(160, 200, 0);
      leds_OUTSIDE[326] = CHSV(160, 200, 0);
      leds_OUTSIDE[327] = CHSV(160, 200, 0);
      leds_OUTSIDE[328] = CHSV(160, 200, 0);
      leds_OUTSIDE[329] = CHSV(160, 200, 0);
      leds_OUTSIDE[330] = CHSV(160, 200, 0);
      leds_OUTSIDE[331] = CHSV(160, 200, 0);
      leds_OUTSIDE[332] = CHSV(160, 200, 0);
      leds_OUTSIDE[333] = CHSV(160, 200, 0);
      leds_OUTSIDE[334] = CHSV(160, 200, 0);
      leds_OUTSIDE[335] = CHSV(160, 200, 0);
      break;
  }
  V_B_B25_NEW = digitalRead(B_B25);
  if (V_B_B25_OLD == 0 && V_B_B25_NEW == 1) {
    if (V_LED_B25 == 0) {
      V_LED_B25 = 1;
    } else {
      V_LED_B25 = 0;
    }
  }
  V_B_B25_OLD = V_B_B25_NEW;
  switch (V_LED_B25) {
    case 0:
      leds_OUTSIDE[336] = CHSV(160, 200, 200);
      leds_OUTSIDE[337] = CHSV(160, 200, 200);
      leds_OUTSIDE[338] = CHSV(160, 200, 200);
      leds_OUTSIDE[339] = CHSV(160, 200, 200);
      leds_OUTSIDE[340] = CHSV(160, 200, 200);
      leds_OUTSIDE[341] = CHSV(160, 200, 200);
      leds_OUTSIDE[342] = CHSV(160, 200, 200);
      leds_OUTSIDE[343] = CHSV(160, 200, 200);
      leds_OUTSIDE[344] = CHSV(160, 200, 200);
      leds_OUTSIDE[345] = CHSV(160, 200, 200);
      leds_OUTSIDE[346] = CHSV(160, 200, 200);
      leds_OUTSIDE[347] = CHSV(160, 200, 200);
      leds_OUTSIDE[348] = CHSV(160, 200, 200);
      leds_OUTSIDE[349] = CHSV(160, 200, 200);
      leds_OUTSIDE[350] = CHSV(160, 200, 200);
      leds_OUTSIDE[351] = CHSV(160, 200, 200);
      leds_OUTSIDE[352] = CHSV(160, 200, 200);
      leds_OUTSIDE[353] = CHSV(160, 200, 200);
      leds_OUTSIDE[354] = CHSV(160, 200, 200);
      leds_OUTSIDE[355] = CHSV(160, 200, 200);
      leds_OUTSIDE[356] = CHSV(160, 200, 200);
      leds_OUTSIDE[357] = CHSV(160, 200, 200);
      leds_OUTSIDE[358] = CHSV(160, 200, 200);
      leds_OUTSIDE[359] = CHSV(160, 200, 200);
      leds_OUTSIDE[360] = CHSV(160, 200, 200);
      leds_OUTSIDE[361] = CHSV(160, 200, 200);
      leds_OUTSIDE[362] = CHSV(160, 200, 200);
      leds_OUTSIDE[363] = CHSV(160, 200, 200);
      leds_OUTSIDE[364] = CHSV(160, 200, 200);
      leds_OUTSIDE[365] = CHSV(160, 200, 200);
      leds_OUTSIDE[366] = CHSV(160, 200, 200);
      leds_OUTSIDE[367] = CHSV(160, 200, 200);
      break;
    case 1:
      leds_OUTSIDE[336] = CHSV(160, 200, 0);
      leds_OUTSIDE[337] = CHSV(160, 200, 0);
      leds_OUTSIDE[338] = CHSV(160, 200, 0);
      leds_OUTSIDE[339] = CHSV(160, 200, 0);
      leds_OUTSIDE[340] = CHSV(160, 200, 0);
      leds_OUTSIDE[341] = CHSV(160, 200, 0);
      leds_OUTSIDE[342] = CHSV(160, 200, 0);
      leds_OUTSIDE[343] = CHSV(160, 200, 0);
      leds_OUTSIDE[344] = CHSV(160, 200, 0);
      leds_OUTSIDE[345] = CHSV(160, 200, 0);
      leds_OUTSIDE[346] = CHSV(160, 200, 0);
      leds_OUTSIDE[347] = CHSV(160, 200, 0);
      leds_OUTSIDE[348] = CHSV(160, 200, 0);
      leds_OUTSIDE[349] = CHSV(160, 200, 0);
      leds_OUTSIDE[350] = CHSV(160, 200, 0);
      leds_OUTSIDE[351] = CHSV(160, 200, 0);
      leds_OUTSIDE[352] = CHSV(160, 200, 0);
      leds_OUTSIDE[353] = CHSV(160, 200, 0);
      leds_OUTSIDE[354] = CHSV(160, 200, 0);
      leds_OUTSIDE[355] = CHSV(160, 200, 0);
      leds_OUTSIDE[356] = CHSV(160, 200, 0);
      leds_OUTSIDE[357] = CHSV(160, 200, 0);
      leds_OUTSIDE[358] = CHSV(160, 200, 0);
      leds_OUTSIDE[359] = CHSV(160, 200, 0);
      leds_OUTSIDE[360] = CHSV(160, 200, 0);
      leds_OUTSIDE[361] = CHSV(160, 200, 0);
      leds_OUTSIDE[362] = CHSV(160, 200, 0);
      leds_OUTSIDE[363] = CHSV(160, 200, 0);
      leds_OUTSIDE[364] = CHSV(160, 200, 0);
      leds_OUTSIDE[365] = CHSV(160, 200, 0);
      leds_OUTSIDE[366] = CHSV(160, 200, 0);
      leds_OUTSIDE[367] = CHSV(160, 200, 0);
      break;
  }

  V_B_B26_NEW = digitalRead(B_B26);
  if (V_B_B26_OLD == 0 && V_B_B26_NEW == 1) {
    if (V_LED_B26 == 0) {
      V_LED_B26 = 1;
    } else {
      V_LED_B26 = 0;
    }
  }
  V_B_B26_OLD = V_B_B26_NEW;
  switch (V_LED_B26) {
    case 0:
      leds_OUTSIDE[368] = CHSV(160, 200, 200);
      leds_OUTSIDE[369] = CHSV(160, 200, 200);
      leds_OUTSIDE[370] = CHSV(160, 200, 200);
      leds_OUTSIDE[371] = CHSV(160, 200, 200);
      leds_OUTSIDE[372] = CHSV(160, 200, 200);
      leds_OUTSIDE[373] = CHSV(160, 200, 200);
      leds_OUTSIDE[374] = CHSV(160, 200, 200);
      leds_OUTSIDE[375] = CHSV(160, 200, 200);
      leds_OUTSIDE[376] = CHSV(160, 200, 200);
      leds_OUTSIDE[377] = CHSV(160, 200, 200);
      leds_OUTSIDE[378] = CHSV(160, 200, 200);
      leds_OUTSIDE[379] = CHSV(160, 200, 200);
      leds_OUTSIDE[380] = CHSV(160, 200, 200);
      leds_OUTSIDE[381] = CHSV(160, 200, 200);
      leds_OUTSIDE[382] = CHSV(160, 200, 200);
      leds_OUTSIDE[383] = CHSV(160, 200, 200);

      break;
    case 1:
      leds_OUTSIDE[368] = CHSV(160, 200, 0);
      leds_OUTSIDE[369] = CHSV(160, 200, 0);
      leds_OUTSIDE[370] = CHSV(160, 200, 0);
      leds_OUTSIDE[371] = CHSV(160, 200, 0);
      leds_OUTSIDE[372] = CHSV(160, 200, 0);
      leds_OUTSIDE[373] = CHSV(160, 200, 0);
      leds_OUTSIDE[374] = CHSV(160, 200, 0);
      leds_OUTSIDE[375] = CHSV(160, 200, 0);
      leds_OUTSIDE[376] = CHSV(160, 200, 0);
      leds_OUTSIDE[377] = CHSV(160, 200, 0);
      leds_OUTSIDE[378] = CHSV(160, 200, 0);
      leds_OUTSIDE[379] = CHSV(160, 200, 0);
      leds_OUTSIDE[380] = CHSV(160, 200, 0);
      leds_OUTSIDE[381] = CHSV(160, 200, 0);
      leds_OUTSIDE[382] = CHSV(160, 200, 0);
      leds_OUTSIDE[383] = CHSV(160, 200, 0);
      break;
  }




  //  delay(dt);
  FastLED.show();
}