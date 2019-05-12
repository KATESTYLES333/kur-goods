#ifndef GOODSWINDOW_H
#define GOODSWINDOW_H
#include <combobox.h>

#include <QMainWindow>

namespace Ui {
class goodsWindow;
}

class goodsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit goodsWindow(QWidget *parent = nullptr);
    ~goodsWindow();

private:
    Ui::goodsWindow *ui;
    ComboBoxModel* countryModel;
    ComboBoxModel* brandModel;
};

#endif // GOODSWINDOW_H
