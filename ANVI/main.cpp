//import QtQuick 2.0

#include "login.h"
#include <qtranslator.h>
#include <QApplication>
//#include <QSerialPort>
#include <QtQuick/QQuickItem>
#include <QtQml/QQmlComponent>


//! [0]
int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);

    QApplication app(argc, argv);
    //QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    //QT_AUTO_SCREEN_SCALE_FACTOR=1 ./app

    //QTranslator translator;
    //translator.load("bank_en_nl.qph", "../translations");
    //app.installTranslator(&translator);
    Login start;
    start.gotoWelkomScherm();
    start.show();

    return app.exec();
}
