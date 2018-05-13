/********************************************************************************
** Form generated from reading UI file 'window1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW1_H
#define UI_WINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionrecent;
    QAction *actionfuzzy;
    QAction *actionsharpen;
    QAction *actionenhancement;
    QAction *actionK_NN;
    QAction *actionSVM;
    QAction *actionBP;
    QAction *actionNetWork;
    QAction *actionCNN_LeNet;
    QAction *actionBeyes;
    QAction *actionDecision;
    QAction *actionfilter;
    QAction *actionabout_me;
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuimage;
    QMenu *menumachine;
    QMenu *menuhelp;
    QMenu *menuabout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1084, 663);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionrecent = new QAction(MainWindow);
        actionrecent->setObjectName(QStringLiteral("actionrecent"));
        actionfuzzy = new QAction(MainWindow);
        actionfuzzy->setObjectName(QStringLiteral("actionfuzzy"));
        actionsharpen = new QAction(MainWindow);
        actionsharpen->setObjectName(QStringLiteral("actionsharpen"));
        actionenhancement = new QAction(MainWindow);
        actionenhancement->setObjectName(QStringLiteral("actionenhancement"));
        actionK_NN = new QAction(MainWindow);
        actionK_NN->setObjectName(QStringLiteral("actionK_NN"));
        actionSVM = new QAction(MainWindow);
        actionSVM->setObjectName(QStringLiteral("actionSVM"));
        actionBP = new QAction(MainWindow);
        actionBP->setObjectName(QStringLiteral("actionBP"));
        actionNetWork = new QAction(MainWindow);
        actionNetWork->setObjectName(QStringLiteral("actionNetWork"));
        actionCNN_LeNet = new QAction(MainWindow);
        actionCNN_LeNet->setObjectName(QStringLiteral("actionCNN_LeNet"));
        actionBeyes = new QAction(MainWindow);
        actionBeyes->setObjectName(QStringLiteral("actionBeyes"));
        actionDecision = new QAction(MainWindow);
        actionDecision->setObjectName(QStringLiteral("actionDecision"));
        actionfilter = new QAction(MainWindow);
        actionfilter->setObjectName(QStringLiteral("actionfilter"));
        actionabout_me = new QAction(MainWindow);
        actionabout_me->setObjectName(QStringLiteral("actionabout_me"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 270, 76, 19));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 300, 100, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 31));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menuimage = new QMenu(menuBar);
        menuimage->setObjectName(QStringLiteral("menuimage"));
        menumachine = new QMenu(menuBar);
        menumachine->setObjectName(QStringLiteral("menumachine"));
        menuhelp = new QMenu(menuBar);
        menuhelp->setObjectName(QStringLiteral("menuhelp"));
        menuabout = new QMenu(menuBar);
        menuabout->setObjectName(QStringLiteral("menuabout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuimage->menuAction());
        menuBar->addAction(menumachine->menuAction());
        menuBar->addAction(menuhelp->menuAction());
        menuBar->addAction(menuabout->menuAction());
        menufile->addSeparator();
        menufile->addSeparator();
        menufile->addAction(actionopen);
        menufile->addAction(actionsave);
        menufile->addAction(actionrecent);
        menuimage->addAction(actionfuzzy);
        menuimage->addAction(actionsharpen);
        menuimage->addAction(actionenhancement);
        menuimage->addAction(actionfilter);
        menumachine->addAction(actionK_NN);
        menumachine->addAction(actionSVM);
        menumachine->addAction(actionBP);
        menumachine->addAction(actionNetWork);
        menumachine->addAction(actionCNN_LeNet);
        menumachine->addAction(actionBeyes);
        menumachine->addAction(actionDecision);
        menuabout->addAction(actionabout_me);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QApplication::translate("MainWindow", "open", nullptr));
        actionsave->setText(QApplication::translate("MainWindow", "save", nullptr));
        actionrecent->setText(QApplication::translate("MainWindow", "recent", nullptr));
        actionfuzzy->setText(QApplication::translate("MainWindow", "fuzzy", nullptr));
        actionsharpen->setText(QApplication::translate("MainWindow", "sharpening", nullptr));
        actionenhancement->setText(QApplication::translate("MainWindow", "enhancement", nullptr));
        actionK_NN->setText(QApplication::translate("MainWindow", "K-NN", nullptr));
        actionSVM->setText(QApplication::translate("MainWindow", "SVM", nullptr));
        actionBP->setText(QApplication::translate("MainWindow", "BP", nullptr));
        actionNetWork->setText(QApplication::translate("MainWindow", "NetWork", nullptr));
        actionCNN_LeNet->setText(QApplication::translate("MainWindow", "CNN-LeNet", nullptr));
        actionBeyes->setText(QApplication::translate("MainWindow", "Beyes", nullptr));
        actionDecision->setText(QApplication::translate("MainWindow", "Decision Tree", nullptr));
        actionfilter->setText(QApplication::translate("MainWindow", "filter", nullptr));
        actionabout_me->setText(QApplication::translate("MainWindow", "about me", nullptr));
        label->setText(QApplication::translate("MainWindow", "windows", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "file", nullptr));
        menuimage->setTitle(QApplication::translate("MainWindow", "image", nullptr));
        menumachine->setTitle(QApplication::translate("MainWindow", "AI", nullptr));
        menuhelp->setTitle(QApplication::translate("MainWindow", "help", nullptr));
        menuabout->setTitle(QApplication::translate("MainWindow", "about", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW1_H
