#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   2 
#define PIXEL_PIN    6 
#define PIXEL_COUNT 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN);

bool oldState = HIGH;
int color = 0;

void setup() {
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();

}

void loop() {
  
  bool newState = digitalRead(BUTTON_PIN);

  if (newState == LOW && oldState == HIGH) {
    delay(20);
    newState = digitalRead(BUTTON_PIN);
    if (newState == HIGH) {
      color++;
    }
      if (color > 2) {
        color=1;
      }
      startShow(color);
  }
}
  
void startShow(int i) {
  switch(i){
    case 1:
      strip.setPixelColor(0, 200, 0, 0);
      strip.show();
      break;
    case 2: 
      strip.setPixelColor(0, 0, 0, 200);
      strip.show();
      break;
  }
}
 
