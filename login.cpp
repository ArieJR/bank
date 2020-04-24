#include "login.h"
#include <QWidget>
#include <QLineEdit>
#include "QListWidgetItem"

//! [0]
Login::Login(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    
    //ATM->setCurrentIndex(0);
    connect(welkom_inlog_button, SIGNAL (released()), this, SLOT (gotoInlogScherm())); //works on arduino input
    connect(welkom_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm())); //check

    connect(inlog_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm())); //check
    //inti
    connect(inlog_hoofd_button, SIGNAL (released()), this, SLOT (inputSend()));
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

    sio::client QTsocket;
    QTsocket.connect("http://145.24.222.11:8085");

//    QTsocket.socket()->emit();
}

void Login::inputSend()
{
    input = inlog_invoerveldPincode->text();
    listWidget->insertItem(1,input);

}


void Login::changeLabel(QLabel* labelToChange, const QString &newLabelContent){
   labelToChange->setText(newLabelContent);
}


void Login::changeATMPage(int idx){
    setPreviousIndex(ATM->currentIndex()); // setting the previous index right
    ATM->setCurrentIndex(idx);
}

// go to different screens, many of those will require a lot more. they lack functionality for now.
void Login::gotoWelkomScherm()
{
    createWelkomScherm();
    ATM->setCurrentIndex(0); //end session?
}

void Login::gotoInlogScherm()
{
    if(checkIfBlocked() == false){
        ATM->setCurrentIndex(1);
    }
    else{
        //card is blocked message
    }
}

void Login::gotoTaalScherm()
{
    createTaalScherm();
    ATM->setCurrentIndex(2); //might need a second 'taalScherm' since the same one is used when someone is logged in and when someone is not
}

void Login::gotoHoofdScherm()
{
    createHoofdScherm();
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

//![1]

void Login::createWelkomScherm()
{


}

void Login::createTaalScherm(){
    //3 language buttons
    //back button
    //abort button
}

void Login:: createInlogScherm()
{

}
void Login:: createHoofdScherm()
{
    createSnelPinnenButton();

}

void Login:: createSaldoScherm()
{
    //get saldo and display on GUI
}

void Login:: createPinKeuzeScherm()
{
    //get balance
    //make 5 different buttons with 5 different values
    //check if the user has enough balance for each individual value
    //if not hide the button option (keypad input shouldn't work either)
}

void Login:: createBedragScherm()
{

}

void Login:: createBiljetKeuzeScherm()
{

}

void Login:: createBonScherm()
{

}

void Login:: createVerwerkingsScherm()
{

}
//! [\1]

//! [2]
void Login::endSession()
{
    //save data
    //check for left actions to do
    //disconnect with database
}


void Login::createSession()
{
    //connect to database
    //check if card is at our bank
    //check if card is at other bank
    //check if blocked
}

//![\2]

bool Login::checkIfBlocked()
{
    return false;
}

void Login::cardBlocked()
{
    returnCard();
    endSession();
    //your card is blocked message
    gotoWelkomScherm();
}


void Login::buttonContent(QPushButton *whatButton, const QString &newButtonContent)
{
   whatButton->setText(newButtonContent);
}

void Login::createSnelPinnenButton()
{
    //get last 10 transaction amounts pick the one that is pinned the most
    //if multiple amounts have the same amount use the last 9 etc.. until you get it right
    //if it is more that the users balance use the highest possible transaction

}
bool Login::checkIfSession()
{
    return true;
}

bool Login::verifyPincode()
{
    if(true){
        resetLoginAttempts();
        return true;
    }
    else{
        increaseLoginAttempts();
        return false;
    }
}
void Login::loginAttempt()
{
    if(verifyPincode())
    {
        gotoHoofdScherm();
    }

    else
    {
        //wrongPwMsg();
        if(checkIfBlocked() == false)
        {
            createInlogScherm();
        }
        else
        {
            createWelkomScherm();
        }
    }
}

void Login::resetLoginAttempts()
{
    //reset login attempts
}

void Login::increaseLoginAttempts()
{
    //increase login attempts
}

void Login::returnCard()
{
    //signal to arduino to return card
}

int Login::getPreviousIndex()
{
    return previousIndex; //get the previous index number of the page
}

void Login::setPreviousIndex(int idx){
    previousIndex = idx;      //set a new previous index number of the page
    return;
}
