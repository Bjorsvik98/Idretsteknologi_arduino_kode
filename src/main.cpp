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
  // put your setup code here, to run once:
}

void loop() {
  // digitalWrite(LED_pin, HIGH);
  // delay(500);
  // digitalWrite(LED_pin, LOW);
  // delay(500);
  Serial.println("loop compleeted");
  for (int i = 0; i < NUM_LEDS; i++){
     leds[i] = CRGB::Blue;
     FastLED.show();
     delay(200);
     leds[i] = CRGB::Black;
     FastLED.show();
 }
  // put your main code here, to run repeatedly:
}
