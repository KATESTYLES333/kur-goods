#include <QApplication>
#include "database.h"
#include "countrieswindow.h"
#include "brandswindow.h"
#include "goodswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Database db;
    BrandsWindow bw;
    bw.show();
    CountriesWindow cw;
    cw.show();
    goodsWindow gw;
    gw.show();
    return a.exec();
}
