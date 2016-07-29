#include "resourcestimer.h"

ResourcesTimer::ResourcesTimer(QString name, qint64 id, qreal amount, qreal incPerSec, qint64 finalAmount)
{
    this->timer = new QTimer(this);

    this->name = name;
    this->id = id;
    this->amount = amount;
    this->incPerSec = incPerSec;
    this->finalAmount = finalAmount;

    this->end = QTime::currentTime();
    this->end = this->end.addSecs(qFloor((finalAmount - amount)/incPerSec));


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
        qDebug() << "finished " << this->name << "  (" << this->id << ")" << endl;
        emit finished(this->id);
    }
    else{
        qDebug() << "changed " << this->name << "  (" << this->id << ")" << endl;
        emit changed(this->id, this->amount);
    }
}

bool ResourcesTimer::isFinished()
{
    return (this->amount >= this->finalAmount) ? true : false;
}
