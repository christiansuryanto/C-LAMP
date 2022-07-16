/* Control.h - provide functions to handle LedStrip */

#ifndef CONTROL_H
#define CONTROL_H

uint8_t deltahue1, deltahue2, deltahue3;
uint16_t randomColorDeltaInterval = 30;

// old Method to shift hue
uint8_t         Red;
uint8_t         Green;
uint8_t         Blue;
double          Hue, Saturation, Lighting, Value;
String          sHex;
uint32_t        hex;

extern eSPIFFS filesystem;

void Cblur2d( CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount);
void CblurCols( CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount);
void CblurRows(CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount);
void clearLED(CRGB *LEDarray);
void blankPattern(CRGB *LEDarray);

void nextPattern(bool isUp);
void effectDown();
void effectUp();
void toggleAutoEffects();
void brightnessDown();
void brightnessUp();
void volDown();
void volUp();
void toggleAutoHuePal();
void setLEDDutyCycle();
void toggleGlobalAudioReactive();
void saturationDown();
void saturationUp();
void HuePalDown();
void HuePalUp();
void HuePalUpAuto();
void animSpeedDown();
void animSpeedUp();

void setTrailHue(double cHue);
void trailHueReset();
void nexusChangePalette(bool isUp);
void nexusSetPalette();
void cwChangePalette(bool isUp);
void Fire2ChangePalette();
void randomColorChangeDeltaHue();
void SBChangePalette(bool isUp);
void initPaint_runtimeSR();
void initPaint_runtimeNOSR();
void keroseneChangePalette(bool isUp);
void setDeltahue3();
void setRandomColorInterval();
long strHexToI(String recv);


// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //

/// BLUR2D REPLACEMENT FOR VERTICAL MATRIX ///
void Cblur2d( CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount)
{
    CblurCols(leds, width, height, blur_amount);
    CblurRows(leds, width, height, blur_amount);
}

// blurCols: perform a blur1d on every column of a rectangular matrix
void CblurCols( CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount)
{
    for( uint8_t col = 0; col < width; ++col) {
        CRGB* col_base = leds + col * height;
        blur1d( col_base, height, blur_amount);
    }
}

// CblurRows: perform a blur1d on each row of a rectangular matrix
void CblurRows(CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount)
{
    // blur rows
    uint8_t keep = 255 - blur_amount;
    uint8_t seep = blur_amount >> 1;
    for( uint8_t row = 0; row < height; ++row) {
        CRGB carryover = CRGB::Black;
        for( uint8_t i = 0; i < width; ++i) {
            CRGB cur = leds[XY(i, row)];
            CRGB part = cur;
            part.nscale8( seep);
            cur.nscale8( keep);
            cur += carryover;
            if( i) leds[XY(i-1, row)] += part;
            leds[XY(i, row)] = cur;
            carryover = part;
        }
    }
}
/// EOF BLUR2D REPLACEMENT FOR VERTICAL MATRIX ///

void clearLED(CRGB *LEDarray)
{
  for (int i = 0; i < NUM_LEDS; i++) {
    //leds[i].nscale8(value);
    LEDarray[i] = CRGB(0,0,0);
  }
  FastLED.show();
}

void blankPattern(CRGB *LEDarray)
{
  for (int i = 0; i < NUM_LEDS; i++) LEDarray[i] = CRGB(CHSV(0, 0, minBrightness));
  //FastLED.show();
  //if (toSleep || toWakeUp) { delay(33); FastLED.show(); }
}

void nextPattern(bool isUp)
{
  //timerBri = millis();
  if (isUp) 
  {
    currentEffect = (currentEffect + 1) % (lastEffect + 1);
  }
  else 
  { 
    if (currentEffect > 0) currentEffect = (currentEffect - 1); 
    else currentEffect = lastEffect; 
  }

  if (isSwapped) sourceEffect = currentEffect;    // Determine which source array for new pattern
  else targetEffect = currentEffect;

  isSwapped = !isSwapped;                           // Swap source array for next time around
}

void effectDown()
{
  autoChangePatterns = false;
  if (currentEffect > 0) currentEffect--; else currentEffect = lastEffect;
}

void effectUp()
{
  autoChangePatterns = false;
  if (currentEffect < lastEffect) currentEffect++; else currentEffect = 0;
}

void toggleAutoEffects()
{
  isPaused = true;
  autoChangePatterns = !autoChangePatterns;
}

void brightnessDown()
{
  if (currentBrightness-10 > minBrightness) { currentBrightness-=10; FastLED.setBrightness(currentBrightness); }
}

void brightnessUp()
{
  if (currentBrightness+10 < maxBrightness) { currentBrightness+=10; FastLED.setBrightness(currentBrightness); }
}

void volDown()
{
    if (currentEffect >= idxSeparatorFFT) {if (currentAmplitude < maxAmplitude) currentAmplitude+=100;}
    else if (currentGVolume > minGVolume) currentGVolume--;
}

void volUp()
{
    if (currentEffect >= idxSeparatorFFT) {if (currentAmplitude > minAmplitude) currentAmplitude-=100;}
    else if (currentGVolume < maxGVolume) currentGVolume++;
}

void toggleAutoHuePal()
{
  if (currentEffect == idxBoil) { boilRandom = !boilRandom; filesystem.saveToFile("/boilRandom.txt", boilRandom); boilLoadingFlag = true; boilSelectedSettings = 1;}
  if (currentEffect == idxNFire) { nfireAutoHue = !nfireAutoHue; filesystem.saveToFile("/nfireAutoHue.txt", nfireAutoHue); if (!nfireAutoHue) filesystem.saveToFile("/currentNFireHue.txt", currentNFireHue); }
  if (currentEffect == idxTrailDown) { trailAutoHue = !trailAutoHue; filesystem.saveToFile("/trailAutoHue.txt", trailAutoHue); if (!trailAutoHue) filesystem.saveToFile("/currentTrailHue.txt", currentTrailHue); }
  if (currentEffect == idxFlame) { flameAutoHue = !flameAutoHue; filesystem.saveToFile("/flameAutoHue.txt", flameAutoHue); if (!flameAutoHue) filesystem.saveToFile("/currentFlameHue.txt", currentFlameHue); }
  if (currentEffect == idxPaint) { paintAutoHue = !paintAutoHue; filesystem.saveToFile("/paintAutoHue.txt", paintAutoHue); if (!paintAutoHue) filesystem.saveToFile("/currentPaintHue.txt", currentPaintHue); }
  if (currentEffect == idxSmoke) { smokeAutoHue = !smokeAutoHue; filesystem.saveToFile("/smokeAutoHue.txt", smokeAutoHue); if (!smokeAutoHue) filesystem.saveToFile("/currentSmokeHue.txt", currentSmokeHue); }
  if (currentEffect == idxStar) { starAutoHue = !starAutoHue; filesystem.saveToFile("/starAutoHue.txt", starAutoHue); if (!starAutoHue) filesystem.saveToFile("/currentStarHue.txt", currentStarHue); }
  if (currentEffect == idxSpinner) { spinnerAutoHue = !spinnerAutoHue; filesystem.saveToFile("/spinnerAutoHue.txt", spinnerAutoHue); if (!spinnerAutoHue) filesystem.saveToFile("/currentSpinnerHue.txt", currentSpinnerHue); }

  if (currentEffect == idxNexus) { nexusAutoPalette = !nexusAutoPalette; filesystem.saveToFile("/nexusAutoPalette.txt", nexusAutoPalette); }
  
  if (currentEffect == idxAurora) { auroraRandom = true; auroraLoadingFlag = true; auroraSelectedSettings = 1;}
  if (currentEffect == idxWFall) { wfallRandom = true; wfallSelectedSettings = 1;}
  if (currentEffect == idxRubik) { rubikRandom = true; rubikLoadingFlag = true; rubikSelectedSettings = 1;}
  if (currentEffect == idxLava1) { lava1Random = true; lava1LoadingFlag = true; lava1SelectedSettings = 1;}
  
  if (currentEffect == idxRotateLamp) { rotateLampAutoHue = !rotateLampAutoHue; filesystem.saveToFile("/rotateLampAutoHue.txt", rotateLampAutoHue); if (!rotateLampAutoHue) { currentRotateLampHue = (round(currentRotateLampHue*10))/10; filesystem.saveToFile("/currentRotateLampHue.txt", currentRotateLampHue);}}
  
  if (currentEffect == idxRadFire) { radFireAutoHue = !radFireAutoHue; filesystem.saveToFile("/radFireAutoHue.txt", radFireAutoHue); if (!radFireAutoHue) { currentRadFireHue = (round(currentRadFireHue*10))/10; filesystem.saveToFile("/currentRadFireHue.txt", currentRadFireHue);}}

  if (currentEffect == idxLava2) { lava2AutoHue = !lava2AutoHue; filesystem.saveToFile("/lava2AutoHue.txt", lava2AutoHue); if (!lava2AutoHue) { currentLava2Hue = (round(currentLava2Hue*10))/10; filesystem.saveToFile("/currentLava2Hue.txt", currentLava2Hue);}}
  if (currentEffect == idxLava3) { lava3AutoHue = !lava3AutoHue; filesystem.saveToFile("/lava3AutoHue.txt", lava3AutoHue); if (!lava3AutoHue) { currentLava3Hue = (round(currentLava3Hue*10))/10; filesystem.saveToFile("/currentLava3Hue.txt", currentLava3Hue);}}

  if (currentEffect == idxBarberPole1) { bp1AutoHue = !bp1AutoHue; filesystem.saveToFile("/bp1AutoHue.txt", bp1AutoHue); if (!bp1AutoHue) { currentBP1Hue = (round(currentBP1Hue*10))/10; filesystem.saveToFile("/currentBP1Hue.txt", currentBP1Hue);}}
  if (currentEffect == idxBarberPole2) { bp2AutoHue = !bp2AutoHue; filesystem.saveToFile("/bp2AutoHue.txt", bp2AutoHue); if (!bp2AutoHue) { currentBP2Hue = (round(currentBP2Hue*10))/10; filesystem.saveToFile("/currentBP2Hue.txt", currentBP2Hue);}}
  if (currentEffect == idxBarberPole3) { bp3AutoHue = !bp3AutoHue; filesystem.saveToFile("/bp3AutoHue.txt", bp3AutoHue); if (!bp3AutoHue) { currentBP3Hue = (round(currentBP3Hue*10))/10; filesystem.saveToFile("/currentBP3Hue.txt", currentBP3Hue);}}

  if (currentEffect == idxRGBHype) { hypAutoHue = !hypAutoHue; filesystem.saveToFile("/hypAutoHue.txt", hypAutoHue); if (!hypAutoHue) { filesystem.saveToFile("/currentHypHue.txt", currentHypHue);}}

  if (currentEffect == idxSNova) { snovaAutoHue = !snovaAutoHue; filesystem.saveToFile("/snovaAutoHue.txt", snovaAutoHue); if (!snovaAutoHue) { filesystem.saveToFile("/currentsnovaHue.txt", currentsnovaHue);}}

  if (currentEffect == idxFire2) { Fire2AutoPalette = !Fire2AutoPalette; filesystem.saveToFile("/Fire2AutoPalette.txt", Fire2AutoPalette); }

  if (currentEffect == idxPurpleBars) { purpleBarsAutoHue = !purpleBarsAutoHue; filesystem.saveToFile("/purpleBarsAutoHue.txt", purpleBarsAutoHue); if (!purpleBarsAutoHue) filesystem.saveToFile("/currentPurpleBarsHue.txt", currentPurpleBarsHue); }
  if (currentEffect == idxCenterBars) { CBAutoHue = !CBAutoHue; filesystem.saveToFile("/CBAutoHue.txt", CBAutoHue); if (!CBAutoHue) filesystem.saveToFile("/currentCBHue.txt", currentCBHue); }

  /// PALETTE AUTOCHANGE //
  if (currentEffect == idxKerosene) { keroseneAutoPalette = !keroseneAutoPalette; filesystem.saveToFile("/keroseneAutoPalette.txt", keroseneAutoPalette); if (!keroseneAutoPalette) filesystem.saveToFile("/kerosenePaletteIndex.txt", kerosenePaletteIndex); }
  if (currentEffect == idxSideBars) { SBAutoPalette = !SBAutoPalette; filesystem.saveToFile("/SBAutoPalette.txt", SBAutoPalette); if (!SBAutoPalette) filesystem.saveToFile("/SBPaletteIndex.txt", SBPaletteIndex); }
  if (currentEffect == idxRandomColor) { randomColorAutoPalette = !randomColorAutoPalette; filesystem.saveToFile("/randomColorAutoPalette.txt", randomColorAutoPalette); }
  if (currentEffect == idxColorWaves) { cwAutoPalette = !cwAutoPalette; filesystem.saveToFile("/cwAutoPalette.txt", cwAutoPalette); if (!cwAutoPalette) filesystem.saveToFile("/cwCurrentPaletteNumber.txt", cwCurrentPaletteNumber); }

  isPaused = true;
}

void setLEDDutyCycle()
{
  if (!isGlobalAudioReactive) 
  {
    LEDActive = 15; LEDinActive = 2;
  }
  else
  {
    LEDActive = 35; LEDinActive = 12;
  }
}

void toggleGlobalAudioReactive()
{
  isGlobalAudioReactive = !isGlobalAudioReactive; filesystem.saveToFile("/isGlobalAudioReactive.txt", isGlobalAudioReactive);
  setLEDDutyCycle();
  if (!isGlobalAudioReactive) FastLED.setBrightness(currentBrightness);
  
  switch (currentEffect)
  {
    case idxPaint :
          if (isGlobalAudioReactive)
            initPaint_runtimeSR();
          else
            initPaint_runtimeNOSR();
          break;
    
  }
}

void saturationDown()
{
    if (currentSaturation > minSaturation) 
    { 
      currentSaturation-=stepSaturation; 
    }
    filesystem.saveToFile("/currentSaturation.txt", currentSaturation); 
}

void saturationUp()
{
    if (currentSaturation < maxSaturation) 
    { 
      currentSaturation+=stepSaturation; 
    }
    filesystem.saveToFile("/currentSaturation.txt", currentSaturation); 
}

void HuePalDown()
{
    if (currentEffect == idxBoil && !boilRandom)    //Ldirko's Boil
    {
      if (currentBoilScale > minBoilScale) currentBoilScale-=stepBoilScale;
      boilLoadingFlag = true;
      boilSelectedSettings = 1;
      filesystem.saveToFile("/currentBoilScale.txt", currentBoilScale); 
    }

    if (currentEffect == idxNFire)   // Noise Fire
    {
      nfireAutoHue = false;
      filesystem.saveToFile("/nfireAutoHue.txt", nfireAutoHue); 
      if (currentNFireHue > minNFireHue) { currentNFireHue-=stepNFireHue;}
        else { currentNFireHue = maxNFireHue;}
      filesystem.saveToFile("/currentNFireHue.txt", currentNFireHue); 
    }

    if (currentEffect == idxSolidColor)   //SolidColor
    {
      if (currentSolidHue > minSolidHue) { currentSolidHue-=stepSolidHue; }
        else { currentSolidHue = maxSolidHue; }
      filesystem.saveToFile("/currentSolidHue.txt", currentSolidHue); 
    }

    if (currentEffect == idxTrailDown)   //Trail
    {
      trailAutoHue = false;
      filesystem.saveToFile("/trailAutoHue.txt", trailAutoHue); 
      if (currentTrailHue > minTrailHue) { currentTrailHue-=stepTrailHue; setTrailHue(currentTrailHue); }
        else { currentTrailHue = maxTrailHue; }
      filesystem.saveToFile("/currentTrailHue.txt", currentTrailHue); 
    }

    if (currentEffect == idxFlame)   // Flame
    {
      flameAutoHue = false;
      filesystem.saveToFile("/flameAutoHue.txt", flameAutoHue); 
      if (currentFlameHue > minFlameHue) { currentFlameHue-=stepFlameHue; }
        else { currentFlameHue = maxFlameHue; }
        emitterFlame.baseHue = currentFlameHue;
      filesystem.saveToFile("/currentFlameHue.txt", currentFlameHue); 
    }

    if (currentEffect == idxPaint)   // Paint
    {
      paintAutoHue = false;
      filesystem.saveToFile("/paintAutoHue.txt", paintAutoHue); 
      if (currentPaintHue > minPaintHue) { currentPaintHue-=stepPaintHue; }
        else { currentPaintHue = maxPaintHue; }
        emitterPaint.baseHue = currentPaintHue;
      filesystem.saveToFile("/currentPaintHue.txt", currentPaintHue); 
    }

    if (currentEffect == idxSmoke)   // Smoke
    {
      smokeAutoHue = false;
      filesystem.saveToFile("/smokeAutoHue.txt", smokeAutoHue); 
      if (currentSmokeHue > minSmokeHue) { currentSmokeHue-=stepSmokeHue; }
        else { currentSmokeHue = maxSmokeHue; }
        emitterSmoke.baseHue = currentSmokeHue;
      filesystem.saveToFile("/currentSmokeHue.txt", currentSmokeHue); 
    }

    if (currentEffect == idxStar)   // Star
    {
      starAutoHue = false;
      filesystem.saveToFile("/starAutoHue.txt", starAutoHue); 
      if (currentStarHue > minStarHue) { currentStarHue-=stepStarHue; }
        else { currentStarHue = maxStarHue; }
        emitterStar.baseHue = currentStarHue;
      filesystem.saveToFile("/currentStarHue.txt", currentStarHue); 
    }

    if (currentEffect == idxSpinner)   // Spinner
    {
      spinnerAutoHue = false;
      filesystem.saveToFile("/spinnerAutoHue.txt", spinnerAutoHue); 
      if (currentSpinnerHue > minSpinnerHue) { currentSpinnerHue-=stepSpinnerHue; }
        else { currentSpinnerHue = maxSpinnerHue; }
        emitterSpinner.baseHue = currentSpinnerHue;
      filesystem.saveToFile("/currentSpinnerHue.txt", currentSpinnerHue); 
    }

    if (currentEffect == idxNexus)   // Nexus
    {
      nexusAutoPalette = false;
      filesystem.saveToFile("/nexusAutoPalette.txt", nexusAutoPalette); 
      nexusChangePalette(false);
    }

    if (currentEffect == idxEasing)   //Easing
    {
      if (intervalEasingHue < maxIntervalEasingHue) { intervalEasingHue++; }
      filesystem.saveToFile("/intervalEasingHue.txt", intervalEasingHue); 
    }

    if (currentEffect == idxKerosene)    //Kerosene
    {
      keroseneAutoPalette = false;
      filesystem.saveToFile("/keroseneAutoPalette.txt", keroseneAutoPalette); 
      keroseneChangePalette(false);
      filesystem.saveToFile("/kerosenePaletteIndex.txt", kerosenePaletteIndex);
    }

    if (currentEffect == idxAurora)    //Aurora
    {
      if (AURORA_COLOR_RANGE > min_AURORA_COLOR_RANGE) AURORA_COLOR_RANGE-=step_AURORA_COLOR_RANGE;
      filesystem.saveToFile("/AURORA_COLOR_RANGE.txt", AURORA_COLOR_RANGE);
    }

    if (currentEffect == idxWFall)    //Ldirko's WFall
    {
      if (currentWFallScale > minWFallScale) currentWFallScale-=stepWFallScale; else currentWFallScale = maxWFallScale;
      filesystem.saveToFile("/currentWFallScale.txt", currentWFallScale); 
    }

    if (currentEffect == idxRubik)    //Ldirko's Rubik
    {
      if (currentRubikScale > minRubikScale) currentRubikScale-=stepRubikScale;
      rubikLoadingFlag = true;
      rubikSelectedSettings = 1;
      filesystem.saveToFile("/currentRubikScale.txt", currentRubikScale); 
    }

    if (currentEffect == idxLava1)    //Ldirko's Lava1
    {
      if (currentLava1Scale > minLava1Scale) currentLava1Scale = (unsigned)currentLava1Scale - (unsigned)stepLava1Scale;
      lava1LoadingFlag = true;
      lava1SelectedSettings = 1;
      filesystem.saveToFile("/currentLava1Scale.txt", currentLava1Scale); 
    }

    if (currentEffect == idxRotateLamp)   // Rotate Lamp
    {
      if (rotateLampAutoHue)
      {
        rotateLampAutoHue = false;
        filesystem.saveToFile("/rotateLampAutoHue.txt", rotateLampAutoHue);
        currentRotateLampHue = (round(currentRotateLampHue*10))/10;
      }
      if (currentRotateLampHue - stepRotateLampHue > minRotateLampHue) { currentRotateLampHue-=stepRotateLampHue;}
        else { currentRotateLampHue = maxRotateLampHue;}
      filesystem.saveToFile("/currentRotateLampHue.txt", currentRotateLampHue); 
    }

    if (currentEffect == idxRadFire)   // Radial Fire
    {
      if (radFireAutoHue)
      {
        radFireAutoHue = false;
        filesystem.saveToFile("/radFireAutoHue.txt", radFireAutoHue);
        currentRadFireHue = (round(currentRadFireHue*10))/10;
      }
      //Serial.println(currentRadFireHue);
      if (currentRadFireHue - stepRadFireHue > minRadFireHue) { currentRadFireHue-=stepRadFireHue;}
        else { currentRadFireHue = maxRadFireHue;}
      filesystem.saveToFile("/currentRadFireHue.txt", currentRadFireHue); 
    }

    if (currentEffect == idxLava2)   // Lava Lamp2
    {
      if (lava2AutoHue)
      {
        lava2AutoHue = false;
        filesystem.saveToFile("/lava2AutoHue.txt", lava2AutoHue);
        currentLava2Hue = (round(currentLava2Hue*10))/10;
      }
      if (currentLava2Hue - stepLava2Hue > minLava2Hue) { currentLava2Hue-=stepLava2Hue;}
        else { currentLava2Hue = maxLava2Hue;}
      filesystem.saveToFile("/currentLava2Hue.txt", currentLava2Hue); 
    }

    if (currentEffect == idxLava3)   // Lava Lamp3
    {
      if (lava3AutoHue)
      {
        lava3AutoHue = false;
        filesystem.saveToFile("/lava3AutoHue.txt", lava3AutoHue);
        //currentLava3Hue = (round(currentLava3Hue*10))/10;
      }
      if (currentLava3Hue - stepLava3Hue > minLava3Hue) { currentLava3Hue-=stepLava3Hue;}
        else { currentLava3Hue = maxLava3Hue;}
      filesystem.saveToFile("/currentLava3Hue.txt", currentLava3Hue); 
    }

    if (currentEffect == idxBarberPole1)   // BarberPole
    {
      if (bp1AutoHue)
      {
        bp1AutoHue = false;
        filesystem.saveToFile("/bp1AutoHue.txt", bp1AutoHue);
        currentBP1Hue = (round(currentBP1Hue*10))/10;
      }
      if (currentBP1Hue - stepBP1Hue > minBP1Hue) { currentBP1Hue-=stepBP1Hue;}
        else { currentBP1Hue = maxBP1Hue;}
      filesystem.saveToFile("/currentBP1Hue.txt", currentBP1Hue); 
    }

    if (currentEffect == idxBarberPole2)   // BarberPole2
    {
      if (bp2AutoHue)
      {
        bp2AutoHue = false;
        filesystem.saveToFile("/bp2AutoHue.txt", bp2AutoHue);
        currentBP2Hue = (round(currentBP2Hue*10))/10;
      }
      if (currentBP2Hue - stepBP2Hue > minBP2Hue) { currentBP2Hue-=stepBP2Hue;}
        else { currentBP2Hue = maxBP2Hue;}
      filesystem.saveToFile("/currentBP2Hue.txt", currentBP2Hue); 
    }

    if (currentEffect == idxBarberPole3)   // BarberPole3
    {
      if (bp3AutoHue)
      {
        bp3AutoHue = false;
        filesystem.saveToFile("/bp3AutoHue.txt", bp3AutoHue);
        currentBP3Hue = (round(currentBP3Hue*10))/10;
      }
      if (currentBP3Hue - stepBP3Hue > minBP3Hue) { currentBP3Hue-=stepBP3Hue;}
        else { currentBP3Hue = maxBP3Hue;}
      filesystem.saveToFile("/currentBP3Hue.txt", currentBP3Hue); 
    }

    if (currentEffect == idxRGBHype)   // RGBHype
    {
      if (hypAutoHue)
      {
        hypAutoHue = false;
        filesystem.saveToFile("/hypAutoHue.txt", hypAutoHue);
      }
      if (currentHypHue - stepHypHue > minHypHue) { currentHypHue-=stepHypHue;}
        else { currentHypHue = maxHypHue;}
      filesystem.saveToFile("/currentHypHue.txt", currentHypHue); 
    }

    if (currentEffect == idxPurpleBars)    //purpleBars
    {
      purpleBarsAutoHue = false;
      filesystem.saveToFile("/purpleBarsAutoHue.txt", purpleBarsAutoHue); 
      if (currentPurpleBarsHue > minPurpleBarsHue) { currentPurpleBarsHue-=stepPurpleBarsHue; }
        else { currentPurpleBarsHue = maxPurpleBarsHue;}
      filesystem.saveToFile("/currentPurpleBarsHue.txt", currentPurpleBarsHue);
    }

    if (currentEffect == idxCenterBars)    //centerBars
    {
      CBAutoHue = false;
      filesystem.saveToFile("/CBAutoHue.txt", CBAutoHue); 
      if (currentCBHue > minCBHue) { currentCBHue-=stepCBHue;}
        else { currentCBHue = maxCBHue;}
      filesystem.saveToFile("/currentCBHue.txt", currentCBHue);
    }

    if (currentEffect ==idxColorWaves)
    {
      cwAutoPalette = false;
      filesystem.saveToFile("/cwAutoPalette.txt", cwAutoPalette);
      cwChangePalette(false);
      filesystem.saveToFile("/cwCurrentPaletteNumber.txt", cwCurrentPaletteNumber);
    }
    
    if (currentEffect == idxSNova)    //Supernova
    {
      snovaAutoHue = false;
      filesystem.saveToFile("/snovaAutoHue.txt", snovaAutoHue); 
      if (currentsnovaHue > minsnovaHue) { currentsnovaHue-=stepsnovaHue;}
        else { currentsnovaHue = maxsnovaHue;}
      filesystem.saveToFile("/currentsnovaHue.txt", currentsnovaHue);
    }

    if (currentEffect == idxFire2)    //Fire2
    {
      Fire2AutoPalette = false;
      filesystem.saveToFile("/Fire2AutoPalette.txt", Fire2AutoPalette); 
      Fire2ChangePalette();
    }

    if (currentEffect == idxSideBars)    //sideBars
    {
      SBAutoPalette = false;
      filesystem.saveToFile("/SBAutoPalette.txt", SBAutoPalette); 
      SBChangePalette(false);
      filesystem.saveToFile("/SBPaletteIndex.txt", SBPaletteIndex);
    }

    if (currentEffect == idxRandomColor)
    {
      randomColorChangeDeltaHue();
    }
}

void HuePalUp()
{
    if (currentEffect == idxBoil && !boilRandom)    //Ldirko's Boil
    {
      if (currentBoilScale < maxBoilScale) currentBoilScale+=stepBoilScale;
      boilLoadingFlag = true;
      boilSelectedSettings = 1;
      filesystem.saveToFile("/currentBoilScale.txt", currentBoilScale); 
    }

    if (currentEffect == idxNFire)   // Noise Fire
    {
      nfireAutoHue = false;
      filesystem.saveToFile("/nfireAutoHue.txt", nfireAutoHue); 
      if (currentNFireHue < maxNFireHue) { currentNFireHue+=stepNFireHue;}
        else { currentNFireHue = minNFireHue;}
      filesystem.saveToFile("/currentNFireHue.txt", currentNFireHue); 
    }

    if (currentEffect == idxSolidColor)
    {
      if (currentSolidHue < maxSolidHue) { currentSolidHue+=stepSolidHue; }
        else { currentSolidHue = minSolidHue; }
      filesystem.saveToFile("/currentSolidHue.txt", currentSolidHue); 
    }

    if (currentEffect == idxTrailDown)     // Trail
    {
      trailAutoHue = false;
      filesystem.saveToFile("/trailAutoHue.txt", trailAutoHue); 
      if (currentTrailHue < maxTrailHue) { currentTrailHue+=stepTrailHue; setTrailHue(currentTrailHue); }
        else { currentTrailHue = minTrailHue; trailHueReset(); }
      filesystem.saveToFile("/currentTrailHue.txt", currentTrailHue);
    }

    if (currentEffect == idxFlame)   //Flame
    {
      flameAutoHue = false;
      filesystem.saveToFile("/flameAutoHue.txt", flameAutoHue); 
      if (currentFlameHue < maxFlameHue) { currentFlameHue+=stepFlameHue; }
        else { currentFlameHue = minFlameHue; }
        emitterFlame.baseHue = currentFlameHue; 
      filesystem.saveToFile("/currentFlameHue.txt", currentFlameHue); 
    }

    if (currentEffect == idxPaint)   //Paint
    {
      paintAutoHue = false;
      filesystem.saveToFile("/paintAutoHue.txt", paintAutoHue); 
      if (currentPaintHue < maxPaintHue) { currentPaintHue+=stepPaintHue; }
        else { currentPaintHue = minPaintHue; }
        emitterPaint.baseHue = currentPaintHue; 
      filesystem.saveToFile("/currentPaintHue.txt", currentPaintHue); 
    }

    if (currentEffect == idxSmoke)   //Smoke
    {
      smokeAutoHue = false;
      filesystem.saveToFile("/smokeAutoHue.txt", smokeAutoHue); 
      if (currentSmokeHue < maxSmokeHue) { currentSmokeHue+=stepSmokeHue; }
        else { currentSmokeHue = minSmokeHue; }
        emitterSmoke.baseHue = currentSmokeHue; 
      filesystem.saveToFile("/currentSmokeHue.txt", currentSmokeHue); 
    }

    if (currentEffect == idxStar)   //Star
    {
      starAutoHue = false;
      filesystem.saveToFile("/starAutoHue.txt", starAutoHue); 
      if (currentStarHue < maxStarHue) { currentStarHue+=stepStarHue; }
        else { currentStarHue = minStarHue; }
        emitterStar.baseHue = currentStarHue; 
      filesystem.saveToFile("/currentStarHue.txt", currentStarHue); 
    }

    if (currentEffect == idxSpinner)   //Spinner
    {
      spinnerAutoHue = false;
      filesystem.saveToFile("/spinnerAutoHue.txt", spinnerAutoHue); 
      if (currentSpinnerHue < maxSpinnerHue) { currentSpinnerHue+=stepSpinnerHue; }
        else { currentSpinnerHue = minSpinnerHue; }
        emitterSpinner.baseHue = currentSpinnerHue; 
      filesystem.saveToFile("/currentSpinnerHue.txt", currentSpinnerHue); 
    }

//    if (currentEffect == idxNexus)   // Nexus
//    {
//      if (currentNexusScale < maxNexusScale) { currentNexusScale+=stepNexusScale; }
//      filesystem.saveToFile("/currentNexusScale.txt", currentNexusScale); 
//    }

    if (currentEffect == idxNexus)   // Nexus
    {
      nexusAutoPalette = false;
      filesystem.saveToFile("/nexusAutoPalette.txt", nexusAutoPalette); 
      nexusChangePalette(true);
    }

    if (currentEffect == idxEasing)   //Easing
    {
      if (intervalEasingHue > minIntervalEasingHue) { intervalEasingHue--; }
      filesystem.saveToFile("/intervalEasingHue.txt", intervalEasingHue); 
    }

    if (currentEffect == idxKerosene)    //Kerosene
    {
      keroseneAutoPalette = false;
      filesystem.saveToFile("/keroseneAutoPalette.txt", keroseneAutoPalette); 
//      if (kerosenePaletteIndex < kerosenePaletteSize-1) { kerosenePaletteIndex++; }
//        else { kerosenePaletteIndex = 1; }
      keroseneChangePalette(true);
      filesystem.saveToFile("/kerosenePaletteIndex.txt", kerosenePaletteIndex);
    }

    if (currentEffect == idxAurora)    //Aurora
    {
      if (AURORA_COLOR_RANGE < max_AURORA_COLOR_RANGE) AURORA_COLOR_RANGE+=step_AURORA_COLOR_RANGE;
      filesystem.saveToFile("/AURORA_COLOR_RANGE.txt", AURORA_COLOR_RANGE);
    }

    if (currentEffect == idxWFall && !wfallRandom)    //Ldirko's WFall
    {
      if (currentWFallScale < maxWFallScale) currentWFallScale+=stepWFallScale; else currentWFallScale = minWFallScale;
      //wfallSelectedSettings = 1;
      filesystem.saveToFile("/currentWFallScale.txt", currentWFallScale); 
    }

     if (currentEffect == idxRubik && !rubikRandom)    //Ldirko's Rubik
    {
      if (currentRubikScale < maxRubikScale) currentRubikScale+=stepRubikScale;
      rubikLoadingFlag = true;
      rubikSelectedSettings = 1;
      filesystem.saveToFile("/currentRubikScale.txt", currentRubikScale); 
    }

    if (currentEffect == idxLava1)    //Ldirko's Lava1
    {
      if (currentLava1Scale < maxLava1Scale) currentLava1Scale = (unsigned)currentLava1Scale + (unsigned)stepLava1Scale;
      lava1LoadingFlag = true;
      lava1SelectedSettings = 1;
      filesystem.saveToFile("/currentLava1Scale.txt", currentLava1Scale); 
    }

    if (currentEffect == idxRotateLamp)   // Rotate Lamp
    {
      if (rotateLampAutoHue)
      {
        rotateLampAutoHue = false;
        filesystem.saveToFile("/rotateLampAutoHue.txt", rotateLampAutoHue);
        currentRotateLampHue = (round(currentRotateLampHue*10))/10;
      }
      if (currentRotateLampHue < maxRotateLampHue) { currentRotateLampHue+=stepRotateLampHue;}
        else { currentRotateLampHue = minRotateLampHue;}
      filesystem.saveToFile("/currentRotateLampHue.txt", currentRotateLampHue); 
    }

    if (currentEffect == idxRadFire)   // Radial Fire
    {
      if (radFireAutoHue)
      {
        radFireAutoHue = false;
        filesystem.saveToFile("/radFireAutoHue.txt", radFireAutoHue);
        currentRadFireHue = (round(currentRadFireHue*10))/10;
      }
      //Serial.println(currentRadFireHue);
      if (currentRadFireHue + stepRadFireHue < maxRadFireHue) { currentRadFireHue+=stepRadFireHue;}
        else { currentRadFireHue = minRadFireHue;}
      filesystem.saveToFile("/currentRadFireHue.txt", currentRadFireHue); 
    }

    if (currentEffect == idxLava2)   // Lava Lamp2
    {
      if (lava2AutoHue)
      {
        lava2AutoHue = false;
        filesystem.saveToFile("/lava2AutoHue.txt", lava2AutoHue);
        currentLava2Hue = (round(currentLava2Hue*10))/10;
      }
      if (currentLava2Hue + stepLava2Hue < maxLava2Hue) { currentLava2Hue+=stepLava2Hue;}
        else { currentLava2Hue = maxLava2Hue;}
      filesystem.saveToFile("/currentLava2Hue.txt", currentLava2Hue); 
    }

    if (currentEffect == idxLava3)   // Lava Lamp3
    {
      if (lava3AutoHue)
      {
        lava3AutoHue = false;
        filesystem.saveToFile("/lava3AutoHue.txt", lava3AutoHue);
        //currentLava3Hue = (round(currentLava3Hue*10))/10;
      }
      if (currentLava3Hue + stepLava3Hue < maxLava3Hue) { currentLava3Hue+=stepLava3Hue;}
        else { currentLava3Hue = minLava3Hue;}
      filesystem.saveToFile("/currentLava3Hue.txt", currentLava3Hue); 
    }

    if (currentEffect == idxBarberPole1)   // BarberPole
    {
      if (bp1AutoHue)
      {
        bp1AutoHue = false;
        filesystem.saveToFile("/bp1AutoHue.txt", bp1AutoHue);
        currentBP1Hue = (round(currentBP1Hue*10))/10;
      }
      if (currentBP1Hue + stepBP1Hue < maxBP1Hue) { currentBP1Hue+=stepBP1Hue;}
        else { currentBP1Hue = minBP1Hue;}
      filesystem.saveToFile("/currentBP1Hue.txt", currentBP1Hue); 
    }

    if (currentEffect == idxBarberPole2)   // BarberPole2
    {
      if (bp2AutoHue)
      {
        bp2AutoHue = false;
        filesystem.saveToFile("/bp2AutoHue.txt", bp2AutoHue);
        currentBP2Hue = (round(currentBP2Hue*10))/10;
      }
      if (currentBP2Hue + stepBP2Hue < maxBP2Hue) { currentBP2Hue+=stepBP2Hue;}
        else { currentBP2Hue = minBP2Hue;}
      filesystem.saveToFile("/currentBP2Hue.txt", currentBP2Hue); 
    }

    if (currentEffect == idxBarberPole3)   // BarberPole3
    {
      if (bp3AutoHue)
      {
        bp3AutoHue = false;
        filesystem.saveToFile("/bp3AutoHue.txt", bp3AutoHue);
        currentBP3Hue = (round(currentBP3Hue*10))/10;
      }
      if (currentBP3Hue + stepBP3Hue < maxBP3Hue) { currentBP3Hue+=stepBP3Hue;}
        else { currentBP3Hue = minBP3Hue;}
      filesystem.saveToFile("/currentBP3Hue.txt", currentBP3Hue); 
    }

    if (currentEffect == idxRGBHype)   // RGBHype
    {
      if (hypAutoHue)
      {
        hypAutoHue = false;
        filesystem.saveToFile("/hypAutoHue.txt", hypAutoHue);
      }
      if (currentHypHue + stepHypHue < maxHypHue) { currentHypHue+=stepHypHue;}
        else { currentHypHue = minHypHue;}
      filesystem.saveToFile("/currentHypHue.txt", currentHypHue); 
    }

   if (currentEffect == idxPurpleBars)    //purpleBars
    {
      purpleBarsAutoHue = false;
      filesystem.saveToFile("/purpleBarsAutoHue.txt", purpleBarsAutoHue); 
      if (currentPurpleBarsHue < maxPurpleBarsHue) { currentPurpleBarsHue+=stepPurpleBarsHue; }
        else { currentPurpleBarsHue = minPurpleBarsHue;}
      filesystem.saveToFile("/currentPurpleBarsHue.txt", currentPurpleBarsHue);
    }

    if (currentEffect == idxCenterBars)
    {
      CBAutoHue = false;
      filesystem.saveToFile("/CBAutoHue.txt", CBAutoHue); 
      if (currentCBHue < maxCBHue) { currentCBHue+=stepCBHue;}
        else { currentCBHue = minCBHue; }
      filesystem.saveToFile("/currentCBHue.txt", currentCBHue);
    }

    if (currentEffect ==idxColorWaves)
    {
      cwAutoPalette = false;
      filesystem.saveToFile("/cwAutoPalette.txt", cwAutoPalette);
      cwChangePalette(true);
      filesystem.saveToFile("/cwCurrentPaletteNumber.txt", cwCurrentPaletteNumber);
    }
    
    if (currentEffect == idxSNova)
    {
      snovaAutoHue = false;
      filesystem.saveToFile("/snovaAutoHue.txt", snovaAutoHue); 
      if (currentsnovaHue < maxsnovaHue) { currentsnovaHue+=stepsnovaHue;}
        else { currentsnovaHue = minsnovaHue; }
      filesystem.saveToFile("/currentsnovaHue.txt", currentsnovaHue);
    }

    if (currentEffect == idxFire2)    //Fire2
    {
      Fire2AutoPalette = false;
      filesystem.saveToFile("/Fire2AutoPalette.txt", Fire2AutoPalette); 
      Fire2ChangePalette();
    }

    if (currentEffect == idxSideBars)
    {
      SBAutoPalette = false;
      filesystem.saveToFile("/SBAutoPalette.txt", SBAutoPalette); 
      SBChangePalette(true);
      filesystem.saveToFile("/SBPaletteIndex.txt", SBPaletteIndex);
    }

    if (currentEffect == idxRandomColor)
    {
      randomColorChangeDeltaHue();
    }
}

void HuePalUpAuto()
{
    if ((currentEffect  == idxNFire) && nfireAutoHue)
    {
      if (currentNFireHue < maxNFireHue) { currentNFireHue+=stepNFireHue; }
        else { currentNFireHue = minNFireHue; }
    }

    if ((currentEffect == idxTrailDown) && trailAutoHue)     // Trail
    {
      if (currentTrailHue < maxTrailHue) { currentTrailHue+=stepTrailHue; setTrailHue(currentTrailHue); }
        else { currentTrailHue = minTrailHue; trailHueReset(); }
    }

    if ((currentEffect == idxPurpleBars) && purpleBarsAutoHue)
    {
      if (currentPurpleBarsHue < maxPurpleBarsHue) { currentPurpleBarsHue+=stepPurpleBarsHue;}
        else { currentPurpleBarsHue = minPurpleBarsHue;}
    }

    if ((currentEffect == idxCenterBars) && CBAutoHue)
    {
      if (currentCBHue < maxCBHue) { currentCBHue+=stepCBHue; }
        else { currentCBHue = minCBHue; }
    }

//    if ((currentEffect == idxSideBars) && SBAutoHue)
//    {
//      if (currentSBHue < maxSBHue) { currentSBHue+=stepSBHue; }
//        else { currentSBHue = minSBHue; }
//    }

    if ((currentEffect == idxRotateLamp) && rotateLampAutoHue)
    {
      if (currentRotateLampHue < maxRotateLampHue) { currentRotateLampHue+=stepRotateLampAutoHue; }
        else { currentRotateLampHue = minRotateLampHue;  }
    }

    if ((currentEffect == idxRadFire) && radFireAutoHue)
    {
      if (currentRadFireHue < maxRadFireHue) { currentRadFireHue+=stepRadFireAutoHue; }
        else { currentRadFireHue = minRadFireHue;  }
    }

    if ((currentEffect == idxLava2) && lava2AutoHue)
    {
      if (currentLava2Hue < maxLava2Hue) { currentLava2Hue+=stepLava2AutoHue; }
        else { currentLava2Hue = minLava2Hue;  }
    }

    if ((currentEffect == idxLava3) && lava3AutoHue)
    {
      if (currentLava3Hue < maxLava3Hue) { currentLava3Hue+=stepLava3AutoHue; }
        else { currentLava3Hue = minLava3Hue;  }
    }

    if ((currentEffect == idxBarberPole1) && bp1AutoHue)
    {
      if (currentBP1Hue + stepBP1AutoHue < maxBP1Hue) { currentBP1Hue+=stepBP1AutoHue; }
        else { currentBP1Hue = minBP1Hue;  }
    }

    if ((currentEffect == idxBarberPole2) && bp2AutoHue)
    {
      if (currentBP2Hue + stepBP2AutoHue < maxBP2Hue) { currentBP2Hue+=stepBP2AutoHue; }
        else { currentBP2Hue = minBP2Hue;  }
    }

    if ((currentEffect == idxBarberPole3) && bp3AutoHue)
    {
      if (currentBP3Hue + stepBP3AutoHue < maxBP3Hue) { currentBP3Hue+=stepBP3AutoHue; }
        else { currentBP3Hue = minBP3Hue;  }
    }
}

void animSpeedDown()
{
    if (currentEffect == idxNFire)    //Noise Fire
    {
      if (currentNFireDelay < maxNFireDelay) currentNFireDelay+=stepNFireDelay;
      filesystem.saveToFile("/currentNFireDelay.txt", currentNFireDelay); 
    }

    if (currentEffect == idxTrailDown)   //Trail
    {
      if (currentTrailDelay < maxTrailDelay) currentTrailDelay+=stepTrailDelay;
      filesystem.saveToFile("/currentTrailDelay.txt", currentTrailDelay); 
    }

    if (currentEffect == idxFlame)    //Flame
    {
      if (currentFlameDelay < maxFlameDelay) currentFlameDelay+=stepFlameDelay;
      filesystem.saveToFile("/currentFlameDelay.txt", currentFlameDelay); 
    }

    if (currentEffect == idxPaint)    //Paint
    {
      if (currentPaintDelay < maxPaintDelay) currentPaintDelay+=stepPaintDelay;
      filesystem.saveToFile("/currentPaintDelay.txt", currentPaintDelay); 
    }

    if (currentEffect == idxSmoke)    //Smoke
    {
      if (currentSmokeDelay < maxSmokeDelay) currentSmokeDelay+=stepSmokeDelay;
      filesystem.saveToFile("/currentSmokeDelay.txt", currentSmokeDelay); 
    }

    if (currentEffect == idxStar)    //Star
    {
      if (currentStarDelay < maxStarDelay) currentStarDelay+=stepStarDelay;
      filesystem.saveToFile("/currentStarDelay.txt", currentStarDelay); 
    }

    if (currentEffect == idxSpinner)    //Spinner
    {
      if (currentSpinnerDelay < maxSpinnerDelay) currentSpinnerDelay+=stepSpinnerDelay;
      filesystem.saveToFile("/currentSpinnerDelay.txt", currentSpinnerDelay); 
    }

    if (currentEffect == idxNexus)    //Nexus
    {
      if (currentNexusDelay < maxNexusDelay) currentNexusDelay+=stepNexusDelay;
      filesystem.saveToFile("/currentNexusDelay.txt", currentNexusDelay); 
    }

    if (currentEffect == idxPacifica1D)    //Pacifica1D
    {
      if (currentPacifica1DDelay < maxPacifica1DDelay) currentPacifica1DDelay+=stepPacifica1DDelay;
      filesystem.saveToFile("/currentPacifica1DDelay.txt", currentPacifica1DDelay); 
    }
    
    if (currentEffect == idxPPlasma)    //PPlasma / Perlin Plasma
    {
      if (currentPPlasmaDelay < maxPPlasmaDelay) currentPPlasmaDelay+=stepPPlasmaDelay;
      filesystem.saveToFile("/currentPPlasmaDelay.txt", currentPPlasmaDelay); 
    }

    if (currentEffect == idxEasing)    //Easing
    {
      if (currentEasingDelay < maxEasingDelay) currentEasingDelay+=stepEasingDelay;
      filesystem.saveToFile("/currentEasingDelay.txt", currentEasingDelay); 
    }

    if (currentEffect == idxAABar)    //AABar
    {
      if (AABarFrameDelay < maxAABarFrameDelay) AABarFrameDelay+=stepAABarFrameDelay;
      filesystem.saveToFile("/AABarFrameDelay.txt", AABarFrameDelay); 
    }

    if (currentEffect == idxAurora && !auroraRandom)    //Aurora
    {
      if (currentAuroraSpeed > minAuroraSpeed) currentAuroraSpeed-=stepAuroraSpeed;
      auroraLoadingFlag = true;
      auroraSelectedSettings = 1;
      //auroraSpeed = currentAuroraSpeed;
      filesystem.saveToFile("/currentAuroraSpeed.txt", currentAuroraSpeed); 
    }

    if (currentEffect == idxWFall)    //WFall
    {
      if (currentWFallVar2 > minWFallVar2) currentWFallVar2-=stepWFallVar2;
      filesystem.saveToFile("/currentWFallVar2.txt", currentWFallVar2); 
    }

    if (currentEffect == idxRubik)    //Rubik
    {
      if (currentRubikDelay < maxRubikDelay) currentRubikDelay+=stepRubikDelay;
      filesystem.saveToFile("/currentRubikDelay.txt", currentRubikDelay); 
    }

    if (currentEffect == idxRadFire)    //Radial Fire
    {
      if (currentRadFireDelay < maxRadFireDelay) currentRadFireDelay+=stepRadFireDelay;
      filesystem.saveToFile("/currentRadFireDelay.txt", currentRadFireDelay); 
    }

    if (currentEffect == idxBarberPole1)    //Barber Pole
    {
      if (currentBP1Delay < maxBP1Delay) currentBP1Delay+=stepBP1Delay;
      filesystem.saveToFile("/currentBP1Delay.txt", currentBP1Delay); 
    }

    if (currentEffect == idxBarberPole2)    //Barber Pole2
    {
      if (currentBP2Delay < maxBP2Delay) currentBP2Delay+=stepBP2Delay;
      filesystem.saveToFile("/currentBP2Delay.txt", currentBP2Delay); 
    }

    if (currentEffect == idxBarberPole3)    //Barber Pole3
    {
      if (currentBP3Delay < maxBP3Delay) currentBP3Delay+=stepBP3Delay;
      filesystem.saveToFile("/currentBP3Delay.txt", currentBP3Delay); 
    }

    if (currentEffect == idxLava1)    //Ldirko's Lava1
    {
      if (currentLava1Speed > minLava1Speed) currentLava1Speed = (unsigned)currentLava1Speed - (unsigned)stepLava1Speed;
      lava1LoadingFlag = true;
      lava1SelectedSettings = 1;
      filesystem.saveToFile("/currentLava1Speed.txt", currentLava1Speed); 
    }

    if (currentEffect == idxLava3)    //Lava Lamp3
    {
      if (currentLava3Speed > minLava3Speed) currentLava3Speed-=stepLava3Speed;
      filesystem.saveToFile("/currentLava3Speed.txt", currentLava3Speed); 
    }

    if (currentEffect == idxSNova)    //Supernova
    {
      if (currentsnovaSpeed > minsnovaSpeed) currentsnovaSpeed-=stepsnovaSpeed;
      filesystem.saveToFile("/currentsnovaSpeed.txt", currentsnovaSpeed); 
    }

    if (currentEffect == idxConfigBars)
    {
      if (selectedBand>0) selectedBand--; else selectedBand=NUM_BANDS-1;
    }
}

void animSpeedUp()
{
    if (currentEffect == idxNFire)    //Noise Fire
    {
      //if (currentFPS < maxFPS) currentFPS+=stepFPS;
      if (currentNFireDelay > minNFireDelay) currentNFireDelay-=stepNFireDelay;
      filesystem.saveToFile("/currentNFireDelay.txt", currentNFireDelay); 
    }

    if (currentEffect == idxTrailDown)   //Trail
    {
      if (currentTrailDelay > minTrailDelay) currentTrailDelay-=stepTrailDelay;
      filesystem.saveToFile("/currentTrailDelay.txt", currentTrailDelay); 
      //ESP.restart()
    }

    if (currentEffect == idxFlame)    //Flame
    {
      if (currentFlameDelay > minFlameDelay) currentFlameDelay-=stepFlameDelay;
      filesystem.saveToFile("/currentFlameDelay.txt", currentFlameDelay); 
    }

    if (currentEffect == idxPaint)    //Paint
    {
      if (currentPaintDelay > minPaintDelay) currentPaintDelay-=stepPaintDelay;
      filesystem.saveToFile("/currentPaintDelay.txt", currentPaintDelay); 
    }

    if (currentEffect == idxSmoke)    //Smoke
    {
      if (currentSmokeDelay > minSmokeDelay) currentSmokeDelay-=stepSmokeDelay;
      filesystem.saveToFile("/currentSmokeDelay.txt", currentSmokeDelay); 
    }

    if (currentEffect == idxStar)    //Star
    {
      if (currentStarDelay > minStarDelay) currentStarDelay-=stepStarDelay;
      filesystem.saveToFile("/currentStarDelay.txt", currentStarDelay); 
    }

    if (currentEffect == idxSpinner)    //Spinner
    {
      if (currentSpinnerDelay < minSpinnerDelay) currentSpinnerDelay-=stepSpinnerDelay;
      filesystem.saveToFile("/currentSpinnerDelay.txt", currentSpinnerDelay); 
    }

    if (currentEffect == idxNexus)    //Nexus
    {
      if (currentNexusDelay > minNexusDelay) currentNexusDelay-=stepNexusDelay;
      filesystem.saveToFile("/currentNexusDelay.txt", currentNexusDelay); 
    }

    if (currentEffect == idxPacifica1D)    //Pacifica1D
    {
      if (currentPacifica1DDelay > minPacifica1DDelay) currentPacifica1DDelay-=stepPacifica1DDelay;
      filesystem.saveToFile("/currentPacifica1DDelay.txt", currentPacifica1DDelay); 
    }

    if (currentEffect == idxPPlasma)    //PPlasma / Perlin Plasma
    {
      if (currentPPlasmaDelay > minPPlasmaDelay) currentPPlasmaDelay-=stepPPlasmaDelay;
      filesystem.saveToFile("/currentPPlasmaDelay.txt", currentPPlasmaDelay); 
    }

    if (currentEffect == idxEasing)    //Easing
    {
      if (currentEasingDelay > minEasingDelay) currentEasingDelay-=stepEasingDelay;
      filesystem.saveToFile("/currentEasingDelay.txt", currentEasingDelay); 
    }


    if (currentEffect == idxAABar)    //AABar
    {
      if (AABarFrameDelay > minAABarFrameDelay) AABarFrameDelay-=stepAABarFrameDelay;
      filesystem.saveToFile("/AABarFrameDelay.txt", AABarFrameDelay); 
    }

    if (currentEffect == idxAurora && !auroraRandom)    //Aurora
    {
      if (currentAuroraSpeed < maxAuroraSpeed) currentAuroraSpeed+=stepAuroraSpeed;
      auroraLoadingFlag = true;
      auroraSelectedSettings = 1;
      ///auroraSpeed = currentAuroraSpeed;
      filesystem.saveToFile("/currentAuroraSpeed.txt", currentAuroraSpeed); 
    }

    if (currentEffect == idxWFall)    //WFall
    {
      if (currentWFallVar2 < maxWFallVar2) currentWFallVar2+=stepWFallVar2;
      filesystem.saveToFile("/currentWFallVar2.txt", currentWFallVar2); 
    }

    if (currentEffect == idxRubik)    //Rubik
    {
      if (currentRubikDelay > minRubikDelay) currentRubikDelay-=stepRubikDelay;
      filesystem.saveToFile("/currentRubikDelay.txt", currentRubikDelay); 
    }

    if (currentEffect == idxRadFire)    //Radial Fire
    {
      if (currentRadFireDelay > minRadFireDelay) currentRadFireDelay-=stepRadFireDelay;
      filesystem.saveToFile("/currentRadFireDelay.txt", currentRadFireDelay); 
    }

    if (currentEffect == idxBarberPole1)    //Barber Pole
    {
      if (currentBP1Delay > minBP1Delay) currentBP1Delay-=stepBP1Delay;
      filesystem.saveToFile("/currentBP1Delay.txt", currentBP1Delay); 
    }

    if (currentEffect == idxBarberPole2)    //Barber Pole2
    {
      if (currentBP2Delay > minBP2Delay) currentBP2Delay-=stepBP2Delay;
      filesystem.saveToFile("/currentBP2Delay.txt", currentBP2Delay); 
    }

    if (currentEffect == idxBarberPole3)    //Barber Pole3
    {
      if (currentBP3Delay > minBP3Delay) currentBP3Delay-=stepBP3Delay;
      filesystem.saveToFile("/currentBP3Delay.txt", currentBP3Delay); 
    }

    if (currentEffect == idxLava1)    //Ldirko's Lava1
    {
      if (currentLava1Speed < maxLava1Speed) currentLava1Speed = (unsigned)currentLava1Speed + (unsigned)stepLava1Speed;
      lava1LoadingFlag = true;
      lava1SelectedSettings = 1;
      filesystem.saveToFile("/currentLava1Speed.txt", currentLava1Speed); 
    }

    if (currentEffect == idxLava3)    //Lava Lamp3
    {
      if (currentLava3Speed < maxLava3Speed) currentLava3Speed+=stepLava3Speed;
      filesystem.saveToFile("/currentLava3Speed.txt", currentLava3Speed); 
    }

    if (currentEffect == idxSNova)    //Supernova
    {
      if (currentsnovaSpeed < maxsnovaSpeed) currentsnovaSpeed+=stepsnovaSpeed;
      filesystem.saveToFile("/currentsnovaSpeed.txt", currentsnovaSpeed); 
    }

    if (currentEffect == idxConfigBars)
    {
      if (selectedBand<NUM_BANDS-1) selectedBand++; else selectedBand=0;
    }
}

void setTrailHue(double cHue)
{
  for (int i=0; i<1; i++)
  {
    RGBConverter::HexToRgb(String(trailColorsRef[i], HEX), Red, Green, Blue);
    RGBConverter::RgbToHsl(Red, Green, Blue, Hue, Saturation, Lighting);
    Hue += cHue;
    RGBConverter::HslToRgb(Hue, Saturation, Lighting, Red, Green, Blue);
    RGBConverter::RgbToHex(Red, Green, Blue, sHex);
    trailColors[i] = strHexToI(sHex);
  }
}


void trailHueReset()
{
  for (int j=0; j<1; j++)
  {
    trailColors[j] = trailColorsRef[j];
    //setTrailSat();
  }
}

void nexusChangePalette(bool isUp)
{
  if (isUp)
    { nexusPaletteIndex = addmod8(nexusPaletteIndex, 1, 6); }
  else
    { if (nexusPaletteIndex>0) nexusPaletteIndex--; else nexusPaletteIndex = 6-1; }
  filesystem.saveToFile("/nexusPaletteIndex.txt", nexusPaletteIndex);
  nexusSetPalette();  
}

void nexusSetPalette()
{
  switch (nexusPaletteIndex)
  {
    case 0 : 
          nexusTargetPalette = RainbowColors_p;
          break;
    case 1 : 
          nexusTargetPalette = OceanColors_p;
          break;
    case 2 : 
          nexusTargetPalette = CRGBPalette16(CRGB::Black, 0x0f001a, 0x1e0034, 0x2d004e, 0x3c0068, CRGB::Indigo, CRGB::Indigo, CRGB::Indigo, CRGB::Indigo, CRGB::Indigo, CRGB::Indigo, 0x3c0084, 0x2d0086, 0x1e0087, 0x0f0089, CRGB::DarkBlue);
          break;
    case 3 : 
          nexusTargetPalette = PartyColors_p;
          break;
    case 4 : 
          nexusTargetPalette = ForestColors_p;
          break;
    case 5 : 
          nexusTargetPalette = HeatColors_p;
          break;
  }
}

void cwChangePalette(bool isUp)
{
  if (isUp)
    cwCurrentPaletteNumber = addmod8(cwCurrentPaletteNumber, 1, cwGradientPaletteCount);
  else
    if (cwCurrentPaletteNumber>0) cwCurrentPaletteNumber--; else cwCurrentPaletteNumber = cwGradientPaletteCount-1;
    cwTargetPalette = cwGradientPalettes[ cwCurrentPaletteNumber ];
}

void Fire2ChangePalette()
{
  Fire2Swap = !Fire2Swap;
  if (Fire2Swap) 
  {
    Fire2Loading2 = true; 
  }
  else 
  {
    Fire2Loading1 = true;
  }
}

void randomColorChangeDeltaHue()
{
    deltahue2 = deltahue3;
    setRandomColorInterval();
    setDeltahue3();
}

void SBChangePalette(bool isUp)
{
  if (isUp)
    SBPaletteIndex = addmod8(SBPaletteIndex, 1, SBGradientPaletteCount-1);
  else
  {
    if (SBPaletteIndex > 0) SBPaletteIndex--; 
    else SBPaletteIndex = SBGradientPaletteCount; 
  }
  SBTargetPalette = SBGradientPalettes[SBPaletteIndex ];
}

void initPaint_runtimeSR()
{
  sourcePaint.vx = 2;
  sourcePaint.vy = 2;
  sourcePaint.x = 20;
  sourcePaint.y = 20;
}

void initPaint_runtimeNOSR()
{
  sourcePaint.vx = 1;
  sourcePaint.vy = 5;
  sourcePaint.x = 10;
  sourcePaint.y = 10;
}

void keroseneChangePalette(bool isUp)
{
    if (isUp)
      kerosenePaletteIndex = addmod8(kerosenePaletteIndex, 1, keroseneGradientPaletteCount-1);
    else
    {
      if (kerosenePaletteIndex > 0) kerosenePaletteIndex--; 
      else kerosenePaletteIndex = keroseneGradientPaletteCount; 
    }
    keroseneTargetPalette = keroseneGradientPalettes[kerosenePaletteIndex ];
}

void setDeltahue3()
{
    random16_set_seed(65535);
    random16_add_entropy(analogRead(32));
    deltahue3 = random8();
}

void setRandomColorInterval()
{
  if (abs(deltahue2 - deltahue1) < 127)
    randomColorDeltaInterval = 5000/(1+abs(deltahue2 - deltahue1));
  else
    randomColorDeltaInterval = 5000/(1+255-abs(deltahue2 - deltahue1));
}

long strHexToI(String recv)
{
  char c[recv.length() + 1];
  recv.toCharArray(c, recv.length() + 1);
  return strtol(c, NULL, HEX); 
}

#endif
