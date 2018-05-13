/********************************************************************************
** Form generated from reading UI file 'imagefuzzy.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEFUZZY_H
#define UI_IMAGEFUZZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageFuzzy
{
public:
    QPushButton *PbbackToMain;
    QLabel *LbInputImage;
    QLabel *LbOutputImage;
    QPushButton *PbOpenFile;
    QPushButton *PbSaveFile;
    QLabel *LbMethod;
    QPushButton *PbAverage;
    QPushButton *PbMax;
    QPushButton *PbCenter;
    QPushButton *PbFilter;
    QSlider *horizontalSlider;
    QLabel *LbFiterSize;

    void setupUi(QWidget *imageFuzzy)
    {
        if (imageFuzzy->objectName().isEmpty())
            imageFuzzy->setObjectName(QStringLiteral("imageFuzzy"));
        imageFuzzy->resize(1159, 695);
        PbbackToMain = new QPushButton(imageFuzzy);
        PbbackToMain->setObjectName(QStringLiteral("PbbackToMain"));
        PbbackToMain->setGeometry(QRect(960, 610, 191, 71));
        LbInputImage = new QLabel(imageFuzzy);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(20, 40, 391, 351));
        LbOutputImage = new QLabel(imageFuzzy);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(530, 50, 391, 351));
        PbOpenFile = new QPushButton(imageFuzzy);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(980, 120, 131, 41));
        PbSaveFile = new QPushButton(imageFuzzy);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(980, 180, 131, 41));
        LbMethod = new QLabel(imageFuzzy);
        LbMethod->setObjectName(QStringLiteral("LbMethod"));
        LbMethod->setGeometry(QRect(990, 240, 76, 19));
        PbAverage = new QPushButton(imageFuzzy);
        PbAverage->setObjectName(QStringLiteral("PbAverage"));
        PbAverage->setGeometry(QRect(980, 280, 131, 41));
        PbMax = new QPushButton(imageFuzzy);
        PbMax->setObjectName(QStringLiteral("PbMax"));
        PbMax->setGeometry(QRect(980, 340, 131, 41));
        PbCenter = new QPushButton(imageFuzzy);
        PbCenter->setObjectName(QStringLiteral("PbCenter"));
        PbCenter->setGeometry(QRect(980, 400, 131, 41));
        PbFilter = new QPushButton(imageFuzzy);
        PbFilter->setObjectName(QStringLiteral("PbFilter"));
        PbFilter->setGeometry(QRect(980, 460, 131, 41));
        horizontalSlider = new QSlider(imageFuzzy);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(110, 610, 541, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        LbFiterSize = new QLabel(imageFuzzy);
        LbFiterSize->setObjectName(QStringLiteral("LbFiterSize"));
        LbFiterSize->setGeometry(QRect(110, 580, 76, 19));

        retranslateUi(imageFuzzy);

        QMetaObject::connectSlotsByName(imageFuzzy);
    } // setupUi

    void retranslateUi(QWidget *imageFuzzy)
    {
        imageFuzzy->setWindowTitle(QApplication::translate("imageFuzzy", "Form", nullptr));
        PbbackToMain->setText(QApplication::translate("imageFuzzy", "back to main", nullptr));
        LbInputImage->setText(QApplication::translate("imageFuzzy", "input image", nullptr));
        LbOutputImage->setText(QApplication::translate("imageFuzzy", "output image", nullptr));
        PbOpenFile->setText(QApplication::translate("imageFuzzy", "Open File", nullptr));
        PbSaveFile->setText(QApplication::translate("imageFuzzy", "Save File", nullptr));
        LbMethod->setText(QApplication::translate("imageFuzzy", "method", nullptr));
        PbAverage->setText(QApplication::translate("imageFuzzy", "Average", nullptr));
        PbMax->setText(QApplication::translate("imageFuzzy", "Max", nullptr));
        PbCenter->setText(QApplication::translate("imageFuzzy", "Center", nullptr));
        PbFilter->setText(QApplication::translate("imageFuzzy", "Filter", nullptr));
        LbFiterSize->setText(QApplication::translate("imageFuzzy", "filter size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imageFuzzy: public Ui_imageFuzzy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEFUZZY_H
