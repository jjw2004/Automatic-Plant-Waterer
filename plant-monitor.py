const int ledPinGreen = 12;
const int ledPinBlue = 13;
const int ledPinRed = 14;
const int soil_moisture_pin = 15;

void setup() {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  int moisture = analogRead(soil_moisture_pin);

  // Convert reading to percentage
  int moisturePercent = map(moisture, 0, 4095, 0, 100);

  moisturePercent = constrain(moisturePercent, 0, 100);

  /*
  Serial.print("Raw Value: ");
  Serial.print(moisture);
  Serial.print(" Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");
  */

  // Turn all LEDs off first
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinBlue, LOW);


  if (moisturePercent < 40) {
    // Dry soil
    digitalWrite(ledPinRed, HIGH);

  } else if (moisturePercent < 80) {
    // Good moisture
    digitalWrite(ledPinGreen, HIGH);

  } else {
    // Very wet soil
    digitalWrite(ledPinBlue, HIGH);
  }


  delay(500);
}