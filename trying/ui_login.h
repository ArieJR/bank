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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QStackedWidget *ATM;
    QWidget *welkomScherm;
    QPushButton *welkom_taal_button;
    QLabel *welkom_label;
    QPushButton *welkom_inlog_button;
    QWidget *inlogScherm;
    QLabel *label_4;
    QPushButton *inlog_taal_button;
    QPushButton *inlog_hoofd_button;
    QPushButton *inlog_welkom_button;
    QLabel *label_9;
    QLineEdit *inlog_invoerveldPincode;
    QWidget *taalScherm;
    QPushButton *taal_optieNederlands_button;
    QPushButton *taal_optieEngels_button;
    QPushButton *taal_optieDuits_button;
    QPushButton *taal_welkom_button;
    QPushButton *taal_hoofd_of_welkom_of_inlog_button;
    QWidget *hoofdScherm;
    QLabel *label_2;
    QPushButton *hoofd_snelPinnen_button;
    QPushButton *hoofd_saldo_button;
    QPushButton *hoofd_pinKeuze_button;
    QPushButton *hoofd_taal_button;
    QPushButton *hoofd_welkom_button;
    QWidget *saldoScherm;
    QLabel *label_3;
    QPushButton *saldo_pinKeuze_button;
    QPushButton *saldo_welkom_button;
    QPushButton *saldo_hoofdscherm_button;
    QLabel *saldo_label;
    QWidget *pinKeuzeScherm;
    QLabel *Labelpinnen;
    QPushButton *pinKeuze_optie1_button;
    QPushButton *pinKeuze_optie2_button;
    QPushButton *pinKeuze_optie3_button;
    QPushButton *pinKeuze_optie4_button;
    QPushButton *pinKeuze_optie5_button;
    QPushButton *pinKeuze_zelfBedragKiezen_button;
    QPushButton *pinKeuze_welkom_button;
    QPushButton *pinKeuze_hoofd_button;
    QWidget *biljetScherm;
    QLabel *label_5;
    QPushButton *biljetKeuze_welkom_button;
    QPushButton *biljetKeuze_hoofd_button;
    QPushButton *biljetKeuze_biljetNietBelangrijk_button;
    QPushButton *biljetKeuze_biljetOpties1_button;
    QWidget *bedragScherm;
    QLabel *label_6;
    QPushButton *bedragKeuze_hoofd_button;
    QPushButton *bedragKeuze_welkom_button;
    QPushButton *bedragKeuze_bevestigen_button;
    QWidget *bonScherm;
    QLabel *label_7;
    QPushButton *bon_metBon_button;
    QPushButton *bon_zonderBon_button;
    QPushButton *bon_hoofd_button;
    QPushButton *bon_welkom_button;
    QWidget *verwerkingsScherm;
    QLabel *label_8;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        ATM = new QStackedWidget(Login);
        ATM->setObjectName(QString::fromUtf8("ATM"));
        ATM->setGeometry(QRect(10, 10, 381, 281));
        ATM->setAutoFillBackground(true);
        ATM->setFrameShape(QFrame::Panel);
        welkomScherm = new QWidget();
        welkomScherm->setObjectName(QString::fromUtf8("welkomScherm"));
        welkom_taal_button = new QPushButton(welkomScherm);
        welkom_taal_button->setObjectName(QString::fromUtf8("welkom_taal_button"));
        welkom_taal_button->setGeometry(QRect(264, 10, 101, 41));
        welkom_label = new QLabel(welkomScherm);
        welkom_label->setObjectName(QString::fromUtf8("welkom_label"));
        welkom_label->setGeometry(QRect(140, 120, 91, 31));
        welkom_inlog_button = new QPushButton(welkomScherm);
        welkom_inlog_button->setObjectName(QString::fromUtf8("welkom_inlog_button"));
        welkom_inlog_button->setGeometry(QRect(214, 220, 121, 23));
        ATM->addWidget(welkomScherm);
        inlogScherm = new QWidget();
        inlogScherm->setObjectName(QString::fromUtf8("inlogScherm"));
        label_4 = new QLabel(inlogScherm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 80, 91, 31));
        inlog_taal_button = new QPushButton(inlogScherm);
        inlog_taal_button->setObjectName(QString::fromUtf8("inlog_taal_button"));
        inlog_taal_button->setGeometry(QRect(270, 20, 101, 41));
        inlog_hoofd_button = new QPushButton(inlogScherm);
        inlog_hoofd_button->setObjectName(QString::fromUtf8("inlog_hoofd_button"));
        inlog_hoofd_button->setGeometry(QRect(290, 210, 75, 23));
        inlog_welkom_button = new QPushButton(inlogScherm);
        inlog_welkom_button->setObjectName(QString::fromUtf8("inlog_welkom_button"));
        inlog_welkom_button->setGeometry(QRect(290, 240, 75, 23));
        label_9 = new QLabel(inlogScherm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(150, 230, 47, 13));
        inlog_invoerveldPincode = new QLineEdit(inlogScherm);
        inlog_invoerveldPincode->setObjectName(QString::fromUtf8("inlog_invoerveldPincode"));
        inlog_invoerveldPincode->setGeometry(QRect(120, 180, 113, 20));
        inlog_invoerveldPincode->setEchoMode(QLineEdit::Password);
        ATM->addWidget(inlogScherm);
        taalScherm = new QWidget();
        taalScherm->setObjectName(QString::fromUtf8("taalScherm"));
        taalScherm->setEnabled(true);
        taal_optieNederlands_button = new QPushButton(taalScherm);
        taal_optieNederlands_button->setObjectName(QString::fromUtf8("taal_optieNederlands_button"));
        taal_optieNederlands_button->setGeometry(QRect(290, 10, 75, 23));
        taal_optieEngels_button = new QPushButton(taalScherm);
        taal_optieEngels_button->setObjectName(QString::fromUtf8("taal_optieEngels_button"));
        taal_optieEngels_button->setGeometry(QRect(290, 40, 75, 23));
        taal_optieDuits_button = new QPushButton(taalScherm);
        taal_optieDuits_button->setObjectName(QString::fromUtf8("taal_optieDuits_button"));
        taal_optieDuits_button->setGeometry(QRect(290, 70, 75, 23));
        taal_welkom_button = new QPushButton(taalScherm);
        taal_welkom_button->setObjectName(QString::fromUtf8("taal_welkom_button"));
        taal_welkom_button->setGeometry(QRect(10, 240, 75, 23));
        taal_hoofd_of_welkom_of_inlog_button = new QPushButton(taalScherm);
        taal_hoofd_of_welkom_of_inlog_button->setObjectName(QString::fromUtf8("taal_hoofd_of_welkom_of_inlog_button"));
        taal_hoofd_of_welkom_of_inlog_button->setGeometry(QRect(10, 210, 75, 23));
        ATM->addWidget(taalScherm);
        hoofdScherm = new QWidget();
        hoofdScherm->setObjectName(QString::fromUtf8("hoofdScherm"));
        label_2 = new QLabel(hoofdScherm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 90, 71, 20));
        hoofd_snelPinnen_button = new QPushButton(hoofdScherm);
        hoofd_snelPinnen_button->setObjectName(QString::fromUtf8("hoofd_snelPinnen_button"));
        hoofd_snelPinnen_button->setGeometry(QRect(10, 70, 75, 23));
        hoofd_saldo_button = new QPushButton(hoofdScherm);
        hoofd_saldo_button->setObjectName(QString::fromUtf8("hoofd_saldo_button"));
        hoofd_saldo_button->setGeometry(QRect(10, 110, 75, 23));
        hoofd_pinKeuze_button = new QPushButton(hoofdScherm);
        hoofd_pinKeuze_button->setObjectName(QString::fromUtf8("hoofd_pinKeuze_button"));
        hoofd_pinKeuze_button->setGeometry(QRect(10, 160, 75, 23));
        hoofd_taal_button = new QPushButton(hoofdScherm);
        hoofd_taal_button->setObjectName(QString::fromUtf8("hoofd_taal_button"));
        hoofd_taal_button->setGeometry(QRect(290, 70, 75, 23));
        hoofd_welkom_button = new QPushButton(hoofdScherm);
        hoofd_welkom_button->setObjectName(QString::fromUtf8("hoofd_welkom_button"));
        hoofd_welkom_button->setGeometry(QRect(290, 120, 75, 23));
        ATM->addWidget(hoofdScherm);
        saldoScherm = new QWidget();
        saldoScherm->setObjectName(QString::fromUtf8("saldoScherm"));
        label_3 = new QLabel(saldoScherm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 120, 81, 20));
        saldo_pinKeuze_button = new QPushButton(saldoScherm);
        saldo_pinKeuze_button->setObjectName(QString::fromUtf8("saldo_pinKeuze_button"));
        saldo_pinKeuze_button->setGeometry(QRect(20, 80, 75, 23));
        saldo_welkom_button = new QPushButton(saldoScherm);
        saldo_welkom_button->setObjectName(QString::fromUtf8("saldo_welkom_button"));
        saldo_welkom_button->setGeometry(QRect(270, 40, 75, 23));
        saldo_hoofdscherm_button = new QPushButton(saldoScherm);
        saldo_hoofdscherm_button->setObjectName(QString::fromUtf8("saldo_hoofdscherm_button"));
        saldo_hoofdscherm_button->setGeometry(QRect(260, 220, 75, 23));
        saldo_label = new QLabel(saldoScherm);
        saldo_label->setObjectName(QString::fromUtf8("saldo_label"));
        saldo_label->setGeometry(QRect(160, 160, 47, 13));
        ATM->addWidget(saldoScherm);
        pinKeuzeScherm = new QWidget();
        pinKeuzeScherm->setObjectName(QString::fromUtf8("pinKeuzeScherm"));
        Labelpinnen = new QLabel(pinKeuzeScherm);
        Labelpinnen->setObjectName(QString::fromUtf8("Labelpinnen"));
        Labelpinnen->setGeometry(QRect(160, 130, 101, 16));
        pinKeuze_optie1_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_optie1_button->setObjectName(QString::fromUtf8("pinKeuze_optie1_button"));
        pinKeuze_optie1_button->setGeometry(QRect(280, 220, 75, 23));
        pinKeuze_optie2_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_optie2_button->setObjectName(QString::fromUtf8("pinKeuze_optie2_button"));
        pinKeuze_optie2_button->setGeometry(QRect(280, 120, 75, 23));
        pinKeuze_optie3_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_optie3_button->setObjectName(QString::fromUtf8("pinKeuze_optie3_button"));
        pinKeuze_optie3_button->setGeometry(QRect(280, 170, 75, 23));
        pinKeuze_optie4_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_optie4_button->setObjectName(QString::fromUtf8("pinKeuze_optie4_button"));
        pinKeuze_optie4_button->setGeometry(QRect(280, 50, 75, 23));
        pinKeuze_optie5_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_optie5_button->setObjectName(QString::fromUtf8("pinKeuze_optie5_button"));
        pinKeuze_optie5_button->setGeometry(QRect(20, 50, 75, 23));
        pinKeuze_zelfBedragKiezen_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_zelfBedragKiezen_button->setObjectName(QString::fromUtf8("pinKeuze_zelfBedragKiezen_button"));
        pinKeuze_zelfBedragKiezen_button->setGeometry(QRect(20, 110, 75, 23));
        pinKeuze_welkom_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_welkom_button->setObjectName(QString::fromUtf8("pinKeuze_welkom_button"));
        pinKeuze_welkom_button->setGeometry(QRect(20, 170, 75, 23));
        pinKeuze_hoofd_button = new QPushButton(pinKeuzeScherm);
        pinKeuze_hoofd_button->setObjectName(QString::fromUtf8("pinKeuze_hoofd_button"));
        pinKeuze_hoofd_button->setGeometry(QRect(20, 220, 75, 23));
        ATM->addWidget(pinKeuzeScherm);
        biljetScherm = new QWidget();
        biljetScherm->setObjectName(QString::fromUtf8("biljetScherm"));
        label_5 = new QLabel(biljetScherm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(116, 140, 111, 20));
        biljetKeuze_welkom_button = new QPushButton(biljetScherm);
        biljetKeuze_welkom_button->setObjectName(QString::fromUtf8("biljetKeuze_welkom_button"));
        biljetKeuze_welkom_button->setGeometry(QRect(260, 40, 75, 23));
        biljetKeuze_hoofd_button = new QPushButton(biljetScherm);
        biljetKeuze_hoofd_button->setObjectName(QString::fromUtf8("biljetKeuze_hoofd_button"));
        biljetKeuze_hoofd_button->setGeometry(QRect(260, 100, 75, 23));
        biljetKeuze_biljetNietBelangrijk_button = new QPushButton(biljetScherm);
        biljetKeuze_biljetNietBelangrijk_button->setObjectName(QString::fromUtf8("biljetKeuze_biljetNietBelangrijk_button"));
        biljetKeuze_biljetNietBelangrijk_button->setGeometry(QRect(260, 180, 75, 23));
        biljetKeuze_biljetOpties1_button = new QPushButton(biljetScherm);
        biljetKeuze_biljetOpties1_button->setObjectName(QString::fromUtf8("biljetKeuze_biljetOpties1_button"));
        biljetKeuze_biljetOpties1_button->setGeometry(QRect(260, 140, 81, 23));
        ATM->addWidget(biljetScherm);
        bedragScherm = new QWidget();
        bedragScherm->setObjectName(QString::fromUtf8("bedragScherm"));
        label_6 = new QLabel(bedragScherm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 120, 111, 20));
        bedragKeuze_hoofd_button = new QPushButton(bedragScherm);
        bedragKeuze_hoofd_button->setObjectName(QString::fromUtf8("bedragKeuze_hoofd_button"));
        bedragKeuze_hoofd_button->setGeometry(QRect(100, 200, 75, 23));
        bedragKeuze_welkom_button = new QPushButton(bedragScherm);
        bedragKeuze_welkom_button->setObjectName(QString::fromUtf8("bedragKeuze_welkom_button"));
        bedragKeuze_welkom_button->setGeometry(QRect(280, 20, 75, 23));
        bedragKeuze_bevestigen_button = new QPushButton(bedragScherm);
        bedragKeuze_bevestigen_button->setObjectName(QString::fromUtf8("bedragKeuze_bevestigen_button"));
        bedragKeuze_bevestigen_button->setGeometry(QRect(280, 80, 75, 23));
        ATM->addWidget(bedragScherm);
        bonScherm = new QWidget();
        bonScherm->setObjectName(QString::fromUtf8("bonScherm"));
        label_7 = new QLabel(bonScherm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(156, 140, 61, 20));
        bon_metBon_button = new QPushButton(bonScherm);
        bon_metBon_button->setObjectName(QString::fromUtf8("bon_metBon_button"));
        bon_metBon_button->setGeometry(QRect(30, 70, 75, 23));
        bon_zonderBon_button = new QPushButton(bonScherm);
        bon_zonderBon_button->setObjectName(QString::fromUtf8("bon_zonderBon_button"));
        bon_zonderBon_button->setGeometry(QRect(30, 190, 75, 23));
        bon_hoofd_button = new QPushButton(bonScherm);
        bon_hoofd_button->setObjectName(QString::fromUtf8("bon_hoofd_button"));
        bon_hoofd_button->setGeometry(QRect(270, 70, 75, 23));
        bon_welkom_button = new QPushButton(bonScherm);
        bon_welkom_button->setObjectName(QString::fromUtf8("bon_welkom_button"));
        bon_welkom_button->setGeometry(QRect(280, 190, 75, 23));
        ATM->addWidget(bonScherm);
        verwerkingsScherm = new QWidget();
        verwerkingsScherm->setObjectName(QString::fromUtf8("verwerkingsScherm"));
        label_8 = new QLabel(verwerkingsScherm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(116, 140, 101, 20));
        ATM->addWidget(verwerkingsScherm);

        retranslateUi(Login);

        ATM->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        welkom_taal_button->setText(QCoreApplication::translate("Login", "[language settings]", nullptr));
        welkom_label->setText(QCoreApplication::translate("Login", "welkom \n"
" voer uw pas in", nullptr));
        welkom_inlog_button->setText(QCoreApplication::translate("Login", "Pas invoer simulatie", nullptr));
        label_4->setText(QCoreApplication::translate("Login", "Voer uw pincode in", nullptr));
        inlog_taal_button->setText(QCoreApplication::translate("Login", "[language settings]", nullptr));
        inlog_hoofd_button->setText(QCoreApplication::translate("Login", "Doorgaan", nullptr));
        inlog_welkom_button->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
        label_9->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        taal_optieNederlands_button->setText(QCoreApplication::translate("Login", "Nederlands", nullptr));
        taal_optieEngels_button->setText(QCoreApplication::translate("Login", "English", nullptr));
        taal_optieDuits_button->setText(QCoreApplication::translate("Login", "Deutsch", nullptr));
        taal_welkom_button->setText(QCoreApplication::translate("Login", "afrbreken", nullptr));
        taal_hoofd_of_welkom_of_inlog_button->setText(QCoreApplication::translate("Login", "terug", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "HoofdScherm", nullptr));
        hoofd_snelPinnen_button->setText(QCoreApplication::translate("Login", "Snel \342\202\25470,-", nullptr));
        hoofd_saldo_button->setText(QCoreApplication::translate("Login", "Saldo", nullptr));
        hoofd_pinKeuze_button->setText(QCoreApplication::translate("Login", "Bedrag kiezen", nullptr));
        hoofd_taal_button->setText(QCoreApplication::translate("Login", "Taal", nullptr));
        hoofd_welkom_button->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "SaldoScherm", nullptr));
        saldo_pinKeuze_button->setText(QCoreApplication::translate("Login", "Geld opnemen", nullptr));
        saldo_welkom_button->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
        saldo_hoofdscherm_button->setText(QCoreApplication::translate("Login", "Hoofdscherm", nullptr));
        saldo_label->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        Labelpinnen->setText(QCoreApplication::translate("Login", "KeuzeScherm pinnen", nullptr));
        pinKeuze_optie1_button->setText(QCoreApplication::translate("Login", "\342\202\25420,-", nullptr));
        pinKeuze_optie2_button->setText(QCoreApplication::translate("Login", "\342\202\25450,-", nullptr));
        pinKeuze_optie3_button->setText(QCoreApplication::translate("Login", "\342\202\25470,-", nullptr));
        pinKeuze_optie4_button->setText(QCoreApplication::translate("Login", "\342\202\254100,-", nullptr));
        pinKeuze_optie5_button->setText(QCoreApplication::translate("Login", "\342\202\254120,-", nullptr));
        pinKeuze_zelfBedragKiezen_button->setText(QCoreApplication::translate("Login", "Zelf kiezen", nullptr));
        pinKeuze_welkom_button->setText(QCoreApplication::translate("Login", "afbreken", nullptr));
        pinKeuze_hoofd_button->setText(QCoreApplication::translate("Login", "Hoofdscherm", nullptr));
        label_5->setText(QCoreApplication::translate("Login", "biljetKeuzeScherm", nullptr));
        biljetKeuze_welkom_button->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
        biljetKeuze_hoofd_button->setText(QCoreApplication::translate("Login", "Hoofdscherm", nullptr));
        biljetKeuze_biljetNietBelangrijk_button->setText(QCoreApplication::translate("Login", "Boeit niet", nullptr));
        biljetKeuze_biljetOpties1_button->setText(QCoreApplication::translate("Login", "Opties biljetten", nullptr));
        label_6->setText(QCoreApplication::translate("Login", "BedragKeuzeScherm", nullptr));
        bedragKeuze_hoofd_button->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
        bedragKeuze_welkom_button->setText(QCoreApplication::translate("Login", "Hoofdscherm", nullptr));
        bedragKeuze_bevestigen_button->setText(QCoreApplication::translate("Login", "Bevestigen", nullptr));
        label_7->setText(QCoreApplication::translate("Login", "Bon Scherm", nullptr));
        bon_metBon_button->setText(QCoreApplication::translate("Login", "Ik wil een bon", nullptr));
        bon_zonderBon_button->setText(QCoreApplication::translate("Login", "Ik wil geen bon", nullptr));
        bon_hoofd_button->setText(QCoreApplication::translate("Login", "Hoofdscherm", nullptr));
        bon_welkom_button->setText(QCoreApplication::translate("Login", "Afbreken", nullptr));
        label_8->setText(QCoreApplication::translate("Login", "verwerkingsScherm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
