// qmvpmi.cpp ---
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
#include "qmvpmi.h"

QmvPMI::QmvPMI( QSqlDatabase db, QTreeView * treeview, QComboBox * query )
{
    qDebug() << "QmvPMI Constructor";

    pmi_model = new QmvPMIModel(this, db);
    QItemSelectionModel *selection_model = new QItemSelectionModel(pmi_model);
    treeview->setModel(pmi_model);
    treeview->setSelectionModel(selection_model);
    setCurrentRow(0);

}

QmvPMI::~QmvPMI()
{
}

void QmvPMI::setCurrentRow(int row)
{
    ;
}
// end qmvpmi.cpp
