#include<SPI.h>
#include<MFRC522.h>
 
#define RST_PIN A0
#define SS_PIN 10
 
MFRC522 mfrc522(SS_PIN, RST_PIN);
 
void setup() {
  Serial.begin(9600);
  Serial.println("RFID reader is ready!");
  Serial.println();
  SPI.begin();
  mfrc522.PCD_Init();
}
 
void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  {
    byte *id = mfrc522.uid.uidByte;
    byte idSize = mfrc522.uid.size;
  
    Serial.print("PICC type: ");
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
  
    Serial.print("UID Size: ");
    Serial.println(idSize);
  
    Serial.print("id : ");
    for (byte i = 0; i < idSize; i++)
    { 
      Serial.print(id[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  
    mfrc522.PICC_HaltA();
    Serial.println();
  } 
}
