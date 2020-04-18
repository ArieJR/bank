#include "login.h"
#include <qtranslator.h>
//#include "data.h"
#include <QApplication>
//#include <QSerialPort>


//! [0]
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QTranslator translator;
    //translator.load("bank_en_nl.qph", "../translations");
    //app.installTranslator(&translator);
    Login start;
    start.show();
    return app.exec();
}
