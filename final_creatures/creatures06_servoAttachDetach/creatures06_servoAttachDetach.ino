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

float pos[15];
Servo servos[] = { servo1, servo2, servo3, servo4, servo5,
                   servo6, servo7, servo8, servo9, servo10,
                   servo11, servo12, servo13, servo14, servo15
                 };

bool isTouched[15];
bool atBottom[15];
bool reset[15];
unsigned int counter[15];
int triggerId;

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

Adafruit_NeoPixel strips[] = { strip1, strip2, strip3, strip4, strip5,
                               strip6, strip7, strip8, strip9, strip10,
                               strip11, strip12, strip13, strip14, strip15
                             };

float r[15];
float g[15];
float b[15];
float targetR[15];
float targetG[15];
float targetB[15];

unsigned int timeSinceLastTrigger;
unsigned int randomLengthofTime;

void setup() {

  while (!Serial);
  Serial.begin(9600);

  timeSinceLastTrigger = 0;
  randomLengthofTime = int(random(1000, 1200));

  setupTouch1();
  setupTouch2();

  setupPixels();
  setupServos();

  setupVariablesforIndividualBehavior();

}

void loop() {

  //read touches
  readTouch1();
  readTouch2();
  trigger();

  //set position and color
  for (int i = 0; i < 15; i++) {
//    servos[i].write(pos[i]);

    colorLerp(i);
  }

  timeSinceLastTrigger ++;
  checkTimeSinceTrigger();

}
