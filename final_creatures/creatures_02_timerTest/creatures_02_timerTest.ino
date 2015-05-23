//setup for timers
int wait = 1000;
unsigned long timer1 = 0;
unsigned long timer2 = 0;

//init for neopixel
#include <Adafruit_NeoPixel.h>
#define light1 5
#define light2 6
#define PIXEL_COUNT 1
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(PIXEL_COUNT, light1);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(PIXEL_COUNT, light2);

//init for servo
#include <Servo.h>
Servo servo1;
Servo servo2;
int servoPin1 = A0;
int servoPin2 = A1;

//init for touch
#include <Wire.h>
#include "Adafruit_MPR121.h"
Adafruit_MPR121 touch = Adafruit_MPR121();
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

Adafruit_NeoPixel strips[] = { strip1, strip2 };
Servo servos[] = { servo1, servo2 };
unsigned long timers [] = { timer1, timer2 };

bool isReleased = false;

void setup() {
  Serial.begin(9600);

  //touch setup
  if (!touch.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

  //light setup
  strip1.begin();
  strip1.setPixelColor(0, 0, 0, 200);
  strip1.show();
  strip2.begin();
  strip2.setPixelColor(0, 0, 0, 200);
  strip2.show();

  //servosetup
  servo1.attach(servoPin1);
  servo1.write(0);
  servo2.attach(servoPin2);
  servo2.write(0);
}
int counter = 0;
void loop() {
  if(isReleased){
   Serial.println("Hello"); 
    counter ++;
  }
  if( counter > 250 ){
   counter = 0;
   
  isReleased = false;
   turnBlue(0) ;
  }
  //buttonTouch code
  // Get the currently touched pads
  currtouched = touch.touched();

  for (uint8_t i = 0; i < 2; i++) {
    // it if *is* touched and *wasnt* touched before, alert!
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" touched");
      turnRed(i);
    }

    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
      timers[i] = millis();
      isReleased = true;
    }
//    checkTimers(i);
  }
  // reset our state
  lasttouched = currtouched;
}

//void checkTimers(int i) {
//  if (isReleased) {
//    Serial.print("CHECKING TIMER "); Serial.println(i);
//    Serial.print(millis() - timers[i]);
//    if (millis() - timers[i] > wait) {
//      Serial.println(i + "OFF");
//      turnBlue(i);
//    }
//   isReleased = false;
//  }
//}

void turnRed(int i) {
  strips[i].setPixelColor(0, 200, 0, 0);
  strips[i].show();
  servos[i].write(180);
}

void turnBlue(int i) {
  strips[i].setPixelColor(0, 0, 0, 200);
  strips[i].show();
  servos[i].write(0);
}
