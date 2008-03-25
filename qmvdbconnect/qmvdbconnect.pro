TEMPLATE = lib
TARGET = qmvdbconnect
QT += core \
    gui \
    sql \
    network
HEADERS += qmvdbconnect.h \
	   qmvdbconnectmodel.h \
	   qmvdbconnectlist.h \
	   qmvdbconnectconf.h
SOURCES += main.cpp \
	   qmvdbconnect.cpp \
	   qmvdbconnectmodel.cpp \
	   qmvdbconnectlist.cpp \
	   qmvdbconnectconf.cpp
FORMS += qmvdbconnectlist.ui \
	 qmvdbconnectconf.ui
RESOURCES += 

CONFIG += staticlib
CONFIG    += create_prl
CONFIG    += link_prl

## extra target for flymake in emacs
flymake.target  = check-syntax
flymake.commands = gcc -o nul -S ${CHK_SOURCES} $(INCPATH)
QMAKE_EXTRA_TARGETS += flymake
