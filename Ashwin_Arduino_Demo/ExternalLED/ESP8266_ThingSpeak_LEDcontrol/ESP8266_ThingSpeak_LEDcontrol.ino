/*
  Control an LED through ThingSpeak ( https://www.thingspeak.com )

  by: 
  Alaa Al Nassan, ROBOSAN
  http://alaa-nassan.weebly.com
  based on an ThingSpeak Library example
*/

/* Ashwin using for IOT
 *  https://api.thingspeak.com/update?api_key=IMK71GRLUXK88MP4&field1=0
 *  COM port is just to see the status you cannot do anything in this
 *  url is used to update the value of LED
 *  thinkspeak is used ot view the status of LED
 *  Note after modifying  1 to 0 or vice - versa in url
 *  to get it reflect to hardware we need to refresh the thinspeak site 
 *  Note:- When connected to relay follow below circuit diagram
 *  https://randomnerdtutorials.com/esp8266-relay-module-ac-web-server/
 *  Also note that relay LED at input side goes in reverse order of output
 * */
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

#define LED D1

char ssid[] = "NETGEAR04";          //  your network SSID (name) 
char pass[] = "narrowplanet649";   // your network password

int status = WL_IDLE_STATUS;
WiFiClient  client;
int readValue; // variable to save channel field reading
    
unsigned long myChannelNumber = 1129852; // modify this with your own Channel Number
const char * myReadAPIKey = "HT5XADWQ1PZWMUDM";

void setup() {
  Serial.begin(9600); // for debugging reasons
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);
}

void loop() {
  // Read the latest value from field 1 of your channel
   readValue = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
  Serial.print("readValue = "); // debugging instrument
  Serial.println(readValue);    // debugging instrument

  if ( readValue == 1){
    digitalWrite(LED, HIGH); // please notice if you need to modify this to LOW 
                            //  if your board's port active low
  }
  else{
    digitalWrite(LED, LOW); // please notice if you need to modify this to HIGH 
                            //  if your board's port active low   
  }
}
