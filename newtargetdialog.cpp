#include "newtargetdialog.h"
#include "ui_newtargetdialog.h"

NewTargetDialog::NewTargetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newTargetDialog)
{
    ui->setupUi(this);

    this->target = new Target("NewTarget");
    ui->nameLineEdit->setText(this->target->getName());
    this->tableModel = new NewTargetTableModel(this->target);

    ui->tableView->setModel(this->tableModel);
    ui->tableView->setAutoScroll(true);

    for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }

}

NewTargetDialog::~NewTargetDialog()
{
    delete ui;
    delete this->tableModel;
}


void NewTargetDialog::on_addButton_clicked()
{
    this->tableModel->appendTimer("");
}

void NewTargetDialog::on_removeButton_clicked()
{
    auto items = ui->tableView->selectionModel()->selectedIndexes();
    auto count = items.at(items.count()-1).row()-items.at(0).row() +1;
    qDebug() << count;

    this->tableModel->removeRows(items.at(0).row(),count,QModelIndex());
}

void NewTargetDialog::on_buttonBox_accepted()
{
    emit newTargetGenerated(this->target);

    this->close();
}

void NewTargetDialog::on_buttonBox_rejected()
{
    delete this->target;
    this->close();
}
