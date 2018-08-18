void moveCoord(float posX, float posY) {
  //Maps out actual length to steps by stretching them according to mapping calculation
  float posMapX = map(posX, 0, 61, 0, 3175);
  float posMapY = map(posY, 0, 51, 0, 2500);
  //Calculates gradient and rounds it up if decimal value

  //Logs Mapped values for x and y
  Serial.print("posMapX:  ");
  Serial.println(posMapX,4);
  Serial.print("posMapY:  ");
  Serial.println(posMapY,4);

  

///////////////////////////////////////////
//if both are greater than zero
if (posMapX > 0 && posMapY > 0){
  if (posMapX > posMapY) {
    // run code for when both positive and x is greater than y
      Serial.println("x was greater than y");
    m = posMapX/posMapY;
      //Logs gradient and rounded value
  Serial.print("the gradient is:  ");
    Serial.println(m,4);
    int mCeil = ceil(m);
    Serial.print("rounded up m:  ");
    Serial.println(mCeil);
    //Logs amount of steps lost in given direction
    Serial.println(posMapY/(mCeil*posMapY-m*posMapY));
    //Creates a counter used for step compensation
    int internalCountY = 0;
      //Loop to move to position
      while (countY < posMapY) {
        movePos(mCeil,1);
        internalCountY++;
        //When the count is equal to the lost steps, move in order to compensate for the loss
        if(internalCountY == posMapY/(mCeil*posMapY-m*posMapY)) {
          movePos(0,1);
          internalCountY = 0;
        } 
    
      } 
    if(countX < posMapX){movePos((posMapX-countX),0);}
      Serial.println(countX);
      Serial.println(countY);
    
  }
  else {
    
    Serial.println("x was less than y");
    m = posMapY/posMapX;
    Serial.println(m,4);
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
 
}

//if both are less than zero
if (posMapX < 0 && posMapY < 0){
  if (abs(posMapX) > abs(posMapY)) {
    // run code for when both are negative but mag x is greater than mag y
  }
  else {
    // run code for when both are negative but mag y is greater than mag x
  }
 
}

//if only x is positive
else if (posMapX > 0 && posMapY < 0){
  if (abs(posMapX) > abs(posMapY)) {
    // run code for when only x is positive and mag is greater than y
  }
  else {
    // run code for when only x is positive but mag less than y
  }
 
}

//if only y is positive
else if (posMapX < 0 && posMapY > 0){
  if (abs(posMapX) > abs(posMapY)) {
    // run code for when only y is positive and mag x is greater than y
  }
  else {
    // run code for when only y is positive but mag y greater than x
  }
 
}
//if only y is positive
else if (posMapX < 0 && posMapY > 0){
 
}

///////////////////////////////////////////

 
 
//if x is zero and y is not zero
else if (!posMapX &&posMapY){
  
}
//if x is not zero and y is zero
else if (posMapX &&!posMapY){
  
}

 //if they are both zero
else if(!posMapX && !posMapY) {Serial.println("you done fuucked up aaron, booth inpuuts where zero. dickhead");}





  


   
}

