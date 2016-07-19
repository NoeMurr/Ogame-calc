#ifndef OGCALC_H
#define OGCALC_H

#include <QMainWindow>

namespace Ui {
class OgCalc;
}

class OgCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit OgCalc(QWidget *parent = 0);
    ~OgCalc();

private:
    Ui::OgCalc *ui;
};

#endif // OGCALC_H
