#include <FastLED.h>

#define LED_PIN    4
#define NUM_LEDS    150
#define NUM_LEDS_HUO    100
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define FRAMES_PER_SECOND 60
#define HUOYANSHIJIAN 60

CRGB leds[NUM_LEDS];

int counter_hongwai;

unsigned long time_isr;
unsigned long time_isr_Start;

void setup() {

  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  //  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, hongwaiInter, HIGH);
  //  attachInterrupt(1, setStart, HIGH);
  time_isr = millis();
  time_isr_Start = millis();
  counter_hongwai = 0;
  FastLED.setBrightness(  BRIGHTNESS );
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


  if (counter_hongwai != 0) {

    //    yangshi_hongwai();
        counter_hongwai--;
    Serial.println("bbb");
    Serial.println(counter_hongwai);
    //    FastLED.clear();
    //    FastLED.clearData();
    //    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip );
    //    FastLED.clear();
    //    FastLED.clearData();
    //    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds1, NUM_LEDS_HUO).setCorrection( TypicalLEDStrip );
    //
    //    //    yangshi6();
    //    yangshi_huoyan();
    //    FastLED.clearData();
    //    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

    //更换灯带数组，循环 变化数组，显示led效果

    //执行红外样式
    




  }
  else
  {
    Serial.println("aaa");
    //执行一般样式
  }
}


void hongwaiInter() {

  unsigned long time_isr_tmp;
  unsigned long time_isr_tmp1 = millis();
  time_isr_tmp =  time_isr_tmp1 - time_isr;
  time_isr = time_isr_tmp1;
  if (time_isr_tmp > 200)
  {
    Serial.println("hw sucessfull!");
    counter_hongwai = 200;
  }
}
