#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the I2C LCD (address 0x27 or 0x3F, adjust if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int soilSensorPin = A0;  // Soil moisture sensor pin
const int relayPin = 8;        // Relay control pin

// Threshold for soil moisture (adjust based on your sensor)
const int moistureThreshold = 500;

// Variables
int soilMoistureValue = 0;

void setup() {
  // Initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Plant Watering");
  delay(2000);

  // Initialize pins
  pinMode(soilSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Turn off pump initially (relay HIGH)

  // Start serial communication
  Serial.begin(9600);
  Serial.println("Automated Plant Watering System");
}

void loop() {
  // Read soil moisture value
  soilMoistureValue = analogRead(soilSensorPin);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // Display soil moisture level on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(soilMoistureValue);

  // Check moisture level
  if (soilMoistureValue < moistureThreshold) {
    // Soil is dry, water the plant
    lcd.setCursor(0, 1);
    lcd.print("Status: Watering");
    digitalWrite(relayPin, LOW); // Turn on the pump (relay LOW)
    Serial.println("Pump ON: Watering plant...");
  } else {
    // Soil is moist, no watering needed
    lcd.setCursor(0, 1);
    lcd.print("Status: OK");
    digitalWrite(relayPin, HIGH); // Turn off the pump (relay HIGH)
    Serial.println("Pump OFF: Soil is moist.");
  }

  // Delay for stability
  delay(2000);
}
