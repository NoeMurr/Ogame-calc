#include "newtargettablemodel.h"

NewTargetTableModel::NewTargetTableModel(Target *target)
{
    this->target = target;
}

int NewTargetTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return this->target->getTimers()->count();
}

int NewTargetTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant NewTargetTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch(section){
        case 0:
            return QString("Name");
            break;
        case 1:
            return QString("Amount");
            break;
        case 2:
            return QString("Increse per hour");
            break;
        case 3:
            return QString("Final Amount");
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

QVariant NewTargetTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    if(role == Qt::DisplayRole){
        switch(index.column()){
        case 0:
            return this->target->getTimers()->at(index.row())->getName();
            break;
        case 1:
            return QString::number(this->target->getTimers()->at(index.row())->getAmount());
            break;
        case 2:
            return QString::number(
                        static_cast<qint64>
                        (this->target->getTimers()->at(index.row())->getIncPerSec() * 3600)
                        );
            break;
        case 3:
            return QString::number(this->target->getTimers()->at(index.row())->getFinalAmount());
            break;
        default:
            return QVariant();
        }
    }
    else{
        return QVariant();
    }
}

void NewTargetTableModel::appendTimer(QString name, qreal amount, qreal incPerHour , qint64 finalAmount)
{
    beginInsertRows(QModelIndex(),this->rowCount(),this->rowCount());
    this->target->addTimer(name,amount,incPerHour,finalAmount);
    endInsertRows();
}

bool NewTargetTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent,row,row+count-1);
    this->target->removeTimers(row, count);
    endRemoveRows();

    return true;
}

bool NewTargetTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole && index.isValid()){
        switch(index.column()){
        case 0:
            this->target->getTimers()->at(index.row())->setName(value.toString());
            break;
        case 1:
            this->target->getTimers()->at(index.row())->setAmount(value.toFloat());
            break;
        case 2:
            this->target->getTimers()->at(index.row())->setIncPerSec(value.toFloat()/3600);
            break;
        case 3:
            this->target->getTimers()->at(index.row())->setFinalAmount(value.toFloat());
            break;
        default:
            return false;
        }
        return true;
    }
     else{
            return false;
    }
}

Qt::ItemFlags NewTargetTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
            return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
