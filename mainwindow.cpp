#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "info.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("D:/Qt/Qt_project/Snake_game3/pics/first.jpg");
    ui->label_picture->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
    ui->label_2->setPixmap(pix.scaled(250,500,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    sw = new SpeedWindow();
    sw->setWindowTitle("Speed");
    sw->show();
    hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    Info* inf = new Info();
    inf->setWindowTitle("Information");
    inf->show();
    hide();

}

