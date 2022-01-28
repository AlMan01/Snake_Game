#ifndef SPEEDWINDOW_H
#define SPEEDWINDOW_H

#include <QWidget>
#include "playwindow.h"


namespace Ui {
class SpeedWindow;
}

class SpeedWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SpeedWindow(QWidget *parent = nullptr);
    ~SpeedWindow();

private slots:
    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

private:
    Ui::SpeedWindow *ui;
    PlayWindow *pw;
};

#endif // SPEEDWINDOW_H
