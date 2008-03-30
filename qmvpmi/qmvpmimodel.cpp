// qmvpmimodel.cpp ---
// -*- C++ -*-
//
// Copyright (C) 2008  Rex McMaster
//
// Author: Rex McMaster source@compsoft.com.au
//
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
//

#include <QtCore/QDebug>
#include <QtSql/QSqlQuery>
#include "qmvpmimodel.h"

QmvPMIModel::QmvPMIModel( QObject * parent, QSqlDatabase db )
    : QSqlRelationalTableModel(parent, db)
{
    setTable("patn");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("Surname"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("Firstname"));
    setHeaderData(3, Qt::Horizontal, QObject::tr("DOB"));

    // set filter, sort && select
    QSqlQuery query("select patn__sequence, patn_psnam, patn_fsname, patn_dob from patn");
    setQuery(query);
    setFilter("patn_psname = 'SMITH'");
    select();
}

QmvPMIModel::~QmvPMIModel()
{
}

// end qmvpmimodel.cpp
