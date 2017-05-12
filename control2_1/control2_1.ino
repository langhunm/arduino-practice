#include <FastLED.h>


#define LED_PIN     11
#define NUM_LEDS    120
#define NUM_LEDS1    60
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
bool inita;
#define UPDATES_PER_SECOND 100



bool start;
bool hongwai;
int counter;
unsigned long time_isr;
unsigned long time_isr_Start;
//==========================================================================================
/*
   去抖动思路

   如果时间够长 就讲hongwai置真


*/
//void zhixing(int style) {
//  Serial.println(style);
//}
void hongwaiInter() {

  unsigned long time_isr_tmp;
  unsigned long time_isr_tmp1 = millis();
  time_isr_tmp =  time_isr_tmp1 - time_isr;
  time_isr = time_isr_tmp1;
  //  delay(300);
  //  Serial.println("hongwai:");
  //  delay(300);
  //  Serial.println(time_isr_tmp);
  if (time_isr_tmp > 200)
  {
    //    hongwai = true;
    //    //    zhixing(5);
    Serial.println("hw sucessfull!");

    //    while (1) {
    //    yangshi7();
    hongwai = true;
    Serial.println("zhongduan neirong!");
    //    }
    //    //    delay(1000000);
  }
  //  //  digitalWrite(2, LOW);
}
//====================================================================
void yangshi6()
{
//  Serial.println("zhongduan neirong!");
  if (inita) {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  }
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}
//===========================================



#define FRAMES_PER_SECOND 60

bool gReverseDirection = false;




void yangshi7()
{
  // Add entropy to random number generator; we use a lot of it.
  // random16_add_entropy( random());
  //  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  int i;
  for (i = 0; i < NUM_LEDS; i++) {
    Fire2012(); // run simulation frame

    FastLED.show(); // display this frame
    FastLED.delay(1000 / FRAMES_PER_SECOND);
  }
}


// Fire2012 by Mark Kriegsman, July 2012
// as part of "Five Elements" shown here: http://youtu.be/knWiGsmgycY
////
// This basic one-dimensional 'fire' simulation works roughly as follows:
// There's a underlying array of 'heat' cells, that model the temperature
// at each point along the line.  Every cycle through the simulation,
// four steps are performed:
//  1) All cells cool down a little bit, losing heat to the air
//  2) The heat from each cell drifts 'up' and diffuses a little
//  3) Sometimes randomly new 'sparks' of heat are added at the bottom
//  4) The heat from each cell is rendered as a color into the leds array
//     The heat-to-color mapping uses a black-body radiation approximation.
//
// Temperature is in arbitrary units from 0 (cold black) to 255 (white hot).
//
// This simulation scales it self a bit depending on NUM_LEDS; it should look
// "OK" on anywhere from 20 to 100 LEDs without too much tweaking.
//
// I recommend running this simulation at anywhere from 30-100 frames per second,
// meaning an interframe delay of about 10-35 milliseconds.
//
// Looks best on a high-density LED setup (60+ pixels/meter).
//
//
// There are two main parameters you can play with to control the look and
// feel of your fire: COOLING (used in step 1 above), and SPARKING (used
// in step 3 above).
//
// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 50, suggested range 20-100
#define COOLING  55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 120


void Fire2012()
{
  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS1];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < NUM_LEDS1; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = NUM_LEDS1 - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < NUM_LEDS1; j++) {
    CRGB color = HeatColor( heat[j]);
    int pixelnumber;
    if ( gReverseDirection ) {
      pixelnumber = (NUM_LEDS1 - 1) - j;
    } else {
      pixelnumber = j;
    }
    leds[pixelnumber] = color;
  }
}



void setStart() {
  unsigned long time_isr_tmp2;
  unsigned long time_isr_tmp3 = millis();

  time_isr_tmp2 = time_isr_tmp3 - time_isr_Start;
  time_isr_Start = time_isr_tmp3;
  Serial.print("start:");
  Serial.println(time_isr_tmp2);
  if (time_isr_tmp2 > 200)
  {
    Serial.println("start sucessfull!");
    if (!start) {
      start = true;
    }
    else
      start = false;
    Serial.println(start);
  }

}

void setup() {
  start = false;
  hongwai = false;
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, hongwaiInter, HIGH);
  attachInterrupt(1, setStart, HIGH);
  time_isr = millis();
  time_isr_Start = millis();
  inita = false;


  //  delay( 200 ); // power-up safety delay
  FastLED.setBrightness(  BRIGHTNESS );
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
  if (start) {
    if (!hongwai) {
      yangshi6();
    }
    else {
      yangshi7();
      hongwai=false;
    }

  }
}
