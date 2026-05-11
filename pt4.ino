#define BLYNK_TEMPLATE_ID "ID_TEMPLATE_KAMU"
#define BLYNK_TEMPLATE_NAME "LampuPintar"
#define BLYNK_AUTH_TOKEN "ISI_TOKEN_KAMU"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "NAMA_WIFI";
char pass[] = "PASSWORD_WIFI";

// Pin
#define LED_PIN 2   // bisa diganti sesuai pin LED

// Virtual Pin Blynk
#define VPIN_LED V0   // lampu

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
// Kontrol LED (Lampu Rumah)
BLYNK_WRITE(VPIN_LED) {
  int status = param.asInt();
  digitalWrite(LED_PIN, status);
}
