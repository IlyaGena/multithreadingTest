#ifndef FIRSTTHREAD_H
#define FIRSTTHREAD_H

#include <QObject>
#include <QThread>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QDataStream>
#include <QSharedMemory>

#include <QRegExp>

class Handler : public QObject
{

public:
    Handler(){};
    virtual int running() = 0;
};

class HandlerDate : public Handler
{
public:
    HandlerDate() : Handler(){};
    int running() override;
};

class HandlerTime : public Handler
{
public:
    HandlerTime() : Handler(){};
    int running() override;
};

class HandlerExit : public Handler
{
public:
    HandlerExit() : Handler(){};
    int running() override;
};

class HandlerFaster : public Handler
{
public:
    HandlerFaster() : Handler(){};
    int running() override;
};

class HandlerSlower : public Handler
{
public:
    HandlerSlower() : Handler(){};
    int running() override;
};

class HandlerPause : public Handler
{
public:
    HandlerPause() : Handler(){};
    int running() override;
};

class HandlerResume : public Handler
{
public:
    HandlerResume() : Handler(){};
    int running() override;
};

class HandlerLevel0 : public Handler
{
public:
    HandlerLevel0() : Handler(){};
    int running() override;
};

class HandlerLevel1 : public Handler
{
public:
    HandlerLevel1() : Handler(){};
    int running() override;
};

class HandlerLevel2 : public Handler
{
public:
    HandlerLevel2() : Handler(){};
    int running() override;
};

class HandlerStat : public Handler
{
public:
    HandlerStat() : Handler(){};
    int running() override;
};

class FirstThread : public QThread
{
    Q_OBJECT
public:
    FirstThread();

    ~FirstThread();

    virtual void run() override;

signals:
    void exitSignal();
    void fasterSignal();
    void slowerSignal();
    void pauseSignal();
    void resumeSignal();
    void level0Signal(int level);
    void level1Signal(int level);
    void level2Signal(int level);
    void statSignal();

private:
    // объекты обработчиков комманд
    HandlerDate print_date;
    HandlerTime time;
    HandlerExit exitApp;
    HandlerFaster faster;
    HandlerSlower slower;
    HandlerPause pause;
    HandlerResume resume;
    HandlerLevel0 level0;
    HandlerLevel1 level1;
    HandlerLevel2 level2;
    HandlerStat stat;

    // переменная для хранения команд и их обработчиков
    QMap<QString, Handler*> mm_command;
};

#endif // FIRSTTHREAD_H
