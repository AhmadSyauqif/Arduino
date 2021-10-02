#define BLYNK_PRINT Serial

#include <DHT.h>
#include <ESP8266WiFi.h>// file modul wifi
#include <BlynkSimpleEsp8266.h>// file untuk blynk


char auth[] = "YourAuthToken";
char ssid[] = "Nama Hotspotmu";
char pass[] = "Password HS(Hotspot)mu";

#define DHTPIN 14
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
Serial.println("Failed to read temp and humidity");
    return;
  }

  Blynk.virtualWrite(V1, t);//Seting Virtual suhu di blynk
  Blynk.virtualWrite(V2, h);//setting Virtual kelembapan di blynk
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  dht.begin();// Sensor mulai membaca suhu dan kelembapan
  timer.setInterval(1000L, sendSensor); //Waktu untuk mengirimkan data setiap 1 detik sekali
}

void loop() {
Blynk.run();
timer.run();
}
