#ifndef GLOBALS_H
#define GLOBALS_H

//#define CLED_GLOBAL extern
const uint8_t  kMatrixWidth                      = 8;                                // Matrix width
const uint8_t  kMatrixHeight                     = 24;                               // Matrix height
const uint8_t  NUM_LEDS                          = kMatrixWidth * kMatrixHeight;     // Total number of LEDs

uint8_t        currentBrightness = 74;

CRGB            sourceLeds[NUM_LEDS];
CRGB            targetLeds[NUM_LEDS];
CRGB            activeLeds[NUM_LEDS];


// IR Stuff
#define         RECV_PIN                          17
#define         OFF                               0
#define         ON                                1
String          KEY_PWR                           = "FF000E0E";                       // key 0 on cooca tv remote
String          KEY_RESTART                       = "F20D0E0E";                       // KEY MUTE on cooca tv remote
String          KEY_DOWN1                         = "FB040E0E";                       // key 4 on cooca tv remote
String          KEY_DOWN2                         = "F8070E0E";                       // key 7 on cooca tv remote
String          KEY_DOWN3                         = "F7080E0E";                       // key 8 on cooca tv remote
String          KEY_MODE                          = "FA050E0E";                       // key 5 on cooca tv remote
String          KEY_UP1                           = "F9060E0E";                       // key 6 on cooca tv remote
String          KEY_UP2                           = "F6090E0E";                       // key 9 on cooca tv remote
String          KEY_UP3                           = "FD020E0E";                       // key 2 on cooca tv remote
String          KEY_GAUD                          = "F40B0E0E";                       // key () on cooca tv remote
String          KEY_FAN                           = "4AB50E0E";                       // key EXIT on cooca tv remote
String          KEY_FANDOWN                       = "FE010E0E";                       // key 1 on cooca tv remote
String          KEY_FANUP                         = "FC030E0E";                       // key 3 on cooca tv remote
String          KEY_WIFI                          = "52AD0E0E";                       // key FAV on cooca tv remote
String          strIRData;

// ---------------------------------------------------------------------------------------------------------------------------------------------------- //

// PATTERN / EFFECT INDEXING ///
#define idxBoil             0
#define idxNFire            1
#define idxSolidColor       2
#define idxTrailDown        3
#define idxFlame            4
#define idxPaint            5
#define idxSmoke            6
#define idxStar             7
#define idxSpinner          8
#define idxNexus            9
#define idxPacifica1D       10
#define idxPPlasma          11
#define idxEasing           12
#define idxAABar            13
#define idxKerosene         14
#define idxRandomColor      15
#define idxPride            16
#define idxPre1STW          17
#define idxPre2STW          18
#define idxSoftTwinkles     19
#define idxPost2STW         20
#define idxPost1STW         21
#define idxAurora           22
#define idxWFall            23
#define idxRubik            24
#define idxRotateLamp       25
#define idxRadFire          26
#define idxBarberPole1      27
#define idxBarberPole2      28
#define idxBarberPole3      29
#define idxLava2            30
#define idxLava3            31
#define idxLava1            32
#define idxDrawBars         33
#define idxRGBHype          34
#define idxColorWaves       35
#define idxSNova            36
#define idxFire2            37

#define idxBLANK1           38

#define idxConfigBars       39
#define idxRainbowBars      40
#define idxOutrun           41
#define idxPurpleBars       42
#define idxCenterBars       43
#define idxSideBars         44
#define idxChangingBars     45
#define idxWFallSR          46

#define idxSeparatorFFT     39
#define idxSeparatorPAT     38

#define        lastEffect   46

// ---------------------------------------------------------------------------------------------------------------------------------------------------- //

//WiFi
bool           enableWifi = true;
bool           enableE131 = false;

// ---------------------------------------------------------------------------------------------------------------------------------------------------- //

// MENU INDICATOR LED & VARS //
#define        LEDMODE1_PIN                      18                                  // INDICATOR LED 1
#define        LEDMODE2_PIN                      5                                   // INDICATOR LED 2
#define        LEDMODE3_PIN                      19                                  // INDICATOR LED 3
#define        LEDMODE1_CH                       1                                   // CHANNEL INDICATOR LED 1
#define        LEDMODE2_CH                       2                                   // CHANNEL INDICATOR LED 2
#define        LEDMODE3_CH                       3                                   // CHANNEL INDICATOR LED 3
#define        FAN_PIN                           26
#define        FAN_CH                            4
int            LEDActive                         = 15;
int            LEDinActive                       = 2;
int            LEDDutyCycle                      = 15;
#define        lastMode                          7                                   // index of last Mode
int            pauseDelay                        = 200;                              // delay for pause in milliseconds
unsigned long  currentMillis;
unsigned long  pauseTimer                        = 0;
byte           currentMode                       = 1; 
byte           currentEffect                     = 0;
byte           selectedBand                      = 0;
bool           isBlinking                        = false;
bool           isPaused                          = false;
bool           isGlobalAudioReactive             = false;
byte           fanState                          = 0;
#define        minFanSpeed                       0
#define        maxFanSpeed                       1020
#define        stepFanSpeed                      102
int            fanSpeed                          = 0;

#define MANUAL_PATTERN_MODE                     1
#define AUTO_PATTERN_MODE                       2
#define BRIGHTNESS_MODE                         3
#define VOLGAIN_MODE                            4
#define AUTO_HUE_PAL_MODE                       5
#define MANUAL_HUE_PAL_MODE                     6
#define SPEED_MODE                              7

bool           autoChangePatterns                = false;                            // Double click will change animation / brightness mode
bool           isLEDOFF                          = false;
bool           firstLoad                         = true;
unsigned long  timerLEDidle                      = 0;
bool           isIdle                            = true;
int            counterIdle                       = 0;
#define        secondsToDim                      2

// ---------------------------------------------------------------------------------------------------------------------------------------------------- //

// AUDIO Stuff
#define         SAMPLES                           512                                 // Must be a power of 2
#define         SAMPLING_FREQ                     40000                               // Hz, must be 40000 or less due to ADC conversion time. Determines maximum frequency that can be analysed by the FFT Fmax=sampleF/2.
#define         NUM_BANDS                         8                                   // To change this, you will need to change the bunch of if statements describing the mapping from bins to bands
#define         minAmplitude                      100                                 // Minimmum amplitude
#define         maxAmplitude                      20000                               // Maximum amplitude
int             currentAmplitude                  = 2000;                             // Depending on your audio source level, you may need to alter this value. Can be used as a 'sensitivity' control.
#define         EQ_NUM                            2
#define         AUDIO_IN_PIN                      32                                  // Signal in on this pin

float EQ[8]     = { 1, 1, 1, 1, 1, 1, 1, 1 };

unsigned int    sampling_period_us;
byte            peak[]                            = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};              // The length of these arrays must be >= NUM_BANDS
int             oldBarHeights[]                   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int             bandValues[]                      = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double          vReal[SAMPLES];
double          vImag[SAMPLES];
unsigned long   newTime;
uint8_t         colorTimer                        = 0;
#define         minGVolume                        1
#define         maxGVolume                        254
int             currentGVolume                    = 10;
double          audioSample;

// ---------------------------------------------------------------------------------------------------------------------------------------------------- //

// LED Stuff
#define                   LED_PIN                           2                                   // LED strip data
#define                   COLOR_ORDER                       GRB                                 // If colours look wrong, play with this
#define                   CHIPSET                           WS2812B                             // LED strip type
int                       MAX_MILLIAMPS                     = 8500;                             // Careful with the amount of power here if running off USB port
#define                   minBrightness                     14
#define                   maxBrightness                     254
extern uint8_t            currentBrightness;
const int                 BRIGHTNESS_SETTINGS[3]            = {10, 70, 200};                    // 3 Integer array for 3 brightness settings (based on pressing+holding BTN_PIN)
#define                   LED_VOLTS                         5                                   // Usually 5 or 12
#define                   DIGITAL_NOISE                     400                                 // Used as a crude noise filter, values below this are ignored
extern const uint8_t      kMatrixWidth;                                                         // Matrix width
extern const uint8_t      kMatrixHeight;                                                        // Matrix height
extern const uint8_t      NUM_LEDS;                                                             // Total number of LEDs
#define                   MAX_LEDS_E131                     170
#define                   BAR_WIDTH                         (kMatrixWidth  / (NUM_BANDS - 1))   // If width >= 8 light 1 LED width per bar, >= 16 light 2 LEDs width bar etc
#define                   TOP                               (kMatrixHeight - 0)                 // Don't allow the bars to go offscreen
#define                   SERPENTINE                        false                               // Set to false if you're LEDS are connected end to end, true if serpentine
unsigned long             timerFading                       = 0;
unsigned long             delayFading                       = 0;
bool                      isFading                          = true;
bool                      toSleep                           = false;
bool                      toWakeUp                          = false;
float                     beginBrightness                   = 1;

int                       blendAmount                       = 0;
int                       blendSteps                        = 15; //3, 5, 15, 17, 51
int                       sourceEffect                      = 0;
int                       targetEffect                      = 1;
bool                      isSwapped                         = false;
bool                      isNext                            = false;

// ---------------------------------------------------------------------------------------------------------------------------------------------------- //

// AUDIO NON-FFT METHOD
#define                   ANALOGMIC 0
#define                   E131      1
uint8_t                   audioSquelch                      = 4;      // Anything below this is background noise. Use a higher value with a physical microphone.
float                     audioSampleAvg                    = 0;      // Smoothed Average.
float                     audioSampleMax                    = 5;      // 
float                     audioMicLevel                     = 0;      // Used to convert returned value to have '0' as minimum.
uint8_t                   vals[NUM_LEDS];                             // Used for sound reactivity blending.


#endif
