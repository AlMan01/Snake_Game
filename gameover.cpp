#include "speedwindow.h"
#include <QPixmap>

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    QPixmap pix("D:/Qt/Qt_project/Snake_game3/pics/sad.png");
    ui->label_go->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    SpeedWindow* sw = new SpeedWindow();
    sw->show();
    hide();
}


void GameOver::on_pushButton_2_clicked()
{
    hide();
}

