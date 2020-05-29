#include "database.h"
#include <QString>
#include <QSqlQuery>
#include <QtSql>



database::database()
{

}

//in rekening kijken welke gebruiker_ID bij rekeningnummer hoort
void database::checkGebruikersId()
{
    //SELECT Gebruikers_ID FROM ANVI.Rekening WHERE Rekeningnummer='DU99ANVI4445556667';

   QSqlQuery query;
   query.prepare("SELECT Gebruikers_ID FROM ANVI.Rekening WHERE Rekeningnummer= :rekn");
   query.bindValue(":rekn", rekeningnummer);
   gebruikersId = query.exec();
}

//Slaat Pas_ID, rekeningnummer en Automaat_ID op in sessie
void database::sessieStart()
{
    //INSERT INTO `ANVI`.`Sessie` (`Automaat_ID`, `Pas_ID`, `Gebruikers_ID`, `Rekeningnummer`) VALUES ('Pin_School', 'CHUAN', '3', 'DU99ANVI4445556667');

    QSqlQuery query;
    query.prepare("INSERT INTO `ANVI`.`Sessie` (`Automaat_ID`, `Pas_ID`, `Gebruikers_ID`, `Rekeningnummer`) VALUES (:autID, :pasID, :gebrID, :rekn)");
    query.bindValue(":autID", automaatId);
    query.bindValue(":pasID", pasId);
    query.bindValue(":gebrID", gebruikersId);
    query.bindValue(":rekn", rekeningnummer);
    query.exec();

    //SELECT MAX(Session_ID) FROM ANVI.Sessie;

    QSqlQuery query2 ("SELECT MAX(Session_ID) FROM ANVI.Sessie");
    huidigeSessieId = query2.exec();
}


bool database::checkPassword(QString pincodeIngevoerd) //gehashed
{
    //SELECT case when 1234=(SELECT Pincode FROM ANVI.Pas WHERE Rekeningnummer='DU99ANVI4445556667') then 1 else 0 end as bool FROM ANVI.Pas;

    QSqlQuery query;
    query.prepare("SELECT case when :pinIn=(SELECT Pincode FROM ANVI.Pas WHERE Rekeningnummer= :rekn) then 1 else 0 end as bool FROM ANVI.Pas");
    query.bindValue(":pinIn", pincodeIngevoerd);
    query.bindValue(":rekn", rekeningnummer);
    pincode = query.exec();


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
    //SELECT Pas_geblokkeerd FROM ANVI.Pas WHERE Rekeningnummer='DU99ANVI4445556667';	#(true of false terug)

    QSqlQuery query;
    query.prepare("SELECT Pas_geblokkeerd FROM ANVI.Pas WHERE Rekeningnummer= :rekn");
    query.bindValue(":rekn", rekeningnummer);
    pasGeblokkeerd = query.exec();

    return pasGeblokkeerd;
}

void database::pogingReset()
{
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = '0' WHERE (Rekeningnummer='DU99ANVI4445556667');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = '0' WHERE (Rekeningnummer=:rekn");
    query.bindValue(":rekn", rekeningnummer);
    query.exec();


    aantalFoutpogingen = 0;     //hard
}

void database::pogingOmhoog()
{
    //UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer='DU99ANVI4445556667');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer= :rekn)");
    query.bindValue(":rekn", rekeningnummer);
    query.exec();


    aantalFoutpogingen++;       //hard
}

int database::checkPogingen()
{
    //SELECT Aantal_foutpogingen FROM ANVI.Pas WHERE (Rekeningnummer='DU99ANVI4445556667');

    QSqlQuery query;
    query.prepare("SELECT Aantal_foutpogingen FROM ANVI.Pas WHERE (Rekeningnummer= :rekn)");
    query.bindValue(":rekn", rekeningnummer);
    aantalFoutpogingen = query.exec();

    return aantalFoutpogingen;
}

void database::blokeerPas()
{
    //UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer='DU99ANVI4445556667');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer= :rekn)");
    query.bindValue(":rekn", rekeningnummer);
    query.exec();


    pasGeblokkeerd= true;       //hard
}

void database::sessieEind()
{
    //UPDATE `ANVI`.`Sessie` SET `Uitlog_tijd` = CURRENT_TIMESTAMP WHERE (`Session_ID` = '8');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Sessie` SET `Uitlog_tijd` = CURRENT_TIMESTAMP WHERE (`Session_ID` = :huidSes)");
    query.bindValue(":huidSes", huidigeSessieId);
    query.exec();
}


int database::get50BriefgeldAantal()
{
    //SELECT Biljet50 FROM ANVI.Automaat WHERE Automaat_ID = 'Pin_School';

    QSqlQuery query;
    query.prepare("SELECT Biljet50 FROM ANVI.Automaat WHERE Automaat_ID = :autID");
    query.bindValue(":autID", automaatId);
    biljet50 = query.exec();


    biljet50 = 20;       //hard
    return biljet50;
}

int database::get20BriefgeldAantal()
{
    //SELECT Biljet20 FROM ANVI.Automaat WHERE Automaat_ID = 'Pin_School';

    QSqlQuery query;
    query.prepare("SELECT Biljet20 FROM ANVI.Automaat WHERE Automaat_ID = :autID");
    query.bindValue(":autID", automaatId);
    biljet20 = query.exec();


    biljet20 = 20;       //hard
    return biljet20;
}

int database::get10BriefgeldAantal()
{
    //SELECT Biljet10 FROM ANVI.Automaat WHERE Automaat_ID = 'Pin_School';

    QSqlQuery query;
    query.prepare("SELECT Biljet10 FROM ANVI.Automaat WHERE Automaat_ID = :autID");
    query.bindValue(":autID", automaatId);
    biljet10 = query.exec();


    biljet10 = 20;       //hard
    return biljet10;
}


void database::setNewBalance(float bedragGepind)
{
    //UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`-100 WHERE (`Rekeningnummer` = 'DU-ANVI-12345600');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`- :gepind WHERE (`Rekeningnummer` = :rekn");
    query.bindValue(":rekn", rekeningnummer);
    query.bindValue(":gepind", bedragGepind);
    query.exec();

    //UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`+100 WHERE (`Gebruikers_ID` = '5');

    QSqlQuery query2;
    query2.prepare("UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`+ :gepind WHERE (`Gebruikers_ID` = '5')");
    query2.bindValue(":rekn", rekeningnummer);
    query2.bindValue(":gepind", bedragGepind);
    query2.exec();


    balance -= bedragGepind;      //hard
}

float database::getBalance()
{
    //SELECT saldo FROM ANVI.Rekening WHERE `Rekeningnummer` = 'DU-ANVI-12345600';

    QSqlQuery query;
    query.prepare("SELECT saldo FROM ANVI.Rekening WHERE `Rekeningnummer` = :rekn");
    query.bindValue(":rekn", rekeningnummer);
    balance = query.exec();

    return balance;
}

//maximaal bedrag dat valt te pinnen per dag checken
float database::getAmountWithdrawnToday()
{
    //rekeningnummer, withdrawnToday
    //SELECT SUM(Bedrag_actie) FROM ANVI.Sessie WHERE (Aanmeld_tijd BETWEEN DATE_SUB(DATE(NOW()), INTERVAL 1 DAY) AND current_timestamp()) AND Rekeningnummer = 'DU-ANVI-12345656' AND Actie = 'Pin';

    QSqlQuery query;
    query.prepare("SELECT SUM(Bedrag_actie) FROM ANVI.Sessie WHERE (Aanmeld_tijd BETWEEN DATE_SUB(DATE(NOW()), INTERVAL 1 DAY) AND current_timestamp()) AND Rekeningnummer = :rekn AND Actie = 'Pin'");
    query.bindValue(":rekn", rekeningnummer);
    withdrawnToday = query.exec();


    withdrawnToday = 200;   //hard
    return withdrawnToday;
}

void database::verlaag50Briefjes(int numberOfNotes)
{
    //numberOfNotes, automaatId
    //UPDATE `ANVI`.`Automaat` SET `Biljet50` = `Biljet50`-3 WHERE (`Automaat_ID` = 'Pin_School');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Automaat` SET `Biljet50` = `Biljet50`- :numbNotes WHERE (`Automaat_ID` = :autID");
    query.bindValue(":autID", automaatId);
    query.bindValue(":numbNotes", numberOfNotes);
    query.exec();
}

void database::verlaag20Briefjes(int numberOfNotes)
{
    //numberOfNotes, automaatId
    //UPDATE `ANVI`.`Automaat` SET `Biljet20` = `Biljet20`-3 WHERE (`Automaat_ID` = 'Pin_School');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Automaat` SET `Biljet20` = `Biljet20`- :numbNotes WHERE (`Automaat_ID` = :autID");
    query.bindValue(":autID", automaatId);
    query.bindValue(":numbNotes", numberOfNotes);
    query.exec();
}

void database::verlaag10Briefjes(int numberOfNotes)
{
    //numberOfNotes, automaatId
    //UPDATE `ANVI`.`Automaat` SET `Biljet10` = `Biljet10`-3 WHERE (`Automaat_ID` = 'Pin_School');

    QSqlQuery query;
    query.prepare("UPDATE `ANVI`.`Automaat` SET `Biljet10` = `Biljet10`- :numbNotes WHERE (`Automaat_ID` = :autID");
    query.bindValue(":autID", automaatId);
    query.bindValue(":numbNotes", numberOfNotes);
    query.exec();
}

float database::getTotaalGeldInATM()
{
    //SELECT Biljet10 FROM ANVI.Automaat WHERE Automaat_ID = 'Pin_School';

    QSqlQuery query;
    query.prepare("SELECT Biljet10 FROM ANVI.Automaat WHERE Automaat_ID = :autID");
    query.bindValue(":autID", automaatId);
    biljet10InAutomaat = query.exec();


    //SELECT Biljet20 FROM ANVI.Automaat WHERE Automaat_ID = 'Pin_School';

    QSqlQuery query2;
    query2.prepare("SELECT Biljet20 FROM ANVI.Automaat WHERE Automaat_ID = :autID");
    query2.bindValue(":autID", automaatId);
    biljet20InAutomaat = query2.exec();


    //SELECT Biljet50 FROM ANVI.Automaat WHERE Automaat_ID = 'Pin_School';

    QSqlQuery query3;
    query3.prepare("SELECT Biljet50 FROM ANVI.Automaat WHERE Automaat_ID = :autID");
    query3.bindValue(":autID", automaatId);
    biljet50InAutomaat = query3.exec();


    //hard
    biljet10InAutomaat = 10;
    biljet20InAutomaat = 10;
    biljet50InAutomaat = 10;


    bedragInAutomaat = biljet10InAutomaat*10 + biljet20InAutomaat*20 + biljet50InAutomaat*50;

    return bedragInAutomaat;
}
