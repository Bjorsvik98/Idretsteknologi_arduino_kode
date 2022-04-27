#include <Arduino.h>
#include <FastLED.h>
#include <fast_LED.h>
#include <interrupt_func.h>

#define NumLeds 120
#define LedStripPin 6
#define Brightnes 255

bool interupt_flag = false;
int i = 0;

CRGB leds[NumLeds];

void runLedStrip(int loopCounter){
    for (int i = 0; i < loopCounter-1;i++){
        leds[i] = CRGB::Black;
    }
    leds[loopCounter-1] = CRGB::Red;
    leds[loopCounter] = CRGB::Green;
    FastLED.show();
}

void StripBlink(int NUM_LED) {
    for (int i = 0; i < NUM_LED; i++){
        leds[i] = CRGB(255,0,0);
        // leds[i-1] = CRGB::Red;
        // leds[i+1] = CRGB::Blue;
        FastLED.show();
        delay(100);
        leds[i] = CRGB(0,0,0);
        // leds[i+1] = CRGB::Black;
        // leds[i-1] = CRGB::Black;
        FastLED.show();
        Serial.println("Test");
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




void StripBlinkConstSpeed(){
    leds[i] = CRGB::Purple;
    leds[i-1] = CRGB::Blue;
    leds[i+1] = CRGB::Red;
    FastLED.show();
    delay(150);
    leds[i] = CRGB::Black;
    leds[i+1] = CRGB::Black;
    leds[i-1] = CRGB::Black;
    FastLED.show();
    i++;

    if (i == (NumLeds - 1)){
        i = 0;
    }
}

void FastLedInit(void){
    FastLED.addLeds<WS2812B, LedStripPin, GRB>(leds, NumLeds);
    FastLED.setBrightness(Brightnes);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
}

void RunStrip(void){
    if (interupt_flag == true) {
        interupt_flag = false;
        leds[i] = CRGB::Black;
        leds[i-1] = CRGB::Black;

        if (i == (NumLeds - 1)){ 
            i = 0; 
        }
        i++;
        leds[i] = CRGB::Red;
        leds[i-1] = CRGB::Purple;
        FastLED.show();
        
    }

}


ISR(TIMER1_COMPA_vect)
{
    interupt_flag = true;
    // leds[i] = CRGB::Black;
    // if (i == (NumLeds - 1)){ i = 0; }

    // i++;
    // leds[i] = CRGB::Red;
    // FastLED.show();

    // interupt_flag = false;

}