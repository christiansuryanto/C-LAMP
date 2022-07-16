// ============================================ //
// Heavily adapted from                         //
// Scott Marley's ESP32_FFT_VU                  //
// https://github.com/s-marley/ESP32_FFT_VU     //
// ============================================ //

#include <esp_system.h>        // Built-in
#include <esp_spi_flash.h>     // Built-in 

#include <IRremote.hpp>         // https://github.com/Arduino-IRremote/Arduino-IRremote
#include <FastLED.h>            // https://github.com/FastLED/FastLED
#include <arduinoFFT.h>         // https://github.com/kosme/arduinoFFT
#include <ColorConverterLib.h>  // https://github.com/luisllamasbinaburo/Arduino-ColorConverter
#include <ParticleSys.h>        // https://github.com/christiansuryanto/arduino-particle-sys, I made a fork from https://github.com/giladaya/arduino-particle-sys
                                // edit library so that different effects can have its own particles parameter instead of shared ones (max. of 3)

#include "GLOBALS.h"
#include "WebCode.h"
#include "IRControl.h"

// Audio.h - included in IRControl.h
// Func.h - included in WiFi_E131.h
// Control.h, PatternDef.h - included in PatternCode.h
// WiFi_E131.h, PatternCode.h, credentials.h - included in WebCode.h


extern CRGB sourceLeds[NUM_LEDS];
extern CRGB targetLeds[NUM_LEDS];
extern CRGB activeLeds[NUM_LEDS];


// Create a eSPIFFS class
eSPIFFS filesystem;


void setup()
{
  // FastLED intialization
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(activeLeds, NUM_LEDS).setDither(0);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setMaxPowerInVoltsAndMilliamps(LED_VOLTS, MAX_MILLIAMPS);
  FastLED.show();

  Serial.begin(115200);
  pinMode(AUDIO_IN_PIN, INPUT_PULLDOWN);
  //delay(1000); // some microcontrollers reboot twice

  if (!filesystem.checkFlashConfig()) 
  {
    Serial.println("Flash size was not correct! Please check your SPIFFS config and try again");
    delay(10);
    ESP.restart();
  }

  filesystem.openFromFile("/enableWifi.txt", enableWifi);

  if (enableWifi) { greenColorSnap(); Serial.println("WIFI ENABLED"); initWebServer(); } else { redColorSnap(); Serial.println("WIFI DISABLED"); }
  
  filesystem.openFromFile("/KEY_PWR.txt", KEY_PWR);
  filesystem.openFromFile("/KEY_RESTART.txt", KEY_RESTART);
  filesystem.openFromFile("/KEY_DOWN1.txt", KEY_DOWN1);
  filesystem.openFromFile("/KEY_DOWN2.txt", KEY_DOWN2);
  filesystem.openFromFile("/KEY_MODE.txt", KEY_MODE);
  filesystem.openFromFile("/KEY_UP1.txt", KEY_UP1);
  filesystem.openFromFile("/KEY_UP2.txt", KEY_UP2);
  filesystem.openFromFile("/KEY_GAUD.txt", KEY_GAUD);
  filesystem.openFromFile("/KEY_FAN.txt", KEY_FAN);
  filesystem.openFromFile("/KEY_FANDOWN.txt", KEY_FANDOWN);
  filesystem.openFromFile("/KEY_FANUP.txt", KEY_FANUP);
  filesystem.openFromFile("/KEY_WIFI.txt", KEY_WIFI);

  filesystem.openFromFile("/MAX_MILLIAMPS.txt", MAX_MILLIAMPS);

  filesystem.openFromFile("/currentEffect.txt", currentEffect);
  sourceEffect = currentEffect;
  targetEffect = currentEffect + 1;
  
  filesystem.openFromFile("/autoChangePatterns.txt", autoChangePatterns);
  filesystem.openFromFile("/currentBrightness.txt", currentBrightness);
  FastLED.setBrightness(currentBrightness);
  filesystem.openFromFile("/currentAmplitude.txt", currentAmplitude);
  filesystem.openFromFile("/pauseDelay.txt", pauseDelay);
  filesystem.openFromFile("/isGlobalAudioReactive.txt", isGlobalAudioReactive);
  filesystem.openFromFile("/currentGVolume.txt", currentGVolume);
  
  filesystem.openFromFile("/EQ0.txt", EQ[0]);
  filesystem.openFromFile("/EQ1.txt", EQ[1]);
  filesystem.openFromFile("/EQ2.txt", EQ[2]);
  filesystem.openFromFile("/EQ3.txt", EQ[3]);
  filesystem.openFromFile("/EQ4.txt", EQ[4]);
  filesystem.openFromFile("/EQ5.txt", EQ[5]);
  filesystem.openFromFile("/EQ6.txt", EQ[6]);
  filesystem.openFromFile("/EQ7.txt", EQ[7]);
  EQLoad();

  setLEDDutyCycle();

  filesystem.openFromFile("/currentSaturation.txt", currentSaturation);

  filesystem.openFromFile("/intervalNFireHue.txt", intervalNFireHue);
  filesystem.openFromFile("/currentNFireHue.txt", currentNFireHue);
  filesystem.openFromFile("/currentNFireDelay.txt", currentNFireDelay);
  filesystem.openFromFile("/nfireAutoHue.txt", nfireAutoHue);

  filesystem.openFromFile("/currentPPlasmaDelay.txt", currentPPlasmaDelay);

  filesystem.openFromFile("/currentEasingDelay.txt", currentEasingDelay);
  filesystem.openFromFile("/currentEasingHue.txt", currentEasingHue);
  filesystem.openFromFile("/intervalEasingHue.txt", intervalEasingHue);

  filesystem.openFromFile("/AABarFrameDelay.txt", AABarFrameDelay);

  filesystem.openFromFile("/keroseneAutoPalette.txt", keroseneAutoPalette);
  filesystem.openFromFile("/kerosenePaletteIndex.txt", kerosenePaletteIndex);

  filesystem.openFromFile("/randomColorAutoPalette.txt", randomColorAutoPalette);

  filesystem.openFromFile("/intervalFlameHue.txt", intervalFlameHue);
  filesystem.openFromFile("/currentFlameHue.txt", currentFlameHue);
  filesystem.openFromFile("/currentFlameDelay.txt", currentFlameDelay);
  filesystem.openFromFile("/flameAutoHue.txt", flameAutoHue);
  emitterFlame.baseHue = currentFlameHue;

  filesystem.openFromFile("/intervalPaintHue.txt", intervalPaintHue);
  filesystem.openFromFile("/currentPaintHue.txt", currentPaintHue);
  filesystem.openFromFile("/currentPaintDelay.txt", currentPaintDelay);
  filesystem.openFromFile("/paintAutoHue.txt", paintAutoHue);
  emitterPaint.baseHue = currentPaintHue;

  filesystem.openFromFile("/intervalSmokeHue.txt", intervalSmokeHue);
  filesystem.openFromFile("/currentSmokeHue.txt", currentSmokeHue);
  filesystem.openFromFile("/currentSmokeDelay.txt", currentSmokeDelay);
  filesystem.openFromFile("/smokeAutoHue.txt", smokeAutoHue);
  emitterSmoke.baseHue = currentSmokeHue;

  filesystem.openFromFile("/intervalStarHue.txt", intervalStarHue);
  filesystem.openFromFile("/currentStarHue.txt", currentStarHue);
  filesystem.openFromFile("/currentStarDelay.txt", currentStarDelay);
  filesystem.openFromFile("/starAutoHue.txt", starAutoHue);
  emitterStar.baseHue = currentStarHue;

  filesystem.openFromFile("/intervalSpinnerHue.txt", intervalSpinnerHue);
  filesystem.openFromFile("/currentSpinnerHue.txt", currentSpinnerHue);
  filesystem.openFromFile("/currentSpinnerDelay.txt", currentSpinnerDelay);
  filesystem.openFromFile("/spinnerAutoHue.txt", spinnerAutoHue);
  emitterSpinner.baseHue = currentSpinnerHue;

  filesystem.openFromFile("/intervalCBHue.txt", intervalCBHue);
  filesystem.openFromFile("/currentCBHue.txt", currentCBHue);
  filesystem.openFromFile("/CBAutoHue.txt", CBAutoHue);

  filesystem.openFromFile("/SBAutoPalette.txt", SBAutoPalette);
  filesystem.openFromFile("/SBPaletteIndex.txt", SBPaletteIndex);
  
  filesystem.openFromFile("/intervalPurpleBarsHue.txt", intervalPurpleBarsHue);
  filesystem.openFromFile("/currentPurpleBarsHue.txt", currentPurpleBarsHue);
  filesystem.openFromFile("/purpleBarsAutoHue.txt", purpleBarsAutoHue);

  filesystem.openFromFile("/intervalTrailHue.txt", intervalTrailHue);
  filesystem.openFromFile("/currentTrailHue.txt", currentTrailHue);
  setTrailHue(currentTrailHue);
  filesystem.openFromFile("/trailAutoHue.txt", trailAutoHue);
  filesystem.openFromFile("/currentTrailDelay.txt", currentTrailDelay);

  filesystem.openFromFile("/currentSolidHue.txt", currentSolidHue);

  filesystem.openFromFile("/currentNexusDelay.txt", currentNexusDelay);
  filesystem.openFromFile("/currentNexusScale.txt", currentNexusScale);
  filesystem.openFromFile("/nexusAutoPalette.txt", nexusAutoPalette);
  filesystem.openFromFile("/nexusPaletteIndex.txt", nexusPaletteIndex);
  nexusSetPalette();

  filesystem.openFromFile("/currentPacifica1DDelay.txt", currentPacifica1DDelay);

  //filesystem.openFromFile("/auroraRandom.txt", auroraRandom);
  filesystem.openFromFile("/currentAuroraSpeed.txt", currentAuroraSpeed);
  filesystem.openFromFile("/AURORA_COLOR_RANGE.txt", AURORA_COLOR_RANGE);

  //filesystem.openFromFile("/boilRandom.txt", boilRandom);
  filesystem.openFromFile("/currentBoilScale.txt", currentBoilScale);

  //filesystem.openFromFile("/wfallRandom.txt", wfallRandom);
  filesystem.openFromFile("/currentWFallScale.txt", currentWFallScale);
  filesystem.openFromFile("/currentWFallVar2.txt", currentWFallVar2);

  //filesystem.openFromFile("/rubikRandom.txt", rubikRandom);
  filesystem.openFromFile("/currentRubikScale.txt", currentRubikScale);
  filesystem.openFromFile("/currentRubikDelay.txt", currentRubikDelay);

  //filesystem.openFromFile("/currentLava1Scale.txt", currentLava1Scale);
  filesystem.openFromFile("/currentLava1Speed.txt", currentLava1Speed);
  
  filesystem.openFromFile("/currentRotateLampHue.txt", currentRotateLampHue);
  filesystem.openFromFile("/rotateLampAutoHue.txt", rotateLampAutoHue);

  filesystem.openFromFile("/currentRadFireDelay.txt", currentRadFireDelay);
  filesystem.openFromFile("/currentRadFireHue.txt", currentRadFireHue);
  filesystem.openFromFile("/radFireAutoHue.txt", radFireAutoHue);

  filesystem.openFromFile("/currentBP1Delay.txt", currentBP1Delay);
  filesystem.openFromFile("/bp1AutoHue.txt", bp1AutoHue);
  filesystem.openFromFile("/currentBP1Hue.txt", currentBP1Hue);
  
  filesystem.openFromFile("/currentBP2Delay.txt", currentBP2Delay);
  filesystem.openFromFile("/bp2AutoHue.txt", bp2AutoHue);
  filesystem.openFromFile("/currentBP2Hue.txt", currentBP2Hue);

  filesystem.openFromFile("/currentBP3Delay.txt", currentBP3Delay);
  filesystem.openFromFile("/bp3AutoHue.txt", bp3AutoHue);
  filesystem.openFromFile("/currentBP3Hue.txt", currentBP3Hue);

  filesystem.openFromFile("/currentLava2Hue.txt", currentLava2Hue);
  filesystem.openFromFile("/lava2AutoHue.txt", lava2AutoHue);

  filesystem.openFromFile("/currentLava3Delay.txt", currentLava3Delay);
  filesystem.openFromFile("/lava3AutoHue.txt", lava3AutoHue);
  filesystem.openFromFile("/currentLava3Hue.txt", currentLava3Hue);
  filesystem.openFromFile("/currentLava3Speed.txt", currentLava3Speed);

  filesystem.openFromFile("/cwAutoPalette.txt", cwAutoPalette);
  filesystem.openFromFile("/cwCurrentPaletteNumber.txt", cwCurrentPaletteNumber);
  cwTargetPalette = cwGradientPalettes[cwCurrentPaletteNumber];

  filesystem.openFromFile("/currentHypHue.txt", currentHypHue);
  filesystem.openFromFile("/hypAutoHue.txt", hypAutoHue);

  filesystem.openFromFile("/currentsnovaHue.txt", currentsnovaHue);
  filesystem.openFromFile("/currentsnovaSpeed.txt", currentsnovaSpeed);
  filesystem.openFromFile("/snovaAutoHue.txt", snovaAutoHue);

  filesystem.openFromFile("/Fire2AutoPalette.txt", Fire2AutoPalette);
  filesystem.openFromFile("/Fire2PaletteIndex.txt", Fire2PaletteIndex);
  filesystem.openFromFile("/Fire2Scale.txt", Fire2Scale);
  filesystem.openFromFile("/Fire2Speed.txt", Fire2Speed);
  // EOF eSPIFFS PART //

  // init Patterns //
  initFlame(activeLeds);
  initPaint(activeLeds);
  initSmoke(activeLeds);
  initStar(activeLeds);
  initSpinner(activeLeds);
  initKerosene();
  initRandomColor();
  initRadFire();
  initsnova();
  // EOF init Patterns //

  //additional init, based on isGlobalAudioReactive //
  if (currentEffect==idxPaint)
  {
    if (isGlobalAudioReactive)
      initPaint_runtimeSR();
    else
      initPaint_runtimeNOSR();
  }
  ///////////////////////////////////////////////////
  
  // INDICATOR LED PIN Initialization //
  initPWM();
  pinMode(LEDMODE1_PIN, OUTPUT);   // IND LED. 1
  pinMode(LEDMODE2_PIN, OUTPUT);   // IND LED. 2
  pinMode(LEDMODE3_PIN, OUTPUT);   // IND LED. 3
  setLED(LEDMODE1_PIN, 1);    // MODE = 1 (animation)
  setLED(LEDMODE2_PIN, 0);
  setLED(LEDMODE3_PIN, 0);

  pinMode(FAN_PIN, OUTPUT);
  filesystem.openFromFile("/fanSpeed.txt", fanSpeed);
  setFanSpeed(fanSpeed);

  IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK); // Start the receiver
  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQ));

  delayFading = 1;
}



void loop() 
{
//  Serial.println(strIRData);
//  strIRData = "";
  if (!isBlinking) IRCheck();
  if (isBlinking) setLEDModeOff(); else setCurrentLEDMode();

  if (isIdle)
  {
    if (millis() > timerLEDidle)
    {
      counterIdle++;
      if (counterIdle == secondsToDim) { isIdle = false; counterIdle = 0; LEDDutyCycle = LEDinActive; setCurrentLEDMode(); }
      timerLEDidle = millis() + 1000;
    }
  }
  
  
  if (enableWifi && !isGlobalAudioReactive)
  {
//    fadeToBlackBy(activeLeds, NUM_LEDS, 2);
    drawE131_to_LED();
    FastLED.show();
  }
  
  if ((enableWifi && isGlobalAudioReactive) || !enableWifi)
  {
    //if (currentEffect < idxBLANK1)
    {
      runPattern(sourceEffect, sourceLeds);                  // Run both patterns simultaneously
      runPattern(targetEffect, targetLeds);
    }
  
    // Reset bandValues[]
    for (int i = 0; i<NUM_BANDS; i++)
    {
      bandValues[i] = 0;
    }
    
    if (currentEffect >= idxSeparatorFFT)
    {
        if (!isLEDOFF) FastLED.setBrightness(currentBrightness);
        // Sample the audio pin
        for (int i = 0; i < SAMPLES; i++) 
        {
          newTime = micros();
          vReal[i] = abs(analogRead(AUDIO_IN_PIN)); // A conversion takes about 9.7uS on an ESP32
          vImag[i] = 0;
          while ((micros() - newTime) < sampling_period_us) { /* chill */ }
        }
      
        // Compute FFT
        FFT.DCRemoval();
        FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
        FFT.Compute(FFT_FORWARD);
        FFT.ComplexToMagnitude();
    }
    else if ((isGlobalAudioReactive) && !isLEDOFF)
    {
      if (!enableWifi)
          getAudioSample(ANALOGMIC);
      else
          getAudioSample(E131);
      //getAudioFromE131();
    }
  
    // Analyse FFT results
    for (int i = 2; i < (SAMPLES/2); i++)
    {       // Don't use sample 0 and only first SAMPLES/2 are usable. Each array element represents a frequency bin and its value the Amplitude.
      if (vReal[i] > DIGITAL_NOISE) 
      {                    // Add a crude noise filter
          //8 bands, 12kHz top band
          if (i<=3 )           bandValues[0]  += (int)vReal[i];
          if (i>3   && i<=6  ) bandValues[1]  += (int)vReal[i];
          if (i>6   && i<=13 ) bandValues[2]  += (int)vReal[i];
          if (i>13  && i<=27 ) bandValues[3]  += (int)vReal[i];
          if (i>27  && i<=55 ) bandValues[4]  += (int)vReal[i];
          if (i>55  && i<=112) bandValues[5]  += (int)vReal[i];
          if (i>112 && i<=229) bandValues[6]  += (int)vReal[i];
          if (i>229          ) bandValues[7]  += (int)vReal[i];
      }
    }
  
    // Process the FFT data into bar heights
    for (byte band = 0; band < NUM_BANDS; band++) 
    {
    // Scale the bars for the display
      int barHeight = (band % 2 == 1? 0 : ((bandValues[band]+bandValues[band+1])/2) * EQ[band]/(currentAmplitude));
  
      if (barHeight > TOP) barHeight = TOP;
  
      // Small amount of averaging between frames
      barHeight = ((oldBarHeights[band] * 1) + (barHeight*1)) / 2;
      
      // Move peak up
      if (barHeight > peak[band]) 
      {
        peak[band] = min(TOP, barHeight);
      }
  
      // Draw bars
      fadeInStartUp();
      if (toSleep) fadeOutSleep();
      if (toWakeUp) fadeInWakeUp();
  
      // BLENDING EFFECT PART //
      EVERY_N_MILLIS(10) 
      {
        blend(sourceLeds, targetLeds, activeLeds, NUM_LEDS, blendAmount);   // Blend between the two sources
    
        if (isSwapped) 
        {
          if (blendAmount < 255) blendAmount+=blendSteps;                   // Blend 'up' to source 2
        } 
        else 
        {
          if (blendAmount > 0) blendAmount-=blendSteps;                     // Blend 'down' to source 1
        }
      }
    
      //Serial.println(blendAmount);
      if (!isLEDOFF && !toSleep && !toWakeUp && isGlobalAudioReactive)
      {
        if (currentEffect == idxColorWaves)
        {  
          if (FastLED.getBrightness()< constrain(currentBrightness*2, minBrightness, maxBrightness*0.75)) { FastLED.setBrightness(FastLED.getBrightness()+1); }
        }
        else
          FastLED.setBrightness(currentBrightness);
      }
  
      if (currentEffect >= idxBLANK1 - 1)
      {
        runPatternSpectrum(sourceEffect, band, barHeight, sourceLeds);                  // Run both patterns simultaneously
        runPatternSpectrum(targetEffect, band, barHeight, targetLeds);
      }
      // EOF BLENDING EFFECT PART //
  
      // Save oldBarHeights for averaging later
      oldBarHeights[band] = barHeight;
    }
  
    // Decay peak
    EVERY_N_MILLISECONDS(60) 
    {
      for (byte band = 0; band < NUM_BANDS; band++)
        if (peak[band] > 0) peak[band] -= 1;
      colorTimer++;
    }
  
    // Used in some of the patterns
    EVERY_N_MILLISECONDS(10) 
    {
      colorTimer++;
    }
    
    if (autoChangePatterns)
    {
      EVERY_N_SECONDS(10)
      {
          nextPattern(true);
          if (currentEffect == idxSolidColor) nextPattern(true);
          //if (currentEffect == idxSeparatorPAT) nextPattern(true);
          if (currentEffect == idxBLANK1) { nextPattern(true); nextPattern(true); }
      }
    }
  
    switch (currentEffect)
    {
      case idxBoil : 
                break;
      case idxNFire : 
                break;
      case idxSolidColor : 
                break;
      case idxTrailDown : 
                break;
      case idxFlame : 
                break;
      case idxPaint : 
                break;
      case idxSmoke : 
                break;
      case idxStar : 
                break;
      case idxSpinner : 
                break;
      case idxNexus : 
                break;
      case idxPacifica1D : 
                break;
      case idxPPlasma : 
                break;
      case idxEasing : 
                break;
      case idxAABar : 
                break;
      case idxKerosene : 
                break;
      case idxRandomColor : 
                break;
      case idxPride : 
                break;
      case idxPre1STW : 
                break;
      case idxPre2STW : 
                break;
      case idxSoftTwinkles : 
                break;
      case idxPost2STW : 
                break;
      case idxPost1STW : 
                break;
      case idxAurora : 
                break;
      case idxWFall : 
                break;
      case idxRubik : 
                break;
      case idxRotateLamp : 
                break;
      case idxRadFire : 
                break;
      case idxBarberPole1 : 
                break;
      case idxBarberPole2 : 
                break;
      case idxBarberPole3 : 
                break;
      case idxLava2 : 
                break;
      case idxLava3 : 
                break;
      case idxLava1 : 
                break;
      case idxDrawBars : 
                break;
      case idxRGBHype : 
                break;
      case idxColorWaves : 
                break;
      case idxSNova : 
                break;
      case idxFire2 : 
                break;
      case idxBLANK1 :
                FastLED.show(); 
                break;
      case idxConfigBars : 
                FastLED.show();
                break;
      case idxRainbowBars : 
                FastLED.show();
                break;
      case idxOutrun : 
                FastLED.show();
                break;
      case idxPurpleBars : 
                FastLED.show();
                break;
      case idxCenterBars : 
                FastLED.show();
                break;
      case idxSideBars : 
                FastLED.show();
                break;
      case idxChangingBars : 
                FastLED.show();
                break;
      case idxWFallSR : 
                FastLED.show();
                break;
    }
  
    ///////////////////////////// SOFT TWINKLES NECESSARY PROCESS, NEED CLEAR AREA /////////////////////////////////
    // Clear the screen, prepare for softTwinkle
    // check for empty screen to ensure code spawn
    //// GETTING INTO SOFTTWINKLES ////
    bool emptyScreen1 = true;
    for(int i = 0; i < NUM_LEDS; i++) 
    {
      if (activeLeds[i])
      {
        emptyScreen1 = false;
        break;
      }
    }
    
    if (strIRData == KEY_UP1 && currentEffect == idxPre1STW && emptyScreen1)
    {
      //Serial.println("OK");
      FastLED.clear();
      strIRData = "";
      nextPattern(true);
      nextPattern(true);
    }
    
    if (strIRData == KEY_DOWN1 && currentEffect == idxPost1STW && emptyScreen1)
    {
      //Serial.println("OK");
      FastLED.clear();
      strIRData = "";
      nextPattern(false);
      nextPattern(false);
    }
  
    //// GETTING OUT FROM SOFTTWINKLES ////
    if (strIRData == KEY_UP1 && currentEffect == idxPost2STW)
    {
      FastLED.clear();
      strIRData = "";
      nextPattern(true);
      nextPattern(true);
    }
  
    if (strIRData == KEY_DOWN1 && currentEffect == idxPre2STW)
    {
      FastLED.clear();
      strIRData = "";
      nextPattern(false);
      nextPattern(false);
    }
  
    //Serial.println(currentEffect);
    if (currentEffect == idxPre1STW && firstLoad)
    {
      firstLoad = false;
      //Serial.println("OK1");
      nextPattern(true);
      nextPattern(true);
    }
  
    if (currentEffect == idxPost1STW && firstLoad)
    {
      firstLoad = false;
      //Serial.println("OK2");
      nextPattern(false);
      nextPattern(false);
    }

    if (currentEffect == idxPre2STW && firstLoad)
    {
      firstLoad = false;
      //Serial.println("OK1");
      nextPattern(false);
      nextPattern(false);
    }
  
    if (currentEffect == idxPost2STW && firstLoad)
    {
      firstLoad = false;
      //Serial.println("OK2");
      nextPattern(true);
      nextPattern(true);
    }
    ///////////////////////////// EOF SOFT TWINKLES NECESSARY PROCESS, NEED CLEAR AREA /////////////////////////////////
  }
}
