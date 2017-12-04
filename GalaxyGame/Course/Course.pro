
TARGET = Course
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++14

SOURCES += \
    starsystem.cc \
    starsystemfactory.cc \
    shipfactory.cc \
    initialize.cc \
    formatexception.cc \
    ioexception.cc \
    gameexception.cc \
    warpdrive.cc \
    moveaction.cc \
    cargoship.cc \
    utility.cc \
    gamerunner.cc \
    ship.cc \
    loadcargo.cc \
    unloadcargo.cc \
    distressaction.cc \
    repairaction.cc \
    shipengine.cc \
    shipnamegenerator.cc \
    wormholedrive.cc \
    chargeaction.cc \
    stateexception.cc \
    objectnotfoundexception.cc

HEADERS += igalaxy.hh \
    igamerunner.hh \
    doxygeninfo.hh \
    starsystem.hh \
    starsystemfactory.hh \
    shipfactory.hh \
    initialize.hh \
    formatexception.hh \
    ioexception.hh \
    gameexception.hh \
    warpdrive.hh \
    iaction.hh \
    moveaction.hh \
    cargoship.hh \
    utility.hh \
    gamerunner.hh \
    ship.hh \
    loadcargo.hh \
    unloadcargo.hh \
    distressaction.hh \
    repairaction.hh \
    point.hh \
    shipengine.hh \
    shipnamegenerator.hh \
    wormholedrive.hh \
    chargeaction.hh \
    istatistics.hh \
    stateexception.hh \
    ieventhandler.hh \
    objectnotfoundexception.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}
