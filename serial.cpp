#include "serial.h"
#include <QString>

#include <QSerialPort>      //nodig om met serialport communiceren
#include <QSerialPortInfo>  //nodig om PID en VID te verkrijgen
#include <QMessageBox>
#include <string>
#include <QDebug>


serial::serial()
{

}
void serial::getVendorProductId()
{
    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier())
        {
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier())
        {
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }

    }

}

void serial::checkArduinoPortName()
{
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
        {
            if(serialPortInfo.vendorIdentifier() == arduinoVendorId)
            {
                if(serialPortInfo.productIdentifier() == arduinoProductId)
                {
                    arduinoPortName = serialPortInfo.portName();
                    arduinoConnected = true;
                }
            }
        }
    }
}


void serial::openSerialPort()
{
    arduino->setPortName(arduinoPortName);     //port naam kan ook bijv.(COM 3)
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "Arduino verbonden.\n";
    arduino->open(QSerialPort::ReadWrite);
    qDebug()<<"serial is open";
}

void serial::closeSerialPort()
{
    if(arduino->isOpen())
    {
        arduino->close();
        qDebug()<< "serial is closed" ;
    }
}

void serial::readArduino()
{
    while (arduinoConnected)
    {
        const QByteArray dataRead = arduino->readAll();
    }
}


void serial::sendArduino(const QByteArray &data)
{

    arduino->write(data);
}


void serial::serialAction()
{

}
