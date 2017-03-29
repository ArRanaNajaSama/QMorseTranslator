#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QMap>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadBtn_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this,tr("Open file"), "",tr("text file (*.txt)"));

    // Next, we attempt to open the file in WriteOnly mode.
    // If this is unsuccessful, we display a QMessageBox to inform the user.
    if (fileName.isEmpty())
    {
        return;
    } else {

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QTextStream in(&file);
        QString line = in.readAll();
        file.close();
        ui->yourTextTextEdit->setPlainText(line);
        QTextCursor cursor = ui->yourTextTextEdit->textCursor();
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
    }
}

void MainWindow::on_saveInitTextBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Result"), "",
                                                    tr("text file (*.txt)"));

    // Next, we attempt to open the file in WriteOnly mode.
    // If this is unsuccessful, we display a QMessageBox to inform the user.
    if (fileName.isEmpty())
    {
        return;
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }

        QTextStream out(&file);

        out << ui->yourTextTextEdit->toPlainText();
    }
}

void MainWindow::on_codeBtn_clicked()
{
    QString init = ui->yourTextTextEdit->toPlainText();
    // check if variable is empty -> display error message
    if (init.isEmpty())
    {
        QMessageBox::information(this, tr("Error!"),tr("Text field is empty!"));
        return;
    }
    QString res = m.engToMorse(init); // convert english text in Morse
    ui->resultTextEdit->setPlainText(res); // display result
}

void MainWindow::on_decodeBtn_clicked()
{
    QString init = ui->yourTextTextEdit->toPlainText();
    // check if variable is empty -> display error message
    if (init.isEmpty())
    {
        QMessageBox::information(this, tr("Error!"),tr("Text field is empty!"));
        return;
    }
    QString res = m.morseToEng(init); // convert english text in Morse
    ui->resultTextEdit->setPlainText(res); // display result
}

void MainWindow::on_saveResBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Result"), "", tr("text file (*.txt)"));

    // Next, we attempt to open the file in WriteOnly mode.
    // If this is unsuccessful, we display a QMessageBox to inform the user.
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),file.errorString());
            return;
        }

        QTextStream out(&file);
        out << ui->resultTextEdit->toPlainText();
    }
}




