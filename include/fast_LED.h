#ifndef FAST_LED_H
#define FAST_LED_H
#include <FastLED.h>


/**
 * @brief Run strip with constatn time and in a for loop, need input. It is a new func that dont need it. Try use strip_blink_constatn_speed instead.
 * 
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

/**
 * @brief blink led strip with constant speed and one run per run in main
 * 
 */
void strip_blink_const_speed();


void run_one_light(int number, CRGB color);

void clear_one_light(int number);




#endif