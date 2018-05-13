#include "window1.h"
#include "ui_mainwindow.h"

window1::window1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window1)
{
    ui->setupUi(this);
}

window1::~window1()
{
    delete ui;
}

void window1::setupconnection()
{
    /*SIGNAL AND SLOT*/
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

void window1::on_pushButton_clicked()
{
    this->hide();
    wind2.show();
}
