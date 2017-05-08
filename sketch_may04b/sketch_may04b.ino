#include <FastLED.h>

#define LED_PIN     11


#define LED_PIN1     12
#define NUM_LEDS    200
#define BRIGHTNESS  80
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define SPEED 400

CRGB leds[NUM_LEDS];
CRGB leds1[NUM_LEDS];

void setup() {
  delay( 3000 ); // power-up safety delay
  
  // the wiki features a much more basic setup line:
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds1, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  s(leds);
  s(leds1);
 
 }
void s(CRGB *leds)
{
 int i;
 for(i=0;i<10;i++)
  {
  leds[i] = CRGB::Green;
  }
  FastLED.show();
  delay(1000);
  for(i=0;i<10;i++)
  {
  leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(1000);
  }






//void loop() {
//  s(leds);
// 
// }
//void s(CRGB leds)
//{
// int i;
// for(i=0;i<10;i++)
//  {
//  leds[i] = CRGB::Green;
//  }
//  FastLED.show();
//  delay(1000);
//  for(i=0;i<10;i++)
//  {
//  leds[i] = CRGB::Black;
//  }
//  FastLED.show();
//  delay(1000);
//  }
