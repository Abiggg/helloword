/********************************************************************************
** Form generated from reading UI file 'winimagestrength.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINIMAGESTRENGTH_H
#define UI_WINIMAGESTRENGTH_H

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

class Ui_WinImageStrength
{
public:
    QLabel *LbFiterSize;
    QLabel *LbInputImage;
    QSlider *horizontalSlider;
    QLabel *LbOutputImage;
    QLabel *LbMethod;
    QPushButton *PbOpenFile;
    QPushButton *PbFilter;
    QPushButton *PbCenter;
    QPushButton *PbAverage;
    QPushButton *PbMax;
    QPushButton *PbbackToMain;
    QPushButton *PbSaveFile;
    QTextEdit *textEdit;

    void setupUi(QWidget *WinImageStrength)
    {
        if (WinImageStrength->objectName().isEmpty())
            WinImageStrength->setObjectName(QStringLiteral("WinImageStrength"));
        WinImageStrength->resize(1177, 718);
        LbFiterSize = new QLabel(WinImageStrength);
        LbFiterSize->setObjectName(QStringLiteral("LbFiterSize"));
        LbFiterSize->setGeometry(QRect(70, 610, 76, 19));
        LbInputImage = new QLabel(WinImageStrength);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(80, 80, 411, 331));
        horizontalSlider = new QSlider(WinImageStrength);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 630, 541, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        LbOutputImage = new QLabel(WinImageStrength);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(530, 70, 391, 351));
        LbMethod = new QLabel(WinImageStrength);
        LbMethod->setObjectName(QStringLiteral("LbMethod"));
        LbMethod->setGeometry(QRect(990, 210, 76, 19));
        PbOpenFile = new QPushButton(WinImageStrength);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(980, 90, 131, 41));
        PbFilter = new QPushButton(WinImageStrength);
        PbFilter->setObjectName(QStringLiteral("PbFilter"));
        PbFilter->setGeometry(QRect(980, 430, 131, 41));
        PbCenter = new QPushButton(WinImageStrength);
        PbCenter->setObjectName(QStringLiteral("PbCenter"));
        PbCenter->setGeometry(QRect(980, 370, 131, 41));
        PbAverage = new QPushButton(WinImageStrength);
        PbAverage->setObjectName(QStringLiteral("PbAverage"));
        PbAverage->setGeometry(QRect(980, 250, 131, 41));
        PbMax = new QPushButton(WinImageStrength);
        PbMax->setObjectName(QStringLiteral("PbMax"));
        PbMax->setGeometry(QRect(980, 310, 131, 41));
        PbbackToMain = new QPushButton(WinImageStrength);
        PbbackToMain->setObjectName(QStringLiteral("PbbackToMain"));
        PbbackToMain->setGeometry(QRect(960, 580, 191, 71));
        PbSaveFile = new QPushButton(WinImageStrength);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(980, 150, 131, 41));
        textEdit = new QTextEdit(WinImageStrength);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 211, 41));

        retranslateUi(WinImageStrength);

        QMetaObject::connectSlotsByName(WinImageStrength);
    } // setupUi

    void retranslateUi(QWidget *WinImageStrength)
    {
        WinImageStrength->setWindowTitle(QApplication::translate("WinImageStrength", "Form", nullptr));
        LbFiterSize->setText(QApplication::translate("WinImageStrength", "filter size", nullptr));
        LbInputImage->setText(QApplication::translate("WinImageStrength", "input image", nullptr));
        LbOutputImage->setText(QApplication::translate("WinImageStrength", "output image", nullptr));
        LbMethod->setText(QApplication::translate("WinImageStrength", "method", nullptr));
        PbOpenFile->setText(QApplication::translate("WinImageStrength", "Open File", nullptr));
        PbFilter->setText(QApplication::translate("WinImageStrength", "Filter", nullptr));
        PbCenter->setText(QApplication::translate("WinImageStrength", "Center", nullptr));
        PbAverage->setText(QApplication::translate("WinImageStrength", "Average", nullptr));
        PbMax->setText(QApplication::translate("WinImageStrength", "Max", nullptr));
        PbbackToMain->setText(QApplication::translate("WinImageStrength", "back to main", nullptr));
        PbSaveFile->setText(QApplication::translate("WinImageStrength", "Save File", nullptr));
        textEdit->setHtml(QApplication::translate("WinImageStrength", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600;\">Image Strength</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinImageStrength: public Ui_WinImageStrength {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINIMAGESTRENGTH_H
