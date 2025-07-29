#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// WiFi Credentials
#define WIFI_SSID "Muskan"
#define WIFI_PASSWORD "muskan090320"

// Firebase Credentials
#define API_KEY "AIzaSyDjf4zz3Xd0QKYQcbxbDs3FOQFFRKnPBI4"
#define DATABASE_URL "https://environment-monitoring-e0d27.firebaseio.com"

#define UNO_RX 3
#define UNO_TX 1

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(9600);
  Serial.swap(); // Use GPIO3 (RX) and GPIO1 (TX)

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    int tIdx = input.indexOf("T:");
    int hIdx = input.indexOf("H:");
    int lIdx = input.indexOf("L:");

    if (tIdx != -1 && hIdx != -1 && lIdx != -1) {
      float temp = input.substring(tIdx + 2, hIdx - 1).toFloat();
      float hum = input.substring(hIdx + 2, lIdx - 1).toFloat();
      int light = input.substring(lIdx + 2).toInt();

      Firebase.setFloat(fbdo, "/Environment/Temperature", temp);
      Firebase.setFloat(fbdo, "/Environment/Humidity", hum);
      Firebase.setInt(fbdo, "/Environment/Light", light);
    }
  }
}
