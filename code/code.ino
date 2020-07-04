/*
 * Arduino Voltmeter
 * Joesphan Lu
 * https://github.com/joesphan/Arduino-Voltmeter
 * Licensed under the Non-Profit Open Software License version 3.0
 */
#include <ssd1306.h>

void setup() {
  Serial.begin(9600);
  analogPinsInit();
  digipotInit();
  initDisplayGFX();

}

void loop() {
  // put your main code here, to run repeatedly:
  takeMeasurement();
  if (Serial.available()) {
    sendDebugMeasurement();
  }
  updateDisplay();
  delay(200);
}
