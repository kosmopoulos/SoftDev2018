////////////////////////////////////////////////////////////////////
//Sets direction for x and y
int dirX;
int dirY;
//error/steps lost checking
int countX, countY = 0;
//Sets pin for laser
int laserPin = 11;
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
float posMapX;
float posMapY;

////////////////////////////////////////////////////////////////////
//Initialises the function to allow for the motor to move and its inputs
void movePos(int deltaX, int deltaY);

//Initialises the function to operate the laser
void laserEngrave(double laserBrightness);

//Initialises function to turn laser off
void laserOff();
//Initialises the function to move to a specific position
void moveCoord(float posX, float posY);

//Initialises the funtion which returns the laser pivot to the start position
void returnStart();
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
 moveCoord(-10,10);
 moveCoord(10,-10);
 moveCoord(10,0);
 laserOff();
 while(1) {}
}
