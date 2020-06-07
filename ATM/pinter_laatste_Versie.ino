#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  BLUE WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer        yellow gnd
SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial);     

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 7, 4}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String Transactienummer;
String Rekeningnummer;
String Bedrag;

bool rekeningnummer = false;
bool transactienummer = false;
bool bedrag = false;
bool tijd = false;
bool datum = false;

String Uur;
String Maand;
String Dag;
String Jaar;
String Minuut;
String Seconde;

String Datum;
String Tijd;

bool uur =false;
bool minuut =false;
bool seconde =false;
bool jaar =false;
bool maand =false;
bool dag =false;

bool printNu = false;

void setup() 
{

  Serial.begin(9600);
  mySerial.begin(9600); //nodig voor printer
  
}

void loop() 
{
  char customKey = customKeypad.getKey();
  if(customKey)
  {
    Serial.println(customKey);
  }
  
  if (Serial.available())                   //als iets te lezen is
  {
    char SerialDataIn = Serial.read();        //lees de char
    int SerialDataInt = Serial.parseInt();    //lees de volgende int
    

    WriteData(SerialDataIn, SerialDataInt);   //schrijf de gelezen data hier naar toe

    if(jaar == true && maand == true && dag == true)  //als alle info over de datum er is 
    {
      Datum = Dag +"-" +Maand +"-" +Jaar;     // maak de datum om uitgeprint kunt worden
      
      datum = true;
      jaar = false;
      maand = false;
      dag = false;
    }
    if(uur == true && minuut == true && seconde == true) //als alle info over de tijd er is 
    {
      Tijd = Uur +":" +Minuut +":" +Seconde;        // voeg het info bijelkaar om uitgeprint kunt worden

      uur =false;
      minuut = false;
      seconde = false;
      tijd = true;
    }
   if(rekeningnummer == true && transactienummer == true && bedrag == true && tijd == true && datum == true )  //als alle nodige info ontvangen is
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


void WriteData(char dataId, int data) // kijk waar data hoort
{
      if(dataId == 't') //als een 't' bij SerialDataIn is
   {
    String TransIn = String(data);
    Transactienummer = "Transactienummer:       "+TransIn;
    
    transactienummer = true;
   }
      else if(dataId == 'r')
   {
    String Rekening = String(data);
    Rekeningnummer ="Rekeningnummer:       ****"+Rekening;
    rekeningnummer = true;
    
   }
      else if(dataId == 'b')
   {
    String BedragIn = String(data);
    Bedrag = BedragIn +".00 EURO" ;
     bedrag = true;
   }
      else if(dataId == 'y')
   {
    Jaar = String(data);
    jaar =true;
   }
      else if(dataId == 'm')
   {
    Maand = String(data);
    maand =true;
   }
      else if(dataId == 'd')
   {
    Dag = String(data);
    dag =true;
   }
      else if(dataId == 'h')
   {
     Uur = String(data);
     uur =true;
   }
      else if(dataId == 'n')
   {
     Minuut = String(data);
    minuut =true;
   }
      else if(dataId == 's')
   {
     Seconde = String(data);
    seconde = true;
   }
}

void Printerprint()   // het design van de bon
{
 printer.begin();    

 printer.setSize('S');
 printer.justify('L');
 printer.println("Wijnhaven 103");
 printer.println("3011WN, Rotterdam");
 printer.println(" ");


 printer.justify('R');  
 printer.println(Datum); 
 printer.println(Tijd);                                 
 printer.justify('L');
 printer.println("");
 printer.println("Automaatnummer:          ""0001");  //onze automaat id
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
// wilt niet goed uitgeprint worden
  printer.println(""); //extra ruimte onderaan
  printer.println("");
  printer.println("");
  printer.sleep();      // Tell printer to sleep
 
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // rest printer
}
