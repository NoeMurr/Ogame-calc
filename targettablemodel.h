#ifndef TARGETTABLEMODEL_H
#define TARGETTABLEMODEL_H
#include <QAbstractTableModel>
#include "target.h"
#include "resourcestimer.h"
#include <QList>
#include <QTimer>
#include <QtAlgorithms>
#include <QColor>
#include <QMessageBox>

#define COLUMN 3

/**
 * @brief The TargetTableModel class
 *
 * Simple table model to show a list of Target types.
 *
 */
class TargetTableModel : public QAbstractTableModel
{
public:
    explicit TargetTableModel(QObject *parent, QList<Target *> *datas);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    /**
     * @brief appendTarget
     * @param target
     *
     * This method permits to add a target to the list of targets.
     *
     */
    void appendTarget(Target *target);

    bool removeRows(int row, int count, const QModelIndex &parent);

public slots:
    /**
     * @brief timeout
     *
     * It's connected to the timeout of the timer necessary to updates.
     *
     */
    void timeout();

    /**
     * @brief targetFinished
     *
     * when a target is finished show an information MessageBox to inform the user.
     *
     */
    void targetFinished();

private:
    /**
     * @brief etaTimer
     *
     * Timer necessary for updating.
     *
     */
    QTimer * etaTimer;

    /**
     * @brief datas
     *
     * the list of Targets to show.
     *
     */
    QList<Target*> *datas;

    /**
     * @brief parent
     *
     * the parent widget.
     *
     */
    QObject *parent;

};

#endif // TARGETTABLEMODEL_H
