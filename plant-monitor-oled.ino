#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SOIL_PIN 34
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {

  // Read soil moisture sensor
  int moisture = analogRead(SOIL_PIN);

  // Convert to percentage
  int moisturePercent = map(moisture, 4095, 1300, 0, 100); //changed as when testing the soil moisture this is around the max value it when fully submerged can give back not sure why
  moisturePercent = constrain(moisturePercent, 0, 100);

  // Print to Serial
  Serial.print("Raw Value: ");
  Serial.print(moisture);
  Serial.print("  Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Update OLED
  display.clearDisplay();
  display.setCursor(0, 0);

  if (moisturePercent < 30) {
    display.println("DRY!");
  }
  else if (moisturePercent < 70) {
    display.println("GOOD");
  }
  else {
    display.println("WET");
  }

  display.print(moisturePercent);
  display.println("%");

  display.display();

  delay(2000);
}