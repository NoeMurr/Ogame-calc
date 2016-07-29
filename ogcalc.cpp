#include "ogcalc.h"
#include "ui_ogcalc.h"

OgCalc::OgCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OgCalc)
{
    ui->setupUi(this);
}

OgCalc::~OgCalc()
{
    delete ui;
}

void OgCalc::updateValue(qint64 row)
{

}
