/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QStackedWidget *stackedWidget;
    QWidget *inlogWelkom;
    QPushButton *languageSettingsButtonBeforeLoggedIn;
    QLabel *label;
    QWidget *inlogPin;
    QLabel *label_4;
    QPlainTextEdit *invoerveldPincode;
    QPushButton *languageSettingsButtonBeforeLoggedIn_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 381, 281));
        stackedWidget->setAutoFillBackground(true);
        stackedWidget->setFrameShape(QFrame::Panel);
        inlogWelkom = new QWidget();
        inlogWelkom->setObjectName(QString::fromUtf8("inlogWelkom"));
        languageSettingsButtonBeforeLoggedIn = new QPushButton(inlogWelkom);
        languageSettingsButtonBeforeLoggedIn->setObjectName(QString::fromUtf8("languageSettingsButtonBeforeLoggedIn"));
        languageSettingsButtonBeforeLoggedIn->setGeometry(QRect(264, 10, 101, 41));
        label = new QLabel(inlogWelkom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 120, 91, 31));
        stackedWidget->addWidget(inlogWelkom);
        inlogPin = new QWidget();
        inlogPin->setObjectName(QString::fromUtf8("inlogPin"));
        label_4 = new QLabel(inlogPin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 170, 91, 31));
        invoerveldPincode = new QPlainTextEdit(inlogPin);
        invoerveldPincode->setObjectName(QString::fromUtf8("invoerveldPincode"));
        invoerveldPincode->setGeometry(QRect(130, 220, 104, 31));
        languageSettingsButtonBeforeLoggedIn_2 = new QPushButton(inlogPin);
        languageSettingsButtonBeforeLoggedIn_2->setObjectName(QString::fromUtf8("languageSettingsButtonBeforeLoggedIn_2"));
        languageSettingsButtonBeforeLoggedIn_2->setGeometry(QRect(270, 20, 101, 41));
        pushButton = new QPushButton(inlogPin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 210, 75, 23));
        pushButton_4 = new QPushButton(inlogPin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(290, 240, 75, 23));
        stackedWidget->addWidget(inlogPin);

        retranslateUi(Login);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        languageSettingsButtonBeforeLoggedIn->setText(QCoreApplication::translate("Login", "[language settings]", nullptr));
        label->setText(QCoreApplication::translate("Login", "welkom \n"
" voer uw pas in", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "Voer uw pincode in", nullptr));
        languageSettingsButtonBeforeLoggedIn_2->setText(QCoreApplication::translate("Login", "[language settings]", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "Doorgaan", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
