#include "Morse.h"

#include <QMap>

Morse::Morse()
{

}

QString Morse::engToMorse(QString str)
{
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

    //split words
    QStringList words = str.split(' ');
    for (int i = 0; i < words.size(); i++)
    {
        it = toEnglish.find(words[i]);
        if (it == toEnglish.end())
        {
            result += ' ';

        } else {
            result += it.value();
        }
    }
    return result;
}
