#include "countrieswindow.h"
#include "ui_countrieswindow.h"

CountriesWindow::CountriesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountriesWindow)
{
    ui->setupUi(this);
    setTableModel();
    setTableView();
   connect(ui->AddCountry, &QPushButton::clicked, this, &CountriesWindow::slotAddCountry);
}

CountriesWindow::~CountriesWindow()
{
    delete ui;
}

void CountriesWindow::setTableModel()
{
    model = new QSqlTableModel;
    model->setTable("Countries");
    model->setHeaderData(1, Qt::Horizontal, QVariant("Countries"));
    model->select();
}

void CountriesWindow::setTableView()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
}

void CountriesWindow::slotAddCountry()
{
    if(!Database::insertIntoTableCountries(QVariant{ui->lineEditInputCountry->text()})){
        QMessageBox::information(this, "error","error");
    }
    else{
        QMessageBox::information(this, "show information","u are right");
        model->select();
        ui->lineEditInputCountry->setText("");
    }
}
