#ifndef FAST_LED_H
#define FAST_LED_H
#include <FastLED.h>


/**
 * @brief Run strip with constatn time
 * 
 * @param NUM_LED 
 */
void strip_blink(int NUM_LED);

/**
 * @brief init LED strip
 * 
 */
void fast_LED_init(void);

/**
 * @brief run strip with interrupt
 * 
 */
void run_strip(void);




#endif