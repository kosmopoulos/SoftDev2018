////////////////////////////////////////////////////////////////////
#include <EEPROM.h>
int savedAddress;

//Initiates laser pin
int ledPin =  13;
//Joystick variables for each direction
int joystickLeft, joystickRight, joystickUp, joystickDown = 0;
//Joystick variables used to set the initial state as off
int joystickState = 0;
int joystickState2 = 0;  
int joystickState3 = 0;  
int joystickState4 = 0;  

//Creates variables for menu use
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
void laserEngrave();

//Initialises function to turn laser off
void laserOff();
void laserOn();
int laserPin = 11;
//Initialises the function to move to a specific position
void moveCoord(float posX, float posY);

//Initialises the funtion which reads a saved value
void readCoord();
//Initialises the function which saves a read value
void saveCoord();
////////////////////////////////////////////////////////////////////


void setup() {
  pinMode(ledPin, OUTPUT);
  // initialize the joystick switches as inputs:
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
  Serial.println("LASER ENGRAVER");
  Serial.println("Welcome, what would you like to do?");
  Serial.println("Enter 1 for demo mode, 2 for Saving and reading or 3 for joystick control");
  
  ////////////////////////////////////////////////////////////////////
  while(proceed == 0) {
    if (Serial.available()) {
      incomingSerial = Serial.read();
      menuItem = 0;
      if(menuItem == 0) {
        switch(incomingSerial) {
          default: Serial.println("Please ensure that you choose either 1, 2 or 3. I promise that there aren't any hidden options");
          break;
          //Switches to demo mode
          case 49:
          Serial.println("number 1 was received");
          proceed = 1;
          menuItem = 1;  
          break;
          //Switches to save/read mode
          case 50:
          Serial.println("number 2 was received");
          proceed = 1;
          menuItem = 2;
          break;
          //Switches to joystick movement mode
          case 51:
          Serial.println("number 3 was received");
          proceed = 1;
          menuItem = 3;
          break;
        }
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
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        //Logs the inputs of the joystick to the serial monitor, 0 for no signal and 1 for signal
        Serial.print(joystickLeft);
        Serial.print("     ");
        Serial.print(joystickRight);
        Serial.print("     ");
        Serial.print(joystickUp);
        Serial.print("     ");
        Serial.println(joystickDown);
        //Checks to see if there is an input, and then moves laser in according direction
        if(joystickRight && !joystickLeft && !joystickUp && !joystickDown) {movePos(100,0); digitalWrite(11, HIGH);}
        if(joystickLeft && !joystickRight && !joystickDown && !joystickUp) {movePos(-100,0); digitalWrite(11, HIGH);}
        if(joystickUp && !joystickRight && !joystickDown && !joystickLeft) {movePos(0,100); digitalWrite(11, HIGH);}
        if(joystickDown && !joystickUp && !joystickRight && !joystickLeft) {movePos(0,-100); digitalWrite(11, HIGH);}
        if(joystickUp && joystickRight && !joystickDown && !joystickLeft) {moveCoord(10,10); digitalWrite(11, HIGH);}
        if(joystickUp && joystickLeft && !joystickDown && !joystickRight) {moveCoord(-10,10); digitalWrite(11, HIGH);}
        if(joystickDown && joystickRight && !joystickUp && !joystickLeft) {moveCoord(10,-10); digitalWrite(11, HIGH);}
        if(joystickDown && joystickLeft && !joystickUp && !joystickRight) {moveCoord(-10,-10); digitalWrite(11, HIGH);}
        //Lowers laser intensity if no movement of axis
        if(!joystickDown && !joystickLeft && !joystickUp && !joystickRight) {digitalWrite(11, LOW);}
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
        Serial.println("Enter x to go back");
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        //Square demo
        moveCoord(20,0);
        moveCoord(0,20);
        moveCoord(-20,0);
        moveCoord(0,-20);
        delayMicroseconds(100);
        //Triangle demo
        moveCoord(26,0);
        moveCoord(-13,26);
        moveCoord(-13,-26); 
        digitalWrite(11, LOW);
        if(incomingSerial == 120) {proceed = 0;}
      }
    
    }
    while(1) {}
}
