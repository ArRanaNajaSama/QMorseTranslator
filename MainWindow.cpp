#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete m;
}


void MainWindow::on_loadBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"), "",tr("text file (*.txt)"));

    // attempt to open the file in WriteOnly mode.
    // If this is unsuccessful, display a box to inform the user.
    if (fileName.isEmpty()) // check if file is empty -> return
    {
        return;
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
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
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Result"), "", tr("text file (*.txt)"));
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
    //clean result window prior coding
    ui->resultTextEdit->clear();

    //get text from text edit field
    QString init = ui->yourTextTextEdit->toPlainText();

    // check if variable is empty -> display error message
    if (init.isEmpty())
    {
        QMessageBox::information(this, tr("Error!"),tr("Your text field is empty!"));
        return;
    }

    //if not empty call morse translator
    QString res = m->engToMorse(init);

    // display result
    ui->resultTextEdit->setPlainText(res);


}

void MainWindow::on_decodeBtn_clicked()
{
    //clean result window prior decoding
    ui->resultTextEdit->clear();

    //get text from text edit field
    QString init = ui->yourTextTextEdit->toPlainText();

    // check if variable is empty -> display error message
    if (init.isEmpty())
    {
        QMessageBox::information(this, tr("Error!"),tr("Your text field is empty!"));
        return;
    }

    //if not empty call english translator
    QString res = m->morseToEng(init);

    // display result
    ui->resultTextEdit->setPlainText(res);
}


void MainWindow::on_saveResBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Result"), "", tr("text file (*.txt)"));
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
        out << ui->resultTextEdit->toPlainText();
    }
}


void MainWindow::on_clearAllBtn_clicked()
{
    ui->yourTextTextEdit->clear();
    ui->resultTextEdit->clear();
}

void MainWindow::on_yourTextTextEdit_textChanged()
{
    ui->resultTextEdit->clear();
}
