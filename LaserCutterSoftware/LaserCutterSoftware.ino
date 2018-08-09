//Sets pins 2,3,4,5 for motor A
int motorPinA1 = 2;
int motorPinA2 = 3;
int motorPinA3 = 4;
int motorPinA4 = 5;
//Sets pins 6,7,8,9 for motor B
int motorPinB1 = 6;
int motorPinB2 = 7;
int motorPinB3 = 8;
int motorPinB4 = 9;
//Sets initial value of step count for both motors to 0
int stepA, stepB = 0;
//Sets the speed of the stepper motors
int motorSpeed = 10000;
//Initialises the motor to select, how many steps of the motor and the direction
int motorSelect, steps, motorDirection;
//Initialises the function to allow for the motor to move and its inputs
void motorMove(int motorSelect, int steps, int motorDirection);
int j;

//Defines the function to move the motors
void motorMove(int motorSelect, int steps, int motorDirection) {
  //Checks direction of motor movement
  if(motorDirection >= 1) {
    // for loop for how many steps
    for(int j; j < steps; j++) {
      //Case statements to cycle through phases of a single step in the x motor
      switch (stepA) {
          case 0:
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          stepA ++;
          break;
          
          case 1:
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          stepA ++;
          break;    
              
          case 2:
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          stepA ++;
          break;  
               
          case 3:
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          stepA = 0;
          break;
          }
      delayMicroseconds(motorSpeed);  
      //Case statements to cyle through phases on single step for y motor    
      switch (stepB) {
          case 0:
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          stepB ++;
          break;

          case 1:
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          stepB ++;
          break;

          case 2:
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          stepB ++;
          break;

          case 3:
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          stepB = 0;
          break;
          }
    }
  }
  else if(motorDirection <= -1) {
    // for loop for how many steps
    for(int j; j < steps; j++) {
      //Case statements to cycle through phases of a single step in the motor
      switch (stepA) {
          case 0:
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          stepA ++;
          break;
          
          case 1:
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          stepA ++;
          break;    
              
          case 2:
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          stepA ++;
          break;  
               
          case 3:
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          stepA = 0;
          break;
          }
      switch (stepB) {
          case 0:
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          stepB ++;
          break;

          case 1:
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          stepB ++;
          break;

          case 2:
          digitalWrite(6, LOW);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          stepB ++;
          break;

          case 3:
          digitalWrite(6, HIGH);
          digitalWrite(7, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(9, LOW);
          stepB = 0;
          break;
          }
    }
  }
}

void setup() {
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


}

void loop() {
  
}
