/*
ESP32-S2;Arduino;Platformio
Мигание сетодиодом используя задержку с выводом статуса в терминал
Blinking inbuilt LED using a delay with status output to the terminal
*/
#include <Arduino.h>

//int LED1 = 1;              // LED connected to digital pin 1
#define LED1 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);    // sets the digital pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH); // sets the LED on
  Serial.println("LED1 is on");
  delay(1000);                // waits for a second
  
  digitalWrite(LED1, LOW);  // sets the LED off
  Serial.println("LED1 is off");
  delay(1000);                // waits for a second
}