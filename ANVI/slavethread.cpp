#include "slavethread.h"

//#include <QtSerialPort/QSerialPortInfo>
#include <qserialport.h>
#include <QTime>
#include <QIODevice>
#include <qbytearray.h>

SlaveThread::SlaveThread(QObject *parent) :
    QThread(parent)
{
}


SlaveThread::~SlaveThread()
{
    m_mutex.lock();
    m_quit = true;
    m_mutex.unlock();
    wait();
}


void SlaveThread::startSlave(const QString &portName, int waitTimeout, const QString &response)
{
    //! [1]
    const QMutexLocker locker(&m_mutex);
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    m_response = response;
    //! [3]
    if (!isRunning())
        start();
}

void SlaveThread::run()
{
    bool currentPortNameChanged = false;

    m_mutex.lock();
//! [4] //! [5]
    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = m_waitTimeout;
    QString currentRespone = m_response;
    m_mutex.unlock();

    QSerialPort serial;

    while (!m_quit) {
//![6] //! [7]
        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2")
                           .arg(m_portName).arg(serial.error()));
                return;
            }
        }

        if (serial.waitForReadyRead(currentWaitTimeout)) {
/
            // read request
            QByteArray requestData = serial.readAll();
            while (serial.waitForReadyRead(10))
                requestData += serial.readAll();

            // write response
            const QByteArray responseData = currentRespone.toUtf8();
            serial.write(responseData);
            if (serial.waitForBytesWritten(m_waitTimeout)) {
                const QString request = QString::fromUtf8(requestData);

                emit this->request(request);

            } else {
                emit timeout(tr("Wait write response timeout %1")
                             .arg(QTime::currentTime().toString()));
            }

        } else {
            emit timeout(tr("Wait read request timeout %1")
                         .arg(QTime::currentTime().toString()));
        }

        m_mutex.lock();
        if (currentPortName != m_portName) {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
        currentRespone = m_response;
        m_mutex.unlock();
    }

}
