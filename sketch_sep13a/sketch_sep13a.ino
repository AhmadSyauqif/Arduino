void setup() {
  /*Semua program void  setup hanya akan dijalankan sekali saja*/
  Serial.begin(9600);
  Serial.println("Welcome to IDN Boarding School");

}

void loop() {
  /* Semua program yang ada di void loop() akan dijalankan berkali-kali ssecara berkala*/
  Serial.println("Welcome to IDN");
  delay(1000);
}
