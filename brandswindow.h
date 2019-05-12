#ifndef BRANDSWINDOW_H
#define BRANDSWINDOW_H
#include "database.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QTableView>

namespace Ui {
class brandsWindow;
}

class BrandsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrandsWindow(QWidget *parent = nullptr);
    ~BrandsWindow();
    QSqlTableModel* model;
public slots:
    void slotAddBrand();

private:
    Ui::brandsWindow *ui;
    void setTableModel();
    void setTableView();
};

#endif // BRANDSWINDOW_H
