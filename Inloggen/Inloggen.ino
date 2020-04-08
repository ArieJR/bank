#include <Wire.h> 
#include <Keypad.h>
#include <SPI.h>
#include <MFRC522.h>

#define Password_Length 8 
#define SS_PIN 10
#define RST_PIN A1
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int signalPin = 12;


char Data[Password_Length]; 
char Master[Password_Length] = "123A456"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}
void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  //Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "56 58 06 85"){ //change here the UID of the card/cards that you want to give access{ 
    login();
             
  }
} 


void login(){
    int i = 0;
    int j = 0;
    Serial.println("Enter Password:");
    while(i<1){ 
        char customKey = customKeypad.getKey();
      
          if (customKey){
            
            Data[data_count] = customKey;
            data_count++; 
          }
          
          if(data_count == Password_Length-1){
            
              //Serial.println(data_count);
              if(!strcmp(Data, Master)){
                Serial.println("Correct");
                digitalWrite(signalPin, HIGH); 
                delay(5000);
                digitalWrite(signalPin, LOW);
                i++;
              }
              else{
                Serial.println("Incorrect");
                delay(1000);
                i++;
              }
            
          }
     }
      clearData();  
      return;
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}

