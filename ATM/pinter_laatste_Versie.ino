#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"
#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  BLUE WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer        yellow gnd
SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial);     

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = 
{
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


// counter that register how many of which note are in queue
int var10;    //q
int var20;    //w
int var50;    //e
//meot nog aangepast worden
// Pins for 10 notes
int in1Pin = 13;
int in2Pin = 2;
int in3Pin = 3;
int in4Pin = 4;
// Pins for 20 notes
int in5Pin = 5;
int in6Pin = 6;
int in7Pin = 7;
int in8Pin = 8;
// Pins for 50 notes
int in9Pin = 9;
int in10Pin = 10;
int in11Pin = 11;
int in12Pin = 12;
// set speed for all steppers
int stepperSpeed = 8;
int steps = 2000;
const int stepsPerRevolution = 2048;

int pause =  500;

#include <Stepper.h>

// setup for steppers
  Stepper stepper10 = Stepper(stepsPerRevolution, in1Pin, in2Pin, in3Pin, in4Pin);
  Stepper stepper20 = Stepper(stepsPerRevolution, in5Pin, in6Pin, in7Pin, in8Pin);
  Stepper stepper50 = Stepper(stepsPerRevolution, in9Pin, in10Pin, in11Pin, in12Pin);


void setup() 
{

  Serial.begin(9600);
  mySerial.begin(9600); //nodig voor printer

  // speed for all steppers
  stepper10.setSpeed(stepperSpeed);
  stepper20.setSpeed(stepperSpeed);
  stepper50.setSpeed(stepperSpeed);
  
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
   else if(dataId == 'q')
   {
       var10 = data;
   }
   else if(dataId == 'w')
   {
       var20 = data;
   }
   else if(dataId == 'e')
   {
       var50 = data;
   }
}

void give10() 
{
    while (var10 != 0) 
    {
    stepper10.step(steps);
    var10--;
    delay(pause);
    }
}

void give20() 
{
    while (var20 != 0) 
    {
    stepper20.step(steps);
    delay(pause);
    var20--;
    }
}

void give50() 
{
    while (var50 != 0) 
    {
    stepper50.step(steps);
    delay(pause);
    var50--;
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
