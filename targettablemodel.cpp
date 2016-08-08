#include "targettablemodel.h"

TargetTableModel::TargetTableModel(QObject *parent, QList<Target *> *datas) : QAbstractTableModel(parent)
{
    this->etaTimer  = new QTimer();
    this->datas     = datas;
    this->parent    = parent;

    connect(etaTimer, &QTimer::timeout, this, &TargetTableModel::timeout);

    this->etaTimer->start(1000);
}

int TargetTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return this->datas->count();
}

int TargetTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return COLUMN;
}

QVariant TargetTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QString("Target");
            break;
        case 1:
            return QString("ETA");
            break;
        case 2:
            return QString("Time to finish");
            break;
        default:
            return QVariant();
        }
    }
    else if(role == Qt::DisplayRole && orientation == Qt::Vertical){
        return QString("%1").arg(section+1);
    }
    else{
        return QVariant();
    }
}

QVariant TargetTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    if(role == Qt::DisplayRole){
        switch(index.column()){
        case 0:
            return this->datas->at(index.row())->getName();
            break;
        case 1:
            return this->datas->at(index.row())->getFinishTime().toString();
            break;
        case 2:
        {
            if(this->datas->at(index.row())->isFinished()){
                return QString("Finished");
            }
            int hours   = QTime::currentTime().secsTo(this->datas->at(index.row())->getFinishTime())/3600;
            int mins    = (QTime::currentTime().secsTo(this->datas->at(index.row())->getFinishTime()) -
                     hours*3600) / 60;
            int secs    = QTime::currentTime().secsTo(this->datas->at(index.row())->getFinishTime()) -
                        hours * 3600 - mins * 60;
            return QString("%1h %2m %3s").arg(QString::number(hours), QString::number(mins), QString::number(secs));
            break;
        }
        default:
            return QVariant();
        }
    }
    else if(role == Qt::BackgroundColorRole){
        switch(index.column()){
        case 0:
            if(this->datas->at(index.row())->isFinished())
                return QColor(Qt::green);
            else
                QVariant();
            break;
        case 1:
            if(this->datas->at(index.row())->isFinished())
                return QColor(Qt::green);
            else
                QVariant();
            break;
        case 2:
            if(this->datas->at(index.row())->isFinished())
                return QColor(Qt::green);
            else
                QVariant();
            break;
        default:
            return QVariant();
        }
    }
    else{
        return QVariant();
    }

    return QVariant();

}

void TargetTableModel::appendTarget(Target *target)
{
    beginInsertRows(QModelIndex(),this->rowCount(),this->rowCount());
    this->datas->append(target);
    connect(target, &Target::finished, this, &TargetTableModel::targetFinished);
    endInsertRows();
}

bool TargetTableModel::removeRows(int row, int count, const QModelIndex &parent = QModelIndex())
{
    beginRemoveRows(parent, row, row+count-1);
    auto begin = this->datas->begin() + row;
    auto end   = begin + count;

    qDeleteAll(begin, end);

    this->datas->erase(begin, end);

    endRemoveRows();

    return true;
}

void TargetTableModel::timeout()
{
    emit dataChanged(index(0,0),index(this->rowCount()-1, this->columnCount()-1));
}

void TargetTableModel::targetFinished()
{
    QObject *sender = QObject::sender();

    int index = this->datas->indexOf(dynamic_cast<Target *>(sender));

    if(index != -1){
        QMessageBox::information(
                    dynamic_cast<QWidget *>(this->parent),
                    QString("%1 has finished").arg(this->datas->at(index)->getName()),
                    QString("%1 has finished and now you have the resources!").arg(this->datas->at(index)->getName())
                    );
    }
    else{
        qDebug() << "Nope";
    }
}
