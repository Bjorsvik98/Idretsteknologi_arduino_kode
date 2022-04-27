#include <Arduino.h>
#include <FastLED.h>
#include <OLED.h>
#include <interrupt_func.h>
#include <fast_LED.h>
#include <Button.h>
#include <button_lib.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LedPin 3
#define LedStripPin 6
#define BoardLedPin 13
#define StartButton 4
#define StopButton 2
#define BuzzerPin 9

#define NumLeds 15
#define NumBlinkTimes 1
#define Brigthnes 255
#define NumLedsUsed 3

int delays[] = {100,100};
// int delays[] = {400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200};


enum states {
    start,
    run,
    end,
    idle,
    reset,
    initialize,
};

states state = initialize;
int size = sizeof(delays) / sizeof(int);
int lightCounter = 0; 
int arrayIndex = 0;
int loopCounter = 0;
int buzzerFreq1 = 700; //Hz
int buzzerFreq2 = 2000; //Hz

uint32_t buzzerOnTime = 500; //ms

unsigned long lastRunTime;
unsigned long startTime;
unsigned long buzzerTimer;
unsigned long StopButtonPressedTime;

bool startButtonFlag;
bool stopButtonFlag;
bool makeSound;

// CRGB leds[NumLeds];




void setup() {
    Serial.begin(9600);
    FastLedInit();  
    pinMode(StartButton, INPUT);
    pinMode(StopButton, INPUT);
    pinMode(LedPin, OUTPUT);
    pinMode(BoardLedPin, OUTPUT);
    pinMode(BuzzerPin, OUTPUT); // Set buzzer - pin 9 as an output

    // OLED_init();



    Serial.println("Program starts");
    digitalWrite(BoardLedPin, HIGH);
    ClearLights(0,64);
    
}

void loop() {
    
    if (digitalRead(StartButton) && startButtonFlag == false){
        startButtonFlag = true;        
    }
    if (digitalRead(StopButton)){
        Serial.println("Stop button is pressed");
        stopButtonFlag = true;
        StopButtonPressedTime = millis();
    }

    switch (state) {
        case initialize:
            state = reset;
        break;
        case start:          
            if ((millis() - buzzerTimer) > buzzerOnTime) {
                
                buzzerTimer = millis();
                if (makeSound) {
                    digitalWrite(LedPin, HIGH);
                    tone(BuzzerPin, buzzerFreq1);
                    makeSound = false;
                } else {
                    digitalWrite(LedPin, LOW);
                    noTone(BuzzerPin);
                    makeSound = true;
                }
                loopCounter++;
            }
            if (loopCounter > NumBlinkTimes*2){
                digitalWrite(LedPin, HIGH);
                tone(BuzzerPin, buzzerFreq2);   
                startTime = millis();
                loopCounter = 0;             
                makeSound = false;
                state = run;
            }

        break;
        case run:
            if (millis() > (lastRunTime + delays[arrayIndex])) {
                arrayIndex++;
                lastRunTime = millis();
                // ClearLights(loopCounter-1, loopCounter+1);
                // RunLights(loopCounter, loopCounter+3, CRGB::White);

                // for (int i = loopCounter; i <= NumLedsUsed; i++) {
                //     leds[i] = CRGB::White;
                // }
                runLedStrip(loopCounter);
                loopCounter++;
            }
            if (arrayIndex == size){
                arrayIndex = 0;
            }
            if (((millis() - buzzerTimer) > buzzerOnTime) && !makeSound) {
                digitalWrite(LedPin, LOW);
                noTone(BuzzerPin);
                makeSound = true;
            }
            if (loopCounter == NumLeds) {
                state = end;
                startButtonFlag = false;
            }
        break;
        case end:
            if (millis() > (lastRunTime + delays[arrayIndex])) {
                ClearLights(0, NumLeds);
            }
            if (stopButtonFlag) {
                // oled disp the time 
                Serial.print("Time passed is ");
                Serial.print(StopButtonPressedTime - startTime);
                Serial.println(" ms");
                // OLED_disp_time(StopButtonPressedTime - startTime);

            }

            if (stopButtonFlag == true && (millis() > (lastRunTime + delays[arrayIndex]))) { //wait untill both cases is done
                state = reset;
                Serial.println("StopButton");
            }
            if (startButtonFlag) {
                state = reset;
                Serial.println("StartButton");

            }
        break;
        case idle:
            if (startButtonFlag) {
                startButtonFlag = false;
                state = start;
            }
        break;
        case reset:
            Serial.println("Reset");
            ClearLights(0, NumLeds);
            stopButtonFlag = false;
            startButtonFlag = false;
            lightCounter = 0;
            arrayIndex = 0;
            lastRunTime = 0; //initialize it to zero so the first itteration start immediatly
            buzzerTimer = 0;
            loopCounter = 0;
            makeSound = true;
            state = idle;
        break;
    }
 
}