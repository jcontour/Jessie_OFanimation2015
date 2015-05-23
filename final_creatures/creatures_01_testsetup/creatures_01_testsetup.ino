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

int button1 = 0;
int button2 = 1;

Adafruit_NeoPixel strips[] = { strip1, strip2 };
Servo servos[] = { servo1, servo2 };

void setup() {
  Serial.begin(9600);

  //touch setup
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test");
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

void loop() {

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
      turnBlue(i);
    }
  }
  // reset our state
  lasttouched = currtouched;

}

void turnRed(int i) {
  for (float j = 0; j < 200; j+=.1) {
    strips[i].setPixelColor(0, j, 0, 200 - j);
    strips[i].show();
  }
  servos[i].write(180);
}
void turnBlue(int i) {
  for (float j = 0; j < 200; j+=.1) {
    strips[i].setPixelColor(0, 200 - j, 0, j);
    strips[i].show();
  }
  servos[i].write(0);
}
