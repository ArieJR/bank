#ifndef LOGIN_H
#define LOGIN_H

#include <QTranslator>
#include "ui_login.h"
#include "data.h"

class Login : public QWidget, private Ui::Login
{
    Q_OBJECT
protected:
    

protected slots:
    
public:
    explicit Login(QWidget *parent = nullptr);


private:
    int previousIndex;

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
    void gotoPreviousPage();
    int getPreviousIndex();
    void setPreviousIndex(int idx);
    void pincodeCheck();
    void changeLabel(QLabel* labelToChange, const QString &newLabelContent);
    void changeATMPage(int idx);



};
//! [1]

#endif

