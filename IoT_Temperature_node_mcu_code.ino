/*
  Before uploid, check if you have all the libraries installed
  and if the ports and board are configured.
  created 24.09.2024
  by Bohdan Suskyi
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>


const char* ssid = "*****";  // Replace with your Wi-Fi name
const char* password = "*****";  // eplace with your Wi-Fi password

const char* serverUrl = "http://USERNAME.pythonanywhere.com/create/";  // The URL of your Django server

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;  // Create a WiFiClient
    HTTPClient http;

    // Data to send via GET request
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
  }
  
  delay(10000);  // Delay before next request
}
