#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T11:50:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DSoundKnete
TEMPLATE = app


SOURCES += main.cpp\
        dsoundknete.cpp \
    colorprocessor.cpp \
    shapeRecognition.cpp \
    calibration.cpp\
	handleData.cpp

HEADERS  += dsoundknete.h \
    colorprocessor.h \
    shapeRecognition.h \
    calibration.h\
	handleData.h

FORMS    += dsoundknete.ui
include(../opencv/videoengine.pri)
include(../drumstick/drumstick.pro)
