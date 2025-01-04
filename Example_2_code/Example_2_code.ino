#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address 0x27 if needed

// Pin Definitions
const int gasSensorPin = A0; // Analog pin for the gas sensor
const int motorIn1 = 9; // Motor Driver IN1
const int motorIn2 = 10; // Motor Driver IN2
const int motorEnable = 5; // Motor Driver ENA (PWM control)

// Threshold for gas concentration (adjust as necessary)
const int gasThreshold = 250; 

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Gas Monitoring");

  // Motor control pins
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorEnable, OUTPUT);

  // Motor off at startup
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  analogWrite(motorEnable, 0);
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(gasSensorPin);

  // Display gas value on LCD
  lcd.setCursor(0, 1);
  lcd.print("Gas: ");
  lcd.print(gasValue);
  lcd.print("    "); // Clear extra digits

  // Print to Serial Monitor
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Control fan based on gas value
  if (gasValue > gasThreshold) {
    lcd.setCursor(12, 1);
    lcd.print("Fan ON ");
    
    // Activate motor (fan)
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    analogWrite(motorEnable, 200); // Adjust speed (0-255)
  } else {
    lcd.setCursor(12, 1);
    lcd.print("Fan OFF");

    // Deactivate motor (fan)
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
    analogWrite(motorEnable, 0);
  }

  delay(500); // Delay for stable reading
}