void moveCoord(float posX, float posY) {
  //Maps out actual length to steps by stretching them according to mapping calculation
  float posMapX = map(posX, 0, 61, 0, 3060);
  float posMapY = map(posY, 0, 51, 0, 2487);
  //Calculates gradient and rounds it up if decimal value
  m = posMapY/posMapX;
  //Logs Mapped values for x and y
  Serial.print("posMapX:  ");
  Serial.println(posMapX,4);
  Serial.print("posMapY:  ");
  Serial.println(posMapY,4);
  //Logs gradient and rounded value
  Serial.print("the gradient is:  ");
  Serial.println(m,4);

  

  if(posX < posY) {
    int mCeil = ceil(m);
    Serial.print("rounded up m:  ");
    Serial.println(mCeil);
    //Logs amount of steps lost in given direction
    Serial.println(posMapX/(mCeil*posMapX-m*posMapX));
    //Creates a counter used for step compensation
    int internalCountX = 0;
      //Loop to move to position
      while (countX < posMapX) {
        movePos(1,mCeil);
        internalCountX++;
        //When the count is equal to the lost steps, move in order to compensate for the loss
        if(internalCountX == posMapX/(mCeil*posMapX-m*posMapX)) {
          movePos(1,0);
          internalCountX = 0;
        } 
    
      } 
    if(countY < posMapY){movePos(0,(posMapY-countY));}
      Serial.println(countX);
      Serial.println(countY);
    
  }

  else if(posY < posX) {
    int mFloor = floor(m);
    Serial.print("rounded down m:  ");
    Serial.println(mFloor);
    //Logs amount of steps lost in given direction
    Serial.println(posMapY/(mFloor*posMapY-m*posMapY));
    //Creates a counter used for step compensation
    int internalCountY = 0;
      //Loop to move to position
      while (countY < posMapY) {
        movePos(mFloor,1);
        internalCountY++;
        //When the count is equal to the lost steps, move in order to compensate for the loss
        if(internalCountY == posMapY/(mFloor*posMapY-m*posMapY)) {
          movePos(0,1);
          internalCountY = 0;
        } 
    
      } 
    if(countX < posMapX){movePos(0,(posMapX-countX));}
      Serial.println(countX);
      Serial.println(countY);
  }
   
}

