#include "WorkerTimer.h"
#include <QDebug>

WorkerTimer::WorkerTimer()
{
    mm_id = 0;
}

void WorkerTimer::workerTimer()
{
//    qDebug() << "сработка таймера!";

    ++mm_id;

    Event event;
    event.mm_time = QDateTime::currentDateTime().toString("dd:MM:yyyy HH:mm:ss");
    event.mm_idEvent = mm_id;
    event.mm_a = 0;
    event.mm_b = 0;
    event.mm_c = 0;

    emit logEvent(event);
}
