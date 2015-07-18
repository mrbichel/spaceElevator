


void Ring() // Ring
{

  for(int x = 0; x < NUM_STRIPS; x++) {
    leds[x][time % NUM_LEDS_PER_STRIP] = CRGB::White;                                 
  }
    
}




void Spiral() 
{

  for(int x = 0; x < NUM_STRIPS; x++) {
    int s = (time/4+x) % NUM_LEDS_PER_STRIP;
    if(s < NUM_LEDS_PER_STRIP) leds[x][s] = CRGB::Blue;
  }
  
  for(int x = 0; x < NUM_STRIPS; x++) {
    int s = (time/4+x) % NUM_LEDS_PER_STRIP;
    if(s+s < NUM_LEDS_PER_STRIP) leds[x][s+s] = CRGB::Blue;
  }
  
  for(int x = 0; x < NUM_STRIPS; x++) {
    int s = (time/4+x) % NUM_LEDS_PER_STRIP;
    if(s+s+s < NUM_LEDS_PER_STRIP) leds[x][s+s+s] = CRGB::Blue;
  }
  
  /*int s = (time/4) % NUM_LEDS_FLOOR;    
  ledsFloor[s] = CRGB::Blue;
  if(s+s<NUM_LEDS_FLOOR-1) ledsFloor[s+s] = CRGB::Blue;
  if(s+s+s<NUM_LEDS_FLOOR-1) ledsFloor[s+s+s] = CRGB::Blue;
  //if(s+s+s+s<NUM_LEDS_FLOOR-1) ledsFloor[s+s+s+s] = CRGB::Blue;
  
  for(int i = 0; i < NUM_LEDS_FLOOR; i++) {
  }*/
  
    
}



void Pulse() {

  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB(sin(time/2)*255);
    }
  }
  
  for(int i = 0; i < NUM_LEDS_FLOOR; i++) {
      ledsFloor[i] = CRGB(sin(time/2)*255);
  }
  

}


void Random() {

  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CHSV(random16(), sin(time/4.0f+i)*255, sin(time/4.0f)*255);
    }
  }
  
  for(int i = 0; i < NUM_LEDS_FLOOR; i++) {
      ledsFloor[i] = CHSV(random16(), sin(time/4.0f)*255, sin(time/4.0f+i)*255);
  }
}



void Rainbow() {

  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CHSV(sin(time/1.0f+i)*255, 200, 255);
    }
  }
  
  for(int i = 0; i < NUM_LEDS_FLOOR; i++) {
      ledsFloor[i] = CHSV(sin(time/1.0f+i)*255, 200, 255);
  }
}




void fillnoise8() {
  for(int i = 0; i < NUM_STRIPS; i++) {
    int ioffset = scale * i;
    for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {
      int joffset = scale * j;
      noise[i][j] = inoise8(noisex + ioffset,noisey + joffset,noisez);
    }
  }
  noisez += noiseSpeed;
}

void Noise() {
  
  static uint8_t ihue=0;
  fillnoise8();
  
  for(int x = 0; x < NUM_STRIPS; x++) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CHSV(noise[i][x],255,noise[x][i]);
    }
  }
  
  
  // use stuff from fire 
  
  for(int i = 0; i < NUM_LEDS_FLOOR; i++) {
      ledsFloor[i] = CHSV(noise[i/NUM_STRIPS/NUM_LEDS_PER_STRIP][i/NUM_STRIPS],255,noise[i/NUM_STRIPS/NUM_LEDS_PER_STRIP][i/NUM_STRIPS]);
  }
}

