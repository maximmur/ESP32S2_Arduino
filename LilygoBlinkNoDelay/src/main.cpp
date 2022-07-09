/*
ESP32-S2;Arduino;Platformio
Мигание двумя сетодиодами без использования задержки
*/
#include <Arduino.h>

const unsigned long TIME_INTERVAL_LED1 = 1000;
const unsigned long TIME_INTERVAL_LED2 = 250;

// Variables will change:
int led1_State = LOW;   // ledState used to set the LED 1
int led2_State = LOW;   // ledState used to set the LED 2
unsigned long previousMillis_LED1 = 0;   // will store last time LED 1 was updated
unsigned long previousMillis_LED2 = 0;   // will store last time LED 2 was updated

//int LED1 = 1;              // LED connected to digital pin 13
#define LED1 1
#define LED2 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);    // sets the digital pin as output
  pinMode(LED2, OUTPUT);    // sets the digital pin as output
  previousMillis_LED1 = previousMillis_LED2 = millis();
}

void loop() {
  if(millis()-previousMillis_LED1 >= TIME_INTERVAL_LED1){  // check to see if it's time to blink the LED 1 
   led1_State = (led1_State == LOW) ? HIGH : LOW;
   digitalWrite(LED1, led1_State); // sets the LED status
   previousMillis_LED1 = millis();   
  }

  if(millis()-previousMillis_LED2 >= TIME_INTERVAL_LED2){  // check to see if it's time to blink the LED 1 
   led2_State = (led2_State == LOW) ? HIGH : LOW;
   digitalWrite(LED2, led2_State); // sets the LED status
   previousMillis_LED2 = millis();   
  }
}