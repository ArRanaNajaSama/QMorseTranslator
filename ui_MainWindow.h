/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *yourTextLabel;
    QTextEdit *yourTextTextEdit;
    QTextEdit *resultTextEdit;
    QPushButton *saveResBtn;
    QLabel *label;
    QSplitter *splitter;
    QPushButton *codeBtn;
    QPushButton *decodeBtn;
    QSplitter *splitter_2;
    QPushButton *loadBtn;
    QPushButton *saveInitTextBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(646, 525);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        yourTextLabel = new QLabel(centralWidget);
        yourTextLabel->setObjectName(QStringLiteral("yourTextLabel"));
        yourTextLabel->setGeometry(QRect(20, 20, 91, 21));
        yourTextTextEdit = new QTextEdit(centralWidget);
        yourTextTextEdit->setObjectName(QStringLiteral("yourTextTextEdit"));
        yourTextTextEdit->setGeometry(QRect(20, 50, 231, 331));
        resultTextEdit = new QTextEdit(centralWidget);
        resultTextEdit->setObjectName(QStringLiteral("resultTextEdit"));
        resultTextEdit->setGeometry(QRect(390, 50, 231, 331));
        resultTextEdit->setReadOnly(true);
        saveResBtn = new QPushButton(centralWidget);
        saveResBtn->setObjectName(QStringLiteral("saveResBtn"));
        saveResBtn->setGeometry(QRect(520, 390, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 20, 55, 16));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(270, 60, 93, 56));
        splitter->setOrientation(Qt::Vertical);
        codeBtn = new QPushButton(splitter);
        codeBtn->setObjectName(QStringLiteral("codeBtn"));
        splitter->addWidget(codeBtn);
        decodeBtn = new QPushButton(splitter);
        decodeBtn->setObjectName(QStringLiteral("decodeBtn"));
        splitter->addWidget(decodeBtn);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(40, 390, 186, 28));
        splitter_2->setOrientation(Qt::Horizontal);
        loadBtn = new QPushButton(splitter_2);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        splitter_2->addWidget(loadBtn);
        saveInitTextBtn = new QPushButton(splitter_2);
        saveInitTextBtn->setObjectName(QStringLiteral("saveInitTextBtn"));
        splitter_2->addWidget(saveInitTextBtn);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        yourTextLabel->setText(QApplication::translate("MainWindow", "Your text", 0));
        saveResBtn->setText(QApplication::translate("MainWindow", "Save As", 0));
        label->setText(QApplication::translate("MainWindow", "Result", 0));
        codeBtn->setText(QApplication::translate("MainWindow", "Code", 0));
        decodeBtn->setText(QApplication::translate("MainWindow", "Decode", 0));
        loadBtn->setText(QApplication::translate("MainWindow", "Load", 0));
        saveInitTextBtn->setText(QApplication::translate("MainWindow", "Save As", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
