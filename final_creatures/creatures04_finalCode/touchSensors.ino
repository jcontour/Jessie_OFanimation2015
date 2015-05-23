#include <Wire.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();

uint16_t lasttouched1 = 0;
uint16_t currtouched1 = 0;
uint16_t lasttouched2 = 0;
uint16_t currtouched2 = 0;

void setupTouch1() {
  Serial.println("#1 test");
  if (!cap1.begin(0x5A)) {
    Serial.println("#1 not found, check wiring?");
    while (1);
  }
  Serial.println("#1 found!");
}

void setupTouch2() {
  Serial.println("#2 test");
  if (!cap2.begin(0x5B)) {
    Serial.println("#2 not found, check wiring?");
    while (1);
  }
  Serial.println("#2 found!");
}

void readTouch1() {
  currtouched1 = cap1.touched();

  for (uint8_t i = 0; i < 10; i++) {
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #1 touched");
      //when touched, trigger
      isTouched[i] = true;
    }

    if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #1 released");

      //WHEN RELEASED, RESTART TIMER
    }
  }
  lasttouched1 = currtouched1;
}

void readTouch2() {
  currtouched2 = cap2.touched();

  for (uint8_t i = 0; i < 5; i++) {
    if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #2 touched");
      //when touched, trigger
       isTouched[i + 10] = true;
     }
    if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
      Serial.print(i); Serial.println(" #2 released");

      //WHEN RELEASED, RESTART TIMER

    }
  }
  lasttouched2 = currtouched2;
}
