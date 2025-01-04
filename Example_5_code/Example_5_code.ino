#include <ESP32Servo.h>

// Define pins
const int joystickXPin = 34; // Analog pin for joystick X-axis
const int servoPin = 14;     // PWM pin for servo motor

// Servo object
Servo myServo;

// Variables to store joystick values and servo angle
int joystickValue = 0;
int servoAngle = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Attach servo to the specified pin
  myServo.attach(servoPin);
}

void loop() {
  // Read the joystick's X-axis value (0-4095 for ESP32 ADC)
  joystickValue = analogRead(joystickXPin);

  if (joystickValue > 3200  || joystickValue < 2700) {
myServo.attach(servoPin);

// Map joystick value (0-4095) to servo angle (0-180)
  servoAngle = map(joystickValue, 0, 4095, 0, 180);
  // Move servo to the mapped angle
  myServo.write(servoAngle);

  } else {

  myServo.detach();
  }


  
  // Print values for debugging
  Serial.print("Joystick Value: ");
  Serial.print(joystickValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(servoAngle);

  // Small delay to stabilize readings
  delay(20);
}
