#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void OLED_init() {

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(4);          // text size
    // display.display();
}

void OLED_disp_time(long input_time) {
    display.clearDisplay();
    display.setTextSize(2);          // text size
    display.setCursor(0, 0);
    display.print((millis() - input_time)/1000.0,2);
    display.print(" sek");
    display.display();
}