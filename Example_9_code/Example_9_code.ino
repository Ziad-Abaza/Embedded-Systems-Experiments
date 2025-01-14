#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int Gas = 7;
int redLed = 3;
int greenLed = 4;
int buzzer = 5;
// Initialize the LCD (set the I2C address and size, e.g., 0x27,0*32 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on the backlight
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.print("Gas sensor MQ135 ");
  lcd.setCursor(0,1);
  lcd.print("DESIGN BY SARATH");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("SENSING REPORT..");
  pinMode(Gas , INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() {
    if(digitalRead(Gas) == HIGH){
      lcd.setCursor(0,1);
      lcd.print("Gas is detected ");
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(buzzer, HIGH);
}

   if(digitalRead(Gas) == LOW){
    lcd.setCursor(0,1);
    lcd.print("Gas Not detected");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, LOW);}
}


 