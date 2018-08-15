//Defines the function to move the motors
void movePos(int deltaX, int deltaY) {
  //Prints the change in position
  //Serial.println(deltaX);
  //Serial.println(deltaY);
  //Checks direction of motor movement
  if(deltaX>=0) {dirX = 0;} else {dirX = 1;}
  if(deltaY>=0) {dirY = 0;} else {dirY = 1;}
  //Prints the directions
  //Serial.println(dirX);
  //Serial.println(dirY);
  for (int jy = 0; jy < abs(deltaY); jy++) {
    //Case statements to cycle through phases of a single step in the y motor 
    switch (stepY) {
        //Setting default in case of unknown value
        default:
            stepY = 0;
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            if(dirY){stepY++;} else {stepY = 3;}
            break;
         
        case 0:
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            if(dirY){stepY++;} else {stepY = 3;}
            break;

        case 1:
            digitalWrite(2, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            if(dirY){stepY++;} else {stepY = 0;}
            break;
            
        case 2:
            digitalWrite(2, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            if(dirY){stepY++;} else {stepY = 1;}
            break;

        case 3:
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            if(dirY){stepY++;} else {stepY = 2;}
            break;
    }
    //Delays for smoother movement
    countY++;
    delayMicroseconds(motorSpeed);
  }

  for (int jx = 0; jx < abs(deltaX); jx++) {
    //Case statements for one phase of movement for the y motor
    switch (stepX) {
        //Setting default in case of unknown value
        default:
            stepX = 0;
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            if(dirX){stepX++;} else {stepX = 3;}
            break;
            
        case 0:
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            if(dirX){stepX++;} else {stepX = 3;}
            break;

        case 1:
            digitalWrite(6, LOW);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            if(dirX){stepX++;} else {stepX = 0;}
            break;

        case 2:
            digitalWrite(6, LOW);
            digitalWrite(7, HIGH);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            if(dirX){stepX++;} else {stepX = 1;}
            break;

        case 3:
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            if(dirX){stepX++;} else {stepX = 2;}
            break;
    }
    //Delays for smoother movement
    delayMicroseconds(motorSpeed);
    countX++;
  }

  
}
