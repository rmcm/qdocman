TEMPLATE = app
TARGET = qmvdocman 

QT        += core gui 

HEADERS   += qmvdocman.h
SOURCES   += main.cpp \
    qmvdocman.cpp
FORMS     += qmvdocman.ui    
RESOURCES += ../qdocman.qrc

INCLUDEPATH += ../qmvdbconnect

LIBS        += ../qmvdbconnect/libqmvdbconnect.a

