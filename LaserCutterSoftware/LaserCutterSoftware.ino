//////////////////////////////////////////////////////////////////// Declerations of variables and functions

//Initiates laser pin
int ledPin =  13;

//Joystick variables for each direction
int joystickLeft, joystickRight, joystickUp, joystickDown = 0;

//Joystick variables used to set the initial state as off
int joystickState1, joystickState12, joystickState13, joystickState14 = 0;

//Creates variables for menu use, incomingSerial for reading input and proceed/menuItem for changing options
int incomingSerial = 0;
int proceed = 0;
int menuItem = 0;

//Sets direction for x axis and y axis
int dirX;
int dirY;

//Initialises vale for error/steps lost checking when ceiling the gradient
int countX, countY = 0;

//Initialises step value in each direction
int stepY; int stepX;

//Sets values for the change in position
int deltaX; int deltaY;

//Sets the default speed of the stepper motors
int motorSpeed = 100000;

//Initialises the position of the x and y axis and how much it has to travel in cm
float posX; float posY;

//Initialises variables used when calculating gradient
float m;
float gradientY;

//Initialises the function to allow for the motor to move in steps
void movePos(int deltaX, int deltaY);

//Initialises the function to move a specific amount in cm
void moveCoord(float posX, float posY);

//////////////////////////////////////////////////////////////////// Setup for inputs and outputs of system, inputs being signals recieved and outputs being signals sent

void setup() {
  //Initialises the laser pin as an output to produce beam
  pinMode(ledPin, OUTPUT);
  //Initialises the joystick switches as inputs:
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
  //Begins the serial monitor for the UI
  Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////// Code to run the system

void loop() {
  //Prints options to UI
  Serial.println("LASER ENGRAVER");
  Serial.println("Welcome, what would you like to do?");
  Serial.println("Enter 1 for demo mode or 2 for joystick control");
  //While statement to check the option chosen for the system
  while(proceed == 0) {
    //Checks to see if the serial box (UI) is avaliable for input, then sets it to read the input
    if (Serial.available()) {
      incomingSerial = Serial.read();
      //Sets the initial menu to be option checking
      menuItem = 0;
      if(menuItem == 0) {
        //Case statements to check which option is selected and a log to the UI if something else was inputted
        switch(incomingSerial) {
          default: Serial.println("Please ensure that you choose either 1, 2 or 3. I promise that there aren't any hidden options");
          break;
          //Switches to demo mode
          case 49:
          Serial.println("number 1 was received");
          proceed = 1;
          menuItem = 1;  
          break;
          //Switches to joystick movement mode
          case 50:
          Serial.println("number 3 was received");
          proceed = 1;
          menuItem = 2;
          break;
        }
      }  
    }
  }
  proceed = 0;
//////////////////////////////////////////////////////////////////// Joystick movement
    Serial.println("Joystick mode, use the joystick to control the laser");
    //Checks if the selected option was joystick movement
    if (menuItem == 2){
      Serial.println("please select the motor speed you would like. Choose L for low, M for medium and H for high speed!");     
      while(!Serial.available()){}
      //Uses variable to check the input of the user from the UI, then changes motor speed accordingly
      int motorSpeedIn = Serial.read();
      if(motorSpeedIn == 108){motorSpeed = 75000;}
      if(motorSpeedIn == 109){motorSpeed = 100000;}
      if(motorSpeedIn == 104){motorSpeed = 150000;}
      while(proceed == 0) {    
        //Reads the input of the joystick for each direction
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        //Logs the inputs of the joystick to the serial monitor, 0 for no signal and 1 for signal
        //Commented out to make the UI look cleaner, but used for error checking of input if needed
        //Serial.print(joystickLeft);
        //Serial.print("     ");
        //Serial.print(joystickRight);
        //Serial.print("     ");
        //Serial.print(joystickUp);
        //Serial.print("     ");
        //Serial.println(joystickDown);
        
        //Checks to see if there is an input, and then moves laser in according direction using steps or coordinates appropriately
        //To move right
        while(joystickRight && !joystickLeft && !joystickUp && !joystickDown) {
        digitalWrite(11, HIGH); 
        movePos(10,0);
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move left
        if(joystickLeft && !joystickRight && !joystickDown && !joystickUp) { 
        digitalWrite(11, HIGH); 
        movePos(-10,0);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move up
        while(joystickUp && !joystickRight && !joystickDown && !joystickLeft) { 
        digitalWrite(11, HIGH);movePos(0,10);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move down
        while(joystickDown && !joystickUp && !joystickRight && !joystickLeft) {
        digitalWrite(11, HIGH);
        movePos(0,-10);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move up and right simultaneously
        while(joystickUp && joystickRight && !joystickDown && !joystickLeft) { 
        digitalWrite(11, HIGH);
        moveCoord(1,1);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move up and left simultaneously
        while(joystickUp && joystickLeft && !joystickDown && !joystickRight) { 
        digitalWrite(11, HIGH);
        moveCoord(-1,1);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move down and right simultaneously
        while(joystickDown && joystickRight && !joystickUp && !joystickLeft) { 
        digitalWrite(11, HIGH);
        moveCoord(1,-1);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
        //To move down and left simultaneously
        while(joystickDown && joystickLeft && !joystickUp && !joystickRight) {
        digitalWrite(11, HIGH);
        moveCoord(-1,-1);        
        joystickLeft = digitalRead(A0);
        joystickRight = digitalRead(A1);
        joystickUp = digitalRead(A2);
        joystickDown = digitalRead(A3);
        digitalWrite(11, LOW);
        }
      }
    }
////////////////////////////////////////////////////////////////////Demo code
    //Checks to see if selected option was demo mode
    if (menuItem == 1){
      while(proceed == 0) {
        Serial.println("Welcome to demo mode! The system will demo the laser engraving ability");
        Serial.println("Press reset to go back");
        delayMicroseconds(100);
        digitalWrite(11, HIGH);
        //Sets speed to move at a reasonable pace to demonstrate power of laser
        motorSpeed = 60000;
        //Demos a square
        moveCoord(40,0);
        moveCoord(0,40);
        moveCoord(-40,0);
        moveCoord(0,-40);     
      }   
    }
    //Ensures that nothing unneccesary is looped
    while(1) {}
}
