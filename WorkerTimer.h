#ifndef WORKERTIMER_H
#define WORKERTIMER_H

#include <QObject>
#include <Event.h>

class WorkerTimer : public QObject
{
    Q_OBJECT
public:
    WorkerTimer();

signals:
    void logEvent(Event event);

public slots:
    void workerTimer();

private:
    int mm_id;
};

#endif // WORKERTIMER_H
