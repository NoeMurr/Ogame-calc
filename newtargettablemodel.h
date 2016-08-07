#ifndef NEWTARGETTABLEMODEL_H
#define NEWTARGETTABLEMODEL_H
#include <QAbstractTableModel>
#include "target.h"

class NewTargetTableModel : public QAbstractTableModel
{
public:

    explicit NewTargetTableModel(Target * target);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void appendTimer(QString name, qreal amount = 0, qreal incPerHour = 0, qint64 finalAmount = 0);

    bool removeRows(int row, int count, const QModelIndex &parent);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    Target *target;
};

#endif // TIMERSTABLEMODEL_H
