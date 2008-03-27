# qmvdbconnect.pro ---
# -*- C++ -*-
# Copyright (C) 2008 Rex McMaster
# Author: Rex McMaster rex@mcmaster.id.au
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2, or (at
# your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301, USA.

TEMPLATE = lib
TARGET = qmvdbconnect
QT += core \
    gui \
    sql \
    network
HEADERS += qmvdbconnectmodel.h \
	   qmvdbconnectlist.h \
	   qmvdbconnectconf.h
SOURCES += qmvdbconnectmodel.cpp \
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


# end qmvdbconnect.pro
