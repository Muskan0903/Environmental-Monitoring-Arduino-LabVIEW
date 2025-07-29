# Environmental-Monitoring-Arduino-LabVIEW

![Arduino](https://img.shields.io/badge/Platform-Arduino-blue?logo=arduino)
![ESP8266](https://img.shields.io/badge/WiFi-ESP8266-lightgrey?logo=esphome)
![Firebase](https://img.shields.io/badge/Backend-Firebase-yellow?logo=firebase)
![LabVIEW](https://img.shields.io/badge/Visualization-LabVIEW-ffda44)
![Status](https://img.shields.io/badge/Status-Working-brightgreen)

## Project Overview

This project monitors environmental parameters like **temperature**, **humidity**, and **light intensity** using Arduino Uno with DHT22 and LDR sensors. Data is:
- Visualized locally in **LabVIEW**
- Sent to **Firebase Realtime Database** via **ESP-01S (ESP8266)** for remote IoT monitoring.

It combines **real-time local visualization** and **cloud-based data storage**, making it ideal for industrial, agricultural, or smart home applications.

---

## Hardware Used

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno R3         | 1        |
| DHT22 Temperature & Humidity Sensor | 1 |
| LDR (GL5539) Light Sensor | 1     |
| ESP-01S (ESP8266) Wi-Fi Module | 1 |
| AMS1117 3.3V Regulator | 1        |
| Breadboard + Jumper Wires | 1    |
| USB Cable              | 1        |

---

## Software Stack

- **Arduino IDE**
- **LabVIEW** (for local GUI)
- **ESP8266 Core** (via Arduino)
- **Firebase Realtime Database**
- **NI VISA Driver** (for LabVIEW serial)

---

## Circuit Diagram

DHT22 Sensor
VCC → Arduino 5V

DATA → Arduino D2 (Digital Pin 2)

GND → Arduino GND

A 10kΩ pull-up resistor is recommended between DATA and VCC.

 LDR Sensor
One terminal of LDR connected to 5V

Other terminal connected to:

A0  of Arduino

And a 10kΩ resistor to GND (Voltage Divider Configuration)

 ESP-01S (ESP8266)
Since ESP-01S operates at 3.3V logic, we use AMS1117-3.3V regulator to power it safely.

VCC → Output of AMS1117-3.3V (NOT Arduino 3.3V)

GND → Common GND (shared with Arduino)

CH_PD → 3.3V (via AMS1117 output)

TX → Arduino Pin 10

RX → Arduino Pin 11 (via voltage divider: 1kΩ + 2kΩ) to step down 5V TX to ~3.3V

Use SoftwareSerial on pins 10 (RX) and 11 (TX) for communication

 AMS1117 Regulator Module
IN → Arduino 5V

GND → Common GND

OUT → 3.3V to ESP-01S VCC & CH_PD

---

## Arduino Code (UNO)

Arduino reads DHT22 & LDR, then:
- Sends data via USB serial to LabVIEW
- Sends data to ESP8266 via SoftwareSerial

---

## ESP8266 Code (ESP-01S)

ESP receives serial data from Arduino, parses it, and uploads:
- Temperature → `/Environment/Temperature`
- Humidity → `/Environment/Humidity`
- Light → `/Environment/Light`

---

## LabVIEW Front Panel

- **Numeric indicators** for Temp, Humidity, Light
- **Waveform chart** for real-time plotting
- **LED Alert** for threshold warnings
- Data read from **Serial (COM)** at 9600 baud
---

## Firebase Structure

/Environment
├── Temperature: 29.6
├── Humidity: 67.1
└── Light: 381

> Uses Firebase ESP8266 Client Library by Mobizt

---

## How It Works

1. Arduino collects sensor data
2. Sends data to:
   - LabVIEW via USB
   - ESP-01 via SoftwareSerial
3. ESP uploads parsed values to Firebase
4. User monitors data remotely via Firebase or locally in LabVIEW

---

## 🙋‍♀️ Author

**Muskan Sinha**  
*Electronics & Instrumentation Engineering*  
[LinkedIn Profile](https://www.linkedin.com/in/muskansinha0903)

---

## ⭐ Contributions & Feedback

Pull requests and suggestions are welcome! Feel free to fork this repo and improve the design, code, or documentation.

---
