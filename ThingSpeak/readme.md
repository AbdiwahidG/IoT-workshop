# ThingSpeak Setup Instructions

Before uploading the code to your ESP32, you need to set up ThingSpeak:
# Step 1: Create a ThingSpeak Account

Go to ThingSpeak.com and sign up for an account (or log in if you already have one)
After logging in, click on "Channels" → "New Channel"

# Step 2: Configure Your Channel

Fill in the following details:

Name: ESP32 Sensor Monitor (or any name you prefer)
Description: Temperature and Light Sensor Monitoring
Field 1: Temperature
Field 2: Light Level


You can leave the other fields blank
Click "Save Channel"

# Step 3: Get Your Channel ID and API Key

After creating the channel, go to the "API Keys" tab
Note down your:

Channel ID: Visible at the top of the page
Write API Key: You'll need this to send data to your channel



# Step 4: Update the Code

In the code I provided, replace:

YOUR_WIFI_SSID with your WiFi network name
YOUR_WIFI_PASSWORD with your WiFi password
YOUR_CHANNEL_ID with the Channel ID from ThingSpeak (as a number, no quotes)
YOUR_WRITE_API_KEY with the Write API Key from ThingSpeak (in quotes)



# Step 5: Install Required Library

In Arduino IDE, go to Sketch → Include Library → Manage Libraries
Search for "ThingSpeak" and install the ThingSpeak library by MathWorks

# Step 6: Upload the Code

Connect your ESP32 to your computer
Select the correct board and port in Arduino IDE
Upload the code to your ESP32

# How This Works

The ESP32 reads values from the thermistor and LDR using the same voltage divider circuits we set up earlier
Every 15 seconds (ThingSpeak's minimum update interval for free accounts), the data is sent to ThingSpeak
Temperature data is stored in Field 1 and light level data in Field 2
You can view this data in real-time on the ThingSpeak website

# Visualizing Your Data
Once your ESP32 is sending data to ThingSpeak, you can:

Create Charts: On your channel page, you'll automatically see time-series charts of your data
Create a Dashboard: Use the "Apps" → "MATLAB Visualizations" to create custom visualizations
Set Up Alerts: Configure "ThingSpeak React" to send notifications when values exceed thresholds
Export Data: Download your data in CSV format for further analysis

This ThingSpeak implementation is much simpler than AWS IoT Core while still giving you excellent visualization and monitoring capabilities. Let me know if you'd like any changes to the code or need additional help with your setup!