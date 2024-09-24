/*
 Before uploid, check if you have all the libraries installed
  and if the ports and board are configured.
  Created 24.09.2024 by Bohdan Suskyi
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

const char* ssid = "**********";  // Replace with your Wi-Fi name
const char* password = "**********";  // Replace with your Wi-Fi password

const char* serverUrl = "http://**********.pythonanywhere.com/create/";  // The URL of your Django server, replace with your server (domain) name

#define DHTPIN 2 // D4 pin -> 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;  // Store last time request was sent
const long interval = 10000;  // Interval for sending data (10 seconds, delay)

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);

  // Non-blocking connection to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi...");
    delay(1000);  // You could optimize this with millis() as well, but this is short enough
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking delay logic

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the last time you sent data
    
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;  // Create a WiFiClient
      HTTPClient http;

      // Read temperature and humidity
      float temperature = dht.readTemperature();
      float humidity = dht.readHumidity();
      
      // Form a URL with parameters
      String urlWithParams = String(serverUrl) + "?temperature=" + String(temperature) + "&humidity=" + String(humidity);
      
      http.begin(client, urlWithParams);  // Start the HTTP request with two parameters: WiFiClient and URL
      
      int httpResponseCode = http.GET();  // Send a GET request
      
      if (httpResponseCode > 0) {
        String response = http.getString();  // Receive the server's response
        Serial.println(httpResponseCode);
        Serial.println(response);
      } else {
        Serial.println("Error in sending GET request");
      }
      
      http.end();  // Finish the request
    } else {
      Serial.println("WiFi not connected, retrying...");
    }
  }
  
}

