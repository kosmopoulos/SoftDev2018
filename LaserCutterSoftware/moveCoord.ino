void moveCoord(float posX, float posY) {
  //Calculates gradient
  m = posY/posX;
  //Maps out actual length to steps
  float posMapX = map(posX, 0, 61, 0, 3060);
  float posMapY = map(posY, 0, 51, 0, 2487);
  Serial.println(m,4);
  gradientY = posMapY*m;
  //Checks direction of motor movement
  if(posX>=0) {dirX = 0;} else {dirX = 1;}
  if(posY>=0) {dirY = 0;} else {dirY = 1;}
  
  for (int j = 0; j < abs(gradientY); j++) {
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
  delayMicroseconds(motorSpeed);
  }

  for (int j = 0; j < abs(posMapX); j++) {
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
  }
}

