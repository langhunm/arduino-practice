#include <FastLED.h>

#define LED_PIN     11
#define NUM_LEDS    200
#define BRIGHTNESS  80
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define SPEED 400

CRGB leds[NUM_LEDS];


void setup() {
  delay( 3000 ); // power-up safety delay
  
  // the wiki features a much more basic setup line:
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
 while(1)
 {
  int i;
  for(i=0;i<NUM_LEDS;i++)
  {
  leds[i] = CRGB::Green;
  }
 Serial.println(leds[0]);
  FastLED.show();
  delay(SPEED);
  for(i=0;i<NUM_LEDS;i++)
  {
  leds[i] = CRGB::Blue;
  }
 Serial.println(leds[0]);
  FastLED.show();
  delay(SPEED);
  for(i=0;i<NUM_LEDS;i++)
  {
  leds[i] = CRGB::Red;
  }
 Serial.println(leds[0]);
  FastLED.show();
  delay(SPEED);
  for(i=0;i<NUM_LEDS;i++)
  {
  leds[i] = CRGB::White;
  }
 Serial.println(leds[0]);
  FastLED.show();
  delay(SPEED);
  }
 }
