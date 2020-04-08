TEMPLATE = app
TARGET = Bank

QT = core gui \
    widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    createScherm.cpp \
    data.cpp \
    login.cpp \
    main.cpp


HEADERS += \
    createScherm.h \
    data.h \
    login.h


FORMS += \
    login.ui


