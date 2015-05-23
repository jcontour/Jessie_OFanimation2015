//setup for timers
unsigned int timer1 = 0;
unsigned int timer2 = 0;
unsigned int timer3 = 0;
unsigned int timer4 = 0;
unsigned int timer5 = 0;
unsigned int timer6 = 0;
unsigned int timer7 = 0;
unsigned int timer8 = 0;
unsigned int timer9 = 0;
unsigned int timer10 = 0;
unsigned int timer11 = 0;
unsigned int timer12 = 0;
unsigned int timer13 = 0;
unsigned int timer14 = 0;
unsigned int timer15 = 0;

//init for neopixel
#include <Adafruit_NeoPixel.h>
#define light1 3
#define light2 22
#define light3 23
#define light4 24
#define light5 25
#define light6 26
#define light7 27
#define light8 28
#define light9 29
#define light10 30
#define light11 31
#define light12 32
#define light13 33
#define light14 34
#define light15 35

#define PIXEL_COUNT 3
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(PIXEL_COUNT, light1);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(PIXEL_COUNT, light2);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(PIXEL_COUNT, light3);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(PIXEL_COUNT, light4);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(PIXEL_COUNT, light5);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(PIXEL_COUNT, light6);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(PIXEL_COUNT, light7);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(PIXEL_COUNT, light8);
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(PIXEL_COUNT, light9);
Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(PIXEL_COUNT, light10);
Adafruit_NeoPixel strip11 = Adafruit_NeoPixel(PIXEL_COUNT, light11);
Adafruit_NeoPixel strip12 = Adafruit_NeoPixel(PIXEL_COUNT, light12);
Adafruit_NeoPixel strip13 = Adafruit_NeoPixel(PIXEL_COUNT, light13);
Adafruit_NeoPixel strip14 = Adafruit_NeoPixel(PIXEL_COUNT, light14);
Adafruit_NeoPixel strip15 = Adafruit_NeoPixel(PIXEL_COUNT, light15);

//init for servo
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;
Servo servo13;
Servo servo14;
Servo servo15;

//init for touch
#include <Wire.h>
#include "Adafruit_MPR121.h"
Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();

uint16_t lasttouched1 = 0;
uint16_t currtouched1 = 0;
uint16_t lasttouched2 = 0;
uint16_t currtouched2 = 0;

Adafruit_NeoPixel strips[] = { strip1, strip2, strip3, strip4, strip5,
                               strip6, strip7, strip8, strip9, strip10,
                               strip11, strip12, strip13, strip14, strip15
                             };
Servo servos[] = { servo1, servo2, servo3, servo4, servo5,
                   servo6, servo7, servo8, servo9, servo10,
                   servo11, servo12, servo13, servo14, servo15
                 };

unsigned int timers [] = { timer1, timer2, timer3, timer4, timer5,
                           timer6, timer7, timer8, timer9, timer10,
                           timer11, timer12, timer13, timer14, timer15
                         };

bool isReleased [] = { false, false, false, false, false,
                       false, false, false, false, false,
                       false, false, false, false, false
                     };

int numCreatures = 15;

void setup() {
  Serial.begin(9600);

  //touch setup
  if (!cap1.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  if (!cap2.begin(0x5B)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }

  //light setup
  for (int i = 0; i < numCreatures; i++) {
    for (int j = 0; j < 3; j++) {
      strips[i].begin();
      strips[i].setPixelColor(j, 0, 0, 200);
      strips[i].show();
    }
  }

  //servosetup
  for (int i = 0; i < numCreatures; i++) {
    servos[i].attach(36 + i);
    servos[i].write(90);
  }
}

void loop() {

  //checking if released and ++ timers
  for (int i = 0; i < numCreatures; i++) {

    if (isReleased[i]) {
      Serial.print(i); Serial.print(" timer = "); Serial.println(timers[i]);
      timers[i] ++;
    }

    if (timers[i] > 100) {
      Serial.print(i); Serial.println(" expired");
      timers[i] = 0;
      isReleased[i] = false;
      turnBlue(i);
    }
  }

  readTouch1();
  readTouch2();

}

void turnRed(int i) {
  for (float j = 0; j < 200; j += .05) {
    for (int k = 0; k < 3; k++) {
      strips[i].setPixelColor(k, j, 0, 200 - j);
      strips[i].show();
    }
  }
  servos[i].write(0);
}

void turnBlue(int i) {
  for (float j = 0; j < 200; j += .05) {
    for (int k = 0; k < 3; k++) {
      strips[i].setPixelColor(k, 200 - j, 0, j);
      strips[i].show();
    }
  }
  servos[i].write(90);
}
