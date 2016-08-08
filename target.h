#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QTimer>
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

    QTimer *timer;

signals:
    void finished();
public slots:
    bool isFinished();
    QTime getFinishTime();
    void addTimer(QString name,
                  qreal  amount,
                  qreal  incPerHour,
                  qint64  finalAmount);
    void removeTimer(qint64 index);
    void removeTimers(qint64 startIndex, qint64 count);
    void startTimer();

private slots:
    void timeout();

};

#endif // TARGET_H
