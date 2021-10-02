#define BLYNK_PRINT Serial // definisi serial pada blynk


#include <ESP8266WiFi.h>// file modul wifi
#include <BlynkSimpleEsp8266.h>// file untuk blynk
#include <Servo.h> //libary servo

char auth[] = "ci25SF6liegbnXmHWOx5cLU28-LsdwB7";//token yang dikirim dari blynk ke email masing masing
char ssid[] = "Iphone Uqi";
char pass[] = "Carisendiri";

//definisi fungsi servo menjadi gerak_servo
Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
} // Fungsi Blynk untuk mengatur  nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk

void setup()
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan baudrate 9600
  Blynk.begin(auth,ssid,pass); // menjalankan blynk sesuai token,wifi dan passwordnya
  gerak_servo.attach(2); // setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run();
}
