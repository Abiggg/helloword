/********************************************************************************
** Form generated from reading UI file 'winimagetransform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINIMAGETRANSFORM_H
#define UI_WINIMAGETRANSFORM_H

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

class Ui_WinImageTransform
{
public:
    QPushButton *PbEquration;
    QSlider *horizontalSlider;
    QPushButton *PbSaveFile;
    QLabel *LbFiterSize;
    QPushButton *PbOpenFile;
    QLabel *LbInputImage;
    QPushButton *PbbackToMain;
    QPushButton *PbRation;
    QPushButton *PbGaussian;
    QLabel *LbMethod;
    QPushButton *PbBiarization;
    QTextEdit *Topic;
    QLabel *LbOutputImage;
    QPushButton *PbYMinior;

    void setupUi(QWidget *WinImageTransform)
    {
        if (WinImageTransform->objectName().isEmpty())
            WinImageTransform->setObjectName(QStringLiteral("WinImageTransform"));
        WinImageTransform->resize(1189, 700);
        PbEquration = new QPushButton(WinImageTransform);
        PbEquration->setObjectName(QStringLiteral("PbEquration"));
        PbEquration->setGeometry(QRect(1010, 370, 131, 41));
        horizontalSlider = new QSlider(WinImageTransform);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 630, 541, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        PbSaveFile = new QPushButton(WinImageTransform);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(1010, 150, 131, 41));
        LbFiterSize = new QLabel(WinImageTransform);
        LbFiterSize->setObjectName(QStringLiteral("LbFiterSize"));
        LbFiterSize->setGeometry(QRect(70, 600, 101, 31));
        QFont font;
        font.setPointSize(16);
        LbFiterSize->setFont(font);
        PbOpenFile = new QPushButton(WinImageTransform);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(1010, 90, 131, 41));
        LbInputImage = new QLabel(WinImageTransform);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(70, 80, 411, 331));
        PbbackToMain = new QPushButton(WinImageTransform);
        PbbackToMain->setObjectName(QStringLiteral("PbbackToMain"));
        PbbackToMain->setGeometry(QRect(990, 580, 191, 71));
        PbRation = new QPushButton(WinImageTransform);
        PbRation->setObjectName(QStringLiteral("PbRation"));
        PbRation->setGeometry(QRect(1010, 430, 131, 41));
        PbGaussian = new QPushButton(WinImageTransform);
        PbGaussian->setObjectName(QStringLiteral("PbGaussian"));
        PbGaussian->setGeometry(QRect(1010, 310, 131, 41));
        LbMethod = new QLabel(WinImageTransform);
        LbMethod->setObjectName(QStringLiteral("LbMethod"));
        LbMethod->setGeometry(QRect(1020, 210, 76, 19));
        PbBiarization = new QPushButton(WinImageTransform);
        PbBiarization->setObjectName(QStringLiteral("PbBiarization"));
        PbBiarization->setGeometry(QRect(1010, 250, 131, 41));
        Topic = new QTextEdit(WinImageTransform);
        Topic->setObjectName(QStringLiteral("Topic"));
        Topic->setGeometry(QRect(30, 20, 161, 31));
        LbOutputImage = new QLabel(WinImageTransform);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(540, 90, 391, 351));
        PbYMinior = new QPushButton(WinImageTransform);
        PbYMinior->setObjectName(QStringLiteral("PbYMinior"));
        PbYMinior->setGeometry(QRect(1010, 490, 131, 41));

        retranslateUi(WinImageTransform);

        QMetaObject::connectSlotsByName(WinImageTransform);
    } // setupUi

    void retranslateUi(QWidget *WinImageTransform)
    {
        WinImageTransform->setWindowTitle(QApplication::translate("WinImageTransform", "Form", nullptr));
        PbEquration->setText(QApplication::translate("WinImageTransform", "Equration", nullptr));
        PbSaveFile->setText(QApplication::translate("WinImageTransform", "Save File", nullptr));
        LbFiterSize->setText(QApplication::translate("WinImageTransform", "filter size:", nullptr));
        PbOpenFile->setText(QApplication::translate("WinImageTransform", "Open File", nullptr));
        LbInputImage->setText(QApplication::translate("WinImageTransform", "input image", nullptr));
        PbbackToMain->setText(QApplication::translate("WinImageTransform", "back to main", nullptr));
        PbRation->setText(QApplication::translate("WinImageTransform", "Ratation", nullptr));
        PbGaussian->setText(QApplication::translate("WinImageTransform", "Grayscale", nullptr));
        LbMethod->setText(QApplication::translate("WinImageTransform", "method", nullptr));
        PbBiarization->setText(QApplication::translate("WinImageTransform", "Binarization", nullptr));
        Topic->setHtml(QApplication::translate("WinImageTransform", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Image Transform</span></p></body></html>", nullptr));
        LbOutputImage->setText(QApplication::translate("WinImageTransform", "output image", nullptr));
        PbYMinior->setText(QApplication::translate("WinImageTransform", "minior_Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinImageTransform: public Ui_WinImageTransform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINIMAGETRANSFORM_H
