#ifndef CREATESCHERM_H
#define CREATESCHERM_H


class createScherm
{
public:
    createScherm();
};

//if you finish a line add a comment *DONE <NAME>* behind it

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
