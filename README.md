# ESP8266 Power Monitoring

This code allows you to measure power consumption (in kWh) using an ESP8266, a current transformer, and a voltage divider. The data is then sent to Adafruit MQTT server for further visualization or storage.

## Hardware Requirements
- ESP8266 microcontroller
- Current transformer (CT)
- Voltage divider (made up of two resistors R1 and R2)
- Power supply for ESP8266

## Circuit Diagram
The CT output is connected to the ESP8266's analog input A0, which is used to measure the current flowing through the circuit. The voltage divider output is connected to the ESP8266's analog input A1, which is used to measure the voltage of the circuit. The ESP8266 uses the values read from the A0 and A1 pins to calculate the power consumption of the circuit. The ESP8266 then sends the data to the Adafruit MQTT server via WiFi connection.

## Software Requirements
- Arduino IDE
- ESP8266 board package installed in Arduino IDE
- Adafruit MQTT library

## Setup
1. Install the ESP8266 board package in Arduino IDE
2. Install the Adafruit MQTT library in Arduino IDE
3. Connect the ESP8266 to your computer via USB
4. Open the code in Arduino IDE and replace the following placeholders with your own values:
   - YOUR_WIFI_SSID
   - YOUR_WIFI_PASSWORD
   - YOUR_ADAFRUIT_USERNAME
   - YOUR_ADAFRUIT_KEY
5. Adjust the values for the current transformer ratio, voltage divider resistor values, and the time interval at which you want to send data
6. Upload the code to the ESP8266

## Safety
- This is a basic example, you can add more features like sending data to a server, adding a web interface, etc.
- It's important to note that working with high voltage circuits can be dangerous. Make sure to follow proper safety procedures and use appropriate protective gear. Always consult an electrician or professional if you're unsure about anything.
