#include <SoftwareSerial.h>

// Pin definitions
#define SIM_RX 10  // Arduino pin connected to SIM800L TX
#define SIM_TX 11  // Arduino pin connected to SIM800L RX
#define MOTOR_PIN 3 // Pin to control motor relay/transistor

// Create SoftwareSerial object
SoftwareSerial sim800(SIM_RX, SIM_TX);

// Phone number to call/message
String phoneNumber = "+254791002857"; 

// Global variables
String receivedData = "";
bool motorState = false;

void setup() {
  // Initialize serial communications
  Serial.begin(9600);
  sim800.begin(9600);
  
  // Initialize motor control pin
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW); // Start with motor OFF
  
  Serial.println("GSM 800L Motor Control System");
  Serial.println("Initializing...");
  
  // Give the GSM module time to initialize
  delay(3000);
  
  // Initialize GSM module
  sendATCommand("AT", "OK", 1000);
  sendATCommand("AT+CMGF=1", "OK", 1000); // Set SMS to text mode
  sendATCommand("AT+CNMI=1,2,0,0,0", "OK", 1000); // Set new message notifications
  
  Serial.println("System Ready!");
  Serial.println("Commands:");
  Serial.println("c: Make a call");
  Serial.println("s: Send a test SMS");
  Serial.println("1: Turn motor ON");
  Serial.println("0: Turn motor OFF");
}

void loop() {
  // Check for commands from Serial Monitor
  if (Serial.available()) {
    char command = Serial.read();
    processSerialCommand(command);
  }
  
  // Check for incoming data from GSM module
  while (sim800.available()) {
    char c = sim800.read();
    receivedData += c;
  }
  
  // Process complete SMS notifications
  if (receivedData.indexOf("+CMT:") != -1) {
    Serial.println("SMS notification detected!");
    
    // Check if we've received the full message (has two line breaks after the +CMT header)
    if (countOccurrences(receivedData, "\r\n") >= 2) {
      // Parse the SMS
      int headerEnd = receivedData.indexOf("\r\n", receivedData.indexOf("+CMT:"));
      if (headerEnd != -1) {
        // Extract message content after the header
        String smsContent = receivedData.substring(headerEnd + 2);
        smsContent.trim();
        
        Serial.println("SMS Content: [" + smsContent + "]");
        
        // Process the command
        processSMSCommand(smsContent);
        
        // Clear the buffer
        receivedData = "";
      }
    }
  }
  
  // Safety - clear buffer if it gets too large
  if (receivedData.length() > 200) {
    Serial.println("Buffer overflow, clearing");
    receivedData = "";
  }
}

int countOccurrences(String str, String sub) {
  int count = 0;
  int pos = 0;
  while ((pos = str.indexOf(sub, pos)) != -1) {
    count++;
    pos += sub.length();
  }
  return count;
}

void processSerialCommand(char command) {
  switch (command) {
    case 'c':
      makeCall();
      break;
      
    case 's':
      sendSMS("Test message from GSM 800L");
      break;
      
    case '1':
      controlMotor(true);
      break;
      
    case '0':
      controlMotor(false);
      break;
      
    default:
      // Ignore other characters (like newlines)
      break;
  }
}

void processSMSCommand(String message) {
  message.toUpperCase(); // Convert to uppercase for easier comparison
  
  Serial.println("Processing SMS command: [" + message + "]");
  
  if (message.indexOf("ON") != -1 || message == "1") {
    controlMotor(true);
    sendSMS("Motor turned ON");
  } 
  else if (message.indexOf("OFF") != -1 || message == "0") {
    controlMotor(false);
    sendSMS("Motor turned OFF");
  }
  else if (message.indexOf("STATUS") != -1) {
    String status = "Motor is " + String(motorState ? "ON" : "OFF");
    sendSMS(status);
  }
  else {
    // Unknown command - send help
    sendSMS("Unknown command. Use ON, OFF, or STATUS");
  }
}

void controlMotor(bool state) {
  motorState = state;
  digitalWrite(MOTOR_PIN, state ? HIGH : LOW);
  Serial.println(state ? "Motor ON" : "Motor OFF");
}

void makeCall() {
  Serial.println("Calling " + phoneNumber);
  sim800.println("ATD" + phoneNumber + ";");
  delay(1000);
}

void hangUpCall() {
  Serial.println("Hanging up");
  sendATCommand("ATH", "OK", 1000);
}

void sendSMS(String message) {
  Serial.println("Sending SMS: " + message);
  
  // Set SMS text mode
  sim800.println("AT+CMGF=1");
  delay(1000);
  
  // Set SMS recipient
  sim800.println("AT+CMGS=\"" + phoneNumber + "\"");
  delay(1000);
  
  // Send the message content
  sim800.print(message);
  delay(100);
  
  // Send Ctrl+Z to indicate end of message
  sim800.write(26);
  
  // Wait for the message to be sent
  delay(2000);
  Serial.println("SMS sent");
}

bool sendATCommand(String command, String expectedResponse, int timeout) {
  String response = "";
  
  Serial.println("Sending: " + command);
  sim800.println(command);
  
  unsigned long startTime = millis();
  while ((millis() - startTime) < timeout) {
    if (sim800.available()) {
      char c = sim800.read();
      response += c;
      
      if (response.indexOf(expectedResponse) != -1) {
        Serial.println("Response: " + response);
        return true;
      }
    }
  }
  
  Serial.println("Response: " + response);
  return false;
}