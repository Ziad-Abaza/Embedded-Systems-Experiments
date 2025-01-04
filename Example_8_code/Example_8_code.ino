// تعريف منافذ توصيل اللمبة RGB LED
const int redPin = 11;   // منفذ اللون الأحمر
const int greenPin = 10; // منفذ اللون الأخضر
const int bluePin = 9;  // منفذ اللون الأزرق

// قيمة الإضاءة المخفضة للحماية (0-255)
const int brightness = 30; // يمكن تعديلها لتقليل الإضاءة أكثر

void setup() {
  // إعداد المنافذ كمخارج
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // بدء الاتصال التسلسلي مع البلوتوث
  Serial.begin(9600);
}

void loop() {
  // التحقق من استقبال البيانات
  if (Serial.available()) {
    char command = Serial.read(); // قراءة الحرف المرسل
    Serial.print("Received: ");
    Serial.println(command); 
    // التحكم في RGB LED بناءً على الحرف المرسل
    switch (command) {
      case 'O': // إطفاء
        setColor(0, 0, 0);
        break;
      case 'R': // اللون الأحمر
        setColor(brightness, 0, 0);
        break;
      case 'G': // اللون الأخضر
        setColor(0, brightness, 0);
        break;
      case 'B': // اللون الأزرق
        setColor(0, 0, brightness);
        break;
      default: 
        break;
    }
  }
}

// وظيفة لتغيير لون الـ RGB LED
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
