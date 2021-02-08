#ifndef SECONDTHREAD_H
#define SECONDTHREAD_H

#include <QObject>
#include <QTimer>
#include <QCoreApplication>

#include <FirstThread.h>
#include <ThirdThread.h>
#include <WorkerTimer.h>

class SecondThread : public QObject
{
    Q_OBJECT

public:
    SecondThread(QObject *parent,
                 FirstThread *firstThread,
                 ThirdThread *thirdThread);

public slots:
    void timerFaster();
    void timerSlower();
    void timerPause();
    void timerResume();

private:
    QTimer mm_timer;
    WorkerTimer worker;

};

#endif // SECONDTHREAD_H
