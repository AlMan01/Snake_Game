#include "speedwindow.h"
#include "ui_speedwindow.h"
#include <QPixmap>

SpeedWindow::SpeedWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpeedWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Qt/Qt_project/Snake_game3/pics/second.png");

    ui->label_2->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
}

SpeedWindow::~SpeedWindow()
{
    delete ui;
}

void SpeedWindow::on_pushButton_clicked()
{
    NormalWindow* nw = new NormalWindow();
    pw = new PlayWindow();
    //nw = pw->get();
    nw->slow_flag = true;

    //pw->get() = new NormalWindow();
    pw->setWindowTitle("Mode");
    pw->show();
    hide();
}


/*void SpeedWindow::on_pushButton_2_clicked()
{
    NormalWindow* nw = new NormalWindow();
    nw->medium_flag = true;
    pw = new PlayWindow();
    pw->show();
    hide();
}


void SpeedWindow::on_pushButton_3_clicked()
{
    NormalWindow* nw = new NormalWindow();
    nw->fast_flag = true;
    pw = new PlayWindow();
    pw->show();
    hide();
}*/

