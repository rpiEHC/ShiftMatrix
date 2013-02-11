#include "cubeplex.h"

void setup () {
  // Begin running the display loops
  initDisplay();
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  //digitalWrite(13,HIGH);
  //drawLed(red,FULL,0,0);
  //flushBuffer();
  animationMax = 60;
}
void loop() {    
  shiftingSquares();
  raindrops();
  circleTest();
  planarSpin();
  bars();
  ripples();
  marqueueText("Welcome to the Smart Lighting Engeneering Research Center");
}

void marqueueText(char* text) {
  int letter = 0;
  int length = 0;
  while(text[length] != 0) length++;

  char* newText = (char*)malloc(sizeof(char)*(length+4));
  
  newText[0] = ' ';
  newText[1] = ' ';
  newText[2] = ' ';
  newText[3] = ' ';
  while(text[letter] != 0){
    newText[letter+4] = text[letter];
    letter++;
  }

  letter = 0;
  text = newText;
  while(text[letter] != 0) {
    for (int i = 0; i < 7; i++) {
      // drawLetter(white, brightness(8), 0-i, 0, letter);
      // drawLetter(white, brightness(8), 6-i, 0, letter+1);
      // drawLetter(white, brightness(8), 12-i, 0, letter+2);
      // drawLetter(white, brightness(8), 18-i, 0, letter+3);
      // drawLetter(white, brightness(8), 24-i, 0, letter+4);

      drawLetter(white, brightness(8), 0-i,  8, text[letter]);
      drawLetter(white, brightness(8), 5-i+2,  8, text[letter+1]);
      drawLetter(white, brightness(8), 10-i+4, 8, text[letter+2]);
      drawLetter(white, brightness(8), 15-i+6, 8, text[letter+3]);
      drawLetter(white, brightness(8), 20-i+8, 8, text[letter+4]);

      // drawLetter(white, brightness(8), 0-i,  16, letter+8);
      // drawLetter(white, brightness(8), 6-i,  16, letter+9);
      // drawLetter(white, brightness(8), 12-i, 16, letter+10);
      // drawLetter(white, brightness(8), 18-i, 16, letter+11);
      // drawLetter(white, brightness(8), 24-i, 16, letter+12);

      flushBuffer();
      clearBuffer();
      delay(50);
    }
    letter++;
  }
  free(newText);
}

//ripples----------------------------------------------------------------------------------
void ripples(){
  continuePattern = true;
  int animationSpeed = 100;
  //               r b g p t y
  int color0[6] = {0,1,2,3,4,5};
  int color1[6] = {3,4,5,1,2,0};
  int color2[6] = {5,3,4,0,1,2};
  int color = random(0,5);
  int posx[3];
  int posy[3];
  int siz[3] = {0,0,0};
  for(int i=0; i<3; i++){
      posx[i] = random(4,20);
      posy[i] = random(4,20);
  }
  for(siz[0]; siz[0]<9; siz[0]++){
    drawCircle(color0[color],brightness(8),posx[0],posy[0],siz[0]);
    drawCircle(color0[color],brightness(8),posx[0],posy[0],siz[0]-1);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }
  for(siz[0]; siz[0]<18; siz[0]++){
    drawCircle(color0[color],brightness(8),posx[0],posy[0],siz[0]);
    drawCircle(color0[color],brightness(8),posx[0],posy[0],siz[0]-1);
    drawCircle(color1[color],brightness(8),posx[1],posy[1],siz[1]);
    drawCircle(color1[color],brightness(8),posx[1],posy[1],siz[1]-1);
    siz[1]++;
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }    
  while(continuePattern){    
    drawCircle(color0[color],brightness(8),posx[0],posy[0],siz[0]);
    drawCircle(color0[color],brightness(8),posx[0],posy[0],siz[0]-1);
    drawCircle(color1[color],brightness(8),posx[1],posy[1],siz[1]);
    drawCircle(color1[color],brightness(8),posx[1],posy[1],siz[1]-1);
    drawCircle(color2[color],brightness(8),posx[2],posy[2],siz[2]);
    drawCircle(color2[color],brightness(8),posx[2],posy[2],siz[2]-1);
    
    siz[0]++;
    siz[1]++;
    siz[2]++;
    
    for(int i=0; i<3; i++){
      if(siz[i] > 26){
        siz[i] = 1;
        posx[i] = random(4,20);
        posy[i] = random(4,20);
      }
    }
    
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
    
  }
}
  

//filling bars------------------------------------------------------------------------------
void bars(){
  continuePattern = true;
  int animationSpeed = 30;
  while(continuePattern){
    int dir = random(0,6);
    char sizes[8] = {1,2,3,4,6,8};
    int bars = sizes[random(0,5)];
    int colors[bars];
    for(int i=0; i<bars; i++){
      colors[i] = random(0,6);
    }
    for(int j=0; j<bars; j++){
      for(int i=0; i<24; i++){
        switch(dir){
          case 0://left to right
            drawLine(colors[j], brightness(8),24/bars*j,i,24/bars*(j+1)-1,i);
            break;
          case 1://right to left
            drawLine(colors[j], brightness(8),24/bars*j,23-i,24/bars*(j+1)-1,23-i);
            break;
          case 2://top to bottom
            drawLine(colors[j], brightness(8),i,24/bars*j,i,24/bars*(j+1)-1);
            break;
          case 3://bottom to top
            drawLine(colors[j], brightness(8),23-i,24/bars*j,23-i,24/bars*(j+1)-1);
            break;
          default://both
            drawLine(colors[j], brightness(8),24/bars*j,i,24/bars*(j+1)-1,i);
            drawLine(colors[j], brightness(8),i,24/bars*j,i,24/bars*(j+1)-1);
            break;
        }
        flushBuffer();
        delay(animationSpeed);
      }
    }
    for(int i=0; i<24; i++){
      delay(animationSpeed);
    }
    clearBuffer();
  }
}

//Concentric Circles-------------------------------------------------------------------------
void circleTest() {
  int maxSize = 16;
  int centerx = 12;
  int centery = 12;
  continuePattern = true;
  int animationSpeed = 100;
  while (continuePattern) {
    for (int i = 0; i < maxSize; i++) {
      drawCircle(blue,   brightness(8), 12, 12, i);
      drawCircle(blue,   brightness(8), 12, 12, (i+1)%maxSize);
      drawCircle(teal,  brightness(8), 12, 12, (i+2)%maxSize);
      drawCircle(teal,  brightness(8), 12, 12, (i+3)%maxSize);
      drawCircle(green,    brightness(8), 12, 12, (i+4)%maxSize);
      drawCircle(green,    brightness(8), 12, 12, (i+5)%maxSize);
      drawCircle(yellow,   brightness(8), 12, 12, (i+6)%maxSize);
      drawCircle(yellow,   brightness(8), 12, 12, (i+7)%maxSize);
      drawCircle(red, brightness(8), 12, 12, (i+8)%maxSize);
      drawCircle(red, brightness(8), 12, 12, (i+9)%maxSize);
      drawCircle(purple, brightness(8), 12, 12, (i+10)%maxSize);
      drawCircle(purple, brightness(8), 12, 12, (i+11)%maxSize);
      drawCircle(white,  brightness(8), 12, 12, (i+12)%maxSize);
      drawCircle(white,  brightness(8), 12, 12, (i+13)%maxSize);

      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
      //while(true);
    }
  }
}

//Shifting Squares-------------------------------------------------------------------
void shiftingSquares() {
  int numberOfSquares = 3;
  int squareXValues[numberOfSquares];
  for (int i = 0; i < numberOfSquares; i++) {
    squareXValues[i] = random(0,6);
  }
  int squareYValues[numberOfSquares];
  for (int i = 0; i < numberOfSquares; i++) {
    squareYValues[i] = random(0,6);
  }

  int animationSpeed = 50;
  continuePattern = true;
  while (continuePattern) {
    // Pick a square to move
    int randomSquare = random(0,numberOfSquares);
    // Pick a direction to move it in
    int randomDirection = random(0,4);
    int xmod = 0;
    int ymod = 0;
    int xShift = 0;
    int yShift = 0;

    int boxsize = 3;

    switch (randomDirection){
      case 0:
        if (squareXValues[randomSquare] < 5) xmod = 1;
        else xmod = -1;
        break;

      case 1:
        if (squareXValues[randomSquare] > 0) xmod = -1;
        else xmod = 1;
        break;

      case 2:
        if (squareYValues[randomSquare] < 5) ymod = 1;
        else ymod = -1;
        break;

      case 3:
        if (squareYValues[randomSquare] > 0) ymod = -1;
        else ymod = 1;
        break;
    }


    while (yShift <= 4 && xShift <= 4 && yShift >= -4 && xShift >= -4) {
      //draw the squares
      for (int i = 0; i < numberOfSquares; i++){
        if (i == randomSquare) {
          int x = squareXValues[i]*4 + xShift;
          int y = squareYValues[i]*4 + yShift;
          drawBox(i, brightness(8),x,y,x+boxsize,y+boxsize);
          xShift += xmod;
          yShift += ymod;
        }
        else {
          drawBox(i, brightness(8),squareXValues[i]*4,squareYValues[i]*4,squareXValues[i]*4+3,squareYValues[i]*4+3);
        }
      }
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    squareXValues[randomSquare] += xmod;
    squareYValues[randomSquare] += ymod;
  }
}


//Raindrops------------------------------------------------------------------
void raindrops() {
  continuePattern = true;
  int animationSpeed = 30;
  int dropHeight[] = {0,0,0};
  dropHeight[0] = 0-random(0,8);
  dropHeight[1] = 0-random(0,8)+8;
  dropHeight[2] = 0-random(0,8)+16;
  int dropColumn[] = {0,0,0};
  dropColumn[0] = random(0,24);
  dropColumn[1] = random(0,24);
  dropColumn[2] = random(0,24);
  while (continuePattern) {

    for (int i = 0; i < 3; i++){
      if (dropHeight[i] < 24){
        drawLed(blue, brightness(8), dropHeight[i], dropColumn[i]);
      }
      else if (dropHeight[i] == 24) {
        drawLed(blue, brightness(8), 22, dropColumn[i]+1);
        drawLed(blue, brightness(8), 22, dropColumn[i]-1);
      }
      else if (dropHeight[i] == 25) {
        drawLed(blue, brightness(8), 22, dropColumn[i]+2);
        drawLed(blue, brightness(8), 22, dropColumn[i]-2);
      }
      else if (dropHeight[i] == 26) {
        drawLed(blue, brightness(8), 23, dropColumn[i]+3);
        drawLed(blue, brightness(8), 23, dropColumn[i]-3);
      }
      dropHeight[i]++;
      if (dropHeight[i] == 27) {
        dropHeight[i] = 0-random(0,8);
        dropColumn[i] = random(0,24);
      }
    }
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }
}

/********************************* PLANAR SPIN ********************************\
| A plane of light spins around the virtical center of the cube and changes    |
| colors after a certian number of rotations                                   |
|                                                                              |
| Written By: Asher Glick                                                      |
\******************************************************************************/
void planarSpin() {
  continuePattern = true;
  int animationSpeed = 20;
  int spinsPerColor = 5; // a spin is actually half a revolution
  int color = yellow;
  while (continuePattern) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < spinsPerColor; i++) {
      for (int x = 0; x < 23; x++) {
        drawLine(color,brightness(8),x,0,23-x,23);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
      for (int y = 0; y < 23; y++) {
        drawLine(color,brightness(8),23,y,0,23-y);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
      clearBuffer();
    }
    color = nextColor(color);
  }
}
