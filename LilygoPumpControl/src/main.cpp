#include <Arduino.h>
#include <ezButton.h> //библиотека для борьбы с дребезгом

// Пин подключения кнопки
 #define PIN_BUTTON 1
// Пин подключения светодиода
 #define PIN_LED 2
// Пин подключения драйвера
 #define PIN_DRIVER 3
 
ezButton button(PIN_BUTTON);  // create ezButton object that attach to PIN_BUTTON;

 
int buttonLastState = HIGH; // the previous state from the input pin
int buttonState;     // the current reading from the input pin
int motorState = LOW; // флаг состояния мотора

void setup()
{
  Serial.begin(9600);
button.setDebounceTime(50); // set debounce time to 50 milliseconds
  pinMode(PIN_DRIVER, OUTPUT);      // Устанавливаем вывод драйвера как выход
  pinMode(PIN_BUTTON, INPUT_PULLUP); // Устанавливаем вывод кнопки как вход и включаем подтяжку
  digitalWrite(PIN_DRIVER, LOW);    // Устанавливаем вывод в LOW
// read the state of the switch/button:
  buttonState = digitalRead(PIN_BUTTON);
}
void loop()
{
buttonLastState = buttonState;  // save the last state
buttonState = digitalRead(PIN_BUTTON);  // read new state
  // print out the button's state
  Serial.println(buttonState);
if (buttonLastState == HIGH && buttonState == LOW) {
    Serial.println("The button is pressed");
    // toggle state of motor
    motorState = !motorState;
    // control motor arccoding to the toggled state
    digitalWrite(PIN_DRIVER, motorState);
  }
}