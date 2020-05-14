#include "login.h"
#include <QWidget>
#include <QLineEdit>
//#include "createScherm.h"
#include "QListWidgetItem"
#include "data.h"
#include "qstring.h"




//! [0]
Login::Login(QWidget *parent)
    : QWidget(parent),
    ui (new Ui::Login)
//###########################SETUP###################################################################################################


{

    setupUi(this);
    balance = 100.00;
    pincode = "1234";
    numberFailedLogins = 0;
    numberOf10Notes = 100;
    numberOf20Notes = 100;
    numberOf50Notes = 100;


    TranslateDutch();
    //createWelkomScherm();
    
    //ATM->setCurrentIndex(0);
    connect(welkom_inlog_button, SIGNAL (released()), this, SLOT (gotoInlogScherm())); //works on arduino input
    connect(welkom_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm())); //check
    buttonContent(welkom_taal_button, tr("languages"));
    buttonContent(welkom_inlog_button, tr("simulation"));


    connect(inlog_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm())); //check
    connect(inlog_hoofd_button, SIGNAL (released()), this, SLOT (loginAttempt()));
    connect(inlog_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    buttonContent(inlog_taal_button, tr("languages"));
    buttonContent(inlog_welkom_button, tr("abort"));
    buttonContent(inlog_hoofd_button, tr("confirm"));

    connect(taal_hoofd_of_welkom_of_inlog_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
    connect(taal_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    connect(taal_optieDuits_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
    connect(taal_optieEngels_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
    connect(taal_optieNederlands_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
    buttonContent(taal_welkom_button, tr("abort"));
    buttonContent(taal_hoofd_of_welkom_of_inlog_button, tr("back"));
    buttonContent(taal_optieDuits_button, "deutsch");
    buttonContent(taal_optieEngels_button, "english");
    buttonContent(taal_optieNederlands_button, "nederlands");

    connect(hoofd_pinKeuze_button, SIGNAL (released()), this, SLOT (gotoPinKeuzeScherm()));
    connect(hoofd_saldo_button, SIGNAL (released()), this, SLOT (gotoSaldoScherm()));
    connect(hoofd_snelPinnen_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    connect(hoofd_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm()));
    connect(hoofd_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    buttonContent(hoofd_taal_button, tr("languages"));
    buttonContent(hoofd_saldo_button, tr("balance"));
    buttonContent(hoofd_snelPinnen_button, tr("get snel pinnen"));
    buttonContent(hoofd_welkom_button, tr("abort"));
    buttonContent(hoofd_pinKeuze_button, tr("choose amount"));

    connect(saldo_hoofdscherm_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(saldo_pinKeuze_button, SIGNAL (released()), this, SLOT (gotoPinKeuzeScherm()));
    connect(saldo_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    buttonContent(pinKeuze_hoofd_button, tr("main page"));
    buttonContent(pinKeuze_welkom_button, tr("abort"));
    buttonContent(pinKeuze_zelfBedragKiezen_button, tr("pick own amount"));

    connect(pinKeuze_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(pinKeuze_optie1_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie2_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie3_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie4_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_optie5_button, SIGNAL (released()), this, SLOT (gotoBiljetScherm()));
    connect(pinKeuze_welkom_button, SIGNAL (released()), this, SLOT (gotoWelkomScherm()));
    connect(pinKeuze_zelfBedragKiezen_button, SIGNAL (released()), this, SLOT (gotoBedragScherm()));
    buttonContent(pinKeuze_hoofd_button, tr("main page"));
    buttonContent(pinKeuze_welkom_button, tr("abort"));
    buttonContent(pinKeuze_zelfBedragKiezen_button, tr("pick own amount"));


    connect(biljetKeuze_biljetNietBelangrijk_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    connect(biljetKeuze_biljetOpties1_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    connect(biljetKeuze_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(biljetKeuze_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    buttonContent(biljetKeuze_hoofd_button, tr("main page"));
    buttonContent(biljetKeuze_welkom_button, tr("abort"));
    buttonContent(biljetKeuze_biljetNietBelangrijk_button, tr("not important"));


    connect(bedragKeuze_bevestigen_button, SIGNAL (released()), this, SLOT (confirmWithdrawAmount()));
    connect(bedragKeuze_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(bedragKeuze_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    buttonContent(bedragKeuze_hoofd_button, tr("main page"));
    buttonContent(bedragKeuze_welkom_button, tr("abort"));
    buttonContent(bedragKeuze_bevestigen_button, tr("confirm"));


    connect(bon_hoofd_button, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
    connect(bon_metBon_button, SIGNAL (released()), this, SLOT (gotoVerwerkingsScherm()));
    connect(bon_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
    connect(bon_zonderBon_button, SIGNAL (released()), this, SLOT (gotoVerwerkingsScherm()));
    buttonContent(bon_hoofd_button, tr("main page"));
    buttonContent(bon_metBon_button, tr("yes"));
    buttonContent(bon_zonderBon_button, tr("no"));
    buttonContent(bon_welkom_button, tr("abort"));



}

//#######################CHANGE CONTAINER MESSAGE##########################################################################################################################

void Login::labelContent(QLabel *changeLabelTo, const QString &newLabelContent)
{
   changeLabelTo->setText(newLabelContent);
}

void Login::buttonContent(QPushButton *changeButtonTo, const QString &newButtonContent)
{
   changeButtonTo->setText(newButtonContent);
}


//################################INDEX'S###############################################################

void Login::changeATMPage(int idx)
{
    setPreviousIndex(ATM->currentIndex()); // setting the previous index right
    ATM->setCurrentIndex(idx);
}

int Login::getPreviousIndex()
{
    return previousIndex; //get the previous index number of the page
}

void Login::setPreviousIndex(int idx)
{
    previousIndex = idx;      //set a new previous index number of the page
    return;
}

void Login::gotoPreviousPage()
{
    int tempPreviousIndex;

    tempPreviousIndex = getPreviousIndex();
    setPreviousIndex(getPreviousIndex());
    ATM->setCurrentIndex(tempPreviousIndex);

    // go back to previous page
}



//#########################PAGES################################################################################################

// go to different screens, many of those will require a lot more. they lack functionality for now.


void Login::gotoWelkomScherm()
{
    createWelkomScherm();
    changeATMPage(0);
    //ATM->setCurrentIndex(0); //end session?
}

void Login::createWelkomScherm()
{


    buttonContent(welkom_taal_button, tr("languages"));
    buttonContent(welkom_inlog_button, tr("simulation"));
    /*if(blocked)
    {
        welkom_inlog_button->hide();
    }
    */
}

//Buttons:


//-----------------------------------------------------------

void Login::gotoInlogScherm()
{
    createInlogScherm();
    changeATMPage(1);
}

void Login:: createInlogScherm()
{
    inlog_invoerveldPincode->clear();
    buttonContent(inlog_taal_button, tr("languages"));
    buttonContent(inlog_welkom_button, tr("abort"));
    buttonContent(inlog_hoofd_button, tr("confirm"));
}

//-----------------------------------------------------------

void Login::gotoTaalScherm()
{
    createTaalScherm();
    changeATMPage(2);
}

void Login::createTaalScherm(){
    isDutch = true;
    TranslateDutch();
    buttonContent(taal_welkom_button, tr("abort"));
    buttonContent(taal_hoofd_of_welkom_of_inlog_button, tr("back"));
    buttonContent(taal_optieDuits_button, "deutsch");
    buttonContent(taal_optieEngels_button, "english");
    buttonContent(taal_optieNederlands_button, "nederlands");
}

//----------------------------------------------------------------------------

void Login::gotoHoofdScherm()
{
    createHoofdScherm();
    changeATMPage(3);
}

void Login:: createHoofdScherm()
{

    //hoofd_taal_button, hoofd_saldo_button, hoofd_welkom_button, hoofd_pinKeuze_button
    buttonContent(hoofd_taal_button, tr("languages"));
    buttonContent(hoofd_saldo_button, tr("balance"));
    buttonContent(hoofd_snelPinnen_button, tr("get snel pinnen"));
    buttonContent(hoofd_welkom_button, tr("abort"));
    buttonContent(hoofd_pinKeuze_button, tr("choose amount"));
    createSnelPinnenButton();
}

void Login::createSnelPinnenButton()
{
    if (checkBalance(70.00) == true)
    {
        buttonContent(hoofd_snelPinnen_button, "€70,-");
        hoofd_snelPinnen_button -> show();
    }
    else
    {
        hoofd_snelPinnen_button -> hide();
    }
    //get last 10 transaction amounts pick the one that is pinned the most
    //if multiple amounts have the same amount use the last 9 etc.. until you get it right
    //if it is more that the users balance use the highest possible transaction
}

//-----------------------------------------------------------------------------

void Login::gotoSaldoScherm()
{
    createSaldoScherm();
    changeATMPage(4);
}

void Login:: createSaldoScherm()
{
    isDutch = false;
    TranslateDutch();
    buttonContent(saldo_welkom_button, tr("abort"));
    buttonContent(saldo_pinKeuze_button, tr("choose amount"));
    buttonContent(saldo_hoofdscherm_button, tr("main page"));
    labelContent(saldo_label, getBalance());

    //get saldo and display on GUI
    //labelContent(saldo_label_wat_is_saldo);
}

//----------------------------------------------------------------------------------

void Login::gotoPinKeuzeScherm()
{
    createPinKeuzeScherm();
    changeATMPage(5);
}

void Login:: createPinKeuzeScherm()
{
    buttonContent(pinKeuze_hoofd_button, tr("main page"));
    buttonContent(pinKeuze_welkom_button, tr("abort"));
    buttonContent(pinKeuze_zelfBedragKiezen_button, tr("pick own amount"));
    if(checkBalance(20) == true)
    {
        pinKeuze_optie1_button -> show();
        buttonContent(pinKeuze_optie1_button, "€20,-");
    }
    else
    {
        pinKeuze_optie1_button -> hide();
    }

    if(checkBalance(50) == true)
    {
        pinKeuze_optie2_button -> show();
        buttonContent(pinKeuze_optie2_button, "€50,-");
    }
    else
    {
        pinKeuze_optie2_button -> hide();
    }

    if(checkBalance(80) == true)
    {
        pinKeuze_optie3_button -> show();
        buttonContent(pinKeuze_optie3_button, "€80,-");
    }
    else
    {
        pinKeuze_optie3_button -> hide();
    }

    if(checkBalance(120) == true)
    {
        pinKeuze_optie4_button -> show();
        buttonContent(pinKeuze_optie4_button, "€120,-");
    }
    else
    {
        pinKeuze_optie4_button -> hide();
    }

    if(checkBalance(180) == true)
    {
        pinKeuze_optie5_button -> show();
        buttonContent(pinKeuze_optie5_button, "€180,-");
    }
    else
    {
        pinKeuze_optie5_button -> hide();
    }

    //get balance
    //make 5 different buttons with 5 different values
    //check if the user has enough balance for each individual value
    //if not hide the button option (keypad input shouldn't work either)
}


//------------------------------------------------------------------------------
void Login::gotoBiljetScherm(int withdrawAmount)
{
    createBiljetKeuzeScherm(withdrawAmount);
    changeATMPage(6);
}
void Login::gotoBiljetScherm()
{
    changeATMPage(6);
}

void Login:: createBiljetKeuzeScherm(int withdrawAmount)
{
    buttonContent(biljetKeuze_hoofd_button, tr("main page"));
    buttonContent(biljetKeuze_welkom_button, tr("abort"));
    buttonContent(biljetKeuze_biljetNietBelangrijk_button, tr("not important"));
}


//------------------------------------------------------------------------------------------

void Login::gotoBedragScherm()
{
    createBedragScherm();
    changeATMPage(7);
}

void Login:: createBedragScherm()
{
    buttonContent(bedragKeuze_hoofd_button, tr("main page"));
    buttonContent(bedragKeuze_welkom_button, tr("abort"));
    buttonContent(bedragKeuze_bevestigen_button, tr("confirm"));
}

//-------------------------------------------------------------------------------------------

void Login::gotoBonScherm()
{
    createBonScherm();
    changeATMPage(8);
}

void Login:: createBonScherm()
{
    buttonContent(bon_hoofd_button, tr("main page"));
    buttonContent(bon_metBon_button, tr("yes"));
    buttonContent(bon_zonderBon_button, tr("no"));
    buttonContent(bon_welkom_button, tr("abort"));
}

//-----------------------------------------------------------------------------------------------

void Login::gotoVerwerkingsScherm()
{
    changeATMPage(9);
                                //the money is being reserved on a special account before the confirmation is sent
}

void Login:: createVerwerkingsScherm()
{

}

//###########################ARDUINO################################################################


void Login::returnCard()
{
    //signal to arduino to return card
}


//###########################DATABASE###########################################################################################

void Login::endSession()
{
    //save data
    //check for left actions to do
    //disconnect with database
    gotoWelkomScherm();
}

void Login::createSession()
{

    //Data newSession;
    //newSession.getBalance();
    //connect to database
    //check if card is at our bank
    //check if card is at other bank
    //check if blocked
}

//----------------------------------------------------------------------------------------------------------

void Login::resetLoginAttempts()
{
    numberFailedLogins = 0;
    return;
}

void Login::increaseLoginAttempts()
{
    numberFailedLogins++;
    return;
}

void Login::loginAttempt()
{
    //createSession();
    if(verifyPincode() == true)
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
            endSession();
        }
    }

}
//-------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------

bool Login::verifyPincode()
{
    if(pincode == inlog_invoerveldPincode->text()){
        resetLoginAttempts();
        inlog_invoerveldPincode->clear();
        return true;
    }
    else{
        increaseLoginAttempts();
        inlog_invoerveldPincode->clear();

        return false;
    }
}

//#####################TRANSLATIONS########################################################

void Login::TranslateDutch()
{
    QTranslator translator;
    if (isDutch) {
        translator.load("bank_en_nl.qm", "");
        qApp->installTranslator(&translator);
        isDutch = true;
    } else {
        translator.load("", ""); // Default is english
        qApp->installTranslator(&translator);
        isDutch = false;
    }

    //ui->retranslateUi(this);
    //doReTranslate();
}

void Login::doReTranslate()
{
    //msgbox->setWindowTitle(QObject::tr("ERROR"));
    //msgbox->setText(QObject::tr("Invalid IP adress"));
    //pbtn->setText(QObject::tr("Ok"));
}

//#####################################################################################################################

QString const Login::getBalance()
{
    QString bal;
    bal.setNum(balance);
    return bal;
}

bool Login::fastPin()
{
    if(balance>= 70.00)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Login::checkBalance(float checkBal)
{
    if(balance >= checkBal)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void Login::confirmWithdrawAmount()
{
    bool wrongMult = false;
    bool notEnoughBalance = false;


    int amount = (bedragKeuze_invoerVeld->text()).toInt();
    if(amount%10==0 && checkBalance(amount) == true){
        bedragKeuze_invoerVeld->clear();
        gotoBiljetScherm(amount);
    }
    else
    {
        if(amount%10!=0)
        {
            //wrongMult = true;
            QString wrongMult = QString("wrong multiplier");
        }
        if(checkBalance(amount) != true)
        {
            //notEnoughBalance = true;
            QString notEnoughBalance = QString("not enough balance");

        }
        QString errorMessage = QString("Error: %1 and %2").arg(wrongMult).arg(notEnoughBalance);
        labelContent(bedragKeuze_error_label, errorMessage);
        return;

    }

}

/*class Session::Session{
    void Session::startSession()
    {

    }
};*/



