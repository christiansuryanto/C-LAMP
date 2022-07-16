/* IRControl.h - provide functions to handle IR */

#ifndef IRCONTROL_H
#define IRCONTROL_H

#include "Audio.h"

void IRCheck()
{
    byte currentLastMode;
    
    if (IrReceiver.decode())
    {
//      String strIRData;
      
      strIRData = String(IrReceiver.decodedIRData.decodedRawData, HEX);
      strIRData.toUpperCase();
      
      if (strIRData != "0")
      {
        if (strIRData == KEY_RESTART) { setLEDModeOff(); delay(200); ESP.restart();}
        if (strIRData == KEY_PWR) { isBlinking= true; LEDDutyCycle = LEDActive; isIdle = true; counterIdle = 0; timerLEDidle = 0; LEDOnOff(); }
        if ((strIRData == KEY_MODE) && (!isLEDOFF))     // KEY MODE DETECTED
        {

          currentLastMode = lastMode;
          
          isBlinking= true;
          if (isIdle)
          {
            if (currentEffect == idxConfigBars && currentMode == SPEED_MODE)
            {
              EQSaveConfig();
            }
            if (currentMode < currentLastMode) currentMode++; else currentMode = 1;
          }
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
          setCurrentLEDMode();
        }
        if ((strIRData == KEY_DOWN1) && (!isLEDOFF))     // KEY DOWN1 DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          switch (currentMode)
          {
            case MANUAL_PATTERN_MODE :
              //effectDown();
              nextPattern(false);
              filesystem.saveToFile("/currentEffect.txt", currentEffect);
              break;
              
            case AUTO_PATTERN_MODE :
              toggleAutoEffects();
              filesystem.saveToFile("/autoChangePatterns.txt", autoChangePatterns);
              break;
              
            case BRIGHTNESS_MODE :
              brightnessDown();
              filesystem.saveToFile("/currentBrightness.txt", currentBrightness);
              break;
              
            case VOLGAIN_MODE :
              volDown();
              filesystem.saveToFile("/currentAmplitude.txt", currentAmplitude);
              filesystem.saveToFile("/currentGVolume.txt", currentGVolume);
              break;
              
            case AUTO_HUE_PAL_MODE :
              toggleAutoHuePal();
              break;

            case MANUAL_HUE_PAL_MODE :
              HuePalDown();
              break;

            case SPEED_MODE :
                animSpeedDown();
              break;
          }

          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        if ((strIRData == KEY_UP1) && (!isLEDOFF))     // KEY UP1 DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          
          //if (isIdle)
          switch (currentMode)
          {
            case MANUAL_PATTERN_MODE :
              //effectUp();
              nextPattern(true);
              filesystem.saveToFile("/currentEffect.txt", currentEffect);
              break;
              
            case AUTO_PATTERN_MODE :
              toggleAutoEffects();
              filesystem.saveToFile("/autoChangePatterns.txt", autoChangePatterns);
              break;
              
            case BRIGHTNESS_MODE :
              brightnessUp();
              filesystem.saveToFile("/currentBrightness.txt", currentBrightness);
              break;
              
            case VOLGAIN_MODE :
              volUp();
              filesystem.saveToFile("/currentAmplitude.txt", currentAmplitude);
              filesystem.saveToFile("/currentGVolume.txt", currentGVolume);
              break;
              
            case AUTO_HUE_PAL_MODE :
              toggleAutoHuePal();
              break;

            case MANUAL_HUE_PAL_MODE :
              HuePalUp();
              break;

            case SPEED_MODE :
                animSpeedUp();
              break;
          }

          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        if ((strIRData == KEY_DOWN2) && (!isLEDOFF))     // KEY DOWN2 DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          saturationDown();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        if ((strIRData == KEY_UP2) && (!isLEDOFF))     // KEY UP2 DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          saturationUp();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }        

        if (strIRData == KEY_DOWN3 && !isLEDOFF && currentMode == SPEED_MODE)     // KEY DOWN3 DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          //saturationDown();
          EQDown();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        if (strIRData == KEY_UP3 && !isLEDOFF && currentMode == SPEED_MODE)     // KEY UP3 DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          EQUp();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }        

        if ((strIRData == KEY_GAUD) && (!isLEDOFF))     // KEY GAUD DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          toggleGlobalAudioReactive();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        //if ((strIRData == KEY_FAN) && (!isLEDOFF))     // KEY FAN DETECTED
        if (strIRData == KEY_FAN)     // KEY FAN DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          toggleFan();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        //if ((strIRData == KEY_FANDOWN) && (!isLEDOFF))     // KEY FANDOWN DETECTED
        if (strIRData == KEY_FANDOWN)     // KEY FANDOWN DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          fanSpeedDown();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        //if ((strIRData == KEY_FANUP) && (!isLEDOFF))     // KEY FANUP DETECTED
        if (strIRData == KEY_FANUP)     // KEY FANUP DETECTED
        {
          currentMillis= millis();
          isBlinking= true;
          fanSpeedUp();
          LEDDutyCycle = LEDActive;
          isIdle = true;
          counterIdle = 0;
          timerLEDidle = 0;
        }

        if ((strIRData == KEY_WIFI) && (!isLEDOFF))     // KEY WIFI DETECTED
        {
          //currentMillis= millis();
          //isBlinking= true;
          enableWifi = !enableWifi;
          filesystem.saveToFile("/enableWifi.txt", enableWifi);
          setLEDModeOff();
          delay(350);
          //setCurrentLEDMode();
          ESP.restart();
        }
      }
      IrReceiver.resume(); // Enable receiving of the next value
    }
}

#endif
