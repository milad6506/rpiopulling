#include "serialport.h"

serialPort::serialPort(QObject *parent) : QObject(parent)
{
    IMU = new QSerialPort;
    IMU->setPortName("ttyAMA0");
    IMU->setBaudRate(QSerialPort::Baud57600);
    IMU->setDataBits(QSerialPort::Data8);
    IMU->setFlowControl(QSerialPort::NoFlowControl);
    IMU->setParity(QSerialPort::NoParity);
    IMU->setStopBits(QSerialPort::OneStop);



}

serialPort::~serialPort()
{
    delete IMU;

}

bool serialPort::openPort()
{
    return IMU->open(QIODevice::ReadWrite);
}

void serialPort::closePort()
{
    IMU->close();
}

void serialPort::interpretData(QString inputData)
{
    cout << " the recievd data is " << inputData.toStdString() << endl;
    imuData.clear();
}

void serialPort::startPolling()
{
    while (openPort()){
        while (IMU->canReadLine()){
            imuData = IMU->readLine();
            if (imuData.contains("\r\n")){

                interpretData(QString::fromStdString(imuData.toStdString()));
            }
        }
    }
    cout << "port is closed" << endl;



}
