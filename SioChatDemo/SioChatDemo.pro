#-------------------------------------------------
#
# Project created by QtCreator 2015-03-30T19:25:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SioChatDemo
TEMPLATE = app

CONFIG+=no_keywords
CONFIG+=c++11

SOURCES += main.cpp\
    mainwindow.cpp \
    nicknamedialog.cpp \
    ./sioclient/src/sio_client.cpp \
    ./sioclient/src/sio_packet.cpp \

HEADERS  += mainwindow.h \
    nicknamedialog.h \
    ./sioclient/src/sio_client.h \
    ./sioclient/src/sio_message.h \

FORMS    += mainwindow.ui \
    nicknamedialog.ui

INCLUDEPATH += $$PWD/sioclient/lib/rapidjson/include
INCLUDEPATH += $$PWD/sioclient/lib/websocketpp

CONFIG(debug, debug|release):DEFINES +=DEBUG=1


INCLUDEPATH += $$PWD/../../../build/include
DEPENDPATH += $$PWD/../../../build/lib

CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/lib/Release/ -lsioclient
else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/lib/Debug/ -lsioclient


CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/lib/Release/ -lboost_random
else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/lib/Debug/ -lboost_random

CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/lib/Release/ -lboost_system
else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/lib/Debug/ -lboost_system

CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/lib/Release/ -lboost_date_time
else:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/lib/Debug/ -lboost_date_tim
