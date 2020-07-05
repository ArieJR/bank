#ifndef LOGIN_H
#define LOGIN_H
#include <QtQuick/QQuickItem>
#include <QTranslator>
#include "ui_login.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtSerialPort/qserialport.h>
#include <com.h>
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
    //Q_INVOKABLE void sendMessage(const QString &msg, QQuickItem *textArea);

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
    //void errorMethod(int error, QLabel *errorLabel);

private:


    Ui::Login *ui;
    float pinOptionOne = 20;
    float pinOptionTwo = 50;
    float pinOptionThree = 80;
    float pinOptionFour = 120;
    float pinOptionFive = 180;
    bool checkIfSession();
    void createSession();
    bool notes = false;
    int previousIndex= 0;

    bool textField = false;
    bool buttonField = false;


    void cardBlocked();
    void returnCard();

    void keyInput(int idx, int key);
    void makeButtonField(int idxPage, int idxButton, QString setText);
    void makeTextField(int idxPage, int idxButton, QString setText);
    void specialKeys(int idx, int key);

    void createWelkomScherm();
    void createTaalScherm();
    void createInlogScherm();
    void resetLoginAttempts();
    void createHoofdScherm();
    void createSnelPinnenButton();
    void createSaldoScherm();
    void createPinKeuzeScherm();
    void createBedragScherm();
    void createBiljetKeuzeScherm(float withdrawAmount);
    void createBonScherm();
    void createVerwerkingsScherm();
    void noteOptions(int amountWithdraw);
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

    void getTime();
    void bonPrint();
    void geldGeven();
    
    bool pasInAutomaat = false;

    void buttonContent(QPushButton* textOfButton, const QString &newButtonContent);


    //serial *gebruikSerial;     // HIER
    database *gebruikDatabase;
    QQmlEngine *engine;
    com *communicatie;

private slots:
//--------------------------
    void readArduino();


//--------------------------
    void loginAttempt();
    void endSession();
    void confirmWithdrawAmount();
    void backspacepin();
    void backspacebedrag();
    void gotoInlogScherm(); //1
    void gotoTaalScherm(); //2
    void gotoHoofdScherm(); //3
    void gotoSaldoScherm(); //4
    void gotoPinKeuzeScherm(); //5
    //void gotoBiljetScherm(float withdrawAmount); //6
    //void gotoBiljetScherm();
    void gotoBedragScherm(); //7
    void gotoBonScherm(); //8
    void gotoVerwerkingsScherm(); //9
    void gotoPreviousPage();
    int getPreviousIndex();
    void setPreviousIndex(int idx);

    void labelContent(QLabel* labelToChange, const QString &newLabelContent);

    void changeATMPage(int idx);

    //void errorMethod();

public slots:
    void gotoWelkomScherm(); //0


};
//! [1]

#endif
