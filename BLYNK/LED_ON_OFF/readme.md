# Simple Blynk Setup for ESP32 LED Control

This guide will help you quickly set up Blynk to control an LED with your ESP32.

## What You Need

- ESP32 board
- USB cable
- LED
- 220Ω resistor
- Jumper wires
- Smartphone (iOS or Android)

## Hardware Setup

1. Connect your LED to the ESP32:
   - Connect the LED's long leg (anode/+) to GPIO 2
   - Connect the LED's short leg (cathode/-) to one end of the 220Ω resistor
   - Connect the other end of the resistor to GND (ground)

## Blynk Setup

### 1. Install Blynk App

1. Download the Blynk app from App Store (iOS) or Google Play (Android)
2. Create a new Blynk account or log in

### 2. Create a New Project

1. Open the Blynk app
2. Tap the "New Project" button
3. Give your project a name (e.g., "ESP32 LED Control")
4. Select "ESP32 Dev Board" as the device
5. Choose "Wi-Fi" as the connection type
6. Tap "Create Project"

### 3. Add a Button

1. Tap anywhere on the empty canvas
2. Find and select the "Button" widget
3. Tap on the button to open its settings
4. Set the following:
   - Output: D2 (GPIO 2)
   - Mode: Switch
5. Tap the back arrow to return to the canvas

### 4. Get Auth Token

1. Look for the Auth Token in your project settings or check your email
2. Copy this token - you'll need it for your code

## Arduino IDE Setup

### 1. Install Blynk Library

1. Open Arduino IDE
2. Go to **Sketch > Include Library > Manage Libraries**
3. Search for "Blynk"
4. Find "Blynk by Volodymyr Shymanskyy" and click "Install"

### 2. Upload the Code
Open a new sketch and paste this code:

3. Replace:
   - `YOUR_AUTH_TOKEN` with your Blynk auth token
   - `YOUR_WIFI_SSID` with your Wi-Fi network name
   - `YOUR_WIFI_PASSWORD` with your Wi-Fi password
   - If you're using a newer Blynk account, also fill in `YOUR_TEMPLATE_ID`

4. Select your ESP32 board from **Tools > Board > ESP32**
5. Select the correct port from **Tools > Port**
6. Click the Upload button

## Test It Out

1. Make sure your ESP32 is powered and connected
2. Open the Blynk app and navigate to your project
3. Tap the button you created
4. The LED connected to your ESP32 should turn on and off

That's it! You've created a simple LED control system using Blynk and ESP32.

Enjoy tinkering! 🚀