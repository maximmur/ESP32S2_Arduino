/*
ESP32-S2;Arduino;Platformio
We begin to work with a buzzer. The code generates a siren on
passive and active piezo emitters.

Начинаем работать с пьезоизлучателем. Код генерирует сирену на 
пассивном и активном пьезоизлучателях. 

Используемый модуль:
Подключение: Баззер - к - + через резистор 400 Ом к I00
*/

#include <Arduino.h>
int buzzPin=0;
int dt1=1;
int dt2=2;
int j;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin, OUTPUT);
}

void loop() {
for (j=1;j<=100;j=j+1){
  digitalWrite(buzzPin, HIGH);
  delay(dt1);
  digitalWrite(buzzPin, LOW);
  delay(dt1);
}
for (j=1; j<=100;j=j+1){
  digitalWrite(buzzPin, HIGH);
  delay(dt2);
  digitalWrite(buzzPin, LOW);
  delay(dt2);
}
}