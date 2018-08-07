int motorA_pin_1 = 2;
int motorA_pin_2 = 3;
int motorA_pin_3 = 4;
int motorA_pin_4 = 5;

int motorB_pin_1 = 6;
int motorB_pin_2 = 7;
int motorB_pin_3 = 8;
int motorB_pin_4 = 9;

int motorSpeed = 10000;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(motorA_pin_1, OUTPUT);
  pinMode(motorA_pin_2, OUTPUT);
  pinMode(motorA_pin_3, OUTPUT);
  pinMode(motorA_pin_4, OUTPUT);

  pinMode(motorB_pin_1, OUTPUT);
  pinMode(motorB_pin_2, OUTPUT);
  pinMode(motorB_pin_3, OUTPUT);
  pinMode(motorB_pin_4, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
delayMicroseconds(motorSpeed);
        digitalWrite(motorA_pin_1, HIGH);
        digitalWrite(motorA_pin_2, LOW);
        digitalWrite(motorA_pin_3, HIGH);
        digitalWrite(motorA_pin_4, LOW);
        
delayMicroseconds(motorSpeed);
        digitalWrite(motorA_pin_1, LOW);
        digitalWrite(motorA_pin_2, HIGH);
        digitalWrite(motorA_pin_3, HIGH);
        digitalWrite(motorA_pin_4, LOW);
delayMicroseconds(motorSpeed);
        digitalWrite(motorA_pin_1, LOW);
        digitalWrite(motorA_pin_2, HIGH);
        digitalWrite(motorA_pin_3, LOW);
        digitalWrite(motorA_pin_4, HIGH);
delayMicroseconds(motorSpeed);
        digitalWrite(motorA_pin_1, HIGH);
        digitalWrite(motorA_pin_2, LOW);
        digitalWrite(motorA_pin_3, LOW);
        digitalWrite(motorA_pin_4, HIGH);

        delayMicroseconds(motorSpeed);
        digitalWrite(motorB_pin_1, HIGH);
        digitalWrite(motorB_pin_2, LOW);
        digitalWrite(motorB_pin_3, HIGH);
        digitalWrite(motorB_pin_4, LOW);
        
delayMicroseconds(motorSpeed);
        digitalWrite(motorB_pin_1, LOW);
        digitalWrite(motorB_pin_2, HIGH);
        digitalWrite(motorB_pin_3, HIGH);
        digitalWrite(motorB_pin_4, LOW);
delayMicroseconds(motorSpeed);
        digitalWrite(motorB_pin_1, LOW);
        digitalWrite(motorB_pin_2, HIGH);
        digitalWrite(motorB_pin_3, LOW);
        digitalWrite(motorB_pin_4, HIGH);
delayMicroseconds(motorSpeed);
        digitalWrite(motorB_pin_1, HIGH);
        digitalWrite(motorB_pin_2, LOW);
        digitalWrite(motorB_pin_3, LOW);
        digitalWrite(motorB_pin_4, HIGH);
     
  
}
