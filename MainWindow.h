#pragma once

#include <QMainWindow>

#include "Morse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadBtn_clicked();
    void on_saveInitTextBtn_clicked();
    void on_codeBtn_clicked();
    void on_decodeBtn_clicked();
    void on_saveResBtn_clicked();
    void on_clearAllBtn_clicked();
    void on_yourTextTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    Morse *m;

};
