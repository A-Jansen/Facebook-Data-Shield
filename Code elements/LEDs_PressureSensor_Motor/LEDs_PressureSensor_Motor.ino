#include <DataButton.h>
#include <FastLED.h>
#include <Stepper.h>

//LED strips -----------------------------
#define LED_PIN_CORE 8
#define LED_PIN_COMPLEX 9
#define LED_PIN_OUTERRIM 10

#define NUM_LEDS_CORE 87
#define NUM_LEDS_COMPLEX 233   //leds in complex layer
#define NUM_LEDS_OUTERRIM 283  //outer rim

CRGB leds_CORE[NUM_LEDS_CORE];
CRGB leds_COMPLEX[NUM_LEDS_COMPLEX];
CRGB leds_OUTERRIM[NUM_LEDS_OUTERRIM];
CHSV OUTERRIM_COLORS[NUM_LEDS_OUTERRIM];

int OUTERRIM_SAT[NUM_LEDS_OUTERRIM];

//---------------------------------------

//define buttonpins, met de klok mee
#define uploadbuttonpin 5

#define corebutton1 7
#define corebutton2 2
#define corebutton3 6
#define corebutton4 4
#define corebutton5 3

#define numCoreButtons 5

#define complexbutton1_1 39
#define complexbutton1_2 25
#define complexbutton1_3 35
#define complexbutton1_4 38
#define complexbutton1_5 16
#define complexbutton1_6 32
#define complexbutton1_7 31

#define numComplex1 7

#define complexbutton2_1 34
#define complexbutton2_2 30
#define complexbutton2_3 17
#define complexbutton2_4 33
#define complexbutton2_5 27
#define complexbutton2_6 13

#define numComplex2 6

#define complexbutton3_1 28
#define complexbutton3_2 12
#define complexbutton3_3 15
#define complexbutton3_4 22

#define numComplex3 4

#define complexbutton4_1 37
#define complexbutton4_2 40
#define complexbutton4_3 24
#define complexbutton4_4 23
#define complexbutton4_5 36
#define complexbutton4_6 29
#define complexbutton4_7 26

#define numComplex4 7


#define complexbutton5_1 11
#define complexbutton5_2 14

#define numComplex5 2

#define pin_pressureSensor 41  //voetmat

#define pin_seeMoreButton 67

//for the motor
#define dirPin 69   //groen
#define stepPin 68  // blauw

/////// Aders connecting core and complex layer
int ader1[] = { 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106 };
int ader1Len = 26;
int ader2[] = { 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 };
int ader2Len = 27;
int ader3[] = { 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53 };
int ader3Len = 17;
int ader4[] = { 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37 };
int ader4Len = 29;
int ader5[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
int ader5Len = 9;

int prevRead = 1;
int value = 0;

//------ DataButton objects
//DataButton name(buttonpin, startValue, endValue) start and end of LED
DataButton uploadButton(uploadbuttonpin, 63, 77, 1);

//see More button
DataButton seeMoreButton(pin_seeMoreButton, 0, 0, 0);


DataButton coreButtons[] = {
  DataButton(corebutton1, 84, 87, 7),
  DataButton(corebutton2, 57, 62, 6),
  DataButton(corebutton3, 51, 56, 4),
  DataButton(corebutton4, 44, 50, 7),
  DataButton(corebutton5, 37, 43, 2)
};

char *coreNames[] = { "yourBehavior", "yourTechnologicalSetup", "YourDemographicInformation", "Post-RelatedInformation" };


DataButton complexButtonsCore1[] = {
  DataButton(complexbutton1_1, 232, 233, 1), DataButton(complexbutton1_2, 107, 111, 1), DataButton(complexbutton1_3, 112, 116, 1), DataButton(complexbutton1_4, 117, 121, 1),
  DataButton(complexbutton1_5, 122, 126, 1), DataButton(complexbutton1_6, 127, 131, 1), DataButton(complexbutton1_7, 132, 136, 1)
};


DataButton complexButtonsCore2[] = {
  DataButton(complexbutton2_1, 137, 141, 1), DataButton(complexbutton2_2, 142, 146, 1), DataButton(complexbutton2_3, 147, 151, 1), DataButton(complexbutton2_4, 152, 156, 1),
  DataButton(complexbutton2_5, 157, 161, 1), DataButton(complexbutton2_6, 162, 166, 1)
};

DataButton complexButtonsCore3[] = {
  DataButton(complexbutton3_1, 167, 172, 1), DataButton(complexbutton3_2, 173, 177, 1), DataButton(complexbutton3_3, 178, 182, 1), DataButton(complexbutton3_4, 183, 186, 1)
};


DataButton complexButtonsCore4[] = {
  DataButton(complexbutton4_1, 187, 191, 1), DataButton(complexbutton4_2, 192, 196, 1), DataButton(complexbutton4_3, 197, 201, 1), DataButton(complexbutton4_4, 202, 206, 1),
  DataButton(complexbutton4_5, 207, 211, 1), DataButton(complexbutton4_6, 212, 216, 1), DataButton(complexbutton4_7, 217, 221, 1)
};

DataButton complexButtonsCore5[] = {
  DataButton(complexbutton5_1, 222, 226, 1), DataButton(complexbutton5_2, 227, 231, 1)
};
//---------------------------



//--------------------------------------
//Variables sketch LEDS
int speedLight = 60;
uint16_t speedLightTimer = 6;
int fullSpeed = 6;
int brightnessOverall = 255;

int activeCoreGroup1 = 7;
int activeCoreGroup2 = 6;
int activeCoreGroup3 = 4;
int activeCoreGroup4 = 7;
int activeCoreGroup5 = 1;

bool upload = false;  // boolean to check if upload was pressed --> use to call function outside of class

//float adjuster = 1;  //multiplier for speedLight and Brightness based on how much is on/off --> 0 if all off, 1 all on
int active = 31;
int oldActive = 31;

//Variables for logging data
int button1;
int button2;



//variables pressure sensor

int thisState = 1;  //current state of the pressure mat
int lastState = 1;  //last state of the pressure mat
bool changeDetected = 0;
bool longPause = 1;  //ensuring that there is at least intervalMillisLow between reading the first low and the first high --> otherwise on low reading could increase the ID number

bool resetOnce = 0;

int ID = 0;  //id of the current interaction, will be reset when disconnected

unsigned long lastLowMillis;   // stores the millis() of when it first becomes high
unsigned long lastHighMillis;  //stores the millis() of when it first becomes low
int intervalMillisLow = 2000;  //at least 2 seconds low before possible to register second one
int intervalMillisHigh = 500;  //at least 500 ms high before adding new ID

//variables motor
//#define stepsPerRevolution 2000
//const int stepsPerRevolution = 200;
//Stepper myStepper(stepsPerRevolution, stepPin, dirPin);  //blauw pin 7
bool turning = false;                                    // track if the shield is turning

int button1ID;
int button2ID;

bool twobuttons = true;
bool twoButtonsChecked = false;
bool firstPressed = false;

unsigned long startTwoMillis;
unsigned long firstButtonMillis;


int counter = 0;
int but1;
int but2;


void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial.println("Starting");
  //pinMode is set when the object is created
  //myStepper.setSpeed(200);

  pinMode(LED_PIN_CORE, OUTPUT);
  pinMode(LED_PIN_COMPLEX, OUTPUT);
  pinMode(LED_PIN_OUTERRIM, OUTPUT);
  pinMode(pin_pressureSensor, INPUT_PULLUP);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  FastLED.addLeds<WS2812B, LED_PIN_COMPLEX, GRB>(leds_COMPLEX, NUM_LEDS_COMPLEX);
  FastLED.addLeds<WS2812B, LED_PIN_CORE, GRB>(leds_CORE, NUM_LEDS_CORE);
  FastLED.addLeds<WS2812B, LED_PIN_OUTERRIM, GRB>(leds_OUTERRIM, NUM_LEDS_OUTERRIM);

  turnAllOn();
  outerrimLEDSsetup();
  FastLED.show();
}

void loop() {
 // Serial.print("see more button: ");
 // Serial.println(digitalRead(pin_seeMoreButton));
   Serial.print("active: ");
  Serial.println(active);
  checkPresence();  //read the value of the pressure sensor to see if someone is standing on it
  //Serial.println(activeCoreGroup1);
  brightnessOverall = int(map(active, 0, 31, 10, 255));
  if (!turning) {
    outerrimLEDS2();
  } 
  uploadButton.uploadButtonPress(leds_CORE, active, upload);
  seeMoreButton.turn(turning);
  //Serial.print("See more: ");
 // Serial.println(turning);
  //turnShield();
  coreButtonsFunction();
  complexButtons();
  //checkTwoHighs();


  if (upload) {
    sendUpload(ID);
    resetInstallation();
    upload = false;
  }
  FastLED.show();
}