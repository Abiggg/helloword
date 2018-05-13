#ifndef WINDOW1_H
#define WINDOW1_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class window1;
}

class window1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit window1(QWidget *parent = 0);
    ~window1();
public:
    void setupconnection();

public slots:
    void on_pushButton_clicked();

private:
    Ui::window1 *ui;
    window2 wind2;
};

#endif //
