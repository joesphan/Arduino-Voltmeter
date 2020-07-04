extern float ch1Value;
extern float ch2Value;
#include <stdlib.h>
void initDisplayGFX() {
  ssd1306_128x64_i2c_init();
  ssd1306_clearScreen();
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  ssd1306_printFixedN(0, 0, " ", STYLE_NORMAL, FONT_SIZE_NORMAL);
  ssd1306_printFixedN(0, 16, "CH1:", STYLE_NORMAL, FONT_SIZE_NORMAL);
  ssd1306_printFixedN(0, 48, "CH2:", STYLE_NORMAL, FONT_SIZE_NORMAL);
  ssd1306_printFixedN (112, 16, "V", STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (112, 48, "V", STYLE_NORMAL, FONT_SIZE_2X);
}
void updateDisplay(void) {
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  //ch2Value = ch2Value * 10;   //debug test
  //ch1Value = ch1Value * 10;   //debug test
  char ch1Converted[8];
  char ch2Converted[8];
  dtostrf(ch1Value, 7, 4, ch1Converted);
  dtostrf(ch2Value, 7, 4, ch2Converted);
  ssd1306_printFixedN (24, 16, ch1Converted, STYLE_NORMAL, FONT_SIZE_2X);
  ssd1306_printFixedN (24, 48, ch2Converted, STYLE_NORMAL, FONT_SIZE_2X);
  /*
  Serial.print("ch1: ");
  Serial.print(ch1Converted);
  Serial.print(" ch2: ");
  Serial.print(ch2Converted);
  Serial.println(" ");
  */
}
