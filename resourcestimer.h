#ifndef RESOURSESTIMER_H
#define RESOURSESTIMER_H

#include <QObject>
#include <QTimer>

class ResourcesTimer : public QObject
{
    Q_OBJECT
public:
    explicit ResourcesTimer(QObject *parent = 0);
    QTimer  *timer; // contains the timer object

    QString *name;  // resource name
    qint64  amount; // the exactly amount of resorce
    qint64  incPerSec;  // increment per second
    qint64  finalAmount;    // final amount of resource

signals:
    void changed();
public slots:
    void resorceTimeout();
};

#endif // RESOURSESTIMER_H
