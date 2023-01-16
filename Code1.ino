#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#define CURRENT_PIN A0
#define VOLTAGE_PIN A1

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "io.adafruit.com";
const char* mqtt_username = "YOUR_ADAFRUIT_USERNAME";
const char* mqtt_key = "YOUR_ADAFRUIT_KEY";

Adafruit_MQTT_Client mqtt(&client, mqtt_server, 1883, mqtt_username, mqtt_key);
Adafruit_MQTT_Publish power = Adafruit_MQTT_Publish(&mqtt, mqtt_username "/feeds/power");

unsigned long lastMillis = 0;
float current = 0;
float voltage = 0;
float power = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  mqtt.connect();
}

void loop() {
  current = analogRead(CURRENT_PIN) * 0.0048828125;
  voltage = analogRead(VOLTAGE_PIN) * 0.0048828125 * (10 + 2) / 2;
  power = current * voltage;
  
  if (millis() - lastMillis >= 5000) {
    lastMillis = millis();
    if (!power.publish(power)) {
      Serial.println(F("Failed to publish power"));
    } else {
      Serial.print(F("Power: "));
      Serial.print(power);
      Serial.println(F(" W"));
    }
  }
  mqtt.processPackets(10000);
}
