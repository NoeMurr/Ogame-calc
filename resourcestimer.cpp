#include "resourcestimer.h"

ResourcesTimer::ResourcesTimer(QString name, qint64 row, qint64 amount, qint64 incPerSec, qint64 finalAmount)
{
    this->timer = new QTimer(this);

    this->name = name;
    this->id = id;
    this->amount = amount;
    this->incPerSec = incPerSec;
    this->finalAmount = finalAmount;

    connect(timer, &QTimer::timeout, this, &ResourcesTimer::resorceTimeout);
}

void ResourcesTimer::resorceTimeout()
{
    qDebug() << "timeout " << this->name << "  (" << this->id << ")" << std::endl;
    emit changed(this->id);
}
