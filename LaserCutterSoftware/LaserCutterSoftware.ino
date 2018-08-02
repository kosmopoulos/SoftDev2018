// defines pins numbers

//x stepper control pins
const int stepPinX = 2;
const int dirPinX = 5;

//y stepper control pins
const int stepPinY = 3;
const int dirPinY = 6;

// to change home position
float locationX;
float locationY;
float posX = 0.0000;
float posY = 0.0000;
float posMapX;
float posMapY;
float gradient = 0.0000;

float majorAxis;
float minorAxis;
void movePos(float posX, float posY);


void setup() {
  // put your setup code here, to run once:
  pinMode(stepPinX, OUTPUT);
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);

  float posMapX = map(posX, 0, 50, 0, 41200);
  float posMapY = map(posY, 0, 50, 0, 41200);




  //delcare buad rate of serial communication
  Serial.begin(9600);
  Serial.println("setup finished, ready for operation");
  Serial.println("-----------------------------------");

Serial.println(gradient,4);
float major = 42;
float minor = 36;
gradient = major/minor;
Serial.println(gradient,4);


}

void loop() {
  // put your main code here, to run repeatedly:

}


