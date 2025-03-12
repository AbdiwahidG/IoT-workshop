#include <SoftwareSerial.h>

// Pin definitions
#define MOTOR_PIN 3 // Pin to control motor relay/transistor

// Global variables
bool motorState = false;

void setup() {
  // Initialize serial communications
  Serial.begin(9600);
  
  // Initialize motor control pin
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW); // Start with motor OFF
  
  Serial.println("Motor Control System");
  Serial.println("System Ready!");
  Serial.println("Commands:");
  Serial.println("1: Turn motor ON");
  Serial.println("0: Turn motor OFF");
  Serial.println("s: Get motor status");
  Serial.println("t: Test motor (brief on/off cycle)");
}

void loop() {
  // Check for commands from Serial Monitor
  if (Serial.available()) {
    char command = Serial.read();
    processSerialCommand(command);
  }
}

void processSerialCommand(char command) {
  switch (command) {
    case '1':
      controlMotor(true);
      break;
      
    case '0':
      controlMotor(false);
      break;
      
    case 's':
      Serial.println("Motor is " + String(motorState ? "ON" : "OFF"));
      break;
      
    case 't':
      testMotor();
      break;
      
    default:
      // Ignore other characters (like newlines)
      break;
  }
}

void controlMotor(bool state) {
  motorState = state;
  digitalWrite(MOTOR_PIN, state ? HIGH : LOW);
  Serial.println(state ? "Motor ON" : "Motor OFF");
}

void testMotor() {
  Serial.println("Testing motor...");
  
  // Turn on
  digitalWrite(MOTOR_PIN, HIGH);
  Serial.println("Motor ON");
  delay(2000);
  
  // Turn off
  digitalWrite(MOTOR_PIN, LOW);
  Serial.println("Motor OFF");
  
  // Reset state variable to match final state
  motorState = false;
  
  Serial.println("Motor test complete");
}