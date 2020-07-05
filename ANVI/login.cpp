

#include "login.h"
#include <QWidget>
#include <QLineEdit>
//#include "createScherm.h"
#include "QListWidgetItem"
#include "login.h"
#include <QWidget>
#include <QLineEdit>
//#include "createScherm.h"
#include "QListWidgetItem"
#include "qstring.h"
#include "database.h"
//#include "serial.h"
#include <QLabel>
#include <QFrame>
#include <QVariant>
#include <QString>
#include <QDebug>
#include <QTextCodec>
#include <QListView>
#include <QQmlComponent>
#include <QtQuick/QQuickItem>

//! [0]
Login::Login(QWidget *parent)
    : QWidget(parent),
    ui (new Ui::Login)
//###########################SETUP###################################################################################################

{

    //engine = new QQmlEngine;
    //QQmlComponent component(&engine,
            //QUrl::fromLocalFile("MyItem.qml"));
    //QObject *object = component.create();


    gebruikDatabase = new database();
    communicatie = new com();
    setupUi(this);
    TranslateDutch();
    arduino = new QSerialPort;
    //communicatie->init();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) //connect serial
    {
            qDebug() << "Name : " << info.portName();
            qDebug() << "Description : " << info.description();
            qDebug() << "Manufacturer: " << info.manufacturer();

            // Example use QSerialPort
            QSerialPort serial;
            arduino->setPort(info);
            if (arduino->open(QIODevice::ReadWrite))
                //arduino->close();
                qDebug() << "test2";
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
    }

    if(true) //connect buttons
    {
        //connect(arduino, SIGNAL(readyRead()),this, SLOT(readArduino()));
        connect(arduino, SIGNAL(readyRead()),this, SLOT(readArduino()));

        connect(oneButton, SIGNAL (released()), this, SLOT (gotoInlogScherm())); //works on arduino input
        buttonContent(oneButton, "[1] go to inlog");
        //connect(welkom_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm())); //check



        //connect(inlog_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm())); //check
        connect(hashButton_2, SIGNAL (released()), this, SLOT (loginAttempt()));
        buttonContent(hashButton_2, "[#] confirm");
        connect(Dbutton_2, SIGNAL (released()), this, SLOT (backspacepin()));
        buttonContent(Dbutton_2, "[D] Back");

        connect(asterixButton_2, SIGNAL (released()), this, SLOT (endSession()));
        buttonContent(asterixButton_2, "[*] Abort");
        connect(asterixButton_3, SIGNAL (released()), this, SLOT (endSession()));
        buttonContent(asterixButton_3, "[*] Abort");
        connect(asterixButton_4, SIGNAL (released()), this, SLOT (endSession()));
        buttonContent(asterixButton_4, "[*] Abort");
        connect(asterixButton_5, SIGNAL (released()), this, SLOT (endSession()));
        buttonContent(asterixButton_5, "[*] Abort");
        connect(asterixButton_6, SIGNAL (released()), this, SLOT (endSession()));
        buttonContent(asterixButton_6, "[*] Abort");

        connect(hashButton_5, SIGNAL (released()), this, SLOT (confirmWithdrawAmount()));
        buttonContent(hashButton_5, "[#] confirm");
        //connect(taal_hoofd_of_welkom_of_inlog_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
        //connect(taal_welkom_button, SIGNAL (released()), this, SLOT (endSession()));
        //connect(taal_optieDuits_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
        //connect(taal_optieEngels_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));
        //connect(taal_optieNederlands_button, SIGNAL (released()), this, SLOT (gotoPreviousPage()));

        connect(Cbutton_3, SIGNAL (released()), this, SLOT (gotoPinKeuzeScherm()));
        connect(oneButton_3, SIGNAL (released()), this, SLOT (gotoSaldoScherm())); //show saldo in text 2
        connect(Bbutton_3, SIGNAL (released()), this, SLOT (gotoBonScherm()));

        //connect(hoofd_taal_button, SIGNAL (released()), this, SLOT (gotoTaalScherm()));
        connect(hoofd_welkom_button, SIGNAL (released()), this, SLOT (endSession()));

        connect(Abutton_4, SIGNAL (released()), this, SLOT (gotoBedragScherm()));

        connect(Dbutton_4, SIGNAL (released()), this, SLOT (backspacebedrag()));
        buttonContent(Dbutton_4, "[D] Backspace");

        connect(Dbutton_5, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
        buttonContent(Dbutton_5, "[D] Main");

        connect(Dbutton_6, SIGNAL (released()), this, SLOT (gotoHoofdScherm()));
        buttonContent(Dbutton_6, "[D] Main");

        connect(oneButtonSide, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(twoButtonSide, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(threeButtonSide, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(fourButtonSide, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(fiveButtonSide, SIGNAL (released()), this, SLOT (gotoBonScherm()));


        //oneButton->hide();
        fourButton-> hide();
        sevenButton-> hide();
        asterixButton-> hide();
        hashButton-> hide();
        Abutton-> hide();
        Bbutton-> hide();
        Cbutton-> hide();
        Dbutton-> hide();

        oneButton_2->hide();
        fourButton_2-> hide();
        sevenButton_2-> hide();
        //asterixButton_2-> hide();
        //hashButton_2-> hide();
        Abutton_2-> hide();
        Bbutton_2-> hide();
        Cbutton_2-> hide();
        //Dbutton_2-> hide();

        //oneButton_2->hide();
        fourButton_2-> hide();
        sevenButton_2-> hide();
        //asterixButton_2-> hide();
        //hashButton_2-> hide();
        Abutton_2-> hide();
        //Bbutton_2-> hide();
        //Cbutton_2-> hide();
        //Dbutton_2-> hide();

        //oneButton_3->hide();
        fourButton_3-> hide();
        sevenButton_3-> hide();
        //asterixButton_3-> hide();
        //hashButton_3-> hide();
        Abutton_3-> hide();
        //Bbutton_3-> hide();
        //Cbutton_3-> hide();
        //Dbutton_3-> hide();

        oneButton_4->hide();
        fourButton_4-> hide();
        sevenButton_4-> hide();
        //asterixButton_4-> hide();
        //hashButton_4-> hide();
        Abutton_4-> hide();
        Bbutton_4-> hide();
        Cbutton_4-> hide();
        //Dbutton_4-> hide();

        oneButtonSide-> hide();
        twoButtonSide-> hide();
        threeButtonSide-> hide();
        fourButtonSide-> hide();
        fiveButtonSide-> hide();






        connect(oneButton_4, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(fourButton_4, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(sevenButton_4, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(Bbutton_4, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        connect(Cbutton_4, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        //connect(pinKeuze_optie5_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
        //connect(pinKeuze_welkom_button, SIGNAL (released()), this, SLOT (gotoBonScherm()));
    }

}


//test Q string omzetten naar const char (kan nog wel is handig zijn)
//    QString tekst = gebruikDatabase->teruggave();
//    QByteArray omzetArray = tekst.toLocal8Bit();
//    const char *tekstChar = omzetArray.data();
//    buttonContent(bon_hoofd_button, tr(tekstChar));



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
    pageId = idx;
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
        if(gebruikDatabase->checkGeblokkeerd())
        {
            //melding pas geblokkeerd

            //errorMethod();
        }
        else
        {
            createInlogScherm();
            changeATMPage(1);
            QLabel *label = new QLabel(this);
            label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
            label->setText("first line\nsecond line");
            label->setAlignment(Qt::AlignTop | Qt::AlignLeft);



        }
    }

    void Login:: createInlogScherm()
    {
        inputBox_2->clear();
        buttonContent(inlog_taal_button, tr("languages"));
        buttonContent(inlog_welkom_button, tr("abort"));
        buttonContent(inlog_hoofd_button, tr("confirm"));
    }


    //----------------------------------------------------------------------------

    void Login::gotoHoofdScherm()
    {
        createHoofdScherm();
        changeATMPage(2);
    }

    void Login:: createHoofdScherm()
    {

        //hoofd_taal_button, hoofd_saldo_button, hoofd_welkom_button, hoofd_pinKeuze_button
        buttonContent(oneButton_3, tr("[1] balance"));
        buttonContent(hoofd_taal_button, tr("languages"));
        buttonContent(hoofd_saldo_button, tr("balance"));
        buttonContent(hoofd_snelPinnen_button, tr("get snel pinnen"));
        buttonContent(hoofd_welkom_button, tr("abort"));
        buttonContent(Cbutton_3, tr("Withdraw money"));
        createSnelPinnenButton();
    }

    void Login::createSnelPinnenButton()
    {
        if (checkBalance(70.00) == true)
        {
            buttonContent(hoofd_snelPinnen_button, "€70,-");
            hoofd_snelPinnen_button -> show();
            buttonContent(Bbutton_3, "[B] €70,-");
        }
        else
        {
            hoofd_snelPinnen_button -> hide();
            buttonContent(Bbutton_3, "[B]");
        }
        //get last 10 transaction amounts pick the one that is pinned the most
        //if multiple amounts have the same amount use the last 9 etc.. until you get it right
        //if it is more that the users balance use the highest possible transaction
    }

    //----------------------------------------------------------------------------------

    void Login::gotoPinKeuzeScherm()
    {
        createPinKeuzeScherm();
        changeATMPage(3);
    }

    void Login:: createPinKeuzeScherm()
    {
        buttonContent(pinKeuze_hoofd_button, tr("main page"));
        buttonContent(pinKeuze_welkom_button, tr("abort"));
        buttonContent(pinKeuze_zelfBedragKiezen_button, tr("pick own amount"));
        buttonContent(Abutton_4, tr("other"));
        oneButton_4 -> hide();
        fourButton_4->hide();
        sevenButton_4 -> hide();
        Bbutton_4 -> hide();
        Cbutton_4 -> hide();

        if(checkBalance(pinOptionOne) == true)
        {
            oneButton_4 -> show();
            buttonContent(oneButton_4, "€ " +QString::number(pinOptionOne));
            noteOptions(pinOptionOne);
        }

        if(checkBalance(pinOptionTwo) == true)
        {
            fourButton_4 -> show();
            buttonContent(fourButton_4, "€ " +QString::number(pinOptionTwo));
            noteOptions(pinOptionTwo);
        }

        if(checkBalance(pinOptionThree) == true)
        {
            sevenButton_4 -> show();
            buttonContent(sevenButton_4, "€ " +QString::number(pinOptionThree));
            noteOptions(pinOptionThree);
        }


        if(checkBalance(pinOptionFour) == true)
        {
            Bbutton_4 -> show();
            buttonContent(Bbutton_4, "€ " +QString::number(pinOptionFour));
            noteOptions(pinOptionFour);
        }

        if(checkBalance(pinOptionFive) == true)
        {
            Cbutton_4 -> show();
            buttonContent(Cbutton_4, "€ " +QString::number(pinOptionFive));
            noteOptions(pinOptionFive);
        }

        //get balance
        //make 5 different buttons with 5 different values
        //check if the user has enough balance for each individual value
        //if not hide the button option (keypad input shouldn't work either)
    }


    //------------------------------------------------------------------------------
    /*void Login::gotoBiljetScherm(float withdrawAmount)
    {
        createBiljetKeuzeScherm(withdrawAmount);
        changeATMPage(5);
    }
    /*void Login::gotoBiljetScherm()
    {
        changeATMPage(5);
    }*/

    void Login::createBiljetKeuzeScherm(float withdrawAmount)
    {
        labelContent(textTwo_6, QString::number(withdrawAmount));
        gotoBonScherm();
    }


    //------------------------------------------------------------------------------------------

    void Login::gotoBedragScherm()
    {
        createBedragScherm();
        changeATMPage(4);
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
        changeATMPage(5);
    }

    void Login:: createBonScherm()
    {
        labelContent(textTwo_6, QString::number(pinOptionOne));
        buttonContent(bon_hoofd_button, tr("Main page"));
        buttonContent(bon_metBon_button, tr("yes"));
        buttonContent(bon_zonderBon_button, tr("no"));
        buttonContent(bon_welkom_button, tr("abort"));
    }

    //-----------------------------------------------------------------------------------------------

    void Login::gotoVerwerkingsScherm()
    {
        changeATMPage(6);
                                    //the money is being reserved on a special account before the confirmation is sent
    }

    void Login:: createVerwerkingsScherm()
    {

    }

    void Login::gotoSaldoScherm()
    {
        createSaldoScherm();
        //changeATMPage(4);
        //ATM->update();
        //changeATMPage(2);
    }

    void Login:: createSaldoScherm()
    {
        isDutch = false;
        TranslateDutch();
        buttonContent(saldo_welkom_button, tr("abort"));
        buttonContent(saldo_pinKeuze_button, tr("choose amount"));
        buttonContent(saldo_hoofdscherm_button, tr("main page"));
        labelContent(textTwo_3, "Uw saldo = : €" +getBalanceString());

        //get saldo and display on GUI
        //labelContent(saldo_label_wat_is_saldo);
    }

//###########################ARDUINO################################################################


void Login::returnCard()
{
    //signal to arduino to return card
}

void Login::readArduino()
{
    if (arduino->isOpen())
    {
        qDebug() << "arduino is open";
        arduino->waitForReadyRead(100);
        const QByteArray dataRead = arduino->readAll();
        qDebug() << dataRead;
        qDebug() << dataRead.size();
        if(dataRead.size() <= 4)
        {
            QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
            QString DataAsString = codec->toUnicode(dataRead);
            qDebug() << "verzonden";
            DataAsString.resize(1);
            qDebug() << DataAsString;
            DataAsString.push_front("0x");
            qDebug() << DataAsString;
            bool ok;
            uint appId = DataAsString.toUInt(&ok, 16);
            qDebug() << ok;
            //int i = DataAsString.toInt();
            //goToPage(DataAsString);
            qDebug() << appId;
            keyInput(ATM->currentIndex(), appId);
        }
        else
        {
           qDebug() << "bigger";
        }

    }
}

void Login::keyInput(int idx, int key) //idx is the current page idx, key is the input key
{
    //check for text field or button field
    if(notes == true)
    {
        switch(key)
        {
            case 1:
                gotoBonScherm();
                notes = false;
            break;

            case 2:
                gotoBonScherm();
                notes = false;
            break;

            case 12:
                //gotoPinKeuzeScherm();
                oneButtonSide-> hide();
                twoButtonSide-> hide();
                threeButtonSide-> hide();
                fourButtonSide-> hide();
                fiveButtonSide-> hide();
                notes = false;
            break;

        }
    }
    else
    {
        if(key > 9 && key < 14)//'#'
            {
                Login::specialKeys(idx, key);
                return;
            }
        if((idx == 1) && (key >= 0 && key <= 9))
        {
            QString s = QString::number(key);
            inputBox_2->insert(s);
            return;
        }
        if((idx==1) && (key == 12))
        {
            inputBox_2->del();
        }
        if((idx == 3) && (key >= 0 && key <= 9))
        {
            QString s = QString::number(key);
            inputBox_4->insert(s);
            return;
        }
        if((idx==3) && (key == 12))
        {
            inputBox_4->del();
        }
        if (idx == 0 && key == 1)
        {
            gotoInlogScherm();
            return;
        }
        if (idx == 3 && key == 1)
        {
            labelContent(textTwo_3, "Uw saldo = : €" +getBalanceString());
        }
        if (idx == 3 && key == 14)
        {
            //chec
            buttonContent(Bbutton_3, "Uw saldo = : €" +getBalanceString());
        }

            if(key == 1 || key == 4 || key == 7 || (key > 13 && key < 16))
            {
                if(idx == 0 && key == 1)
                {
                    gotoInlogScherm();
                }
                if(idx == 2)
                {
                    switch(key)
                    {
                        case 1:
                            labelContent(textTwo_3, "Uw saldo = : €" +getBalanceString());
                        break;

                        case 14:
                            gotoBonScherm();
                        break;

                        case 15:
                            gotoPinKeuzeScherm();
                        break;

                        default:

                        break;
                    }
                }
                if(idx == 3 && (key == 1 || key == 4 || key == 7|| key == 14|| key == 15))
                {

                    //gotoBonScherm();
                    switch(key)
                    {
                        case 1:
                            if (checkBalance(pinOptionOne) == true)
                            {
                                noteOptions(pinOptionOne);
                            }
                            buttonContent(oneButton_4, "€ " +QString::number(pinOptionOne));
                        break;

                        case 4:
                            if (checkBalance(pinOptionTwo) == true)
                            {
                                noteOptions(pinOptionTwo);
                            }
                            buttonContent(fourButton_4, "€ " +QString::number(pinOptionTwo));
                        break;

                        case 7:
                            if (checkBalance(pinOptionThree) == true)
                            {
                                noteOptions(pinOptionThree);
                            }
                            buttonContent(sevenButton_4, "€ " +QString::number(pinOptionThree));
                        break;

                        case 14:
                            if (checkBalance(pinOptionFour) == true)
                            {
                                noteOptions(pinOptionFour);
                            }
                            buttonContent(Bbutton_4, "€ " +QString::number(pinOptionFour));
                        break;

                        case 15:
                            if (checkBalance(pinOptionFive) == true)
                            {
                                noteOptions(pinOptionFive);
                            }
                            buttonContent(Cbutton_4, "€ " +QString::number(pinOptionFive));
                        break;

                        default:

                        break;
                    }
                }



            }

    }
}


void Login::specialKeys(int idx, int key)
{
    if(key == 10)
    {
        endSession();
        return;
    }
    if(key == 11)
    {
        if(idx == 1)
        {
            loginAttempt();
            return;
        }
        else if(idx == 3)
        {
            confirmWithdrawAmount();
            return;
        }
        return;

    }
    else if(key == 12)
    {
        if(idx >= 3)
        {
            gotoHoofdScherm();
            return;
        }

        else if(idx < 3)
        {
            return;
        }
        return;
    }
    else if(key == 13)
    {
        if(idx == 3)
        {
            gotoPinKeuzeScherm();
            return;
        }
        return;
    }
}

void Login::noteOptions(int amountWithdraw)
{


     int twentyNotes;
     int tenNotes;
     int fiftyNotes;


     if (amountWithdraw%20==0)
     {
         twentyNotes = amountWithdraw/20;
     }
     else
     {
         twentyNotes = (amountWithdraw-10)/20;
     }
     tenNotes = amountWithdraw/10;
     if(amountWithdraw%50 == 0 )
     {
         fiftyNotes = amountWithdraw/50;
     }
     else
     {
         fiftyNotes = (amountWithdraw-(fiftyNotes%50)/50);
     }

     if(gebruikDatabase->get20BriefgeldAantal()>twentyNotes)
     {
        if(amountWithdraw%2==0)
        {
            buttonContent(oneButtonSide, "[1] €20*" +QString::number(twentyNotes));
            oneButtonSide->show();
        }
        else
        {
            buttonContent(twoButtonSide, "[1] €10*1 €20*" +QString::number(twentyNotes));
            oneButtonSide->show();
        }
     }
     else
     {
          buttonContent(oneButtonSide, "[1] €20*" +QString::number(twentyNotes)+"€10*"+QString::number((amountWithdraw-20*twentyNotes)/10));
          oneButtonSide->show();

     }
     if(gebruikDatabase->get50BriefgeldAantal()>fiftyNotes)
     {
         if(fiftyNotes>1)
         {
             buttonContent(twoButtonSide, "[2] €50*" +QString::number(fiftyNotes) +"€10*" +QString::number((amountWithdraw-50*fiftyNotes)/10));
             twoButtonSide->show();
         }
         else
         {
             buttonContent(twoButtonSide, "[2] €10*" +QString::number(tenNotes));
             twoButtonSide->show();
         }
     }
     else
     {
         buttonContent(oneButtonSide, "[1] €50*" +QString::number(fiftyNotes)+"€10*"+QString::number((amountWithdraw-50*fiftyNotes)/10));
         twoButtonSide->show();

     }

     if(gebruikDatabase->get10BriefgeldAantal()>tenNotes)
     {
          buttonContent(threeButtonSide, "[2] €10*" +QString::number(tenNotes));
     }

     notes = true;
     return;





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
    gebruikDatabase->checkGebruikersId();
    gebruikDatabase->sessieStart();     //Data newSession;
    //newSession.getBalanceString();
    //connect to database
    //check if card is at our bank
    //check if card is at other bank
    //check if blocked
}

//----------------------------------------------------------------------------------------------------------

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
        if(gebruikDatabase->checkGeblokkeerd() == false)
        {
            createInlogScherm();
        }
        else
        {
            returnCard();
            //your card is blocked message
            endSession();
        }
    }

}
//-------------------------------------------------------------------------------------------

bool Login::verifyPincode()
{
    if(gebruikDatabase->checkPassword(inputBox_2->text()))
    {
        gebruikDatabase->pogingReset();
        inputBox_2->clear();
        return true;
    }
    else
    {
        gebruikDatabase->pogingOmhoog();
        inputBox_2->clear();
        if(gebruikDatabase->checkPogingen() >= 3)
        {
            gebruikDatabase->blokeerPas();
        }
        return false;
    }
}

void Login::backspacepin()
{
    inputBox_2->backspace();
}
void Login::backspacebedrag()
{
    inputBox_4->backspace();
}

//#####################TRANSLATIONS########################################################

void Login::TranslateDutch()
{
    QTranslator translator;
    if (isDutch)
    {
        translator.load("bank_en_nl.qm", "");
        qApp->installTranslator(&translator);
        isDutch = true;
    }
    else
    {
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

QString const Login::getBalanceString()
{
    QString bal;
    bal.setNum(gebruikDatabase->getBalance());
    return bal;
}

bool Login::fastPin()
{
    if(checkBalance(70.00))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Login::checkBalance(float checkBal)
{
    if(gebruikDatabase->getBalance() >= checkBal)
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


    int amount = (inputBox_5->text()).toInt();
    if(amount%10==0 && checkBalance(amount) == true)
    {
        inputBox_5->clear();
        noteOptions(amount);
        //gotoBonScherm();
    }
    else
    {
        if(amount%10!=0)
        {
            //wrongMult = true;
            QString wrongMulti = QString(tr("wrong multiplier"));
        }
        if(checkBalance(amount) != true)
        {
            //notEnoughBalance = true;
            QString notEnoughBalances = QString(tr("not enough balance"));

        }
        QString errorMessage = QString(tr("Error: %1 and %2")).arg(wrongMult).arg(notEnoughBalance);
        labelContent(textTwo_5, errorMessage);
        return;
    }

}


/*void Login::errorMethod(int error, QLabel *errorLabel)
{
    switch(error)
    {
        case 1:
            labelContent(errorLabel, tr(("Neem kaart uit, de kaart is geblokkeerd.")));
            break;
        case 2:
            labelContent(errorLabel, tr(("Foute pincode: nog 2 pogingen.")));
            break;
        case 3:
            labelContent(errorLabel, tr(("Foute pincode: nog 1 poging.")));
            break;
        case 4:
            labelContent(errorLabel, tr(("3 foute pogingen, pas geblokkeerd.")));
            break;
        case 5:
            labelContent(errorLabel, tr(("U heeft niet voldoende saldo.")));
            break;
        case 6:
            labelContent(errorLabel, tr(("Onbekende error, neem contact op met de bank.")));
            break;
        case 7:
            labelContent(errorLabel, tr(("Vul A.U.B een veelvoud in van 10")));
            break;
        case 8:
            labelContent(errorLabel, tr(("next error")));
            break;
        default:
            break;
    }
    return;
}
*/
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

//-----------------------------------------------------------------------------

/*
void Login::gotoSaldoScherm()
{
    createSaldoScherm();
    //changeATMPage(4);
    //ATM->update();
    //changeATMPage(2);
}

void Login:: createSaldoScherm()
{
    isDutch = false;
    TranslateDutch();
    buttonContent(saldo_welkom_button, tr("abort"));
    buttonContent(saldo_pinKeuze_button, tr("choose amount"));
    buttonContent(saldo_hoofdscherm_button, tr("main page"));
    labelContent(textTwo_3, "Uw saldo = : €" +getBalanceString());

    //get saldo and display on GUI
    //labelContent(saldo_label_wat_is_saldo);
}

*/
