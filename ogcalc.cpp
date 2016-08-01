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
}

OgCalc::~OgCalc()
{
    delete ui;
}

void OgCalc::on_actionNew_Target_triggered()
{
    qDebug() << "new target";
    this->targetModel->appendTarget(new Target("proviamo"));
    this->repaint();
}
