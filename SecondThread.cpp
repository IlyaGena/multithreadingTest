#include "SecondThread.h"

SecondThread::SecondThread(QObject *parent, FirstThread *firstThread, ThirdThread *thirdThread)
{

    // определение сигнал/слотов
    QObject::connect(&mm_timer, &QTimer::timeout, &worker, &WorkerTimer::workerTimer);
    QObject::connect(&worker, &WorkerTimer::logEvent, thirdThread, &ThirdThread::logger);
    //  сигнал/слоты первого потока
    QObject::connect(firstThread, &FirstThread::exitSignal, parent, QCoreApplication::quit);
    QObject::connect(firstThread, &FirstThread::fasterSignal, this, &SecondThread::timerFaster);
    QObject::connect(firstThread, &FirstThread::slowerSignal, this, &SecondThread::timerSlower);
    QObject::connect(firstThread, &FirstThread::exitSignal, parent, QCoreApplication::quit);
    QObject::connect(firstThread, &FirstThread::level0Signal, thirdThread, &ThirdThread::setLevel);
    QObject::connect(firstThread, &FirstThread::level1Signal, thirdThread, &ThirdThread::setLevel);
    QObject::connect(firstThread, &FirstThread::level2Signal, thirdThread, &ThirdThread::setLevel);
    QObject::connect(firstThread, &FirstThread::statSignal, thirdThread, &ThirdThread::statFile);


    mm_timer.setInterval(2000);
    mm_timer.start();
}

void SecondThread::timerFaster()
{
    auto count = mm_timer.interval();
    count -= 500;
    mm_timer.setInterval(count);
    qDebug() << "Интервал равен: " + QString::number(count);
}

void SecondThread::timerSlower()
{
    auto count = mm_timer.interval();
    count += 500;
    mm_timer.setInterval(count);
    qDebug() << "Интервал равен: " + QString::number(count);
}

void SecondThread::timerPause()
{
    if (mm_timer.isActive())
        mm_timer.stop();
}

void SecondThread::timerResume()
{
    if (!mm_timer.isActive())
        mm_timer.start();
}
