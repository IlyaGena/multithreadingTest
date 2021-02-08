#include <Logger.h>

Logger::Logger(QString *fileName)
{
    mm_fileName = *fileName;
}

Logger *Logger::Get_Logger(int level)
{
    Logger *tmp = nullptr;

    switch (level)
    {
    case 0:
        tmp = new LogType0("log.txt");
        break;

    case 1:
        tmp = new LogType1("log.txt");
        break;

    case 2:
        tmp = new LogType2("log.txt");
        break;

    default:
        break;
    }

    return tmp;
}

Logger *LogType0::Write(Event event)
{
    QString str = "0 тип события. Событие произошло в <" + event.mm_time + "> с ID: <" + QString::number(event.mm_idEvent) + ">\n";
    QFile file(this->mm_fileName);
    if (file.open(QIODevice::Append) || file.open(QIODevice::Text))
    {
        QTextStream append(&file);
        append << str;
    }
    file.close();
    return this;
}

Logger *LogType1::Write(Event event)
{
    QString str = "1 тип события. Событие произошло в <" + event.mm_time + "> с ID: <" + QString::number(event.mm_idEvent) + "> VALUE1: <" +
            QString::number(event.mm_a) + ">\n";
    QFile file(this->mm_fileName);
    if (file.open(QIODevice::Append) || file.open(QIODevice::Text))
    {
        QTextStream append(&file);
        append << str;
    }
    file.close();
    return this;
}

Logger *LogType2::Write(Event event)
{
    QString str = "2 тип события. Событие произошло в <" + event.mm_time +
            "> с ID: <" + QString::number(event.mm_idEvent) +
            "> VALUE1: <" + QString::number(event.mm_a) +
            "> VALUE1: <" + QString::number(event.mm_b) +
            "> VALUE1: <" + QString::number(event.mm_c) + ">\n";

    QFile file(this->mm_fileName);
    if (file.open(QIODevice::Append) || file.open(QIODevice::Text))
    {
        QTextStream append(&file);
        append << str;
    }
    file.close();
    return this;
}

