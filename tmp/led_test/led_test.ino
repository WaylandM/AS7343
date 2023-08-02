/* This example will set the onboard LED current to various values and blink
   the LED */

#include "AMS_OSRAM_AS7343.h"

AMS_OSRAM_AS7343 as7343;


void setup() {
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }

  if (!as7343.begin()){
    Serial.println("Could not find as7343");
    while (1) { delay(10); }
  }
}

void loop() {
  Serial.println("4 mA LED blink");
  as7343.setLEDCurrent(4); // 4mA
  as7343.enableLED(true);
  delay(100);
  as7343.enableLED(false);
  delay(500);

  Serial.println("100 mA LED blink");
  as7343.setLEDCurrent(100); // 100mA
  as7343.enableLED(true);
  delay(100);
  as7343.enableLED(false);
  delay(500);
}
