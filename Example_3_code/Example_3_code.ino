#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10
#define RELAY_PIN 7

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte validUID[] = {0x12, 0x34, 0x56, 0x78};

void setup() {
  Serial.begin(9600);

  lcd.init(); // Corrected from lcd.begin()
  lcd.backlight();

  SPI.begin();
  rfid.PCD_Init();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("RFID Door Lock");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  lcd.clear(); // Clear before showing Scanning message
  lcd.setCursor(0, 0);
  lcd.print("Scanning...");

  if (isValidUID(rfid.uid.uidByte, rfid.uid.size)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    unlockDoor();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
    delay(2000);
  }

  rfid.PICC_HaltA();
  delay(500);
}

bool isValidUID(byte *uid, byte length) {
  if (length != sizeof(validUID)) {
    return false;
  }
  for (byte i = 0; i < length; i++) {
    if (uid[i] != validUID[i]) {
      return false;
    }
  }
  return true;
}

void unlockDoor() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(5000);
  digitalWrite(RELAY_PIN, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Door Locked");
  delay(2000);
}