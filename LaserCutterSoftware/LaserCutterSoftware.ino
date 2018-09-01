////////////////////////////////////////////////////////////////////
#include <EEPROM.h>

int buttonPin1 = 0;     // the number of the pushbutton pin
 int ledPin =  13;      // the number of the LED pin
int buttonPin2 = 1; 
int buttonPin3 = 2; 
int buttonPin4 = 3; 
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;  
int buttonState3 = 0;  
int buttonState4 = 0;  
int savedAddress;

int incomingSerial = 0;
int proceed = 0;
int menuItem = 0;
//Sets direction for x and y
int dirX;
int dirY;
//error/steps lost checking
int countX, countY = 0;
//Sets pin for laser

////////////////////////////////////////////////////////////////////
//Initialises step value in each direction
int stepY; int stepX;

//Sets values of change in position
int deltaX; int deltaY;

//Sets the speed of the stepper motors
//int motorSpeed = 15000;
int motorSpeed = 100000;

//Initialises the brightness of the laser
double laserBrightness;

//Initialises the position of the x and y axis
float posX; float posY;

//Initialises gradient
float m;
float gradientY;
//Initialises the mapping value for x and y to convert from steps to cm
//float posMapX;
//float posMapY;

////////////////////////////////////////////////////////////////////
//Initialises the function to allow for the motor to move and its inputs
void movePos(int deltaX, int deltaY);

//Initialises the function to operate the laser
void laserEngrave(int laserBrightness);

//Initialises function to turn laser off
void laserOff();
void laserOn();
//Initialises the function to move to a specific position
void moveCoord(float posX, float posY);

//Initialises the funtion which reads a saved value
void readCoord();
//Initialises the function which saves a read value
void saveCoord();
////////////////////////////////////////////////////////////////////


void setup() {
   pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
      pinMode(buttonPin3, INPUT);
        pinMode(buttonPin4, INPUT);
  //Sets the pins for motor A to send output signals
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  //Sets the pins for motor B to send output signals
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  //Sets the laser pin as an output
  //pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
  saveCoord();
}

void loop() {
//  Serial.print(analogRead(buttonPin1));
//  Serial.print("        ");
//  Serial.print(analogRead(buttonPin2));
//  Serial.print("        ");
//  Serial.print(analogRead(buttonPin3));
//  Serial.print("        ");
//  Serial.print(analogRead(buttonPin4));
//   Serial.print("        ");
//
//   
//    Serial.print(buttonState);
//  Serial.print("        ");
//  Serial.print(buttonState2);
//  Serial.print("        ");
//  Serial.print(buttonState3);
//  Serial.print("        ");
//  Serial.print(buttonState4);
//   Serial.println("        ");

digitalWrite(11, HIGH);



Serial.println("welcome to the program");
Serial.println("what would you like to do?");
Serial.println("enter 1 for this, 2 for that, or 3 for random inputs");

////////////////////////////////////////////////////////////////////
while(proceed == 0)
{
if (Serial.available()) {
incomingSerial = Serial.read();
switch(incomingSerial)
{
  default: Serial.println("please make sure you enter either 1, 2 or 3");
  break;

  
  case 49:
  //go to one situation
  Serial.print("number 1 was received");
  proceed = 1;
  menuItem = 1;

  break;
  case 50:
  //go to two situation
  Serial.print("number 2 was received");
 proceed = 1;
 menuItem = 2;
  break;
  case 51:
  //go to random movement mode
  Serial.print("number 3 was received");
 proceed = 1;
 menuItem = 3;
  break;
}
}


}
proceed = 0;
//////////////////////////////////////////////////////////////////////
Serial.println("okay, enter what direction youu want to move it");
if (menuItem == 3){
  while(proceed == 0)
{
if(analogRead(buttonPin2) > 1000)
{
  
  movePos(0,100);
}


if(analogRead(buttonPin4) > 1000)
{
  movePos(-100,0);
}

if(analogRead(buttonPin3) > 1000)
{
  movePos(100,0);
}
if(analogRead(buttonPin1) > 1000)
{
  movePos(0,-100);
}

  
}
/////////////////////////////////////////////////////
if (menuItem == 2){
  while(proceed == 0)
{
if(analogRead(buttonPin2) > 1000)
{
  
  movePos(0,100);
}


if(analogRead(buttonPin4) > 1000)
{
  movePos(-100,0);
}

if(analogRead(buttonPin3) > 1000)
{
  movePos(100,0);
}
if(analogRead(buttonPin1) > 1000)
{
  movePos(0,-100);
}

  
}

}
///////////////////////////////////////////////////// do demo
if (menuItem == 1){
  while(proceed == 0)
{
if(analogRead(buttonPin2) > 1000)
{
  
  movePos(0,100);
}


if(analogRead(buttonPin4) > 1000)
{
  movePos(-100,0);
}

if(analogRead(buttonPin3) > 1000)
{
  movePos(100,0);
}
if(analogRead(buttonPin1) > 1000)
{
  movePos(0,-100);
}

  
}

}
  Serial.println("we proceeded");



  while(1) {}
}
