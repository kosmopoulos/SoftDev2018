void moveCoord(float posX, float posY) {
  Serial.println("///////////////NEW COORD MOVEMENT////////////////");
   countX, countY = 0;
  
  //Maps out actual length to steps by stretching them according to mapping calculation
  float posMapX = map(posX, 0, 200, 0, 3175);
  float posMapY = map(posY, 0, 200, 0, 2500);
  //Calculates gradient and rounds it up if decimal value

  //Logs Mapped values for x and y
  Serial.print("posMapX:  ");
  Serial.println(posMapX,4);
  Serial.print("posMapY:  ");
  Serial.println(posMapY,4);

///////////////////////////////////////////
  //if both are greater than zero
  if (posMapX > 0 && posMapY > 0){
    Serial.println("both are greater than zero");
    if (posMapX > posMapY) {
        //run code for when both positive and x is greater than y
        Serial.println("x was greater than y");
        m = posMapX/posMapY;
        //Logs gradient and rounded value
        Serial.print("the gradient is:  ");
        Serial.println(m,4);
      
        int mCeil = ceil(m);
        if(abs(m) ==1) {mCeil = m;}
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
      if(abs(m) ==1) {mCeil = m;}
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
  else if (posMapX < 0 && posMapY < 0){
    Serial.println("both are less than zero");
    int absY = abs(posMapY);
    int absX = abs(posMapX);
    if (abs(posMapX) > abs(posMapY)) {
      // run code for when both are negative but mag x is greater than mag y
        //run code for when both positive and x is greater than y
        Serial.println("x was greater than y");
        m = absX/absY;
        //Logs gradient and rounded value
        Serial.print("the gradient is:  ");
        Serial.println(m,4);
        int mCeil = ceil(m);
        if(abs(m) ==1) {mCeil = m;}
        Serial.print("rounded up m:  ");
        Serial.println(mCeil);
        //Logs amount of steps lost in given direction
        Serial.println("sdfsfsdf");
        Serial.println(absY/(mCeil*absY-m*absY));
        //Creates a counter used for step compensation
        int internalCountY = 0;
        //Loop to move to position
        while (countY < absY) {
          movePos(-mCeil,-1);
          internalCountY++;
          //When the count is equal to the lost steps, move in order to compensate for the loss
          if(absY/(mCeil*absY-m*absY)==0){}
          else{
           movePos(0,-1);
            internalCountY = 0;}
          if(internalCountY == absY/(mCeil*absY-m*absY)) {
           
          }       
        } 
        if(countX < posMapX){movePos((absX-countX),0);}
        
          Serial.print("final count X is:");
          Serial.println(countX);
          Serial.print("final count Y is:");
          Serial.println(countY);
    }
    else {
      // run code for when both are negative but mag y is greater than mag x
      Serial.println("x was less than y");
      m = absY/absX;
      Serial.println(m,4);
      int mCeil = ceil(m);
      if(abs(m) ==1) {mCeil = m;}
      Serial.print("rounded up m:  ");
      Serial.println(mCeil);
      //Logs amount of steps lost in given direction
      Serial.println(absX/(mCeil*absX-m*absX));
      //Creates a counter used for step compensation
      int internalCountX = 0;
        //Loop to move to position
        while (countX < absX) {
          movePos(-1,-mCeil);
          internalCountX++;
          //When the count is equal to the lost steps, move in order to compensate for the loss
          if(internalCountX == absX/(mCeil*absX-m*absX)) {
            movePos(-1,0);
            internalCountX = 0;
          }  
        } 
      if(countY < posMapY){movePos(0,(absY-countY));}
        Serial.println(countX);
        Serial.println(countY);     
    }        
    }
  
  //if only x is positive
  else if (posMapX > 0 && posMapY < 0){
    Serial.println("only x was positive");
    int absY = abs(posMapY);
    int absX = abs(posMapX);
      // run code for when only x is positive and mag is greater than y
    if (abs(posMapX) > abs(posMapY)) {
        Serial.println("x was greater than y");
        m = absX/absY;
        //Logs gradient and rounded value
        Serial.print("the gradient is:  ");
        Serial.println(m);
        int mCeil = ceil(m);
        if(abs(m) ==1) {mCeil = m;}
        Serial.print("rounded up m:  ");
        Serial.println(mCeil);
        //Logs amount of steps lost in given direction
        Serial.println(absY/(mCeil*absY-m*absY));
        //Creates a counter used for step compensation
        int internalCountY = 0;
        //Loop to move to position
        while (countY < absY) {
          movePos(mCeil,-1);
          internalCountY++;
          //When the count is equal to the lost steps, move in order to compensate for the loss
          if(internalCountY == absY/(mCeil*absY-m*absY)) {
            movePos(0,-1);
            internalCountY = 0;
          }       
        } 
        if(countX < posMapX){movePos((absX-countX),0);}
          Serial.println(countX);
          Serial.println(countY);       
    }
    else {
      // run code for when only x is positive but mag less than y
      Serial.println("x was less than y");
      m = absY/absX;
      Serial.println(m,4);
      int mCeil = ceil(m);
      if(abs(m) ==1) {mCeil = m;}
      Serial.print("rounded up m:  ");
      Serial.println(mCeil);
      //Logs amount of steps lost in given direction
      Serial.println(absX/(mCeil*absX-m*absX));
      //Creates a counter used for step compensation
      int internalCountX = 0;
        //Loop to move to position
        while (countX < absX) {
          movePos(1,-mCeil);
          internalCountX++;
          //When the count is equal to the lost steps, move in order to compensate for the loss
          if(internalCountX == absX/(mCeil*absX-m*absX)) {
            movePos(1,0);
            internalCountX = 0;
          }  
        } 
      if(countY < posMapY){movePos(0,(absY-countY));}
        Serial.println(countX);
        Serial.println(countY);      
    }  
  }
  
  //if only y is positive
  else if (posMapX < 0 && posMapY > 0){
    Serial.println("only y is positive");
    int absY = abs(posMapY);
    int absX = abs(posMapX);
    if (abs(posMapX) > abs(posMapY)) {
      // run code for when only y is positive and mag x is greater than y
        Serial.println("x was greater than y");
        m = absX/absY;
        //Logs gradient and rounded value
        Serial.print("the gradient is:  ");
        Serial.println(m,4);
        int mCeil = ceil(m);
        if(abs(m) ==1) {mCeil = m;}
        Serial.print("rounded up m:  ");
        Serial.println(mCeil);
        //Logs amount of steps lost in given direction
        Serial.println(absY/(mCeil*absY-m*absY));
        //Creates a counter used for step compensation
        int internalCountY = 0;
        //Loop to move to position
        while (countY < absY) {
          movePos(-mCeil,1);
          internalCountY++;
          //When the count is equal to the lost steps, move in order to compensate for the loss
          if(internalCountY == absY/(mCeil*absY-m*absY)) {
            movePos(0,1);
            internalCountY = 0;
          }       
        } 
        if(countX < posMapX){movePos((absX-countX),0);}
          Serial.println(countX);
          Serial.println(countY);    
    }
    else {
      // run code for when only y is positive but mag y greater than x
      Serial.println("x was less than y");
      m = absY/absX;
      Serial.println(m,4);
      int mCeil = ceil(m);
      if(abs(m) ==1) {mCeil = m;}
      Serial.print("rounded up m:  ");
      Serial.println(mCeil);
      //Logs amount of steps lost in given direction
      Serial.println(absX/(mCeil*absX-m*absX));
      //Creates a counter used for step compensation
      int internalCountX = 0;
        //Loop to move to position
        while (countX < absX) {
          movePos(-1,mCeil);
          internalCountX++;
          //When the count is equal to the lost steps, move in order to compensate for the loss
          if(internalCountX == absX/(mCeil*absX-m*absX)) {
            movePos(-1,0);
            internalCountX = 0;
          }  
        } 
      if(countY < posMapY){movePos(0,(absY-countY));}
        Serial.println(countX);
        Serial.println(countY);       
    }
   
  }
  
///////////////////////////////////////////
   
  //if x is zero and y is not zero
  else if (!posMapX &&posMapY){
    Serial.println("x was zero and y was not zero");
    if(posMapY > 0) {
      
        movePos(0,posMapY);
      
    }
    else if (posMapY < 0) {
      
        movePos(0,posMapY);
      
    }
  }
  //if x is not zero and y is zero
  else if (posMapX &&!posMapY){
    Serial.println("y was zero and x was not zero");

    if(posMapX > 0) {
      
        movePos(posMapX,0);
      
    }
    else if (posMapX < 0) {
      
        movePos(posMapX,0);
      
    }
  }
  
  //if they are both zero
  else if(!posMapX && !posMapY) {Serial.println("both inputs were wrong, check that you have entered a number");}
}

