/*
 * Blink the LED at a rate proportional to the received digit value
 * 
 * Мигание светодиодом со скоростью, пропорциональной полученному по 
 * последовательному интерфейсу значению
 * 
 * Connections:
 *  Indicator LED connected to IO1-1kOm Resistor-GND
*/

#include <Arduino.h>
#define LED1 1

int blinkDelay = 0;  // blink delay stored in this variable

// blink the LED with the on and off times determined by blinkDelay
void blink()
{
  digitalWrite(LED1, HIGH);
  delay(blinkDelay); // delay depends on blinkDelay value
  digitalWrite(LED1, LOW);
  delay(blinkDelay);
}

void setup()
{
  Serial.begin(115200); // Initialize serial port to send and receive at 9600 baud
  pinMode(LED1, OUTPUT); // set this pin as output
}

void loop()
{
  if (Serial.available()) // Check to see if at least one character is available
  {
    char ch = (char) Serial.read();
    if( isDigit(ch) ) // is this an ascii digit between 0 and 9?
    {
      blinkDelay = (ch - '0');       // ASCII value converted to numeric value
      blinkDelay = blinkDelay * 100; // actual delay is 100ms times received digit
    }
  }
  blink();
}


