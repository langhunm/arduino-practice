/*

   定时扫描红外，更新红外标记

   1 2 3 引脚为灯带引脚
   4 5 6 引脚为红外引脚


*/

#include <FastLED.h>
#include <MsTimer2.h>


#define LED_PIN     11
#define NUM_LEDS    120
#define NUM_HONGWEI_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
CRGB leds_hongwei[NUM_HONGWEI_LEDS];
int hongwei[NUM_HONGWEI_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  MsTimer2::set(10, saomiao_hongwai); // 500ms period
  MsTimer2::start();
  for(int i=0;i<NUM_HONGWEI_LEDS;i++){
    hongwei[i]=0;
    }
}

void loop() {

  yangshi6();

}


void yangshi6()
{
  //  Serial.println("zhongduan neirong!");

  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}

//扫描 3 4 5引脚的输入
void saomiao_hongwai()
{
  int i;
  for (i = 4; i <= 6; i++) {
    if (digitalRead(i) == HIGH) {

      hongwei[i] =100;
      Serial.println(i);

    }
  }

}

//
