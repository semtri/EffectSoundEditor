#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T11:37:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EffectSoundEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QMAKE_LFLAGS += -L/Users/dennis/SDKs/SDL2-2.0.4/built/lib -lSDL2

LIBS += -framework Carbon -framework cocoa -framework IOKit -framework CoreAudio -framework CoreFoundation \
    -framework AudioUnit -framework AudioToolbox -framework CoreVideo -framework ForceFeedback \
      -liconv
INCLUDEPATH += /Users/dennis/SDKs/SDL2-2.0.4/built/include
