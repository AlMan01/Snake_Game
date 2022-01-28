#ifndef LVLWINDOW_H
#define LVLWINDOW_H

#include <QWidget>
#include "normalwindow.h"

namespace Ui {
class LvlWindow;
}

class LvlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LvlWindow(QWidget *parent = nullptr);
    ~LvlWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::LvlWindow *ui;
    NormalWindow *nw;
};

#endif // LVLWINDOW_H
