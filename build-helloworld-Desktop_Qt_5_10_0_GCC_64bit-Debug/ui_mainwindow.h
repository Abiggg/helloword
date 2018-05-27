/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *PbImageFuzzy;
    QPushButton *PbImageFilter;
    QPushButton *PbImageStrength;
    QPushButton *PbImageMorphology;
    QPushButton *PbImageTransform;
    QLabel *LbCameraArea;
    QPushButton *PbPhotoGraph;
    QPushButton *PbImageTransform_3;
    QPushButton *PbImageTransform_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1150, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        PbImageFuzzy = new QPushButton(centralwidget);
        PbImageFuzzy->setObjectName(QStringLiteral("PbImageFuzzy"));
        PbImageFuzzy->setGeometry(QRect(970, 170, 161, 41));
        PbImageFilter = new QPushButton(centralwidget);
        PbImageFilter->setObjectName(QStringLiteral("PbImageFilter"));
        PbImageFilter->setGeometry(QRect(970, 240, 161, 41));
        PbImageStrength = new QPushButton(centralwidget);
        PbImageStrength->setObjectName(QStringLiteral("PbImageStrength"));
        PbImageStrength->setGeometry(QRect(970, 310, 161, 41));
        PbImageMorphology = new QPushButton(centralwidget);
        PbImageMorphology->setObjectName(QStringLiteral("PbImageMorphology"));
        PbImageMorphology->setGeometry(QRect(970, 380, 161, 41));
        PbImageTransform = new QPushButton(centralwidget);
        PbImageTransform->setObjectName(QStringLiteral("PbImageTransform"));
        PbImageTransform->setGeometry(QRect(970, 100, 161, 41));
        LbCameraArea = new QLabel(centralwidget);
        LbCameraArea->setObjectName(QStringLiteral("LbCameraArea"));
        LbCameraArea->setGeometry(QRect(160, 40, 551, 461));
        PbPhotoGraph = new QPushButton(centralwidget);
        PbPhotoGraph->setObjectName(QStringLiteral("PbPhotoGraph"));
        PbPhotoGraph->setGeometry(QRect(160, 550, 161, 41));
        PbImageTransform_3 = new QPushButton(centralwidget);
        PbImageTransform_3->setObjectName(QStringLiteral("PbImageTransform_3"));
        PbImageTransform_3->setGeometry(QRect(380, 550, 161, 41));
        PbImageTransform_4 = new QPushButton(centralwidget);
        PbImageTransform_4->setObjectName(QStringLiteral("PbImageTransform_4"));
        PbImageTransform_4->setGeometry(QRect(610, 550, 161, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1150, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        PbImageFuzzy->setText(QApplication::translate("MainWindow", "Image fuzzy", nullptr));
        PbImageFilter->setText(QApplication::translate("MainWindow", "Image filter", nullptr));
        PbImageStrength->setText(QApplication::translate("MainWindow", "Image strength", nullptr));
        PbImageMorphology->setText(QApplication::translate("MainWindow", "Image morphology", nullptr));
        PbImageTransform->setText(QApplication::translate("MainWindow", "Image Transform", nullptr));
        LbCameraArea->setText(QApplication::translate("MainWindow", "Camera Area", nullptr));
        PbPhotoGraph->setText(QApplication::translate("MainWindow", "PhotoGraph", nullptr));
        PbImageTransform_3->setText(QApplication::translate("MainWindow", "beautifyPhoto", nullptr));
        PbImageTransform_4->setText(QApplication::translate("MainWindow", "AImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
