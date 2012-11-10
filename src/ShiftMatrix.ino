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
  //digitalWrite()
  //trifade();
  marqueueText("1234567");
  letterTest();
  circleTest();
  planarSpin();
  
  //chaseTheDot();
  //everyColor();
  //whitefull();
  //kevinTest();
  //lineTest();
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
  while(text[letter] != 0) {
    for (int i = 0; i < 6; i++) {
      // drawLetter(white, brightness(8), 0-i, 0, letter);
      // drawLetter(white, brightness(8), 6-i, 0, letter+1);
      // drawLetter(white, brightness(8), 12-i, 0, letter+2);
      // drawLetter(white, brightness(8), 18-i, 0, letter+3);
      // drawLetter(white, brightness(8), 24-i, 0, letter+4);

      drawLetter(white, brightness(8), 0-i,  8, text[letter]);
      drawLetter(white, brightness(8), 6-i,  8, text[letter+1]);
      drawLetter(white, brightness(8), 12-i, 8, text[letter+2]);
      drawLetter(white, brightness(8), 18-i, 8, text[letter+3]);
      drawLetter(white, brightness(8), 24-i, 8, text[letter+4]);

      // drawLetter(white, brightness(8), 0-i,  16, letter+8);
      // drawLetter(white, brightness(8), 6-i,  16, letter+9);
      // drawLetter(white, brightness(8), 12-i, 16, letter+10);
      // drawLetter(white, brightness(8), 18-i, 16, letter+11);
      // drawLetter(white, brightness(8), 24-i, 16, letter+12);

      flushBuffer();
      clearBuffer();
      delay(100);
    }
    letter++;
  }
}

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

      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
  }
}

void clock() {
  continuePattern = true;
  int animationSpeed = 100;
  while (continuePattern) {

    drawCircle(white, brightness(8), 12, 12, 12);

  }
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
  drawLine(white, brightness(8), 0,21, 23, 21);
  flushBuffer();
  clearBuffer();

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
  flushBuffer();
  clearBuffer();
  delay(delayTime);

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