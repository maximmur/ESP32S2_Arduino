/*
ESP32-S2;Arduino;Platformio
Определяем размер и тип подключенной SD карты
Determine the size and type of the connected SD card

Используемый модуль: HW-203
Подключение:  * #define SCK  IO36 (fspiclk)
              * #define MISO Io37 (fspiq)
              * #define MOSI IO35 (fspid)
              * #define CS   IO34 (fspics0)
              * GND
              * 3.3V
Пример вывода:
 */
#include <Arduino.h>
#include "SD.h"


void initSDCard(){
  if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}


void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
  initSDCard();
}

void loop() {
  // put your main code here, to run repeatedly:
}