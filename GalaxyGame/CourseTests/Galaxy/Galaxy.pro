#-------------------------------------------------
#
# Project created by QtCreator 2017-07-11T10:09:01
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = galaxytest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++14
TEMPLATE = app


SOURCES += galaxytest.cc \
    ../../Student/galaxy.cc \
    ../../Course/ship.cc \
    ../../Course/starsystem.cc \
    ../../Course/stateexception.cc \
    ../../Course/gameexception.cc \
    ../../Course/objectnotfoundexception.cc \
    ../../Course/utility.cc \
    ../../Course/warpdrive.cc \
    ../../Course/shipengine.cc \
    ../../Course/cargoship.cc \
    ../../Course/repairaction.cc \
    ../../Course/distressaction.cc \
    ../../Course/loadcargo.cc \
    ../../Course/unloadcargo.cc \
    ../../Course/chargeaction.cc \
    ../../Course/wormholedrive.cc \
    ../../Course/moveaction.cc





DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../Student/galaxy.hh


INCLUDEPATH += $$PWD/../../Course
DEPENDPATH += $$PWD/../../Course

INCLUDEPATH += $$PWD/../../Student
DEPENDPATH += $$PWD/../../Student
