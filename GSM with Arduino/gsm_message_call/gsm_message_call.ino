#include <SoftwareSerial.h>

// Pin definitions
#define SIM_RX 10  // Arduino pin connected to SIM800L TX
#define SIM_TX 11  // Arduino pin connected to SIM800L RX

// Create SoftwareSerial object
SoftwareSerial sim800(SIM_RX, SIM_TX);

// Phone number to call/message
String phoneNumber = "+254791002857"; 

// Global variables
String receivedData = "";

void setup() {
  // Initialize serial communications
  Serial.begin(9600);
  sim800.begin(9600);
  
  Serial.println("GSM 800L Call and SMS System");
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
  Serial.println("h: Hang up call");
  Serial.println("r: Read incoming messages");
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
    Serial.write(c);  // Echo to serial monitor
  }
  
  // Safety - clear buffer if it gets too large
  if (receivedData.length() > 200) {
    Serial.println("Buffer overflow, clearing");
    receivedData = "";
  }
}

void processSerialCommand(char command) {
  switch (command) {
    case 'c':
      makeCall();
      break;
      
    case 's':
      sendSMS("Test message from GSM 800L");
      break;
      
    case 'h':
      hangUpCall();
      break;
      
    case 'r':
      readSMS();
      break;
      
    default:
      // Ignore other characters (like newlines)
      break;
  }
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

void readSMS() {
  Serial.println("Reading SMS messages");
  sendATCommand("AT+CMGF=1", "OK", 1000);
  sendATCommand("AT+CMGL=\"ALL\"", "OK", 5000);
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