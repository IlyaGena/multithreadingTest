#include "ThirdThread.h"
#include <QDebug>

ThirdThread::ThirdThread() :
    mm_file("log.txt"),
    mm_level(0)
{
    mm_file.open(QIODevice::ReadOnly);
}

ThirdThread::~ThirdThread()
{
    qDebug() << "поток 3 остановлен";
    quit();
}

void ThirdThread::run()
{
    qDebug() << "открыт поток #3";
}

void ThirdThread::logger(Event event)
{
    Logger* object1 = Logger::Get_Logger(mm_level);
    object1->Write(event);
}

void ThirdThread::setLevel(int level)
{
    mm_level = level;
    qDebug() << "изменен уровень логирования событий";
}

void ThirdThread::statFile()
{
    if (mm_file.isOpen())
    {
        QTextStream out(stdout);
        QString str;
        while (!mm_file.atEnd())
        {
            out << mm_file.readLine();
        }
    }
}
