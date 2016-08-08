#include "resourcestimer.h"

ResourcesTimer::ResourcesTimer(QString name, qint64 id, qreal amount, qreal incPerSec, qint64 finalAmount)
{
    this->timer = new QTimer(this);

    this->name = name;
    this->id = id;
    this->amount = amount;
    this->incPerSec = incPerSec;
    this->finalAmount = finalAmount;

    setEndTime();


    connect(timer, &QTimer::timeout, this, &ResourcesTimer::resorceTimeout);


    this->timer->setSingleShot(false);
    this->timer->start(1000);

}

ResourcesTimer::~ResourcesTimer()
{
    delete this->timer;
}


void ResourcesTimer::resorceTimeout()
{
    // updating
    this->amount += this->incPerSec;

    // sending signals
    if(this->amount >= this->finalAmount){
        this->timer->stop();
        emit finished(this->id);
    }
    else{
        emit changed(this->id, this->amount);
    }
}

qint64 ResourcesTimer::getId() const
{
    return id;
}

void ResourcesTimer::setId(const qint64 &value)
{
    id = value;
}

bool ResourcesTimer::isFinished()
{
    return (this->amount >= this->finalAmount) ? true : false;
}

QDateTime ResourcesTimer::getEndTime() const
{
    return this->end;
}

QString ResourcesTimer::getName() const
{
    return name;
}

void ResourcesTimer::setName(const QString &value)
{
    name = value;
}

qreal ResourcesTimer::getAmount() const
{
    return amount;
}

void ResourcesTimer::setAmount(const qreal &value)
{
    amount = value;
    setEndTime();
}

qint64 ResourcesTimer::getFinalAmount() const
{
    return finalAmount;
}

void ResourcesTimer::setFinalAmount(const qint64 &value)
{
    finalAmount = value;
    setEndTime();
}

qreal ResourcesTimer::getIncPerSec() const
{
    return incPerSec;
}

void ResourcesTimer::setIncPerSec(const qreal &value)
{
    incPerSec = value;
    setEndTime();
}

void ResourcesTimer::setEndTime()
{
    if(this->incPerSec == 0){
        this->end = QDateTime::currentDateTime();
    }
    else{
        this->end = QDateTime::currentDateTime().addSecs(qCeil((finalAmount - amount)/incPerSec));
    }
}
