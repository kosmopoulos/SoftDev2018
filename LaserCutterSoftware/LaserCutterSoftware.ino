////////////////////////////////////////////////////////////////////
#include <EEPROM.h>
int savedAddress;

//Initiates laser pin
int ledPin =  13;
//Joystick variables for each direction
int buttonLeft, buttonRight, buttonUp, buttonDown = 0;
//Joystick variables used to set the initial state as off
int buttonState = 0;
int buttonState2 = 0;  
int buttonState3 = 0;  
int buttonState4 = 0;  


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
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
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
}

void loop() {
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
//////////////////////////////////////////////////////////////////////Joystick movement
Serial.println("Joystick mode, use the joystick to control the laser");
//Checks if the selected option was joystick movement
if (menuItem == 3){
  while(proceed == 0) {
    //Reads the input of the joystick for each direction
    buttonLeft = digitalRead(A0);
    buttonRight = digitalRead(A1);
    buttonUp = digitalRead(A2);
    buttonDown = digitalRead(A3);
    //Logs the inputs of the joystick to the serial monitor, 0 for no signal and 1 for signal
    Serial.print(buttonLeft);
    Serial.print("     ");
    Serial.print(buttonRight);
    Serial.print("     ");
    Serial.print(buttonUp);
    Serial.print("     ");
    Serial.println(buttonDown);
    //Checks to see if there is an input, and then moves laser in according direction
    if(buttonRight) {movePos(100,0);}
    if(buttonLeft) {movePos(-100,0);}
    if(buttonUp) {movePos(0,100);}
    if(buttonDown) {movePos(0,-100);}
    if(buttonUp && buttonRight) {movePos(100,100);}
    if(buttonUp && buttonLeft) {movePos(-100,100);}
    if(buttonDown && buttonRight) {movePos(100,-100);}
    if(buttonDown && buttonLeft) {movePos(-100,-100);}
  }
}
/////////////////////////////////////////////////////EEPROM saving and reading
if (menuItem == 2){
  while(proceed == 0) {
    Serial.println("Coord saving and reading screen, choose if you want to save or read");
        
  }
}
/////////////////////////////////////////////////////Demo code
if (menuItem == 1){
  while(proceed == 0) {
    Serial.println("Welcome to demo mode! The system will demo the laser engraving ability");
    Serial.println("Press x to go back");
    delay(100);
    //Square demo
    moveCoord(20,0);
    moveCoord(0,20);
    moveCoord(-20,0);
    moveCoord(0,-20);
    //Triangle demo
    moveCoord(26,0);
    moveCoord(-13,26);
    moveCoord(-13,-26); 
  }

}
  Serial.println("we proceeded");



  while(1) {}
}
