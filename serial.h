#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>      //nodig om met serialport communiceren
#include <QSerialPortInfo>  //nodig om PID en VID te verkrijgen
#include <QMessageBox>
#include <string>

class serial
{
public :
    int controlGui = 0;
    explicit serial();
    void getVendorProductId();
    void arduinoSetting();

    void checkArduinoPortName();
    void connectArduino();
    void openSerialPort();
    void closeSerialPort();
    void readArduino();
    void inputPassw();
    void sendArduino(const QByteArray &data);
    void trickerbuttom();
    void arduinoSendBack();

    void serialAction();
    void intobject(int value);

    bool arduinoConnected = false;
    QString arduinoPortName;
    static const quint16 arduinoVendorId = 6790;
    static const quint16 arduinoProductId = 29987 ;
    QSerialPort *arduino;

private :


};

#endif // SERIAL_H
