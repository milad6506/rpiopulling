#include "serialport.h"

serialPort::serialPort(QObject *parent) : QObject(parent)
{

    QList <QSerialPortInfo> avail = QSerialPortInfo::availablePorts();

    for (int i=0;i <avail.count();i++){
        cout << avail.at(i).portName().toStdString() << endl;
    }


}



void serialPort::interpretData(QString inputData)
{
    cout << " the recievd data is " << inputData.toStdString() << endl;
    imuData.clear();
}

void serialPort::startPolling()
{
    QSerialPort IMU;
    IMU.setPortName("ttyAMA0");
    IMU.setBaudRate(QSerialPort::Baud57600);
    IMU.setDataBits(QSerialPort::Data8);
    IMU.setFlowControl(QSerialPort::NoFlowControl);
    IMU.setParity(QSerialPort::NoParity);
    IMU.setStopBits(QSerialPort::OneStop);
    while (true){
        while (IMU.bytesAvailable()>0){
            imuData = IMU.readAll();
            cout << imuData.toStdString() << "data" << endl;
            /*
            if (imuData.contains("\r\n")){

                interpretData(QString::fromStdString(imuData.toStdString()));
            }*/
        }
    }
    cout << IMU.errorString().toStdString() << endl;
    cout << "port is closed" << endl;



}
