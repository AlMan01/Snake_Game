#include "game_over.h"
#include "ui_game_over.h"

Game_over::Game_over(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_over)
{
    ui->setupUi(this);
}

Game_over::~Game_over()
{
    delete ui;
}

void Game_over::on_pushButton_3_clicked()
{
    pw = new PlayWindow();
    pw->show();
    hide();
}

