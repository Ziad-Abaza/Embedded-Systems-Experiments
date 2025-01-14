#include <Wire.h>                  // مكتبة للتواصل عبر I2C
#include <LiquidCrystal_I2C.h>     // مكتبة للشاشات I2C LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);  // تعريف شاشة I2C بعنوانها (يمكن تغييره حسب العنوان الخاص بك)

// تعريف أطراف حسّاس Ultrasonic
const int trigPin = 7;
const int echoPin = 8;

// تعريف البازر
const int buzzerPin = 9;

void setup() {
  // تهيئة الشاشة
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  // تهيئة الحساس والبازر
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // بدء الاتصال التسلسلي (اختياري)
  Serial.begin(9600);
}

void loop() {
  // إرسال نبضة من الحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // حساب الوقت الذي استغرقته النبضة للعودة
  long duration = pulseIn(echoPin, HIGH);

  // حساب المسافة (سم)
  float distance = (duration * 0.034) / 2;

  // طباعة المسافة على الشاشة
  lcd.setCursor(10, 0);
  lcd.print("    ");  // مسح القيمة القديمة
  lcd.setCursor(10, 0);
  lcd.print(distance);
  lcd.print("cm");

  // تشغيل الجرس إذا كانت المسافة أقل من 10 سم
  if (distance < 10.0) {
    digitalWrite(buzzerPin, HIGH);  // تشغيل الجرس
  } else {
    digitalWrite(buzzerPin, LOW);   // إيقاف الجرس
  }

  // عرض القيمة في Serial Monitor (اختياري)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}