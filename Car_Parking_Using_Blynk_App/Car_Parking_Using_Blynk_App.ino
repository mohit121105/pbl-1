#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height

// Create display object (I2C address 0x3C for many OLEDs)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SENSOR1 32
#define SENSOR2 33
#define SENSOR3 25
#define SENSOR4 26

BlynkTimer timer;

char auth[] = "fpEkw9yaQ0CiT5XIitpR_vhq_0_EPaKc";
char ssid[] = "bhavesh’s iPhone";
char pass[] = "12345678";

WidgetLED LED1(V0);
WidgetLED LED2(V1);
WidgetLED LED3(V2);
WidgetLED LED4(V4);

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println("  Welcome To");
  display.setCursor(0, 30);
  display.println("JustDoElectronic");
  display.display();
  delay(2000);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  pinMode(SENSOR1, INPUT_PULLUP);
  pinMode(SENSOR2, INPUT_PULLUP);
  pinMode(SENSOR3, INPUT_PULLUP);
  pinMode(SENSOR4, INPUT_PULLUP);
}

void sensor() {
  int L1 = digitalRead(SENSOR1);
  int L2 = digitalRead(SENSOR2);
  int L3 = digitalRead(SENSOR3);
  int L4 = digitalRead(SENSOR4);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Sensor 1
  if (L1 == 1) {
    Serial.println(" IR Sensor 1 detected");
    display.setCursor(0, 0);
    display.println("1: Full");
    LED1.on();
  } else {
    Serial.println(" 1 === All clear");
    display.setCursor(0, 0);
    display.println("1: Empty");
    LED1.off();
  }

  // Sensor 2
  if (L2 == 1) {
    Serial.println(" IR Sensor 2 detected");
    display.setCursor(64, 0);
    display.println("2: Full");
    LED2.on();
  } else {
    Serial.println(" 2 === All clear");
    display.setCursor(64, 0);
    display.println("2: Empty");
    LED2.off();
  }

  // Sensor 3
  if (L3 == 1) {
    Serial.println(" IR Sensor 3 detected");
    display.setCursor(0, 20);
    display.println("3: Full");
    LED3.on();
  } else {
    Serial.println(" 3 === All clear");
    display.setCursor(0, 20);
    display.println("3: Empty");
    LED3.off();
  }

  // Sensor 4
  if (L4 == 1) {
    Serial.println(" IR Sensor 4 detected");
    display.setCursor(64, 20);
    display.println("4: Full");
    LED4.on();
  } else {
    Serial.println(" 4 === All clear");
    display.setCursor(64, 20);
    display.println("4: Empty");
    LED4.off();
  }

  display.display();
}

void loop() {
  sensor();
  Blynk.run();
  delay(200);
}
