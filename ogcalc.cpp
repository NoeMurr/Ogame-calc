#include "ogcalc.h"
#include "ui_ogcalc.h"

OgCalc::OgCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OgCalc)
{
    ui->setupUi(this);

    this->targets = new QList<Target *>();

    this->targetModel = new TargetTableModel(this, this->targets);

    ui->tableView->setModel(this->targetModel);

    for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

OgCalc::~OgCalc()
{
    delete ui;
}

void OgCalc::on_actionNew_Target_triggered()
{
    NewTargetDialog dialog;
    connect(&dialog,&NewTargetDialog::newTargetGenerated,this,&OgCalc::newTarget);
    dialog.exec();
}

void OgCalc::on_actionDelete_target_triggered()
{
    auto items = ui->tableView->selectionModel()->selectedIndexes();
    if(items.count() == 1)
        this->targetModel->removeRows(items.at(0).row(),1, QModelIndex());
    else{
        auto count = items.at(items.count()-1).row()-items.at(0).row() +1;
        this->targetModel->removeRows(items.at(0).row(),count, QModelIndex());
    }
}

void OgCalc::newTarget(Target *newTarget)
{
    this->targetModel->appendTarget(newTarget);
}
