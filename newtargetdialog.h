#ifndef NEWTARGETDIALOG_H
#define NEWTARGETDIALOG_H

#include <QDialog>

namespace Ui {
class newTargetDialog;
}

class newTargetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newTargetDialog(QWidget *parent = 0);
    ~newTargetDialog();

private:
    Ui::newTargetDialog *ui;
};

#endif // NEWTARGETDIALOG_H
