# IoT Cloud Integration Workshop

![ESP32 IoT Integration](https://img.shields.io/badge/ESP32-IoT_Integration-blue)
![ThingSpeak](https://img.shields.io/badge/Cloud-ThingSpeak-brightgreen)
![Blynk](https://img.shields.io/badge/Cloud-Blynk-orange)
![AWS IoT](https://img.shields.io/badge/Cloud-AWS_IoT-yellow)

This repository contains comprehensive materials for implementing IoT sensor data collection and cloud integration using ESP32 microcontrollers. Learn how to collect temperature and light sensor data and integrate with three different cloud platforms.

## 📌 Project Overview

Connect ESP32 microcontrollers with temperature and light sensors to popular cloud platforms:
- **Blynk** - Quick setup with intuitive mobile app interface
- **ThingSpeak** - Data visualization and analytics
- **AWS IoT** - Enterprise-grade IoT solution with advanced features

## 📂 Repository Structure

```
IoT-Workshop/
├── AWS/                      # AWS IoT implementation
│   ├── diagrams/             # Connection diagrams for AWS setup
│   ├── code/                 # AWS IoT integration code
│   └── README.md             # AWS-specific instructions
│
├── Blynk/                    # Blynk implementation
│   ├── diagrams/             # Connection diagrams for Blynk setup
│   ├── code/                 # Blynk integration code
│   └── README.md             # Blynk-specific instructions
│
├── ThingSpeak/               # ThingSpeak implementation
│   ├── diagrams/             # Connection diagrams for ThingSpeak setup
│   ├── code/                 # ThingSpeak integration code
│   └── README.md             # ThingSpeak-specific instructions
│
├── LED_ON_OFF/               # Basic LED control project
│   ├── led_on_off.ino        # Basic LED control sketch
│   ├── circuit_LED.png       # Circuit diagram for LED
│   └── README.md             # LED project instructions
│
├── Thermistor_LDR/           # Temperature and light sensing
│   ├── thermistor_ldr.ino    # Sensor reading code
│   └── README.md             # Sensor-specific instructions
│
├── ESP32/                    # ESP32 basic setup information
│   └── README.md             # ESP32 getting started guide
│
├── diagrams/                 # Common circuit diagrams
├── slides/                   # Workshop presentation slides
├── troubleshooting/          # Common issues and solutions
└── README.md                 # This main README file
```

## 🚀 Quick Start Guide

1. **Clone this repository:**
   ```bash
   git clone https://github.com/yourusername/IoT-Cloud-Integration-Workshop.git
   ```

2. **Set up your development environment:**
   - Install [Arduino IDE](https://www.arduino.cc/en/software)
   - Install ESP32 board support via Boards Manager
   
3. **Install required libraries:**
   ```
   - DHT Sensor Library by Adafruit
   - Adafruit Unified Sensor
   - ThingSpeak (for ThingSpeak project)
   - Blynk (for Blynk project)
   - MQTT, ArduinoJson, and AWS-SDK-ESP32 (for AWS project)
   ```

4. **Choose your implementation path:**
   - For beginners: Start with LED_ON_OFF, then try Blynk or ThingSpeak
   - For intermediate: Implement the ThingSpeak project
   - For advanced: Tackle the AWS IoT implementation

5. **Hardware setup:**
   - Connect components according to the diagrams in each project folder
   - Review sensor-specific information in the Thermistor_LDR folder

6. **Upload code and test:**
   - Select the appropriate sketch from your chosen implementation folder
   - Update WiFi credentials and API keys/certificates in the code
   - Upload to your ESP32 and monitor results

## 🛠️ Hardware Requirements

- ESP32 development board (ESP32 DevKit, NodeMCU-32S, etc.)
- Thermistor (10K NTC recommended)
- LDR (Light Dependent Resistor)
- 2 × 10K ohm resistors (for voltage dividers)
- Breadboard and jumper wires
- Micro USB cable
- Power source for ESP32

## 🌐 Cloud Platform Options

### Blynk Integration (Beginner-Friendly)
- Quick mobile app interface
- Simple visual programming
- Free tier available
- See [Blynk/README.md](./Blynk/README.md) for detailed setup

### ThingSpeak Integration (Beginner-Friendly)
- MATLAB integration for data analysis
- Built-in visualization tools
- Free tier with update rate limits
- See [ThingSpeak/README.md](./ThingSpeak/README.md) for detailed setup

### AWS IoT Integration (Advanced)
- Enterprise-grade security
- Unlimited scalability
- Advanced features (device shadows, rules engine)
- See [AWS/README.md](./AWS/README.md) for detailed setup

## 📊 Example Projects

Each implementation includes working examples for:
- Basic temperature and light monitoring
- Data visualization dashboards
- Alert mechanisms for value thresholds
- Data logging and export options

## 🔧 Troubleshooting

Common issues and their solutions are documented in the [troubleshooting/common_issues.md](./troubleshooting/common_issues.md) file. If you encounter problems not covered there, please open an issue on this repository.

## 🧪 Extensions and Next Steps

After completing the basic implementations, consider these extensions:
- Add additional sensors (motion, soil moisture, etc.)
- Create custom dashboards and visualizations
- Set up alerts and notifications
- Implement device shadows in AWS IoT
- Create a web or mobile application to interact with your IoT devices

## 📚 Learning Resources

- [ESP32 Official Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [ThingSpeak Documentation](https://www.mathworks.com/help/thingspeak/)
- [Blynk Documentation](https://docs.blynk.io/)
- [AWS IoT Documentation](https://docs.aws.amazon.com/iot/latest/developerguide/what-is-aws-iot.html)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👏 Acknowledgments

- ESP32 Community
- ThingSpeak, Blynk, and AWS documentation
- All workshop participants and contributors

## 📧 Contact

For questions or assistance, please open an issue on this repository.

---

⭐ Star this repository if you found it helpful! ⭐