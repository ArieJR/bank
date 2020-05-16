#ifndef LOGIN_H
#define LOGIN_H

#include <QTranslator>
#include "ui_login.h"

class database;     //inti test

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


private:

    Ui::Login *ui;

    bool checkIfSession();
    int previousIndex= 0;
    void createSession();
    void cardBlocked();
    void returnCard();
    void createWelkomScherm();
    void createTaalScherm();
    void buttonContent(QPushButton* textOfButton, const QString &newButtonContent);
    void createInlogScherm();
    void resetLoginAttempts();
    void increaseLoginAttempts();
    void wrongPassword();
    void wrongPwMsg();
    void createHoofdScherm();
    void createSnelPinnenButton();
    bool reserveMoney();
    bool returnReservedMoney();
    void afbreken();
    QString const getBalanceString();
    void createSaldoScherm();
    void createPinKeuzeScherm();
    void knopBedrag();
    void enoughBalance();
    void createBedragScherm();
    void createBiljetKeuzeScherm(int withdrawAmount);
    void doesntmatter();
    void createBonScherm();
    void createVerwerkingsScherm();
    bool verifyPincode();
    bool fastPin();
    bool checkBalance(float checkBal);
    bool isDutch = true;

    void createTestScherm();  //inti test

    database *gebruikDatabase;

private slots:

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

    void gotoTestScherm(); //inti test

public slots:
    void gotoWelkomScherm(); //0


};
//! [1]

#endif
/*class Session: public Login
{
public:
    void startSession();
};*/
