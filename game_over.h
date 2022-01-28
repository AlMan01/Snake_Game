#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QWidget>
#include "playwindow.h"

namespace Ui {
class Game_over;
}

class Game_over : public QWidget
{
    Q_OBJECT

public:
    explicit Game_over(QWidget *parent = nullptr);
    ~Game_over();

private slots:
    void on_pushButton_3_clicked();


private:
    Ui::Game_over *ui;
    PlayWindow* pw;
};

#endif // GAME_OVER_H
