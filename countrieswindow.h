#ifndef COUNTRIESWINDOW_H
#define COUNTRIESWINDOW_H
#include <QMessageBox>
#include "database.h"
#include <QMainWindow>

namespace Ui {
class CountriesWindow;
}

class CountriesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CountriesWindow(QWidget *parent = nullptr);
    ~CountriesWindow();
    QSqlTableModel* model;
private:
    Ui::CountriesWindow *ui;
    void setTableModel();
    void setTableView();
public slots:
    void slotAddCountry();

};

#endif // COUNTRIESWINDOW_H
