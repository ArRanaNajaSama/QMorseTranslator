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
    QPushButton *loadBtn;
    QPushButton *codeBtn;
    QTextEdit *resultTextEdit;
    QPushButton *saveResBtn;
    QPushButton *saveInitTextBtn;
    QPushButton *decodeBtn;
    QLabel *label;
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
        loadBtn = new QPushButton(centralWidget);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        loadBtn->setGeometry(QRect(20, 400, 93, 28));
        codeBtn = new QPushButton(centralWidget);
        codeBtn->setObjectName(QStringLiteral("codeBtn"));
        codeBtn->setGeometry(QRect(280, 70, 90, 28));
        resultTextEdit = new QTextEdit(centralWidget);
        resultTextEdit->setObjectName(QStringLiteral("resultTextEdit"));
        resultTextEdit->setGeometry(QRect(390, 50, 231, 331));
        resultTextEdit->setReadOnly(true);
        saveResBtn = new QPushButton(centralWidget);
        saveResBtn->setObjectName(QStringLiteral("saveResBtn"));
        saveResBtn->setGeometry(QRect(530, 400, 93, 28));
        saveInitTextBtn = new QPushButton(centralWidget);
        saveInitTextBtn->setObjectName(QStringLiteral("saveInitTextBtn"));
        saveInitTextBtn->setGeometry(QRect(140, 400, 93, 28));
        decodeBtn = new QPushButton(centralWidget);
        decodeBtn->setObjectName(QStringLiteral("decodeBtn"));
        decodeBtn->setGeometry(QRect(280, 110, 90, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 20, 55, 16));
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
        loadBtn->setText(QApplication::translate("MainWindow", "Load", 0));
        codeBtn->setText(QApplication::translate("MainWindow", "Code", 0));
        saveResBtn->setText(QApplication::translate("MainWindow", "Save As", 0));
        saveInitTextBtn->setText(QApplication::translate("MainWindow", "Save As", 0));
        decodeBtn->setText(QApplication::translate("MainWindow", "Decode", 0));
        label->setText(QApplication::translate("MainWindow", "Result", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
