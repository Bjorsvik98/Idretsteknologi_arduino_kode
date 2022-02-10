#include <Arduino.h>
#include <Button.h>
#include <interrupt_func.h>

Button button1(4);
Button button2(3);

void button_init(void){
  button1.begin();
}


void change_speed(void){
    
    if (button1.pressed()) {
        // OCR1A = 500;
        Serial.println("button1 is pressed");
    }
    else if (button2.pressed()) {
        // OCR1A = 2000;
        Serial.println("button2 is pressed");
    }
}