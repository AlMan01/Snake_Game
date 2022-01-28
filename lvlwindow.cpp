#include "playwindow.h"
#include <QPixmap>

LvlWindow::LvlWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LvlWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Qt/Qt_project/Snake_game3/pics/happy.png");
    //ui->label_picture->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
    ui->label_4->setPixmap(pix.scaled(210,200,Qt::KeepAspectRatio));
    ui->label_6->setPixmap(pix.scaled(210,200,Qt::KeepAspectRatio));
}

LvlWindow::~LvlWindow()
{
    delete ui;
}

void LvlWindow::on_pushButton_clicked()
{
    nw = new NormalWindow();
    nw->lvl_1_flag = true;
    nw->infinity_flag = true;
    nw->setWindowTitle("Level 1");
    nw->show();
    hide();
}


void LvlWindow::on_pushButton_2_clicked()
{
    nw = new NormalWindow();
    nw->lvl_1_flag = false;
    nw->infinity_flag = false;
    nw->setWindowTitle("Level 2");
    nw->show();
    hide();
}


void LvlWindow::on_pushButton_3_clicked()
{
    nw = new NormalWindow();
    nw->lvl_3_flag = true;
    nw->infinity_flag = false;
    nw->setWindowTitle("Level 3");
    nw->show();
    hide();
}

