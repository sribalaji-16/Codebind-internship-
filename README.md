# Codebind internship

In this intern i have learned a lot about the arduino and ESP32 (wifi) board to integrate and use the sensors for various purpose   

Whee through the knowledge of these skills and hands on experience i did a project Gesture controlled home automation using ESP32 the code i used was also attached in this repo or click on [code](https://github.com/sribalaji-16/Codebind-internship-/blob/main/Gesture%20controlled%20home%20automation%20using%20Arduino%20IDE.ino) to access the code file  

# 🏠 Gesture-Controlled Home Automation 

## 🎯 Objective
Automate home appliances using hand gestures via the **APDS-9960 sensor** and **ESP32 microcontroller**.

## 🔧 Key Components
- **ESP32**: Handles WiFi, gesture processing, and relay control.
- **APDS-9960 Sensor**: Detects UP, DOWN, LEFT, RIGHT gestures.
- **Relay Module**: Controls the appliance (connected to pin 13).
- **Blynk IoT Platform**: Provides remote monitoring and control via smartphone.

## ⚙️ Functionality
- **UP Gesture** → Turns appliance **ON**
- **DOWN Gesture** → Turns appliance **OFF**
- **LEFT/RIGHT Gestures** → Detected but not assigned to actions
- **Blynk App** → Displays appliance status using virtual pin **V1**

## 🛠️ Setup Highlights
- WiFi credentials and Blynk tokens are required for connectivity.
- Gesture sensor is initialized and enabled in setup.
- Real-time gesture detection and appliance control in loop.

## 💡 Applications
- Smart homes  
- Touchless control systems  
- Accessibility solutions
