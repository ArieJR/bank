TEMPLATE = app
TARGET = Bank

QT = core gui \
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    login.cpp \
    main.cpp


HEADERS += \
    login.h


FORMS += \
    login.ui


