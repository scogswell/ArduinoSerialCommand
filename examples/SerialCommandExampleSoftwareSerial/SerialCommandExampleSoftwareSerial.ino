// Demo Code for SerialCommand Library.
// This example uses a SoftwareSerial object instead of the Hardware Serial port. 
// 
// Make sure your SoftwareSerial port is actually functioning correctly before 
// you use this.  See sketch for SoftwareSerialCheck included with this library. 
//
// For this demo, all the command output is also echoed to the Hardware Serial port
// which you might find useful for debugging that you have it working correctly. 
//
// Steven Cogswell
// October 2013

#include <SoftwareSerial.h> 
#include <SerialCommand.h>

#define arduinoLED 13   // Arduino LED on board

// Parameters for SoftwareSerial port.  For this example a Sparkfun CP2103 Breakout Module
// was used.  Change defines as appopriate for your use.  
// CP2103  -- Arduino
// 3.3V       3.3V 
// TX-O       pin 7
// RX-I       pin 6
// GND        GND
#define TX 6
#define RX 7
SoftwareSerial testSoftSerial = SoftwareSerial(RX,TX);     // The SoftwareSerial Object

SerialCommand SCmd(testSoftSerial);   // The demo SerialCommand object, using the SoftwareSerial Constructor

void setup()
{  
  pinMode(arduinoLED,OUTPUT);      // Configure the onboard LED for output
  digitalWrite(arduinoLED,LOW);    // default to LED off

  Serial.begin(9600); 
  testSoftSerial.begin(9600); 

  // Setup callbacks for SerialCommand commands 
  SCmd.addCommand("ON",LED_on);       // Turns LED on
  SCmd.addCommand("OFF",LED_off);        // Turns LED off
  SCmd.addCommand("HELLO",SayHello);     // Echos the string argument back
  SCmd.addCommand("P",process_command);  // Converts two arguments to integers and echos them back 
  SCmd.addDefaultHandler(unrecognized);  // Handler for command that isn't matched  (says "What?") 
  Serial.println("Ready"); 
  testSoftSerial.println("SoftSerial Port Ready"); 
  testSoftSerial.println("Command Output will also echo to Hardware Serial Port"); 
}

void loop()
{  
  SCmd.readSerial();     // We don't do much, just process serial commands
}


void LED_on()
{
  Serial.println("LED on"); 
  testSoftSerial.println("(softserial) LED on"); 
  digitalWrite(arduinoLED,HIGH);  
}

void LED_off()
{
  Serial.println("LED off"); 
  testSoftSerial.println("(softserial) LED off"); 

  digitalWrite(arduinoLED,LOW);
}

void SayHello()
{
  char *arg;  
  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.print("Hello "); 
    Serial.println(arg); 
    
    testSoftSerial.print("(softserial) Hello "); 
    testSoftSerial.println(arg); 
  } 
  else {
    Serial.println("Hello, whoever you are"); 
    testSoftSerial.println("(softserial) Hello, whoever you are"); 
  }
}


void process_command()    
{
  int aNumber;  
  char *arg; 

  Serial.println("We're in process_command"); 
  testSoftSerial.println("(softserial) We're in process_command"); 
  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: "); 
    Serial.println(aNumber); 
    
    testSoftSerial.print("(softserial) First argument was: "); 
    testSoftSerial.println(aNumber); 
  } 
  else {
    Serial.println("No arguments"); 
    testSoftSerial.println("(softserial) No Arguments"); 
  }

  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    aNumber=atol(arg); 
    Serial.print("Second argument was: "); 
    Serial.println(aNumber); 
    
    testSoftSerial.print("(softserial) Second argument was: "); 
    testSoftSerial.println(aNumber); 
  } 
  else {
    Serial.println("No second argument"); 
    testSoftSerial.println("No second argument"); 

  }

}

// This gets set as the default handler, and gets called when no other command matches. 
void unrecognized()
{
  Serial.println("What?"); 
  testSoftSerial.println("(softserial) What?"); 
}

