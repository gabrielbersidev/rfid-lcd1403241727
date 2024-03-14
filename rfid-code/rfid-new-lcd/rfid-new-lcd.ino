#include <Wire.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define PINO_RST 9
#define PINO_SDA 10
MFRC522 rfid(PINO_SDA, PINO_RST);
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.init();
  lcd.setBacklight(HIGH);
}
 

void loop() 
{
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("SESI SP Mangal");
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Aproxime sua");
  lcd.setCursor(0,1);
  lcd.print("TAG Faber!");
  delay(2500);


   //Procura nova tag
  if (!rfid.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  // Seleciona uma tag
  if (!rfid.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  //Mostra UID na serial e LCD
  //lcd.clear();
  //lcd.print("UID da tag:");
  String conteudo= "";

  for (byte i = 0; i < rfid.uid.size; i++) 
  {
     conteudo.concat(String(rfid.uid.uidByte[i] < HEX ? " 0" : " ")); 
     conteudo.concat(String(rfid.uid.uidByte[i], HEX)); 
  }

  lcd.print(conteudo);

//  Serial.print("UID RFID: ");
//  if (conteudo.substring(1) == "f2 b1 ae 20") //UID 1 - Chaveiro
//  {
//    Serial.println("Chaveiro");
//  }
//  else if (conteudo.substring(1) == "42 36 5a 1a") //UID 2 - Cartao
//  {
//    Serial.println("Cartão");
//  }
//  else
//  {
//    Serial.println("Não registrada");
//  }
}









