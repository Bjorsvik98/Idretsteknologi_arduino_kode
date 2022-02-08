#include <Arduino.h>
#include <FastLED.h>
#include <interrupt_func.h>
#include <fast_LED.h>
#include <Button.h>
#include <button_lib.h>

#define NUM_LEDS 20
#define LED_pin 13

void setup() {
  Serial.begin(9600);
  fast_LED_init();
  // interrupt_init();
  // button_init();

}

void loop() {

  // run_strip();
  // change_speed();

  strip_blink_const_speed();
  
}

