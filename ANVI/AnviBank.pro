# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = AnviBank

TEMPLATE = app
TARGET = Bank

QT = core gui \
    widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    data.cpp \
    login.cpp \
    main.cpp

HEADERS += \
    data.h \
    login.h


FORMS += \
    login.ui

DISTFILES += \
    bank_en_nl.qm
