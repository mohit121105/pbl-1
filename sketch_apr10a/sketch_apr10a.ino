#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  delay(2000); // Give some time to boot

  // Clear the buffer
  display.clearDisplay();

  // Set text settings
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner

  // Print text
  display.println("Hello, ESP32 + OLED!");
  display.display();                  // Show the text
}

void loop() {
  // Nothing here for now
}
