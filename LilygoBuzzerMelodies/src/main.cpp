/*
ESP32-S2;Arduino;Platformio
Plays a melody

Играет мелодию

by Tom Igoe
This example code is in the public domain.
https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody

Используемый модуль:
Подключение: Баззер - к - + через резистор 400 Ом к I00
*/

#include "pitches.h"
#include <Arduino.h>

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int buzzPin=0;

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzPin);
  }
}

void loop() {
  // no need to repeat the melody.
}