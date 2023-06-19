#include <ESP8266WiFi.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const int currentPin = A0;
const int voltagePin = A1;
const float currentRatio = 1000; // ratio of the current transformer
const int voltageDividerResistor1 = 10;
const int voltageDividerResistor2 = 2;

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
}

void loop() {
  current = analogRead(currentPin) * currentRatio * 0.000001;
  voltage = analogRead(voltagePin) * 0.0048828125 * (voltageDividerResistor1 + voltageDividerResistor2) / voltageDividerResistor2;
  power = current * voltage;
  totalEnergy += power / 3600;

  if (millis() - lastMillis >= 5000) {
    lastMillis = millis();
    Serial.print("Power: ");
    Serial.print(power);
    Serial.println(" W");
    Serial.print("Total energy: ");
    Serial.print(totalEnergy);
    Serial.println(" kWh");
  }
}
