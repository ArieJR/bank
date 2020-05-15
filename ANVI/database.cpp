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
void database::checkGebruikersId()
{
    //gebruikersId, rekeningnummer
    //SELECT Gebruikers_ID FROM Rekening WHERE Rekeningnummer='DU99ANVI4445556667';
}

//Slaat Pas_ID, rekeningnummer en Automaat_ID op in sessie
void database::sessieStart()
{
    //pasId, rekeningnummer, automaatId, rekeningnummer
    //INSERT INTO `ANVI`.`Sessie` (`         Automaat_ID`, `Pas_ID`, `Gebruikers_ID`, `Rekeningnummer`) VALUES ('Pin_School', 'CHUAN', '3', 'DU99ANVI4445556667');

    //huidigeSessieId
    //SELECT MAX(Session_ID) FROM Sessie;
}

void database::checkPassword()
{
    //pincodeIngevoerd, pincode, rekeningnummer
    //SELECT case when 1234=(SELECT Pincode FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667') then 1 else 0 end as bool FROM Pas;
}

void database::checkGeblokkeerd()
{
    //pasGeblokkeerd, rekeningnummer
    //SELECT Pas_geblokkeerd FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667';	#(true of false terug)
}

void database::pogingReset()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = '0' WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void database::pogingOmhoog()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void database::checkPogingen()
{
    //aantalFoutpogingen, rekeningnummer
    //SELECT Aantal_foutpogingen FROM Pas WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void database::blokeerPas()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer='DU99ANVI4445556667');
}

void database::sessieEind()
{
    //huidigeSessieId
    //UPDATE `ANVI`.`Sessie` SET `Uitlog_tijd` = CURRENT_TIMESTAMP WHERE (`Session_ID` = '8');
}


void database::getBriefgeldAantal()
{
    //biljet10, biljet20, biljet50;
    //SELECT Biljet10 FROM Automaat WHERE Automaat_ID = "Pin_School";
    //SELECT Biljet20 FROM Automaat WHERE Automaat_ID = "Pin_School";
    //SELECT Biljet50 FROM Automaat WHERE Automaat_ID = "Pin_School";
}

void database::setNewBalance()
{
    //rekeningnummer, bedragGepind
    //UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`-100 WHERE (`Rekeningnummer` = 'DU-ANVI-12345600');
}

float database::getBalance()
{
    balance = 30.0; //balance, rekeningnummer
    //SELECT saldo FROM Rekening WHERE `Rekeningnummer` = 'DU-ANVI-12345600';
    return balance;
}

//maximaal bedrag dat valt te pinnen per dag?
float database::getAmountWithdrawnToday()
{
    /* sql querys voor balance afgelopen sessies */
    return withdrawnToday;
}

void database::verlaag50Briefjes(int numberOfNotes)
{
    //numberOfNotes, automaatId
    //UPDATE `ANVI`.`Automaat` SET `Biljet50` = `Biljet50`-3 WHERE (`Automaat_ID` = 'Pin_School');
}

void database::verlaag20Briefjes(int numberOfNotes)
{
    //numberOfNotes, automaatId
    //UPDATE `ANVI`.`Automaat` SET `Biljet20` = `Biljet20`-3 WHERE (`Automaat_ID` = 'Pin_School');
}

void database::verlaag10Briefjes(int numberOfNotes)
{
    //numberOfNotes, automaatId
    //UPDATE `ANVI`.`Automaat` SET `Biljet10` = `Biljet10`-3 WHERE (`Automaat_ID` = 'Pin_School');
}

float database::getTotaalGeldInATM()
{
    biljet10InAutomaat = 10;//automaatId //SELECT Biljet10 FROM Automaat WHERE Automaat_ID = "Pin_School";
    biljet20InAutomaat = 10;//automaatId //SELECT Biljet20 FROM Automaat WHERE Automaat_ID = "Pin_School";
    biljet50InAutomaat = 10;//automaatId //SELECT Biljet50 FROM Automaat WHERE Automaat_ID = "Pin_School";
    bedragInAutomaat = biljet10InAutomaat*10 + biljet20InAutomaat*20 + biljet50InAutomaat*50;
    return bedragInAutomaat;
}
