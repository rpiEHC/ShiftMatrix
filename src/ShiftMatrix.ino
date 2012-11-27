#include "cubeplex.h"

void setup () {
  // Begin running the display loops
  initDisplay();
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  //digitalWrite(13,HIGH);
  //drawLed(red,FULL,0,0);
  //flushBuffer();
}
void loop() {
  //whitefull();
  //digitalWrite()
  //trifade();
  
  //marqueueText("Welcome to the");
  //marqueueText("Smart Lighting ERC!");
  //animationTimer = 0;

  //marqueueText("Welcome to the Lightting research center!");
  //marqueueText("Welcome to the Lightting research center!");
  //letterTest();
  //testDraw();
  //shiftingSquares();
  raindrops();
  circleTest();
  //planarSpin();
  
  //chaseTheDot();
  //everyColor();
  
  //kevinTest();
  //lineTest();
  //checkerboard();
}

int color = 6;


void letterTest() {
  char letter = '0';
  while(true) {
    for (int i = 0; i < 6; i++) {
      drawLetter(white, brightness(8), 0-i, 0, letter);
      drawLetter(white, brightness(8), 6-i, 0, letter+1);
      drawLetter(white, brightness(8), 12-i, 0, letter+2);
      drawLetter(white, brightness(8), 18-i, 0, letter+3);
      drawLetter(white, brightness(8), 24-i, 0, letter+4);

      drawLetter(white, brightness(8), 0-i,  8, letter+4);
      drawLetter(white, brightness(8), 6-i,  8, letter+5);
      drawLetter(white, brightness(8), 12-i, 8, letter+6);
      drawLetter(white, brightness(8), 18-i, 8, letter+7);
      drawLetter(white, brightness(8), 24-i, 8, letter+8);

      drawLetter(white, brightness(8), 0-i,  16, letter+8);
      drawLetter(white, brightness(8), 6-i,  16, letter+9);
      drawLetter(white, brightness(8), 12-i, 16, letter+10);
      drawLetter(white, brightness(8), 18-i, 16, letter+11);
      drawLetter(white, brightness(8), 24-i, 16, letter+12);

      flushBuffer();
      clearBuffer();
      delay(100);
    }
    letter++;
  }
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

void circleTest() {
  int maxSize = 16;
  int centerx = 12;
  int centery = 12;
  continuePattern = true;
  int animationSpeed = 100;
  while (continuePattern) {
    for (int i = 0; i < maxSize-2; i++) {
      drawCircle(blue,   brightness(8), 12, 12, i);
      drawCircle(blue,   brightness(8), 12, 12, (i+1)%maxSize);
      drawCircle(green,  brightness(8), 12, 12, (i+2)%maxSize);
      drawCircle(green,  brightness(8), 12, 12, (i+3)%maxSize);
      drawCircle(red,    brightness(8), 12, 12, (i+4)%maxSize);
      drawCircle(red,    brightness(8), 12, 12, (i+5)%maxSize);
      drawCircle(teal,   brightness(8), 12, 12, (i+6)%maxSize);
      drawCircle(teal,   brightness(8), 12, 12, (i+7)%maxSize);
      drawCircle(yellow, brightness(8), 12, 12, (i+8)%maxSize);
      drawCircle(yellow, brightness(8), 12, 12, (i+9)%maxSize);
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

/*
void allShifting() {
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
*/
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

void testDraw() {
  color = blue;
  int bright = brightness(8);
  int x0 = 12;
  int y0 = 12;
  int radius = 0;

  int f = 1 - radius;
  int ddF_x = 1;
  int ddF_y = -2 * radius;
  int x = 0;
  int y = radius;
 

  drawLed(color,bright,x0, y0 + radius);
  drawLed(color,bright,x0, y0 - radius);
  /*drawLed(color,bright,x0 + radius, y0);
  drawLed(color,bright,x0 - radius, y0);
 
  while(x < y)
  {
    // ddF_x == 2 * x + 1;
    // ddF_y == -2 * y;
    // f == x*x + y*y - radius*radius + 2*x - y + 1;
    if(f >= 0) 
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;    
    drawLed(color,bright,x0 + x, y0 + y);
    drawLed(color,bright,x0 - x, y0 + y);
    drawLed(color,bright,x0 + x, y0 - y);
    drawLed(color,bright,x0 - x, y0 - y);
    drawLed(color,bright,x0 + y, y0 + x);
    drawLed(color,bright,x0 - y, y0 + x);
    drawLed(color,bright,x0 + y, y0 - x);
    drawLed(color,bright,x0 - y, y0 - x);
  }*/
  //drawLed(blue, brightness(8),12,12);
  flushBuffer();
  clearBuffer();
}

void clock() {
  continuePattern = true;
  int animationSpeed = 100;
  while (continuePattern) {

    drawCircle(white, brightness(8), 12, 12, 12);

  }
}

void checkerboard() {
  for (int i = 0; i < 24; i ++) {
    for (int j = i%2^1; j < 24; j+= 2) {
      drawLed(white, brightness(8), i,j);
    }
  }
  flushBuffer();
  clearBuffer();  
}

void kevinTest() {
  for (int i = 0; i < 24; i++) {
    drawLed(yellow, brightness(8), 0, i);
      flushBuffer();
  clearBuffer();
  delay(1000);
  }
}

void lineTest() {
  for (int i = 0; i < 24; i++) {
    drawLine(white, brightness(8), 0,i, 23, i);
    flushBuffer();
    clearBuffer();
    delay(100);
  }

}

void whitefull() {
  int size = 23;
  int delayTime = 1000;
  
  // drawBox(blue,brightness(8),0,0,size,size); 
  // flushBuffer();
  // clearBuffer();
  // delay(delayTime);

  // drawBox(green,brightness(8),0,0,size,size);
  // flushBuffer();
  // clearBuffer();
  // delay(delayTime);

  // drawBox(red,brightness(8),0,0,size,size); 
  // flushBuffer();
  // clearBuffer();
  // delay(delayTime);

  // drawBox(teal,brightness(8),0,0,size,size); 
  // flushBuffer();
  // clearBuffer();
  // delay(delayTime);

  // drawBox(purple,brightness(8),0,0,size,size); 
  // flushBuffer();
  // clearBuffer();
  // delay(delayTime);

  drawBox(white,brightness(8),0,0,size,size); 
  drawBox(blue,  brightness(8),0,0,0,size);
  flushBuffer();
  clearBuffer();
  delay(delayTime);
  while(true);

  // drawBox(white,brightness(8),0,0,size,size); 
  // flushBuffer();
  // clearBuffer();
  // delay(delayTime);
}

void everyColor() {
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 24; j++) {
      drawLed(red,brightness(8),i,j);
      flushBuffer();
      clearBuffer();
      //delay();
    }
  }
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 24; j++) {
      drawLed(green,brightness(8),i,j);
      flushBuffer();
      clearBuffer();
      //(1000);
    }
  }
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 24; j++) {
      drawLed(blue,brightness(8),i,j);
      flushBuffer();
      clearBuffer();
      //delay(1000);
    }
  }
}

/********************************** TRI-FADE **********************************\
| This animation fades through the red green and blue colors of the leds       |
| creating different mixtures of each of the colors.                           |
|                                                                              |
| Written By: Asher Glick                                                      |
\******************************************************************************/
void trifade() {
  continuePattern = true;
  int animationSpeed = 200;
  while (continuePattern) {
    // blue fade out, red fade in
    for (int i = 1; i <= 16; i++) {
      drawBox(blue,correctBrightness(9-i),0,0,3,3);
      drawBox(red,correctBrightness(i),0,0,3,3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // red fade out, green fade in
    for (int i = 1; i <= 16; i++) {
      drawBox(red,correctBrightness(9-i),0,0,3,3);
      drawBox(green,correctBrightness(i),0,0,3,3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // green fade out, blue fade in
    for (int i = 1; i <= 16; i++) {
      drawBox(green,correctBrightness(9-i),0,0,3,3);
      drawBox(blue,correctBrightness(i),0,0,3,3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
  }
}

/******************************** CHASE THE DOT *******************************\
| A single point of light moves around the cube randomly and changes colors    |
| when it tries to go out of bounds                                            |
|                                                                              |
| Inspired By: Jonah Glick                                                     |
| Written By: Asher Glick                                                      |
\******************************************************************************/
void chaseTheDot() {
  continuePattern = true;
  int animationSpeed = 1;
  
  int xpos = 0;
  int ypos = 0;
  
  while (continuePattern) {
    switch(random(0,4)) {
      case 0:
        if (xpos > 0) {xpos--;break;}
        else color=nextColor(color);
      case 1:
        if (xpos < 23) {xpos++;break;}
        else color=nextColor(color);
        xpos--; break;
        
      case 2:
        if (ypos > 0) {ypos--;break;}
        else color=nextColor(color);
      case 3:
        if (ypos < 23) {ypos++;break;}
        else color=nextColor(color);
        ypos--; break;
      
    }
    drawLed(color,brightness(8),xpos,ypos);
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
  int animationSpeed = 0;
  int spinsPerColor = 5; // a spin is actually half a revolution
  color = yellow;
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
    }
    color = nextColor(color);
  }
}

//void 