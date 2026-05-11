#include <WiFi.h>
#include <ESP32Servo.h>

// Pin
#define RAIN_SENSOR_PIN 35
#define SERVO_PIN 18
#define LED_PIN 2   // bisa diganti sesuai pin LED

Servo jemuranServo;

void setup() {
  Serial.begin(115200);

  pinMode(RAIN_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  jemuranServo.attach(SERVO_PIN);

  // Default posisi awal
  jemuranServo.write(0);
}

void loop() {
  
  int statusHujan = digitalRead(RAIN_SENSOR_PIN);

  // Jika tidak hujan → otomatis keluar (45 derajat)
  if (statusHujan == 0) {         // sesuaikan (kadang 0/1 tergantung sensor)
    jemuranServo.write(45);
    Serial.println("Cuaca Cerah, Jemuran dibuka.");
  }
  // Jika hujan → otomatis tutup (0 derajat)
  else if (statusHujan == 1) {    // sesuaikan (kadang 0/1 tergantung sensor)
    jemuranServo.write(0);
    Serial.println("Hujan terdeteksi! Jemuran ditutup.");
  }
  
}
