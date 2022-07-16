#ifndef WIFI_H
#define WIFI_H

#include <esp_wifi_types.h>    // Built-in
#include <esp_wifi.h>
#include <WiFi.h>               // Built-in
#include <ESPAsyncE131.h>       // https://github.com/forkineye/ESPAsyncE131

#include "Func.h"

// E131 definition stuff
#define MAX_LEDS_PER_UNIVERSE 170
#define UNIVERSE              1
#define UNIVERSE_COUNT        10  // Total number of Universes to listen for, starting at UNIVERSE
#define CHANNEL_START         1

ESPAsyncE131 e131(UNIVERSE_COUNT);

void drawE131_to_LED();

// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //
// ========================================================================================================================================== //

void drawE131_to_LED()
{
  if (!e131.isEmpty())
  {
    //fadeToBlackBy(activeLeds, NUM_LEDS, 1);
    //nscale8(activeLeds, NUM_LEDS, 10);
    e131_packet_t packet;
    e131.pull(&packet);     // Pull packet from ring buffer
    uint8_t universeIDX = htons(packet.universe);
  
    if (universeIDX == 1) // FOR 2D STRIP
    {
        //for (uint8_t i = 0; i < universeIDX*MAX_LEDS_PER_UNIVERSE < NUM_LEDS ? MAX_LEDS_PER_UNIVERSE : NUM_LEDS - ((universeIDX-1)*MAX_LEDS_PER_UNIVERSE); i++) 
        for (uint8_t i = 0; i < kMatrixHeight; i++) 
        {
          uint16_t j = (i * 3) + (CHANNEL_START);
           for (uint8_t x=0; x<kMatrixWidth; x++)
           {
              activeLeds[XYRev(x, i)] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
           }
        }
    }
    
    if (universeIDX == 5) // FOR 1D STRIP 
    {
        //for (uint8_t i = 0; i < universeIDX*MAX_LEDS_PER_UNIVERSE < NUM_LEDS ? MAX_LEDS_PER_UNIVERSE : NUM_LEDS - ((universeIDX-1)*MAX_LEDS_PER_UNIVERSE); i++) 
        for (uint8_t i = 0; i < MAX_LEDS_PER_UNIVERSE; i++) 
        {
          uint16_t j = (i * 3) + (CHANNEL_START);
           activeLeds[i] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
        }
    }

    if (universeIDX == 6) // FOR 1D STRIP..CONTINUED
    {
        for (uint8_t i = 0; i < NUM_LEDS - MAX_LEDS_PER_UNIVERSE; i++) 
        {
          uint16_t j = (i * 3) + (CHANNEL_START);
           //activeLeds[XYTable[MAX_LEDS_PER_UNIVERSE + i]] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
           activeLeds[MAX_LEDS_PER_UNIVERSE + i] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
        }
    }

    if (universeIDX == 9) // FOR 1D STRIP, REVERSED ORDER
    {
        //for (uint8_t i = 0; i < universeIDX*MAX_LEDS_PER_UNIVERSE < NUM_LEDS ? MAX_LEDS_PER_UNIVERSE : NUM_LEDS - ((universeIDX-1)*MAX_LEDS_PER_UNIVERSE); i++) 
        for (uint8_t i = 0; i < MAX_LEDS_PER_UNIVERSE; i++) 
        {
          uint16_t j = (i * 3) + (CHANNEL_START);
           activeLeds[XYTable[i]] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
        }
    }

    if (universeIDX == 10) // FOR 1D STRIP.. CONTINUED, REVERSED ORDER
    {
        for (uint8_t i = 0; i < NUM_LEDS - MAX_LEDS_PER_UNIVERSE; i++) 
        {
          uint16_t j = (i * 3) + (CHANNEL_START);
           //activeLeds[XYTable[MAX_LEDS_PER_UNIVERSE + i]] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
           activeLeds[XYTable[MAX_LEDS_PER_UNIVERSE + i]] = CRGB(packet.property_values[j], packet.property_values[j + 1], packet.property_values[j + 2]);
        }
    }
  }
  else
  {
    //fadeToBlackBy(activeLeds, NUM_LEDS, 20);
    //nscale8(activeLeds, NUM_LEDS, 10);
  }
  //FastLED.show();
}
#endif
