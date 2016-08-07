#ifndef TARGETTABLEMODEL_H
#define TARGETTABLEMODEL_H
#include <QAbstractTableModel>
#include "target.h"
#include "resourcestimer.h"
#include <QList>
#include <QTimer>
#include <QtAlgorithms>

#define COLUMN 3

class TargetTableModel : public QAbstractTableModel
{
public:
    explicit TargetTableModel(QObject *parent, QList<Target *> *datas);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void appendTarget(Target *target);

    bool removeRows(int row, int count, const QModelIndex &parent);

public slots:
    void timeout();
private:
    QTimer * etaTimer;
    QList<Target*> *datas;

};

#endif // TARGETTABLEMODEL_H
