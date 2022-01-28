#include "info.h"
#include "ui_info.h"
#include "mainwindow.h"

Info::Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}

void Info::on_pushButton_clicked()
{
    MainWindow* mw = new MainWindow();
    mw->show();
    hide();
}

