#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "winimagefuzzy.h"
#include "winimagestrength.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PbImageFuzzy_clicked()
{
    this->hide();//主界面关闭
    WinImageFuzzy *fuzzy = new WinImageFuzzy();//新建子界面
    connect(fuzzy,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    fuzzy->show();//子界面出现
}

void MainWindow::reshow()
{
    this->show();
}

void MainWindow::on_PbImageStrength_clicked()
{
    this->hide();//主界面关闭
    WinImageStrength *fuzzy = new WinImageStrength();//新建子界面
    connect(fuzzy,SIGNAL(WinDisplay()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    fuzzy->show();//子界面出现
}
