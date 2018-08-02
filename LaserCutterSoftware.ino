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
float gradient;

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

}


void movePos(float posX, float posY) {
  //gradient


  //check to see if pos or neg input, then adjust accordingly
  if (posX >= 0)
  {
    digitalWrite(dirPinX, HIGH);
  }
  else {
    digitalWrite(dirPinX, LOW);
    posX = -1 * posX;
  }

  if (posY >= 0)
  {
    digitalWrite(dirPinY, HIGH);
  }
  else {
    digitalWrite(dirPinY, LOW);
    posY = -1 * posY;
  }

  //posMapX = map(posX,0,61.5,0,49150);
  posMapX = map(posX, 0, 50, 0, 50000);
  Serial.print("posX is   "); Serial.println(posX);
  Serial.print("posMapX is   "); Serial.println(posMapX);

  //posMapY = map(posY,0,50,0,41200);
  posMapY = map(posY, 0, 50, 0, 50000);

  Serial.print("posY is   "); Serial.println(posY);
  Serial.print("posMapY is   "); Serial.println(posMapY);


//find dominant axes
if(posX > posY)
{
  float majorAxis = posMapX;
  float minorAxis = posMapY;
  Serial.print("X is the major axis");
}
else if (posX < posY){
  float majorAxis = posMapY;
  float minorAxis = posMapX;
  Serial.print("Y is the major axis");
}
else {
  int majorAxis = 0;
  int minorAxis = 0;
  Serial.print("No dominant axis");
}

if(majorAxis == 0){
  gradient = 1;
  Serial.println("we set it to 1");
}
else {
  gradient = majorAxis/minorAxis;
  Serial.println("we set it to ratio");
}
float p = 40/7;
Serial.println(p,4);
gradient = majorAxis*10000/minorAxis*10000;

  Serial.print("gradient is   "); Serial.println(gradient);

  for (float i = 0; i <= posMapY; i++)
  {



    //do it according to gradient
    int count = 0;
    for (float x = 0; x < 10 * gradient; x++) { //3000 changes distance
      count++;
      if (count == 10)
      {
        digitalWrite(stepPinX, HIGH);
        delayMicroseconds(50); //changes speed
        digitalWrite(stepPinX, LOW);
        delayMicroseconds(50);
        count = 0;
      }

    }

    //do it once
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(50); //changes speed
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(50);




  }
}

void loop() {
  // put your main code here, to run repeatedly:
  movePos(50, 5);
  while (1) {}

}

