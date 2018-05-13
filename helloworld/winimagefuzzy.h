#ifndef WINIMAGEFUZZY_H
#define WINIMAGEFUZZY_H

#include <QWidget>

namespace Ui {
class WinImageFuzzy;
}

class WinImageFuzzy : public QWidget
{
    Q_OBJECT

public:
    explicit WinImageFuzzy(QWidget *parent = 0);
    ~WinImageFuzzy();

private slots:
    void on_PbOpenFile_clicked();

    void on_PbbackToMain_clicked();

signals:
    void WinDisplay();

private:
    Ui::WinImageFuzzy *ui;
};

#endif // WINIMAGEFUZZY_H
