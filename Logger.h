#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QTextStream>

#include <Event.h>

class Logger
{
protected:
    Logger(QString *fileName);;
    ~Logger();

public:
    static Logger* Get_Logger(int level);
    virtual Logger* Write(Event event) = 0;

    QString mm_fileName;
};

class LogType0 : public Logger
{
public:
    LogType0(QString fileName) : Logger(&fileName){};
    Logger* Write(Event event) override;
};

class LogType1 : public Logger
{
public:
    LogType1(QString fileName) : Logger(&fileName){};
    Logger* Write(Event event) override;
};

class LogType2 : public Logger
{
public:
    LogType2(QString fileName) : Logger(&fileName){};
    Logger* Write(Event event) override;
};

#endif // LOGGER_H
