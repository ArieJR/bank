#include "login.h"
#include <QWidget>
#include <QLineEdit>



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
void Login::changeLabel(QLabel* labelToChange, const QString &newLabelContent){
   labelToChange->setText(newLabelContent);
}
void Login::pincodeCheck()
{
    // check for correctness of the pincode
    // pincode will be verified in the database in the future
}


int Login::getPreviousIndex()
{
    return previousIndex; //get the previous index number of the page
}

void Login::setPreviousIndex(int idx){
    previousIndex = idx;      //set a new previous index number of the page
    return;
}
void Login::changeATMPage(int idx){
    setPreviousIndex(ATM->currentIndex()); // setting the previous index right
    ATM->setCurrentIndex(idx);
}

// go to different screens, many of those will require a lot more. they lack functionality for now.
void Login::gotoWelkomScherm()
{
    ATM->setCurrentIndex(0); //end session?
}

void Login::gotoInlogScherm()
{
    ATM->setCurrentIndex(1); //UID detection from microcontroller
}

void Login::gotoTaalScherm()
{
    ATM->setCurrentIndex(2); //might need a second 'taalScherm' since the same one is used when someone is logged in and when someone is not
}

void Login::gotoHoofdScherm()
{
    ATM->setCurrentIndex(3); // snell pinnen option should be removed when someone has less than €70,-
}

void Login::gotoSaldoScherm()
{
    ATM->setCurrentIndex(4); //get saldo from database to show saldo
}

void Login::gotoPinKeuzeScherm()
{
    ATM->setCurrentIndex(5); //user is given a couple withdraw options, he can also choose to put in the amount he wants (still no more than the maximum withdrawable amount, or more than his/her balance)
}

void Login::gotoBiljetScherm()
{
    ATM->setCurrentIndex(6); //there will be a different class dedicated to the different options a user can pick between.
}

void Login::gotoBedragScherm()
{
    ATM->setCurrentIndex(7); // user can choose how much he wants to withdraw, within the limit ofcourse.
}

void Login::gotoBonScherm()
{
    ATM->setCurrentIndex(8); // check if there is enough paper left in the printer
}

void Login::gotoVerwerkingsScherm()
{
    ATM->setCurrentIndex(9); //before the money is being dispensed, the GUI will need to receive confirmation from the database first
                                //the money is being reserved on a special account before the confirmation is sent
}
void Login::gotoPreviousPage()
{
    int tempPreviousIndex;

    tempPreviousIndex = getPreviousIndex();
    ATM->setCurrentIndex(getPreviousIndex());
    setPreviousIndex(tempPreviousIndex);
    // go back to previous page
}



