/********************************************************************************
** Form generated from reading UI file 'window2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW2_H
#define UI_WINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window2
{
public:
    QWidget *centralwidget;
    QPushButton *backToMain;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window2)
    {
        if (window2->objectName().isEmpty())
            window2->setObjectName(QStringLiteral("window2"));
        window2->resize(800, 600);
        centralwidget = new QWidget(window2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        backToMain = new QPushButton(centralwidget);
        backToMain->setObjectName(QStringLiteral("backToMain"));
        backToMain->setGeometry(QRect(320, 380, 121, 27));
        window2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        window2->setMenuBar(menubar);
        statusbar = new QStatusBar(window2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        window2->setStatusBar(statusbar);

        retranslateUi(window2);

        QMetaObject::connectSlotsByName(window2);
    } // setupUi

    void retranslateUi(QMainWindow *window2)
    {
        window2->setWindowTitle(QApplication::translate("window2", "MainWindow", nullptr));
        backToMain->setText(QApplication::translate("window2", "back to main", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window2: public Ui_window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H
