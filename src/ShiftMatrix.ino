#include "cubeplex.h"

void setup () {
  // Begin running the display loops
  initDisplay();
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  //drawLed(red,FULL,0,0);
  //flushBuffer();
}
void loop() {
  //trifade();
  //planarSpin();
  //chaseTheDot();

  whitefull();
}

int color = 6;



void whitefull() {
  drawBox(blue,brightness(8),0,0,23,23); 
  flushBuffer();
  clearBuffer();
  delay(2000);
  drawBox(green,brightness(8),0,0,23,23);
  drawBox(red,brightness(8),0,0,23,23); 
  flushBuffer();
  clearBuffer();
  delay(2000);
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
  int animationSpeed = 100;
  
  int xpos = 0;
  int ypos = 0;
  
  while (continuePattern) {
    switch(random(0,4)) {
      case 0:
        if (xpos > 0) {xpos--;break;}
        else color=nextColor(color);
      case 1:
        if (xpos < 3) {xpos++;break;}
        else color=nextColor(color);
        xpos--; break;
        
      case 2:
        if (ypos > 0) {ypos--;break;}
        else color=nextColor(color);
      case 3:
        if (ypos < 3) {ypos++;break;}
        else color=nextColor(color);
        ypos--; break;
      
    }
    drawLed(color,xpos,ypos);
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
  int animationSpeed = 100;
  int spinsPerColor = 5; // a spin is actually half a revolution
  while (continuePattern) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < spinsPerColor; i++) {
      for (int x = 0; x < 3; x++) {
        drawLine(color,x,0,3-x,3);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
      for (int y = 0; y < 3; y++) {
        drawLine(color,3,y,0,3-y);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
    }
    //color = nextColor(color);
  }
}
