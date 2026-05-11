#include <WiFi.h>
#include <ESP32Servo.h>

// Pin
#define SERVO_PIN 14

Servo myServo;

void setup() {
  Serial.begin(115200);

  myServo.attach(SERVO_PIN);

  // Default posisi awal
  myServo.write(0);
}

void loop() {
  myServo.write(90); //bergerak ke sudut 90 derajat
  delay(2000);
  myServo.write(0);  //kembali ke sudut 0 derajat
  delay(2000);
}
