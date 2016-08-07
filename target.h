#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QList>
#include <QDebug>
#include "resourcestimer.h"
#include <QtAlgorithms>

class Target : public QObject
{
    Q_OBJECT
public:
    explicit Target(QString name);
    ~Target();


    QList<ResourcesTimer *> *getTimers() const;

    QString getName() const;
    void setName(const QString &value);

private:
    QList<ResourcesTimer *> *timers;

    QString name;

signals:
    void finished(QString name);
public slots:
    bool isFinished();
    QTime getFinishTime();
    void addTimer(QString name,
                  qreal  amount,
                  qreal  incPerHour,
                  qint64  finalAmount);
    void removeTimer(qint64 index);
    void removeTimers(qint64 startIndex, qint64 count);

};

#endif // TARGET_H
