TEMPLATE = lib
TARGET = qmvdbconnect
QT += core \
    gui \
    sql \
    network
HEADERS += qmvdbconnect.h \
	   qmvdbconnectconf.h
SOURCES += main.cpp \
	   qmvdbconnect.cpp \
	   qmvdbconnectconf.cpp
FORMS += qmvdbconnectconf.ui
RESOURCES += 

CONFIG += staticlib
CONFIG    += create_prl
CONFIG    += link_prl
