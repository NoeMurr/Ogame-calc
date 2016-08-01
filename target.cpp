#include "target.h"

Target::Target(QString name)
{
    this->timers = new QList<ResourcesTimer*>();
    this->name = name;
}

Target::~Target()
{
    delete this->timers;
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
    qDebug() << "added Item: " << temp->getName() << " " << temp->getId() << endl;
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

bool Target::isFinished()
{
    bool finished = true;

    QListIterator<ResourcesTimer*> iter(*this->timers);

    while(iter.hasNext())
    {
        if(!iter.next()->isFinished())
        {
            finished = false;
            break;
        }
    }

    return finished;
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
