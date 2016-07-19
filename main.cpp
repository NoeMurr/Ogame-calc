#include "ogcalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OgCalc w;
    w.show();

    return a.exec();
}
