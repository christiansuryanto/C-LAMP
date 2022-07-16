#ifndef PATTERNCODE_H
#define PATTERNCODE_H

#include "PatternDef.h"
#include "Control.h"

extern  uint16_t XYRev(uint8_t x, uint8_t y);
extern  uint16_t XY(uint8_t x, uint8_t y);
extern  eSPIFFS  filesystem;
extern  CRGB     activeLeds[NUM_LEDS];
extern  uint16_t getIndex( uint8_t x, uint8_t y);
void    extern   Cblur2d( CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount);

class NexusEffect 
{
  private:
    float dotPosX[nexusEntity];
    float dotPosY[nexusEntity];
    int8_t dotDirect[nexusEntity];
    CRGB dotColor[nexusEntity];
    float dotAccel[nexusEntity];
    bool white = false;
    byte type = 1;
    bool randColor = false;
    float windProgress;

    void reload();
    void resetDot(uint8_t idx);

  public:
    bool run(CRGB*);
    void load();
};

void runPattern(int pattern, CRGB *LEDArray);
void runPatternSpectrum(int pattern, int band, int barHeight, CRGB *LEDArray);
void greenColorSnap();
void redColorSnap();
void makeNFire(CRGB *LEDarray);
void solidColor(CRGB *LEDarray, double cHue);
void trailDown(CRGB *LEDarray);
void initFlame(CRGB *LEDarray);
void makeFlame(CRGB *LEDarray);
void initPaint(CRGB *LEDarray);
void makePaint(CRGB *LEDarray);
void initSmoke(CRGB *LEDarray);
void makeSmoke(CRGB *LEDarray);
void initStar(CRGB *LEDarray);
void makeStar(CRGB *LEDarray);
void initSpinner(CRGB *LEDarray);
void makeSpinner(CRGB *LEDarray);
void nexus_drawPixelXYF_X(CRGB *LEDARRAY3, float x, uint16_t y, const CRGB &color);
void nexus_drawPixelXYF_Y(CRGB *LEDARRAY4, uint16_t x, float y, const CRGB &color);
void makeNEXUS(CRGB *LEDARRAY1);
void makePacifica1D(CRGB *LEDArray1);
void drawPacifica1D(CRGB *LEDArray2);
void pacifica1D_one_layer(CRGB *LEDArray3, CRGBPalette16& p, uint16_t cistart, uint16_t wavescale, uint8_t bri, uint16_t ioff, uint8_t brightness);
void pacifica1D_add_whitecaps(CRGB *LEDArray4);
void pacifica1D_deepen_colors(CRGB *LEDArray5);
void auroraSetCurrentPalette();
void auroraSetModeSettings(uint8_t Scale, uint8_t Speed);
void auroraSetSpeed(uint8_t Speed);
void auroraFillauroraMyPal16_2(uint8_t hue, bool isInvert);
void makeAurora(CRGB *LEDARRAY);
void drawPixelXY(CRGB *LEDARRAY1, int8_t x, int8_t y, CRGB color);
void boilSetCurrentPalette();
void boilSetModeSettings(uint8_t Scale, uint8_t Speed);
void boilSetScale(uint8_t Scale);
void makeBoil(CRGB *LEDARRAY);
void wfallSetModeSettings(uint8_t Scale, uint8_t Speed);
void wfallSetScale(uint8_t Scale);
void makeWFall(CRGB *LEDARRAY);
void rubikSetCurrentPalette();
void rubikSetModeSettings(uint8_t Scale, uint8_t Speed);
void rubikSetScale(uint8_t Scale);
void makeRubik(CRGB *LEDARRAY);
void blurScreen(fract8 blur_amount, CRGB *LEDARRAY6);
void lavaDrawPixelXY(int8_t x, int8_t y, CRGB color, CRGB *LEDARRAY3);
void drawPixelXYF(float x, float y, CRGB color, CRGB *LEDARRAY2);
void lavaSetModeSettings(uint8_t Scale, uint8_t Speed);
void LavaLampGetspeed(uint8_t l);
void drawBlob(uint8_t l, CRGB color, CRGB *LEDARRAY1);
void makeLava1(CRGB *LEDARRAY);
void rotateLamp(CRGB *LEDARRAY);
void initRadFire();
void makeRadFire(CRGB *LEDARRAY) ;
void BarberPole1(CRGB *LEDARRAY);
void BarberPole2(CRGB *LEDARRAY);
void BarberPole3(CRGB *LEDARRAY);
void makeLava2(CRGB *LEDARRAY);
void doSendVoxels(CRGB *LEDARRAY2);
void lava3_wu_pixelY(CRGB *LEDARRAY5, uint8_t x, uint32_t y, CRGB * col);
void doSendVoxelsV2(CRGB *LEDARRAY3);
void doLavaSend(CRGB *LEDARRAY4);
void makeLava3(CRGB *LEDARRAY1);
void dBars_wu_pixel(CRGB *LEDARRAY3, uint32_t x, uint32_t y, CRGB * col);
void dBars_DrawBar(CRGB *LEDARRAY2, byte value, byte minimum, byte maximum, byte pos, CRGB color, bool Vert);
void runAllDBars(CRGB *LEDARRAY5);
void makeDBars(CRGB *LEDARRAY6);
void drawDBars1(CRGB *LEDARRAY1);
void drawDBars2(CRGB *LEDARRAY4);
void hypChangeHue(bool isUp);
void makeHyp(CRGB *LEDARRAY);
void colorwaves(CRGB* ledarray, uint16_t numLeds, CRGBPalette16& palette);
void makeCW(CRGB *LEDARRAY1);
void snovaChangeHue();
void snovaDrawPixelXY(CRGB *LEDARRAY3, int8_t x, int8_t y, CRGB color);
void snovaDrawPixelXYF(CRGB *LEDARRAY2, float x, float y, CRGB color);
void snovaParticlesUpdate(uint8_t i);
void snovaStarfieldEmit(uint8_t i);
void initsnova();
void makesnova(CRGB *LEDARRAY1);
void makeFire2(CRGB *LEDARRAY1);
void runAllFire2(CRGB *LEDARRAY20);
void drawFire21(CRGB *LEDARRAY21);
void drawFire22(CRGB *LEDARRAY22);
void makePPlasma(CRGB *LEDarray);
void makeEasing(CRGB *LEDarray);
void makeAABar(CRGB *LEDarray);
void drawAABar(CRGB *LEDarray, int pos16, int width, uint8_t hue);
void initKerosene();
void drawKerosene(CRGB *LEDarray, CRGBPalette16& palette, uint8_t brightness);
void makeKerosene(CRGB *LEDarray);
void setDeltahue();
void setRandomPalette();
void initRandomColor();
void randomColorChangePalette(CRGB *LEDarray);
void drawRandomColor(CRGB *LEDarray, uint8_t brightness);
void makeRandomColor(CRGB *LEDarray);
void makePride(CRGB *LEDarray) ;
void make_softtwinkles(CRGB *LEDARRAY1);
void draw_softtwinkles(CRGB *LEDARRAY2);
void rainbowBars(CRGB *LEDarray, int band, int barHeight);
void configBars(CRGB *LEDarray, int band, int barHeight);
void whitePeak(CRGB *LEDarray, int band);
void outrunPeak(CRGB *LEDarray, int band);
void purpleBars(CRGB *LEDarray, int band, int barHeight);
void centerBars(CRGB *LEDarray, int band, int barHeight);
void sideBars(CRGB *LEDarray, int band, int barHeight);
void changingBars(CRGB *LEDarray, int band, int barHeight);
void WFallSR(CRGB *LEDarray, int band);


// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //

uint8_t flameSR;
uint8_t flameOldSR = 0;

void runPattern(int pattern, CRGB *LEDArray)
{
  pattern = abs(pattern);
    switch (pattern) 
    {
      case idxBoil:
        makeBoil(LEDArray);
        break;
      
      case idxNFire:
        makeNFire(LEDArray);
        break;
      
      case idxSolidColor:
        solidColor(LEDArray, currentSolidHue);
        break;
      
      case idxTrailDown:
        trailDown(LEDArray);
        //SR inside pattern subroutine
        break;
      
      case idxFlame:
        if (isGlobalAudioReactive) 
        {
          flameSR = pow(constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 1, (currentBrightness+currentBrightness+maxBrightness)/3), 1, (currentBrightness+currentBrightness+maxBrightness)/3), 2);
          if (audioSampleAvg > 0)
          {
            if (!enableWifi) flameSR = ((flameOldSR*1) + flameSR)/2;
            else flameSR = ((flameOldSR*1)+flameSR)/2;
          }
          emitterFlame.minLife = 1;
          emitterFlame.maxLife = flameSR;
        }
        else
        {  
          emitterFlame.minLife = 10;
          emitterFlame.maxLife = 180;
        }
        makeFlame(LEDArray);
        if (isGlobalAudioReactive) flameOldSR = flameSR;
        break;
      
      case idxPaint:
        if (isGlobalAudioReactive) 
        {
            emitterPaint.minLife = emitterPaint.maxLife = constrain(audioSampleAvg*currentGVolume*3, 0, 254);
          //Serial.print(audioSampleAvg); Serial.print(" - "); Serial.println(emitterPaint.minLife);
        }
        else
          emitterPaint.minLife = emitterPaint.maxLife = 150;
        makePaint(LEDArray);
        break;
      
      case idxSmoke:
        makeSmoke(LEDArray);
        // SR inside pattern subroutine
        break;
      
      case idxStar:
        if (isGlobalAudioReactive) 
        {
          if (audioSampleAvg*currentGVolume >= 140)
          {
            emitterStar.minLife = constrain(audioSampleAvg*currentGVolume, 0, 50);
            emitterStar.maxLife = constrain(audioSampleAvg*currentGVolume*2, 0, 254);
          }
          else
          {  
            emitterStar.minLife = 1;
            emitterStar.maxLife = 5;
          }
        }
        else
        {  
          emitterStar.minLife = 50;
          emitterStar.maxLife = 250;
        }
        makeStar(LEDArray);
        break;
      
      case idxSpinner:
        makeSpinner(LEDArray);
        // SR inside pattern subroutine
        break;
      
      case idxNexus:
        makeNEXUS(LEDArray);
        break;

      case idxPacifica1D:
        makePacifica1D(LEDArray);
        //SR inside pattern subroutine
        break;
      
      case idxPPlasma:
        makePPlasma(LEDArray);
        //SR inside pattern routine
        break;
      
      case idxEasing:
        makeEasing(LEDArray);
        //SR inside pattern routine
        break;
      
      case idxAABar:
        makeAABar(LEDArray);
        break;
      
      case idxKerosene:
        makeKerosene(LEDArray);
        break;
      
      case idxRandomColor:
        makeRandomColor(LEDArray);
        break;

      case idxPride:
        makePride(LEDArray);
        break;
      
      case idxPre1STW:
        clearLED(LEDArray);
        break;
      
      case idxPre2STW:
        clearLED(LEDArray);
        break;
      
      case idxSoftTwinkles:
        make_softtwinkles(LEDArray);
        break;

      case idxPost2STW:
        clearLED(LEDArray);
        break;
      
      case idxPost1STW:
        clearLED(LEDArray);
        break;
      
      case idxAurora:
        makeAurora(LEDArray);
        break;
      
      case idxWFall:
        makeWFall(LEDArray);
        break;
      
      case idxRubik:
        makeRubik(LEDArray);
        break;
      
      case idxLava1:
        makeLava1(LEDArray);
        break;
      
      case idxRotateLamp:
        rotateLamp(LEDArray);
        break;
      
      case idxRadFire:
        makeRadFire(LEDArray);
        break;
      
      case idxBarberPole1:
        BarberPole1(LEDArray);
        break;
      
      case idxBarberPole2:
        BarberPole2(LEDArray);
        break;
      
      case idxBarberPole3:
        BarberPole3(LEDArray);
        break;
      
      case idxLava2:
        makeLava2(LEDArray);
        break;
      
      case idxLava3:
        makeLava3(LEDArray);
        break;
      
      case idxDrawBars:
        makeDBars(LEDArray);
        break;
      
      case idxColorWaves:
        makeCW(LEDArray);
        break;

      case idxRGBHype:
        makeHyp(LEDArray);
        break;

      case idxSNova:
        makesnova(LEDArray);
        break;

      case idxFire2:
        makeFire2(LEDArray);
        break;

      case idxBLANK1:
        //clearLED(LEDArray);
        blankPattern(LEDArray);
        break;
    }
}


void runPatternSpectrum(int pattern, int band, int barHeight, CRGB *LEDArray)
{
  pattern = abs(pattern);
    switch (pattern) 
    {
      case idxBLANK1:
        //clearLED(LEDArray);
        blankPattern(LEDArray);
        break;
      case idxConfigBars:
        configBars(LEDArray, band, barHeight);
        break;
      case idxRainbowBars:
        whitePeak(LEDArray, band);
        rainbowBars(LEDArray, band, barHeight);
        break;
      case idxOutrun:
        outrunPeak(LEDArray, band);
        break;
      case idxPurpleBars:
        whitePeak(LEDArray, band);
        purpleBars(LEDArray, band, barHeight);
        break;
      case idxCenterBars:
        centerBars(LEDArray, band, barHeight);
        break;
      case idxSideBars:
        sideBars(LEDArray, band, barHeight);
        break;
      case idxChangingBars:
        changingBars(LEDArray, band, barHeight);
        break;
      case idxWFallSR:
        WFallSR(LEDArray, band);
        break;
    }
}
void greenColorSnap()
{
  for (int i = 0; i < NUM_LEDS; i++) activeLeds[i] = CRGB(40, 140, 45);
  for (double j = 2; j<currentBrightness; j*=1.1)
  {
    FastLED.setBrightness(j);
    FastLED.show();
    delay(10);
  }
  delay(2000);
  for (double j = currentBrightness; j> 0.2; j/=1.3)
  {
    FastLED.setBrightness(j);
    FastLED.show();
    delay(10);
  }
  FastLED.clear();
}


void redColorSnap() 
{
  for (int i = 0; i < NUM_LEDS; i++) activeLeds[i] = CRGB(140, 40, 40);
  for (double j = 2; j<currentBrightness; j*=1.1)
  {
    FastLED.setBrightness(j);
    FastLED.show();
    delay(10);
  }
  delay(2000);
  for (double j = currentBrightness; j> 0.2; j/=1.3)
  {
    FastLED.setBrightness(j);
    FastLED.show();
    delay(10);
  }
  FastLED.clear();
}


// PATTERNS BELOW //
uint8_t nfireSR;
uint8_t nfireOldSR = 0;
void makeNFire(CRGB *LEDarray)
{
  int  a = millis();
  double cHue;
  CHSV hsv;
  
  EVERY_N_MILLIS(intervalNFireHue)
  {
    if ((nfireAutoHue) && (!isLEDOFF)) HuePalUpAuto();
  }

  if (currentEffect == idxNFire && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    nfireSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 5, (currentBrightness+currentBrightness+maxBrightness)/3);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) nfireSR = ((nfireOldSR*2)+ nfireSR)/3;
      else nfireSR = ((nfireOldSR*1)+nfireSR)/2;
    }
  }
  
  EVERY_N_MILLIS_I(timeObj8, 3*currentNFireDelay)
  {
    timeObj8.setPeriod(3*currentNFireDelay);
    for (int i = 0; i < kMatrixWidth; i++) 
    {
      for (int j = 0; j < kMatrixHeight; j++) 
      {
        uint16_t colorIndex = qsub8 (inoise8 (i * 60 , j * 60+ a , a /3), abs8(j - (kMatrixHeight-1)) * 255 / (kMatrixHeight-1));
  
        uint8_t Bri2;
        if (isGlobalAudioReactive)
          Bri2 = (nfireSR+currentBrightness)/2;
        else
          Bri2 = currentBrightness;
        hsv = rgb2hsv_precise(ColorFromPalette (gNFirePal, colorIndex, Bri2, LINEARBLEND) );
        
        cHue = hsv.h + currentNFireHue > 254 ? 255 - (hsv.h + currentNFireHue) : hsv.h + currentNFireHue;
        LEDarray[XY(i,j)] = CHSV(cHue, hsv.s, hsv.v);
      }
    }
    FastLED.show();
    if (isGlobalAudioReactive) nfireOldSR = nfireSR;
  }
  if (toSleep || toWakeUp) delay(33);
}

uint8_t solidColorSR;
uint8_t solidColorOldSR=0;
void solidColor(CRGB *LEDarray, double cHue)
{
  if (currentEffect == idxSolidColor && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    solidColorSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) solidColorSR = ((solidColorOldSR*7)+solidColorSR)/8;
      else solidColorSR = ((solidColorOldSR*1)+solidColorSR)/2;
    }
    FastLED.setBrightness(solidColorSR);
  }

  for (int i = 0; i < NUM_LEDS; i++) LEDarray[i] = CRGB(CHSV(cHue, currentSaturation*255, 255));
  if (toSleep || toWakeUp) delay(33); 
  FastLED.show();
  if (isGlobalAudioReactive) solidColorOldSR = solidColorSR;
}


void trailDown(CRGB *LEDarray)
{
  EVERY_N_MILLIS(intervalTrailHue)
  {
    if ((trailAutoHue) && (!isLEDOFF)) HuePalUpAuto();
  }

  EVERY_N_MILLIS_I(timeObj, currentTrailDelay) // falling speed
  {
    timeObj.setPeriod(currentTrailDelay);
    // move code downward
    // start with lowest row to allow proper overlapping on each column

    for (int8_t row=kMatrixHeight-1; row>=0; row--)
    {
      for (int8_t col=0; col<kMatrixWidth; col++)
      {
        if (LEDarray[getIndex(col, row)] == CRGB(trailColors[1]))
        {
          LEDarray[getIndex(col, row)] = CRGB(trailColors[0]); // create trail
          if (row < kMatrixHeight-1) LEDarray[getIndex(col, row+1)] = CRGB(trailColors[1]);
        }
      }
    }

    // fade all leds
    for(int i = 0; i < NUM_LEDS; i++) {
      if (LEDarray[i].g != 255) LEDarray[i].nscale8(192); // only fade trail
    }

    // check for empty screen to ensure code spawn
    bool emptyScreen = true;
    for(int i = 0; i < NUM_LEDS; i++) 
    {
      if (LEDarray[i])
      {
        emptyScreen = false;
        break;
      }
    }

    //DIY PREAMP MIC
    if ((isGlobalAudioReactive && random8(1000/(audioSampleAvg*currentGVolume)) == 0 ) || (!isGlobalAudioReactive && (random8(3) == 0 || emptyScreen))) // lower number == more frequent spawns
    {
      int8_t spawnX = random8(kMatrixWidth);
      LEDarray[getIndex(spawnX, 0)] = CRGB(trailColors[1]);
    }
    FastLED.show();
  }
  //FastLED.show();
  if (isPaused) { delay(pauseDelay); isPaused = false; }
  if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}


void initFlame(CRGB *LEDarray)
{
  rendererFlame.reset(LEDarray);
  sourceFlame.x = gFlame.center_x;
  sourceFlame.y = gFlame.max_y-(gFlame.res_y/2);
  Particle_Std::ay = -1;
  pSysFlame.perCycle = 40;
  emitterFlame.minLife = 10;
  emitterFlame.maxLife = 180;
  emitterFlame.baseHue = currentFlameHue;   //color
}

void makeFlame(CRGB *LEDarray)
{
    EVERY_N_MILLIS_I(timeObj, 200)
    {
      timeObj.setPeriod(intervalFlameHue);
      if ((flameAutoHue) && (!isLEDOFF))
      {
          currentFlameHue+=stepFlameHue;
          if (currentFlameHue >= maxFlameHue) currentFlameHue = minFlameHue;
          emitterFlame.baseHue = currentFlameHue;
      }
    }
    
    EVERY_N_MILLIS_I(timeObj2, 3*currentFlameDelay)
    {
      timeObj2.setPeriod(3*currentFlameDelay);
      pSysFlame.update();
      rendererFlame.reset(LEDarray);
      rendererFlame.render(&gFlame, particlesFlame, numParticlesFlame, LEDarray);
      //FastLED.show();
      //delay(currentFlameDelay);
      FastLED.show();
    }
    //FastLED.show();
    if (toSleep || toWakeUp) delay(33);
}


void initPaint(CRGB *LEDarray)
{
  rendererPaint.reset(LEDarray);
  sourcePaint.vx = 1;
  sourcePaint.vy = 5;
  sourcePaint.x = 10;
  sourcePaint.y = 10;
  emitterPaint.minLife = 150;
  emitterPaint.maxLife = 150;
  emitterPaint.baseHue = currentPaintHue;   //color
}

void makePaint(CRGB *LEDarray)
{
    EVERY_N_MILLIS_I(timeObj, 200)
    {
      timeObj.setPeriod(intervalPaintHue);
      if (paintAutoHue)
      {
        currentPaintHue+=stepPaintHue;
        if (currentPaintHue >= maxPaintHue) currentPaintHue = minPaintHue;
        emitterPaint.baseHue = currentPaintHue;
      }
    }
    
    EVERY_N_MILLIS_I(timeObj3, 3*currentPaintDelay)
    {
      timeObj3.setPeriod(3*currentPaintDelay);
      pSysPaint.update();
      rendererPaint.reset(LEDarray);
      rendererPaint.render(&gPaint, particlesPaint, numParticlesPaint, LEDarray);
      FastLED.show();
      //delay(currentPaintDelay);
    }
    if (toSleep || toWakeUp) delay(33);
}

void initSmoke(CRGB *LEDarray)
{
  rendererSmoke.reset(LEDarray);
  sourceSmoke.vx = 1;
  sourceSmoke.vy = 3;
  sourceSmoke.y = random(50)+100;
  sourceSmoke.x = random(10)+1;
  sourceSmoke.atf = 2;
  emitterSmoke.minLife = 100;
  emitterSmoke.maxLife = 200;
  pSysSmoke.perCycle = 2;
  emitterSmoke.baseHue = currentSmokeHue;   //color
}

uint16_t smokeSR;
uint16_t smokeOldSR=0;
void makeSmoke(CRGB *LEDarray)
{
    if (currentEffect==idxSmoke && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
        smokeSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) smokeSR = ((smokeOldSR*5)+smokeSR)/6;
        else smokeSR = ((smokeOldSR*3)+smokeSR)/4;
      }
      FastLED.setBrightness(smokeSR);
    }

    EVERY_N_MILLIS_I(timeObj, 200)
    {
      timeObj.setPeriod(intervalSmokeHue);
      if (smokeAutoHue)
      {
        currentSmokeHue+=stepSmokeHue;
        if (currentSmokeHue >= maxSmokeHue) currentSmokeHue = minSmokeHue;
        emitterSmoke.baseHue = currentSmokeHue;
      }
    }
    
    EVERY_N_MILLIS_I(timeObj4, 3*currentSmokeDelay)
    {
      timeObj4.setPeriod(3*currentSmokeDelay);
      pSysSmoke.update();
      rendererSmoke.reset(LEDarray);
      rendererSmoke.render(&gSmoke, particlesSmoke, numParticlesSmoke, LEDarray);
      FastLED.show();
      //delay(currentSmokeDelay);
    }
    //FastLED.show();
    if (isGlobalAudioReactive) smokeOldSR = smokeSR;
    if (toSleep || toWakeUp) delay(33);
}

void initStar(CRGB *LEDarray)
{
  rendererStar.reset(LEDarray);
  emitterStar.baseHue = currentStarHue;   //color
}

void makeStar(CRGB *LEDarray)
{
    EVERY_N_MILLIS_I(timeObj, 200)
    {
      timeObj.setPeriod(intervalStarHue);
      if (starAutoHue)
      {
        currentStarHue+=stepStarHue;
        if (currentStarHue >= maxStarHue) currentStarHue = minStarHue;
        emitterStar.baseHue = currentStarHue;
      }
    }
    
    EVERY_N_MILLIS_I(timeObj5, 3*currentStarDelay)
    {
      timeObj5.setPeriod(3*currentStarDelay);
      pSysStar.update();
      rendererStar.fade(LEDarray);
      rendererStar.render(&gStar, particlesStar, numParticlesStar, LEDarray);
      FastLED.show();
      //delay(currentStarDelay);
    }
    if (toSleep || toWakeUp) delay(33);
}


void initSpinner(CRGB *LEDarray)
{
  rendererSpinner.reset(LEDarray);
  emitterSpinner.oscilate = true;
  emitterSpinner.baseHue = currentSpinnerHue;   //color
}

uint8_t spinnerSR;
uint8_t spinnerOldSR = 0;
void makeSpinner(CRGB *LEDarray)
{
    if (currentEffect==idxSpinner && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
        spinnerSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) spinnerSR = ((spinnerOldSR*4)+spinnerSR)/5;
        else spinnerSR = ((spinnerOldSR*3)+spinnerSR)/4;
      }
      FastLED.setBrightness(spinnerSR);
    }

    EVERY_N_MILLIS_I(timeObj, intervalSpinnerHue)
    {
      timeObj.setPeriod(intervalSpinnerHue);
      if (spinnerAutoHue)
      {
        currentSpinnerHue+=stepSpinnerHue;
        if (currentSpinnerHue >= maxSpinnerHue) currentSpinnerHue = minSpinnerHue;
        emitterSpinner.baseHue = currentSpinnerHue;
      }
    }
    
    EVERY_N_MILLIS_I(timeObj6, 3*currentSpinnerDelay)
    {
      timeObj6.setPeriod(3*currentSpinnerDelay);
      pSysSpinner.update();
      rendererSpinner.fade(LEDarray);
      rendererSpinner.render(&gSpinner, particlesSpinner, numParticlesSpinner, LEDarray);
      FastLED.show();
      //delay(currentSpinnerDelay);
    }
    //FastLED.show();
    if (isGlobalAudioReactive) spinnerOldSR = spinnerSR;
    if (toSleep || toWakeUp) delay(33);
}

// NEXUS CODES //
uint8_t nexusSR;
uint8_t nexusOldSR = 0;

double nexusFMAP(const double x, const double in_min, const double in_max, const double out_min, const double out_max)
{
  return (out_max - out_min) * (x - in_min) / (in_max - in_min) + out_min;
}

void nexus_drawPixelXYF_X(CRGB *LEDARRAY3, float x, uint16_t y, const CRGB &color)
{
  if (x<0 || y<0 || x>((float)kMatrixWidth) || y>((float)kMatrixHeight)) return;
  uint8_t xx = (x - (int)x) * 255, ix = 255 - xx;
  uint8_t wu[2] = {ix, xx};
  for (int8_t i = 1; i >= 0; i--) {
      int16_t xn = x + (i & 1);
      CRGB clr = LEDARRAY3[XY(xn, y)];
      if(xn>0 && xn<(int)kMatrixWidth-1){
        clr.r = qadd8(clr.r, (color.r * wu[i]) >> 8);
        clr.g = qadd8(clr.g, (color.g * wu[i]) >> 8);
        clr.b = qadd8(clr.b, (color.b * wu[i]) >> 8);
      } else if(xn==0 || xn==(int)kMatrixWidth-1) {
        clr.r = qadd8(clr.r, (color.r * 85) >> 8);
        clr.g = qadd8(clr.g, (color.g * 85) >> 8);
        clr.b = qadd8(clr.b, (color.b * 85) >> 8);
      }
      LEDARRAY3[XY(xn, y)]= clr;
  }
}

void nexus_drawPixelXYF_Y(CRGB *LEDARRAY4, uint16_t x, float y, const CRGB &color)
{
  if (x<0 || y<0 || x>((float)kMatrixWidth) || y>((float)kMatrixHeight)) return;

  uint8_t yy = (y - (int)y) * 255, iy = 255 - yy;
  uint8_t wu[2] = {iy, yy};
  for (int8_t i = 1; i >= 0; i--) 
  {
      int16_t yn = y + (i & 1);
      CRGB clr = LEDARRAY4[XY(x, yn)];
      if(yn>0 && yn<(int)kMatrixHeight-1)
      {
        clr.r = qadd8(clr.r, (color.r * wu[i]) >> 8);
        clr.g = qadd8(clr.g, (color.g * wu[i]) >> 8);
        clr.b = qadd8(clr.b, (color.b * wu[i]) >> 8);
      } 
      else if(yn==0 || yn==(int)kMatrixHeight-1) 
      {
        clr.r = qadd8(clr.r, (color.r * 85) >> 8);
        clr.g = qadd8(clr.g, (color.g * 85) >> 8);
        clr.b = qadd8(clr.b, (color.b * 85) >> 8);
      }
    LEDARRAY4[XY(x, yn)] = clr;
  }
}

//class NexusEffect 
//{
//  private:
//    float dotPosX[nexusEntity];
//    float dotPosY[nexusEntity];
//    int8_t dotDirect[nexusEntity];
//    CRGB dotColor[nexusEntity];
//    float dotAccel[nexusEntity];
//    bool white = false;
//    byte type = 1;
//    bool randColor = false;
//    float windProgress;
//
//    void reload();
//    void resetDot(uint8_t idx);
//
//  public:
//    bool run(CRGB*);
//    void load();
//};


void NexusEffect::reload()
{
  for (byte i = 0; i < nexusEntity; i++) 
  {
    dotDirect[i] = random(0, 4);
    dotPosX[i] = random(0, kMatrixWidth);
    dotPosY[i] = random(0, kMatrixHeight);
    dotColor[i] = ColorFromPalette(RainbowColors_p, random8(0, 9) * 31, 255);
    dotAccel[i] = (float)random(5, 11) / 70;
  }
}

void NexusEffect::load()
{
  randomSeed(millis());
  reload();
}

bool NexusEffect::run(CRGB *LEDARRAY2) 
{
  float speedfactor = nexusFMAP(nexusSpeed, 1, 255, 0.1, .33);

  fadeToBlackBy(LEDARRAY2, NUM_LEDS, map(nexusSpeed, 1, 255, 16, 22));

  uint8_t nScale;
  if (isGlobalAudioReactive)
    nScale = nexusSR;
  else
    nScale = currentNexusScale;
    
  for (byte i = 0; i < map(nScale, 1, 255, 1, nexusEntity); i++) 
  {
    switch (dotDirect[i])
    {
    case 0:
      dotPosY[i] += (speedfactor + dotAccel[i]);
      break;
    case 1:
      dotPosY[i] -= (speedfactor + dotAccel[i]);
      break;
    case 2:
      dotPosX[i] += ((0.2*speedfactor) + dotAccel[i]);
      break;
    case 3:
      dotPosX[i] -= ((0.2*speedfactor) + dotAccel[i]);
      break;
    default:
      break;
    } 

    if (dotPosY[i] < 0) 
    {
      dotPosY[i] = (float)kMatrixHeight - 1.;    
      resetDot(i);
    }

    if (dotPosY[i] > (kMatrixHeight - 1)) 
    {
      dotPosY[i] = 0;
      resetDot(i);
    }

    if (dotPosX[i] < 0) 
    {
      dotPosX[i] = (kMatrixWidth - 1);
      resetDot(i);
    }
    if (dotPosX[i] > (kMatrixWidth - 1)) 
    {
      dotPosX[i] = 0;
      resetDot(i);
    }

    switch (dotDirect[i])
    {
    case 0:
    case 1:
      nexus_drawPixelXYF_Y(LEDARRAY2, dotPosX[i], dotPosY[i], dotColor[i]);
      break;
    case 2:
    case 3:
      nexus_drawPixelXYF_X(LEDARRAY2, dotPosX[i], dotPosY[i], dotColor[i]);
      break;
    default:
      break;
    } 
  }
  //fpsmeter();
  return true;
}

void NexusEffect::resetDot(uint8_t idx)
{
  randomSeed(micros());
  dotDirect[idx] = random8(0, 4);
  
  //dotColor[idx] = ColorFromPalette(RainbowColors_p, random(0, 9) * 31, 255);
  dotColor[idx] = ColorFromPalette(nexusCurrentPalette, random(0, 9) * 31, currentBrightness);
  
  dotAccel[idx] = (float)random(5, 10) / 70;
  switch (dotDirect[idx])
  {
  case 0:
    dotPosX[idx] = random8(0, kMatrixWidth);
    dotPosY[idx] = 0;
    break;
  case 1:
    dotPosX[idx] = random8(0, kMatrixWidth);
    dotPosY[idx] = kMatrixHeight-1;
    break;
  case 2:
    dotPosX[idx] = 0;
    dotPosY[idx] = random8(0, kMatrixHeight);
    break;
  case 3:
    dotPosX[idx] = kMatrixWidth-1;
    dotPosY[idx] = random8(0, kMatrixHeight);
    break;
  default:
    break;
  } 
}


NexusEffect NEXUS;

void makeNEXUS(CRGB *LEDARRAY1)
{
  if (currentEffect == idxNexus && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    nexusSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, 250), 0, 250);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) nexusSR = ((nexusOldSR*2)+nexusSR)/3;
      else nexusSR = ((nexusOldSR*2)+nexusSR)/3;
    }
    //FastLED.setBrightness(SR);
  }

  if (nexusAutoPalette)
  {
    EVERY_N_SECONDS(20)
    {
      nexusChangePalette(true);
    }
  }

  EVERY_N_MILLISECONDS(40) 
  {
    nblendPaletteTowardPalette(nexusCurrentPalette, nexusTargetPalette, 30);
  }

  if (nexusLoading) NEXUS.load(), nexusLoading = false;
  if (nexusBG)
    for (uint16_t i =0; i< NUM_LEDS; i++) LEDARRAY1[i] += CRGB(0, 2, 6);
  EVERY_N_MILLIS_I(timeObj, currentNexusDelay)
  {
    timeObj.setPeriod(currentNexusDelay);
    NEXUS.run(LEDARRAY1);
    //delay(16); // ~= 60FPS
  }
  FastLED.show();
  if (isGlobalAudioReactive) nexusOldSR = nexusSR;
}
// EOF NEXUS CODES //



// PACIFICA1D START //
void makePacifica1D(CRGB *LEDArray1)
{
  if (!isLEDOFF)
  {
    EVERY_N_MILLISECONDS_I(timeObj, currentPacifica1DDelay) 
    {
      timeObj.setPeriod(currentPacifica1DDelay);
      drawPacifica1D(LEDArray1);
      FastLED.show();
    }
  }
  if (toSleep || toWakeUp) delay(33);
  //FastLED.show();
}

uint8_t pacifica1DSR;
uint8_t pacifica1DOldSR = 0;
void drawPacifica1D(CRGB *LEDArray2)
{
  if (currentEffect == idxPacifica1D && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    pacifica1DSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
    if (audioSampleAvg > 0)
    {
      if (!enableWifi) pacifica1DSR = ((pacifica1DOldSR*2) + pacifica1DSR)/3;
      else pacifica1DSR = ((pacifica1DOldSR*1)+pacifica1DSR)/2;
    }
    //FastLED.setBrightness(pacifica1DSR);
  }
  
  // Increment the four "color index start" counters, one for each wave layer.
  // Each is incremented at a different speed, and the speeds vary over time.
  static uint16_t sCIStart1, sCIStart2, sCIStart3, sCIStart4;
  static uint32_t sLastms = 0;
  uint32_t ms = GET_MILLIS();
  uint32_t deltams = ms - sLastms;
  sLastms = ms;
  uint16_t speedfactor1 = beatsin16(3, 179, 269);
  uint16_t speedfactor2 = beatsin16(4, 179, 269);
  uint32_t deltams1 = (deltams * speedfactor1) / 256;
  uint32_t deltams2 = (deltams * speedfactor2) / 256;
  uint32_t deltams21 = (deltams1 + deltams2) / 2;
  sCIStart1 += (deltams1 * beatsin88(1011,10,13));
  sCIStart2 -= (deltams21 * beatsin88(777,8,11));
  sCIStart3 -= (deltams1 * beatsin88(501,5,7));
  sCIStart4 -= (deltams2 * beatsin88(257,4,6));

  // Clear out the LED array to a dim background blue-green
  fill_solid( LEDArray2, NUM_LEDS, CRGB( 2, 6, 10));

  // Render each of four layers, with different scales and speeds, that vary over time
  pacifica1D_one_layer(LEDArray2, pacifica1D_palette_1, sCIStart1, beatsin16( 3, 11 * 256, 14 * 256), beatsin8( 10, 70, 130), 0-beat16( 301), pacifica1DSR);
  pacifica1D_one_layer(LEDArray2, pacifica1D_palette_2, sCIStart2, beatsin16( 4,  6 * 256,  9 * 256), beatsin8( 17, 40,  80), beat16( 401), pacifica1DSR);
  pacifica1D_one_layer(LEDArray2, pacifica1D_palette_3, sCIStart3, 6 * 256, beatsin8( 9, 10,38), 0-beat16(503), pacifica1DSR);
  pacifica1D_one_layer(LEDArray2, pacifica1D_palette_3, sCIStart4, 5 * 256, beatsin8( 8, 10,28), beat16(601), pacifica1DSR);

  // Add brighter 'whitecaps' where the waves lines up more
  pacifica1D_add_whitecaps(LEDArray2);

  // Deepen the blues and greens a bit
  pacifica1D_deepen_colors(LEDArray2);

  //SOUND REACTIVE HERE
  if (isGlobalAudioReactive) pacifica1DOldSR = pacifica1DSR;
}

// Add one layer of waves into the led array
void pacifica1D_one_layer(CRGB *LEDArray3, CRGBPalette16& p, uint16_t cistart, uint16_t wavescale, uint8_t bri, uint16_t ioff, uint8_t brightness)
{
  uint16_t ci = cistart;
  uint16_t waveangle = ioff;
  uint16_t wavescale_half = (wavescale / 2) + 20;
  for( uint16_t i = 0; i < NUM_LEDS; i++) {
    waveangle += 250;
    uint16_t s16 = sin16( waveangle ) + 32768;
    uint16_t cs = scale16( s16 , wavescale_half ) + wavescale_half;
    ci += cs;
    uint16_t sindex16 = sin16( ci) + 32768;
    uint8_t sindex8 = scale16( sindex16, 240);

    uint16_t bri2;
    
    if (isGlobalAudioReactive)
      bri2 = (brightness+bri)/2;
    else
      bri2 = bri;
    
    CRGB c = ColorFromPalette( p, sindex8, bri2, LINEARBLEND);
    LEDArray3[i] += c;
  }
}

// Add extra 'white' to areas where the four layers of light have lined up brightly
void pacifica1D_add_whitecaps(CRGB *LEDArray4)
{
  uint8_t basethreshold = beatsin8( 9, 55, 65);
  uint8_t wave = beat8( 7 );
  
  for( uint16_t i = 0; i < NUM_LEDS; i++) {
    uint8_t threshold = scale8( sin8( wave), 20) + basethreshold;
    wave += 7;
    uint8_t l = LEDArray4[i].getAverageLight();
    if( l > threshold) {
      uint8_t overage = l - threshold;
      uint8_t overage2 = qadd8( overage, overage);
      LEDArray4[i] += CRGB( overage, overage2, qadd8( overage2, overage2));
    }
  }
}

// Deepen the blues and greens
void pacifica1D_deepen_colors(CRGB *LEDArray5)
{
  for( uint16_t i = 0; i < NUM_LEDS; i++) 
  {
    LEDArray5[i].blue = scale8( LEDArray5[i].blue,  145); 
    LEDArray5[i].green= scale8( LEDArray5[i].green, 200); 
    LEDArray5[i] |= CRGB( 2, 5, 7);
  }
}
// PACIFICA1D END //


//AURORA CODES //
void auroraSetCurrentPalette()
{
      if (auroraScale > 100U) auroraScale = 100U;
      auroraCurPalette = auroraPalette_arr[(uint8_t)(auroraScale/100.0F*((sizeof(auroraPalette_arr)/sizeof(TProgmemRGBPalette16 *))-0.01F))];
}

void auroraSetModeSettings(uint8_t Scale, uint8_t Speed)
{
    auroraScale = Scale;
    auroraSpeed = Speed;
    auroraSelectedSettings = 0U;
}

void auroraSetSpeed(uint8_t Speed)
{
  auroraSpeed = Speed;
  auroraSelectedSettings = 0U;
}

CRGBPalette16 auroraMyPal;

// instead of a set of palettes in the original effect, a palette generator has been added
#define AURORA_COLOR_PERIOD 2 // (2 times per minute) the frequency with which the selected hue oscillates within the allowed range

static const uint8_t MBAuroraColors_arr[5][4] PROGMEM =
{
  {0  , 0 , 255,   0},// black
  {80 , 0 , 255, 255},
  {130, 25, 220, 255},
  {180, 25, 185, 255},
  {255, 25, 155, 255} //245
};

void auroraFillauroraMyPal16_2(uint8_t hue, bool isInvert = false)
{ 
  int8_t auroraLastSlotUsed = -1;
  uint8_t auroraistart8, auroriend8;
  CRGB auroraRGBstart, rgbend;
  
  if (isInvert)
    hsv2rgb_spectrum(CHSV(256 + hue - pgm_read_byte(&MBAuroraColors_arr[0][1]), pgm_read_byte(&MBAuroraColors_arr[0][2]), pgm_read_byte(&MBAuroraColors_arr[0][3])), auroraRGBstart);
  else
    hsv2rgb_spectrum(CHSV(hue + pgm_read_byte(&MBAuroraColors_arr[0][1]), pgm_read_byte(&MBAuroraColors_arr[0][2]), pgm_read_byte(&MBAuroraColors_arr[0][3])), auroraRGBstart);
  int indexstart = 0; // начальный индекс палитры
  for (uint8_t i = 1U; i < 5U; i++) { // в палитре @obliterator всего 5 строчек
    int indexend = pgm_read_byte(&MBAuroraColors_arr[i][0]);
    if (isInvert)
      hsv2rgb_spectrum(CHSV(hue + pgm_read_byte(&MBAuroraColors_arr[i][1]), pgm_read_byte(&MBAuroraColors_arr[i][2]), pgm_read_byte(&MBAuroraColors_arr[i][3])), rgbend);
    else
      hsv2rgb_spectrum(CHSV(256 + hue - pgm_read_byte(&MBAuroraColors_arr[i][1]), pgm_read_byte(&MBAuroraColors_arr[i][2]), pgm_read_byte(&MBAuroraColors_arr[i][3])), rgbend);
    auroraistart8 = indexstart / 16;
    auroriend8   = indexend   / 16;
    if ((auroraistart8 <= auroraLastSlotUsed) && (auroraLastSlotUsed < 15)) {
       auroraistart8 = auroraLastSlotUsed + 1;
       if (auroriend8 < auroraistart8)
         auroriend8 = auroraistart8;
    }
    auroraLastSlotUsed = auroriend8;
    fill_gradient_RGB( auroraMyPal, auroraistart8, auroraRGBstart, auroriend8, rgbend);
    indexstart = indexend;
    auroraRGBstart = rgbend;
  }
}

unsigned long auroraPolarTimer;
uint8_t auroraSR;
uint8_t auroraOldSR=0;
void makeAurora(CRGB *LEDARRAY)
{
  if (currentEffect == idxAurora && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
        auroraSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) auroraSR = ((auroraOldSR*2)+auroraSR)/3;
        else auroraSR = ((auroraOldSR*1)+auroraSR)/2;
      }
      FastLED.setBrightness(auroraSR);
    }
      
  if (auroraLoadingFlag) 
  {
    if (auroraSelectedSettings)
    {
      if (auroraRandom)
        {
          randomSeed(analogRead(AUDIO_IN_PIN));
          auroraSetModeSettings(random(3) ? 1U+random(99) : 100U, 1U+random(170));
          auroraRandom = false;
        }
      else
        //auroraSetModeSettings(random8(3U) ? 1U+random8(99U) : 100U, currentAuroraSpeed);
        auroraSetSpeed(currentAuroraSpeed);
    }

    auroraLoadingFlag = false;
    auroraSetCurrentPalette();
    auroraEmitterX = 400. / HEIGHT;
    
    auroraFF_y = map(WIDTH, 8, 64, 310, 63);
    auroraFF_z = auroraFF_y;
    auroraSpeedfactor = map(auroraSpeed, 1, 255, 128, 16); // _speed = map(speed, 1, 255, 128, 16);
  }
  
  //Serial.print(auroraRandom); Serial.print(" - "); Serial.println(auroraSpeedfactor);
  
  if (auroraScale == 100){
    if (auroraHue2++ & 0x01 && auroraDeltaHue++ & 0x01 && auroraDeltaHue2++ & 0x01) auroraHue++;
    auroraFillauroraMyPal16_2((uint8_t)((auroraScale - 1U) * 2.55) + auroraHue, auroraScale & 0x01);
  }
  else
    auroraFillauroraMyPal16_2((uint8_t)((auroraScale - 1U) * 2.55) + AURORA_COLOR_RANGE - beatsin8(AURORA_COLOR_PERIOD, 0U, AURORA_COLOR_RANGE+AURORA_COLOR_RANGE), auroraScale & 0x01);


  for (byte x = 0; x < WIDTH; x++) {
    for (byte y = 0; y < HEIGHT; y++) {
      auroraPolarTimer++;
      LEDARRAY[XY(x, y)]= 
          ColorFromPalette(auroraMyPal, qsub8(inoise8(auroraPolarTimer % 2 + x * auroraFF_z, y * 16 + auroraPolarTimer % 16, auroraPolarTimer / auroraSpeedfactor), fabs((float)HEIGHT/2 - (float)y) * auroraEmitterX));
    }
  }
  FastLED.show();
  if (isGlobalAudioReactive) auroraOldSR = auroraSR;
  if (toSleep || toWakeUp) delay(33);
}
// EOF AURORA CODES //


// LDIRKO'S BOIL CODES //
void drawPixelXY(CRGB *LEDARRAY1, int8_t x, int8_t y, CRGB color)
{
  if (x < 0 || x > (kMatrixWidth - 1) || y < 0 || y > (kMatrixHeight - 1)) return;
  uint32_t thisPixel = XYRev((uint8_t)x, (uint8_t)y);// * SEGMENTS;
    LEDARRAY1[thisPixel] = color;
}

void boilSetCurrentPalette()
{
      if (boilScale > 100U) boilScale = 100U;
      boilCurPalette = boilPalette_arr[(uint8_t)(boilScale/100.0F*((sizeof(boilPalette_arr)/sizeof(TProgmemRGBPalette16 *))-0.01F))];
}

void boilSetModeSettings(uint8_t Scale = 0U, uint8_t Speed = 0U)
{
  boilScale = Scale;
  boilSpeed = Speed;
  boilSelectedSettings = 0U;
}

void boilSetScale(uint8_t Scale = 0U)
{
  boilScale = Scale;
  boilSelectedSettings = 0U;
}

uint8_t boilSR;
uint8_t boilOldSR = 0;
void makeBoil(CRGB *LEDARRAY)
{
  if (currentEffect == idxBoil && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    boilSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) boilSR = ((boilOldSR*2)+boilSR)/3;
      else boilSR = ((boilOldSR*1)+boilSR)/2;
    }
    FastLED.setBrightness(boilSR);
  }
  
  if (boilLoadingFlag) 
  {
      if (boilSelectedSettings)
      {
        if (boilRandom)
        {
          randomSeed(analogRead(AUDIO_IN_PIN));
          uint8_t tmp = random(6);
          if (tmp > 1U) tmp += 3U;
          tmp = tmp*11U+4U+random(8);
          if (tmp > 97U) tmp = 94U;
          boilSetModeSettings(tmp, 200U+random(46));// scale 4-11, palettes 0, 1, 5, 6, 7, 8 (except 2, 3, 4)
          boilRandom = false;
        }
        else
          boilSetScale(currentBoilScale);
          //boilSetModeSettings(16, 255);
      }

    //Serial.println(boilSpeed);
    boilLoadingFlag = false;
    boilSetCurrentPalette();
    boilDeltaValue = 10U * ((boilScale - 1U) % 11U + 1U);// values from 1 to 11 
  }
  boilHue2 += 32U;
  if (boilHue2 < 32U)
    boilHue++;
  boilFF_y += 16U;
  
  for (uint8_t y = 0; y < kMatrixHeight; y++)
    for (uint16_t x = 0; x < kMatrixWidth; x++)
      drawPixelXY(LEDARRAY, x, y, ColorFromPalette (*boilCurPalette, map(inoise8(x * boilDeltaValue, y * boilDeltaValue - boilFF_y, boilFF_z) - y * 255 / (kMatrixHeight - 1), 0, 255, 205, 255) + boilHue, (currentBrightness+currentBrightness+maxBrightness)/3));
  boilFF_z++; 
  FastLED.show();     
  if (isGlobalAudioReactive) boilOldSR = boilSR;
}
// EOF LDIRKO'S BOIL //


// LDIRKO'S WFALL CODES //
void wfallSetModeSettings(uint8_t Scale = 0U, uint8_t Speed = 0U)
{
  wfallScale = Scale;
  wfallSpeed = Speed;
  wfallSelectedSettings = 0U;
}

void wfallSetScale(uint8_t Scale = 0U)
{
  wfallScale = Scale;
  wfallSelectedSettings = 0U;
}

// =============- новый огонь / водопад -===============
// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100
//#define WFALL_COOLINGNEW 32

uint8_t WFALL_COOLINGNEW;
// 8  an almost continuous flow of beautiful illuminated water in an even flow from top to bottom. as if there is a small "spring" on the table
// 20 a smooth waterfall with a peak in the light, where streams of flying water above are broken by the wind into white foam
// 32 no longer an even waterfall, in which jets of water reach the ground unevenly
// the larger the parameter, the more the shadow below
// 55 like in the video

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
//#define WFALL_SPARKINGNEW 80 // 30 // 120 // 90 // 60

uint8_t WFALL_SPARKINGNEW = 80; // 30 // 120 // 90 // 60
// 80 almost all white jets from above will reach the bottom - good with the selected slider Scale = 100 (white water without tinting)
// 50 a little more than half will fly. for colored liquid options it is more effective

uint8_t wfallSR;
uint8_t wfallOldSR=0;
void makeWFall(CRGB *LEDARRAY)
{
  if (currentEffect == idxWFall && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
//      if (audioSampleAvg*currentGVolume >= 80)
        wfallSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//      else
//        wfallSR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) wfallSR = ((wfallOldSR*2)+wfallSR)/3;
        else wfallSR = ((wfallOldSR*3)+wfallSR)/4;
      }
      //FastLED.setBrightness(wfallSR);
    }  
  
  if (isGlobalAudioReactive) 
    WFALL_COOLINGNEW = 4000 / (1 + wfallSR);
  else
    WFALL_COOLINGNEW = currentWFallVar2;
  
  if (wfallSelectedSettings)
  {
    if (wfallRandom)
      {
          randomSeed(analogRead(35));
          wfallSetModeSettings(random(7) ? 46+random(26) : 100U, 195+random(40));
          wfallRandom = false;
      }
      else
        wfallSetScale(currentWFallScale);
  }

  for (uint8_t x = 0; x < kMatrixWidth; x++) 
  {
    // Step 1.  Cool down every cell a little
    for (uint8_t i = 0; i < kMatrixHeight; i++) {
      wfallNoise3d[0][x][i] = qsub8(wfallNoise3d[0][x][i], random8(0, ((WFALL_COOLINGNEW * 10) / kMatrixHeight) + 2));
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for (uint8_t k = kMatrixHeight - 1; k >= 2; k--) 
    {
      wfallNoise3d[0][x][k] = (wfallNoise3d[0][x][k - 1] + wfallNoise3d[0][x][k - 2] + wfallNoise3d[0][x][k - 2]) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if (random8() < WFALL_SPARKINGNEW) 
    {
      uint8_t y = random8(2);
      wfallNoise3d[0][x][y] = qadd8(wfallNoise3d[0][x][y], random8(160, 255));
    }

    // Step 4.  Map from heat cells to LED colors
    for (uint8_t j = 0; j < kMatrixHeight; j++) 
    {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
      byte colorindex = scale8(wfallNoise3d[0][x][j], 240);

      if (isGlobalAudioReactive)
        LEDARRAY[XY(x, (kMatrixHeight - 1) - j)] = ColorFromPalette(CRGBPalette16( CRGB::Black, CHSV(currentWFallScale, 255U, 255U) , CHSV(currentWFallScale, 128U, 255U) , CRGB::White), colorindex);// 2.57 instead of 2.55 because 100 for white
      else
        LEDARRAY[XYRev(x, (kMatrixHeight - 1) - j)] = ColorFromPalette(CRGBPalette16( CRGB::Black, CHSV(currentWFallScale, 255U, 255U) , CHSV(currentWFallScale, 128U, 255U) , CRGB::White), colorindex);// 2.57 instead of 2.55 because 100 for white
    }
  }
  FastLED.show();
  if (isGlobalAudioReactive) wfallOldSR = wfallSR;
}
// EOF LDIRKO'S WFALL CODES //



// LDIRKO'S RUBIK CODES //
void rubikSetCurrentPalette()
{
      if (rubikScale > 100U) rubikScale = 100U; // чтобы не было проблем при прошивке без очистки памяти
      rubikCurPalette = rubikPalette_arr[(uint8_t)(rubikScale/100.0F*((sizeof(rubikPalette_arr)/sizeof(TProgmemRGBPalette16 *))-0.01F))];
}

void rubikSetModeSettings(uint8_t Scale = 0U, uint8_t Speed = 0U)
{
  rubikScale = Scale;
  rubikSpeed = Speed;
  rubikSelectedSettings = 0U;
}

void rubikSetScale(uint8_t Scale = 0U)
{
  rubikScale = Scale;
  rubikSelectedSettings = 0U;
}


// ------------------------------ ЭФФЕКТ КУБИК РУБИКА 2D ----------------------
// (c) SottNick

#define RUBIK_PAUSE_MAX 7 // skip 7 frames after cell shift animation completes

uint8_t rubikRazmerX, rubikRazmerY;
uint8_t rubikShtukX, rubikShtukY;
uint8_t rubikPoleX, rubikPoleY;
int8_t rubikGlobalShiftX, rubikGlobalShiftY;
bool rubikSeamlessX;
bool rubikKrutimVertikalno;

uint8_t rubikSR;
uint8_t rubikOldSR=0;
void makeRubik(CRGB *LEDARRAY)
{
    uint8_t x, y;
    uint8_t anim0;
    int8_t shift, kudaVse;
    CRGB color, color2;
    
  if (currentEffect == idxRubik && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
      //if (audioSampleAvg*currentGVolume >= 80)
        rubikSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
      //else
      //  rubikSR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

      //rubikSR = ((rubikOldSR*99)+rubikSR)/100;
      //FastLED.setBrightness(rubikSR);
    }

    //uint16_t timing;

    //Serial.println(rubikSR);
    if (isGlobalAudioReactive && random8(rubikSR)>= 90)
    {  
      EVERY_N_MILLIS(500)
      {
        toggleAutoHuePal();
      }
    }
          
      //timing = 600/(1+rubikSR);
    //else 
    //  timing = currentRubikDelay;
    
    EVERY_N_MILLIS_I(timeObj5, currentRubikDelay)
    {
      timeObj5.setPeriod(currentRubikDelay);
      
      if (rubikLoadingFlag)
      {
          if (rubikSelectedSettings)
          {
            if (rubikRandom)
            {
              randomSeed(analogRead(AUDIO_IN_PIN));
              uint8_t tmp = random(9)*11+random(8);
              if (tmp == 45U) tmp = 100U;
              rubikSetModeSettings(tmp, 175U+random(66));
              rubikRandom = false;
            }
            else
            {
              rubikSetScale(currentRubikScale);
            }
          }
  
        rubikLoadingFlag = false;
        rubikSetCurrentPalette();

        //FastLED.clear();
        for (int a=0; a< NUM_LEDS - 1; a++)
              LEDARRAY[a] = CRGB(0, 0, 0);
  
        rubikRazmerX = (rubikScale - 1U) % 11U + 1U;
        rubikRazmerY = rubikRazmerX;
        if (rubikSpeed & 0x01)
          rubikRazmerY = (rubikRazmerY << 1U) + 1U;
  
        rubikShtukY = kMatrixHeight / (rubikRazmerY + 1U);
        if (rubikShtukY < 2U)
          rubikShtukY = 2U;
        y = kMatrixHeight / rubikShtukY - 1U;
        if (rubikRazmerY > y)
          rubikRazmerY = y;
        rubikPoleY = (rubikRazmerY + 1U) * rubikShtukY;
        rubikShtukX = kMatrixWidth / (rubikRazmerX + 1U);
        if (rubikShtukX < 2U)
          rubikShtukX = 2U;
        x = kMatrixWidth / rubikShtukX - 1U;
        if (rubikRazmerX > x)
          rubikRazmerX = x;
        rubikPoleX = (rubikRazmerX + 1U) * rubikShtukX;
        rubikSeamlessX = (rubikPoleX == kMatrixWidth);
        rubikDeltaHue = 0U;
        rubikDeltaHue2 = 0U;
        rubikGlobalShiftX = 0;
        rubikGlobalShiftY = 0;
  
        for (uint8_t j = 0U; j < rubikShtukY; j++)
        {
          y = j * (rubikRazmerY + 1U); // + rubikDeltaHue2 т.к. оно =0U
          for (uint8_t i = 0U; i < rubikShtukX; i++)
          {
            x = i * (rubikRazmerX + 1U); // + rubikDeltaHue т.к. оно =0U
            if (rubikScale == 100U)
              color = CHSV(45U, 0U, 128U + random8(128U));
            else  
              color = ColorFromPalette(*rubikCurPalette, random8(), (currentBrightness + maxBrightness + maxBrightness)/3);
            for (uint8_t k = 0U; k < rubikRazmerY; k++)
              for (uint8_t m = 0U; m < rubikRazmerX; m++)
                LEDARRAY[XYRev(x+m, y+k)] = color;
          }
        }
        rubikStep = 4;
        rubikDeltaValue = 4;
        rubikHue2 = 0U;
      }
  
  
    if (rubikHue2 == 0 && rubikStep < rubikDeltaValue)
    {
      rubikStep++;
      if (rubikKrutimVertikalno)
      {
        for (uint8_t i = 0U; i < rubikShtukX; i++)
        {
          x = (rubikDeltaHue + i * (rubikRazmerX + 1U)) % kMatrixWidth;
          if (rubikNoise3d[0][i][0] > 0)
          {
            rubikNoise3d[0][i][0]--;
            shift = rubikNoise3d[0][i][1] - 1;
  
            if (rubikGlobalShiftY == 0)
              anim0 = (rubikDeltaHue2 == 0U) ? 0U : rubikDeltaHue2 - 1U;
            else if (rubikGlobalShiftY > 0)
              anim0 = rubikDeltaHue2;
            else
              anim0 = rubikDeltaHue2 - 1U;
            
            if (shift < 0)
            {
              color = LEDARRAY[XYRev(x, anim0)];
              for (uint8_t k = anim0; k < anim0+rubikPoleY-1; k++)
              {
                color2 = LEDARRAY[XYRev(x,k+1)];
                for (uint8_t m = x; m < x + rubikRazmerX; m++)
                  LEDARRAY[XYRev(m % kMatrixWidth,k)] = color2;
              }
              for   (uint8_t m = x; m < x + rubikRazmerX; m++)
                LEDARRAY[XYRev(m % kMatrixWidth,anim0+rubikPoleY-1)] = color;
            }
            else if (shift > 0)
            {
              color = LEDARRAY[XYRev(x,anim0+rubikPoleY-1)];
              for (uint8_t k = anim0+rubikPoleY-1; k > anim0 ; k--)
              {
                color2 = LEDARRAY[XYRev(x,k-1)];
                for (uint8_t m = x; m < x + rubikRazmerX; m++)
                  LEDARRAY[XYRev(m % kMatrixWidth,k)] = color2;
              }
              for   (uint8_t m = x; m < x + rubikRazmerX; m++)
                LEDARRAY[XYRev(m % kMatrixWidth, anim0)] = color;
            }
          }
        }
      }
      else
      {
        for (uint8_t j = 0U; j < rubikShtukY; j++)
        {
          y = rubikDeltaHue2 + j * (rubikRazmerY + 1U);
          if (rubikNoise3d[0][0][j] > 0)
          {
            rubikNoise3d[0][0][j]--;
            shift = rubikNoise3d[0][1][j] - 1;
        
            if (rubikSeamlessX)
              anim0 = 0U;
            else if (rubikGlobalShiftX == 0)
              anim0 = (rubikDeltaHue == 0U) ? 0U : rubikDeltaHue - 1U;
            else if (rubikGlobalShiftX > 0)
              anim0 = rubikDeltaHue;
            else
              anim0 = rubikDeltaHue - 1U;
            
            if (shift < 0) // если крутим строку влево
            {
              color = LEDARRAY[XYRev(anim0, y)];
              for (uint8_t k = anim0; k < anim0+rubikPoleX-1; k++)
              {
                color2 = LEDARRAY[XYRev(k+1, y)];
                for (uint8_t m = y; m < y + rubikRazmerY; m++)
                  LEDARRAY[XYRev(k, m)] = color2;
              }
              for   (uint8_t m = y; m < y + rubikRazmerY; m++)
                LEDARRAY[XYRev(anim0+rubikPoleX-1, m)] = color;
            }
            else if (shift > 0)
            {
              color = LEDARRAY[XYRev(anim0+rubikPoleX-1, y)];
              for (uint8_t k = anim0+rubikPoleX-1; k > anim0 ; k--)
              {
                color2 = LEDARRAY[XYRev(k-1, y)];
                for (uint8_t m = y; m < y + rubikRazmerY; m++)
                  LEDARRAY[XYRev(k, m)] = color2;
              }
              for   (uint8_t m = y; m < y + rubikRazmerY; m++)
                LEDARRAY[XYRev(anim0, m)] = color;
            }
          }
        }
      }
     
    }
    else if (rubikHue2 != 0U)
      rubikHue2--;
  
    if (rubikStep >= rubikDeltaValue)
    {
      rubikStep = 0U; 
      rubikHue2 = RUBIK_PAUSE_MAX;
  
      rubikDeltaHue2 = rubikDeltaHue2 + rubikGlobalShiftY; //+= rubikGlobalShiftY;
      rubikGlobalShiftY = 0;
  
      rubikDeltaHue = (kMatrixWidth + rubikDeltaHue + rubikGlobalShiftX) % kMatrixWidth;
      rubikGlobalShiftX = 0;
  
      kudaVse = 0;
      rubikKrutimVertikalno = random8(2U);
      if (rubikKrutimVertikalno)
      {
        for (uint8_t i = 0U; i < rubikShtukX; i++)
        {
          rubikNoise3d[0][i][1] = random8(3);
          shift = rubikNoise3d[0][i][1] - 1;
          if (kudaVse == 0)
            kudaVse = shift;
          else if (shift != 0 && kudaVse != shift)
            kudaVse = 50;
        }
        rubikDeltaValue = rubikRazmerY + ((rubikDeltaHue2 - kudaVse >= 0 && rubikDeltaHue2 - kudaVse + rubikPoleY < (int)kMatrixHeight) ? random8(2U) : 1U);
  
  
        if (rubikDeltaValue == rubikRazmerY)
        {
          rubikGlobalShiftY = 1 - kudaVse;
          for (uint8_t i = 0U; i < rubikShtukX; i++)
            if (rubikNoise3d[0][i][1] == 1U)
            {
              rubikNoise3d[0][i][1] = rubikGlobalShiftY;
              rubikNoise3d[0][i][0] = 1U;
            }
            else
              rubikNoise3d[0][i][0] = rubikDeltaValue;
          rubikGlobalShiftY--;
        }
        else
        {
          x = 0;
          for (uint8_t i = 0U; i < rubikShtukX; i++)
            if (rubikNoise3d[0][i][1] != 1U)
              {
                y = random8(rubikShtukY);
                if (y > x)
                  x = y;
                rubikNoise3d[0][i][0] = rubikDeltaValue * (x + 1U);
              }  
          rubikDeltaValue = rubikDeltaValue * (x + 1U);
        }      
      }
      else
      {
        for (uint8_t j = 0U; j < rubikShtukY; j++)
        {
          rubikNoise3d[0][1][j] = random8(3);
          shift = rubikNoise3d[0][1][j] - 1;
          if (kudaVse == 0)
            kudaVse = shift;
          else if (shift != 0 && kudaVse != shift)
            kudaVse = 50;
        }
        if (rubikSeamlessX)
          rubikDeltaValue = rubikRazmerX + ((kudaVse < 50) ? random8(2U) : 1U);
        else  
          rubikDeltaValue = rubikRazmerX + ((rubikDeltaHue - kudaVse >= 0 && rubikDeltaHue - kudaVse + rubikPoleX < (int)kMatrixWidth) ? random8(2U) : 1U);
        
        if (rubikDeltaValue == rubikRazmerX)
        {
          rubikGlobalShiftX = 1 - kudaVse;
          for (uint8_t j = 0U; j < rubikShtukY; j++)
            if (rubikNoise3d[0][1][j] == 1U)
            {
              rubikNoise3d[0][1][j] = rubikGlobalShiftX;
              rubikNoise3d[0][0][j] = 1U;
            }
            else
              rubikNoise3d[0][0][j] = rubikDeltaValue;
          rubikGlobalShiftX--;
        }
        else
        {
          y = 0;
          for (uint8_t j = 0U; j < rubikShtukY; j++)
            if (rubikNoise3d[0][1][j] != 1U)
              {
                x = random8(rubikShtukX);
                if (x > y)
                  y = x;
                rubikNoise3d[0][0][j] = rubikDeltaValue * (x + 1U);
              }  
          rubikDeltaValue = rubikDeltaValue * (y + 1U);
        }      
      }
    }
  }
  FastLED.show();
  if (isGlobalAudioReactive) rubikOldSR = rubikSR;
  if (toSleep || toWakeUp) delay(33);
}
// EOF LDIRKO'S RUBIK CODES //


// LDIRKO'S LAVA CODES //
void blurScreen(fract8 blur_amount, CRGB *LEDARRAY6)
{
  Cblur2d(LEDARRAY6, kMatrixWidth, kMatrixHeight, blur_amount);
}

uint32_t getPixColor(uint32_t thisSegm, CRGB *LEDARRAY5)
{
  uint32_t thisPixel = thisSegm;// * SEGMENTS;
  if (thisPixel > NUM_LEDS - 1) return 0;
  return (((uint32_t)LEDARRAY5[thisPixel].r << 16) | ((uint32_t)LEDARRAY5[thisPixel].g << 8 ) | (uint32_t)LEDARRAY5[thisPixel].b);
}

uint32_t getPixColorXY(uint8_t x, uint8_t y, CRGB *LEDARRAY4)
{
  return getPixColor(XYRev(x, y), LEDARRAY4);
}

void lavaDrawPixelXY(int8_t x, int8_t y, CRGB color, CRGB *LEDARRAY3)
{
  //CLEAR ALL LEDS HERE, USE MATRIX LEDARRAY3, DO NOT USE FASTLED.CLEAR
//  for (int a=0; a< kMatrixWidth - 1; a++)
//    for (int b=0; b< kMatrixHeight - 1; b++)
//        LEDARRAY3[XY(a, b)] = CRGB(0, 0, 0);
  
  
  if (x < 0 || x > (kMatrixWidth - 1) || y < 0 || y > (kMatrixHeight - 1)) return;
  uint32_t thisPixel = XYRev((uint8_t)x, (uint8_t)y);// * SEGMENTS;
    LEDARRAY3[thisPixel] = color;
}

//по мотивам
//https://gist.github.com/sutaburosu/32a203c2efa2bb584f4b846a91066583
void drawPixelXYF(float x, float y, CRGB color, CRGB *LEDARRAY2) //, uint8_t darklevel = 0U)
{
  uint8_t xx = (x - (int)x) * 255, yy = (y - (int)y) * 255, ix = 255 - xx, iy = 255 - yy;
//  #define WU_WEIGHT(a,b) ((uint8_t) (((a)*(b)+(a)+(b))>>8))
  uint8_t wu[4] = {WU_WEIGHT(ix, iy), WU_WEIGHT(xx, iy),
                   WU_WEIGHT(ix, yy), WU_WEIGHT(xx, yy)};
  for (uint8_t i = 0; i < 4; i++) 
  {
    int16_t xn = x + (i & 1), yn = y + ((i >> 1) & 1);
    CRGB clr = getPixColorXY(xn, yn, LEDARRAY2);
    clr.r = qadd8(clr.r, (color.r * wu[i]) >> 8);
    clr.g = qadd8(clr.g, (color.g * wu[i]) >> 8);
    clr.b = qadd8(clr.b, (color.b * wu[i]) >> 8);
    lavaDrawPixelXY(xn, yn, clr, LEDARRAY2);
  }
}

// with this number of palettes (9pcs), each Scale range (from 1 to 100) can be divided into sections of 11 values
// values from 0 to 10 = ((lava1Scale - 1U) % 11U)
// values from 1 to 11 = ((lava1Scale - 1U) % 11U + 1U)
// and the 100th Scale value can be used for white


void lavaSetModeSettings(uint8_t Scale = 0U, uint8_t Speed = 0U)
{
  lava1Scale = (unsigned)Scale;
  lava1Speed = (unsigned)Speed;
  lava1SelectedSettings = 0U;
}

void LavaLampGetspeed(uint8_t l)
{
  //trackingObjectSpeedY[l] = (float)random8(1, 11) / 10.0; // скорость пузырей 10 градаций?
  trackingObjectSpeedY[l] = (float)random8(5, 11) / (257U - lava1Speed) / 4.0; // если скорость кадров фиксированная
}
void drawBlob(uint8_t l, CRGB color, CRGB *LEDARRAY1)
{ //раз круги нарисовать не получается, будем попиксельно вырисовывать 2 варианта пузырей
  if (trackingObjectShift[l] == 2)
    {
      for (int8_t x = -2; x < 3; x++)
        for (int8_t y = -2; y < 3; y++)
          if (abs(x)+abs(y) < 4)
            drawPixelXYF(fmod(trackingObjectPosX[l]+x +kMatrixWidth,kMatrixWidth), trackingObjectPosY[l]+y, color, LEDARRAY1);
    }
  else
    {
      for (int8_t x = -1; x < 3; x++)
        for (int8_t y = -1; y < 3; y++)
          if (!(x==-1 && (y==-1 || y==2) || x==2 && (y==-1 || y==2)))
            drawPixelXYF(fmod(trackingObjectPosX[l]+x +kMatrixWidth,kMatrixWidth), trackingObjectPosY[l]+y, color, LEDARRAY1);
    }
}


uint8_t lava1SR;
uint8_t lava1OldSR=0;
void makeLava1(CRGB *LEDARRAY)
{
  //unsigned num = map(scale, 0U, 255U, 6U, sizeof(boids) / sizeof(*boids));
  if (currentEffect == idxLava1 && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
//    if (audioSampleAvg*currentGVolume >= 80)
      lava1SR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//    else
//      lava1SR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) lava1SR = ((lava1OldSR*2)+lava1SR)/3;
      else lava1SR = ((lava1OldSR*1)+lava1SR)/2;
    }
    FastLED.setBrightness(lava1SR);
  }

  EVERY_N_MILLIS(1)
  {
    if (lava1LoadingFlag)
    {
        if (lava1SelectedSettings)
        {
          if (lava1Random)
          {
            randomSeed(analogRead(35));
            lavaSetModeSettings(random8(30U) ? (random8(3U) ? 2+random8(98U) : 1U) : 100U, 50U+random8(196U));
            lava1Random = false;
          }
          else
            lavaSetModeSettings(currentLava1Scale, currentLava1Speed);
        }
      
      lava1LoadingFlag = false;
      enlargedObjectNUM = (lava1Scale - 1U) / 99.0 * (enlargedOBJECT_MAX_COUNT - 1U) + 1U;
      if (enlargedObjectNUM > enlargedOBJECT_MAX_COUNT)
        enlargedObjectNUM = enlargedOBJECT_MAX_COUNT;
      if (enlargedObjectNUM < 2U) enlargedObjectNUM = 2U;
      
//      enlargedObjectNUM = (kMatrixWidth / 2) -  ((kMatrixWidth - 1) & 0x01);
  
      uint8_t shift = random8(2);
      for (uint8_t i = 0; i < enlargedObjectNUM; i++) 
      {
        //LavaLampRestart_leaper(i);
        trackingObjectPosY[i] = 0;//random8(kMatrixHeight);
        trackingObjectPosX[i] = i * 2U + shift;
        LavaLampGetspeed(i);
        //trackingObjectShift[i] = 1.0 + 0.2 * random8(8); // assigned a random radius to bubbles from 1 to 2.5
        trackingObjectShift[i] = random8(1,3); // assigned a random integer radius to bubbles from 1 to 2
      }

//      if (lava1Scale != 1U)
//        lava1Hue = lava1Scale * 2.57;
    }
//    if (lava1Scale == 1U)
      {
        lava1Hue2++;
        if (lava1Hue2 % 0x10 == 0U)
          lava1Hue++;
      }
    CRGB color = CHSV(lava1Hue, (lava1Scale < 100U) ? 255U : 0U, 255U);
    //CRGB halfcolor = CHSV(lava1Hue, 255U, 1275U);
   
    //FastLED.clear();
  
  //  for (int a=0; a< kMatrixWidth - 1; a++)
  //    for (int b=0; b< kMatrixHeight - 1; b++)
  //        LEDARRAY[XYRev(a, b)] = CRGB(0, 0, 0);
    
    for (int a=0; a< NUM_LEDS - 1; a++)
          LEDARRAY[a] = CRGB(0, 0, 0);
  
    for (uint8_t i = 0; i < enlargedObjectNUM; i++) 
    { //moving in the same way as https://jiwonk.im/lavalamp/
      //LavaLampMove_leaper(i);
      if (trackingObjectPosY[i] + trackingObjectShift[i] >= kMatrixHeight - 1)
         trackingObjectPosY[i] += (trackingObjectSpeedY[i] * ((kMatrixHeight - 1 - trackingObjectPosY[i]) / trackingObjectShift[i] + 0.005));
      else if (trackingObjectPosY[i] - trackingObjectShift[i] <= 0)
         trackingObjectPosY[i] += (trackingObjectSpeedY[i] * (trackingObjectPosY[i] / trackingObjectShift[i] + 0.005));
      else
         trackingObjectPosY[i] += trackingObjectSpeedY[i];
  
      // bounce off the floor and ceiling?
      if (trackingObjectPosY[i] < 0.01)
      {                   // for some reason, at zero, flicker appears (one frame, barely noticeable)
        LavaLampGetspeed(i);
        //trackingObjectShift[i] = 1+2*trackingObjectSpeedY[i]; changing radius after bounce is a bad idea
        trackingObjectPosY[i] = 0.01;
        }
      else if (trackingObjectPosY[i] > kMatrixHeight - 1.01)
      {     // тоже на всякий пожарный
        LavaLampGetspeed(i);
        //trackingObjectShift[i] = 1+2*trackingObjectSpeedY[i]; changing radius after bounce is a bad idea
        trackingObjectSpeedY[i] = -trackingObjectSpeedY[i];
        trackingObjectPosY[i] = kMatrixHeight - 1.01;
        }
      drawBlob(i, color, LEDARRAY); // since the circles look bad, draw pixel by pixel 2 sizes of bubbles
    };
    blurScreen(20, LEDARRAY);
    FastLED.show();
  }
  //FastLED.show();
  if (isGlobalAudioReactive) lava1OldSR = lava1SR;
  if (toSleep || toWakeUp) delay(33);
}
// EOF LDIRKO'S LAVA CODES //


// ROTATE LAMP CODES //
uint8_t rotateLampSR;
uint8_t rotateLampOldSR;
void rotateLamp(CRGB *LEDARRAY)
{
  uint32_t ms = millis();
  double cHue;
  CHSV hsv;

  if (currentEffect == idxRotateLamp && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    rotateLampSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/2), 0, (currentBrightness+currentBrightness+maxBrightness)/2);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) rotateLampSR = ((rotateLampOldSR*2)+rotateLampSR)/3;
      else rotateLampSR = ((rotateLampOldSR*1)+rotateLampSR)/2;
    }
    FastLED.setBrightness(rotateLampSR);
  }
  
  EVERY_N_MILLIS(intervalRotateLampHue)
  {
    if ((rotateLampAutoHue) && (!isLEDOFF)) HuePalUpAuto();
  }
  
  random16_add_entropy( random(0,65535));
  EVERY_N_MILLIS(6000)
  {
    rotateLampSpeedMult = random8(20, 170);
  }

  uint32_t yHueDelta = (int32_t)sin16(ms * rotateLampSpeedMult) * 5;
  uint32_t xHueDelta = (int32_t)cos16(ms * rotateLampSpeedMult) * 5;

  uint32_t startHue = -128;  // half the width of a single Palette16 colour, to centre the line
  uint32_t lineStartHue = startHue - (kMatrixHeight - 4) * yHueDelta / 2;
  for (byte y = 0; y < kMatrixHeight; y++) 
  {
    uint32_t pixelHue = lineStartHue - (kMatrixWidth + 1) * xHueDelta / 2;
    uint32_t xhd = xHueDelta;
    for (byte x = 0; x < kMatrixWidth; x++) 
    {
      hsv = rgb2hsv_precise(ColorFromPalette(rotateLampPalette, pixelHue >> 15, (currentBrightness+currentBrightness+maxBrightness)/3, LINEARBLEND));
      
      //cHue = hsv.h + currentRotateLampHue;
      cHue = hsv.h + currentRotateLampHue > 254 ? 255 - (hsv.h + currentRotateLampHue) : hsv.h + currentRotateLampHue;
      LEDARRAY[XY(x,y)] = CHSV(cHue, hsv.s, hsv.v);
      pixelHue += xhd;
    }
    lineStartHue += yHueDelta;
  }
  FastLED.show();
  if (isGlobalAudioReactive) rotateLampOldSR = rotateLampSR;
  if (toSleep || toWakeUp) delay(33);
}
// EOF ROTATE LAMP CODES //

// RADFIRE CODES //
void initRadFire()
{
  for (int8_t x = -kHalfWidth; x < kHalfWidth; x++) 
  {
    for (int8_t y = -kHalfHeight; y < kHalfHeight; y++) 
    {
      radFireAngle[x + kHalfWidth][y + kHalfHeight] = atan2(y, x) * (360. / 2. / PI) * kHalfWidth;
      radFireRadius[x + kHalfWidth][y + kHalfHeight] = hypotf(x, y);
    }
  }
}

uint8_t radFireSR;
uint8_t radFireOldSR = 0;
void makeRadFire(CRGB *LEDARRAY) 
{
  static byte scale = 16;
  static byte speed = 48;
  static uint32_t t;
  double cHue;
  CHSV hsv;

  if (currentEffect == idxRadFire && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    radFireSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
    if (audioSampleAvg > 0)
    {
      if (!enableWifi) radFireSR = ((radFireOldSR*2)+radFireSR)/3;
      else radFireSR = ((radFireOldSR*1)+radFireSR)/2;
    }
    //FastLED.setBrightness(radFireSR);
  }

  EVERY_N_MILLIS_I(timeObj, currentRadFireDelay)
  {
    timeObj.setPeriod(currentRadFireDelay);
    
    EVERY_N_MILLIS(intervalRadFireHue)
    {
      if ((radFireAutoHue) && (!isLEDOFF)) HuePalUpAuto();
    }
    
    t += speed;
    for (uint8_t x = 0; x < kMatrixWidth; x++) 
    {
      for (uint8_t y = 0; y < kMatrixHeight; y++) 
      {
        float angle = radFireAngle[x][y];
        float radius = radFireRadius[x][y];
        int16_t Bri = inoise8(angle, radius * scale - t) - radius * kMatrixHeight;
        byte Col = Bri;
        if (Bri < 0) Bri = 0; if(Bri != 0) Bri = 256 - (Bri * 0.2);
  
        uint8_t Bri2;
        if (isGlobalAudioReactive)
          Bri2 = ((radFireSR*3) + Bri)/4;
        else
          Bri2 = Bri;
          
        hsv = rgb2hsv_precise(ColorFromPalette(radFirePalette, Col, Bri2));
        
        //cHue = hsv.h + currentRadFireHue;
        cHue = hsv.h + currentRadFireHue > 254 ? 255 - (hsv.h + currentRadFireHue) : hsv.h + currentRadFireHue;
        nblend(LEDARRAY[XY(x, y)], CHSV(cHue, hsv.s, hsv.v), speed);}
    }
  }
  FastLED.show();
  if (isGlobalAudioReactive) radFireOldSR = radFireSR;
  if (toSleep || toWakeUp) delay(33);
}
// EOF RADFIRE CODES //

// BARBERPOLE1 CODES //
uint8_t bp1SR;
uint8_t bp1OldSR=0;
void BarberPole1(CRGB *LEDARRAY)
{
    CRGB:CRGB bp1Color, bp1Red, bp1White, bp1Blue;
    bp1Red = CRGB((currentBrightness+currentBrightness+maxBrightness)/3, 0, 0);
    bp1White = CRGB(floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8), floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8), floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8));
    bp1Blue = CRGB(0, 0, (currentBrightness+currentBrightness+maxBrightness)/3);
    
    if (currentEffect == idxBarberPole1 && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
//      if (audioSampleAvg*currentGVolume >= 80)
        bp1SR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//      else
//        bp1SR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;
  
      if (audioSampleAvg > 0)
      {
        if (!enableWifi) bp1SR = ((bp1OldSR*2)+bp1SR)/3;
        else bp1SR = ((bp1OldSR*1)+bp1SR)/2;
      }
      //FastLED.setBrightness(bp1SR);
    }    

    uint16_t timing;
    if (isGlobalAudioReactive)
      timing = (currentBP1Delay + (700/(1+bp1SR)))/2;
    else
      timing = currentBP1Delay;
    
    EVERY_N_MILLIS_I(timeObj, timing)
    {
        timeObj.setPeriod(timing);
        for( int i = 0; i < kMatrixHeight; i++) 
        {                          
          for( int strip = 0; strip < kMatrixWidth; strip++) 
          {
     
            int diag = strip+i+bp1Rotate;
            diag = diag % 8;
    
            switch(strip)
            {
            case 0:
              bp1Color = bp1Red;
              break;
            case 1:
              bp1Color = bp1Red;
              break;
            case 2:
              bp1Color = bp1Red;
              break;
            case 3:
              bp1Color = bp1White;
              break;
            case 4:
              bp1Color = bp1Blue;
              break;
            case 5:
              bp1Color = bp1Blue;
              break;
            case 6:
              bp1Color = bp1Blue;
              break;
            case 7:
              bp1Color = bp1White;
              break;
            }
            LEDARRAY[XY(diag,i)] = bp1Color;
          }
        }
        FastLED.show(); // display this frame
        if (bp1Rotate + 1 < kMatrixWidth) bp1Rotate++; else bp1Rotate = 0;
    }
    if (isGlobalAudioReactive) bp1OldSR = bp1SR;
    if (toSleep || toWakeUp) delay(33);
}
// EOF BARBERPOLE CODES //


// BARBERPOLE2 CODES //
uint8_t bp2SR;
uint8_t bp2OldSR=0;
void BarberPole2(CRGB *LEDARRAY)
{
    double cHue;
    CHSV hsv;

    EVERY_N_MILLIS(intervalBP2Hue)
    {
      if ((bp2AutoHue) && (!isLEDOFF)) HuePalUpAuto();
    }
    
    CRGB:CRGB bp2Color, bp2Red, bp2White, bp2Blue;
    bp2Red = CRGB((currentBrightness+currentBrightness+maxBrightness)/3, 0, 0);
    bp2White = CRGB(floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8), floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8), floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8));
    bp2Blue = CRGB(0, 0, (currentBrightness+currentBrightness+maxBrightness)/3);
    
    if (currentEffect == idxBarberPole2 && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
//      if (audioSampleAvg*currentGVolume >= 80)
        bp2SR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//      else
//        bp2SR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;
  
        if (audioSampleAvg > 0)
        {
          if (!enableWifi) bp2SR = ((bp2OldSR*2)+bp2SR)/3;
          else bp2SR = ((bp2OldSR*1)+bp2SR)/2;
        }
    }    

    uint16_t timing;
    if (isGlobalAudioReactive)
      timing = (currentBP2Delay + (700/(1+bp2SR)))/2;
    else
      timing = currentBP2Delay;
    
    EVERY_N_MILLIS_I(timeObj, timing)
    {
        timeObj.setPeriod(timing);
        if (bp2Loop < (16*bp2Count)) ++bp2Loop; else bp2Loop = 0;
        for (int ledIx = 0; ledIx < NUM_LEDS; ++ledIx) 
        {
            switch (((ledIx + bp2Loop) % bp2Count) / bp2Size) 
            {
            case 0:
                bp2Color = bp2Red;
                break;
            case 1:
                bp2Color = bp2White;
                break;
            case 2:
                bp2Color = bp2Blue;
                break;
            case 3:
                bp2Color = bp2White;
                break;
            case 4:
                bp2Color = bp2Red;
                break;
            case 5:
                bp2Color = bp2White;
                break;
            case 6:
                bp2Color = bp2Blue;
                break;
            case 7:
                bp2Color = bp2White;
                break;
            case 8:
                bp2Color = bp2Red;
                break;
            case 9:
                bp2Color = bp2White;
                break;
            case 10:
                bp2Color = bp2Blue;
                break;
            case 11:
                bp2Color = bp2White;
                break;
            case 12:
                bp2Color = bp2Red;
                break;
            case 13:
                bp2Color = bp2White;
                break;
            case 14:
                bp2Color = bp2Blue;
                break;
            case 15:
                bp2Color = bp2White;
                break;
            }
            
            hsv = rgb2hsv_precise(bp2Color);
            //cHue = hsv.h + currentBP2Hue;
            cHue = hsv.h + currentBP2Hue > 254 ? 255 - (hsv.h + currentBP2Hue) : hsv.h + currentBP2Hue;
            LEDARRAY[bp2XYTable[ledIx]] = CHSV(cHue, hsv.s, hsv.v);
        }
        FastLED.show();
    }
    if (isGlobalAudioReactive) bp2OldSR = bp2SR;
    if (toSleep || toWakeUp) delay(33);
}
// EOF BARBERPOLE2 CODES //


// BARBERPOLE3 CODES //
uint8_t bp3SR;
uint8_t bp3OldSR=0;
void BarberPole3(CRGB *LEDARRAY)
{
    double cHue;
    CHSV hsv;

    EVERY_N_MILLIS(intervalBP3Hue)
    {
      if ((bp3AutoHue) && (!isLEDOFF)) HuePalUpAuto();
    }
    
    CRGB:CRGB bp3Color, bp3Red, bp3White, bp3Blue;
    bp3Red = CRGB((currentBrightness+currentBrightness+maxBrightness)/3, 0, 0);
    bp3White = CRGB(floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8), floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8), floor(((currentBrightness+currentBrightness+maxBrightness)/3)*0.8));
    bp3Blue = CRGB(0, 0, (currentBrightness+currentBrightness+maxBrightness)/3);
    
    if (currentEffect == idxBarberPole3 && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
//      if (audioSampleAvg*currentGVolume >= 80)
        bp3SR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//      else
//        bp3SR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;
  
        if (audioSampleAvg > 0)
        {
          if (!enableWifi) bp3SR = ((bp3OldSR*2)+bp3SR)/3;
          else bp3SR = ((bp3OldSR*3)+bp3SR)/4;
        }
    }    

    uint16_t timing;
    if (isGlobalAudioReactive)
      timing = (currentBP3Delay + (600/(1+bp3SR)))/2;
    else
      timing = currentBP3Delay;
    
    EVERY_N_MILLIS_I(timeObj, timing)
    {
        timeObj.setPeriod(timing);
        if (bp3Loop < (3*bp3Count)) ++bp3Loop; else bp3Loop = 0;
        for (int ledIx = 0; ledIx < NUM_LEDS; ++ledIx) 
        {
            switch (((ledIx + bp3Loop) % bp3Count) / bp3Size) 
            {
            case 0:
                bp3Color = bp3Red;
                break;
            case 1:
                bp3Color = bp3White;
                break;
            case 2:
                bp3Color = bp3Blue;
                break;
            case 3:
                bp3Color = bp3White;
                break;
            case 4:
                bp3Color = bp3Red;
                break;
            }
            hsv = rgb2hsv_precise(bp3Color);
            //cHue = hsv.h + currentBP3Hue;
            cHue = hsv.h + currentBP3Hue > 254 ? 255 - (hsv.h + currentBP3Hue) : hsv.h + currentBP3Hue;
            LEDARRAY[bp3XYTable[ledIx]] = CHSV(cHue, hsv.s, hsv.v);
        }
        FastLED.show();
    }
    if (isGlobalAudioReactive) bp3OldSR = bp3SR;
    if (toSleep || toWakeUp) delay(33);
}
// EOF BARBERPOLE3 CODES //



// LAVALAMP2 CODES //
uint8_t lava2SR;
uint8_t lava2OldSR=0;
void makeLava2(CRGB *LEDARRAY)
{
  CRGBPalette16 lava2Palette = lava2Pal;
  CHSV hsv;

  uint8_t scaley = lava2Intensity / 8 + 15;
  uint8_t scalex = scaley * 1.5;
  uint8_t lava2Speed = (255 - lava2Speed) / 16;
  uint8_t n = 2 + lava2FFT2 / 16;
  uint8_t kscale = n < 4 ? 4 : n < 8 ? 3 : 2;
  double cHue;

  if (currentEffect == idxLava2 && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    //if (audioSampleAvg*currentGVolume >= 80)
      lava2SR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
    //else
    //  lava2SR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) lava2SR = ((lava2OldSR*2)+lava2SR)/3;
        else lava2SR = ((lava2OldSR*3)+lava2SR)/4;
      }
      //FastLED.setBrightness(lava2SR);
  }

  EVERY_N_MILLIS(intervalLava2Hue)
  {
    if ((lava2AutoHue) && (!isLEDOFF)) HuePalUpAuto();
  }

  
  uint16_t t = millis();
  for (int i = 0; i < kMatrixWidth; i++) 
  {
    for (int j = 0; j < kMatrixHeight; j++) 
    {

      int ci = lava2FFT1;
      for (int k = 0; k < n; k++) {
        ci += qsub8(inoise8(i * scalex - sin8(t / (kMatrixHeight + 10*k)) / 4
                               , (k % 2 == 0 ? j : -j) * scaley + t / (lava2Speed + kscale * k + 1)
                               , 0), lava2FFT3);

      }
      uint8_t Bri2;
      if (isGlobalAudioReactive)
        Bri2 = lava2SR;
      else
        Bri2 = (currentBrightness+currentBrightness+maxBrightness)/3;
        
      hsv = rgb2hsv_precise(ColorFromPalette(lava2Palette, ci, Bri2));
      //cHue = hsv.h + currentLava2Hue;
      cHue = hsv.h + currentLava2Hue > 254 ? 255 - (hsv.h + currentLava2Hue) : hsv.h + currentLava2Hue;
      LEDARRAY[XYRev(i, j)] = blend(LEDARRAY[XYRev(i, j)], CHSV(cHue, hsv.s, hsv.v), 20);
    }
  }
  FastLED.show();
  if (isGlobalAudioReactive) lava2OldSR = lava2SR;
  if (toSleep || toWakeUp) delay(33);
}
// EOF LAVALAMP2 CODES //



// LAVALAMP3 CODES //
void doSendVoxels(CRGB *LEDARRAY2)
{
  if (lava3Loading) 
  {
    //FastLED.clear();
    for (int c=0; c<NUM_LEDS; c++) LEDARRAY2[c] = CRGB(0, 0, 0);
    
    for (uint8_t x = 0; x < kMatrixWidth; x++) 
    {
      LEDARRAY2[XY(x, (random(1) == 1) ? kMatrixHeight - 1 : 0)] = CHSV(0, 0, 255);
    }
    lava3Loading = false;
  }
  if (!lava3Sending) 
  {
    lava3SelX = random(0, kMatrixHeight);
    if (LEDARRAY2[XY(lava3SelX, 0)] == CHSV(0, 0, 255)) 
    {
      lava3SelY = 0;
      lava3SendDirection = 1;
    } 
    else if (LEDARRAY2[XY(lava3SelX, kMatrixHeight - 1)]) 
    {
      lava3SelY = kMatrixHeight - 1;
      lava3SendDirection = 0;
    }
    lava3Sending = true;
  } 
  else 
  {
    if (lava3SendDirection == 1) 
    {
      lava3SelY ++;
      LEDARRAY2[XY(lava3SelX, lava3SelY)] = CHSV(0, 0, 255);
      LEDARRAY2[XY(lava3SelX, lava3SelY - 1)] = 0;
      if (lava3SelY == kMatrixHeight - 1) 
      {
        lava3Sending = false;
      }
    } 
    else 
    {
      lava3SelY --;
      LEDARRAY2[XY(lava3SelX, lava3SelY)] = CHSV(0, 0, 255);
      LEDARRAY2[XY(lava3SelX, lava3SelY + 1)] = 0;
      if (lava3SelY == 0) 
      {
        lava3Sending = false;
      }
    }
  }
}


void lava3_wu_pixelY(CRGB *LEDARRAY5, uint8_t x, uint32_t y, CRGB * col)
{
   uint8_t yy = y & 0xff, iy = 255 - yy;
//  #define WU_WEIGHT(a, b)((uint8_t)(((a) * (b) + (a) + (b)) >> 8))
  uint8_t wu[2] = { iy, yy };

  for (int8_t i = 1; i >= 0; i--) 
  {
    uint16_t xy = XY(x, (y >> 8) + ((i >> 1) & 1));
    LEDARRAY5[xy].r = qadd8(LEDARRAY5[xy].r, col -> r * wu[i] >> 8);
    LEDARRAY5[xy].g = qadd8(LEDARRAY5[xy].g, col -> g * wu[i] >> 8);
    LEDARRAY5[xy].b = qadd8(LEDARRAY5[xy].b, col -> b * wu[i] >> 8);
  }
}

void doSendVoxelsV2(CRGB *LEDARRAY3)
{
  double cHue;
  CHSV hsv;
  
  EVERY_N_MILLIS(intervalLava3Hue)
  {
    if ((lava3AutoHue) && (!isLEDOFF)) HuePalUpAuto();
  }

  if (lava3Loading) 
  {
    //FastLED.clear();
    for (int c=0; c<NUM_LEDS; c++) LEDARRAY3[c] = CRGB(0, 0, 0);
    
    for (uint8_t i = 0; i < kMatrixWidth; i++) 
    {
      lava3PosY[i] = (random(2) == 1) ? (kMatrixHeight - 1) * 256 : 0;
    }
    lava3Loading = false;
  }
  //blur2d(leds,kMatrixWidth,kMatrixHeight,5);
  for (uint8_t i = 0; i < kMatrixWidth; i++) 
  {
    hsv = rgb2hsv_precise(lava3Color);
    //cHue = hsv.h + currentLava3Hue;
    cHue = hsv.h + currentLava3Hue > 254 ? 255 - (hsv.h + currentLava3Hue) : hsv.h + currentLava3Hue;
    CRGB color = CHSV(cHue, hsv.s, hsv.v);
    if(i == lava3SelX)
    lava3_wu_pixelY(LEDARRAY3, i, lava3PosY[i], &color);
    else
    LEDARRAY3[XY(i, lava3PosY[i] / 256)] += color;
    if (!lava3Sending) 
    {
      lava3SelX = random(0, kMatrixWidth);
      if (lava3PosY[lava3SelX] == 0) {
        lava3SendDirection = 1;
      } 
      else if (lava3PosY[lava3SelX] ==(kMatrixHeight - 1) * 256) 
      {
        lava3SendDirection = 0;
      }
      lava3Sending = true;
    } 
    else 
    {
      if (lava3SendDirection) 
      {
        lava3PosY[lava3SelX] += currentLava3Speed;
        if (lava3PosY[lava3SelX] >= (kMatrixHeight - 1) * 256) 
        {
          lava3PosY[lava3SelX] = (kMatrixHeight - 1) * 256;
          lava3Sending = false;
        }
      } 
      else 
      {
        lava3PosY[lava3SelX] -= currentLava3Speed;
        if (lava3PosY[lava3SelX] <= 0) 
        {
          lava3PosY[lava3SelX] = 0;
          lava3Sending = false;
        }
      }
    }
  }
  Cblur2d(LEDARRAY3, kMatrixWidth, kMatrixHeight, 35);
}

byte lava3_dist (uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)  
{
int8_t a = y2-y1;
int8_t b = x2-x1; 
byte dist = 220 / sqrt16(a*a+b*b);
return dist;
}

void doLavaSend(CRGB *LEDARRAY4)
{
  if (lava3Loading) 
  {
    //FastLED.clear();
    for (int c=0; c<NUM_LEDS; c++) LEDARRAY4[c] = CRGB(0, 0, 0);
    
    for (uint8_t i = 0; i < kMatrixWidth; i++) 
    {
      lava3PosY[i] = (random(2) == 1) ? (kMatrixHeight - 1) * 256 : 0;
    }
    lava3Loading = false;
  }
  for (uint8_t i = 0; i < kMatrixWidth; i++) 
  {
    if (!lava3Sending) 
    {
      lava3SelX = random(0, kMatrixWidth);
      if (lava3PosY[lava3SelX] == 0) 
      {
        lava3SendDirection = 1;
      } else if (lava3PosY[lava3SelX] ==(kMatrixHeight - 1) * 256) 
      {
        lava3SendDirection = 0;
      }
      lava3Sending = true;
    } 
    else 
    {
      if (lava3SendDirection) 
      {
        lava3PosY[lava3SelX] += currentLava3Speed;
        if (lava3PosY[lava3SelX] >= (kMatrixHeight - 1) * 256) 
        {
          lava3PosY[lava3SelX] = (kMatrixHeight - 1) * 256;
          lava3Sending = false;
        }
      } 
      else 
      {
        lava3PosY[lava3SelX] -= currentLava3Speed;
        if (lava3PosY[lava3SelX] <= 0) 
        {
          lava3PosY[lava3SelX] = 0;
          lava3Sending = false;
        }
      }
    }
  }
  for (int i = 0; i < kMatrixWidth; i++)    
  {
    for (int j = 0; j < kMatrixHeight; j++) 
    {

      byte  sum =  lava3_dist(i, j, 0, lava3PosY[0]/256)/2;
      for (uint8_t s = 1; s < kMatrixWidth; s++) {sum += lava3_dist(i, j, s, lava3PosY[s]/256)/2;}
      nblend(LEDARRAY4[XY (i, j)],  ColorFromPalette(HeatColors_p , sum + 128), 22);
    }
  }
}

uint8_t lava3SR;
uint8_t lava3OldSR=0;
void makeLava3(CRGB *LEDARRAY1)
{
  if (currentEffect == idxLava3 && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
//    if (audioSampleAvg*currentGVolume >= 80)
      lava3SR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//    else
//      lava3SR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) lava3SR = ((lava3OldSR*2)+lava3SR)/3;
        else lava3SR = ((lava3OldSR*3)+lava3SR)/4;
      }
      
      //Serial.println(lava3SR);
      
      FastLED.setBrightness(lava3SR);
  }

//  EVERY_N_MILLIS(intervalLava3Hue)
//  {
//    if ((lava3AutoHue) && (!isLEDOFF)) HuePalUpAuto();
//  }
  
  if (lava3Regime == 1) doSendVoxelsV2(LEDARRAY1);
  else if (lava3Regime == 2) doLavaSend(LEDARRAY1);
    else doSendVoxels(LEDARRAY1);

  if (isGlobalAudioReactive) lava3OldSR = lava3SR;
}
// EOF LAVALAMP3 CODES //



// DRAWBARS CODES //
uint8_t dbarsSR;
uint8_t dbarsOldSR=0;
void dBars_wu_pixel(CRGB *LEDARRAY3, uint32_t x, uint32_t y, CRGB * col)
{
  // extract the fractional parts and derive their inverses
  uint8_t xx = x & 0xff, yy = y & 0xff, ix = 255 - xx, iy = 255 - yy;
  // calculate the intensities for each affected pixel
  #define WU_WEIGHT(a,b) ((uint8_t) (((a)*(b)+(a)+(b))>>8))
  uint8_t wu[4] = {WU_WEIGHT(ix, iy), WU_WEIGHT(xx, iy),
                   WU_WEIGHT(ix, yy), WU_WEIGHT(xx, yy)};
  // multiply the intensities by the colour, and saturating-add them to the pixels
  for (uint8_t i = 0; i < 4; i++) 
  {
    uint16_t xy = XYRev((x >> 8) + (i & 1), (y >> 8) + ((i >> 1) & 1));
    LEDARRAY3[xy].r = qadd8(LEDARRAY3[xy].r, col->r * wu[i] >> 8);
    LEDARRAY3[xy].g = qadd8(LEDARRAY3[xy].g, col->g * wu[i] >> 8);
    LEDARRAY3[xy].b = qadd8(LEDARRAY3[xy].b, col->b * wu[i] >> 8);
  }
}

void dBars_DrawBar(CRGB *LEDARRAY2, byte value, byte minimum, byte maximum, byte pos, CRGB color, bool Vert)
{
  if (Vert) 
  {
    for (int x = 0; x < map(value, minimum, maximum, 0, kMatrixWidth*256); x +=16) 
    {
      dBars_wu_pixel(LEDARRAY2, x, pos * 256, &color);
    }
  } 
  else 
  {
    //Serial.println((float)dbarsSR/100);
    if (isGlobalAudioReactive)
    {
      for (int y = 0; y < map(value, minimum, maximum, 0, ((float)dbarsSR/110)*kMatrixHeight*256); y +=16) 
        dBars_wu_pixel(LEDARRAY2, pos * 256, y, &color);
    }
    else
    {
      for (int y = 0; y < map(value, minimum, maximum, 0, kMatrixHeight*256); y +=16) 
        dBars_wu_pixel(LEDARRAY2, pos * 256, y, &color);
    }
    
  }
}

void runAllDBars(CRGB *LEDARRAY5)
{
    EVERY_N_MILLIS(10) 
    {
      blend(dBarsLeds1, dBarsLeds2, LEDARRAY5, NUM_LEDS, dBarsBlendAmount);
  
      if (dBarsSwap) 
      {
        if (dBarsBlendAmount < 255) dBarsBlendAmount+=dBarsBlendSteps;                   // Blend 'up' to source 2
      } else {
        if (dBarsBlendAmount > 0) dBarsBlendAmount-=dBarsBlendSteps;                     // Blend 'down' to source 1
      }
    }
    
    drawDBars1(dBarsLeds1);
    drawDBars2(dBarsLeds2);
}

void makeDBars(CRGB *LEDARRAY6)
{
  //Serial.print(dbarsSR); Serial.print(" - "); Serial.print(audioSampleMax); Serial.print(" - ");  Serial.println(currentGVolume); 
  if (currentEffect == idxDrawBars && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
//    if (audioSampleAvg*currentGVolume >= 80)
      dbarsSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//    else
//      dbarsSR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) dbarsSR = ((dbarsOldSR*2)+dbarsSR)/3;
        else dbarsSR = ((dbarsOldSR*1)+dbarsSR)/2;
      }
      //FastLED.setBrightness(dbarsSR);
  }
  
  EVERY_N_SECONDS(10)
  {
    dBarsSwap = !dBarsSwap;
    if (dBarsSwap) dBars2Setup = true; else dBars1Setup = true;
  }
  runAllDBars(LEDARRAY6);
  if (isGlobalAudioReactive) dbarsOldSR = dbarsSR;
}

void drawDBars1(CRGB *LEDARRAY1)
{
  if (dBars1Setup) 
  {
    dBars1Setup = false;
    
    random16_set_seed(8934);
    random16_add_entropy(analogRead(32));
    
    for (byte i = 0; i < dBars_Array; i++) 
    {
      dBars1Speed[i] = random(30, 75);
      dBars1Col[i] = random(255);
      dBars1Min[i] = random(0, 32);
      //dBars1Min[i] = 0;
      dBars1Max[i] = random(64, 255);
      dBars1Val[i] = 1;
    }
  }
  
  //FastLED.clear();
  for (uint8_t a=0; a<NUM_LEDS; a++) LEDARRAY1[a] = CRGB(0,0,0);
  
  if (dBars_ROT) 
  {
    for (byte y = 0; y < kMatrixHeight; y++) 
    {
      dBars1Val[y] = beatsin8(dBars1Speed[y], dBars1Min[y], dBars1Max[y]);
      dBars_DrawBar(LEDARRAY1, dBars1Val[y], dBars1Min[y], dBars1Max[y], y, CHSV(dBars1Col[y],255,(currentBrightness+currentBrightness+maxBrightness)/3), 1);
    }
  } 
  else 
  {
    for (byte x = 0; x < kMatrixWidth; x++) 
    {
      dBars1Val[x] = beatsin8(dBars1Speed[x], dBars1Min[x], dBars1Max[x]);
      dBars_DrawBar(LEDARRAY1, dBars1Val[x], dBars1Min[x], dBars1Max[x], x, CHSV(dBars1Col[x],255,(currentBrightness+currentBrightness+maxBrightness)/3), 0);
    }
  }
  //Cblur2d(LEDARRAY1, kMatrixWidth, kMatrixHeight, 64);
  FastLED.show();
}

void drawDBars2(CRGB *LEDARRAY4)
{
  if (dBars2Setup) 
  {
    dBars2Setup = false;
    
    random16_set_seed(8934);
    random16_add_entropy(analogRead(32));
    
    for (byte i = 0; i < dBars_Array; i++) 
    {
      dBars2Speed[i] = random(30, 75);
      dBars2Col[i] = random(255);
      dBars2Min[i] = random(0, 32);
      //dBars2Min[i] = 0;
      dBars2Max[i] = random(64, 255);
      //dBars2Max[i] = audioSampleAvg;
      dBars2Val[i] = 1;
    }
  }
  
  //FastLED.clear();
  for (uint8_t a=0; a<NUM_LEDS; a++) LEDARRAY4[a] = CRGB(0,0,0);
  
  if (dBars_ROT) 
  {
    for (byte y = 0; y < kMatrixHeight; y++) 
    {
      dBars2Val[y] = beatsin8(dBars2Speed[y], dBars2Min[y], dBars2Max[y]);
      dBars_DrawBar(LEDARRAY4, dBars2Val[y], dBars2Min[y], dBars2Max[y], y, CHSV(dBars2Col[y],255,(currentBrightness+currentBrightness+maxBrightness)/3), 1);
    }
  } 
  else 
  {
    for (byte x = 0; x < kMatrixWidth; x++) 
    {
      dBars2Val[x] = beatsin8(dBars2Speed[x], dBars2Min[x], dBars2Max[x]);
      dBars_DrawBar(LEDARRAY4, dBars2Val[x], dBars2Min[x], dBars2Max[x], x, CHSV(dBars2Col[x],255,(currentBrightness+currentBrightness+maxBrightness)/3), 0);
    }
  }
  //Cblur2d(LEDARRAY4, kMatrixWidth, kMatrixHeight, 64);
  FastLED.show();
}
// EOF DRAWBARS CODES //


// RGBHype CODES //
void hypChangeHue(bool isUp)
{
  if (isUp)
    currentHypHue = addmod8(currentHypHue, stepHypHue, maxHypHue);
  else
    if (currentHypHue>=minHypHue+stepHypHue) currentHypHue-=stepHypHue; else currentHypHue = maxHypHue;
}

uint8_t hypSR;
uint8_t hypOldSR=0;
void makeHyp(CRGB *LEDARRAY)
{
  
  if (currentEffect == idxRGBHype && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
      hypSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) hypSR = ((hypOldSR*4)+hypSR)/5;
        else hypSR = ((hypOldSR*4)+hypSR)/5;
      }
      FastLED.setBrightness(hypSR);
  }

//  if (hypAutoHue)
//  {
//    EVERY_N_SECONDS(HYP_SECONDS_PER_HUE) 
//    {
//      hypChangeHue(true);
//    }
//  }

  int a = millis()/8;
  for (int x = 0; x < kMatrixWidth; x++) 
  {
    for (int y = 0; y < kMatrixHeight; y++) 
    {
      double red   = exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)];
      double green = exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2];
      double blue  = exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)];

      //leds[XY(x, y)] = ColorFromPalette(hypCurrentPalette, (rgb2hsv_precise(CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]))).h, (rgb2hsv_precise(CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]))).v, LINEARBLEND);
      //leds[XY(x, y)] = CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]);
      
      //if (currentHypHue == 0)
      //  LEDARRAY[XY(x, y)] = CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]);
      //else
      
      //LEDARRAY[XY(x, y)] = CHSV((rgb2hsv_precise(CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]))).h + currentHypHue, (rgb2hsv_precise(CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]))).s, (rgb2hsv_precise(CRGB(exp_gamma[sin8(cos8(x*8+a/3)+sin8(y*8+a/4)+a)], exp_gamma[(sin8(x*16+a/3)+cos8(y*8+a/2))/2], exp_gamma[sin8((x-8)*cos8((y+20)*4)/4+a)]))).v);

      LEDARRAY[XY(x, y)] = CRGB(red, green, blue);
    }
  }
  //Cblur2d(leds, kMatrixWidth, kMatrixHeight, 16);
  FastLED.show();
  if (isGlobalAudioReactive) { hypOldSR = hypSR; }
  if (toSleep || toWakeUp) delay(33);
}
// EOF RGBHype CODES //


// COLORWAVES CODES //
void colorwaves(CRGB* ledarray, uint16_t numLeds, CRGBPalette16& palette)
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t sat8 = beatsin88( 87, 220, 250);
  //uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 300, 1500);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < numLeds; i++) 
  {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;
    uint16_t h16_128 = hue16 >> 7;
    if( h16_128 & 0x100) 
    {
      hue8 = 255 - (h16_128 >> 1);
    } 
    else 
    {
      hue8 = h16_128 >> 1;
    }

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    uint8_t index = hue8;
    //index = triwave8( index);
    index = scale8( index, 240);

    //Serial.println(bri8);

    CRGB newcolor = ColorFromPalette(palette, index, (bri8+currentBrightness)/2);
    //CRGB newcolor = ColorFromPalette(cwCurrentPalette, index, bri8);

    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend( ledarray[pixelnumber], newcolor, 128);
  }
}

uint8_t cwSR;
uint8_t cwOldSR=0;
void makeCW(CRGB *LEDARRAY1)
{
  if (currentEffect == idxColorWaves && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
//    if (audioSampleAvg*currentGVolume >= 80)
      cwSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness)), 0, (currentBrightness));
//    else
//      cwSR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) cwSR = ((cwOldSR*3)+cwSR)/4;
        else cwSR = ((cwOldSR*3)+cwSR)/4;
      }
      FastLED.setBrightness(cwSR);
  }

  if (cwAutoPalette)
  {
    EVERY_N_SECONDS(CW_SECONDS_PER_PALETTE) 
    {
      cwChangePalette(true);
    }
  }

  EVERY_N_MILLISECONDS(40) 
  {
    nblendPaletteTowardPalette(cwCurrentPalette, cwTargetPalette, 16);
  }
  
  colorwaves(LEDARRAY1, NUM_LEDS, cwCurrentPalette);
  FastLED.show();
  if (isGlobalAudioReactive) { cwOldSR = cwSR; }
  if (toSleep || toWakeUp) delay(33);
}
// EOF COLORWAVES CODES //


// SUPERNOVA CODES //
uint8_t snovaSR;
uint8_t snovaOldSR = 0;

void snovaChangeHue()
{
  if (currentsnovaHue < 255) currentsnovaHue += stepsnovaHue;
  else currentsnovaHue = 0;
}

uint32_t snovaGetPixColor(CRGB *LEDARRAY5, uint32_t thisSegm)
{
  uint32_t thisPixel = thisSegm;// * SEGMENTS;
  if (thisPixel > NUM_LEDS - 1) return 0;
  return (((uint32_t)LEDARRAY5[thisPixel].r << 16) | ((uint32_t)LEDARRAY5[thisPixel].g << 8 ) | (uint32_t)LEDARRAY5[thisPixel].b);
}

uint32_t snovaGetPixColorXY(CRGB * LEDARRAY4, uint8_t x, uint8_t y)
{
  return snovaGetPixColor(LEDARRAY4, XY(x, y));
}

void snovaDrawPixelXY(CRGB *LEDARRAY3, int8_t x, int8_t y, CRGB color)
{
  if (x < 0 || x > (kMatrixWidth - 1) || y < 0 || y > (kMatrixHeight - 1)) return;
  uint32_t thisPixel = XY((uint8_t)x, (uint8_t)y);// * SEGMENTS; 
  LEDARRAY3[thisPixel] = color;  
}

void snovaDrawPixelXYF(CRGB *LEDARRAY2, float x, float y, CRGB color)
{
  uint8_t xx = (x - (int)x) * 255, yy = (y - (int)y) * 255, ix = 255 - xx, iy = 255 - yy;
  #define snova_WU_WEIGHT(a,b) ((uint8_t) (((a)*(b)+(a)+(b))>>8))
  
  uint8_t wu[4] = {snova_WU_WEIGHT(ix, iy), snova_WU_WEIGHT(xx, iy),
                   snova_WU_WEIGHT(ix, yy), snova_WU_WEIGHT(xx, yy)};
                   
  for (uint8_t i = 0; i < 4; i++) {
    int16_t xn = x + (i & 1), yn = y + ((i >> 1) & 1);
    CRGB clr = snovaGetPixColorXY(LEDARRAY2, xn, yn);
    clr.r = qadd8(clr.r, (color.r * wu[i]) >> 8);
    clr.g = qadd8(clr.g, (color.g * wu[i]) >> 8);
    clr.b = qadd8(clr.b, (color.b * wu[i]) >> 8);
    snovaDrawPixelXY(LEDARRAY2, xn, yn, clr);
  }
}

uint8_t snovaScale8(uint8_t x) 
{
  uint8_t x8 = x % 8U;
  uint8_t x4 = x8 % 4U;
  if (x4 == 0U)
    if (x8 == 0U)       return 0U;
    else                return 255U;
    
  else if (x8 < 4U)     return (1U   + x4 * 72U);
                        return (253U - x4 * 72U);
}

float snovaSQRT3(const float x)
{
  union
  {
    int i;
    float x;
  } u;

  u.x = x;
  u.i = (1<<29) + (u.i >> 1) - (1<<22);
  return u.x;
}

void snovaParticlesUpdate(uint8_t i)
{
  //apply velocity
  snova_PosX[i] += snova_SpeedX[i];
  snova_PosY[i] += snova_SpeedY[i];
  if(snovaState[i] == 0 || snova_PosX[i] <= -1 || snova_PosX[i] >= kMatrixWidth || snova_PosY[i] <= -1 || snova_PosY[i] >= kMatrixHeight) 
    snovaIsShift[i] = false;
}

void snovaStarfieldEmit(uint8_t i)
{
  random16_set_seed(65535);
  random16_add_entropy(analogRead(32));

  if (snovaHueValue++ & 0x01)
     snovaHueValue2+=1;//counter++;

  snova_PosX[i] = kMatrixWidth * 0.5;
  snova_PosY[i] = kMatrixHeight * 0.5;
  //snova_SpeedX[i] = (((float)random8()-127.)/512.);
  snova_SpeedX[i] = (((float)random8()-127.)/4096.);
  //snova_SpeedY[i] = sqrt(0.0626-snova_SpeedX[i]*snova_SpeedX[i]);
  snova_SpeedY[i] = sqrt((currentsnovaSpeed * 0.00033)-snova_SpeedX[i]*snova_SpeedX[i]);
  if(random8(2U)) 
  { 
    snova_SpeedY[i]=-snova_SpeedY[i]; 
  }
  
  if (!isGlobalAudioReactive)
    snovaState[i] = random8(1, 250); // random8(minLife, maxLife);// particle->ttl  
  else
    snovaState[i] = random8(1, snovaSR); 
  
  //Serial.println(snovaSR);
  
  snovaHueArr[i] = snovaHueValue2; 
  snovaIsShift[i] = true;
}

void initsnova()
{
    snovaLoading = false;   
    snovaEnlargedObjectNUM = 200;
    
    if (snovaEnlargedObjectNUM > snovaMAX_COUNT) snovaEnlargedObjectNUM = 200U;
    snovaDeltaValue = snovaEnlargedObjectNUM / (snovaSQRT3(snova_CENTER_X_MAJOR*snova_CENTER_X_MAJOR + snova_CENTER_Y_MAJOR*snova_CENTER_Y_MAJOR) * 4U) + 1U;
    for(int i = 0; i<snovaEnlargedObjectNUM; i++)
      snovaIsShift[i] = false;
}


void makesnova(CRGB *LEDARRAY1)
{
  double cHue;
  CHSV hsv;

  if (currentEffect == idxSNova && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    snovaSR = constrain(map(audioSampleAvg*audioSampleAvg*currentGVolume, 0, audioSampleMax*audioSampleMax*currentGVolume, 1, 250), 1, 250);

    if (audioSampleAvg > 0)
      snovaSR = ((snovaOldSR*2)+snovaSR)/3;
    //FastLED.setBrightness(SR);
  }

  //Serial.print(audioSampleAvg); Serial.print(" : ");Serial.println(snovaSR);
  
  if (snovaAutoHue)
  {
    EVERY_N_MILLIS(500)
    {
      snovaChangeHue();
    }
  }

  snovaStep = -1;
  nscale8(LEDARRAY1, NUM_LEDS, 200);
  for(int i = 0; i<snovaEnlargedObjectNUM; i++) 
  {
    if (!snovaIsShift[i] && snovaStep) 
    {      
      snovaStarfieldEmit(i);
      snovaStep-=1;
    }
    if (snovaIsShift[i])
    {
      snovaParticlesUpdate(i);

      hsv = rgb2hsv_precise(ColorFromPalette (LavaColors_p, snovaHueArr[i], currentBrightness, LINEARBLEND) );
      
      cHue = hsv.h + currentsnovaHue > 254 ? 255 - (hsv.h + currentsnovaHue) : hsv.h + currentsnovaHue;
      
      CRGB baseRGB = CHSV(cHue, hsv.s, hsv.v);

      //CRGB baseRGB = ColorFromPalette(HeatColors_p, snovaHueArr[i], currentBrightness, LINEARBLEND);
      
      baseRGB.nscale8(snovaState[i]);
      snovaDrawPixelXYF(LEDARRAY1, snova_PosX[i], snova_PosY[i], baseRGB);
    }
  }
  FastLED.show();
  if (isGlobalAudioReactive) snovaOldSR = snovaSR;
}
// EOF SUPERNOVA CODES //


// FIRE2 CODES //
// ============= Эффект Огонь 2021 вариант 2 с фиксированным масштабом по оси Y ===============
// (c) SottNick
// На основе алгоритма https://editor.soulmatelights.com/gallery/546-fire
// by Stepko

void makeFire2(CRGB *LEDARRAY1)
{
  if (Fire2AutoPalette)
  {
    EVERY_N_SECONDS(10)
    {
      Fire2ChangePalette();
    }
  }
  
  runAllFire2(LEDARRAY1);
}

void runAllFire2(CRGB *LEDARRAY20)
{
    EVERY_N_MILLIS(10) 
    {
      blend(Fire2Leds1, Fire2Leds2, LEDARRAY20, NUM_LEDS, Fire2BlendAmount);
  
      if (Fire2Swap) 
      {
        if (Fire2BlendAmount < 255) Fire2BlendAmount+=Fire2BlendSteps;                   // Blend 'up' to source 2
      } 
      else 
      {
        if (Fire2BlendAmount > 0) Fire2BlendAmount-=Fire2BlendSteps;                     // Blend 'down' to source 1
      }
    }
    
    drawFire21(Fire2Leds1);
    drawFire22(Fire2Leds2);
}

void drawFire21(CRGB *LEDARRAY21)
{
  if (Fire2Loading1)
  { 
    if (Fire2FirstLoad)
    {
        Fire2Scale1 = Fire2Scale;
        Fire2Speed1 = Fire2Speed;
        currentFire2Palette1 = Fire2Palette[Fire2PaletteIndex];
        Fire2FirstLoad = false;
    }
    else
    {
      random16_set_seed(8934);
      random16_add_entropy(analogRead(32));
      Fire2Scale1 = 1+random8(99);
      Fire2Speed1 = 2+random8(169);

      if (Fire2Scale1 > 100U) Fire2Scale1 = 100U;
      Fire2PaletteIndex1 = (uint8_t)(Fire2Scale1/100.0F*((sizeof(Fire2Palette)/sizeof(TProgmemRGBPalette16 *))-0.01F));
      currentFire2Palette1 = Fire2Palette[Fire2PaletteIndex1];
      filesystem.saveToFile("/Fire2PaletteIndex.txt", Fire2PaletteIndex1); 
      filesystem.saveToFile("/Fire2Scale.txt", Fire2Scale1); 
      filesystem.saveToFile("/Fire2Speed.txt", Fire2Speed1); 
    }
    
    //Serial.println((uint8_t)(Fire2Scale/100.0F*((sizeof(Fire2Palette)/sizeof(TProgmemRGBPalette16 *))-0.01F)));

    Fire2Loading1 = false;
    if (Fire2Scale1 > 100U) Fire2Scale1 = 100U;
    
    Fire2Step1 = map(Fire2Speed1*Fire2Speed1, 1U, 65025U, (FIXED_FIRE2_SCALE_FOR_Y-1U)/2U+1U, FIXED_FIRE2_SCALE_FOR_Y * 18U + 44);
    Fire2DeltaValue1 = 0.7 * Fire2DeltaValue1 * Fire2DeltaValue1 + 31.3;
    Fire2_pcnt1 = map(Fire2Step1, 1U, 255U, 20U, 128U);
    Fire2DeltaHue1 = 0.7 * FIXED_FIRE2_SCALE_FOR_Y * FIXED_FIRE2_SCALE_FOR_Y + 31.3;
  }
  
  Fire2_ff_x1 += Fire2Step1;
  for (byte x = 0; x < kMatrixWidth; x++) 
  {
    for (byte y = 0; y < kMatrixHeight; y++) 
    {
      int16_t Bri1 = inoise8(x * Fire2DeltaValue1, (y * Fire2DeltaHue1) - Fire2_ff_x1, Fire2_ff_z1) - (y * (255 / kMatrixHeight));
      byte Col1 = Bri1;
      if (Bri1 < 0) 
        Bri1 = 0; 
      if (Bri1 != 0) 
        Bri1 = 256 - (Bri1 * 0.2);
      nblend(LEDARRAY21[XYRev(x, y)], ColorFromPalette(*currentFire2Palette1, Col1, Bri1), Fire2_pcnt1);
    }
  }
  if (!random8())
    Fire2_ff_z1++;
  FastLED.show();
}

void drawFire22(CRGB *LEDARRAY22)
{
  if (Fire2Loading2)
  { 
    random16_set_seed(8934);
    random16_add_entropy(analogRead(32));
    
    Fire2Scale2 = 1+random8(99);
    Fire2Speed2 = 2+random8(169);

    if (Fire2Scale2 > 100U) Fire2Scale2 = 100U;
    Fire2PaletteIndex2 = (uint8_t)(Fire2Scale2/100.0F*((sizeof(Fire2Palette)/sizeof(TProgmemRGBPalette16 *))-0.01F));
    currentFire2Palette2 = Fire2Palette[Fire2PaletteIndex2];

    filesystem.saveToFile("/Fire2PaletteIndex.txt", Fire2PaletteIndex2); 
    filesystem.saveToFile("/Fire2Scale.txt", Fire2Scale2);
    filesystem.saveToFile("/Fire2Speed.txt", Fire2Speed2);
    
    //Serial.println((uint8_t)(Fire2Scale/100.0F*((sizeof(Fire2Palette)/sizeof(TProgmemRGBPalette16 *))-0.01F)));

    Fire2Loading2 = false;
    if (Fire2Scale2 > 100U) Fire2Scale2 = 100U;
    
    Fire2Step2 = map(Fire2Speed2*Fire2Speed2, 1U, 65025U, (FIXED_FIRE2_SCALE_FOR_Y-1U)/2U+1U, FIXED_FIRE2_SCALE_FOR_Y * 18U + 44);
    Fire2DeltaValue2 = 0.7 * Fire2DeltaValue2 * Fire2DeltaValue2 + 31.3;
    Fire2_pcnt2 = map(Fire2Step2, 1U, 255U, 20U, 128U);
    Fire2DeltaHue2 = 0.7 * FIXED_FIRE2_SCALE_FOR_Y * FIXED_FIRE2_SCALE_FOR_Y + 31.3;
  }
  
  Fire2_ff_x2 += Fire2Step2;
  for (byte x = 0; x < kMatrixWidth; x++) 
  {
    for (byte y = 0; y < kMatrixHeight; y++) 
    {
      int16_t Bri2 = inoise8(x * Fire2DeltaValue2, (y * Fire2DeltaHue2) - Fire2_ff_x2, Fire2_ff_z2) - (y * (255 / kMatrixHeight));
      byte Col2 = Bri2;
      if (Bri2 < 0) 
        Bri2 = 0; 
      if (Bri2 != 0) 
        Bri2 = 256 - (Bri2 * 0.2);
      nblend(LEDARRAY22[XYRev(x, y)], ColorFromPalette(*currentFire2Palette2, Col2, Bri2), Fire2_pcnt2);
    }
  }
  if (!random8())
    Fire2_ff_z2++;
  FastLED.show();
}

// EOF FIRE2 CODES //

uint8_t pplasmaSR;
uint8_t pplasmaOldSR = 0;
void makePPlasma(CRGB *LEDarray)
{
  if (currentEffect == idxPPlasma && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    pplasmaSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, currentBrightness), 0, currentBrightness);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) pplasmaSR = ((pplasmaOldSR*2)+pplasmaSR)/3;
      else pplasmaSR = ((pplasmaOldSR*1)+pplasmaSR)/2;
    }
    FastLED.setBrightness(pplasmaSR);
  }

  uint16_t ms = millis();
  for (int i = 0; i < kMatrixWidth; i++) 
  {
    for (int j = 0; j < kMatrixHeight; j++) 
    {
      uint8_t index = inoise8(i * 41, j * 41, ms / 4);  // x and y not change, only change z value with time increment for nice plasma looking noise
      LEDarray[XY (i, j)] = CHSV((index + ms / 200) % 255, 255, (currentBrightness+currentBrightness+maxBrightness)/3); // within palette
      // leds[XY (i, j)] = ColorFromPalette (RainbowColors_p, (index + ms / 200) % 255, currentBrightness ); // with palette
    }
  }
  delay(1);
  FastLED.show();
  if (isGlobalAudioReactive) pplasmaOldSR = pplasmaSR;
  if (toSleep || toWakeUp) delay(33);
}  


uint16_t easingSR;
uint16_t easingOldSR = 0;
void makeEasing(CRGB *LEDarray)
{
  static uint8_t easeOutVal = 0;
  static uint8_t easeInVal  = 0;
  static uint8_t lerpVal    = 0;


    if (currentEffect==idxEasing && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
        easingSR = constrain(audioSampleAvg*currentGVolume, 0, 240);

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) easingSR = ((easingOldSR*5)+easingSR)/6;
        else easingSR = ((easingOldSR*2)+easingSR)/3;
      }

      //for (uint8_t a=0; a<NUM_LEDS; a++) LEDarray[a] = CRGB(CHSV(currentEasingHue, 255, 40));
      //FastLED.setBrightness(easingSR);
    }
  
  //Serial.println(SRTimer);
  if (!isLEDOFF)
  {
    uint16_t timing;
    if (isGlobalAudioReactive)
      timing = (currentEasingDelay+(700/(1+easingSR)))/2;
    else
      timing = currentEasingDelay;
      
    //EVERY_N_MILLIS_I(timeObj, currentEasingDelay)    // FastLED based non-blocking delay to update/display the sequence.
    EVERY_N_MILLIS_I(timeObj, timing)    // FastLED based non-blocking delay to update/display the sequence.
    {                           
      timeObj.setPeriod(timing);

      counterEasingHue++;
      if (counterEasingHue >= intervalEasingHue)
      {
        if (currentEasingHue < maxEasingHue) currentEasingHue+=stepEasingHue; else currentEasingHue = minEasingHue;
        counterEasingHue = 0;
      }
    
      easeOutVal = ease8InOutQuad(easeInVal);                     // Start with easeInVal at 0 and then go to 255 for the full easing.
      if (easeInVal<NUM_LEDS) easeInVal++; else easeInVal=0;
      lerpVal = lerp8by8(0, NUM_LEDS, easeOutVal);                // Map it to the number of LED's you have.
    
      LEDarray[lerpVal] = CRGB(CHSV(currentEasingHue, 255, 255));
      fadeToBlackBy(LEDarray, NUM_LEDS, 16);                          // 8 bit, 1 = slow fade, 255 = fast fade
    }
    if (isGlobalAudioReactive) easingOldSR = easingSR;
  }
  if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}

uint8_t aabarSR;
uint8_t aabarOldSR=0;
void makeAABar(CRGB *LEDarray)
{
  if (!isLEDOFF)
  {
    if (currentEffect == idxAABar && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
      {
//        if (audioSampleAvg*currentGVolume >= 80)
          aabarSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);
//        else
//          aabarSR = ((31*minBrightness) + constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3))/32 ;
  
        if (audioSampleAvg > 0)
        {
          if (!enableWifi) aabarSR = ((aabarOldSR*2)+aabarSR)/3;
          else aabarSR = ((aabarOldSR*1)+aabarSR)/2;
        }
        FastLED.setBrightness(aabarSR);
      }

    EVERY_N_MILLIS_I(timeObj7, 3*AABarFrameDelay)
    {
      timeObj7.setPeriod(3*AABarFrameDelay);
      aaBarF16pos += aaBarF16delta;
      if( aaBarF16pos >= (NUM_LEDS * 16)) 
      {
        aaBarF16pos -= (NUM_LEDS * 16);
      }
      memset8(LEDarray, 0, NUM_LEDS * sizeof(CRGB));
      aaBarFhue16 = aaBarFhue16 + 19;
      drawAABar(LEDarray, aaBarF16pos, aaBarWidth, aaBarFhue16 / 256);
       
      FastLED.show();
      //delay(AABarFrameDelay);
    }
    if (isGlobalAudioReactive) aabarOldSR = aabarSR;
  }
  if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}

void drawAABar(CRGB *LEDarray, int pos16, int width, uint8_t hue)
{
  int i = pos16 / 16; // convert from pos to raw pixel number
  uint8_t frac = pos16 & 0x0F; // extract the 'factional' part of the position 
  uint8_t firstpixelbrightness = 255 - (frac * 16);
  uint8_t lastpixelbrightness  = 255 - firstpixelbrightness;
  uint8_t bright;
  for( int n = 0; n <= width; n++) 
  {
    if(n == 0) 
    {
      bright = firstpixelbrightness;
    } 
    else if(n == width) 
    {
      bright = lastpixelbrightness;
    } 
    else 
    {
      bright = 255;
    }
    
    LEDarray[i] += CHSV(hue, 255, bright);
    i++; 
    if( i == NUM_LEDS) i = 0; // wrap around
  }
}

// make Kerosene //
void initKerosene()
{
  keroseneLowSin = 20;          // The location of the highest value of the sine wave is between 0 and 31. . .
  //keroseneGamma = 0.5;          // Tapering/keroseneGamma correction on the top half of the wave.
  keroseneGamma = 0;          // Tapering/keroseneGamma correction on the top half of the wave.
  keroseneMinBrightness =  2;   // Minimum brightness for the bottom half of the wave.
}

void drawKerosene(CRGB *LEDarray, CRGBPalette16& palette, uint8_t brightness)
{
  random16_set_seed(535);
  uint16_t sinOut;
  uint16_t pixBri;
  //CRGBPalette16 randomPal1, randomPal2;
 
  for (int i = 0; i < NUM_LEDS; i++) 
  {
    if (i < keroseneLowSin) 
    {
      sinOut = (127 * cos( PI + i * PI / keroseneLowSin) + 127.);
      pixBri = beatsin8(128 / 2 + random8() / 4, 128, 255, 0, random8());
      pixBri = pixBri * sinOut / 255;
      if (pixBri < keroseneMinBrightness) pixBri = keroseneMinBrightness;
    } 
    else 
    {
      float temp = (float)(i - keroseneLowSin) / (NUM_LEDS - keroseneLowSin - 1);
      sinOut = cos( PI * temp) * 128. + 127;
      sinOut = (float)(pow((float)sinOut / (float)255, keroseneGamma) * 255. + 0.5);
      pixBri = beatsin8(128 / 2 + random8() / 4, 128, 255, 0, random8());
      pixBri = pixBri * sinOut / 255;
    }

    uint8_t bri;

    if (isGlobalAudioReactive)
      bri = ((brightness*2) + pixBri)/3;
    else
      bri = pixBri;
    CRGB newcolor = ColorFromPalette(palette, i*20 + millis() / 100, bri, LINEARBLEND);
    
    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend(LEDarray[pixelnumber], newcolor, 128);
    //LEDarray[i] = ColorFromPalette(kerosenePalette[0], i * 20 + millis() / 100, pixBri, LINEARBLEND);
    //LEDarray[i] = newcolor;
  }
  //blur1d(LEDarray, NUM_LEDS, 128);
}

uint8_t keroseneSR;
uint8_t keroseneOldSR=0;
void makeKerosene(CRGB *LEDarray)
{
  if (currentEffect == idxKerosene && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
        keroseneSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

      //keroseneSR = ((keroseneOldSR*2)+keroseneSR)/3;
      //FastLED.setBrightness(keroseneSR);
    }

  //Serial.println(keroseneGradientPaletteCount);
  
  if (keroseneAutoPalette)
  {
    EVERY_N_SECONDS(20)
    {
      //if (kerosenePaletteIndex < kerosenePaletteSize-1) kerosenePaletteIndex++; else kerosenePaletteIndex = 1;
      keroseneChangePalette(true);
    }
  }

  EVERY_N_MILLISECONDS(40) 
  {
    nblendPaletteTowardPalette(keroseneCurrentPalette, keroseneTargetPalette, 16);
  }

  drawKerosene(LEDarray, keroseneCurrentPalette, keroseneSR);
  FastLED.show();

  if (isGlobalAudioReactive) keroseneOldSR = keroseneSR;
  if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}
// EOF make Kerosene //


// make randomColor //
//uint8_t deltahue1, deltahue2, deltahue3;
//uint16_t randomColorDeltaInterval = 30;

void setDeltahue()
{
    random16_set_seed(65535);
    random16_add_entropy(analogRead(32));
    deltahue1 = random8();

    random16_set_seed(65535);
    random16_add_entropy(analogRead(32));
    deltahue2 = random8();
  
    random16_set_seed(65535);
    random16_add_entropy(analogRead(32));
    deltahue3 = random8();
}

void setRandomPalette()
{
    randomColorPalette1[0] = CHSV((deltahue1+5)%255, 255, 128);
    randomColorPalette1[1] = CHSV((deltahue1+5)%255, 255, 143);
    randomColorPalette1[2] = CHSV((deltahue1+5)%255, 255, 166);
    randomColorPalette1[3] = CHSV((deltahue1+5)%255, 250, 181);
    randomColorPalette1[4] = CHSV((deltahue1+8)%255, 250, 194);
    randomColorPalette1[5] = CHSV((deltahue1+8)%255, 253, 214);
    randomColorPalette1[6] = CHSV((deltahue1+8)%255, 253, 227);
    randomColorPalette1[7] = CHSV((deltahue1+10)%255, 253, 237);
    randomColorPalette1[8] = CHSV((deltahue1+13)%255, 255, 250);
    randomColorPalette1[9] = CHSV((deltahue1+13)%255, 255, 253);
    randomColorPalette1[10] = CHSV((deltahue1+13)%255, 255, 255);
    randomColorPalette1[11] = CHSV((deltahue1+15)%255, 255, 255);
    randomColorPalette1[12] = CHSV((deltahue1+15)%255, 255, 255);
    randomColorPalette1[13] = CHSV((deltahue1+15)%255, 255, 255);
    randomColorPalette1[14] = CHSV((deltahue1+15)%255, 255, 255);
    randomColorPalette1[15] = CHSV((deltahue1+15)%255, 255, 255);
}

void initRandomColor()
{
  randomColorLowSin = 20;          // The location of the highest value of the sine wave is between 0 and 31. . .
  randomColorGamma = 0.5;          // Tapering/keroseneGamma correction on the top half of the wave.
  randomColorMinBrightness =  2;   // Minimum brightness for the bottom half of the wave.

  setDeltahue();
  setRandomPalette();
  setRandomColorInterval();
}

void randomColorChangePalette(CRGB *LEDarray)
{
  EVERY_N_MILLIS_I(timeObj, randomColorDeltaInterval)
  {
    timeObj.setPeriod(randomColorDeltaInterval);
    
    if (deltahue2 > deltahue1 && (abs(deltahue2 - deltahue1)<=127))
      deltahue1++;
    
    if (deltahue2 < deltahue1 && (abs(deltahue2 - deltahue1)<=127))
      deltahue1--;

    if (deltahue2 > deltahue1 && (abs(deltahue2 - deltahue1)>127))
    {
      if (deltahue1 > 0)
      {
        deltahue1--;
      }
      else deltahue1 = 255;
    }
    
    if (deltahue2 < deltahue1 && (abs(deltahue2 - deltahue1)>127))
    {
      if (deltahue1 < 255)
        deltahue1++;
      if (deltahue1 >= 255)
        deltahue1 = 0;
    }
    //Serial.print(deltahue2); Serial.print(" - "); Serial.println(deltahue1);

    setRandomPalette();
  }
}

void drawRandomColor(CRGB *LEDarray, uint8_t brightness)
{
  random16_set_seed(535);
  uint16_t sinOut;
  uint16_t pixBri;
 
  for (uint8_t j=0; j<kMatrixWidth; j++)
  {
    //for (int i = 0; i < NUM_LEDS; i++) 
    for (uint8_t i = 0; i < kMatrixHeight; i++) 
    {
      if (i < randomColorLowSin) 
      {
        sinOut = (127 * cos( PI + i * PI / randomColorLowSin) + 127.);
        //pixBri = beatsin8(128 / 2 + random8() / 4, 64, 255, 0, random8());
        pixBri = beatsin8(128 / 2 + random8() / 4, currentBrightness, 255, 0, random8());
        pixBri = pixBri * sinOut / 255;
        if (pixBri < randomColorMinBrightness) pixBri = randomColorMinBrightness;
      } 
      else 
      {
        //float temp = (float)(i - randomColorLowSin) / (NUM_LEDS - randomColorLowSin - 1);
        float temp = (float)(i - randomColorLowSin) / (kMatrixHeight - randomColorLowSin - 1);
        sinOut = cos( PI * temp) * 128. + 127;
        sinOut = (float)(pow((float)sinOut / (float)255, randomColorGamma) * 255. + 0.5);
        //pixBri = beatsin8(128 / 2 + random8() / 4, 64, 255, 0, random8());
        pixBri = beatsin8(128 / 2 + random8() / 4, currentBrightness, 255, 0, random8());
        pixBri = pixBri * sinOut / 255;
      }
      
      uint8_t Bri2;
      if (isGlobalAudioReactive)
        Bri2 = ((brightness*3) + pixBri)/4;
      else
        Bri2 = pixBri;
        
      if (i< (kMatrixHeight-1) && i> 1)
        LEDarray[XY(j,i)] = ColorFromPalette(randomColorPalette1, i * 20 + millis() / 100, Bri2, LINEARBLEND);
    }
  }
  Cblur2d(LEDarray, kMatrixWidth, kMatrixHeight, 128);
}


uint8_t randomColorSR;
uint8_t randomColorOldSR=0;
void makeRandomColor(CRGB *LEDarray)
{
  if (currentEffect == idxRandomColor && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
    {
      randomColorSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

      if (audioSampleAvg > 0)
      {
        if (!enableWifi) randomColorSR = ((randomColorOldSR*2)+randomColorSR)/3;
        else randomColorSR = ((randomColorOldSR*1)+randomColorSR)/2;
      }
      //FastLED.setBrightness(constrain(randomColorSR*5, 0, maxBrightness));
      //FastLED.setBrightness(randomColorSR);
    }


  drawRandomColor(LEDarray, randomColorSR);
  FastLED.show();

  if (randomColorAutoPalette)
  {
    EVERY_N_SECONDS(20)
    {
      randomColorChangeDeltaHue();
    }
  }
  randomColorChangePalette(LEDarray);

  if (isGlobalAudioReactive) randomColorOldSR = randomColorSR;
  if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}
// EOF make randomColor //


// START PRIDE CODES //
uint8_t prideSR;
uint8_t prideOldSR=0;
void makePride(CRGB *LEDarray) 
{
  if (currentEffect == idxPride && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    prideSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) prideSR = ((prideOldSR*2)+prideSR)/3;
      else prideSR = ((prideOldSR*1)+prideSR)/2;
    }
  }

  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t currentBrightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t currentBrightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < NUM_LEDS; i++) 
  {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    currentBrightnesstheta16  += currentBrightnessthetainc16;
    uint16_t b16 = sin16( currentBrightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    CRGB newcolor;
    if (isGlobalAudioReactive)
      //newcolor = CHSV( hue8, sat8, constrain(currentBrightness+(prideSR*2), currentBrightness, maxBrightness));
      newcolor = CHSV( hue8, sat8, ((prideSR*3)+ bri8)/4);
    else 
      newcolor = CHSV( hue8, sat8, bri8);
    
    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend(LEDarray[pixelnumber], newcolor, 64);
  }
  FastLED.show();
  if (isGlobalAudioReactive) prideOldSR = prideSR;
  if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}
// EOF PRIDE CODES //



// START SOFTTWINKLES CODES //
uint8_t stwSR;
uint8_t stwOldSR = 0;
void make_softtwinkles(CRGB *LEDARRAY1)
{
  if (currentEffect == idxSoftTwinkles && isGlobalAudioReactive && !isLEDOFF && !toSleep && !toWakeUp)
  {
    stwSR = constrain(map(audioSampleAvg*currentGVolume, 0, audioSampleMax*currentGVolume, 0, (currentBrightness+currentBrightness+maxBrightness)/3), 0, (currentBrightness+currentBrightness+maxBrightness)/3);

    if (audioSampleAvg > 0)
    {
      if (!enableWifi) stwSR = ((stwOldSR*2)+stwSR)/3;
      else stwSR = ((stwOldSR*1)+stwSR)/2;
    }
    FastLED.setBrightness(stwSR);
  }

  // Soft, warm white twinkles all along the LEDs
  draw_softtwinkles(LEDARRAY1);
  FastLED.show();
  FastLED.delay(20);
  if (isGlobalAudioReactive) stwOldSR = stwSR;
}


void draw_softtwinkles(CRGB *LEDARRAY2)  // Mark Kriegsman (2014) - https://gist.github.com/kriegsman/99082f66a726bdff7776
{
  for( int i = 0; i < NUM_LEDS; i++) 
  {
    if( !LEDARRAY2[i]) continue; // skip black pixels
    if( LEDARRAY2[i].r & 1) 
    { // is red odd?
      LEDARRAY2[i] -= stwLightcolor; // darken if red is odd
    } 
    else 
    {
      LEDARRAY2[i] += stwLightcolor; // brighten if red is even
    }
  }
  
  if( random8() < STW_DENSITY) 
  {
    int j = random16(NUM_LEDS);
    if( !LEDARRAY2[j] ) LEDARRAY2[j] = stwLightcolor;
  }
}
// EOF SOFTTWINKLES CODES //

////////////// FFT PATTERN ///////////////
void rainbowBars(CRGB *LEDarray, int band, int barHeight)
{
  int xStart = BAR_WIDTH * band;

  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int y = TOP; y >= TOP - barHeight; y--) 
    {
      LEDarray[XY(x, y)] = CRGB(CHSV((x / BAR_WIDTH) * (255 / NUM_BANDS), currentSaturation*255, 255));
      if (band % 2 == 1)
          LEDarray[XY(x, y)] = CRGB::Black;
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}


void configBars(CRGB *LEDarray, int band, int barHeight)
{
  int xStart = BAR_WIDTH * band;
  //int colorIndex;
  double cHue;

  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int z = 0; z < kMatrixHeight; z++) { LEDarray[XY(x, z)] = CRGB(0, 0, 0); }
    for (int y = TOP; y >= TOP - barHeight; y--) 
    {
      if (x == selectedBand)
        LEDarray[XY(x,y)] = CRGB::Red;
      else
        LEDarray[XY(x,y)] = CRGB::Blue;
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}


void whitePeak(CRGB *LEDarray, int band)
{
  int xStart = BAR_WIDTH * band;
  int peakHeight = TOP - peak[band] - 1;

  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int y = 0; y < kMatrixHeight; y++) { LEDarray[XY(x, y)] = CRGB(0, 0, 0); }
    LEDarray[XY(x, peakHeight)] = CRGB(200, 200, 200);
    if (band % 2 == 1)
        LEDarray[XY(x, peakHeight)] = CRGB::Black;
  }
  //FastLED.show();
}

void outrunPeak(CRGB *LEDarray, int band)
{
  int xStart = BAR_WIDTH * band;
  int peakHeight = TOP - peak[band] - 1;
  int colorIndex;
  
  if (!isLEDOFF)
  {
    for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
    {
      for (int y = 0; y < kMatrixHeight; y++) { LEDarray[XY(x, y)] = CRGB(0, 0, 0); }
      colorIndex = peakHeight * (255 / kMatrixHeight);
      LEDarray[XY(x, peakHeight)] = ColorFromPalette (outrunPal, colorIndex, (currentBrightness+currentBrightness+maxBrightness)/3);
      if (band % 2 == 1)
          LEDarray[XY(x, peakHeight)] = CRGB::Black;
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}


void purpleBars(CRGB *LEDarray, int band, int barHeight)
{
  int xStart = BAR_WIDTH * band;
  int colorIndex;
  double cHue;
  CHSV hsv;

  if ((purpleBarsAutoHue) && (!isLEDOFF))
  {
     //Serial.println("AUTOHUE");
     EVERY_N_MILLIS(intervalPurpleBarsHue) { HuePalUpAuto(); }
  }
  
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int y = TOP; y >= TOP - barHeight; y--) 
    {
      colorIndex = y * (255 / (barHeight + 1));
        
      hsv = rgb2hsv_precise(ColorFromPalette (purplePal, colorIndex, (currentBrightness+currentBrightness+maxBrightness)/3));
      //cHue = hsv.h + currentPurpleBarsHue;
      cHue = hsv.h + currentPurpleBarsHue > 254 ? 255 - (hsv.h + currentPurpleBarsHue) : hsv.h + currentPurpleBarsHue;
      LEDarray[XY(x,y)] = CHSV(cHue, hsv.s, hsv.v);
      if (band % 2 == 1)
          LEDarray[XY(x, y)] = CRGB::Black;
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}


void centerBars(CRGB *LEDarray, int band, int barHeight)
{
  int xStart = BAR_WIDTH * band;
  int colorIndex;
  double cHue;
  CHSV hsv;
  
  //uint8_t maxChanges = 14; 
  
  EVERY_N_MILLIS(intervalCBHue)
  {
    if ((CBAutoHue) && (!isLEDOFF)) HuePalUpAuto();
  }
 
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int z = 0; z < kMatrixHeight; z++) { LEDarray[XY(x, z)] = CRGB(0, 0, 0); }
    if (barHeight % 2 == 0) barHeight--;
    int yStart = ((kMatrixHeight - barHeight) / 2 );
    for (int y = yStart; y <= (yStart + barHeight); y++) 
    {
//      if (round(barHeight/2) == 0)
//        colorIndex = map((abs((round(barHeight/2))-(y - yStart))), 0, 1, 0, 10) ;
//      else
//        colorIndex = map((abs((round(barHeight/2))-(y - yStart))), 0, round(barHeight/2), 0, 10) ;
//        LEDarray[XY(x, y)] = CRGB(CBColors[colorIndex]);
        
        colorIndex = constrain((y - yStart) * (255 / barHeight), 0, 255);
        hsv = rgb2hsv_precise(ColorFromPalette(heatPal, colorIndex));
        
        //cHue = hsv.h + currentCBHue;
        cHue = hsv.h + currentCBHue > 254 ? 255 - (hsv.h + currentCBHue) : hsv.h + currentCBHue;
        LEDarray[XY(x, y)] = CHSV(cHue, hsv.s, hsv.v);
        if (band % 2 == 1)
            LEDarray[XY(x, y)] = CRGB::Black;
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}

//// SIDEBARS CODE ////
void sideBars(CRGB *LEDarray, int band, int barHeight)
{
  int xStart = BAR_WIDTH * band;
  int colorIndex;
//  double cHue;
  
  if (SBAutoPalette)
  {
    EVERY_N_SECONDS(14)
    {
      //if (SBPaletteIndex < SBPaletteSize-1) SBPaletteIndex++; else SBPaletteIndex = 1;
      SBChangePalette(true);
    }
  }

  EVERY_N_MILLISECONDS(40) 
  {
    nblendPaletteTowardPalette(SBCurrentPalette, SBTargetPalette, 16);
  }
 
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int z = 0; z < kMatrixHeight; z++) { LEDarray[XY(x, z)] = CRGB(0, 0, 0); }
//    if (barHeight % 2 == 1) barHeight--;
    
    int yStart = 0;
    
    //for (int y = yStart; y <= (yStart + (barHeight/2)); y++) 
    for (int y = yStart; y <= (yStart + (barHeight)); y++) 
    {
      colorIndex = y * (255 / ((barHeight)+1));
      LEDarray[XYRev(x, y)] = x % 2 == 1 ? CRGB::Black : ColorFromPalette(SBCurrentPalette, colorIndex, (currentBrightness+currentBrightness+maxBrightness)/3, LINEARBLEND);
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}

///// EOF SIDEBARS CODE //////

void changingBars(CRGB *LEDarray, int band, int barHeight)
{
  int xStart = BAR_WIDTH * band;
  
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    for (int z = 0; z < kMatrixHeight; z++) { LEDarray[XY(x, z)] = CRGB(0, 0, 0); }
    for (int y = TOP; y >= TOP - barHeight; y--) 
    {
      LEDarray[XY(x, y)] = CHSV(y * (255 / kMatrixHeight) + colorTimer, currentSaturation*255, 255);
      if (band % 2 == 1)
          LEDarray[XY(x, y)] = CRGB::Black;
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}

void WFallSR(CRGB *LEDarray, int band)
{
  int xStart = BAR_WIDTH * band;
  double highestBandValue = 45000;        // Set this to calibrate your waterfall

  // Draw bottom line
  for (int x = xStart; x < xStart + BAR_WIDTH; x++) 
  {
    //for (int z = 0; z < kMatrixHeight; z++) { LEDarray[XY(x, z)] = CRGB(0, 0, 0); }
    LEDarray[XY(x, 0)] = CHSV(constrain(map(bandValues[band],0,highestBandValue,160,0),0,160), currentSaturation*255, 255);
    //LEDarray[XY(x, 0)] = CHSV(constrain(map(bandValues[band],0,highestBandValue,160,0),0,160), currentSaturation*255, currentBrightness);
    if (band % 2 == 1)
        LEDarray[XY(x, 0)] = CRGB::Black;
  }

  // Move screen up starting at 2nd row from top
  if (band == NUM_BANDS - 1)
  {
    for (int y = kMatrixHeight - 2; y >= 0; y--) 
    {
      for (int x = 0; x < kMatrixWidth; x++) 
      {
        int pixelIndexY = XY(x, y + 1);
        int pixelIndex = XY(x, y);
        LEDarray[pixelIndexY] = LEDarray[pixelIndex];
      }
    }
  }
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}
// EOF PATTERNS //

#endif
