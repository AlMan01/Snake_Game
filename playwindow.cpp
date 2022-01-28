#include "playwindow.h"
#include "ui_playwindow.h"
#include <QPixmap>

PlayWindow::PlayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Qt/Qt_project/Snake_game3/pics/first.png");
    ui->label_picc->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
    //ui->label_2->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

NormalWindow *PlayWindow::get()
{
    return nw;
}

void PlayWindow::on_pushButton_2_clicked()
{
    lw = new LvlWindow();
    lw->setWindowTitle("Levels");
    lw->show();
    hide();
}


void PlayWindow::on_pushButton_clicked()
{
    nw = new NormalWindow();
    nw->infinity_flag = true;
    nw->setWindowTitle("Infinity");
    nw->show();
    hide();
}

