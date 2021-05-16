#include <Adafruit_NeoPixel.h>

#define LED_PIN    30

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 8
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
   strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  
 mouth3();
}

void mouth1() {
   strip.setPixelColor(3, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(75);
  strip.setPixelColor(3, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(2, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(75);
  strip.setPixelColor(2, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(1, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(75);
  strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(0, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(75);
  strip.setPixelColor(0, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(75);
}

void mouth2() {
  strip.setPixelColor(0, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(1, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(2, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(3, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(125);
  strip.setPixelColor(0, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(2, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(3, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(125);
  
}

void mouth3() {
  strip.setPixelColor(3, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  
  strip.setPixelColor(2, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  
  strip.setPixelColor(1, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  
  strip.setPixelColor(0, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  strip.setPixelColor(0, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  strip.setPixelColor(2, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  strip.setPixelColor(3, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
  strip.setPixelColor(0, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(100);
}
