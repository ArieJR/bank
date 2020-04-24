#ifndef CREATESCHERM_H
#define CREATESCHERM_H

#include <QTranslator>
#include "ui_login.h"
#include "data.h"

class CreateScherm
{
    Q_OBJECT
public:
    CreateScherm();
    void createWelkomScherm();
        void createTaalSchermButton();
        void createSession();//!
            //connect to datebase
            //check if card has an account at our bank
            //check if card has an account at an other bank
            //check if card is blocked

    void cardBlocked();
        void cardIsBlockedMsg();
        void endSession();//!

            //save all data
            //check if any money needs to be dispensed
            //disconnect database

    void returnCard();
        //signal to arduino to return card
    void createInlogScherm();
        bool verifyPincode();
            void resetLoginAttempts();

        void wrongPassword();
            void increaseLoginAttempts();
            void wrongPwMsg();
                //check if blocked

    void createTaalScherm();

        //make language buttons use qtranslator
        void returnButtonLanguage();
            bool getActiveSession();
                //welkomscherm or inlogscherm depending if there is an active session.

    void createHoofdScherm();
        void createSnelPinnenButton();
            //get saldo from database
            //get last x pin transactions and pick the amount that is used the most
            //if multiple values have the same amount take away the last one until 1 has the most
            //anything above saldo is not possible
            // if no values are below or equal the balance value, use the highest possible
    bool reserveMoney();
        //reserve money on a different account, returns true if succeeded
    bool returnReservedMoney();

    void afbreken();
        //abort the session, return the card, go back to the
    void createSaldoScherm();
    void createPinKeuzeScherm();
    void knopBedrag();
    void enoughBalance();
    void createBedragScherm();
    void createBiljetKeuzeScherm();
    void doesntmatter();
    void createBonScherm();
    void createVerwerkingsScherm();
    //createScherm();

    protected:

    protected slots:

private:

};




//welkomsscherm
    //needs a language button
        //-->taalScherm (when no session activated)
    //waits for UID tag
        //starts session when UID tag is noticed
        //checks if a card has an account at our bank
            //checks if card has an account on other bank
                //checks if card is blocked
                    //--> inlogscherm
                    //-->BLOCKED


//blocked
    //return card
        //blocked message
    //end session
    //-->welkomsscherm


//inlogscherm
    //confirm
        //verifies password
            //resets login attempts
                //-->hoofdscherm
        //-->login error
    //-->afbreken

//login error
    //increase login attempts
        //check if blocked
            //BLOCKED
            //-->hoofdscherm

//taalscherm 2 different ones, depending if you're logged in or not
    //-->back
        //back function
    //-->hoofdscherm
    //-->language options

//hoofdscherm
    //check if balance €70,- or higher (maybe an algorithm that tracks latest transactions to pick show the best offer)
        //make snel €70,- button
            //reservesaldo
        //possible lower amounts?
    //-->saldoscherm
    //-->taalscherm
    //-->bedragkeuzescherm
    //-->afbreken

//afbreken
    //return card
    //end session
    //-->welkomscherm

//saldoscherm
    //getsaldo
    //-->afbreken
    //-->pinKeuzescherm

//pinKeuzescherm
    //-->knopbedrag
        //-->afbreken
        //-->hoofdscherm
        //-->bedragscherm
        //-->biljetkeuzescherm

//knopbedrag
        //check saldo
             //make butttons within the limit

//enoughsaldo?
    //getsaldo
        //compare

//reservesaldo
    //reserve withdrawable money into seperate account

//reservedback
    //put back reserved money

//bedragscherm
        //confirm
            //-->enoughsaldo?
                //-->biljetkeuzescherm
                //not enough saldo


//biljetkeuzescherm
    //--> afbreken
    //-->hoofdscherm
    //-->boeit niet
        //-->reservesaldo
        //-->bonscherm
    //-->banknote algorithm
        //banknote options
            //-->reservesaldo
            //-->bonscherm

//boeit niet
    //algoritme beste biljetten om weg te doen
        //maak knoppen

//bonscherm
   //check if paper
        //ticket?
            //yes
                //-->verwerkingsscherm
            //no
                //-->hoofdscherm
                //reservedback

        //still want to continue?
            //yes
                //-->verwerkingsscherm
            //no
                //-->hoofdscherm
                //reservedback

    //-->hoofdscherm
        //reservedback

    //-->afbreken
        //reservedback

//verwerkenscherm
    //-->endsession
    //return card
    //check for dispense money
        //dispense
        //skip
    //check if bon
        //print bon
        //skip

#endif // CREATESCHERM_H
