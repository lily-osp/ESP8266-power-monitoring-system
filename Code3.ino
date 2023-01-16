#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const int currentPin = A0;
const int voltagePin = A1;
const float currentRatio = 1000; // ratio of the current transformer
const int voltageDividerResistor1 = 10;
const int voltageDividerResistor2 = 2;

const char* mqtt_server = "io.adafruit.com";
const char* mqtt_username = "YOUR_ADAFRUIT_USERNAME";
const char* mqtt_key = "YOUR_ADAFRUIT_KEY";

Adafruit_MQTT_Client mqtt(&client, mqtt_server, 1883, mqtt_username, mqtt_key);
Adafruit_MQTT_Publish power = Adafruit_MQTT_Publish(&mqtt, mqtt_username "/feeds/power");
Adafruit_MQTT_Publish energy = Adafruit_MQTT_Publish(&mqtt, mqtt_username "/feeds/energy");

unsigned long lastMillis = 0;
float current = 0;
float voltage = 0;
float power = 0;
float totalEnergy = 0;

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
  current = analogRead(currentPin) * currentRatio * 0.000001;
  voltage = analogRead(voltagePin) * 0.0048828125 * (voltageDividerResistor1 + voltageDividerResistor2) / voltageDividerResistor2;
  power = current * voltage;
  totalEnergy += power / 3600;

  if (millis() - lastMillis >= 5000) {
    lastMillis = millis();
    if (!power.publish(power)) {
      Serial.println(F("Failed to publish power"));
    } else {
      Serial.print(F("Power: "));
      Serial.print(power);
      Serial.println(F(" W"));
    }
    if (!energy.publish(totalEnergy)) {
      Serial.println(F("Failed to publish energy"));
    } else {
      Serial.print(F("Energy: "));
      Serial.print(totalEnergy);
      Serial.println(F(" kWh"));
    }
  }
  mqtt.processPackets(10000);
}
