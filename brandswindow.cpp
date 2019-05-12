#include "brandswindow.h"
#include "ui_brandswindow.h"

BrandsWindow::BrandsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::brandsWindow)
{
    ui->setupUi(this);
    setTableModel();
    setTableView();
    connect(ui->pushButton, &QPushButton::clicked, this, &BrandsWindow::slotAddBrand);
}

BrandsWindow::~BrandsWindow()
{
    delete ui;
}

void BrandsWindow::slotAddBrand()
{
    if(!Database::insertIntoTableBrands(QVariant{ui->lineEdit->text()})){
        QMessageBox::information(this, "error","error");
    }
    else{
        QMessageBox::information(this, "show information","u are right");
        model->select();
    }
}

void BrandsWindow::setTableModel()
{
    model = new QSqlTableModel;
    model->setTable("brands");
    model->setHeaderData(1, Qt::Horizontal, QVariant("brands"));
    model->select();
}

void BrandsWindow::setTableView()
{
    ui->brandstableView->setModel(model);
    ui->brandstableView->setColumnHidden(0, true);

}
