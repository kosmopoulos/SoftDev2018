////////////////////////////////////////////////////////////////////


int incomingSerial = 0;
int proceed = 0;
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
 pinMode(11, OUTPUT);
  //Sets the laser pin as an output
  //pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {


//digitalWrite(11, HIGH);
//moveCoord(-20,-20);
digitalWrite(11, HIGH);
//moveCoord(-11,-5);
//moveCoord(11,5);



Serial.println("welcome to the program");
Serial.println("what would you like to do?");
Serial.println("enter 1 for this, 2 for that, or 3 for random inputs");

//////////////////////////////////////////////////////////////////////
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

  break;
  case 50:
  //go to two situation
  Serial.print("number 2 was received");
 proceed = 1;
  break;
  case 51:
  //go to random movement mode
  Serial.print("number 3 was received");
 proceed = 1;
  break;
}
}


}
proceed = 0;
//////////////////////////////////////////////////////////////////////
Serial.println("okay, enter what direction youu want to move it");
while(proceed == 0)
{
if (Serial.available()) {
incomingSerial = Serial.read();

  Serial.println("please make sure you enter a number");
  
}


}







  Serial.println("we proceeded");

if(incomingSerial == 119)
{
  
  moveCoord(0,1);
}


if(incomingSerial == 97)
{
  moveCoord(-1,0);
}

if(incomingSerial == 100)
{
  moveCoord(1,0);
}
if(incomingSerial == 115)
{
  moveCoord(0,-1);
}


//Serial.println("turn laser off");
//digitalWrite(11, LOW);


 //digitalWrite(11, LOW);

  //laserOff();

  //while(1) {}
}
