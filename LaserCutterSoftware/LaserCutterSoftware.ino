
////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////
//Sets initial value of steps in each direction
int stepY; int stepX;
//Sets values of change in position
int deltaX; int deltaY;
//Sets the speed of the stepper motors
int motorSpeed = 10000;
//Initialises the function to allow for the motor to move and its inputs
void movePos(int deltaX, int deltaY);
////////////////////////////////////////////////////////////////////

//Defines the function to move the motors
void movePos(int deltaX, int deltaY) {
  //Checks direction of motor movement
  //if(deltaX>0) {int dirX = 1;} else {int dirX = 0;}
  for (int j; j < deltaY; j++) {
    //Case statements to cycle through phases of a single step in the y motor
    switch (stepY) {
        //Setting default in case of unknown value
        default:
            stepY = 0;
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            stepY++;
            break;
         
        case 0:
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            stepY++;
            break;

        case 1:
            digitalWrite(2, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            stepY++;
            break;
            
        case 2:
            digitalWrite(2, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            stepY++;
            break;

        case 3:
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            stepY = 0;
            break;
    }
    //Delays for smoother movement
    delayMicroseconds(motorSpeed);
  }

  for (int j; j < deltaX; j++) {
    //Case statements for one phase of movement for the y motor
    switch (stepX) {
        //Setting default in case of unknown value
        default:
            stepX = 0;
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            stepX++;
            break;
            
        case 0:
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            stepX++;
            break;

        case 1:
            digitalWrite(6, LOW);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            stepX++;
            break;

        case 2:
            digitalWrite(6, LOW);
            digitalWrite(7, HIGH);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            stepX++;
            break;

        case 3:
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            stepX = 0;
            break;
    }
    delayMicroseconds(motorSpeed);
    //Delays for smoother movement
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
  movePos(100, 500);
}
