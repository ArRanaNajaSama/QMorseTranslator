#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_codeBtn_clicked();

    void on_saveResBtn_clicked();

    void on_saveInitTextBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
