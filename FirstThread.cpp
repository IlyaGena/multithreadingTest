#include "FirstThread.h"

FirstThread::FirstThread()
{
    mm_command.insert("date", &print_date);
    mm_command.insert("time", &time);
    mm_command.insert("exit", &exitApp);
    mm_command.insert("faster", &faster);
    mm_command.insert("slower", &slower);
    mm_command.insert("pause", &pause);
    mm_command.insert("resume", &resume);
    mm_command.insert("level 0", &level0);
    mm_command.insert("level 1", &level1);
    mm_command.insert("level 2", &level2);
    mm_command.insert("stat", &stat);
}

FirstThread::~FirstThread()
{
    qDebug() << "поток 1 остановлен";
}

void FirstThread::run()
{
    qDebug() << "открыт поток #1";

    qDebug() << "Введите команду";
    QTextStream cin(stdin);
    QString command;

    QRegExp reg("(\\w+)(\\s*)(\\d+$)");

    while (cin.readLineInto(&command))
    {
        QString tmp;
        int pos = reg.indexIn(command);
        if (pos > -1)
        {
            tmp = reg.cap(0);
        }
        else
        {
            QRegExp reg("([a-z]+)");
            reg.indexIn(command);
            tmp = reg.cap(1);
        }

        QList<QString> listCommand = mm_command.keys();

        if (!listCommand.contains(tmp))
        {
            qDebug() << "Команда ошибочна";
            continue;
        }

        Handler* tmpo = mm_command.value(tmp);
        int number = tmpo->running();

        // парсинг объекта и отправка сигнала
        switch (number)
        {
        case 1:
        {
            emit exitSignal();
            quit();
            return;
        }

        case 2:
            emit fasterSignal();
            break;

        case 3:
            emit slowerSignal();
            break;

        case 4:
            emit pauseSignal();
            break;

        case 5:
            emit resumeSignal();
            break;

        case 6:
            emit level0Signal(0);
            break;

        case 7:
            emit level1Signal(1);
            break;

        case 8:
            emit level2Signal(2);
            break;

        case 9:
            emit statSignal();
            break;

        default:
            break;
        }
    }
}

int HandlerDate::running()
{
    QTextStream cout(stdout);
    cout << QDateTime::currentDateTime().toString("dd:MM:yyyy") << Qt::endl;
    return 0;
}

int HandlerTime::running()
{
    QTextStream cout(stdout);
    cout << QDateTime::currentDateTime().toString("HH:mm:ss") << Qt::endl;
    return 0;
}

int HandlerExit::running()
{
    return 1;
}

int HandlerFaster::running()
{
    return 2;
}

int HandlerSlower::running()
{
    return 3;
}

int HandlerPause::running()
{
    return 4;
}

int HandlerResume::running()
{
    return 5;
}

int HandlerLevel0::running()
{
    QTextStream cout(stdout);
    cout << "level 0" << Qt::endl;
    return 6;
}

int HandlerLevel1::running()
{
    QTextStream cout(stdout);
    cout << "level 1" << Qt::endl;
    return 7;
}

int HandlerLevel2::running()
{
    QTextStream cout(stdout);
    cout << "level 2" << Qt::endl;
    return 8;
}

int HandlerStat::running()
{
    return 9;
}
