#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"          // Replace with your Template ID
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"      // Replace with your Template Name
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"      // Replace with your Auth Token


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "wifi name"; // wifi name 
char pass[] = "password"; // enter your wifi password

// Pin definitions
#define THERMISTOR_PIN 34
#define LDR_PIN 35

// Variables for sensor readings
float temperature;
int lightLevel;

// Constants for thermistor calculations
#define THERMISTOR_NOMINAL 10000   // Resistance at 25°C
#define TEMPERATURE_NOMINAL 25     // Temperature for nominal resistance (°C)
#define B_COEFFICIENT 3950         // Beta coefficient of the thermistor
#define SERIES_RESISTOR 10000      // Value of the series resistor

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendSensorData() {
  // Read temperature
  int thermistorReading = analogRead(THERMISTOR_PIN);
  
  // Convert ADC reading to resistance
  float resistance = SERIES_RESISTOR / ((4095.0 / thermistorReading) - 1);
  
  // Convert resistance to temperature using Steinhart-Hart equation
  temperature = resistance / THERMISTOR_NOMINAL;          // (R/R0)
  temperature = log(temperature);                         // ln(R/R0)
  temperature /= B_COEFFICIENT;                           // 1/B * ln(R/R0)
  temperature += 1.0 / (TEMPERATURE_NOMINAL + 273.15);    // + (1/T0)
  temperature = 1.0 / temperature;                        // Invert
  temperature -= 273.15;                                  // Convert to Celsius
  
  // Read light level
  lightLevel = analogRead(LDR_PIN);
  
  // Send data to Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, lightLevel);
  
  // Debug output to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Light Level: ");
  Serial.println(lightLevel);
}