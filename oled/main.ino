#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR   0x3C
#define SCROLL_DELAY 500
#define SCROLL_OFFSET 1

Adafruit_SSD1306 display(-1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Hello, Make Skilled!");
  display.display();
  delay(2000);  // Wait 2 seconds before scrolling
}

void scrollTextLeft() {
  for (int16_t x = 0; x >= -display.width(); x--) {
    display.clearDisplay();
    display.setCursor(x, 0);
    display.println("Hello, Make Skilled!");
    display.display();
    delay(SCROLL_DELAY);
  }
}

void scrollTextRight() {
  for (int16_t x = -display.width(); x <= 0; x++) {
    display.clearDisplay();
    display.setCursor(x, 0);
    display.println("Hello, Make Skilled!");
    display.display();
    delay(SCROLL_DELAY);
  }
}

void loop() {
  scrollTextLeft();
  delay(2000);  // Delay before scrolling right
  scrollTextRight();
  delay(2000);  // Delay before scrolling left again
}
