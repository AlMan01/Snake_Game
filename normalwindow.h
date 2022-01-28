#ifndef NORMALWINDOW_H
#define NORMALWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QLCDNumber>
#include <QTime>
#include "wall.h"
#include "gameover.h"
#include "ui_gameover.h"



namespace Ui {
class NormalWindow;
}

class NormalWindow : public QWidget
{
private:
    Q_OBJECT

    QLCDNumber *lcd = new QLCDNumber();
    int score = 0;
    Apple *ap = new Apple();
    Wall *wl = new Wall();
    bool game_over = false;
    QVector<QPoint> snake_coordinates;
    enum DIR {STOP, LEFT, RIGHT, UP, DOWN};
    DIR move;
    int timerID;

    //static NormalWindow* shared_instance;


public:
    explicit NormalWindow(QWidget *parent = nullptr);
    bool infinity_flag, lvl_1_flag, lvl_3_flag = false;
    void move_dir();
    void check_field();
    void check_apple();
    void gameOver();
    void draw();
    void check_wall();
    void setup();
    void message(QMessageBox&);
    //static NormalWindow* get_instance();
    void get_delay();
    bool slow_flag = false;
    bool medium_flag = false;
    bool fast_flag = false;

    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void timerEvent(QTimerEvent*event) override;
    int DELAY = 100;
    ~NormalWindow();

private:
    Ui::NormalWindow *ui;
    GameOver *go;

};

#endif // NORMALWINDOW_H
