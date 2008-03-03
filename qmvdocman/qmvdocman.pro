TEMPLATE = app
TARGET = qmvdocman 

QT        += core gui 

HEADERS   += qmvdocman.h
SOURCES   += main.cpp \
    qmvdocman.cpp
FORMS     += qmvdocman.ui    
RESOURCES +=

INCLUDEPATH += ../qmvdbconnect

LIBS        += ../qmvdbconnect/libqmvdbconnect.a

