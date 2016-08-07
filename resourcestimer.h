#ifndef RESOURSESTIMER_H
#define RESOURSESTIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtMath>
#include <QTime>

class ResourcesTimer : public QObject
{
    Q_OBJECT
public:
    explicit ResourcesTimer(QString name,
                            qint64  id,
                            qreal  amount,
                            qreal  incPerSec,
                            qint64  finalAmount);
    ~ResourcesTimer();

    qint64 getId() const;
    void setId(const qint64 &value);

    QTime getEndTime() const;

    QString getName() const;
    void setName(const QString &value);

    qreal getAmount() const;
    void setAmount(const qreal &value);

    qint64 getFinalAmount() const;
    void setFinalAmount(const qint64 &value);

    qreal getIncPerSec() const;
    void setIncPerSec(const qreal &value);

private:
    QTimer  *timer; // timer of resource.

    qint64  id;     // row of the table
    QString name;  // resource name
    qreal  amount; // the exactly amount of resorce
    qreal  incPerSec;  // increment per second
    qint64  finalAmount;    // final amount of resource

    QTime end; // the end time

    void setEndTime();

signals:
    void changed(qint64  id, qreal  amount);
    void finished(qint64 id);
public slots:
    void resorceTimeout();
    bool isFinished();
};

#endif // RESOURSESTIMER_H
