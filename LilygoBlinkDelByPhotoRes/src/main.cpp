/*
ESP32-S2; Arduino; Platformio
Управление частотой мигания светодиодом, с помощью светодиода вместо 
фоторезистора с масштабированной частотой мигания, фильтрацией шумов и 
выводом в монитор порта
Controlling the blink frequency of the LED, using a LED diode instead 
photoresistor with scaled blink rate, noise filtering and port monitor output

Connections:
Sensor LED connected to GND and IO3
Indicator LED connected to IO1-1kOm Resistor-GND

Experiment results:
0-Bright light 6373-Dark
In the dark 896 - 2213
Bright light then Dark 0 - 6373
*/

#include <Arduino.h>

#define FILTER_LEN  30 //Number of probes for ADC Noise Reduction filter
#define LED1 1				 // LED connected to digital pin 1

const int sensorPin = A3;    // Connect sensor to Analog input 3

// Low and high values for the sensor readings. You may need to adjust these for scaling
/*const int low  = 200;
const int high = 800;*/
const int low  = 500;
const int high = 1500;

int delayval = 0;
int delayval_Filtered = 0;

uint32_t AN_Pot1_Buffer[FILTER_LEN] = {0}; //Probes array for ADC Noise Reduction filter
int AN_Pot1_i = 0;

// the next two lines set the min and max delay between blinks
const int minDuration = 200;  // minimum wait between blinks
const int maxDuration = 1000; // maximum wait between blinks


void setup()
{
  pinMode(LED1, OUTPUT);  // enable output on the led pin
    Serial.begin(9600);   // initialize Serial
}

//ADC Noise Reduction By Multi-Sampling & Moving Average Digital Filtering
uint32_t readADC_Avg(int ADC_Raw)
{
  int i = 0;
  uint32_t Sum = 0;
  
  AN_Pot1_Buffer[AN_Pot1_i++] = ADC_Raw;
  if(AN_Pot1_i == FILTER_LEN)
  {
    AN_Pot1_i = 0;
  }
  for(i=0; i<FILTER_LEN; i++)
  {
    Sum += AN_Pot1_Buffer[i];
  }
  return (Sum/FILTER_LEN);
}

//ADC Scaling. Scales the delay value between the min and max values
uint32_t readADC_Scal(int ADC_Raw)
{
  uint32_t Scal = 0;
  Scal = map(ADC_Raw, low, high, minDuration, maxDuration);
  Scal = constrain(Scal, minDuration, maxDuration);
  return (Scal);
}

//ADC Scaling. Scales the value between the min and max values
uint32_t readADC_ScalVal(int ADC_Raw)
{
  uint32_t Scal = 0;
  Scal = ADC_Raw;
  Scal = constrain(Scal, low, high);
  return (Scal);
}

//ADC Scaling. Scales the delay value between the 0 and 100%
uint32_t readADC_ScalPrcnt(int ADC_Raw)
{
  uint32_t Scal = 0;
  Scal = map(ADC_Raw, low, high, 100, 0);
  Scal = constrain(Scal, 0, 100);
  return (Scal);
}

//Get Delay
uint32_t getDelay(int ADC_Raw)
{
  uint32_t Scal = 0;
  Scal = map(ADC_Raw, 0, 100, 100, 5);
  Scal = constrain(Scal, 5, 100);
  Scal = Scal * 10;
  return (Scal);
}

void loop()
{

  
  int delayval = analogRead(sensorPin);    // read the analog input
  
  int delayval_Filtered = readADC_Avg(delayval);    //ADC Noise Reduction By Multi-Sampling & Moving Average Digital Filtering
  int delayval_Scaled = readADC_Scal(delayval);     //ADC Scaling. Scales the delay value between the min and max values
  int val_Scal = readADC_ScalVal(delayval_Filtered);    //ADC Scaling. Scales the value between the min and max values
  int delayval_SAndF = readADC_Scal(delayval_Filtered);   //ADC Scaling. Scales the delay value between the min and max values
  int delayval_SAndFPrcnt = readADC_ScalPrcnt(val_Scal);    //ADC Scaling. Scales the delay value between the 0 and 100%
  int del = getDelay(delayval_SAndFPrcnt);    //Get Delay

  Serial.print("AnalogValue:");
  Serial.print(delayval);

  Serial.print(" FilteredValue:");
  Serial.print(delayval_Filtered);

  Serial.print(" ScaledValue:");
  Serial.print(delayval_Scaled);

  Serial.print(" FilteredandScaledValue:");
  Serial.print(delayval_SAndF);
  
  Serial.print(" LightPercent:");
  Serial.println(delayval_SAndFPrcnt);

  digitalWrite(LED1, HIGH); // set the LED on
  delay(del);    // delay is dependent on light level
  digitalWrite(LED1, LOW);  // set the LED off
  delay(del);
}

