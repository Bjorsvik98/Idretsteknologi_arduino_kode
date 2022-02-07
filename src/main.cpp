#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN 6



int LED_pin = 13;
CRGB leds[NUM_LEDS];

void setup() {
  pinMode(LED_pin, OUTPUT);
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.addLeds<WS2812B,DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
}

void loop() {
  // fill_gradient_RGB(leds, NUM_LEDS, CRGB::Blue, CRGB::Red, CRGB::Yellow);
  // leds[1] = CRGB::HotPink;
  // FastLED.show();
  // delay(1000);

  // fill_solid(leds, NUM_LEDS, CRGB::Red);
  
 
  


for (int i = 0; i < NUM_LEDS; i++){
  leds[i] = CRGB::Green;
  leds[i-1] = CRGB::MediumBlue;
  leds[i+1] = CRGB::MediumBlue;
  FastLED.show();
  delay(500);
  leds[i] = CRGB::Black;
  leds[i+1] = CRGB::Black;
  leds[i-1] = CRGB::Black;
  FastLED.show();
  
    
  //  FastLED.show();
}
  
  // put your main code here, to run repeatedly:
}
