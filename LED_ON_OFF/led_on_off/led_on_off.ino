// Include the library files
#define BLYNK_PRINT Serial

// Add these lines at the top of your code
// #define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"          // Replace with your Template ID
// #define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"      // Replace with your Template Name
// #define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"   
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"  




#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//include your Auth token
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";


//Your Wifi and Password
char ssid[] = ""; //your wifi name
char password[] =""; // your wifi password

void setup() {
  //Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, password, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}