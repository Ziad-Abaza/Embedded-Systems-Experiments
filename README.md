# Intro to Embedded Systems - Hands-on Experiments

This repository contains a collection of hands-on experiments designed to introduce first-year Information Technology students to the fundamentals of embedded systems. These experiments were originally taught and explained to my university's first-year students while I was in my third year, as part of an initiative suggested by Dr. Osama El-Nahas, Head of the Information Technology Department. His vision was to provide beginner students with practical experience in embedded systems and the Internet of Things (IoT).

## Purpose

The experiments in this repository aim to help students gain foundational knowledge in working with microcontrollers, sensors, and actuators, and to understand how embedded systems interact with the real world. By following these experiments, students will develop hands-on skills in programming, circuit design, and system integration.

## Table of Contents

1. [DC Motor Control with Motion Sensor (ESP32)](#experiment-1-dc-motor-control-with-motion-sensor-esp32)
2. [Fan Control with DHT22 Sensor and OLED Display](#experiment-2-fan-control-with-dht22-sensor-and-oled-display)
3. [Door Lock Control with RFID](#experiment-3-door-lock-control-with-rfid)
4. [Water Level Measurement with Ultrasonic Sensor](#experiment-4-water-level-measurement-with-ultrasonic-sensor)
5. [Servo Motor Control with Joystick (ESP32)](#experiment-5-servo-motor-control-with-joystick-esp32)
6. [ESP32-CAM Live Stream with Mobile DC Motor Control](#experiment-6-esp32-cam-live-stream-with-mobile-dc-motor-control)
7. [Smart Irrigation System](#experiment-7-smart-irrigation-system)
8. [RGB LED Control with Bluetooth](#experiment-8-rgb-led-control-with-bluetooth)
9. [Smoke and Gas Detection](#experiment-9-smoke-and-gas-detection)
10. [Servo Motor Control via Keypad](#experiment-10-servo-motor-control-via-keypad)

## Experiment Details

### Experiment 1: DC Motor Control with Motion Sensor (ESP32)
- **Components**: 2x ESP32, Motion Sensor, DC Motor, L298N Motor Driver
- **Objective**: Use a motion sensor to detect movement and wirelessly control a DC motor via two ESP32 microcontrollers.

### Experiment 2: Fan Control with DHT22 Sensor and OLED Display
- **Components**: Arduino, DHT22 Sensor, OLED Display, Relay
- **Objective**: Automate a fan based on temperature and humidity readings displayed on an OLED screen.

### Experiment 3: Door Lock Control with RFID
- **Components**: Arduino, RFID Module, Solenoid Door Lock, LCD Display, Relay
- **Objective**: Implement an RFID-based door access control system.

### Experiment 4: Water Level Measurement with Ultrasonic Sensor
- **Components**: Arduino, Ultrasonic Sensor, OLED Display, Buzzer
- **Objective**: Monitor water levels and trigger an alert when a threshold is exceeded.

### Experiment 5: Servo Motor Control with Joystick (ESP32)
- **Components**: ESP32, Joystick, Servo Motor
- **Objective**: Control a servo motor position using a joystick interface.

### Experiment 6: ESP32-CAM Live Stream with Mobile DC Motor Control
- **Components**: ESP32-CAM, DC Motor, Motor Driver
- **Objective**: Stream live video and control a motor remotely via a mobile device.

### Experiment 7: Smart Irrigation System
- **Components**: Arduino, Soil Moisture Sensor, Water Pump, Relay
- **Objective**: Automate irrigation based on soil moisture levels.

### Experiment 8: RGB LED Control with Bluetooth
- **Components**: Arduino, Bluetooth Module (HC-05 or HC-06), RGB LED
- **Objective**: Wirelessly control an RGB LED’s color using a mobile app.

### Experiment 9: Smoke and Gas Detection
- **Components**: Arduino, MQ135 Gas Sensor, LCD Display
- **Objective**: Detect smoke and gas levels and display real-time readings.

### Experiment 10: Servo Motor Control via Keypad
- **Components**: Arduino, 4x4 Keypad, OLED Display, Servo Motor
- **Objective**: Input servo motor angles via a keypad and display values on an OLED screen.

## Prerequisites

- Basic understanding of embedded systems and microcontrollers.
- Familiarity with Arduino and ESP32 programming.
- Experience working with sensors, actuators, and circuit connections.

## Getting Started

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/Ziad-Abaza/intro-to-embedded-systems-practical-experiments.git
    ```
2. Follow the instructions in each experiment’s directory to set up hardware and upload code.

## Contributions

Contributions are welcome! Feel free to fork the repository and submit pull requests with improvements, additional experiments, or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

