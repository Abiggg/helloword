/********************************************************************************
** Form generated from reading UI file 'winimagefuzzy.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINIMAGEFUZZY_H
#define UI_WINIMAGEFUZZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinImageFuzzy
{
public:
    QPushButton *PbAverage;
    QPushButton *PbMax;
    QLabel *LbInputImage;
    QPushButton *PbSaveFile;
    QPushButton *PbCenter;
    QLabel *LbFiterSize;
    QLabel *LbMethod;
    QSlider *horizontalSlider;
    QLabel *LbOutputImage;
    QPushButton *PbOpenFile;
    QPushButton *PbbackToMain;
    QPushButton *PbFilter;
    QTextEdit *textEdit;

    void setupUi(QWidget *WinImageFuzzy)
    {
        if (WinImageFuzzy->objectName().isEmpty())
            WinImageFuzzy->setObjectName(QStringLiteral("WinImageFuzzy"));
        WinImageFuzzy->resize(1195, 684);
        PbAverage = new QPushButton(WinImageFuzzy);
        PbAverage->setObjectName(QStringLiteral("PbAverage"));
        PbAverage->setGeometry(QRect(990, 240, 131, 41));
        PbMax = new QPushButton(WinImageFuzzy);
        PbMax->setObjectName(QStringLiteral("PbMax"));
        PbMax->setGeometry(QRect(990, 300, 131, 41));
        LbInputImage = new QLabel(WinImageFuzzy);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(50, 70, 411, 331));
        PbSaveFile = new QPushButton(WinImageFuzzy);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(990, 140, 131, 41));
        PbCenter = new QPushButton(WinImageFuzzy);
        PbCenter->setObjectName(QStringLiteral("PbCenter"));
        PbCenter->setGeometry(QRect(990, 360, 131, 41));
        LbFiterSize = new QLabel(WinImageFuzzy);
        LbFiterSize->setObjectName(QStringLiteral("LbFiterSize"));
        LbFiterSize->setGeometry(QRect(50, 630, 76, 19));
        LbMethod = new QLabel(WinImageFuzzy);
        LbMethod->setObjectName(QStringLiteral("LbMethod"));
        LbMethod->setGeometry(QRect(1000, 200, 76, 19));
        horizontalSlider = new QSlider(WinImageFuzzy);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(50, 650, 541, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        LbOutputImage = new QLabel(WinImageFuzzy);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(520, 80, 391, 351));
        PbOpenFile = new QPushButton(WinImageFuzzy);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(990, 80, 131, 41));
        PbbackToMain = new QPushButton(WinImageFuzzy);
        PbbackToMain->setObjectName(QStringLiteral("PbbackToMain"));
        PbbackToMain->setGeometry(QRect(970, 570, 191, 71));
        PbFilter = new QPushButton(WinImageFuzzy);
        PbFilter->setObjectName(QStringLiteral("PbFilter"));
        PbFilter->setGeometry(QRect(990, 420, 131, 41));
        textEdit = new QTextEdit(WinImageFuzzy);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 161, 31));

        retranslateUi(WinImageFuzzy);

        QMetaObject::connectSlotsByName(WinImageFuzzy);
    } // setupUi

    void retranslateUi(QWidget *WinImageFuzzy)
    {
        WinImageFuzzy->setWindowTitle(QApplication::translate("WinImageFuzzy", "Form", nullptr));
        PbAverage->setText(QApplication::translate("WinImageFuzzy", "Average", nullptr));
        PbMax->setText(QApplication::translate("WinImageFuzzy", "Max", nullptr));
        LbInputImage->setText(QApplication::translate("WinImageFuzzy", "input image", nullptr));
        PbSaveFile->setText(QApplication::translate("WinImageFuzzy", "Save File", nullptr));
        PbCenter->setText(QApplication::translate("WinImageFuzzy", "Center", nullptr));
        LbFiterSize->setText(QApplication::translate("WinImageFuzzy", "filter size", nullptr));
        LbMethod->setText(QApplication::translate("WinImageFuzzy", "method", nullptr));
        LbOutputImage->setText(QApplication::translate("WinImageFuzzy", "output image", nullptr));
        PbOpenFile->setText(QApplication::translate("WinImageFuzzy", "Open File", nullptr));
        PbbackToMain->setText(QApplication::translate("WinImageFuzzy", "back to main", nullptr));
        PbFilter->setText(QApplication::translate("WinImageFuzzy", "Filter", nullptr));
        textEdit->setHtml(QApplication::translate("WinImageFuzzy", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Image Fuzzy</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinImageFuzzy: public Ui_WinImageFuzzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINIMAGEFUZZY_H
