#define BLYNK_PRINT Serial // digunakan untuk monitor blynk di serial


//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h>// file untuk blynk


char auth[] = "ci25SF6liegbnXmHWOx5cLU28-LsdwB7";//token yang dikirim dari blynk ke email masing masing
char ssid[] = "@wifi.id";
char pass[] = "12345678";

void setup()// fungsii utama dijalankan  sekali 
{
  // Debug console
  Serial.begin(9600);//untukk monitor serial print

  Blynk.begin(auth, ssid, pass);// Menjalankan blynk sesuai token,wifi, dan passwordnya
 
}

void loop()// fungsi utama dijalankan berulang kali
{
  Blynk.run();//perintah untuk menjalankan blynk
}
