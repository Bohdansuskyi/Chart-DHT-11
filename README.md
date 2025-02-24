# Projekt IoT: NodeMCU v3 z czujnikiem DHT11 do przesyłania danych do Django REST API
Projekt demonstruje, jak przesyłać dane z czujnika temperatury i wilgotności DHT11 za pomocą płytki NodeMCU v3 do aplikacji Django wdrożonej na PythonAnywhere. Django REST Framework jest używany do uproszczenia komunikacji API. Dane dotyczące temperatury i wilgotności są również wyświetlane na wykresach (chart.js).
### Funkcje
- Przesyłanie danych z czujnika DHT11 w czasie rzeczywistym (z opóźnieniem).
- RESTful API do obsługi danych.
- Łatwa integracja z urządzeniami IoT przy użyciu NodeMCU
### Wada
Jednym z minusów jest to, że czas pomiaru jest zapisywany w formacie GMT zamiast w lokalnej strefie czasowej.
_____________________________________________________________________________________________________________________________
# IoT Project: NodeMCU v3 with DHT11 Sensor for Data Transmission to Django REST API

 This project demonstrates how to send data from a DHT11 temperature and humidity sensor using a NodeMCU v3 board to a Django application deployed on PythonAnywhere. The Django REST Framework is used to simplify API communication. Temperature and humidity data are also displayed using graphs (chart.js).

### Requirements
- Django: 5.0.7
- Django REST Framework: 3.15.2
- django-filter: 24.2
- Markdown: 3.6
- Python 3.12.3
You may use another version, but it is recommended to use Python 3.9 and newer.

### Features
1. Real-time data transmission from the DHT11 sensor (with delay).
2. RESTful API endpoints for data handling.
3. Easy integration with IoT devices using NodeMCU.

### Deploy Django Project
[You can learn how to deploy a Django project in this video](https://youtu.be/xtnUwvjOThg?si=O-7C6Hsz7lhh11IP)

# Photo
## Homepage of the website
![20240924_150150](https://github.com/user-attachments/assets/e1abd510-acd1-4f8a-bc3f-ac823ffcdca8)

## Page with graph
![20240924_151343](https://github.com/user-attachments/assets/1fdda986-6ffd-4f95-8782-8471152f14bd)

# Drawback
One disadvantage is that the measurement time is recorded in GMT instead of the time zone.
