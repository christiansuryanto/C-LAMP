#ifndef AUDIO_H
#define AUDIO_H

arduinoFFT FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);
extern eSPIFFS filesystem;

void EQDown();
void EQUp();
void EQSaveConfig();
void EQLoad();
void getAudioSample(bool inputType);
float getAudioFromE131();


// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //


void EQDown()
{
  if (EQ[selectedBand] > 0) EQ[selectedBand]-=0.05;
}

void EQUp()
{
  if (EQ[selectedBand] < 10) EQ[selectedBand]+=0.05;
}

void EQSaveConfig()
{
  Serial.println("Saving EQ Configuration...\n");

  filesystem.saveToFile("/EQ0.txt", EQ[0]);
  Serial.print("EQ for band-0 = "); Serial.println(EQ[0]);
  
  filesystem.saveToFile("/EQ1.txt", EQ[1]);
  Serial.print("EQ for band-1 = "); Serial.println(EQ[11]);

  filesystem.saveToFile("/EQ2.txt", EQ[2]);
  Serial.print("EQ for band-2 = "); Serial.println(EQ[2]);

  filesystem.saveToFile("/EQ3.txt", EQ[3]);
  Serial.print("EQ for band-3 = "); Serial.println(EQ[3]);

  filesystem.saveToFile("/EQ4.txt", EQ[4]);
  Serial.print("EQ for band-4 = "); Serial.println(EQ[4]);
  
  filesystem.saveToFile("/EQ5.txt", EQ[5]);
  Serial.print("EQ for band-5 = "); Serial.println(EQ[5]);
  
  filesystem.saveToFile("/EQ6.txt", EQ[6]);
  Serial.print("EQ for band-6 = "); Serial.println(EQ[6]);
  
  filesystem.saveToFile("/EQ7.txt", EQ[7]);
  Serial.print("EQ for band-7 = "); Serial.println(EQ[7]);

  Serial.println("\nEQ Configuration saved");
  delay(3000);
}

void EQLoad()
{
  Serial.println("Loading EQ Configuration...");
  for (int i=0; i<NUM_BANDS; i++)
  {
    Serial.print("EQ"); Serial.print(i); Serial.print(" = "); Serial.println(EQ[i]);
  }
  Serial.println("EQ Configuration loaded");
  delay(1000);
}

// ANALOG AUDIO SAMPLING NON-FFT //
void getAudioSample(bool inputType)
{
  int16_t audioMicIn;                                                                 // Current sample starts with negative values and large values, which is why it's 16 bit signed.
  uint16_t audioSampleMaxTimer;
  uint8_t audioSampleMaxMult;
  
  if (inputType == ANALOGMIC)
      audioMicIn = analogRead(AUDIO_IN_PIN);
  if (inputType == E131)
      audioMicIn = getAudioFromE131();
  audioMicLevel = ((audioMicLevel * 31) + audioMicIn) / 32;
  audioMicIn -= audioMicLevel;
  audioMicIn = abs(audioMicIn);

  audioSample = (audioMicIn <= audioSquelch) ? 0 : (audioSample + audioMicIn) / 2;    // Let's filter out the background noise with a ternary operator and more exponential smoothing.
  
  audioSampleAvg = ((audioSampleAvg * 25) + audioSample) / 32;
  if (audioSampleMax<audioSampleAvg) audioSampleMax = audioSampleAvg;

  if (audioSampleMax>70)
  {  
    audioSampleMaxTimer = 1;
    audioSampleMaxMult = 1;
  }  
  else
  {  
    audioSampleMaxTimer = 200;
    audioSampleMaxMult = 199;
  }
    
  if (audioSampleMax > audioSquelch+1)
  {
    EVERY_N_MILLIS_I(timeObj, audioSampleMaxTimer)
    {
      timeObj.setPeriod(audioSampleMaxTimer);
      audioSampleMax = ((audioSampleMaxMult*audioSampleMax) + audioSampleAvg)/(audioSampleMaxMult+1);
    }
  }
  //audioSampleAvg = ((audioSampleAvg * 30) + audioSample) / 32;
}


float getAudioFromE131()
{
  float audioVal = 0;
  
  if (!e131.isEmpty())
  {
    e131_packet_t packet;
    e131.pull(&packet);     // Pull packet from ring buffer
    uint8_t universeIDX = htons(packet.universe);
  
    audioVal = 0;
    if (universeIDX == 1) 
    {
        for (uint8_t i = 0; i < kMatrixHeight; i++) 
        {
          uint16_t j = (i * 3) + (CHANNEL_START);
          audioVal += (packet.property_values[j] + packet.property_values[j + 1] + packet.property_values[j + 2])/3;
        }
        audioVal /= (kMatrixHeight-1);
    }
    return constrain(audioVal, 0, 1000);
  }
  else return 0;
}
#endif
