#-------------------------------------------------
#
# Project created by QtCreator 2016-12-31T11:04:31
#
#-------------------------------------------------

QT       -= gui

TARGET = Util
TEMPLATE = lib

DEFINES += UTIL_LIBRARY
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boostlogcfg.cpp \
    logcfg.cpp \
    logcfgfactory.cpp \
    logconfig.cpp

HEADERS += \
    boostlogcfg.h \
    logcfg.h \
    logcfgfactory.h \
    logconfig.h \
    boostlogger.h

LIBS += -LD:\Software\Boost\boost_1_62_0\lib64-msvc-14.0

INCLUDEPATH += D:\Software\Boost\boost_1_62_0
DEPENDPATH += D:\Software\Boost\boost_1_62_0
