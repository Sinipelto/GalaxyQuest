#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T12:45:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GalaxyGame
TEMPLATE = app
CONFIG += c++17

SOURCES += \
    main.cc\
    galaxy.cc \
    statistics.cc \
    eventhandler.cc \
    startdialog.cc \
    gamewindow.cc \
    playership.cc \
    control.cc \
    tools.cc \
    playershipnamegenerator.cc \
    scoreboard.cc

HEADERS  += \
    galaxy.hh \
    eventhandler.hh \
    statistics.hh \
    gamewindow.hh \
    startdialog.hh \
    playershipnamegenerator.hh \
    tools.hh \
    playership.hh \
    control.hh \
    complex.hh \
    scoreboard.hh

INCLUDEPATH += $$PWD/../Course
DEPENDPATH += $$PWD/../Course

CONFIG(release, debug|release) {
   DESTDIR = release
}

CONFIG(debug, debug|release) {
   DESTDIR = debug
}

win32 {
    copyfiles.commands += @echo NOW COPYING ADDITIONAL FILE(S) for Windows &
    copyfiles.commands += @call xcopy ..\\..\\GalaxyGame\\Assets Assets /i /s /e /y
}
unix:!macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for Linux\" &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR
}
macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for MacOS\" &&
    copyfiles.commands += mkdir -p $$DESTDIR/GalaxyGame.app/Contents/MacOS &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR &&
    copyfiles.commands += cp -r ../../GalaxyGame/Assets $$DESTDIR/GalaxyGame.app/Contents/MacOS/
}

LIBS += -L$$OUT_PWD/../Course/
LIBS += -L$$OUT_PWD/../Course/$${DESTDIR}/ -lCourse


QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

FORMS += \
    gamewindow.ui \
    startdialog.ui
