/* This example will read all channels from the AS7343 and print out reported values */

// include the library file from this github (instead of the)
#include "AMS_OSRAM_AS7343.h"

// Define the spectrometer Type
AMS_OSRAM_AS7343 as7343;


void setup() {
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }
  
  if (!as7343.begin()) {
    Serial.println("Could not find AS7343");
    while (1) { delay(10); }
  }

  as7343.setATIME(100);
  as7343.setASTEP(999);1
  as7343.setGain(AS7343_GAIN_256X);
}

void loop() {
    uint16_t readings[12];

  if (!as7343.readAllChannels(readings)) {
    Serial.println("Error reading all channels!");
    return;
  }

  Serial.print("ADC0/F1 415nm : ");
  Serial.println(readings[0]);
  Serial.print("ADC1/F2 445nm : ");
  Serial.println(readings[1]);
  Serial.print("ADC2/F3 480nm : ");
  Serial.println(readings[2]);
  Serial.print("ADC3/F4 515nm : ");
  Serial.println(readings[3]);
  Serial.print("ADC0/F5 555nm : ");

  /* 
  // we skip the first set of duplicate clear/NIR readings
  Serial.print("ADC4/Clear-");
  Serial.println(readings[4]);
  Serial.print("ADC5/NIR-");
  Serial.println(readings[5]);
  */
 
  Serial.println(readings[6]);
  Serial.print("ADC1/F6 590nm : ");
  Serial.println(readings[7]);
  Serial.print("ADC2/F7 630nm : ");
  Serial.println(readings[8]);
  Serial.print("ADC3/F8 680nm : ");
  Serial.println(readings[9]);
  Serial.print("ADC4/Clear    : ");
  Serial.println(readings[10]);
  Serial.print("ADC5/NIR      : ");
  Serial.println(readings[11]);

  Serial.println("-----------------------");
}
