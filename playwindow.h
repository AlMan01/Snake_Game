#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>
//#include "normalwindow.h"
#include "lvlwindow.h"
#include "ui_lvlwindow.h"




namespace Ui {
class PlayWindow;
}

class PlayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();
    NormalWindow* get();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::PlayWindow *ui;
    NormalWindow *nw;
    LvlWindow *lw;
};

#endif // PLAYWINDOW_H
