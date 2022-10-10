/*********************************************************************
   Example of the ESP connecting to WiFi and accessing items in an
   Entity dataset on the Data Foundry.
   This works only with an existing account, project and dataset on
   the Data Foundry (https://data.id.tue.nl)
 *********************************************************************/

#include "DFDataset.h"
int ID;
int buttonPressed; //use some kind of dictionary afterward to convert them to the names
bool activated;
String button;
const char* Button1 = "test1";
const char* Button2= "test2";


int coreButtons[4];
int complexButtons[26];

// SSID of your Wifi network, the library currently does not support WPA2 Enterprise networks
const char* ssid = "yourssid";
// Password of your Wifi network.
const char* password = "yourpassword";

// put the adress of Data Foundry here
const char* datafoundry = "data.id.tue.nl";

// create connection to dataset with server address, dataset id, and the access token
DFDataset iotRaw(datafoundry, 2809, "ZEVGMGJpMm1RUk1hWCtQL3lvQWJ1cTBxUmVLa0ZiRnVwVlc5L2xzQlJiOD0");
DFDataset iotUpload(datafoundry, 2809, "WnBPNUNqTWw3MnNlYkJqejJCa25VVUhJYnRmQjBmaEl6dnpBWDVJVEgrND0=");
// put your setup code here, to run once:
void setup() {
  Serial.begin(115200);

  // establish Wifi connection
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print('.');
  }

  Serial.println("Connected to the WiFi network");

  // you can also already set the device and activity here,
  // if they don't change throughout the program execution
  //  iot.device("mydevice");
  //  iot.activity("idle");
}

void loop() {

  logRawData();

  delay(10000);
}


void logRawData(){
  // specify device, can be empty
  iotRaw.device("");
  // specify activity, can be empty
  iotRaw.activity("");

  // fill in some data for the item (very similar to OOCSI)
  iotRaw.addInt("ID_day", ID); //ID of the participant, is day specific 
  iotRaw.addInt("buttonPressed", buttonPressed); //string variable with the name of the button pressed, or if too difficult the number
  iotRaw.addBool("activated", activated); //boolean variable to record if it is activated (true) or deactivated (false)
 
  // log the item data to the dataset
  iotRaw.logItem();
}

void logUploadData(){
  iotUpload.device("");
  iotUpload.activity("");


  iotUpload.addInt("ID_day", ID); //ID of the participant, is day specific 
  iotUpload.addString("button1", Button1); //one of the two buttons pressed to start the session --> should be "NA" if nothing
  iotUpload.addString("button2", Button2); //one of the two buttons pressed to start the session --> should be "NA" if nothing

  //final states for all buttons (1 active, 0 not)
   for (int i = 0; i < sizeof(coreButtons); i++) {
     bool finalState = true;//coreButtons[i].checkFinalState();
     button= String("Corebutton");
     button += i;
     iotUpload.addBool("button", finalState);

  }
   for (int i = 0; i < sizeof(complexButtons); i++) {
    bool finalState = false;//complexButtons[i].checkFinalState();
     button= String("Complexbutton");
     button += i;
     iotUpload.addBool("button", finalState);
  }
 // log the item data to the dataset
  iotUpload.logItem();
}