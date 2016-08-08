#include "target.h"

Target::Target(QString name)
{
    this->timers = new QList<ResourcesTimer*>();
    this->name = name;
}

Target::~Target()
{
    qDeleteAll(*(this->timers));
}

QList<ResourcesTimer *> *Target::getTimers() const
{
    return timers;
}

QString Target::getName() const
{
    return name;
}

void Target::setName(const QString &value)
{
    name = value;
}

void Target::addTimer(QString name, qreal amount, qreal incPerHour, qint64 finalAmount)
{
    // generating the item
    ResourcesTimer *temp = new ResourcesTimer(
                name,
                this->timers->count(),
                amount,
                incPerHour/3600,
                finalAmount);

    this->timers->append(temp);
}

void Target::removeTimer(qint64 index)
{
    ResourcesTimer *temp = this->timers->at(index);
    this->timers->removeAt(index);
    delete temp;

    // setting new IDs
    for(qint64 i = index; i < this->timers->count(); i++){
        this->timers->at(i)->setId(this->timers->at(i)->getId()-1);
    }
}

void Target::removeTimers(qint64 startIndex, qint64 count)
{
    auto begin = this->timers->begin() + startIndex, end = begin + count;
    qDeleteAll(begin, end);
    this->timers->erase(begin, end);

    for(int i = 0; i < this->timers->count(); i++)
        this->timers->at(i)->setId(i);
}

void Target::startTimer()
{
    this->timer = new QTimer();

    connect(this->timer, &QTimer::timeout, this, &Target::timeout);

    this->timer->start(1000);
}

void Target::timeout()
{
    if(this->isFinished()){
        this->timer->stop();
        emit this->finished();
    }
}

bool Target::isFinished()
{
    if(QTime::currentTime().secsTo(this->getFinishTime()) <= 0){
        return true;
    }
    else{
        return false;
    }
}

QTime Target::getFinishTime()
{
    QTime temp;

    QListIterator<ResourcesTimer*> iter(*this->timers);

    if(iter.hasNext()){
        temp = iter.next()->getEndTime();
    }
    else{
        return QTime::currentTime();
    }
    while(iter.hasNext()){
        if(iter.peekNext()->getEndTime() > temp){
            temp = iter.next()->getEndTime();
        }
        else{
            iter.next();
        }
    }

    return temp;
}
