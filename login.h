#ifndef LOGIN_H
#define LOGIN_H

#include <QTranslator>
#include "ui_login.h"
#include "data.h"

#include <src\sio_client.h>


class Login : public QWidget, private Ui::Login
{
    Q_OBJECT
protected:
    

protected slots:
    
public:
    explicit Login(QWidget *parent = nullptr);
    QString test;
    QString input;

private:



    bool checkIfSession();
    int previousIndex;
    void endSession();
    void createSession();
    void cardBlocked();
    void returnCard();
    void createWelkomScherm();
    void createTaalScherm();
    void buttonContent(QPushButton* textOfButton, const QString &newButtonContent);
    void createInlogScherm();
    bool verifyPincode();
    void resetLoginAttempts();
    void increaseLoginAttempts();
    void wrongPassword();
    void wrongPwMsg();
    void createHoofdScherm();
    void createSnelPinnenButton();
    bool reserveMoney();
    bool returnReservedMoney();
    void afbreken();
    bool checkIfBlocked();
    void loginAttempt();

    void createSaldoScherm();
    void createPinKeuzeScherm();
    void knopBedrag();
    void enoughBalance();
    void createBedragScherm();
    void createBiljetKeuzeScherm();
    void doesntmatter();
    void createBonScherm();
    void createVerwerkingsScherm();

private slots:

    void inputSend();

    void gotoWelkomScherm(); //0
    void gotoInlogScherm(); //1
    void gotoTaalScherm(); //2
    void gotoHoofdScherm(); //3
    void gotoSaldoScherm(); //4
    void gotoPinKeuzeScherm(); //5
    void gotoBiljetScherm(); //6
    void gotoBedragScherm(); //7
    void gotoBonScherm(); //8
    void gotoVerwerkingsScherm(); //9
    void gotoPreviousPage();
    int getPreviousIndex();
    void setPreviousIndex(int idx);
    void changeLabel(QLabel* labelToChange, const QString &newLabelContent);
    void changeATMPage(int idx);



};
//! [1]

#endif

