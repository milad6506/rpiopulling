#include <QCoreApplication>
#include <serialport.h>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    serialPort serial;
    QThread serialThread;

    QObject::connect(&serialThread,SIGNAL(started()),&serial,SLOT(startPolling()));
    serial.moveToThread(&serialThread);
    serialThread.start();



    return a.exec();
}
