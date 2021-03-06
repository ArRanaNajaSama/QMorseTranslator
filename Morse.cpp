#include <QMap>
#include "Morse.h"

Morse::Morse(){}

Morse::~Morse(){}

QString Morse::engToMorse(QString str)
{
    str = str.toUpper(); // make all char uppercase.

    QMap <QString, QString> toMorse; // create map to contain keys / values
    toMorse["A"] = ".-";
    toMorse["B"] = "-...";
    toMorse["C"] = "-.-.";
    toMorse["D"] = "-..";
    toMorse["E"] = ".";
    toMorse["F"] = "..-.";
    toMorse["G"] = "--.";
    toMorse["H"] = "....";
    toMorse["I"] = "..";
    toMorse["J"] = ".---";
    toMorse["K"] = "-.-";
    toMorse["L"] = ".-..";
    toMorse["M"] = "--";
    toMorse["N"] = "-.";
    toMorse["O"] = "---";
    toMorse["P"] = ".--.";
    toMorse["Q"] = "--.-";
    toMorse["R"] = ".-.";
    toMorse["S"] = "...";
    toMorse["T"] = "-";
    toMorse["U"] = "..-";
    toMorse["V"] = "...-";
    toMorse["W"] = ".--";
    toMorse["X"] = "-..-";
    toMorse["Y"] = "-.--";
    toMorse["Z"] = "--..";
    toMorse["1"] = ".----";
    toMorse["2"] = "..---";
    toMorse["3"] = "...--";
    toMorse["4"] = "....-";
    toMorse["5"] = ".....";
    toMorse["6"] = "-....";
    toMorse["7"] = "--...";
    toMorse["8"] = "---..";
    toMorse["9"] = "----.";
    toMorse["0"] = "-----";

    QMap <QString, QString>::const_iterator it;

    QString result; // will contain final result

    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == ' ')
        {
            result += "  ";
        } else if (str.at(i) == '\n'){
            result += "\n";
        } else {
            it = toMorse.find(str.at(i));
            if (it == toMorse.end()) // if no match was found -> space
            {
                continue;
            } else {
                result += it.value() + " "; // add letter to string
            }
        }
    }
    return result;
}

QString Morse::morseToEng(QString str)
{
    QMap <QString, QString> toEnglish; // create map to contain keys / values
    toEnglish[".-"] = "A";
    toEnglish["-..."] = "B";
    toEnglish["-.-."] = "C";
    toEnglish["-.."] = "D";
    toEnglish["."] = "E";
    toEnglish["..-."] = "F";
    toEnglish["--."] = "G";
    toEnglish["...."] = "H";
    toEnglish[".."] = "I";
    toEnglish[".---"] = "J";
    toEnglish["-.-"] = "K";
    toEnglish[".-.."] = "L";
    toEnglish["--"] = "M";
    toEnglish["-."] = "N";
    toEnglish["---"] = "O";
    toEnglish[".--."] = "P";
    toEnglish["--.-"] = "Q";
    toEnglish[".-."] = "R";
    toEnglish["..."] = "S";
    toEnglish["-"] = "T";
    toEnglish["..-"] = "U";
    toEnglish["...-"] = "V";
    toEnglish[".--"] = "W";
    toEnglish["-..-"] = "X";
    toEnglish["-.--"] = "Y";
    toEnglish["--.."] = "Z";
    toEnglish[".----"] = "1";
    toEnglish["..---"] = "2";
    toEnglish["...--"] = "3";
    toEnglish["....-"] = "4";
    toEnglish["....."] = "5";
    toEnglish["-...."] = "6";
    toEnglish["--..."] = "7";
    toEnglish["---.."] = "8";
    toEnglish["----."] = "9";
    toEnglish["-----"] = "0";

    QMap <QString, QString>::const_iterator it; // iterate over a QMap
    QString result; // to keep out result
    QStringList words = str.split(QRegExp("[\\s\n]")); //split string by new lines
    for (int i = 0; i < words.size(); i++)
    {
        it = toEnglish.find(words[i]);
        if (it == toEnglish.end()) // if no match was found -> space
        {
            result += " ";

        } else {
            result += it.value(); // add letter to string
        }
    }

    return result;
}
