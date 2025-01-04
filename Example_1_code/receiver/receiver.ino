#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "realmi 6i";
const char* password = "Marwan10";

// Static IP configuration
IPAddress local_IP(192, 168, 1, 200); // عنوان IP الثابت للـ Slave ESP32
IPAddress gateway(192, 168, 1, 1);    // بوابة الشبكة
IPAddress subnet(255, 255, 255, 0);   // قناع الشبكة

// Motor control pins connected to L298N
const int in1Pin = 33;  // IN1 on L298N
const int in2Pin = 32;  // IN2 on L298N

// Create a web server object
WebServer server(80);

void setup() {
  // Set motor control pins as outputs
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  digitalWrite(in1Pin, LOW);  // Ensure motor is off initially
  digitalWrite(in2Pin, LOW);  // Ensure motor is off initially

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
  Serial.print("Slave ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Define route to start the motor (forward direction)
  server.on("/start_motor", []() {
    digitalWrite(in1Pin, HIGH);  // Set IN1 to HIGH
    digitalWrite(in2Pin, LOW);   // Set IN2 to LOW (for forward direction)
    delay(1000);
    digitalWrite(in1Pin, LOW);
    Serial.println("Motor started (Forward direction)!");
    server.send(200, "text/plain", "Motor started successfully (Forward direction)!");
  });

  // server.on("/stop_motor", []() {
  //   digitalWrite(in1Pin, LOW);  // Set both IN1 and IN2 to LOW to stop the motor
  //   digitalWrite(in2Pin, LOW);
  //   delay(200); // Optional delay for stabilization
  //   Serial.println("Motor stopped!");
  //   server.send(200, "text/plain", "Motor stopped successfully!");
  // });



  // Handle undefined routes
  server.onNotFound([]() {
    server.send(404, "text/plain", "404: Not Found");
  });

  // Start the server
  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  // Handle incoming HTTP requests
  server.handleClient();
}
