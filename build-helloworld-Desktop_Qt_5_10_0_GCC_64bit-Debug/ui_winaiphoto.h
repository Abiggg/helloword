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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QProgressBar *PgFinishPercent;
    QLabel *label_7;
    QStackedWidget *SwAiFun;
    QWidget *SwpKnn;
    QLabel *label_8;
    QWidget *SwpBpSvm;
    QLabel *label_9;
    QWidget *SwpDecisionTree;
    QLabel *label_10;
    QWidget *SwpBayes;
    QLabel *label_11;
    QWidget *SwpBpNetWork;
    QPushButton *PbBpStartTrain;
    QLineEdit *LeLableRoot;
    QLabel *LbBpLableRoot;
    QLabel *LbBpImageRoot;
    QLineEdit *LeImageRoot;
    QPushButton *PbBpEndTrain;
    QLabel *LbBpInNum;
    QLineEdit *LeInNum;
    QLabel *LbBpHdNum;
    QLineEdit *LeHdNum;
    QLabel *LbBpOutNum;
    QLineEdit *LeOutNum;
    QLabel *LbBpLearnRate;
    QLineEdit *LeLearnRate;
    QLabel *LbBpBatchSize;
    QLineEdit *LeBatchSize;
    QLabel *LbBpTrainNum;
    QLineEdit *LeTrainNum;
    QPushButton *PbBpStartTest;
    QPushButton *PbBpEndTest;
    QPushButton *PbFlash;
    QLabel *LbBpSaveRoot;
    QLineEdit *LeSaveRoot;
    QWidget *SwpCnnLet;
    QLabel *label_13;
    QWidget *SwpRnn;
    QLabel *label_14;
    QListWidget *LwAiFun;

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
        LbOutputImage->setGeometry(QRect(610, 30, 541, 401));
        LbOutputImage->setFrameShadow(QFrame::Raised);
        LbOutputImage->setMidLineWidth(2);
        LbInputImage = new QLabel(winAiPhoto);
        LbInputImage->setObjectName(QStringLiteral("LbInputImage"));
        LbInputImage->setGeometry(QRect(20, 30, 561, 401));
        PbNext = new QPushButton(winAiPhoto);
        PbNext->setObjectName(QStringLiteral("PbNext"));
        PbNext->setGeometry(QRect(10, 630, 131, 41));
        PbResetAll = new QPushButton(winAiPhoto);
        PbResetAll->setObjectName(QStringLiteral("PbResetAll"));
        PbResetAll->setGeometry(QRect(1070, 550, 100, 81));
        PbLast = new QPushButton(winAiPhoto);
        PbLast->setObjectName(QStringLiteral("PbLast"));
        PbLast->setGeometry(QRect(10, 570, 131, 41));
        PbWinBeatify = new QPushButton(winAiPhoto);
        PbWinBeatify->setObjectName(QStringLiteral("PbWinBeatify"));
        PbWinBeatify->setGeometry(QRect(1070, 640, 100, 81));
        PbSaveFile = new QPushButton(winAiPhoto);
        PbSaveFile->setObjectName(QStringLiteral("PbSaveFile"));
        PbSaveFile->setGeometry(QRect(10, 510, 131, 41));
        label_6 = new QLabel(winAiPhoto);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 780, 41, 31));
        PbOpenFile = new QPushButton(winAiPhoto);
        PbOpenFile->setObjectName(QStringLiteral("PbOpenFile"));
        PbOpenFile->setGeometry(QRect(10, 450, 131, 41));
        TbHint = new QTextBrowser(winAiPhoto);
        TbHint->setObjectName(QStringLiteral("TbHint"));
        TbHint->setGeometry(QRect(90, 780, 1081, 31));
        PbBackToMain = new QPushButton(winAiPhoto);
        PbBackToMain->setObjectName(QStringLiteral("PbBackToMain"));
        PbBackToMain->setGeometry(QRect(10, 690, 131, 41));
        PbConfirm = new QPushButton(winAiPhoto);
        PbConfirm->setObjectName(QStringLiteral("PbConfirm"));
        PbConfirm->setGeometry(QRect(1070, 450, 100, 91));
        PgFinishPercent = new QProgressBar(winAiPhoto);
        PgFinishPercent->setObjectName(QStringLiteral("PgFinishPercent"));
        PgFinishPercent->setGeometry(QRect(90, 750, 1081, 23));
        PgFinishPercent->setValue(24);
        label_7 = new QLabel(winAiPhoto);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 750, 71, 31));
        SwAiFun = new QStackedWidget(winAiPhoto);
        SwAiFun->setObjectName(QStringLiteral("SwAiFun"));
        SwAiFun->setGeometry(QRect(330, 450, 721, 281));
        SwpKnn = new QWidget();
        SwpKnn->setObjectName(QStringLiteral("SwpKnn"));
        label_8 = new QLabel(SwpKnn);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 71, 31));
        SwAiFun->addWidget(SwpKnn);
        SwpBpSvm = new QWidget();
        SwpBpSvm->setObjectName(QStringLiteral("SwpBpSvm"));
        label_9 = new QLabel(SwpBpSvm);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 71, 31));
        SwAiFun->addWidget(SwpBpSvm);
        SwpDecisionTree = new QWidget();
        SwpDecisionTree->setObjectName(QStringLiteral("SwpDecisionTree"));
        label_10 = new QLabel(SwpDecisionTree);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 10, 111, 31));
        SwAiFun->addWidget(SwpDecisionTree);
        SwpBayes = new QWidget();
        SwpBayes->setObjectName(QStringLiteral("SwpBayes"));
        label_11 = new QLabel(SwpBayes);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 0, 71, 31));
        SwAiFun->addWidget(SwpBayes);
        SwpBpNetWork = new QWidget();
        SwpBpNetWork->setObjectName(QStringLiteral("SwpBpNetWork"));
        PbBpStartTrain = new QPushButton(SwpBpNetWork);
        PbBpStartTrain->setObjectName(QStringLiteral("PbBpStartTrain"));
        PbBpStartTrain->setGeometry(QRect(10, 250, 111, 31));
        LeLableRoot = new QLineEdit(SwpBpNetWork);
        LeLableRoot->setObjectName(QStringLiteral("LeLableRoot"));
        LeLableRoot->setGeometry(QRect(120, 10, 581, 31));
        LbBpLableRoot = new QLabel(SwpBpNetWork);
        LbBpLableRoot->setObjectName(QStringLiteral("LbBpLableRoot"));
        LbBpLableRoot->setGeometry(QRect(20, 10, 91, 31));
        LbBpImageRoot = new QLabel(SwpBpNetWork);
        LbBpImageRoot->setObjectName(QStringLiteral("LbBpImageRoot"));
        LbBpImageRoot->setGeometry(QRect(20, 60, 91, 31));
        LeImageRoot = new QLineEdit(SwpBpNetWork);
        LeImageRoot->setObjectName(QStringLiteral("LeImageRoot"));
        LeImageRoot->setGeometry(QRect(120, 60, 581, 31));
        PbBpEndTrain = new QPushButton(SwpBpNetWork);
        PbBpEndTrain->setObjectName(QStringLiteral("PbBpEndTrain"));
        PbBpEndTrain->setGeometry(QRect(160, 250, 101, 31));
        LbBpInNum = new QLabel(SwpBpNetWork);
        LbBpInNum->setObjectName(QStringLiteral("LbBpInNum"));
        LbBpInNum->setGeometry(QRect(20, 160, 61, 31));
        LeInNum = new QLineEdit(SwpBpNetWork);
        LeInNum->setObjectName(QStringLiteral("LeInNum"));
        LeInNum->setGeometry(QRect(80, 160, 151, 31));
        LbBpHdNum = new QLabel(SwpBpNetWork);
        LbBpHdNum->setObjectName(QStringLiteral("LbBpHdNum"));
        LbBpHdNum->setGeometry(QRect(250, 160, 61, 31));
        LeHdNum = new QLineEdit(SwpBpNetWork);
        LeHdNum->setObjectName(QStringLiteral("LeHdNum"));
        LeHdNum->setGeometry(QRect(320, 160, 141, 31));
        LbBpOutNum = new QLabel(SwpBpNetWork);
        LbBpOutNum->setObjectName(QStringLiteral("LbBpOutNum"));
        LbBpOutNum->setGeometry(QRect(490, 160, 71, 31));
        LeOutNum = new QLineEdit(SwpBpNetWork);
        LeOutNum->setObjectName(QStringLiteral("LeOutNum"));
        LeOutNum->setGeometry(QRect(570, 160, 131, 31));
        LbBpLearnRate = new QLabel(SwpBpNetWork);
        LbBpLearnRate->setObjectName(QStringLiteral("LbBpLearnRate"));
        LbBpLearnRate->setGeometry(QRect(20, 200, 61, 31));
        LeLearnRate = new QLineEdit(SwpBpNetWork);
        LeLearnRate->setObjectName(QStringLiteral("LeLearnRate"));
        LeLearnRate->setGeometry(QRect(80, 200, 151, 31));
        LbBpBatchSize = new QLabel(SwpBpNetWork);
        LbBpBatchSize->setObjectName(QStringLiteral("LbBpBatchSize"));
        LbBpBatchSize->setGeometry(QRect(250, 200, 61, 31));
        LeBatchSize = new QLineEdit(SwpBpNetWork);
        LeBatchSize->setObjectName(QStringLiteral("LeBatchSize"));
        LeBatchSize->setGeometry(QRect(320, 200, 141, 31));
        LbBpTrainNum = new QLabel(SwpBpNetWork);
        LbBpTrainNum->setObjectName(QStringLiteral("LbBpTrainNum"));
        LbBpTrainNum->setGeometry(QRect(480, 200, 81, 31));
        LeTrainNum = new QLineEdit(SwpBpNetWork);
        LeTrainNum->setObjectName(QStringLiteral("LeTrainNum"));
        LeTrainNum->setGeometry(QRect(570, 200, 131, 31));
        PbBpStartTest = new QPushButton(SwpBpNetWork);
        PbBpStartTest->setObjectName(QStringLiteral("PbBpStartTest"));
        PbBpStartTest->setGeometry(QRect(300, 250, 101, 31));
        PbBpEndTest = new QPushButton(SwpBpNetWork);
        PbBpEndTest->setObjectName(QStringLiteral("PbBpEndTest"));
        PbBpEndTest->setGeometry(QRect(440, 250, 101, 31));
        PbFlash = new QPushButton(SwpBpNetWork);
        PbFlash->setObjectName(QStringLiteral("PbFlash"));
        PbFlash->setGeometry(QRect(580, 250, 121, 31));
        LbBpSaveRoot = new QLabel(SwpBpNetWork);
        LbBpSaveRoot->setObjectName(QStringLiteral("LbBpSaveRoot"));
        LbBpSaveRoot->setGeometry(QRect(20, 110, 91, 31));
        LeSaveRoot = new QLineEdit(SwpBpNetWork);
        LeSaveRoot->setObjectName(QStringLiteral("LeSaveRoot"));
        LeSaveRoot->setGeometry(QRect(120, 110, 581, 31));
        SwAiFun->addWidget(SwpBpNetWork);
        SwpCnnLet = new QWidget();
        SwpCnnLet->setObjectName(QStringLiteral("SwpCnnLet"));
        label_13 = new QLabel(SwpCnnLet);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 0, 71, 31));
        SwAiFun->addWidget(SwpCnnLet);
        SwpRnn = new QWidget();
        SwpRnn->setObjectName(QStringLiteral("SwpRnn"));
        label_14 = new QLabel(SwpRnn);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 0, 71, 31));
        SwAiFun->addWidget(SwpRnn);
        LwAiFun = new QListWidget(winAiPhoto);
        QFont font;
        font.setFamily(QStringLiteral("Symbola"));
        font.setPointSize(14);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem->setFont(font);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem1->setFont(font);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem2->setFont(font);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem3->setFont(font);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem4->setFont(font);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem5->setFont(font);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(LwAiFun);
        __qlistwidgetitem6->setFont(font);
        LwAiFun->setObjectName(QStringLiteral("LwAiFun"));
        LwAiFun->setGeometry(QRect(170, 450, 151, 281));
        QFont font1;
        font1.setPointSize(15);
        LwAiFun->setFont(font1);

        retranslateUi(winAiPhoto);

        SwAiFun->setCurrentIndex(4);


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
        label_7->setText(QApplication::translate("winAiPhoto", "Percent:", nullptr));
        label_8->setText(QApplication::translate("winAiPhoto", "KNN", nullptr));
        label_9->setText(QApplication::translate("winAiPhoto", "SVM", nullptr));
        label_10->setText(QApplication::translate("winAiPhoto", "DecisionTree", nullptr));
        label_11->setText(QApplication::translate("winAiPhoto", "Bayes", nullptr));
        PbBpStartTrain->setText(QApplication::translate("winAiPhoto", "Start Train", nullptr));
        LbBpLableRoot->setText(QApplication::translate("winAiPhoto", "Lable Root", nullptr));
        LbBpImageRoot->setText(QApplication::translate("winAiPhoto", "Image Root", nullptr));
        PbBpEndTrain->setText(QApplication::translate("winAiPhoto", "End Train", nullptr));
        LbBpInNum->setText(QApplication::translate("winAiPhoto", "InNum", nullptr));
        LbBpHdNum->setText(QApplication::translate("winAiPhoto", "HdNum", nullptr));
        LbBpOutNum->setText(QApplication::translate("winAiPhoto", "OutNum", nullptr));
        LbBpLearnRate->setText(QApplication::translate("winAiPhoto", "LearnR", nullptr));
        LbBpBatchSize->setText(QApplication::translate("winAiPhoto", "BatchS", nullptr));
        LbBpTrainNum->setText(QApplication::translate("winAiPhoto", "TrainNum", nullptr));
        PbBpStartTest->setText(QApplication::translate("winAiPhoto", "Start Test", nullptr));
        PbBpEndTest->setText(QApplication::translate("winAiPhoto", "End Test", nullptr));
        PbFlash->setText(QApplication::translate("winAiPhoto", "Flash", nullptr));
        LbBpSaveRoot->setText(QApplication::translate("winAiPhoto", "Save Root", nullptr));
        label_13->setText(QApplication::translate("winAiPhoto", "Cnn", nullptr));
        label_14->setText(QApplication::translate("winAiPhoto", "Rnn", nullptr));

        const bool __sortingEnabled = LwAiFun->isSortingEnabled();
        LwAiFun->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = LwAiFun->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("winAiPhoto", "KnnAlgorithm", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = LwAiFun->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("winAiPhoto", "SvmAlgoritm", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = LwAiFun->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("winAiPhoto", "DecisionTree", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = LwAiFun->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("winAiPhoto", "BayesAlgoritm", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = LwAiFun->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("winAiPhoto", "BpNetwork", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = LwAiFun->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("winAiPhoto", "CnnLenet5", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = LwAiFun->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("winAiPhoto", "Rnn-Lstm", nullptr));
        LwAiFun->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class winAiPhoto: public Ui_winAiPhoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINAIPHOTO_H
