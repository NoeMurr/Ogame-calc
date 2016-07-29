#ifndef RESOURSESTIMER_H
#define RESOURSESTIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "ogcalc.h"

class ResourcesTimer : public QObject
{
    Q_OBJECT
public:
    explicit ResourcesTimer(QString name,
                            qint64  id,
                            qint64  amount,
                            qint64  incPerSec,
                            qint64  finalAmount);

    QTimer  *timer; // timer of resource.

    qint64  id;     // row of the table
    QString name;  // resource name
    qint64  amount; // the exactly amount of resorce
    qint64  incPerSec;  // increment per second
    qint64  finalAmount;    // final amount of resource

signals:
    void changed(qint64  id);
public slots:
    void resorceTimeout();
};

#endif // RESOURSESTIMER_H
