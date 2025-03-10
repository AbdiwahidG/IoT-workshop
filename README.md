# IoT Cloud Integration Workshop

This repository contains all the materials needed for the IoT Cloud Integration workshop. The project demonstrates how to connect ESP32 microcontrollers with temperature sensors to cloud platforms (ThingSpeak and AWS IoT) for data collection, storage, and visualization.

## Quick Start

1. Clone this repository:
2. Open Arduino IDE and install required libraries:
   - DHT Sensor Library by Adafruit
   - Adafruit Unified Sensor
   - ESP32 board support
   - ThingSpeak (for ThingSpeak project)
   - MQTT, ArduinoJson, and AWS-SDK-ESP32 (for AWS project)

3. Connect your hardware according to the diagrams in the `diagrams` folder

4. Load the appropriate sketch from the `code` folder

5. Update WiFi credentials and API keys/certificates as needed

6. Upload to your ESP32 and monitor results!

## Repository Contents

- **code/** - Arduino sketches organized by project phase
- **diagrams/** - Connection diagrams and system architecture
- **slides/** - Presentation slides from the workshop
- **troubleshooting/** - Common issues and solutions

## Hardware Requirements

- ESP32 development board (ESP32 DevKit, NodeMCU-32S, etc.)
- DHT22 or DHT11 temperature sensor
- Breadboard
- Jumper wires
- 4.7kΩ or 10kΩ resistor (for DHT sensor pull-up)
- Micro USB cable

## Project Options

### Blynk Integration (Beginner-Friendly)
The Blynk project is simpler to set up and requires:
- Free blynk account
- create new template and data streams
-
-
-
-

### ThingSpeak Integration (Beginner-Friendly)
The ThingSpeak project is simpler to set up and requires:
- Free ThingSpeak account
- Channel with fields for temperature and humidity
- Write API Key from your ThingSpeak channel

### AWS IoT Integration (Advanced)
The AWS IoT project offers more features but requires:
- AWS account
- IoT Thing configuration
- Security certificates
- IAM policies
- Additional libraries

## Step-by-Step Guides

### Basic Setup
1. Connect hardware according to the diagram
2. Install required libraries in Arduino IDE
3. Load the `basic_temperature_reading.ino` sketch
4. Verify sensor readings in the Serial Monitor

### ThingSpeak Setup
1. Create a ThingSpeak account at [thingspeak.com](https://thingspeak.com/)
2. Create a new channel with two fields: Temperature and Humidity
3. Note your Channel ID and Write API Key
4. Update these values in the `thingspeak_integration.ino` sketch
5. Upload and monitor data on ThingSpeak dashboard

### AWS IoT Setup
1. Follow the detailed AWS setup guide in `docs/aws_setup.md`
2. Download and properly place your certificates
3. Update the `secrets.h` file with your endpoint and certificate details
4. Upload the `aws_integration.ino` sketch
5. Monitor device connection and data flow in AWS IoT console

## Troubleshooting

See the `troubleshooting/common_issues.md` file for solutions to common problems.

Common issues include:
- Incorrect wiring connections
- Missing pull-up resistor for DHT sensor
- WiFi connectivity problems
- Incorrect API keys or credentials
- Library conflicts

## Extensions and Next Steps

After completing the basic project, consider these extensions:
- Add additional sensors (light, motion, soil moisture)
- Create custom dashboards and visualizations
- Set up alerts and notifications
- Implement device shadows in AWS IoT
- Create a web or mobile application to view your data

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- ESP32 Community
- ThingSpeak and AWS documentation
- All workshop participants

## Contact

For questions or assistance, please open an issue on this repository.
