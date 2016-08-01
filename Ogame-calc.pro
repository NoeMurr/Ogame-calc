#-------------------------------------------------
#
# Project created by QtCreator 2016-07-19T18:09:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ogame-calc
TEMPLATE = app


SOURCES += main.cpp\
        ogcalc.cpp \
    resourcestimer.cpp \
    target.cpp \
    targettablemodel.cpp \
    newtargetdialog.cpp

HEADERS  += ogcalc.h \
    resourcestimer.h \
    target.h \
    targettablemodel.h \
    newtargetdialog.h

FORMS    += ogcalc.ui \
    newtargetdialog.ui
