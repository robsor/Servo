/*  
 * Read a card using a mfrc522 reader on your SPI interface  
  * Pin layout should be as follows (on Arduino Uno):  
  * MOSI: Pin 11 / ICSP-4  
  * MISO: Pin 12 / ICSP-1  
  * SCK: Pin 13 / ISCP-3  
  * SS: Pin 10  
  * RST: Pin 9  
  */  
 #include <SPI.h>  
 #include <RFID.h>  
 #define SS_PIN 10  
 #define RST_PIN 9 
 RFID rfid(SS_PIN,RST_PIN);  
 int serNum[5];
 byte access[5] =
 
 void setup(){  
  Serial.begin(9600);  
  SPI.begin();  
  rfid.init();
  Serial.println("Scan RFID card"); 
 }
 
 void loop(){  
  if(rfid.isCard()){  
   if(rfid.readCardSerial()) {  
    Serial.print(rfid.serNum[0],HEX);  
    Serial.print(" ");  
    Serial.print(rfid.serNum[1],HEX);  
    Serial.print(" ");  
    Serial.print(rfid.serNum[2],HEX);  
    Serial.print(" ");  
    Serial.print(rfid.serNum[3],HEX);  
    Serial.print(" ");  
    Serial.print(rfid.serNum[4],HEX);  
    Serial.println("");
   delay(500);
   }  
  }  
  rfid.halt();  
 }  
