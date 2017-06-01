/*
   一般情况下样式循环
   有红外 就显示红外样式
   隔一段时间 恢复开始状态 重新执行

*/

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

CRGB leds2[NUM_LEDS];

CRGB leds1[NUM_LEDS_HUO];
int counter_hongwai;

#define UPDATES_PER_SECOND 100
bool gReverseDirection = false;


#define COOLING  55
#define SPARKING 120


unsigned long time_isr;
unsigned long time_isr_Start;

void yangshi();
void yangshi_hongwai();
void  changestyle();
void  displayled();
void yangshi6();
void yangshi_huoyan();



CRGBPalette16 currentPalette;
TBlendType    currentBlending;

static uint8_t secondHand ;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

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

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;


}


void loop() {
  if (counter_hongwai != 0) {

    yangshi_hongwai();
    counter_hongwai--;
    Serial.println(counter_hongwai);
    //        Serial.println("aaa");
    FastLED.clear();
    FastLED.clearData();
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.clear();
    FastLED.clearData();
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds1, NUM_LEDS_HUO).setCorrection( TypicalLEDStrip );

    //    yangshi6();
    yangshi_huoyan();
    FastLED.clearData();
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

    //更换灯带数组，循环 变化数组，显示led效果

  }
  else
  {
    //    Serial.println("aaa");

    changestyle();
    displayled();
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
    counter_hongwai = 2;
  }
}

//=====================================================





void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;

  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}


void ChangePalettePeriodically()
{
  secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;

  if ( lastSecond != secondHand) {
    lastSecond = secondHand;
    if ( secondHand ==  0)  {
      currentPalette = RainbowColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 10)  {
      currentPalette = RainbowStripeColors_p;
      currentBlending = NOBLEND;
    }
    if ( secondHand == 15)  {
      currentPalette = RainbowStripeColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 20)  {
      SetupPurpleAndGreenPalette();
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 25)  {
      SetupTotallyRandomPalette();
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 30)  {
      SetupBlackAndWhiteStripedPalette();
      currentBlending = NOBLEND;
    }
    if ( secondHand == 35)  {
      SetupBlackAndWhiteStripedPalette();
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 40)  {
      currentPalette = CloudColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 45)  {
      currentPalette = PartyColors_p;
      currentBlending = LINEARBLEND;
    }
    if ( secondHand == 50)  {
      currentPalette = myRedWhiteBluePalette_p;
      currentBlending = NOBLEND;
    }
    if ( secondHand == 55)  {
      currentPalette = myRedWhiteBluePalette_p;
      currentBlending = LINEARBLEND;
    }
  }
}

// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette()
{
  for ( int i = 0; i < 16; i++) {
    currentPalette[i] = CHSV( random8(), 255, random8());
  }
}


void SetupBlackAndWhiteStripedPalette()
{

  fill_solid( currentPalette, 16, CRGB::Black);

  currentPalette[0] = CRGB::White;
  currentPalette[4] = CRGB::White;
  currentPalette[8] = CRGB::White;
  currentPalette[12] = CRGB::White;

}

// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette()
{
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;

  currentPalette = CRGBPalette16(
                     green,  green,  black,  black,
                     purple, purple, black,  black,
                     green,  green,  black,  black,
                     purple, purple, black,  black );
}



const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
  CRGB::Red,
  CRGB::Gray, // 'white' is too bright compared to red and blue
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Red,
  CRGB::Gray,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Blue,
  CRGB::Black,
  CRGB::Black
};

//void yangshi() {
//    Serial.println("bbbb");
//  //  Serial.println(currentPalette);
//  //  Serial.println("cccc");
//  //  Serial.println(currentBlending);
//
//  while (secondHand != 55 )
//  {
//    Serial.println(secondHand);
//    ChangePalettePeriodically();
//
//    static uint8_t startIndex = 0;
//    startIndex = startIndex + 1; /* motion speed */
//
//    FillLEDsFromPaletteColors( startIndex);
//
//    FastLED.show();
//    FastLED.delay(1000 / UPDATES_PER_SECOND);
//  }
//}


void changestyle() {

  ChangePalettePeriodically();

  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  FillLEDsFromPaletteColors( startIndex);

}
void displayled() {
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

//=====================================================
void yangshi_hongwai()
{

}


//====================================================================
void yangshi6()
{
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(100);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(100);
}

//====================================


void Fire2012()
{
  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS_HUO];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < HUOYANSHIJIAN; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS_HUO) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = NUM_LEDS_HUO - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < NUM_LEDS_HUO; j++) {
    CRGB color = HeatColor( heat[j]);
    int pixelnumber;
    if ( gReverseDirection ) {
      pixelnumber = (NUM_LEDS_HUO - 1) - j;
    } else {
      pixelnumber = j;
    }
    leds1[pixelnumber] = color;
  }
}


void yangshi_huoyan()
{
  int i;
  for (i = 0; i < HUOYANSHIJIAN; i++)
  {

    Fire2012(); // run simulation frame

    FastLED.show(); // display this frame
    FastLED.delay(1000 / FRAMES_PER_SECOND);
  }
}
//========================================
