/********************************************************************************
** Form generated from reading UI file 'winaiphoto.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINAIPHOTO_H
#define UI_WINAIPHOTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winAiPhoto
{
public:
    QLabel *label_5;
    QLabel *label_4;
    QLabel *LbOutputImage;
    QLabel *LbInputImage;
    QPushButton *PbNext;
    QPushButton *PbResetAll;
    QPushButton *PbLast;
    QPushButton *PbWinBeatify;
    QPushButton *PbSaveFile;
    QLabel *label_6;
    QPushButton *PbOpenFile;
    QTextBrowser *TbHint;
    QPushButton *PbBackToMain;
    QPushButton *PbConfirm;

    void setupUi(QWidget *winAiPhoto)
    {
        if (winAiPhoto->objectName().isEmpty())
            winAiPhoto->setObjectName(QStringLiteral("winAiPhoto"));
        winAiPhoto->resize(1199, 821);
        label_5 = new QLabel(winAiPhoto);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(650, 0, 131, 20));
        label_4 = new QLabel(winAiPhoto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 0, 131, 20));
        LbOutputImage = new QLabel(winAiPhoto);
        LbOutputImage->setObjectName(QStringLiteral("LbOutputImage"));
        LbOutputImage->setGeometry(QRect(610, 30, 541, 421));
        LbOutputImage->setFrameShadow(QFrame::Raised);
        LbOutputImage->setMidLineWidth(2);
        LbInputImage = new QLabel(winAiPhoto);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(20, 30, 561, 421));
        PbNext = new QPushButton(winAiPhoto);
        PbNext->setObjectName(QStringLiteral("PbNext"));
        PbNext->setGeometry(QRect(10, 650, 131, 41));
        PbResetAll = new QPushButton(winAiPhoto);
        PbResetAll->setObjectName(QStringLiteral("PbResetAll"));
        PbResetAll->setGeometry(QRect(1070, 570, 100, 81));
        PbLast = new QPushButton(winAiPhoto);
        PbLast->setObjectName(QStringLiteral("PbLast"));
        PbLast->setGeometry(QRect(10, 590, 131, 41));
        PbWinBeatify = new QPushButton(winAiPhoto);
        PbWinBeatify->setObjectName(QStringLiteral("PbWinBeatify"));
        PbWinBeatify->setGeometry(QRect(1070, 660, 100, 81));
        PbSaveFile = new QPushButton(winAiPhoto);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(10, 530, 131, 41));
        label_6 = new QLabel(winAiPhoto);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 770, 41, 31));
        PbOpenFile = new QPushButton(winAiPhoto);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(10, 470, 131, 41));
        TbHint = new QTextBrowser(winAiPhoto);
        TbHint->setObjectName(QStringLiteral("TbHint"));
        TbHint->setGeometry(QRect(70, 770, 1101, 31));
        PbBackToMain = new QPushButton(winAiPhoto);
        PbBackToMain->setObjectName(QStringLiteral("PbBackToMain"));
        PbBackToMain->setGeometry(QRect(10, 710, 131, 41));
        PbConfirm = new QPushButton(winAiPhoto);
        PbConfirm->setObjectName(QStringLiteral("PbConfirm"));
        PbConfirm->setGeometry(QRect(1070, 470, 100, 91));

        retranslateUi(winAiPhoto);

        QMetaObject::connectSlotsByName(winAiPhoto);
    } // setupUi

    void retranslateUi(QWidget *winAiPhoto)
    {
        winAiPhoto->setWindowTitle(QApplication::translate("winAiPhoto", "Form", nullptr));
        label_5->setText(QApplication::translate("winAiPhoto", "AiPhoto", nullptr));
        label_4->setText(QApplication::translate("winAiPhoto", "Source Photo", nullptr));
        LbOutputImage->setText(QApplication::translate("winAiPhoto", "output image", nullptr));
        LbInputImage->setText(QApplication::translate("winAiPhoto", "input image", nullptr));
        PbNext->setText(QApplication::translate("winAiPhoto", "Next", nullptr));
        PbResetAll->setText(QApplication::translate("winAiPhoto", "ResetAll", nullptr));
        PbLast->setText(QApplication::translate("winAiPhoto", "Last", nullptr));
        PbWinBeatify->setText(QApplication::translate("winAiPhoto", "WinBeatify", nullptr));
        PbSaveFile->setText(QApplication::translate("winAiPhoto", "Save File", nullptr));
        label_6->setText(QApplication::translate("winAiPhoto", "Hint:", nullptr));
        PbOpenFile->setText(QApplication::translate("winAiPhoto", "Open File", nullptr));
        PbBackToMain->setText(QApplication::translate("winAiPhoto", "BackToMain", nullptr));
        PbConfirm->setText(QApplication::translate("winAiPhoto", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class winAiPhoto: public Ui_winAiPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINAIPHOTO_H
