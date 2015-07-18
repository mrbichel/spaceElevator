// MultipleStripsInOneArray - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up four NEOPIXEL strips on three
// different pins, each strip will be referring to a different part of the single led array

#include "FastLED.h"

#define NUM_STRIPS 7

#define NUM_LEDS_PER_STRIP 34
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS
#define FRAMES_PER_SECOND 60

#define NUM_LEDS_FLOOR 141

CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

CRGB ledsFloor[NUM_LEDS_FLOOR];

// noise settings
uint16_t noiseSpeed = 10; //20
uint8_t noise[NUM_STRIPS][NUM_LEDS_PER_STRIP];
// The 32bit version of our coordinates
static uint16_t noisex;
static uint16_t noisey;
static uint16_t noisez;
uint16_t scale = 111; //311

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  FastLED.addLeds<NEOPIXEL, 40>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 42>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 44>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 46>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 48>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 50>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 52>(leds[6], NUM_LEDS_PER_STRIP);
  
  FastLED.addLeds<NEOPIXEL, 6>(ledsFloor, NUM_LEDS_FLOOR);
  
  
  
  
  noisex = random16();
  noisey = random16();
  noisez = random16();
  
  
}
unsigned long time = 0;


unsigned long modeElapsedTime = 0;

int mode = 2; 
// 0 - Fire 
// 1 - Spiral
// 2 pulse
// buttonDown - startElevator

// 


void clear() {
  
  // clear  
  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Black;
    }
  }
  
  for(int i = 0; i < NUM_LEDS_FLOOR; i++) {
      ledsFloor[i] = CRGB::Black;
  }

}

void loop() {
  
  random16_add_entropy( random());  
  
  if(mode == 0) {
    
    clear();
    Fire2012(); // run simulation frame
    
    FastLED.delay(1000 / FRAMES_PER_SECOND);
  
  } else if (mode == 1) {
  
    clear();
    Spiral();
  
  } else if (mode == 2) {
  
    clear();
    Noise();
  
  }
  
  
    time++;

  
  
    FastLED.show();
    //FastLED.delay(1000 / FRAMES_PER_SECOND); // better to have a draw function and check elapsed time maybe ? 
  
  
}



