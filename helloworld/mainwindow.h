#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
void reshow();
void on_PbImageFuzzy_clicked();

void on_PbImageStrength_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
