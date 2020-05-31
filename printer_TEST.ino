#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

String Datum;
String Tijd;
String Transactienummer;
String Rekeningnummer;
String Bedrag;

bool rekeningnummer = false;
bool transactienummer = false;
bool bedrag = false;
bool tijd = false;
bool datum = false;

void setup() 
{

  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(3,OUTPUT);
  digitalWrite(3, LOW);    
}

void loop() 
{

  if (Serial.available())                   //als iets te lezen is
  {
    ////tes/////////
     digitalWrite(3, HIGH);   
                    
     digitalWrite(3, LOW);   
     /////////////
     
    char SerialDataIn = Serial.read();        //lees de char
    int SerialDataInt = Serial.parseInt();    //lees de volgende int

    WriteData(SerialDataIn, SerialDataInt);   //schrijf de gelezen data hier naar toe

    Serial.println(Bedrag);

    
   if(rekeningnummer == true && transactienummer == true && bedrag == true && tijd == true && datum == true)  //als alle nodige info ontvangen is
    {

      Printerprint();
      
      rekeningnummer = false;
      transactienummer = false;
      bedrag = false;
      tijd = false;
      datum = false;
    }
  }
}


void WriteData(char dataId, int data)
{
   if(dataId == 't') //als een 't' bij SerialDataIn is
   {
    ///////////////
     digitalWrite(3, HIGH);   
     //delay(1000);                       
     digitalWrite(3, LOW);    
  ////////////////////
    String TransIn = String(data);
    Transactienummer = "Transactienummer:       "+TransIn;
    Serial.println(Transactienummer);
    transactienummer = true;
   }
   if(dataId == 'r')
   {
    ///////////////
         digitalWrite(3, HIGH);   
     //delay(1000);                       
     digitalWrite(3, LOW); 
    //////////////
    String Rekening = String(data);
    Rekeningnummer ="Rekeningnummer:       ****"+Rekening;
    Serial.println(Rekeningnummer);
    rekeningnummer = true;
    
   }
   if(dataId == 'b')
   {
    ////////////////////
         digitalWrite(3, HIGH);   
     //delay(1000);                       
     digitalWrite(3, LOW); 
     ///////////////
    String BedragIn = String(data);
    Bedrag = BedragIn +"0.00 EURO" ;
    Serial.println(Bedrag);
     bedrag = true;
   }

   //moet nog verwerkt worden of niet
   //dus negeer dit
  String Datum = "00-00-0000";
  String Tijd = "00:00";
  

  tijd = true;
  datum = true;
  
}

void Printerprint()   // het design van de bon
{
  /////////////
  digitalWrite(3, HIGH);   
  //delay(3000);                       
  digitalWrite(3, LOW); 
  ////////////////
 printer.begin();    

 printer.setSize('S');
 printer.justify('L');
 printer.println("Wijnhaven 103");
 printer.println("3011WN, Rotterdam");
 printer.println(" ");

 printer.println(Datum);  //datum
 printer.justify('R');  
 printer.println(Tijd);                                 //tijd
 printer.justify('L');
 printer.println("");
 printer.println("Automaatnummer:          ""0001");
 printer.println(Transactienummer);
 printer.println("");
 printer.println(Rekeningnummer);

 printer.println("");
 printer.println("Bedrag");
 printer.justify('R');
 printer.underlineOn();
 printer.println(Bedrag);
 printer.underlineOff();
  
 printer.println("");
 printer.setSize('M');
 printer.justify('C');
 printer.println("Bedankt en tot ziens.");   //slot
 
  printer.sleep();      // Tell printer to sleep
  //delay(3000);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
}
