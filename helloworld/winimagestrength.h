#ifndef WINIMAGESTRENGTH_H
#define WINIMAGESTRENGTH_H

#include <QWidget>

namespace Ui {
class WinImageStrength;
}

class WinImageStrength : public QWidget
{
    Q_OBJECT

public:
    explicit WinImageStrength(QWidget *parent = 0);
    ~WinImageStrength();

private slots:
    void on_PbOpenFile_clicked();

    void on_PbbackToMain_clicked();

    void on_PbSaveFile_clicked();

    void on_PbAverage_clicked();

signals:
    void WinDisplay();

private:
    Ui::WinImageStrength *ui;
};

#endif // WINIMAGESTRENGTH_H
