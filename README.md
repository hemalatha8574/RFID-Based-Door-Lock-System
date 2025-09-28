
---

# RFID Based Door Lock System  

## 🎯 Objective  
To design a secure door lock that only opens with an authorized RFID tag.

---

## 🛠 Components Required  
- Arduino UNO  
- RFID Module RC522  
- Servo Motor (Door Lock)  
- Buzzer  
- Jumper wires  

---

## 🔌 Circuit Diagram  


RFID RC522 SDA → D10
RFID SCK → D13
RFID MOSI → D11
RFID MISO → D12
RFID RST → D9
Servo Motor → D8
Buzzer → D7

---

## ⚙️ Working Principle  
- Each RFID card has a unique UID.  
- Arduino checks UID against stored values.  
- If UID matches → Servo rotates → Door unlocks.  
- If UID doesn’t match → Access denied.  

---

## 🌍 Applications  
- Smart home door locks.  
- Office access control.  
- Attendance systems.  

---
