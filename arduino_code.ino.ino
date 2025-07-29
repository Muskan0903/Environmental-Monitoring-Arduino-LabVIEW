#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define LDR_PIN A0

SoftwareSerial espSerial(10, 11); // RX, TX (for ESP-01S)

void setup() {
  Serial.begin(9600);       // For LabVIEW via USB
  espSerial.begin(9600);    // For ESP-01S
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int light = analogRead(LDR_PIN);

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Data format
  String data = "T:" + String(temp) + ",H:" + String(hum) + ",L:" + String(light);

  Serial.println(data);      // To LabVIEW
  espSerial.println(data);   // To ESP-01S

  delay(2000);
}
