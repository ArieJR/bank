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
    //SELECT Gebruikers_ID FROM ANVI.Rekening WHERE Rekeningnummer='DU99ANVI4445556667';
}

//Slaat Pas_ID, rekeningnummer en Automaat_ID op in sessie
void database::sessieStart()
{
    //pasId, rekeningnummer, automaatId, rekeningnummer
    //INSERT INTO `ANVI`.`Sessie` (`Automaat_ID`, `Pas_ID`, `Gebruikers_ID`, `Rekeningnummer`) VALUES ('Pin_School', 'CHUAN', '3', 'DU99ANVI4445556667');

    //huidigeSessieId
    //SELECT MAX(Session_ID) FROM ANVI.Sessie;
}


bool database::checkPassword(QString pincodeIngevoerd) //gehashed
{
    //pincodeIngevoerd, pincode, rekeningnummer
    //SELECT case when 1234=(SELECT Pincode FROM Pas WHERE Rekeningnummer='DU99ANVI4445556667') then 1 else 0 end as bool FROM ANVI.Pas;

    if(pincodeIngevoerd == "1234")      //hard
    {
        pincode = true;
    }
    else
    {
        pincode = false;
    }

    return pincode;
}

bool database::checkGeblokkeerd()
{
    //pasGeblokkeerd, rekeningnummer
    //SELECT Pas_geblokkeerd FROM ANVI.Pas WHERE Rekeningnummer='DU99ANVI4445556667';	#(true of false terug)
    return pasGeblokkeerd;
}

void database::pogingReset()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = '0' WHERE (Rekeningnummer='DU99ANVI4445556667');

    aantalFoutpogingen = 0;     //hard
}

void database::pogingOmhoog()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer='DU99ANVI4445556667');

    aantalFoutpogingen++;       //hard
}

int database::checkPogingen()
{
    //aantalFoutpogingen, rekeningnummer
    //SELECT Aantal_foutpogingen FROM ANVI.Pas WHERE (Rekeningnummer='DU99ANVI4445556667');

    return aantalFoutpogingen;
}

void database::blokeerPas()
{
    //rekeningnummer
    //UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer='DU99ANVI4445556667');

    pasGeblokkeerd= true;       //hard
}

void database::sessieEind()
{
    //huidigeSessieId
    //UPDATE `ANVI`.`Sessie` SET `Uitlog_tijd` = CURRENT_TIMESTAMP WHERE (`Session_ID` = '8');
}


int database::get50BriefgeldAantal()
{
    //biljet50;
    //SELECT Biljet50 FROM ANVI.Automaat WHERE Automaat_ID = "Pin_School";

    biljet50 = 20;       //hard
    return biljet50;
}

int database::get20BriefgeldAantal()
{
    //biljet20;
    //SELECT Biljet20 FROM ANVI.Automaat WHERE Automaat_ID = "Pin_School";

    biljet20 = 20;       //hard
    return biljet20;
}

int database::get10BriefgeldAantal()
{
    //biljet10;
    //SELECT Biljet10 FROM ANVI.Automaat WHERE Automaat_ID = "Pin_School";

    biljet10 = 20;       //hard
    return biljet10;
}


void database::setNewBalance(float bedragGepind)
{
    //rekeningnummer, bedragGepind
    //UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`-100 WHERE (`Rekeningnummer` = 'DU-ANVI-12345600');
    //UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`+100 WHERE (`Gebruikers_ID` = '5');
    balance -= bedragGepind;      //hard
}

float database::getBalance()
{
    //balance, rekeningnummer
    //SELECT saldo FROM ANVI.Rekening WHERE `Rekeningnummer` = 'DU-ANVI-12345600';
    return balance;
}

//maximaal bedrag dat valt te pinnen per dag checken
float database::getAmountWithdrawnToday()
{
    //rekeningnummer, withdrawnToday
    //SELECT SUM(Bedrag_actie) FROM ANVI.Sessie WHERE (Aanmeld_tijd BETWEEN DATE_SUB(DATE(NOW()), INTERVAL 1 DAY) AND current_timestamp()) AND Rekeningnummer = 'DU-ANVI-12345656' AND Actie = 'Pin';
    withdrawnToday = 200;   //hard
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
{       //hard
    biljet10InAutomaat = 10;//automaatId //SELECT Biljet10 FROM ANVI.Automaat WHERE Automaat_ID = "Pin_School";
    biljet20InAutomaat = 10;//automaatId //SELECT Biljet20 FROM ANVI.Automaat WHERE Automaat_ID = "Pin_School";
    biljet50InAutomaat = 10;//automaatId //SELECT Biljet50 FROM ANVI.Automaat WHERE Automaat_ID = "Pin_School";
    bedragInAutomaat = biljet10InAutomaat*10 + biljet20InAutomaat*20 + biljet50InAutomaat*50;
    return bedragInAutomaat;
}
