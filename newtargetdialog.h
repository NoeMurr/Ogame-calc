#ifndef NEWTARGETDIALOG_H
#define NEWTARGETDIALOG_H

#include <QDialog>
#include "target.h"
#include "newtargettablemodel.h"
namespace Ui {
class newTargetDialog;
}

class NewTargetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTargetDialog(QWidget *parent = 0);
    ~NewTargetDialog();

private:
    Ui::newTargetDialog *ui;
    NewTargetTableModel *tableModel;
    Target *target;

signals:
    void newTargetGenerated(Target *newTarget);

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
};

#endif // NEWTARGETDIALOG_H
