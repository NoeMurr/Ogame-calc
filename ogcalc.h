#ifndef OGCALC_H
#define OGCALC_H

#include <QMainWindow>
#include "target.h"
#include "targettablemodel.h"
#include <QList>
#include "newtargetdialog.h"

namespace Ui {
class OgCalc;
}

class OgCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit OgCalc(QWidget *parent = 0);
    ~OgCalc();

private slots:
    void on_actionNew_Target_triggered();

    void on_actionDelete_target_triggered();

    void newTarget(Target *newTarget);

private:
    Ui::OgCalc *ui;
    QList<Target *> *targets;
    TargetTableModel * targetModel;
};

#endif // OGCALC_H
