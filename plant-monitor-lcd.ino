#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SOIL_PIN 34

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {

  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Plant Monitor");

  delay(2000);
}


void loop() {

  int moisture = analogRead(SOIL_PIN);

  int moisturePercent = map(moisture, 4095, 1300, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);


  Serial.print("Raw: ");
  Serial.print(moisture);
  Serial.print(" Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");


  lcd.setCursor(0,0);
  lcd.print("                ");

  lcd.setCursor(0,1);
  lcd.print("                ");


  lcd.setCursor(0,0);

  if (moisturePercent < 30) {
    lcd.print("SOIL: DRY");
  }
  else if (moisturePercent < 70) {
    lcd.print("SOIL: GOOD");
  }
  else {
    lcd.print("SOIL: WET");
  }


  lcd.setCursor(0,1);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%");


  delay(1000);
}