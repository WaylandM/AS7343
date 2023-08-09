/* This example will read all channels from the AS7341 and print out reported values */

#include "AMS_OSRAM_AS7343.h"


AMS_OSRAM_AS7343 as7343;


void setup() {
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }
  
  if (!as7343.begin()){
    Serial.println("Could not find AS7343");
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
  Serial.print("F1 405nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_405_F1));
  Serial.print("F2 425nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_425_F2));
  Serial.print("FZ 450nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_450_FZ));
  Serial.print("F3 475nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_475_F3));
  Serial.print("F4 515nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_515_F4));
  Serial.print("F5 550nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_550_F5));
  Serial.print("FY 555nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_555_FY));
  Serial.print("FXL 600nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_600_FXL));
  Serial.print("F6 640nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_640_F6));
  Serial.print("F7 690nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_690_F7));
  Serial.print("F8 745nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_745_F8));
  Serial.print("NIR 855nm : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_855_NIR));
  Serial.print("Clear : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_CLEAR));
  Serial.print("Clear 0 : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_CLEAR_0));
  Serial.print("Clear 1 : ");
  Serial.println(as7343.getChannel(AS7343_CHANNEL_CLEAR_1));

  Serial.println("");
}


//  AS7343_CHANNEL_FD_1,
//  AS7343_CHANNEL_FD_0,
//  AS7343_CHANNEL_FD,
