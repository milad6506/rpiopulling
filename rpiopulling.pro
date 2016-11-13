QT += core serialport
QT -= gui

CONFIG += c++11

TARGET = rpiopulling
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    serialport.cpp

HEADERS += \
    serialport.h
