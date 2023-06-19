# ESP8266 power monitoring system

This repository contains code examples for monitoring power consumption using an ESP8266 board and an Arduino board. The code allows you to measure power consumption in kilowatt-hours (kWh) using a combination of current transformers (CT) and voltage dividers. The data can be sent to Adafruit IO MQTT service for further visualization or storage.

## Hardware Requirements

- ESP8266 or Arduino board
- Current transformer (CT)
- Voltage divider (consisting of resistors)
- Power supply for the board

## Circuit Connection

The CT output is connected to an analog input pin (A0) of the board, which is used to measure the current flowing through the circuit. The voltage divider output is connected to another analog input pin (A1) of the board, which is used to measure the voltage of the circuit. The board uses these values to calculate the power consumption and can send the data to Adafruit IO MQTT service via a Wi-Fi connection.

## Software Requirements

- Arduino IDE
- ESP8266 or Arduino board package installed in Arduino IDE
- Adafruit MQTT library

## Setup

1. Install the board package (ESP8266 or Arduino) in Arduino IDE.
2. Install the Adafruit MQTT library in Arduino IDE.
3. Connect the ESP8266 or Arduino board to your computer.
4. Open the code in Arduino IDE and replace the following placeholders with your own values:
   - `YOUR_WIFI_SSID`: Replace with your Wi-Fi network name (SSID).
   - `YOUR_WIFI_PASSWORD`: Replace with your Wi-Fi network password.
   - `YOUR_ADAFRUIT_USERNAME`: Replace with your Adafruit IO username.
   - `YOUR_ADAFRUIT_KEY`: Replace with your Adafruit IO key.
5. Adjust the values for the current transformer ratio, voltage divider resistor values, and the time interval at which you want to send data.
6. Upload the code to the ESP8266 or Arduino board.

## Safety Precautions

- It's important to note that working with high voltage circuits can be dangerous. Make sure to follow proper safety procedures and use appropriate protective gear. Always consult an electrician or professional if you're unsure about anything.

## Troubleshooting

If you encounter any issues, consider the following:

- Double-check your Wi-Fi credentials and Adafruit IO account details.
- Ensure that the current transformer and voltage divider are correctly connected to the board.
- Verify that you have the necessary libraries and board package installed in your Arduino IDE.

Please note that the code provided in this repository is a starting point and may need to be modified to fit your specific requirements. Refer to the official documentation of the respective libraries for detailed usage instructions.

---

## Code Examples

This repository contains the following code examples:

1. [code 1](https://github.com/1999AZZAR/esp8266-home-energy-monitor/blob/master/The%20Code/code1/readme.md): Code for power monitoring using an ESP8266 board.
2. [code 2](https://github.com/1999AZZAR/esp8266-home-energy-monitor/blob/master/The%20Code/code2/readme.md): Code for energy consumption monitoring using an ESP8266 board.
3. [code 3](https://github.com/1999AZZAR/esp8266-home-energy-monitor/blob/master/The%20Code/code3/readme.md): Code for power and energy monitoring using an Arduino board and Adafruit IO MQTT service.

Feel free to explore the individual code samples and adapt them according to your needs. If you have any questions or encounter any issues, don't hesitate to ask for assistance. Happy monitoring!
