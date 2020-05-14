#include "login.h"
#include <qtranslator.h>
//#include "data.h"
#include <QApplication>
//#include <QSerialPort>


//! [0]
int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    //QT_AUTO_SCREEN_SCALE_FACTOR=1 ./app

    //QTranslator translator;
    //translator.load("bank_en_nl.qph", "../translations");
    //app.installTranslator(&translator);
    Login start;
    start.gotoWelkomScherm();
    start.show();

    return app.exec();
}
