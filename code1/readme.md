# Code 1

This code is designed to monitor power consumption using an Arduino board and publish the power data to Adafruit IO MQTT service. It reads the current and voltage values from analog pins, calculates the power, and publishes it to an Adafruit IO feed at regular intervals.

## Prerequisites

Before using this code, make sure you have the following:

- Arduino board (compatible with Adafruit MQTT library)
- Wi-Fi network credentials (SSID and password)
- Adafruit IO account (username and key)

## Dependencies

This code requires the following libraries:

- `Adafruit_MQTT.h`
- `Adafruit_MQTT_Client.h`

Make sure you have these libraries installed in your Arduino IDE.

## Circuit Connection

Make sure you have connected your current and voltage sensors correctly to the Arduino board. Connect the current sensor output to analog pin A0 and the voltage sensor output to analog pin A1.

## Configuration

Before uploading the code, you need to provide the necessary configuration details:

- Replace `YOUR_WIFI_SSID` with the SSID (name) of your Wi-Fi network.
- Replace `YOUR_WIFI_PASSWORD` with the password of your Wi-Fi network.
- Replace `YOUR_ADAFRUIT_USERNAME` with your Adafruit IO username.
- Replace `YOUR_ADAFRUIT_KEY` with your Adafruit IO key.

## Usage

1. Upload the code to your Arduino board.
2. Open the serial monitor to view the debugging information.
3. The Arduino will attempt to connect to the Wi-Fi network. Once connected, it will establish a connection to the Adafruit IO MQTT server.
4. The code continuously reads the current and voltage values from the sensors, calculates the power, and publishes it to the Adafruit IO feed.
5. Every 5 seconds, the power value is published to the feed. The power value is also printed to the serial monitor.
6. Make sure your Adafruit IO feed is correctly set up to receive the power data.

## Flowchart

```mermaid
graph LR
A(Start) --> B{Wi-Fi Connected?}
B -- No --> A
B -- Yes --> C{MQTT Connected?}
C -- No --> C1[Connect to MQTT]
C -- Yes --> D{Time Interval Elapsed?}
D -- No --> D
D -- Yes --> E[Read Current and Voltage]
E --> F[Calculate Power]
F --> G[Publish Power to Adafruit IO]
G --> H[Print Power to Serial Monitor]
H --> D
```

## Troubleshooting

If you encounter any issues, consider the following:

- Double-check your Wi-Fi credentials and Adafruit IO account details.
- Ensure that the current and voltage sensors are correctly connected to the Arduino board.
- Verify that you have the necessary libraries installed in your Arduino IDE.

## Note

Please note that this code is provided as a starting point and may need to be modified to fit your specific requirements. Refer to the official documentation of the Adafruit MQTT library for detailed usage instructions.

Happy power monitoring!
