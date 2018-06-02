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
    QSpinBox *SbBinarization;
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
    QSpinBox *spinBox_9;
    QSpinBox *SbSketch_2;
    QSpinBox *SbGaussian_2;
    QSpinBox *SbOilPaint_2;
    QSpinBox *SbFuzzy_2;
    QPushButton *PbWinAiPhoto;

    void setupUi(QWidget *WinBeatifyPhoto)
    {
        if (WinBeatifyPhoto->objectName().isEmpty())
            WinBeatifyPhoto->setObjectName(QStringLiteral("WinBeatifyPhoto"));
        WinBeatifyPhoto->resize(1191, 819);
        PbFilter = new QPushButton(WinBeatifyPhoto);
        PbFilter->setObjectName(QStringLiteral("PbFilter"));
        PbFilter->setGeometry(QRect(730, 670, 131, 41));
        PbSaveFile = new QPushButton(WinBeatifyPhoto);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(10, 550, 131, 41));
        PbFuzzy = new QPushButton(WinBeatifyPhoto);
        PbFuzzy->setObjectName(QStringLiteral("PbFuzzy"));
        PbFuzzy->setGeometry(QRect(520, 490, 131, 41));
        PbLast = new QPushButton(WinBeatifyPhoto);
        PbLast->setObjectName(QStringLiteral("PbLast"));
        PbLast->setGeometry(QRect(10, 610, 131, 41));
        PbGaussian = new QPushButton(WinBeatifyPhoto);
        PbGaussian->setObjectName(QStringLiteral("PbGaussian"));
        PbGaussian->setGeometry(QRect(520, 550, 131, 41));
        LbOutputImage = new QLabel(WinBeatifyPhoto);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(620, 50, 541, 421));
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
        VsBrightness->setGeometry(QRect(940, 490, 16, 251));
        VsBrightness->setOrientation(Qt::Vertical);
        VsSaturation = new QSlider(WinBeatifyPhoto);
        VsSaturation->setObjectName(QStringLiteral("VsSaturation"));
        VsSaturation->setGeometry(QRect(980, 490, 16, 251));
        VsSaturation->setOrientation(Qt::Vertical);
        VsConstration = new QSlider(WinBeatifyPhoto);
        VsConstration->setObjectName(QStringLiteral("VsConstration"));
        VsConstration->setGeometry(QRect(1020, 490, 16, 251));
        VsConstration->setOrientation(Qt::Vertical);
        PbBiarization = new QPushButton(WinBeatifyPhoto);
        PbBiarization->setObjectName(QStringLiteral("PbBiarization"));
        PbBiarization->setGeometry(QRect(310, 490, 131, 41));
        PbEquration_k = new QPushButton(WinBeatifyPhoto);
        PbEquration_k->setObjectName(QStringLiteral("PbEquration_k"));
        PbEquration_k->setGeometry(QRect(730, 490, 131, 41));
        PbGrayScale = new QPushButton(WinBeatifyPhoto);
        PbGrayScale->setObjectName(QStringLiteral("PbGrayScale"));
        PbGrayScale->setGeometry(QRect(160, 610, 131, 41));
        PbYMinior = new QPushButton(WinBeatifyPhoto);
        PbYMinior->setObjectName(QStringLiteral("PbYMinior"));
        PbYMinior->setGeometry(QRect(160, 550, 131, 41));
        PbEquration = new QPushButton(WinBeatifyPhoto);
        PbEquration->setObjectName(QStringLiteral("PbEquration"));
        PbEquration->setGeometry(QRect(160, 730, 131, 41));
        PbNext = new QPushButton(WinBeatifyPhoto);
        PbNext->setObjectName(QStringLiteral("PbNext"));
        PbNext->setGeometry(QRect(10, 670, 131, 41));
        PbBackToMain = new QPushButton(WinBeatifyPhoto);
        PbBackToMain->setObjectName(QStringLiteral("PbBackToMain"));
        PbBackToMain->setGeometry(QRect(10, 730, 131, 41));
        PbXMinior = new QPushButton(WinBeatifyPhoto);
        PbXMinior->setObjectName(QStringLiteral("PbXMinior"));
        PbXMinior->setGeometry(QRect(160, 490, 131, 41));
        PbCorrosion = new QPushButton(WinBeatifyPhoto);
        PbCorrosion->setObjectName(QStringLiteral("PbCorrosion"));
        PbCorrosion->setGeometry(QRect(310, 550, 131, 41));
        PbEquration_4 = new QPushButton(WinBeatifyPhoto);
        PbEquration_4->setObjectName(QStringLiteral("PbEquration_4"));
        PbEquration_4->setGeometry(QRect(730, 730, 131, 41));
        PbOilPaint = new QPushButton(WinBeatifyPhoto);
        PbOilPaint->setObjectName(QStringLiteral("PbOilPaint"));
        PbOilPaint->setGeometry(QRect(520, 610, 131, 41));
        PbEquration_6 = new QPushButton(WinBeatifyPhoto);
        PbEquration_6->setObjectName(QStringLiteral("PbEquration_6"));
        PbEquration_6->setGeometry(QRect(310, 730, 131, 41));
        SbBinarization = new QSpinBox(WinBeatifyPhoto);
        SbBinarization->setObjectName(QStringLiteral("SbBinarization"));
        SbBinarization->setGeometry(QRect(440, 490, 61, 41));
        SbCorrosion = new QSpinBox(WinBeatifyPhoto);
        SbCorrosion->setObjectName(QStringLiteral("SbCorrosion"));
        SbCorrosion->setGeometry(QRect(440, 550, 61, 41));
        PbExpand = new QPushButton(WinBeatifyPhoto);
        PbExpand->setObjectName(QStringLiteral("PbExpand"));
        PbExpand->setGeometry(QRect(310, 610, 131, 41));
        SbExpand = new QSpinBox(WinBeatifyPhoto);
        SbExpand->setObjectName(QStringLiteral("SbExpand"));
        SbExpand->setGeometry(QRect(440, 610, 61, 41));
        PbShapen = new QPushButton(WinBeatifyPhoto);
        PbShapen->setObjectName(QStringLiteral("PbShapen"));
        PbShapen->setGeometry(QRect(310, 670, 131, 41));
        SbSharpen = new QSpinBox(WinBeatifyPhoto);
        SbSharpen->setObjectName(QStringLiteral("SbSharpen"));
        SbSharpen->setGeometry(QRect(440, 670, 61, 41));
        PbConfirm = new QPushButton(WinBeatifyPhoto);
        PbConfirm->setObjectName(QStringLiteral("PbConfirm"));
        PbConfirm->setGeometry(QRect(1070, 490, 100, 91));
        SbRatation = new QSpinBox(WinBeatifyPhoto);
        SbRatation->setObjectName(QStringLiteral("SbRatation"));
        SbRatation->setGeometry(QRect(440, 730, 61, 41));
        label = new QLabel(WinBeatifyPhoto);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(940, 740, 21, 20));
        label_2 = new QLabel(WinBeatifyPhoto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(980, 740, 21, 20));
        label_3 = new QLabel(WinBeatifyPhoto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1020, 740, 21, 20));
        PbEquration_9 = new QPushButton(WinBeatifyPhoto);
        PbEquration_9->setObjectName(QStringLiteral("PbEquration_9"));
        PbEquration_9->setGeometry(QRect(730, 550, 131, 41));
        PbEquration_10 = new QPushButton(WinBeatifyPhoto);
        PbEquration_10->setObjectName(QStringLiteral("PbEquration_10"));
        PbEquration_10->setGeometry(QRect(730, 610, 131, 41));
        PbLaplaceShape = new QPushButton(WinBeatifyPhoto);
        PbLaplaceShape->setObjectName(QStringLiteral("PbLaplaceShape"));
        PbLaplaceShape->setGeometry(QRect(520, 730, 141, 41));
        PbClassical = new QPushButton(WinBeatifyPhoto);
        PbClassical->setObjectName(QStringLiteral("PbClassical"));
        PbClassical->setGeometry(QRect(160, 670, 131, 41));
        PbSketch = new QPushButton(WinBeatifyPhoto);
        PbSketch->setObjectName(QStringLiteral("PbSketch"));
        PbSketch->setGeometry(QRect(520, 670, 131, 41));
        label_4 = new QLabel(WinBeatifyPhoto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 10, 131, 20));
        label_5 = new QLabel(WinBeatifyPhoto);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(660, 10, 131, 20));
        TbHint = new QTextBrowser(WinBeatifyPhoto);
        TbHint->setObjectName(QStringLiteral("TbHint"));
        TbHint->setGeometry(QRect(70, 780, 1101, 31));
        label_6 = new QLabel(WinBeatifyPhoto);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 780, 41, 31));
        PbResetAll = new QPushButton(WinBeatifyPhoto);
        PbResetAll->setObjectName(QStringLiteral("PbResetAll"));
        PbResetAll->setGeometry(QRect(1070, 590, 100, 81));
        SbFuzzy = new QSpinBox(WinBeatifyPhoto);
        SbFuzzy->setObjectName(QStringLiteral("SbFuzzy"));
        SbFuzzy->setGeometry(QRect(650, 490, 61, 41));
        SbGaussian = new QSpinBox(WinBeatifyPhoto);
        SbGaussian->setObjectName(QStringLiteral("SbGaussian"));
        SbGaussian->setGeometry(QRect(650, 550, 61, 41));
        spinBox_8 = new QSpinBox(WinBeatifyPhoto);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setGeometry(QRect(860, 730, 61, 41));
        SbOilPaint = new QSpinBox(WinBeatifyPhoto);
        SbOilPaint->setObjectName(QStringLiteral("SbOilPaint"));
        SbOilPaint->setGeometry(QRect(650, 610, 61, 41));
        SbSketch = new QSpinBox(WinBeatifyPhoto);
        SbSketch->setObjectName(QStringLiteral("SbSketch"));
        SbSketch->setGeometry(QRect(650, 670, 61, 41));
        spinBox_9 = new QSpinBox(WinBeatifyPhoto);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));
        spinBox_9->setGeometry(QRect(670, 730, 61, 41));
        SbSketch_2 = new QSpinBox(WinBeatifyPhoto);
        SbSketch_2->setObjectName(QStringLiteral("SbSketch_2"));
        SbSketch_2->setGeometry(QRect(860, 670, 61, 41));
        SbGaussian_2 = new QSpinBox(WinBeatifyPhoto);
        SbGaussian_2->setObjectName(QStringLiteral("SbGaussian_2"));
        SbGaussian_2->setGeometry(QRect(860, 550, 61, 41));
        SbOilPaint_2 = new QSpinBox(WinBeatifyPhoto);
        SbOilPaint_2->setObjectName(QStringLiteral("SbOilPaint_2"));
        SbOilPaint_2->setGeometry(QRect(860, 610, 61, 41));
        SbFuzzy_2 = new QSpinBox(WinBeatifyPhoto);
        SbFuzzy_2->setObjectName(QStringLiteral("SbFuzzy_2"));
        SbFuzzy_2->setGeometry(QRect(860, 490, 61, 41));
        PbWinAiPhoto = new QPushButton(WinBeatifyPhoto);
        PbWinAiPhoto->setObjectName(QStringLiteral("PbWinAiPhoto"));
        PbWinAiPhoto->setGeometry(QRect(1070, 680, 100, 81));

        retranslateUi(WinBeatifyPhoto);

        QMetaObject::connectSlotsByName(WinBeatifyPhoto);
    } // setupUi

    void retranslateUi(QWidget *WinBeatifyPhoto)
    {
        WinBeatifyPhoto->setWindowTitle(QApplication::translate("WinBeatifyPhoto", "Form", nullptr));
        PbFilter->setText(QApplication::translate("WinBeatifyPhoto", "FFTHighFilter", nullptr));
        PbSaveFile->setText(QApplication::translate("WinBeatifyPhoto", "Save File", nullptr));
        PbFuzzy->setText(QApplication::translate("WinBeatifyPhoto", "Fuzzy", nullptr));
        PbLast->setText(QApplication::translate("WinBeatifyPhoto", "Last", nullptr));
        PbGaussian->setText(QApplication::translate("WinBeatifyPhoto", "Gaussian", nullptr));
        LbOutputImage->setText(QApplication::translate("WinBeatifyPhoto", "output image", nullptr));
        LbInputImage->setText(QApplication::translate("WinBeatifyPhoto", "input image", nullptr));
        PbOpenFile->setText(QApplication::translate("WinBeatifyPhoto", "Open File", nullptr));
        PbBiarization->setText(QApplication::translate("WinBeatifyPhoto", "Binarization", nullptr));
        PbEquration_k->setText(QApplication::translate("WinBeatifyPhoto", "unused", nullptr));
        PbGrayScale->setText(QApplication::translate("WinBeatifyPhoto", "Grayscale", nullptr));
        PbYMinior->setText(QApplication::translate("WinBeatifyPhoto", "minior_Y", nullptr));
        PbEquration->setText(QApplication::translate("WinBeatifyPhoto", "Equration", nullptr));
        PbNext->setText(QApplication::translate("WinBeatifyPhoto", "Next", nullptr));
        PbBackToMain->setText(QApplication::translate("WinBeatifyPhoto", "BackToMain", nullptr));
        PbXMinior->setText(QApplication::translate("WinBeatifyPhoto", "minior_X", nullptr));
        PbCorrosion->setText(QApplication::translate("WinBeatifyPhoto", "Corrosion", nullptr));
        PbEquration_4->setText(QApplication::translate("WinBeatifyPhoto", "FFTBandFilter", nullptr));
        PbOilPaint->setText(QApplication::translate("WinBeatifyPhoto", "OilPaint", nullptr));
        PbEquration_6->setText(QApplication::translate("WinBeatifyPhoto", "Ratation", nullptr));
        PbExpand->setText(QApplication::translate("WinBeatifyPhoto", "expand", nullptr));
        PbShapen->setText(QApplication::translate("WinBeatifyPhoto", "sharpen", nullptr));
        PbConfirm->setText(QApplication::translate("WinBeatifyPhoto", "Confirm", nullptr));
        label->setText(QApplication::translate("WinBeatifyPhoto", "BT", nullptr));
        label_2->setText(QApplication::translate("WinBeatifyPhoto", "ST", nullptr));
        label_3->setText(QApplication::translate("WinBeatifyPhoto", "CT", nullptr));
        PbEquration_9->setText(QApplication::translate("WinBeatifyPhoto", "unused", nullptr));
        PbEquration_10->setText(QApplication::translate("WinBeatifyPhoto", "FFTLowFilter", nullptr));
        PbLaplaceShape->setText(QApplication::translate("WinBeatifyPhoto", "LaplaceShape", nullptr));
        PbClassical->setText(QApplication::translate("WinBeatifyPhoto", "Classical", nullptr));
        PbSketch->setText(QApplication::translate("WinBeatifyPhoto", "Sketch", nullptr));
        label_4->setText(QApplication::translate("WinBeatifyPhoto", "Source Photo", nullptr));
        label_5->setText(QApplication::translate("WinBeatifyPhoto", "Beatify Photo", nullptr));
        label_6->setText(QApplication::translate("WinBeatifyPhoto", "Hint:", nullptr));
        PbResetAll->setText(QApplication::translate("WinBeatifyPhoto", "ResetAll", nullptr));
        PbWinAiPhoto->setText(QApplication::translate("WinBeatifyPhoto", "GotoWinAi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinBeatifyPhoto: public Ui_WinBeatifyPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINBEATIFYPHOTO_H
