////////////////////////////////////////////////////////////////////
//Sets pins 2,3,4,5 for motor A
int dirX;
int dirY;
//Sets pin for laser
int laserPin = 11;
////////////////////////////////////////////////////////////////////
//Initialises step value in each direction
int stepY; int stepX;

//Sets values of change in position
int deltaX; int deltaY;

//Sets the speed of the stepper motors
int motorSpeed = 100000;

//Initialises the brightness of the laser
double laserBrightness;
////////////////////////////////////////////////////////////////////
//Initialises the function to allow for the motor to move and its inputs
void movePos(int deltaX, int deltaY);

//Initialises the function to operate the laser
void laserEngrave(double laserBrightness);
////////////////////////////////////////////////////////////////////


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
  //Sets the laser pin as an output
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 laserEngrave(100);
 movePos(1,1);
}
