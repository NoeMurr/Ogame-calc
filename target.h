#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QList>
#include "resourcestimer.h"

class target : public QObject
{
    Q_OBJECT
public:
    explicit target();
    ~target();

    // proprieties
    QList<ResourcesTimer> *timers;

    QString name; // the name of target


signals:
    void finished(QString name);
public slots:
    bool isFinished();
    QTime getFinishTime();
    void addTimer(ResourcesTimer *timer);
    void removeTimer(qint64 index);

};

#endif // TARGET_H
