#ifndef FAST_LED_H
#define FAST_LED_H
#include <FastLED.h>


/**
 * @brief Run strip with constatn time and in a for loop, need input. It is a new func that dont need it. Try use strip_blink_constatn_speed instead.
 * 
 * 
 * @param NUM_LED 
 */
void StripBlink(int NUM_LED);

/**
 * @brief init LED strip
 * 
 */
void FastLedInit(void);

/**
 * @brief run strip with interrupt
 * 
 */
void RunStrip(void);

/**
 * @brief blink led strip with constant speed and one run per run in main
 * 
 */
void StripBlinkConstSpeed();

void RunLights(int first, int last, CRGB color);

void ClearLights(int first, int last);

void RunOneLight(int number, CRGB color);

void ClearOneLight(int number);

void runLedStrip(int loopCounter);




#endif