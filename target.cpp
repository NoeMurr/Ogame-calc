#include "target.h"

target::target(QString name)
{
    this->timers = new QList<ResourcesTimer>();
    this->name = name;
}

target::~target()
{
    delete this->timers;
}
