/******************************************************************************\
|                                     ,,                                       |
|                    db             `7MM                                       |
|                   ;MM:              MM                                       |
|                  ,V^MM.    ,pP"Ybd  MMpMMMb.  .gP"Ya `7Mb,od8                |
|                 ,M  `MM    8I   `"  MM    MM ,M'   Yb  MM' "'                |
|                 AbmmmqMA   `YMMMa.  MM    MM 8M""""""  MM                    |
|                A'     VML  L.   I8  MM    MM YM.    ,  MM                    |
|              .AMA.   .AMMA.M9mmmP'.JMML  JMML.`Mbmmd'.JMML.                  |
|                                                                              |
|                                                                              |
|                                ,,    ,,                                      |
|                     .g8"""bgd `7MM    db        `7MM                         |
|                   .dP'     `M   MM                MM                         |
|                   dM'       `   MM  `7MM  ,p6"bo  MM  ,MP'                   |
|                   MM            MM    MM 6M'  OO  MM ;Y                      |
|                   MM.    `7MMF' MM    MM 8M       MM;Mm                      |
|                   `Mb.     MM   MM    MM YM.    , MM `Mb.                    |
|                     `"bmmmdPY .JMML..JMML.YMbmd'.JMML. YA.                   |
|                                                                              |
\******************************************************************************/
/******************************************************************************\
| Copyright (c) 2012, Asher Glick, Smart Lighting Engeneering Research Center  |
| All rights reserved.                                                         |
|                                                                              |
| Redistribution and use in source and binary forms, with or without           |
| modification, are permitted provided that the following conditions are met:  |
|                                                                              |
| * Redistributions of source code must retain the above copyright notice,     |
|   this list of conditions and the following disclaimer.                      |
| * Redistributions in binary form must reproduce the above copyright notice,  |
|   this list of conditions and the following disclaimer in the documentation  |
|   and/or other materials provided with the distribution.                     |
|                                                                              |
| THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  |
| AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    |
| IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   |
| ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE    |
| LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          |
| CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         |
| SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     |
| INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      |
| CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      |
| ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   |
| POSSIBILITY OF SUCH DAMAGE.                                                  |
\******************************************************************************/

#ifndef _CUBEPLEX_H_
#define _CUBEPLEX_H_

// Define the full brightness of the LEDs
#define FULL 8




// Define the size of the LED matrix
#define MATRIX_WIDTH 24
#define MATRIX_HEIGHT 24
#define BUFFERSIZE MATRIX_WIDTH * MATRIX_HEIGHT * 3

int rowSize = MATRIX_WIDTH;
int displaySize = MATRIX_WIDTH * MATRIX_HEIGHT;


#include "Arduino.h"
//#include "WProgram.h"
#include "mappings.h"
#include "niceTimer.h"

char * _display_buffer;

// 
char oncontext = 0x0F;
char offcontext = 0xF0;

bool continuePattern = false;

char brightness(int intBrightness) {
  char trimmedBrightness = intBrightness && 0x0F;
  return offcontext==0x0F?trimmedBrightness:trimmedBrightness<<4;
}

int correctBrightness (int oldBrightness) {
  return oldBrightness << 4;
}

/***************************** INITITLIZE DISPLAY *****************************\
|
\******************************************************************************/
void initDisplay() {
  _display_buffer = (char*)malloc(sizeof(char) * (BUFFERSIZE+1));  
  
  char val = 0x0;
  
  for (int i = 0; i < BUFFERSIZE; i++) {
    _display_buffer[i] = 0x00;
  }  
  
  pinMode(SHIFT_OUT_RED,OUTPUT);
  pinMode(SHIFT_OUT_BLUE,OUTPUT);
  pinMode(SHIFT_OUT_GREEN,OUTPUT);
  pinMode(SHIFT_OUT_COMMON,OUTPUT);
  pinMode(CLEAR,OUTPUT);
  pinMode(CLOCK,OUTPUT);
  pinMode(REGESTER_CLOCK,OUTPUT);
  pinMode(ENABLE,OUTPUT);
  
 
  digitalWrite(ENABLE, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(REGESTER_CLOCK, LOW);
  digitalWrite(CLEAR, LOW);
  delay(1);
  digitalWrite(CLEAR, HIGH);
   
  digitalWrite(SHIFT_OUT_COMMON, HIGH);
  digitalWrite(SHIFT_OUT_RED, LOW);
  digitalWrite(SHIFT_OUT_GREEN, LOW);
  digitalWrite(SHIFT_OUT_BLUE, LOW);
  
 
   
  // Configure Interrupt for color display
  setTimer2Prescaler(32);
  enableTimer2OverflowInterrupt();
  setTimer2Mode (TIMER2_NORMAL);
  
  // Configure Interrupt for Animation Progression
  setTimer1Prescaler(256);
  enableTimer1OverflowInterrupt();
  setTimer1Mode (TIMER1_NORMAL);  
}
  //////////////////////////////////////////////////////////////////////////////
 ////////////////////////////// HELPER FUNCTIONS //////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/******************************** CLEAR BUFFER ********************************\
| This function will clear the buffer that you can write to, this will allow   |
| you to draw an eniterly new frame int othe buffer
\******************************************************************************/
void clearBuffer () {
  for (int i = 0; i < BUFFERSIZE; i++) {
    _display_buffer[i] &= oncontext;
  }
}

/**************************** NEXT COLOR FUNCTIONS ****************************\
| These functions cycle thorugh                                                |
|  the three primary colors red, greed, and blue                               |
|  the secondary colors purple, teal, yellow (every pairing of two leds)       |
|  the ALL THE COLORS (red,green,blue,purple,teal,yellow,white)                |
\******************************************************************************/
int nextPrimaryColor(int color)   { return  (color+1)%3; }
int nextSecondaryColor(int color) { return ((color+1)%3)+3; }
int nextColor(int color)          { return  (color+1)%7; }

/********************************** SWAP INT **********************************\
| This function uses the fast xor swap to change the values of the two         |
| intigers passed into the function                                            |
\******************************************************************************/
void swapint(int & one, int & two) {
  one = one^two;
  two = one^two;
  one = one^two;
}

/******************************* ROUND CLOSTEST *******************************\
| This function takes in a numberator and denominator and rounds to the        |
| nearist number instead of trunkating. It does this by calculating an extra   |
| digit (this function should be changes to be more accurate)                  |
\******************************************************************************/
int roundClostest(int numerator, int denominator) {
  numerator = (numerator << 1)/denominator;
  int output = (numerator>>1) + (numerator % 2);
  return output;
}

  //////////////////////////////////////////////////////////////////////////////
 //////////////////////////////////// DRAWING /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


// #define B 0
// #define G 1
// #define R 2
// #define T 3
// #define Y 4
// #define P 5
// #define W 6
// #define O 7

// #define blue 0
// #define green 1
// #define red 2
// #define teal 3
// #define yellow 4
// #define purple 5
// #define white 6
// #define off -7


#define R 0
#define B 1
#define G 2
#define P 3
#define T 4
#define Y 5
#define W 6
#define O 7

#define red 0
#define blue 1
#define green 2
#define purple 3
#define teal 4
#define yellow 5
#define white 6
#define off -7

/********************************** DRAW LED **********************************\
| This function turns on leds at a specified position. Depending on which      |
| color this function turns on different colors of the LED                     |
\******************************************************************************/
void drawLed(int color, int brightness, int x, int y) {
  if (x > MATRIX_WIDTH || x < 0 || y > MATRIX_HEIGHT || y < 0) return;
  if ((color/3)==0) { // single color (red green blue)
    _display_buffer[(((color)%3)*displaySize)+(x*rowSize)+y] += brightness;
  }
  else if ((color/3)==1) { // double color (teal yellow purple)
    _display_buffer[(((color)%3)*displaySize)+(x*rowSize)+y] += brightness;
    _display_buffer[(((color+1)%3)*displaySize)+(x*rowSize)+y] += brightness;
  }
  else if (color == 6){ // all colors (white)
    _display_buffer[((0)*displaySize)+(x*rowSize)+y] += brightness;
    _display_buffer[((1)*displaySize)+(x*rowSize)+y] += brightness;
    _display_buffer[((2)*displaySize)+(x*rowSize)+y] += brightness;
  }
  else if (color == -7) {
    _display_buffer[((0)*displaySize)+(x*rowSize)+y] = 0;
    _display_buffer[((1)*displaySize)+(x*rowSize)+y] = 0;
    _display_buffer[((2)*displaySize)+(x*rowSize)+y] = 0;
  }
}
void drawLed(int color, int x, int y) {
  drawLed(color,FULL,x,y);
}


#include "drawLetter.h"




/********************************** DRAW BOX **********************************\
| This function will draw a filled in box of the specified color on the cube   |
\******************************************************************************/
void drawBox(int color, int brightness, int startx, int starty, int endx, int endy) {
  if (startx > endx) swapint(startx,endx);
  if (starty > endy) swapint(starty,endy);  
  for (int i = startx; i <= endx; i++) {
    for (int j = starty; j <= endy; j++) {
      drawLed(color,brightness,i,j);
    } 
  }
}
void drawBox(int color, int startx, int starty, int endx, int endy) {
  drawBox(color,8,startx,starty,endx,endy);
}
/******************************* DRAW HOLLOW BOX ******************************\
| This function will draw the walls, celing, and floor of a defined box        |
\******************************************************************************/
void drawHollowBox(int color, int brightness, int startx, int starty, int endx, int endy) {
  if (startx > endx) swapint(startx,endx);
  if (starty > endy) swapint(starty,endy);
  
  
  for (int i = startx; i <= endx; i ++) {
    for (int j = starty; j <= endy; j ++) {
      if (i == startx || i == endx || j == starty || j == endy) {
        drawLed(color,brightness,i,j);
      }
    }
  }
}
void drawHollowBox(int color, int startx, int starty, int endx, int endy) {
   drawHollowBox(color,FULL,startx,starty,endx,endy);
}
/********************************** DRAW LINE *********************************\
| This function will attempt to draw a line between the two points given. Due  |
| to the limited avalibility of pixels the best approximation is chosen for    |
| each pixel value                                                             |
\******************************************************************************/
void drawLine(int color, int brightness, int startx, int starty, int endx, int endy) {
  bool reverseX = false;
  bool reverseY = false;
  if (startx > endx) {swapint(startx,endx);reverseX=true;}
  if (starty > endy) {swapint(starty,endy);reverseY=true;}

  int delx = endx - startx;
  int dely = endy - starty;
  
  int longest = (delx>dely?delx:dely);
  for (int i = 0; i < longest; i++) {
    int xpos;
    if (reverseX) xpos = roundClostest(((longest-i)*delx),longest) + startx;
    else xpos = roundClostest((i*delx),longest) + startx;
    
    int ypos;
    if (reverseY) ypos = roundClostest(((longest-i)*dely),longest) + starty;
    else ypos = roundClostest((i*dely),longest) + starty;
    
    drawLed(color,brightness,xpos,ypos);
  }
  
  if (reverseX) swapint(startx,endx);
  if (reverseY) swapint(starty,endy);
  drawLed(color,brightness,endx,endy);
}
void drawLine(int color, int startx, int starty, int endx, int endy) {
  drawLine(color,FULL,startx, starty, endx, endy);
}

/*
*/
void drawCircle(int color, int brightness, int x0, int y0, int radius)
{
  int f = 1 - radius;
  int ddF_x = 1;
  int ddF_y = -2 * radius;
  int x = 0;
  int y = radius;
 

  drawLed(color,brightness,x0, y0 + radius);
  drawLed(color,brightness,x0, y0 - radius);
  drawLed(color,brightness,x0 + radius, y0);
  drawLed(color,brightness,x0 - radius, y0);
 
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
    drawLed(color,brightness,x0 + x, y0 + y);
    drawLed(color,brightness,x0 - x, y0 + y);
    drawLed(color,brightness,x0 + x, y0 - y);
    drawLed(color,brightness,x0 - x, y0 - y);
    drawLed(color,brightness,x0 + y, y0 + x);
    drawLed(color,brightness,x0 - y, y0 + x);
    drawLed(color,brightness,x0 + y, y0 - x);
    drawLed(color,brightness,x0 - y, y0 - x);
  }
}
  //////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////// DISPLAY //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int pwmm = 0; // used for determining the number of full frames that have been displayed
int display_length;

void flushBuffer() {
  for (int i = 0; i < BUFFERSIZE; i++) {
    _display_buffer[i] &=0xF0;
    _display_buffer[i] |= (_display_buffer[i] >> 4);
  }
}


/*************************** INTERRUPT DISPLAY LEDS ***************************\
| This is the interrupt function to turn on one led. After it turns that one   |
| on it will 
\******************************************************************************/
int currentRow = 0;
ISR(TIMER2_OVF_vect) {
  //digitalWrite(13,HIGH);
  //for (int i = 0; i < MATRIX_WIDTH; i++) {
    for (int i = MATRIX_WIDTH-1; i >= 0; i--){
    // set RED BLUE and GREEN
    PORTD &= ~0x3C;
    PORTD |= (_display_buffer[i+(currentRow*rowSize)                ]&oncontext)!=0?0x10:0x00; // RED
    PORTD |= (_display_buffer[i+(currentRow*rowSize)+(  displaySize)]&oncontext)!=0?0x04:0x00; // BLUE
    PORTD |= (_display_buffer[i+(currentRow*rowSize)+(2*displaySize)]&oncontext)!=0?0x08:0x00; // GREEN
    // shift the common row
    PORTD |= i==currentRow?0x20:0x00; // COMMON
    // CLOCK PULSE
    PORTB |= 0x01;
    PORTB &= ~0x01;
  }
  //digitalWrite(REGESTER_CLOCK, HIGH);
  PORTB |= 0x02;
  //delayMicroseconds(10);
  //digitalWrite(REGESTER_CLOCK, LOW);
  PORTB &= ~0x02;
  if (currentRow == MATRIX_HEIGHT) currentRow = 0;
  else currentRow = (currentRow+1);
}





/******************************************************************************\
| Some helpfull info for overflowing timers with different prescaler values    |
|  16000000 / (   1*256) = 16000000 / 256    =  62500 Hz                       |
|  16000000 / (   8*256) = 16000000 / 2048   =  ~7812 Hz                       |
|  16000000 / (  32*256) = 16000000 / 8192   =  ~1953 Hz                       |
|  16000000 / (  64*256) = 16000000 / 16384  =   ~976 Hz                       |
|  16000000 / ( 128*256) = 16000000 / 32768  =   ~488 Hz                       | 
|  16000000 / ( 256*256) = 16000000 / 65536  =   ~244 Hz                       |
|  16000000 / (1024*256) = 16000000 / 262144 =    ~61 Hz                       |
\******************************************************************************/
int animationTimer = 0;
int animationMax = 10;

ISR(TIMER1_OVF_vect) {
  animationTimer++;
  if (animationTimer == animationMax) {
    continuePattern = false;
    animationTimer=0;
  }
}

#endif
