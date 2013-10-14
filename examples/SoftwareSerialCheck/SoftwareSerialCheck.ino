#include <SoftwareSerial.h>

// Do you actually have your SoftwareSerial hooked up correctly?   Find out with this. 
// Tested with Sparkfun CPD2103 module.   

#define TX 6
#define RX 7
SoftwareSerial SoS = SoftwareSerial(RX,TX); 


void setup()  {
  Serial.begin(9600);
  SoS.begin(9600);
  Serial.println("Starting up"); 
  SoS.println("(Software) Starting up");
}

void loop()  {
  Serial.print("(Hardware) I'm sending something... "); 
  SoS.println("(Software) Hello out the Software Serial Port"); 
  SoS.println("(Software) This one is the Software Serial Port"); 
  Serial.println("I sent two lines");
  delay(1000); 
}


