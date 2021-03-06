#-------------------------------------------------
#
# Project created by QtCreator 2018-05-03T18:12:01
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Katsu-kun
TEMPLATE = app

INCLUDEPATH += include

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        src\mainwindow.cpp \
        src\databasemanager.cpp \
        src\verb.cpp \
        src\ichidan.cpp \
        src\godan.cpp \
    src/suru.cpp \
    src/kuru.cpp

HEADERS += \
        include\mainwindow.h \
        include\databasemanager.h \
        include\verb.h \
        include\ichidan.h \
        include\godan.h \
    include/suru.h \
    include/kuru.h

FORMS += \
        mainwindow.ui
