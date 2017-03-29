#pragma once

#include <QString>

class Morse
{
public:
    Morse();
    QString engToMorse(QString str); // function to translate english into Morse;
    QString morseToEng(QString str); // function to translate morse into English

};
