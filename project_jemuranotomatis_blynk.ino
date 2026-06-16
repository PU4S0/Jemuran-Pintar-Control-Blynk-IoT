#define BLYNK_TEMPLATE_ID "TMPL6iUudq3SY"
#define BLYNK_TEMPLATE_NAME "tes Jemuran Otomatis"
#define BLYNK_AUTH_TOKEN "qMdAHmMhWgVeOQjzC7xeKTvGFVZNOdpL"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char ssid[] = "ayahhhhh";
char pass[] = "ayah23maret";

// Pin
#define RAIN_SENSOR_PIN 35
#define SERVO_PIN 14
#define LED_PIN 12   // bisa diganti sesuai pin LED

Servo jemuranServo;

// Virtual Pin Blynk
#define VPIN_JEMUR       V0   // tombol jemur kain
#define VPIN_TIDAK_JEMUR V1   // tombol tidak digunakan
#define VPIN_LED         V2   // lampu

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(RAIN_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  jemuranServo.attach(SERVO_PIN);

  // Default posisi awal
  jemuranServo.write(90);
  digitalWrite(LED_PIN,HIGH);
}

void loop() {
  Blynk.run();

  int statusHujan = digitalRead(RAIN_SENSOR_PIN);

  // Jika hujan → otomatis tutup (0 derajat)
  if (statusHujan == 1) {  // sesuaikan (kadang 0/1 tergantung sensor)
    jemuranServo.write(0);
    Serial.println("Hujan terdeteksi! Jemuran ditutup.");
  }

  delay(500);
}

// Tombol Jemur Kain → 45 derajat
BLYNK_WRITE(VPIN_JEMUR) {
  int tombol = param.asInt();
  if (tombol == 1) {
    jemuranServo.write(90);
    Serial.println("Mode Jemur Kain (90 derajat)");
  }
}

// Tombol Tidak Digunakan → 0 derajat
BLYNK_WRITE(VPIN_TIDAK_JEMUR) {
  int tombol = param.asInt();
  if (tombol == 1) {
    jemuranServo.write(0);
    Serial.println("Jemuran ditutup (0 derajat)");
  }
}

// Kontrol LED (Lampu Rumah)
BLYNK_WRITE(VPIN_LED) {
  int status = param.asInt();
  digitalWrite(LED_PIN, status);
}
