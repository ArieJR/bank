#include "database.h"
#include <QString>

database::database()
{

}


QString database::teruggave()
{
    woord = "hooi";
    return woord;
}

//in rekening kijken welke gebruiker_ID bij rekeningnummer hoort
void checkGebruikersId()
{
    //gebruikersId, rekeningnummer
    //SELECT Gebruikers_ID FROM Rekening WHERE Rekeningnummer='DU99ANVI4445556667';
}

//Slaat Pas_ID, rekeningnummer en Automaat_ID op in sessie
void sessieStart()
{
    //pasId, rekeningnummer, automaatId, rekeningnummer
    //INSERT INTO `ANVI`.`Sessie` (`         Automaat_ID`, `Pas_ID`, `Gebruikers_ID`, `Rekeningnummer`) VALUES ('Pin_School', 'CHUAN', '3', 'DU99ANVI4445556667');

    //huidigeSessieId
    //SELECT MAX(Session_ID) FROM Sessie;
}

void checkPassword()
{
    //pincodeIngevoerd, pincode, rekeningnummer
    //SELECT case when 1234=(SELECT Pincode FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667') then 1 else 0 end as bool FROM Pas;
}

void checkGeblokkeerd()
{
    //pasGeblokkeerd, rekeningnummer
    //SELECT Pas_geblokkeerd FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667';	#(true of false terug)
}

void pogingReset()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = '0' WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void pogingOmhoog()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void checkPogingen()
{
    //aantalFoutpogingen, rekeningnummer
    //SELECT Aantal_foutpogingen FROM Pas WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void blokeerPas()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer='DU99ANVI4445556667');
}



void sessieEind()
{
    //huidigeSessieId
    //UPDATE `ANVI`.`Sessie` SET `Uitlog_tijd` = CURRENT_TIMESTAMP WHERE (`Session_ID` = '8');
}


void getBriefgeldAantal();

void setNewBalance();
float getBalance();
float getAmountWithdrawnToday(); //maximaal bedrag dat valt te pinnen per dag?

void verlaag50Briefjes(int numberOfNotes);
void verlaag20Briefjes(int numberOfNotes);
void verlaag10Briefjes(int numberOfNotes);

float getTotaalGeldInATM();
