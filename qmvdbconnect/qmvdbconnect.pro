TEMPLATE = app
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
