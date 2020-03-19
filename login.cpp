#include "login.h"
#include <QWidget>


//! [0]
Login::Login(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    //ATM->setCurrentIndex(0);
    connect(welkom_inlog_button, SIGNAL (released()), this, SLOT (gotoInlogScherm()));
    connect(welkom_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm()));

    connect(inlog_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm()));
    connect(inlog_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(inlog_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));

    connect(taal_hoofd_of_welkom_of_inlog_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));
    connect(taal_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));
    connect(taal_optieDuits_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(taal_optieEngels_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(taal_optieNederlands_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));

    connect(hoofd_pinKeuze_button, SIGNAL (released()), this, SLOT (gotoPinKeuzeScherm()));
    connect(hoofd_saldo_button, SIGNAL (released()), this, SLOT (gotoSaldoScherm()));
    connect(hoofd_snelPinnen_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    connect(hoofd_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm()));
    connect(hoofd_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));

    connect(saldo_hoofdscherm_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(saldo_pinKeuze_button, SIGNAL (released()), this, SLOT (gotopinKeuzeScherm()));
    connect(saldo_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));

    connect(pinKeuze_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(pinKeuze_optie1_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie2_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie3_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie4_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie5_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));
    connect(pinKeuze_zelfBedragKiezen_button, SIGNAL (released()), this, SLOT (gotoBedragKeuzeScherm()));

    connect(biljetKeuze_biljetNietBelangrijk_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    connect(biljetKeuze_biljetOpties1_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    connect(biljetKeuze_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(biljetKeuze_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));

    connect(bedragKeuze_bevestigen_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(bedragKeuze_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(bedragKeuze_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));

    connect(bon_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(bon_metBon_button, SIGNAL (released()), this, SLOT (gotoVerwerkingsScherm()));
    connect(bon_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));
    connect(bon_zonderBon_button, SIGNAL (released()), this, SLOT (gotoVerwerkingsScherm()));


}

void Login::goBack()
{

}

void Login::gotoWelkomScherm()
{
    ATM->setCurrentIndex(0);
}

void Login::gotoInlogScherm()
{
    ATM->setCurrentIndex(1);
}

void Login::gotoTaalScherm()
{
    ATM->setCurrentIndex(2);
}

void Login::gotoHoofdScherm()
{
    ATM->setCurrentIndex(3);
}

void Login::gotoSaldoScherm()
{
    ATM->setCurrentIndex(4);
}

void Login::gotoPinKeuzeScherm()
{
    ATM->setCurrentIndex(5);
}

void Login::gotoBiljetScherm()
{
    ATM->setCurrentIndex(6);
}

void Login::gotoBedragScherm()
{
    ATM->setCurrentIndex(7);
}

void Login::gotoBonScherm()
{
    ATM->setCurrentIndex(8);
}

void Login::gotoVerwerkingsScherm()
{
    ATM->setCurrentIndex(9);
}
