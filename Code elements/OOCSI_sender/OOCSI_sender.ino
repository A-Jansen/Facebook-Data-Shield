/******************************************************************************
   Example of the OOCSI-ESP library connecting to WiFi and sending messages
   over OOCSI. Designed to work with the Processing OOCSI receiver example
   that is provided in the same directory
 ******************************************************************************/

#include "OOCSI.h"
#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>


// use this if you want the OOCSI-ESP library to manage the connection to the Wifi
// SSID of your Wifi network, the library currently does not support WPA2 Enterprise networks

const char* ssid = "...";
// Password of your Wifi network.

const char* password = "...";

// name for connecting with OOCSI (unique handle)
const char* OOCSIName = "...";
// put the adress of your OOCSI server here, can be URL or IP address string
const char* hostserver = "oocsi.id.tue.nl";

// OOCSI reference for the entire sketch
OOCSI oocsi = OOCSI();


//variables
int ID;
int buttonPressed;  //use some kind of dictionary afterward to convert them to the names
int activated;
String button;
int button1;
int button2;
// const char* Button1 = "test1";
// const char* Button2 = "test2";
String buttonStates;


int coreButtons[4];
int complexButtons[26];


int status = WL_IDLE_STATUS;  // the Wi-Fi radio's status
// put your setup code here, to run once:
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);  //Serial1 for the communication with the mega

  // attempt to connect to Wi-Fi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, password);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");
  Serial.println("---------------------------------------");

  // output OOCSI activity on the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
  oocsi.setActivityLEDPin(LED_BUILTIN);

  // use this to switch off logging to Serial
  // oocsi.setLogging(false);

  // setting up OOCSI. processOOCSI is the name of the function to call when receiving messages, can be a random function name
  // connect wifi and OOCSI to the server
  oocsi.connect(OOCSIName, hostserver, ssid, password);
}

// put your main code here, to run repeatedly:
void loop() {
  while (Serial1.available() >= 0) {


    String incomingString = Serial1.readStringUntil('\n');
    if (incomingString.length() != 0) {
      Serial.println(incomingString);

      oocsi.newMessage("DDW_test_channel");
      //oocsi.addInt("ID_test", 1);
      oocsi.addString("DataDump", incomingString.c_str());
      oocsi.sendMessage();
      oocsi.keepAlive();

      if (incomingString.charAt(0) == 'r') {
        //"r0001010" => id =0001 and button=01 and it is off (0)
        String stringID = incomingString.substring(1, 5);
        ID = stringID.toInt();
        String stringButton = incomingString.substring(5, 7);
        buttonPressed = stringButton.toInt();
        activated = String(incomingString.charAt(7)).toInt();
        logRawData(ID, buttonPressed, activated);
      }
      if (incomingString.charAt(0) == 'u') {
        //"u0001120,1,1,1,0," ID=0001, button1= 1, button2= 2, buttonstate="0,1,1,1,0,"
        String stringID = incomingString.substring(1, 5);
        ID = stringID.toInt();
        String stringButton1 = incomingString.substring(5, 6);
        button1 = stringButton1.toInt();
        String stringButton2 = incomingString.substring(6, 7);
        button2 = stringButton2.toInt();
        Serial.println(incomingString.substring(7));
        buttonStates = incomingString.substring(7);
        // byte buffer[buttonStates.length() + 1];
        // buttonStates.toCharArray(buffer, buttonStates.length() + 1);
        logUploadData(ID, button1, button2, buttonStates);
      }
    }
  }
}


void logRawData(int _ID, int _buttonPressed, int _activated) {
  // create a new message
  oocsi.newMessage("rawDataFacebookDataShield");

  oocsi.addInt("ID_day", _ID);
  oocsi.addInt("buttonPressed", _buttonPressed);
  oocsi.addInt("activated", _activated);

  // this command will send the message; don't forget to call this after creating a message
  oocsi.sendMessage();

  // prints out the raw message (how it is sent to the OOCSI server)
  oocsi.printSendMessage();

  // let OOCSI keep the connection to the OOCSI server fresh and crunchy
  // use this keepAlive() function if you do NOT need to receive data from OOCSI
  // use the check() function if you also need to process incoming messages
  oocsi.keepAlive();
}

void logUploadData(int _ID, int _button1, int _button2, String _buttonStates) {
  oocsi.newMessage("uploadButtonFacebookDataShield");

  oocsi.addInt("ID_day", _ID);  //ID of the participant, is day specific
  oocsi.addInt("button1", _button1);
  oocsi.addInt("button2", _button2);
  //oocsi.addString("button1", Button1);  //one of the two buttons pressed to start the session --> should be "NA" if nothing
  //oocsi.addString("button2", Button2);  //one of the two buttons pressed to start the session --> should be "NA" if nothing
  oocsi.addString("allButtonState", _buttonStates.c_str());

  // this command will send the message; don't forget to call this after creating a message
  oocsi.sendMessage();

  // prints out the raw message (how it is sent to the OOCSI server)
  oocsi.printSendMessage();

  // let OOCSI keep the connection to the OOCSI server fresh and crunchy
  // use this keepAlive() function if you do NOT need to receive data from OOCSI
  // use the check() function if you also need to process incoming messages
  oocsi.keepAlive();
}