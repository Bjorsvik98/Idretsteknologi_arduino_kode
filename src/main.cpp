#include <Arduino.h>
#include <FastLED.h>
#include <Run_LED_strip.h>

// #include <OLED.h>
// #include <SPI.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

#define LedPin 3
#define LedStripPin 6
#define BoardLedPin 13
#define StartButton 4
#define StopButton 2
#define BuzzerPin 9

#define NumLeds 20
#define NumBlinkTimes 3
#define Brigthnes 255

// To make the strip run at variable speed, the time between each led is written in an array like this. If it is shorter than the number of leds it loop back to the first one again.
// To get the strip run at different speeds its needed different code. A start at that is implemented in the python folder.
int delays[] = {100,100};
// int delays[] = {400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200};


enum states {
    start,
    run,
    end,
    idle,
    reset,
};

states state = reset;
int size = sizeof(delays) / sizeof(int);
int lightCounter = 0; 
int arrayIndex = 0;
int loopCounter = 0;
int buzzerFreq1 = 500; //Hz
int buzzerFreq2 = 2000; //Hz

uint32_t buzzerOnTime = 500; //ms

unsigned long lastRunTime;
unsigned long startTime;
unsigned long buzzerTimer;
unsigned long StopButtonPressedTime;

bool startButtonFlag;
bool stopButtonFlag;
bool makeSound;



void setup() {
    Serial.begin(9600);
    FastLedInit();  
    pinMode(StartButton, INPUT);
    pinMode(StopButton, INPUT);
    pinMode(LedPin, OUTPUT);
    pinMode(BoardLedPin, OUTPUT); 
    pinMode(BuzzerPin, OUTPUT); // Set buzzer - pin 9 as an output

    // An Oled was thought to be used to display the time, but the last itteration of the code crashes during initialization of it
    // OLED_init(); 

    Serial.println("Program starts");
    ClearLights(0,64);
    
}

void loop() {
    // The buttons is read ever time the loop runs
    if (digitalRead(StartButton) && startButtonFlag == false){
        startButtonFlag = true;        
    }
    if (digitalRead(StopButton)){
        stopButtonFlag = true;
        StopButtonPressedTime = millis();
    }

    switch (state) {
        case start:          
            // Make the wait for start signal with the buzzer
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
            // When it should start the buzzer change freq to indicate start signal.
            if (loopCounter > NumBlinkTimes*2){
                digitalWrite(LedPin, HIGH);
                tone(BuzzerPin, buzzerFreq2);   
                startTime = millis();
                loopCounter = 0;             
                makeSound = false;
                state = run;
                startButtonFlag = false;
            }

        break;
        case run:
            if (millis() > (lastRunTime + delays[arrayIndex])) {
                arrayIndex++;
                lastRunTime = millis();
                
                runLedStrip(loopCounter);
                loopCounter++;
            }
            if (arrayIndex == size){
                arrayIndex = 0;
            }
            // The buzzer turn off when it has beeped for long enough
            if (((millis() - buzzerTimer) > (buzzerOnTime + 50)) && !makeSound) {
                digitalWrite(LedPin, LOW);
                noTone(BuzzerPin);
                makeSound = true;
            }
            if (loopCounter == NumLeds) {
                state = end;
            }
        break;
        case end:
            if (millis() > (lastRunTime + delays[arrayIndex])) {
                ClearLights(0, NumLeds);
            }

            if (stopButtonFlag == true && (millis() > (lastRunTime + delays[arrayIndex]))) { //wait untill both cases is done
                state = reset;
                Serial.println("StopButton");
                Serial.print("Time passed is ");
                Serial.print(StopButtonPressedTime - startTime);
                Serial.println(" ms");
            }
            if (startButtonFlag) { // This will restart theexecution, and are mostly there for debuggin and testing.
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