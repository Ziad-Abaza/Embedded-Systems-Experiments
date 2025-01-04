#include "Servo.h"
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Servo object
Servo myservo;

// LCD setup: I2C address 0x27 and dimensions 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define ROW_NUM 4     // Four rows
#define COLUMN_NUM 4  // Four columns
const int SERVO_PIN = 10; // Servo pin

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; // Keypad row pins
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; // Keypad column pins

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

const String passwords[] = {"332211", "5080", "9765"};
String input_password = "";

unsigned long lastTime = 0;
bool servoActive = false;

void setup() {
  Serial.begin(9600);
  input_password.reserve(32); // Reserve memory for input password

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();

  // Servo setup
  myservo.attach(SERVO_PIN);
  myservo.write(90); // Stop the servo initially
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '*') {
      input_password = ""; // Reset the input password
      lcd.clear();
      lcd.print("Password Reset");
    } else if (key == '#') {
      if (isPasswordCorrect(input_password)) {
        Serial.println("Correct password, activating servo.");
        lcd.clear();
        lcd.print("Access Granted");
        myservo.write(45); // Rotate the servo
        lastTime = millis();
        servoActive = true;
      } else {
        Serial.println("Incorrect password, try again.");
        lcd.clear();
        lcd.print("Access Denied");
        delay(2000); // Display the message for 2 seconds
        lcd.clear();
        lcd.print("Enter Password:");
      }
      input_password = ""; // Reset the input password
    } else {
      input_password += key; // Add key to the password
      lcd.clear();
      lcd.print("Input: ");
      lcd.print(input_password); // Show current input
    }
  }

  // Automatically stop the servo after 5 seconds
  if (servoActive && (millis() - lastTime > 5000)) {
    myservo.write(90); // Stop the servo
    servoActive = false;
    lcd.clear();
    lcd.print("Servo Stopped");
    delay(2000); // Display the message for 2 seconds
    lcd.clear();
    lcd.print("Enter Password:");
  }
}

// Function to validate the input password
bool isPasswordCorrect(const String &input) {
  for (const String &password : passwords) {
    if (input == password) {
      return true;
    }
  }
  return false;
}
