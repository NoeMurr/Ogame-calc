#include "newtargetdialog.h"
#include "ui_newtargetdialog.h"

newTargetDialog::newTargetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newTargetDialog)
{
    ui->setupUi(this);
}

newTargetDialog::~newTargetDialog()
{
    delete ui;
}
