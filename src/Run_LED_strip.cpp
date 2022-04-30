#include <Arduino.h>
#include <FastLED.h>
#include <Run_LED_strip.h>
#include <interrupt_func.h>

#define NumLeds 120
#define LedStripPin 6
#define Brightnes 255


CRGB leds[NumLeds];

void FastLedInit(void){
    FastLED.addLeds<WS2812B, LedStripPin, GRB>(leds, NumLeds);
    FastLED.setBrightness(Brightnes);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
}

void ClearOneLight(int number){
    leds[number] = CRGB::Black;
    FastLED.show();
}

void ClearLights(int first, int last){
    for (int i = first; i <= last; i++){
        leds[i] = CRGB::Black;
        FastLED.show();
    }
}

void RunOneLight(int number, CRGB color){
    leds[number] = color;
    FastLED.show();
}

void RunLights(int first, int last, CRGB color){
    for (int i = first; i <= last; i++){
        leds[i] = color;
        FastLED.show();
    }
}

void runLedStrip(int loopCounter){
    for (int i = 0; i < loopCounter-1;i++){
        leds[i] = CRGB::Black;
    }
    leds[loopCounter-1] = CRGB::Red;
    leds[loopCounter] = CRGB::Green;
    FastLED.show();
}

