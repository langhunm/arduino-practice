#include "FastLED.h"
#define NUM_LEDS 140
#define DATA_PIN 7

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
pinMode(DATA_PIN, OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
}

void loop() {
  int val = analogRead(2);
  int numLedsToLight = map(val, 0, 1023, 0, NUM_LEDS);

  // First, clear the existing led values
  FastLED.clear();
  for (int led = 0; led < numLedsToLight; led++) {
    leds[led] = CRGB::Blue;
  }
  FastLED.show();
}
