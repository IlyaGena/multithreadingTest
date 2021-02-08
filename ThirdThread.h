#ifndef THIRDTHREAD_H
#define THIRDTHREAD_H

#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

#include <Logger.h>

class ThirdThread : public QThread
{
    Q_OBJECT

public:
    ThirdThread();

    ~ThirdThread();

    virtual void run();

public slots:
    void logger(Event event);
    void setLevel(int level);
    void statFile();

private:
    QFile mm_file;
    quint8 mm_level;
};
#endif // THIRDTHREAD_H
