#include <WiFi.h>
#include <HTTPClient.h>

// WiFi credentials
const char* ssid = "realmi 6i";
const char* password = "Marwan10";

// Static IP configuration
IPAddress local_IP(192, 168, 1, 150); // عنوان IP الثابت للـ Master ESP32
IPAddress gateway(192, 168, 1, 1);    // بوابة الشبكة
IPAddress subnet(255, 255, 255, 0);   // قناع الشبكة

// PIR sensor pin
const int motionPin = 12;

// Variable to store the previous motion state
int prevMotionState = LOW;

void setup() {
  pinMode(motionPin, INPUT);
  Serial.begin(115200);

  // Configure static IP
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  Serial.print("Master ESP32 IP Address: ");
  Serial.println(WiFi.localIP()); // عرض عنوان IP للـ Master ESP32
}

void loop() {
  int motionState = digitalRead(motionPin);

  // Send HTTP request only if the state has changed
  if (motionState != prevMotionState) {
    HTTPClient http;

    if (motionState == HIGH) {  // Motion detected
      Serial.println("Motion detected! Sending '1' to Slave...");
      http.begin("http://192.168.1.200/start_motor");  // IP الثابت للـ Slave
    }

    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.printf("HTTP request sent successfully: %d\n", httpCode);
    } else {
      Serial.println("Failed to send request.");
    }

    http.end();

    // Update the previous motion state
    prevMotionState = motionState;

    // Add delay to avoid continuous triggering
    delay(5000);
  }
}
