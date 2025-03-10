# Getting Started with ESP32

Welcome to the world of ESP32 development! This quick guide will help you set up your development environment so you can start tinkering right away.

## Setting Up Your Arduino IDE for ESP32

### 1. Install the Arduino IDE

If you haven't already, download and install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software).

### 2. Add ESP32 Board Support

1. Open Arduino IDE
2. Go to **File > Preferences**
3. Find the "Additional Boards Manager URLs" field
4. Add this URL:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
   (If you already have URLs in this field, separate them with commas)
5. Click "OK" to save

### 3. Install ESP32 Board Package

1. Go to **Tools > Board > Boards Manager** or on the Left Tabs click on **Boards Manager**
2. In the search box, type "esp32"
3. Find "ESP32 by Espressif Systems" 
4. Click "Install"
5. Wait for the installation to complete

### 4. Select Your ESP32 Board

1. Go to **Tools > Board > ESP32 Arduino**
2. Select your specific ESP32 board model (typically "ESP32 Dev Module" works for most boards)

### 5. That's It!

You're all set to start programming your ESP32. Connect your board via USB, select the correct port under **Tools > Port**, and you're ready to upload your first sketch.

## Welcome!

Welcome to the ESP32 community! This powerful microcontroller offers Wi-Fi, Bluetooth, tons of GPIO pins, and amazing performance at a low cost. It's perfect for IoT projects, wearables, home automation, and much more.

Enjoy tinkering with your ESP32 - the possibilities are endless!

Happy coding! 🚀