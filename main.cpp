#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDataStream>

#include <FirstThread.h>
#include <SecondThread.h>
#include <ThirdThread.h>
#include <WorkerTimer.h>
#include <Event.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // поток получения информации от пользователя
    FirstThread firstThread;
    // поток логирования событий
    ThirdThread thirdThread;

    // основной поток
    SecondThread secondThread(&a, &firstThread, &thirdThread);

    firstThread.start();
    thirdThread.start();

    return a.exec();
}
