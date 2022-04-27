// #include <Arduino.h>
// #include <FastLED.h>
// #include <OLED.h>
// #include <interrupt_func.h>
// #include <fast_LED.h>
// #include <Button.h>
// #include <button_lib.h>



// // #include <Wire.h>
// // #include <Adafruit_GFX.h>
// // #include <Adafruit_SSD1306.h>

// // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// // #include <pgmspace.h>


// #define NUM_LEDS 62
// #define LED_pin 3
// #define button1 4
// #define button2 2
// #define buzzer 9

// #define NumBlinkTimes 3



// unsigned long StartTime ;
// unsigned long loopTime ;
// unsigned long time2 ;
// unsigned long time1 ;
// unsigned long timeStart ;
// // Button button3(4);


// // int array2[] = {50, 50, 50, 50, 50, 50, 200, 200, 200, 200, 50, 50, 50, 50, 50, 50, 200, 200, 200, 200};
// int array2[] = {10};
// int j = 0; 
// // int long_array[] = {32, 33, 35, 33, 33, 31, 31, 33, 34, 31, 31, 29, 31, 32, 34, 33, 32, 28, 38, 37, 40, 38, 34, 32, 30, 30, 34, 25, 24, 21, 24, 25, 27, 31, 29, 28, 30, 32, 35, 32, 30, 33, 31, 34, 33, 35, 35, 31, 34, 32, 30, 28, 30, 30, 27, 28, 33, 33, 31, 30, 33, 35, 33, 33, 35, 34, 36, 36, 34, 32, 29, 30, 32, 31, 28, 31, 31, 33, 36, 36, 35, 35, 34, 34, 34, 33, 32, 31, 32, 33, 33, 32, 31, 32, 32, 33, 32, 33, 32, 33, 33, 33, 31, 30, 31, 32, 31, 28, 27, 25, 28, 31, 33, 29, 30, 30, 32, 33, 33, 33, 32, 31, 31, 32, 33, 34, 34, 34, 36, 34, 33, 35, 36, 37, 37, 35, 31, 30, 28, 26, 26, 26, 21, 24, 27, 29, 31, 30, 29, 32, 28, 27, 27, 25, 26, 27, 30, 31, 34, 34, 36, 38, 38, 39, 39, 38, 35, 38, 39, 39, 37, 36, 33, 31, 33, 34, 30, 28, 29, 30, 31, 29, 32, 32, 32, 31, 34, 37, 29, 32, 33, 31, 32, 33, 33, 32, 30, 38, 34, 34};
// int k = 0;
// // int array2[] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300,300};
// // int array3[] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100};



// void setup() {
//   Serial.begin(9600);
//   fast_LED_init();  
//   StartTime = millis();
//   pinMode(button1, INPUT);
//   pinMode(button2, INPUT);
//   pinMode(LED_pin, OUTPUT);
//   pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
//   // OLED_init();
  
//   // clear_one_light(i);
//   run_one_light(3, CRGB::Red);
//   run_one_light(4, CRGB::Red);
//   run_one_light(5, CRGB::Red);
//   run_one_light(6, CRGB::Green);
//   run_one_light(7, CRGB::Green);
//   run_one_light(8, CRGB::Green);
// // while (true){}
 
//   Serial.println("Program starts");

// }

// void blink_LED(int LED_pin1, int Buzzer_pin, int duration){
//   unsigned long time = millis();
//   while(millis()-time2 < 4500){

//   }
// }

// void loop() {

//   j = 0;
//   if (true){
//   // if (button3.pressed()){
    
//     time1 = millis();
    
//     if (digitalRead(button1)){
//     // if (true){
//         time2 = millis();
//               int runNumbers = 0;
//               loopTime = millis();
//               while(runNumbers < NumBlinkTimes*2){
//                 // Serial.println(loopTime);
//                   if ((millis()-loopTime) > 500){
//                       loopTime = millis();
//                       digitalWrite(LED_pin, !digitalRead(LED_pin));
//                       if (runNumbers % 2 == 0){
//                           tone(buzzer, 700);
//                           Serial.println("run 700");
//                       } else if(runNumbers == NumBlinkTimes-1) {
//                           tone(buzzer, 2000);
//                           Serial.println("run 2000");
//                           loopTime = loopTime - 200;
//                       } else  {
//                           noTone(buzzer);
//                       }
                      
//                       runNumbers++;
//                   }
//               }
        
//       while(millis()-time2 < 4400){
//         if (millis()-time2 < 500){
//           digitalWrite(LED_pin, HIGH);
//           tone(buzzer, 500);
//         } else if (millis()-time2 < 1000) {
//           digitalWrite(LED_pin, LOW);
//           noTone(buzzer);
//         } else if (millis()-time2 < 1500){
//           digitalWrite(LED_pin, HIGH);
//           tone(buzzer, 500);
//         } else if (millis()-time2 < 2000) {
//           digitalWrite(LED_pin, LOW);
//           noTone(buzzer);
//         } else if (millis()-time2 < 2500){
//           digitalWrite(LED_pin, HIGH);
//           tone(buzzer, 500);
//         } else if (millis()-time2 < 3000) {
//           digitalWrite(LED_pin, LOW);
//           noTone(buzzer);
//         } else if (millis()-time2 < 3500){
//           digitalWrite(LED_pin, HIGH);
//           tone(buzzer, 1800);
//         } else if (millis()-time2 < 4400) {
//           digitalWrite(LED_pin, LOW);
//           noTone(buzzer);
//         }
//       }
//       timeStart = millis();

//     time1 = millis();
//     while(j < NUM_LEDS){
//        // clear_one_light(j-2); 
//         clear_one_light(j-1);
//         clear_one_light(j);
//         clear_one_light(j+1);
//         clear_one_light(j+2);

//         // run_one_light(j-1, CRGB::Red);
//         run_one_light(j, CRGB::Red);
//         run_one_light((j+1), CRGB::Red);
//         run_one_light(j+2, CRGB::Green);
//         run_one_light(j+3, CRGB::Green);
//         j++;

//       if (millis() > (time1 + array2[k])){
//         time1 = millis();       
//         // clear_one_light(j-2); 
//         clear_one_light(j-1);
//         clear_one_light(j);
//         clear_one_light(j+1);
//         clear_one_light(j+2);

//         // run_one_light(j-1, CRGB::Red);
//         run_one_light(j, CRGB::Red);
//         run_one_light((j+1), CRGB::Red);
//         run_one_light(j+2, CRGB::Green);
//         run_one_light(j+3, CRGB::Green);

//         j++;
//         k++;
//       }
//       int size = sizeof(array2) / sizeof(int);
//       if (k == size){
//         k = 0;
//       }
     
      
//     }

//     clear_one_light(NUM_LEDS-1);
//     // while (digitalRead(button2) == false){  }
//     // Serial.print(millis() - timeStart);
//     // Serial.println("ms");
//     // OLED_disp_time(timeStart);
    
//     // tone(buzzer, 2000);
//     // timeStart = millis();
//     // while ((millis()-timeStart < 100)){

    
//     // noTone(buzzer);
//     }
//   }
    
    
//   // unsigned long CurrentTime = millis();
//   // unsigned long ElapsedTime = CurrentTime - StartTime;



// }

