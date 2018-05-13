/********************************************************************************
** Form generated from reading UI file 'window3.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW3_H
#define UI_WINDOW3_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_backtowindow2
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuwindows3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *backtowindow2)
    {
        if (backtowindow2->objectName().isEmpty())
            backtowindow2->setObjectName(QStringLiteral("backtowindow2"));
        backtowindow2->resize(800, 600);
        centralwidget = new QWidget(backtowindow2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 280, 181, 19));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 340, 141, 27));
        backtowindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(backtowindow2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        menuwindows3 = new QMenu(menubar);
        menuwindows3->setObjectName(QStringLiteral("menuwindows3"));
        backtowindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(backtowindow2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        backtowindow2->setStatusBar(statusbar);

        menubar->addAction(menuwindows3->menuAction());

        retranslateUi(backtowindow2);

        QMetaObject::connectSlotsByName(backtowindow2);
    } // setupUi

    void retranslateUi(QMainWindow *backtowindow2)
    {
        backtowindow2->setWindowTitle(QApplication::translate("backtowindow2", "MainWindow", nullptr));
        label->setText(QApplication::translate("backtowindow2", "This is windows 3", nullptr));
        pushButton->setText(QApplication::translate("backtowindow2", "backtowindow2", nullptr));
        menuwindows3->setTitle(QApplication::translate("backtowindow2", "windows3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class backtowindow2: public Ui_backtowindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW3_H
