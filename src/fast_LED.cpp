#include <Arduino.h>
#include <FastLED.h>
#include <fast_LED.h>
#include <interrupt_func.h>

#define NUM_LEDS 20
#define DATA_PIN 6
#define LED_pin 13

bool interupt_flag = false;
int i = 0;

CRGB leds[NUM_LEDS];

void strip_blink(int NUM_LED) {
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

void strip_blink_const_speed(){
    leds[i] = CRGB::Blue;
    leds[i-1] = CRGB::MediumBlue;
    leds[i+1] = CRGB::MediumBlue;
    FastLED.show();
    delay(150);
    leds[i] = CRGB::Black;
    leds[i+1] = CRGB::Black;
    leds[i-1] = CRGB::Black;
    FastLED.show();
    i++;

    if (i == (NUM_LEDS - 1)){
        i = 0;
    }
}

void fast_LED_init(void){
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(20);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
}

void run_strip(void){
    if (interupt_flag == true) {
        interupt_flag = false;
        leds[i] = CRGB::Black;
        leds[i-1] = CRGB::Black;

        if (i == (NUM_LEDS - 1)){ 
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
    // if (i == (NUM_LEDS - 1)){ i = 0; }

    // i++;
    // leds[i] = CRGB::Red;
    // FastLED.show();

    // interupt_flag = false;

}