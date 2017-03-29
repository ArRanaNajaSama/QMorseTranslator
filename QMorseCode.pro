QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMorseCode
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp \
        Morse.cpp

HEADERS  += MainWindow.h \
            Morse.h

FORMS    += MainWindow.ui

DISTFILES +=

RESOURCES +=
