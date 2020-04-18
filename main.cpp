#include <QCoreApplication>
#include <iostream>
#include <QSerialPort>
#include <QDebug>
#include <QElapsedTimer>
using namespace std;
QSerialPort serial;
QElapsedTimer timer;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    serial.setPortName("COM3");
    serial.open(QIODevice::ReadWrite);
       serial.setBaudRate(QSerialPort::Baud9600);
       serial.setDataBits(QSerialPort::Data8);
       serial.setParity(QSerialPort::NoParity);
       serial.setStopBits(QSerialPort::OneStop);
       serial.setFlowControl(QSerialPort::NoFlowControl);
        while(!serial.isOpen()) serial.open(QIODevice::ReadWrite);

        //kijk of het serialport open is
       if (serial.isOpen() && serial.isWritable())
       {
       qDebug() << "SerialPort is open";

       QByteArray input;

         while(true)
         {

         serial.waitForReadyRead(500);  //soort delay

            if(serial.bytesAvailable()>=1)
            {
            input = serial.read(1);
            qDebug()<<input;            //print de output van de arduino
            }
          }
       }
    return a.exec();
}
