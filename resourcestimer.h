#ifndef RESOURSESTIMER_H
#define RESOURSESTIMER_H
/**
 *   @file   resourcestimer.h
 *   @author Noè Murr
 *   @date   08-08-2016
 *   @brief  this files contains the definition of the class ResourcesTimer
 */

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtMath>
#include <QTime>

/**
 * @brief The ResourcesTimer class
 *
 * this is the class implements the concept of Resources that has an Amount,
 * an increment per seconds and a final amount.
 *
 */
class ResourcesTimer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief ResourcesTimer
     * @param name          the resources name (ex. Iron)
     * @param id            the Id is used by a target Class
     * @param amount        the actual amount of the resources represented
     * @param incPerSec     the increment per second of the resources.
     * @param finalAmount   the target amount. the target is finished when the amount == finalAmount
     *
     * Constructor that assign the value and start the timer.
     */
    explicit ResourcesTimer(QString name,
                            qint64  id,
                            qreal  amount,
                            qreal  incPerSec,
                            qint64  finalAmount);
    ~ResourcesTimer();

    /**
     * @brief getId
     * @return qint64 that represent the Id.
     */
    qint64 getId() const;

    /**
     * @brief setId
     * @param value     the Value of the new Id.
     */
    void setId(const qint64 &value);

    /**
     * @brief getEndTime
     * @return time of end.
     */
    QTime getEndTime() const;

    /**
     * @brief getName
     * @return the name of the resources.
     */
    QString getName() const;

    /**
     * @brief setName
     * @param value     name to set.
     */
    void setName(const QString &value);

    /**
     * @brief getAmount
     * @return  the actual amount of resources
     */
    qreal getAmount() const;

    /**
     * @brief setAmount
     * @param value     the new amount.
     */
    void setAmount(const qreal &value);

    /**
     * @brief getFinalAmount
     * @return the Amount of resources that is the arival.
     */
    qint64 getFinalAmount() const;

    /**
     * @brief setFinalAmount
     * @param value     new final amount.
     */
    void setFinalAmount(const qint64 &value);

    /**
     * @brief getIncPerSec
     * @return  the actual increment per second.
     */
    qreal getIncPerSec() const;

    /**
     * @brief setIncPerSec
     * @param value     the new increment per second.
     */
    void setIncPerSec(const qreal &value);

private:
    /**
     * @brief timer of resource.
     *
     * It is the timer that is necessary for update the Amount value every second.
     */
    QTimer  *timer; // timer of resource.

    /**
     * @brief id
     *
     * It is used by other class.
     *
     */
    qint64  id;     // row of the table

    /**
     * @brief name
     *
     * It's the resources name like Iron, Cristal or Energy.
     *
     */
    QString name;  // resource name

    /**
     * @brief amount
     *
     * It's the actual amount of the resources, it is updated every second.
     *
     */
    qreal  amount; // the exactly amount of resorce

    /**
     * @brief incPerSec
     *
     * It's the value to add every second at Amount value.
     *
     */
    qreal  incPerSec;  // increment per second

    /**
     * @brief finalAmount
     *
     * It's the final Amount.
     * The timer finished when the Amount value is equal to finalAmount.
     *
     */
    qint64  finalAmount;    // final amount of resource

    /**
     * @brief end Time
     *
     * It's the end time of the timer.
     *
     */
    QTime end; // the end time

    /**
     * @brief setEndTime
     *
     * It sets the end time by the formula currentTime + ((finalAmount - amount)/incPerSec)
     *
     */
    void setEndTime();

signals:
    /**
     * @brief changed
     * @param id
     * @param amount
     *
     * It's advise that the value of actual amount is changed.
     *
     */
    void changed(qint64  id, qreal  amount);

    /**
     * @brief finished
     * @param id
     *
     * It's advise that the timer is finished so the finalAmount == amount
     *
     */
    void finished(qint64 id);
public slots:
    /**
     * @brief resorceTimeout
     *
     * It's connected to the timeout of the timer to update the amount value.
     *
     */
    void resorceTimeout();

    /**
     * @brief isFinished
     * @return true if timer is finished
     *
     * If the timer is finished the function return true.
     *
     */
    bool isFinished();
};

#endif // RESOURSESTIMER_H
