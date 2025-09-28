/*
  RFID Based Door Lock System
  Components: RC522 RFID, Servo Motor, Arduino
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
Servo doorServo;

byte masterCard[4] = {0xDE, 0xAD, 0xBE, 0xEF}; // Example UID

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  doorServo.attach(8);
  doorServo.write(0); // Locked
  Serial.println("RFID Door Lock Ready...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  if (rfid.uid.uidByte[0] == masterCard[0] &&
      rfid.uid.uidByte[1] == masterCard[1] &&
      rfid.uid.uidByte[2] == masterCard[2] &&
      rfid.uid.uidByte[3] == masterCard[3]) {
    Serial.println("✅ Access Granted!");
    doorServo.write(90); // Unlock
    delay(5000);
    doorServo.write(0);  // Lock again
  } else {
    Serial.println("❌ Access Denied!");
  }

  rfid.PICC_HaltA();
}
