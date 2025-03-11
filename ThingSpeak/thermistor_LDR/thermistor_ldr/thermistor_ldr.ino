#include <WiFi.h>
#include "ThingSpeak.h"

// WiFi credentials
char ssid[] = "Wifi_name"; // your wifi name
char pass[] = "password"; // your wifi password

// ThingSpeak credentials
unsigned long channelID = channelID; // Enter you channel ID
const char* apiKey = "your_api_key"; // enter your write api key

// Pin definitions
#define THERMISTOR_PIN 34
#define LDR_PIN 35

// Constants for thermistor calculations
#define THERMISTOR_NOMINAL 10000   // Resistance at 25�C
#define TEMPERATURE_NOMINAL 25     // Temperature for nominal resistance (�C)
#define B_COEFFICIENT 3950         // Beta coefficient of the thermistor
#define SERIES_RESISTOR 10000      // Value of the series resistor

// Variables for sensor readings
float temperature;
int lightLevel;
unsigned long lastPublishTime = 0;
const unsigned long publishInterval = 15000;  // ThingSpeak has a 15-second update limit, minimum allowed time for free version

// Create a WiFiClient instance
WiFiClient client;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Initialize ThingSpeak
  ThingSpeak.begin(client);
  
  Serial.println("Setup complete");
}

void loop() {
  // Check WiFi connection
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection lost. Reconnecting...");
    WiFi.begin(ssid, pass);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    
    Serial.println("Reconnected to WiFi");
  }
  
  // Publish data at regular intervals
  if (millis() - lastPublishTime > publishInterval) {
    readSensors();
    publishToThingSpeak();
    lastPublishTime = millis();
  }
}

void readSensors() {
  // Read temperature from thermistor
  int thermistorReading = analogRead(THERMISTOR_PIN);
  
  // Calculate resistance of thermistor using voltage divider formula
  float resistance = SERIES_RESISTOR / ((4095.0 / thermistorReading) - 1);
  
  // Convert resistance to temperature using Steinhart-Hart equation
  temperature = resistance / THERMISTOR_NOMINAL;          // (R/R0)
  temperature = log(temperature);                         // ln(R/R0)
  temperature /= B_COEFFICIENT;                           // 1/B * ln(R/R0)
  temperature += 1.0 / (TEMPERATURE_NOMINAL + 273.15);    // + (1/T0)
  temperature = 1.0 / temperature;                        // Invert
  temperature -= 273.15;                                  // Convert to Celsius
  
  // Read light level from LDR
  lightLevel = analogRead(LDR_PIN);
  
  // Print sensor readings to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("�C, Light Level: ");
  Serial.println(lightLevel);
}

void publishToThingSpeak() {
  // Set the fields with the sensor values
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, lightLevel);
  
  // Write to the ThingSpeak channel
  int response = ThingSpeak.writeFields(channelID, apiKey);
  
  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.print("Error sending data to ThingSpeak. HTTP error code: ");
    Serial.println(response);
  }
}