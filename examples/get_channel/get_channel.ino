/* This example will read all channels from the AS7341 and print out reported values */

#include "AMS_OSRAM_AS7343.h"

AMS_OSRAM_AS7343 as7343;


void setup() {
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }
  
  if (!as7341.begin()){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }

  as7343.setATIME(100);
  as7343.setASTEP(999);
  as7343.setGain(AS7343_GAIN_256X);
}

void loop() {
  // Read all channels at the same time and store in as7343 object
  if (!as7343.readAllChannels()){
    Serial.println("Error reading all channels!");
    return;
  }

  // Print out the stored values for each channel
  Serial.print("F1 415nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_415nm_F1));
  Serial.print("F2 445nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_445nm_F2));
  Serial.print("F3 480nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_480nm_F3));
  Serial.print("F4 515nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_515nm_F4));
  Serial.print("F5 555nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_555nm_F5));
  Serial.print("F6 590nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_590nm_F6));
  Serial.print("F7 630nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_630nm_F7));
  Serial.print("F8 680nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_680nm_F8));

  Serial.print("Clear    : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_CLEAR));

  Serial.print("Near IR  : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_NIR));

  Serial.println("");
}
