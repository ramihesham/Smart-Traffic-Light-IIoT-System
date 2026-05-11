# 🚦 Smart Traffic Light IIoT System

## 📌 Overview

This project presents **3 ways Smart Traffic Light System** based on **Industrial Internet of Things (IIoT)** using ESP32. It supports multiple operation modes and integrates real-time monitoring with environmental sensing. No pre-built system or template was used I devoloped all the conditions based on my engineering sense to enhance the current standard traffic lights logic which are ineffiecient in complex situations because it relays on timing only and never looks to emergency or you may waste time waiting for the traffic light to turn green while the other routes are totally free of cars.

---

## ⚙️ Features

### 🔹 Mode 1: Standard Traffic Cycle

* Traditional Red-Yellow-Green sequence
* Fixed timing control
* Simple and reliable operation

### 🔹 Mode 2: Wireless Control (ESP-NOW)

* Real-time traffic control using buttons
* Ultra-low latency communication
* Suitable for emergency/manual override

### 🔹 Mode 3: Smart Adaptive Control

* Uses ultrasonic sensors
* Dynamically adjusts traffic flow
* Decision-based rule system

### 🌦️ Climate Monitoring System

* Temperature & Humidity (DHT11)
* Pressure (BMP180)
* Rain Sensor
* Light Detection (LDR)
* LCD Display + Blynk Dashboard

---

## 🧠 Technologies Used

* ESP32
* Arduino IDE
* ESP-NOW Protocol
* Blynk IoT Platform
* Ultrasonic Sensors
* Environmental Sensors

---

## 🧠 Adaptive Traffic Rules Engine

The system uses a **rule-based decision engine** driven by ultrasonic sensor readings to dynamically control traffic flow.

### 📏 Distance-Based Conditions

| Condition | Description           | Action                    |
| --------- | --------------------- | ------------------------- |
| 1         | All distances < 20 cm | `standard_cycle()`        |
| 2         | D1 & D2 < 20, D3 ≥ 20 | `standardcycle_1_2_3_4()` |
| 3         | D1 & D3 < 20, D2 ≥ 20 | `standardcycle_1_2_5_6()` |
| 4         | D2 & D3 < 20, D1 ≥ 20 | `standardcycle_3_4_5_6()` |
| 5         | All distances ≥ 20 cm | `special_star_1()`        |
| 6         | Only D1 < 20          | `special_star_2()`        |
| 7         | Only D2 < 20          | `special_star_3()`        |
| 8         | Only D3 < 20          | `special_star_4()`        |

---

### 🚦 Traffic Light State Table

Each rule corresponds to a specific configuration of the traffic lights:

| Rule           | R1 | Y1 | G1 | R2 | Y2 | G2 | R3 | Y3 | G3 |
| -------------- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| 1              | 0  | 0  | 1  | 1  | 0  | 0  | 1  | 0  | 0  |
| 2              | 0  | 1  | 0  | 1  | 0  | 0  | 1  | 0  | 0  |
| 3              | 1  | 0  | 0  | 0  | 0  | 1  | 1  | 0  | 0  |
| 4              | 1  | 0  | 0  | 0  | 1  | 0  | 1  | 0  | 0  |
| 5              | 1  | 0  | 0  | 1  | 0  | 0  | 0  | 0  | 1  |
| 6              | 1  | 0  | 0  | 1  | 0  | 0  | 0  | 1  | 0  |
| special_star_1 | 1  | 0  | 0  | 1  | 0  | 0  | 1  | 0  | 0  |
| special_star_2 | 0  | 0  | 1  | 1  | 0  | 0  | 1  | 0  | 0  |
| special_star_3 | 1  | 0  | 0  | 0  | 0  | 1  | 1  | 0  | 0  |
| special_star_4 | 1  | 0  | 0  | 1  | 0  | 0  | 0  | 0  | 1  |

---
## BLYNK Dashboards

# SMART TRAFFIC LIGHTS

<img width="940" height="526" alt="image" src="https://github.com/user-attachments/assets/6fbf5970-7e7b-491c-9f6d-15a9613940dc" />

<img width="940" height="560" alt="image" src="https://github.com/user-attachments/assets/9038795e-9228-4c52-b02a-fc3c2795e3d3" />



# Climate Condition

<img width="940" height="400" alt="image" src="https://github.com/user-attachments/assets/570cea56-009b-417e-949a-9a0b7c3d1cbd" />

<img width="940" height="517" alt="image" src="https://github.com/user-attachments/assets/69627d7d-d189-497e-9f37-bb5de626c805" />




* Real-time decision making using sensor fusion
* Scalable IIoT architecture
* Multi-mode operation (manual, timed, intelligent)

---
## 💡 Engineering Highlights

* Real-time decision making using sensor fusion
* Scalable IIoT architecture
* Multi-mode operation (manual, timed, intelligent)

---
## 📂 Project Structure

```
Smart-Traffic-Light-IIoT-System/
│
├── README.md
│
├── code/
│   ├── mode1_standard_cycle/
│   │   └── three_ways_traffic_light_standard.ino
│   │
│   ├── mode2_espnow_manual_control/
│   │   ├── sender_espnow/
│   │   │   └── sender_espnow.ino
│   │   ├── reciver_espnow/
│   │   │    └── reciver_espnow.ino
│   │   └── espnow_macaddress_finder/
│   │       └── espnow_macaddress_finder.ino
│   │
│   ├── mode3_smart_ultrasonic_control/
│   │   └── smart_ultrasonic_control.ino
│   │   └── smart_ultrasonic_control_blynk.ino
│   │
│   └── weather_monitoring_system/
│       └── weather_monitoring_system.ino
```


## 🚀 Getting Started

### 1. Clone Repository

```bash
git clone https://github.com/ramihesham/Smart-Traffic-Light-IIoT-System.git
```

### 2. Install Libraries

* Blynk
* DHT Sensor Library
* BMP180 Library
* LiquidCrystal_I2C

---

## 👨‍💻 Author

Rami Hesham Mohamed
Mechatronics and robotics engineer

---
