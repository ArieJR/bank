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


