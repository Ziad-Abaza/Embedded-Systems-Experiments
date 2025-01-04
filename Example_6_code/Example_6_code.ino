#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "POCO";
const char* password = "12345777";
// const char* ssid = "realmi 6i";
// const char* password = "Marwan10";

// Static IP configuration
IPAddress local_IP(192, 168, 26, 202);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8); // Optional: Use Google's DNS
IPAddress secondaryDNS(8, 8, 4, 4); // Optional: Use Google's secondary DNS

// Define motor pins
const int IN1 = 33;
const int IN2 = 26;
const int ENA = 27; // PWM pin for speed control

// Create web server object
WebServer server(80);

// Motor speed (0-255)
int motorSpeed = 0;

// Serve the web app
void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>DC Motor Control</title>
      <style>
        body { font-family: Arial; text-align: center; margin: 50px; }
        button { font-size: 18px; padding: 10px 20px; margin: 10px; }
        input[type="range"] { width: 200px; margin: 20px; }
      </style>
    </head>
    <body>
      <h1>DC Motor Control</h1>
      <button onclick="sendRequest('forward')">Forward</button>
      <button onclick="sendRequest('reverse')">Reverse</button>
      <button onclick="sendRequest('stop')">Stop</button>
      <br>
      <label for="speed">Speed:</label>
      <input type="range" id="speed" min="0" max="255" oninput="updateSpeed(this.value)">
      <p>Speed: <span id="speedValue">0</span></p>
      <p>Stream: <span id="stream">http://192.168.26.205:81/stream</span></p>
      <img id="stream" src="http://192.168.26.205:81/stream" crossorigin="">
      <script>
        function sendRequest(action) {
          const speed = document.getElementById('speed').value;
          fetch(`/control?action=${action}&speed=${speed}`)
            .then(response => response.text())
            .then(data => console.log(data));
        }
        function updateSpeed(value) {
          document.getElementById('speedValue').innerText = value;
        }
      </script>
    </body>
    </html>
  )rawliteral";
  server.send(200, "text/html", html);
}

// Handle motor control commands
void handleControl() {
  String action = server.arg("action");
  int speed = server.arg("speed").toInt();
  motorSpeed = constrain(speed, 0, 255);

  if (action == "forward") {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, motorSpeed);
    server.send(200, "text/plain", "Motor moving forward.");
    Serial.println("forward");
    Serial.println(motorSpeed);
  } else if (action == "reverse") {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, motorSpeed);
    server.send(200, "text/plain", "Motor moving reverse.");
    Serial.println("reverse");
    Serial.println(motorSpeed);
  } else if (action == "stop") {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
    server.send(200, "text/plain", "Motor stopped.");
    Serial.println("stop");
  } else {
    server.send(400, "text/plain", "Invalid action.");
  }
}

// Setup function
void setup() {
  // Initialize motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Start with motor off

  // Start serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi with static IP
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("Static IP Configuration Failed!");
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define routes for web app
  server.on("/", handleRoot);
  server.on("/control", handleControl);

  // Start the server
  server.begin();
  Serial.println("Web server started.");
}

// Loop function
void loop() {
  server.handleClient();
}


