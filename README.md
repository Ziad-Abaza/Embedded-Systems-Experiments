# Embedded Systems Experiments

This repository contains 10 hands-on experiments designed for first-year Information Technology students to introduce them to the world of embedded systems. The experiments leverage components like ESP32, ESP32-CAM, and Arduino to perform various tasks such as motor control, smart irrigation, door locks, and more.

These projects are intended to provide a solid foundation in working with sensors and controllers, as well as integrating them into practical applications.

## Table of Contents

1. [Experiment 1: DC Motor Control with Motion Sensor through ESP32](#experiment-1-dc-motor-control-with-motion-sensor-through-esp32)
2. [Experiment 2: Fan Control with DHT22 Sensor and OLED Display](#experiment-2-fan-control-with-dht22-sensor-and-oled-display)
3. [Experiment 3: Door Lock Control with RFID](#experiment-3-door-lock-control-with-rfid)
4. [Experiment 4: Water Level Measurement with Ultrasonic Sensor](#experiment-4-water-level-measurement-with-ultrasonic-sensor)
5. [Experiment 5: Servo Motor Control with ESP32 and Joystick](#experiment-5-servo-motor-control-with-esp32-and-joystick)
6. [Experiment 6: ESP32-CAM Live Stream with Mobile DC Motor Control](#experiment-6-esp32-cam-live-stream-with-mobile-dc-motor-control)
7. [Experiment 7: Smart Irrigation System](#experiment-7-smart-irrigation-system)
8. [Experiment 8: RGB LED Control with Bluetooth Module](#experiment-8-rgb-led-control-with-bluetooth-module)
9. [Experiment 9: Smoke and Gas Detection](#experiment-9-smoke-and-gas-detection)
10. [Experiment 10: Servo Motor Control by Keypad](#experiment-10-servo-motor-control-by-keypad)

## List of Experiments

### Experiment 1: DC Motor Control with Motion Sensor through ESP32
- **Components**: 2x ESP32, Motion Sensor, DC Motor, L298N Motor Driver
- **Description**: Control a DC motor using two ESP32s and a motion sensor, one ESP32 detects motion, while the other controls the motor through Wi-Fi.

### Experiment 2: Fan Control with DHT22 Sensor and OLED Display
- **Components**: Arduino, DHT22 Sensor, OLED Display, Relay
- **Description**: Control a fan based on temperature and humidity using an Arduino and DHT22 sensor, displaying real-time data on an OLED screen.

### Experiment 3: Door Lock Control with RFID
- **Components**: Arduino, RFID Module, Solenoid Door Lock, LCD Display, Relay
- **Description**: Implement a secure door lock system using RFID and Arduino, unlocking the door upon detecting a valid RFID tag.

### Experiment 4: Water Level Measurement with Ultrasonic Sensor
- **Components**: Arduino, Ultrasonic Sensor, OLED Display, Buzzer
- **Description**: Measure water levels in a tank and activate a buzzer if the water level exceeds a set threshold.

### Experiment 5: Servo Motor Control with ESP32 and Joystick
- **Components**: ESP32, Joystick, Servo Motor
- **Description**: Control the position of a servo motor using an ESP32 and a joystick, with the joystick sending analog signals.

### Experiment 6: ESP32-CAM Live Stream with Mobile DC Motor Control
- **Components**: ESP32-CAM, ESP32-CAM Programmer, DC Motor, Motor Driver
- **Description**: Stream live video from an ESP32-CAM to a mobile device and control a DC motor via a web app.

### Experiment 7: Smart Irrigation System
- **Components**: Arduino, Soil Moisture Sensor, OLED Display, Water Pump, Relay
- **Description**: Automate irrigation by monitoring soil moisture and activating a water pump using an Arduino-based system.

### Experiment 8: RGB LED Control with Bluetooth Module
- **Components**: Arduino Uno, Bluetooth Module (HC-05 or HC-06), RGB LED
- **Description**: Control the color of an RGB LED via Bluetooth using a mobile app.

### Experiment 9: Smoke and Gas Detection
- **Components**: Arduino, MQ135 Gas Sensor, LCD Display
- **Description**: Detect smoke and gases with an MQ135 sensor, displaying real-time gas levels on an LCD.

### Experiment 10: Servo Motor Control by Keypad
- **Components**: Arduino Uno, 4x4 Keypad, OLED Display, Servo Motor
- **Description**: Control a servo motor with a 4x4 keypad by entering the desired angle, displayed on an OLED screen.

## Prerequisites

- Basic knowledge of embedded systems.
- Familiarity with Arduino/ESP32 IDE.
- Some experience with sensors and actuators.

## Getting Started

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/Ziad-Abaza/Embedded-Systems-Experiments.git
    ```

2. Follow the instructions in each experiment’s directory for setting up the components and uploading the code to your microcontroller.

## Contributions

Feel free to fork the repository and submit pull requests with improvements, bug fixes, or new experiments.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
