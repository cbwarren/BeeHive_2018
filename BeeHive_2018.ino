/* Using this code to do basic testing of the ESP board in the hive monitor
 *  ? is it problem with HSX library?
 *  did i get this into github?
 *  Need to confirm this can still use wifi
 */

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
// ----------- weigh scale section ----
#include "HX711.h"
#define DOUT  12  // CONFIRM!
#define CLK  13   // CONFIRM!


HX711 scale(DOUT, CLK);
long zero_factor = 1195657;
int calibration_factor = -21430; //-21450 worked for 150kg max scale setup - intial calibration
//float weight_kg;




//--------------------  ESP wifi setup  ---------------

#include <ESP8266WiFi.h>// this library is not visible unless the ESP board is selected.
#include <WiFiClientSecure.h>
#include <StreamString.h>
#include <base64.h>
#include <ESP8266HTTPClient.h>
#include "config.h"

  //AdafruitIO_Feed *weight = io.feed("beehive_weight");


void setup() {
  Serial.begin(9600);
  Serial.println("weigh scale test");
/*
  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  */
}
  
void loop() {
    // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  
  //io.run();
float Myweight = GetWeight(); // just simple test
    
    Serial.print("Weight =  ");
    Serial.print(Myweight);
    Serial.println(" kg");
  
    //weight->save(Myweight);
    
    Serial.println();
    delay(20000);// update every 1 minutes
}
//-----------------------------------------
float GetWeight() {
  float weight;
  weight = scale.get_units(), 1; // returns a float
  
  return weight;
}
//-----------------------------------------
