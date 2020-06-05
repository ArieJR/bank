#ifndef LOGIN_H
#define LOGIN_H

#include <QTranslator>
#include "ui_login.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtSerialPort/qserialport.h>
//#include <QtSerialPort/qserialportinfo.h>

class database;     //inti test
//class serial;       //HIER

class Login : public QWidget, private Ui::Login
{
    Q_OBJECT
protected:


protected slots:

public:
    explicit Login(QWidget *parent = nullptr);
    void doReTranslate();

public slots:
    void TranslateDutch();

public:
    //serial dingen
    //moet nog private
    //static const quint16 arduinoVendorId = 6790;
    //static const quint16 arduinoProductId = 29987;
    //bool arduinoAvailable = false;
    //QString arduinoName;
    QSerialPort *arduino;

    void goToPage(QString command);
    int pageId = 0;
    void sendToArduino(QString command);        //<<===
    void getTime();
    void bonPrint();
    void geldGeven();
private:

    Ui::Login *ui;

    bool checkIfSession();
    void createSession();

    int previousIndex= 0;

    void cardBlocked();
    void returnCard();

    void createWelkomScherm();
    void createTaalScherm();
    void createInlogScherm();
    void resetLoginAttempts();
    void createHoofdScherm();
    void createSnelPinnenButton();
    void createSaldoScherm();
    void createPinKeuzeScherm();
    void createBedragScherm();
    void createBiljetKeuzeScherm(int withdrawAmount);
    void createBonScherm();
    void createVerwerkingsScherm();

    void increaseLoginAttempts();

    void wrongPassword();
    void wrongPwMsg();

    bool reserveMoney();
    bool returnReservedMoney();
    void afbreken();
    QString const getBalanceString();
    void knopBedrag();
    void enoughBalance();
    void doesntmatter();
    bool verifyPincode();
    bool fastPin();
    bool checkBalance(float checkBal);
    bool isDutch = true;

    void buttonContent(QPushButton* textOfButton, const QString &newButtonContent);


    //serial *gebruikSerial;     // HIER
    database *gebruikDatabase;

private slots:
//--------------------------
    void readArduino();


//--------------------------
    void loginAttempt();
    void endSession();
    void confirmWithdrawAmount();

    void gotoInlogScherm(); //1
    void gotoTaalScherm(); //2
    void gotoHoofdScherm(); //3
    void gotoSaldoScherm(); //4
    void gotoPinKeuzeScherm(); //5
    void gotoBiljetScherm(int withdrawAmount); //6
    void gotoBiljetScherm();
    void gotoBedragScherm(); //7
    void gotoBonScherm(); //8
    void gotoVerwerkingsScherm(); //9

    void gotoPreviousPage();
    int getPreviousIndex();
    void setPreviousIndex(int idx);

    void labelContent(QLabel* labelToChange, const QString &newLabelContent);

    void changeATMPage(int idx);

    void errorMethod();

public slots:
    void gotoWelkomScherm(); //0


};
//! [1]

#endif
