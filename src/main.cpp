#include <Arduino.h>
#include <FastLED.h>
#include <interrupt_func.h>
#include <fast_LED.h>
#include <Button.h>

#define NUM_LEDS 20
#define LED_pin 13

Button button1(2);
Button button2(3);

int k = 0;

// CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  fast_LED_init();
  interrupt_init();

  button1.begin();


}



void loop() {

  // strip_blink(NUM_LEDS);

  run_strip();

  if (button1.pressed()) {
    OCR1A = 500;
    Serial.println("button1 is pressed");
  }
  else if (button2.pressed()) {
    OCR1A = 2000;
    Serial.println("button2 is pressed");

  }
    
  // OCR1A = (k + 100);
  // k++;
  // if (k == 10000){
  //   k = 0;
  // }

}

