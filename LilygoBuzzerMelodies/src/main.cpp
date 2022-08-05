/*
ESP32-S2;Arduino;Platformio
We work with a piezo emitter. The code generates various melodies,
which are set by the number from the terminal. Active buzzer does 
not allow you to control of the tone, or pitch.

Работаем с пьезоизлучателем. Код генерирует различные мелодии,
которые задаются номером из терминала. Активный пьезоизлучатель 
не позволяет вам контролировать тон или высоту тона

Используемый модуль:
Подключение: Баззер - к - + через резистор 400 Ом к I00
*/

#include <Arduino.h>
#include "pitches.h"
#define BUZZER_PIN         0  // ESP32 pin IO0 connected to Buzzer's pin
 
 int melodyNum = 0;  // play melody number
 int repeatDelay = 1000;  // play melody number

// Melody 1
// The melody array (notes in the melody)
int melody1[] = {NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4};
// note durations: 4 = quarter note, 8 = eighth note, etc, also called tempo:
int NoteDurations1[] = {8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 16, 16, 8, 8, 8, 8, 4, 4};
 
// Melody 2: Melody Marry had a little lamb
int melody2[] = {NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4};
int NoteDurations2[]  = {2, 2, 2, 2, 2, 2, 4,2, 2, 2, 2, 2, 2, 4}; 

// Melody 3: Сирена

// Melody 4: Intro melody
int melody4[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int NoteDurations4[]  = {4, 8, 8, 4, 4, 4, 4, 4}; 

// Melody 5: Сирена 

// Melody 6: Star Wars Theme
int melody6[] = {f4, f4, f4, a4s, f5, d5s, d5, c5, a5s, f5, d5s, d5, c5, a5s, f5, d5s, d5, d5s, c5};
int NoteDurations6[]  = {21, 21, 21, 128, 128, 21, 21, 21, 128, 64, 21, 21, 21, 128, 64, 21, 21, 21, 128 }; 

// Melody 7: Star Wars Imperial March
int melody7[] = {  a4, R,  a4, R,  a4, R,  f4, R, c5, R,  a4, R,  f4, R, c5, R, a4, R,  e5, R,  e5, R,  e5, R,  f5, R, c5, R,  g5, R,  f5, R,  c5, R, a4, R};
int NoteDurations7[]  = {  50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5, 20, 5, 60, 80, 50, 20, 50, 20, 50, 20, 40, 5, 20, 5,  60, 10, 40, 5,  20, 5, 60, 40};
 
void setup() { 
  pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(115200); // Set serial out if we want debugging
  } 


void playMelody(int melodyNum) {
    if(melodyNum == 1){
      repeatDelay = 1000;
    // iterate over the notes of the melody:
      int size = sizeof(NoteDurations1) / sizeof(int);

      for (int thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / NoteDurations1[thisNote];
        tone(BUZZER_PIN, melody1[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZER_PIN);
      }
    }     
    if(melodyNum == 2){
      repeatDelay = 1000;
    // iterate over the notes of the melody:
      int size = sizeof(NoteDurations2) / sizeof(int);

      for (int thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / NoteDurations2[thisNote];
        tone(BUZZER_PIN, melody2[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZER_PIN);
      }
    }    
    if(melodyNum == 3){
      repeatDelay = 0;
    int duration = 1000/ 4;
        tone(BUZZER_PIN, 500, duration);
        
        delay(duration);
        // stop the tone
        noTone(BUZZER_PIN);
        tone(BUZZER_PIN, 1000, duration);
        // pause between notes
        
        delay(duration);
        // stop the tone
        noTone(BUZZER_PIN);
    }    
    if(melodyNum == 4){
      repeatDelay = 1000;
    // iterate over the notes of the melody:
      int size = sizeof(NoteDurations4) / sizeof(int);

      for (int thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / NoteDurations4[thisNote];
        tone(BUZZER_PIN, melody4[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZER_PIN);
      }
    }     
    if(melodyNum == 5){
      repeatDelay = 0;
      int dt1=1;
      int dt2=2;
      int j;

      for (j=1;j<=100;j=j+1){
        digitalWrite(BUZZER_PIN, HIGH);
        delay(dt1);
        digitalWrite(BUZZER_PIN, LOW);
        delay(dt1);
      }
      for (j=1; j<=100;j=j+1){
        digitalWrite(BUZZER_PIN, HIGH);
        delay(dt2);
        digitalWrite(BUZZER_PIN, LOW);
        delay(dt2);
      }
    }   
    if(melodyNum == 6){
      repeatDelay = 1000;
    // iterate over the notes of the melody:
      int size = sizeof(NoteDurations6) / sizeof(int);

      for (int thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / NoteDurations6[thisNote];
        tone(BUZZER_PIN, melody6[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZER_PIN);
      }
    }
    if(melodyNum == 7){
      repeatDelay = 1000;
    // iterate over the notes of the melody:
      int size = sizeof(NoteDurations7) / sizeof(int);

      for (int thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / NoteDurations7[thisNote];
        tone(BUZZER_PIN, melody7[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(BUZZER_PIN);
      }
    }                                  
}
 
// LOOP //
void loop() {  if (Serial.available()) // Check to see if at least one character is available
  {
    char ch = (char) Serial.read();
    if( isDigit(ch) ) // is this an ascii digit between 0 and 9?
    {
      melodyNum = (ch - '0');       // ASCII value converted to numeric value

    }
  }
        playMelody(melodyNum);
        delay(repeatDelay);
}