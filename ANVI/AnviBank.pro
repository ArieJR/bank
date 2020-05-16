# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = AnviBank

TEMPLATE = app
TARGET = Bank

QT = core gui \
    widgets \
    core        #inti test


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    database.cpp \
    login.cpp \
    main.cpp

HEADERS += \
    database.h \
    login.h


FORMS += \
    login.ui

DISTFILES += \
    ANVI_LOGO.png \
    ANVI_LOGO_200.png \
    Afbeelding1.png \
    bank_en_nl.qm \
    duitsland_100.png \
    engeland_100.png \
    nederland_100.png
