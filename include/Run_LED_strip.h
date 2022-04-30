#ifndef RUN_LED_STRIP_H
#define RUN_LED_STRIP_H
#include <FastLED.h>


/**
 * @brief init LED strip
 * 
 */
void FastLedInit(void);

/**
 * @brief Run multiple LEDs from first to last (Zero indexed)
 * 
 * @param first The fist LED to be lit
 * @param last The last LED to be lit
 * @param color The color on the LED
 */
void RunLights(int first, int last, CRGB color);

/**
 * @brief Clear the light from first to last (Zero indexed)
 * 
 * @param first 
 * @param last 
 */
void ClearLights(int first, int last);

/**
 * @brief Light up ine LED (Zero indexed)
 * 
 * @param number 
 * @param color 
 */
void RunOneLight(int number, CRGB color);

/**
 * @brief Clear the color from one LED (Zero indexed)
 * 
 * @param number 
 */
void ClearOneLight(int number);

/**
 * @brief Light up one red and one green light and turn the ones before to black. 
 * It is loopCounter and the one before that is lit up
 * 
 * @param loopCounter The LED that goes green, and the one before goes red
 */
void runLedStrip(int loopCounter);




#endif