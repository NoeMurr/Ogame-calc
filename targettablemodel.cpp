#include "targettablemodel.h"

TargetTableModel::TargetTableModel(QObject *parent, QList<Target *> *datas) : QAbstractTableModel(parent)
{
    this->datas = datas;
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
            return this->datas->at(index.row())->getFinishTime();
            break;
        case 2:
            return QTime::currentTime().secsTo(this->datas->at(index.row())->getFinishTime());
            break;
        default:
            return QVariant();
        }
    }
    else{
        return QVariant();
    }

}

void TargetTableModel::appendTarget(Target *target)
{
    beginInsertRows(QModelIndex(),this->rowCount(),this->rowCount());
    this->datas->append(target);
    qDebug() << "righe totali: " << this->rowCount();
    //emit this->dataChanged(this->index(0,0), this->index(this->rowCount()-1,this->columnCount()-1));
    endInsertRows();
}

bool TargetTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    return true;
}
