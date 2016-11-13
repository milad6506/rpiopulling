#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <qserialport.h>
#include <iostream>

using namespace std;

class serialPort : public QObject
{
    Q_OBJECT
    //QSerialPort* IMU;
    QByteArray imuData;

public:
    explicit serialPort(QObject *parent = 0);

signals:

public slots:

    void interpretData(QString inputData);
    void startPolling();
};

#endif // SERIALPORT_H
