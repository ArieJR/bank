#ifndef LOGIN_H
#define LOGIN_H

//! [0]
#include "ui_login.h"
//! [0]

//! [1]
class Login : public QWidget, private Ui::Login
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

private slots:

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
    void goBack();

private:


};
//! [1]

#endif

