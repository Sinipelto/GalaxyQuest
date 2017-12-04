#-------------------------------------------------
#
# Project created by QtCreator 2017-10-09T19:40:06
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = statisticstest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++17
TEMPLATE = app


SOURCES += statisticstest.cc \
           ../../Student/statistics.cc \
    ../../Course/gameexception.cc \
    ../../Course/stateexception.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Student/statistics.hh \
    ../../Course/istatistics.hh
INCLUDEPATH += ../../Student ../../Course/
DEPENDPATH += ../../Student
