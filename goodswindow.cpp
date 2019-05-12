#include "goodswindow.h"
#include "ui_goodswindow.h"

goodsWindow::goodsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::goodsWindow)
{
    ui->setupUi(this);
    countryModel = new ComboBoxModel;
    brandModel = new ComboBoxModel;
    ui->ComboBoxBrand->setModel(brandModel);
    ui->ComboBoxCountry->setModel(countryModel);
}

goodsWindow::~goodsWindow()
{
    delete ui;
}
