#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QtAlgorithms>

#include "resourcestimer.h"

/**
 * @brief The Target class
 *
 * A target represents a goal. It could be necessary to have more than one resources
 * so the Target class contains a variable value of ResourcesTimer
 *
 */
class Target : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Target
     * @param name  the name of the target.
     *
     * It's the constructor and generate a simple target without timers
     *
     */
    explicit Target(QString name);
    ~Target();


    /**
     * @brief getTimers
     * @return the ResourcesTimer list.
     *
     * return the list of resourcesTimer
     *
     */
    QList<ResourcesTimer *> *getTimers() const;

    /**
     * @brief getName
     * @return  the name of the target.
     */
    QString getName() const;

    /**
     * @brief setName
     * @param value     the new name
     *
     * It sets a new name for the target.
     *
     */
    void setName(const QString &value);

private:
    /**
     * @brief timers
     *
     * List of ResourcesTimer pointers.
     *
     */
    QList<ResourcesTimer *> *timers;

    /**
     * @brief name
     *
     * the name of theese target.
     *
     */
    QString name;

    /**
     * @brief timer
     *
     * timer, it is necessary for updates.
     *
     */
    QTimer *timer;

signals:
    /**
     * @brief finished
     *
     * Signal emited when the Target is completed.
     *
     */
    void finished();

public slots:
    /**
     * @brief isFinished
     * @return true if the target is finished.
     */
    bool isFinished();

    /**
     * @brief getFinishTime
     * @return the finish time of the target
     */
    QTime getFinishTime();
    /**
     * @brief addTimer
     * @param name
     * @param amount
     * @param incPerHour
     * @param finalAmount
     *
     * It permits to add a ResourcesTimer to the Target
     *
     */
    void addTimer(QString name,
                  qreal  amount,
                  qreal  incPerHour,
                  qint64  finalAmount);

    /**
     * @brief removeTimer
     * @param index
     *
     * It permits to remove one target.
     *
     */
    void removeTimer(qint64 index);

    /**
     * @brief removeTimers
     * @param startIndex
     * @param count
     *
     * It permits to remove more than one ResourcesTimer from the list of timers.
     */
    void removeTimers(qint64 startIndex, qint64 count);

    /**
     * @brief startTimer
     *
     * It permits to start the timer that is necessary for the updates.
     *
     */
    void startTimer();

private slots:
    /**
     * @brief timeout
     *
     * It's connected to the timeout of the timer.
     *
     */
    void timeout();

};

#endif // TARGET_H
