#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QMap>

#include "MainWindow.h"
#include "ui_MainWindow.h"

QString engToMorse (QString str); // function to translate english into Morse;
QString morseToEng (QString str); // function to translate morse into English

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadBtn_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Open file"), "",
                                                    tr("text file (*.txt)"));

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
    QString res = engToMorse(init); // convert english text in Morse
    ui->resultTextEdit->setPlainText(res); // display result
}

void MainWindow::on_saveResBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Result"), "",
                                                    tr("text file (*.txt)"));

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

QString engToMorse(QString str)
{
    QMap <QString, QString> toMorse; // create map to contain keys / values
    toMorse["A"] = ". -";
    toMorse["B"] = "- . . .";
    toMorse["C"] = "- . - .";
    toMorse["D"] = "- . .";
    toMorse["E"] = ".";
    toMorse["F"] = ". . - .";
    toMorse["G"] = "- - .";
    toMorse["H"] = ". . . .";
    toMorse["I"] = ". .";
    toMorse["J"] = ". - - -";
    toMorse["K"] = "- . -";
    toMorse["L"] = ". - . .";
    toMorse["M"] = "- -";
    toMorse["N"] = "- .";
    toMorse["O"] = "- - -";
    toMorse["P"] = ". - - .";
    toMorse["Q"] = "- - . -";
    toMorse["R"] = ". - .";
    toMorse["S"] = ". . .";
    toMorse["T"] = "-";
    toMorse["U"] = ". . -";
    toMorse["V"] = ". . . -";
    toMorse["W"] = ". - -";
    toMorse["X"] = "- . . -";
    toMorse["Y"] = "- . - -";
    toMorse["Z"] = "- - . .";
    toMorse["1"] = ". - - - -";
    toMorse["2"] = ". . - - -";
    toMorse["3"] = ". . .- -";
    toMorse["4"] = ". . . . -";
    toMorse["5"] = ". . . . .";
    toMorse["6"] = "- . . . .";
    toMorse["7"] = "- - . . .";
    toMorse["8"] = "- - - . .";
    toMorse["9"] = "- - - - .";
    toMorse["0"] = "- - - - -";

    QMap <QString, QString>::const_iterator it;

    str = str.toUpper(); // make sure that all char are uppercase.

    QString result; // will contain final result

    for (int i = 0; i < str.size(); i++)
    {
        if(str.at(i) != ' ') // is current char is not space
        {

            it = toMorse.find(str.at(i)); // we will seek through our map for it
            if (str.at(i) != it.key()) // if char is not in map - just skip
            {
                continue;
            } else {
                result += it.value() + " "; // if char is found write it's value in result + space;
            }
        } else if (str.at(i) == ' ') // is char is space
        {
            result += " "; // add extra space to line;
        }
    }
    return result;
}

QString morseToEng (QString str)
{
    QMap <QString, QString> toEnglish; // create map to contain keys / values
    toEnglish[". -"] = "A";
    toEnglish["- . . ."] = "B";
    toEnglish["- . - ."] = "C";
    toEnglish["- . ."] = "D";
    toEnglish["."] = "E";
    toEnglish[". . - ."] = "F";
    toEnglish["- - ."] = "G";
    toEnglish[". . . ."] = "H";
    toEnglish[". ."] = "I";
    toEnglish[". - - -"] = "J";
    toEnglish["- . -"] = "K";
    toEnglish[". - . ."] = "L";
    toEnglish["- -"] = "M";
    toEnglish["- ."] = "N";
    toEnglish["- - -"] = "O";
    toEnglish[". - - ."] = "P";
    toEnglish["- - . -"] = "Q";
    toEnglish[". - ."] = "R";
    toEnglish[". . ."] = "S";
    toEnglish["-"] = "T";
    toEnglish[". . -"] = "U";
    toEnglish[". . . -"] = "V";
    toEnglish[". - -"] = "W";
    toEnglish["- . . -"] = "X";
    toEnglish["- . - -"] = "Y";
    toEnglish["- - . ."] = "Z";
    toEnglish[". - - - -"] = "1";
    toEnglish[". . - - -"] = "2";
    toEnglish[". . .- -"] = "3";
    toEnglish[". . . . -"] = "4";
    toEnglish[". . . . ."] = "5";
    toEnglish["- . . . ."] = "6";
    toEnglish["- - . . ."] = "7";
    toEnglish["- - - . ."] = "8";
    toEnglish["- - - - ."] = "9";
    toEnglish["- - - - -"] = "0";
}


