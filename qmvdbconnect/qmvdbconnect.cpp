// qmvdbconnect.cpp ---
// -*- C++ -*-
// Copyright (C) 2008 Rex McMaster
// Author: Rex McMaster rex@mcmaster.id.au
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.



#include <QtSql/QSqlDatabase>
#include "qmvdbconnect.h"

QmvDBConnect::QmvDBConnect(const char *name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", name);
    // get current db settings from qsettings
    // and set the fields
    settings = new QSettings();
    settings->beginGroup(name);
    db.setHostName(settings->value("host", "localhost").toString());
    db.setDatabaseName(settings->value("database", "qdocman").toString());
    db.setUserName(settings->value("user", "").toString());
    db.setPassword(settings->value("password", "").toString());
    settings->endGroup();
}

QmvDBConnect::~QmvDBConnect() {
    QSqlDatabase::removeDatabase("qmvdbconnect_test");
}

// end qmvdbconnect.cpp
