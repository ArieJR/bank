# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#requires(qtConfig(combobox))
#TARGET = AnviBank

TEMPLATE = app
TARGET = Bank

QT = core gui \
    widgets \
    core \
    sql

QT += serialport \
    qml quick


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    com.cpp \
    database.cpp \
    login.cpp \
    main.cpp

HEADERS += \
    com.h \
    database.h \
    login.h


FORMS += \
    login.ui

##INCLUDEPATH += \
    ##<C:/Qt/5.14.2/Src/qtbase/src/sql>

DISTFILES += \
    ../../../../Documents/bank-last-push/comunicatie.js \
    ANVI_LOGO.png \
    ANVI_LOGO_200.png \
    Afbeelding1.png \
    bank_en_nl.qm \
    duitsland_100.png \
    engeland_100.png \
    jsFile.js \
    jsQml.qml \
    nederland_100.png
