/********************************************************************************
** Form generated from reading UI file 'winbeatifyphoto.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINBEATIFYPHOTO_H
#define UI_WINBEATIFYPHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinBeatifyPhoto
{
public:
    QPushButton *PbFilter;
    QPushButton *PbSaveFile;
    QPushButton *PbFuzzy;
    QPushButton *PbLast;
    QPushButton *PbGaussian;
    QLabel *LbOutputImage;
    QLabel *LbInputImage;
    QPushButton *PbOpenFile;
    QSlider *VsBrightness;
    QSlider *VsSaturation;
    QSlider *VsConstration;
    QPushButton *PbBiarization;
    QPushButton *PbEquration_k;
    QPushButton *PbGrayScale;
    QPushButton *PbYMinior;
    QPushButton *PbEquration;
    QPushButton *PbNext;
    QPushButton *PbBackToMain;
    QPushButton *PbXMinior;
    QPushButton *PbCorrosion;
    QPushButton *PbEquration_4;
    QPushButton *PbOilPaint;
    QPushButton *PbEquration_6;
    QSpinBox *SbFilter;
    QSpinBox *SbCorrosion;
    QPushButton *PbExpand;
    QSpinBox *SbExpand;
    QPushButton *PbShapen;
    QSpinBox *SbSharpen;
    QPushButton *PbConfirm;
    QSpinBox *SbRatation;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *PbEquration_9;
    QPushButton *PbEquration_10;
    QPushButton *PbLaplaceShape;
    QPushButton *PbClassical;
    QPushButton *PbSketch;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *TbHint;
    QLabel *label_6;
    QPushButton *PbResetAll;
    QSpinBox *SbFuzzy;
    QSpinBox *SbGaussian;
    QSpinBox *spinBox_8;
    QSpinBox *SbOilPaint;
    QSpinBox *SbSketch;

    void setupUi(QWidget *WinBeatifyPhoto)
    {
        if (WinBeatifyPhoto->objectName().isEmpty())
            WinBeatifyPhoto->setObjectName(QStringLiteral("WinBeatifyPhoto"));
        WinBeatifyPhoto->resize(1242, 819);
        PbFilter = new QPushButton(WinBeatifyPhoto);
        PbFilter->setObjectName(QStringLiteral("PbFilter"));
        PbFilter->setGeometry(QRect(700, 490, 131, 41));
        PbSaveFile = new QPushButton(WinBeatifyPhoto);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(10, 550, 131, 41));
        PbFuzzy = new QPushButton(WinBeatifyPhoto);
        PbFuzzy->setObjectName(QStringLiteral("PbFuzzy"));
        PbFuzzy->setGeometry(QRect(470, 490, 131, 41));
        PbLast = new QPushButton(WinBeatifyPhoto);
        PbLast->setObjectName(QStringLiteral("PbLast"));
        PbLast->setGeometry(QRect(10, 610, 131, 41));
        PbGaussian = new QPushButton(WinBeatifyPhoto);
        PbGaussian->setObjectName(QStringLiteral("PbGaussian"));
        PbGaussian->setGeometry(QRect(470, 550, 131, 41));
        LbOutputImage = new QLabel(WinBeatifyPhoto);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(660, 50, 541, 421));
        LbOutputImage->setFrameShadow(QFrame::Raised);
        LbOutputImage->setMidLineWidth(2);
        LbInputImage = new QLabel(WinBeatifyPhoto);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(30, 50, 561, 421));
        PbOpenFile = new QPushButton(WinBeatifyPhoto);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(10, 490, 131, 41));
        VsBrightness = new QSlider(WinBeatifyPhoto);
        VsBrightness->setObjectName(QStringLiteral("VsBrightness"));
        VsBrightness->setGeometry(QRect(1000, 490, 16, 271));
        VsBrightness->setOrientation(Qt::Vertical);
        VsSaturation = new QSlider(WinBeatifyPhoto);
        VsSaturation->setObjectName(QStringLiteral("VsSaturation"));
        VsSaturation->setGeometry(QRect(1040, 490, 16, 271));
        VsSaturation->setOrientation(Qt::Vertical);
        VsConstration = new QSlider(WinBeatifyPhoto);
        VsConstration->setObjectName(QStringLiteral("VsConstration"));
        VsConstration->setGeometry(QRect(1080, 490, 16, 271));
        VsConstration->setOrientation(Qt::Vertical);
        PbBiarization = new QPushButton(WinBeatifyPhoto);
        PbBiarization->setObjectName(QStringLiteral("PbBiarization"));
        PbBiarization->setGeometry(QRect(170, 670, 131, 41));
        PbEquration_k = new QPushButton(WinBeatifyPhoto);
        PbEquration_k->setObjectName(QStringLiteral("PbEquration_k"));
        PbEquration_k->setGeometry(QRect(320, 490, 131, 41));
        PbGrayScale = new QPushButton(WinBeatifyPhoto);
        PbGrayScale->setObjectName(QStringLiteral("PbGrayScale"));
        PbGrayScale->setGeometry(QRect(170, 610, 131, 41));
        PbYMinior = new QPushButton(WinBeatifyPhoto);
        PbYMinior->setObjectName(QStringLiteral("PbYMinior"));
        PbYMinior->setGeometry(QRect(170, 550, 131, 41));
        PbEquration = new QPushButton(WinBeatifyPhoto);
        PbEquration->setObjectName(QStringLiteral("PbEquration"));
        PbEquration->setGeometry(QRect(170, 730, 131, 41));
        PbNext = new QPushButton(WinBeatifyPhoto);
        PbNext->setObjectName(QStringLiteral("PbNext"));
        PbNext->setGeometry(QRect(10, 670, 131, 41));
        PbBackToMain = new QPushButton(WinBeatifyPhoto);
        PbBackToMain->setObjectName(QStringLiteral("PbBackToMain"));
        PbBackToMain->setGeometry(QRect(10, 730, 131, 41));
        PbXMinior = new QPushButton(WinBeatifyPhoto);
        PbXMinior->setObjectName(QStringLiteral("PbXMinior"));
        PbXMinior->setGeometry(QRect(170, 490, 131, 41));
        PbCorrosion = new QPushButton(WinBeatifyPhoto);
        PbCorrosion->setObjectName(QStringLiteral("PbCorrosion"));
        PbCorrosion->setGeometry(QRect(700, 550, 131, 41));
        PbEquration_4 = new QPushButton(WinBeatifyPhoto);
        PbEquration_4->setObjectName(QStringLiteral("PbEquration_4"));
        PbEquration_4->setGeometry(QRect(470, 610, 131, 41));
        PbOilPaint = new QPushButton(WinBeatifyPhoto);
        PbOilPaint->setObjectName(QStringLiteral("PbOilPaint"));
        PbOilPaint->setGeometry(QRect(470, 670, 131, 41));
        PbEquration_6 = new QPushButton(WinBeatifyPhoto);
        PbEquration_6->setObjectName(QStringLiteral("PbEquration_6"));
        PbEquration_6->setGeometry(QRect(700, 730, 131, 41));
        SbFilter = new QSpinBox(WinBeatifyPhoto);
        SbFilter->setObjectName(QStringLiteral("SbFilter"));
        SbFilter->setGeometry(QRect(830, 490, 61, 41));
        SbCorrosion = new QSpinBox(WinBeatifyPhoto);
        SbCorrosion->setObjectName(QStringLiteral("SbCorrosion"));
        SbCorrosion->setGeometry(QRect(830, 550, 61, 41));
        PbExpand = new QPushButton(WinBeatifyPhoto);
        PbExpand->setObjectName(QStringLiteral("PbExpand"));
        PbExpand->setGeometry(QRect(700, 610, 131, 41));
        SbExpand = new QSpinBox(WinBeatifyPhoto);
        SbExpand->setObjectName(QStringLiteral("SbExpand"));
        SbExpand->setGeometry(QRect(830, 610, 61, 41));
        PbShapen = new QPushButton(WinBeatifyPhoto);
        PbShapen->setObjectName(QStringLiteral("PbShapen"));
        PbShapen->setGeometry(QRect(700, 670, 131, 41));
        SbSharpen = new QSpinBox(WinBeatifyPhoto);
        SbSharpen->setObjectName(QStringLiteral("SbSharpen"));
        SbSharpen->setGeometry(QRect(830, 670, 61, 41));
        PbConfirm = new QPushButton(WinBeatifyPhoto);
        PbConfirm->setObjectName(QStringLiteral("PbConfirm"));
        PbConfirm->setGeometry(QRect(1130, 490, 100, 131));
        SbRatation = new QSpinBox(WinBeatifyPhoto);
        SbRatation->setObjectName(QStringLiteral("SbRatation"));
        SbRatation->setGeometry(QRect(830, 730, 61, 41));
        label = new QLabel(WinBeatifyPhoto);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(910, 580, 91, 20));
        label_2 = new QLabel(WinBeatifyPhoto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(910, 630, 81, 20));
        label_3 = new QLabel(WinBeatifyPhoto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(910, 680, 91, 20));
        PbEquration_9 = new QPushButton(WinBeatifyPhoto);
        PbEquration_9->setObjectName(QStringLiteral("PbEquration_9"));
        PbEquration_9->setGeometry(QRect(320, 550, 131, 41));
        PbEquration_10 = new QPushButton(WinBeatifyPhoto);
        PbEquration_10->setObjectName(QStringLiteral("PbEquration_10"));
        PbEquration_10->setGeometry(QRect(320, 610, 131, 41));
        PbLaplaceShape = new QPushButton(WinBeatifyPhoto);
        PbLaplaceShape->setObjectName(QStringLiteral("PbLaplaceShape"));
        PbLaplaceShape->setGeometry(QRect(320, 670, 131, 41));
        PbClassical = new QPushButton(WinBeatifyPhoto);
        PbClassical->setObjectName(QStringLiteral("PbClassical"));
        PbClassical->setGeometry(QRect(320, 730, 131, 41));
        PbSketch = new QPushButton(WinBeatifyPhoto);
        PbSketch->setObjectName(QStringLiteral("PbSketch"));
        PbSketch->setGeometry(QRect(470, 730, 131, 41));
        label_4 = new QLabel(WinBeatifyPhoto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 10, 131, 20));
        label_5 = new QLabel(WinBeatifyPhoto);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(660, 10, 131, 20));
        TbHint = new QTextBrowser(WinBeatifyPhoto);
        TbHint->setObjectName(QStringLiteral("TbHint"));
        TbHint->setGeometry(QRect(70, 780, 1131, 31));
        label_6 = new QLabel(WinBeatifyPhoto);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 780, 41, 31));
        PbResetAll = new QPushButton(WinBeatifyPhoto);
        PbResetAll->setObjectName(QStringLiteral("PbResetAll"));
        PbResetAll->setGeometry(QRect(1130, 650, 100, 71));
        SbFuzzy = new QSpinBox(WinBeatifyPhoto);
        SbFuzzy->setObjectName(QStringLiteral("SbFuzzy"));
        SbFuzzy->setGeometry(QRect(600, 490, 61, 41));
        SbGaussian = new QSpinBox(WinBeatifyPhoto);
        SbGaussian->setObjectName(QStringLiteral("SbGaussian"));
        SbGaussian->setGeometry(QRect(600, 550, 61, 41));
        spinBox_8 = new QSpinBox(WinBeatifyPhoto);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setGeometry(QRect(600, 610, 61, 41));
        SbOilPaint = new QSpinBox(WinBeatifyPhoto);
        SbOilPaint->setObjectName(QStringLiteral("SbOilPaint"));
        SbOilPaint->setGeometry(QRect(600, 670, 61, 41));
        SbSketch = new QSpinBox(WinBeatifyPhoto);
        SbSketch->setObjectName(QStringLiteral("SbSketch"));
        SbSketch->setGeometry(QRect(600, 730, 61, 41));

        retranslateUi(WinBeatifyPhoto);

        QMetaObject::connectSlotsByName(WinBeatifyPhoto);
    } // setupUi

    void retranslateUi(QWidget *WinBeatifyPhoto)
    {
        WinBeatifyPhoto->setWindowTitle(QApplication::translate("WinBeatifyPhoto", "Form", nullptr));
        PbFilter->setText(QApplication::translate("WinBeatifyPhoto", "Filter", nullptr));
        PbSaveFile->setText(QApplication::translate("WinBeatifyPhoto", "Save File", nullptr));
        PbFuzzy->setText(QApplication::translate("WinBeatifyPhoto", "Fuzzy", nullptr));
        PbLast->setText(QApplication::translate("WinBeatifyPhoto", "Last", nullptr));
        PbGaussian->setText(QApplication::translate("WinBeatifyPhoto", "Gaussian", nullptr));
        LbOutputImage->setText(QApplication::translate("WinBeatifyPhoto", "output image", nullptr));
        LbInputImage->setText(QApplication::translate("WinBeatifyPhoto", "input image", nullptr));
        PbOpenFile->setText(QApplication::translate("WinBeatifyPhoto", "Open File", nullptr));
        PbBiarization->setText(QApplication::translate("WinBeatifyPhoto", "Binarization", nullptr));
        PbEquration_k->setText(QApplication::translate("WinBeatifyPhoto", "Gaussian", nullptr));
        PbGrayScale->setText(QApplication::translate("WinBeatifyPhoto", "Grayscale", nullptr));
        PbYMinior->setText(QApplication::translate("WinBeatifyPhoto", "minior_Y", nullptr));
        PbEquration->setText(QApplication::translate("WinBeatifyPhoto", "Equration", nullptr));
        PbNext->setText(QApplication::translate("WinBeatifyPhoto", "Next", nullptr));
        PbBackToMain->setText(QApplication::translate("WinBeatifyPhoto", "BackToMain", nullptr));
        PbXMinior->setText(QApplication::translate("WinBeatifyPhoto", "minior_X", nullptr));
        PbCorrosion->setText(QApplication::translate("WinBeatifyPhoto", "Corrosion", nullptr));
        PbEquration_4->setText(QApplication::translate("WinBeatifyPhoto", "Equration", nullptr));
        PbOilPaint->setText(QApplication::translate("WinBeatifyPhoto", "OilPaint", nullptr));
        PbEquration_6->setText(QApplication::translate("WinBeatifyPhoto", "Ratation", nullptr));
        PbExpand->setText(QApplication::translate("WinBeatifyPhoto", "expand", nullptr));
        PbShapen->setText(QApplication::translate("WinBeatifyPhoto", "sharpen", nullptr));
        PbConfirm->setText(QApplication::translate("WinBeatifyPhoto", "Confirm", nullptr));
        label->setText(QApplication::translate("WinBeatifyPhoto", "Brightness", nullptr));
        label_2->setText(QApplication::translate("WinBeatifyPhoto", "Saturation", nullptr));
        label_3->setText(QApplication::translate("WinBeatifyPhoto", "Constration", nullptr));
        PbEquration_9->setText(QApplication::translate("WinBeatifyPhoto", "Equration", nullptr));
        PbEquration_10->setText(QApplication::translate("WinBeatifyPhoto", "Equration", nullptr));
        PbLaplaceShape->setText(QApplication::translate("WinBeatifyPhoto", "LaplaceShape", nullptr));
        PbClassical->setText(QApplication::translate("WinBeatifyPhoto", "Classical", nullptr));
        PbSketch->setText(QApplication::translate("WinBeatifyPhoto", "Sketch", nullptr));
        label_4->setText(QApplication::translate("WinBeatifyPhoto", "Source Photo", nullptr));
        label_5->setText(QApplication::translate("WinBeatifyPhoto", "Beatify Photo", nullptr));
        label_6->setText(QApplication::translate("WinBeatifyPhoto", "Hint:", nullptr));
        PbResetAll->setText(QApplication::translate("WinBeatifyPhoto", "ResetAll", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinBeatifyPhoto: public Ui_WinBeatifyPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINBEATIFYPHOTO_H
