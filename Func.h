/* Func.h - provide functions to handle any part of device (non-LedStrip, non-IR) */
 
#ifndef FUNC_H
#define FUNC_H

uint16_t getIndex( uint8_t x, uint8_t y);
uint16_t XY( uint8_t x, uint8_t y);
uint16_t XYRev( uint8_t x, uint8_t y);

void initPWM();
void toggleFan();
void setFanSpeed(int value);
void fanSpeedDown();
void fanSpeedUp();
void fanControl(byte input);
void setLED(byte channel, int value);
void setLEDModeOff();
void setCurrentLEDMode();
void LEDOnOff();
void fadeInStartUp();
void fadeInWakeUp();
void fadeOutSleep();

// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //

const uint8_t XYTable[] = 
{
    23,  22,  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0,
    47,  46,  45,  44,  43,  42,  41,  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  24,
    71,  70,  69,  68,  67,  66,  65,  64,  63,  62,  61,  60,  59,  58,  57,  56,  55,  54,  53,  52,  51,  50,  49,  48,
    95,  94,  93,  92,  91,  90,  89,  88,  87,  86,  85,  84,  83,  82,  81,  80,  79,  78,  77,  76,  75,  74,  73,  72,
   119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100,  99,  98,  97,  96,
   143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120,
   167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144,
   191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168
  };


uint16_t getIndex( uint8_t x, uint8_t y)
{
  uint16_t i;
  //i = (x * kMatrixHeight) + y;
  i = (x * kMatrixHeight) + kMatrixHeight - 1 - y;
  return i;
}

uint16_t XY( uint8_t x, uint8_t y)
{
  if(y >= kMatrixHeight) { y = kMatrixHeight - 1; }
  if(x >= kMatrixWidth) { x = kMatrixWidth - 1; }
  uint16_t ret;

  ret = (x * kMatrixHeight) + kMatrixHeight - 1 - y;
  return ret;
}

uint16_t XYRev( uint8_t x, uint8_t y)
{
  if(y >= kMatrixHeight) { y = kMatrixHeight - 1; }
  if(x >= kMatrixWidth) { x = kMatrixWidth - 1; }
  uint16_t ret;

  ret = (x * kMatrixHeight) + y;
  return ret;
}

void initPWM()
{
  ledcSetup(FAN_CH, 16, 10);
  ledcAttachPin(FAN_PIN, FAN_CH);  
}

void toggleFan()
{
  if (fanSpeed == 0) fanSpeed = 510; else fanSpeed = 0;
  filesystem.saveToFile("/fanSpeed.txt", fanSpeed);
  setFanSpeed(fanSpeed);
}

void setFanSpeed(int value)
{
  ledcWrite(FAN_CH, value);
}

void fanSpeedDown()
{
  if (fanSpeed > minFanSpeed) fanSpeed-=stepFanSpeed;
  filesystem.saveToFile("/fanSpeed.txt", fanSpeed);
  setFanSpeed(fanSpeed);
}

void fanSpeedUp()
{
  if (fanSpeed < maxFanSpeed) fanSpeed+=stepFanSpeed;
  filesystem.saveToFile("/fanSpeed.txt", fanSpeed);
  setFanSpeed(fanSpeed);
}

void fanControl(byte input)
{
  digitalWrite(FAN_PIN, input);  
}

void setLED(byte channel, int value)
{
  if (value == 1) analogWrite(channel, LEDDutyCycle); else analogWrite(channel, 0);
  //if (value == 1) ledcWrite(channel, LEDDutyCycle); else ledcWrite(channel, 0);
}


void setLEDModeOff()
{
  setLED(LEDMODE1_PIN, 0);
  setLED(LEDMODE2_PIN, 0);
  setLED(LEDMODE3_PIN, 0);
  //if (millis() > currentMillis + pauseDelay) isBlinking = false;
  if (currentEffect <= idxSolidColor) isBlinking = false;
      else if (millis() > currentMillis + pauseDelay) isBlinking = false;
}

void setCurrentLEDMode()
{
  switch (currentMode)
  {
    case 1 :    // MODE EFFECTS   //GREEN
      setLED(LEDMODE1_PIN, 1);
      setLED(LEDMODE2_PIN, 0);
      setLED(LEDMODE3_PIN, 0);
      break;

    case 2 :    // MODE TOGGLE AUTOCHANGE EFFECTS   //BLUE
      setLED(LEDMODE1_PIN, 0);
      setLED(LEDMODE2_PIN, 1);
      setLED(LEDMODE3_PIN, 0);
      break;

    case 3 :    // MODE BRIGHTNESS    //RED
      setLED(LEDMODE1_PIN, 0);
      setLED(LEDMODE2_PIN, 0);
      setLED(LEDMODE3_PIN, 1);
      break;

    case 4 :    // MODE VOLUME    //YELLOW
      setLED(LEDMODE1_PIN, 1);
      setLED(LEDMODE2_PIN, 0);
      setLED(LEDMODE3_PIN, 1);
      break;

    case 5 :    // MODE AUTOCHANGE HUE CENTERBARS     //PINK
      setLED(LEDMODE1_PIN, 0);
      setLED(LEDMODE2_PIN, 1);
      setLED(LEDMODE3_PIN, 1);
      break;

    case 6 :    // MODE MANUAL CHANGE HUE CENTERBARS  //CYAN
      setLED(LEDMODE1_PIN, 1);
      setLED(LEDMODE2_PIN, 1);
      setLED(LEDMODE3_PIN, 0);
      break;

    case 7 :    // MODE SPEED (DELAY)   //WHITE
      setLED(LEDMODE1_PIN, 1);
      setLED(LEDMODE2_PIN, 1);
      setLED(LEDMODE3_PIN, 1);
      break;
  }
}

void LEDOnOff()
{
  if (!isLEDOFF)
  {
    beginBrightness = currentBrightness;
    timerFading = 0;
    toSleep = true;
  }
  else 
  {
    beginBrightness = 1;
    timerFading = 0;
    toWakeUp = true;
  }
  isLEDOFF = !isLEDOFF;
}

void fadeInStartUp()
{
  if (isFading)
  {
    if ((millis() > timerFading))
    {
      FastLED.setBrightness(beginBrightness);
      beginBrightness/=0.5;
      if (beginBrightness >= currentBrightness) { isFading = false; FastLED.setBrightness(currentBrightness); }
      timerFading = millis() + delayFading;
    }
  }
}

void fadeInWakeUp()
{
  if (toWakeUp)
  {
    if ((millis() > timerFading))
    {
      FastLED.setBrightness(beginBrightness);
      beginBrightness/=0.5;
      if (beginBrightness >= currentBrightness) { toWakeUp = false; FastLED.setBrightness(currentBrightness); }
      timerFading = millis() + delayFading;
    }
  }
}


void fadeOutSleep()
{
  if (toSleep)
  {
    if ((millis() > timerFading))
    {
      FastLED.setBrightness(beginBrightness);
      beginBrightness*=0.6;
      if (beginBrightness <= 0.5) { toSleep = false; FastLED.setBrightness(0); }
      timerFading = millis() + delayFading;
    }
  }
}

#endif
