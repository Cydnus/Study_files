#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class


void RFID_init()
{            
  SPI.begin(); // Init SPI bus
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522  

}

String RFID_Read(bool isReset)
{           
      byte nuidPICC[4];
      String RetStr = "";

      if (! rfid.PICC_IsNewCardPresent())
          return " ";
      
        // Verify if the NUID has been readed
        if ( ! rfid.PICC_ReadCardSerial())
          return " ";
          
        MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
        
        // Check is the PICC of Classic MIFARE type
        if ( piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
          piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
          piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          return " ";
        }
      if(!isReset ||
      rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3]){ 
            RetStr = ByteToString(rfid.uid.uidByte, rfid.uid.size);     
      }
     
        // Halt PICC
        rfid.PICC_HaltA();
      
        // Stop encryption on PCD
        rfid.PCD_StopCrypto1();
        
        return RetStr;
}

String ByteToString(byte *buffer, byte bufferSize)
{  
      String temp = "";
      for (byte i = 0; i < bufferSize; i++) 
      {
            temp = temp + String(buffer[i] < 0x10 ? " 0" : " ");
             temp = temp +String(buffer[i],HEX);
      }
      temp. toUpperCase();
      temp.trim();
      return temp;
}
