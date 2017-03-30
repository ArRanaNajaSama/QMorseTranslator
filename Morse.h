/*Class designed to contain 2 methods: code and decode Morse.*/

#pragma once

#include <QString>

class Morse
{
public:
    Morse();
    QString engToMorse(QString str); // method to translate english into Morse;
    QString morseToEng(QString str); // method to translate morse into English

};
