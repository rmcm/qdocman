// qmvdbconnectlist.h ---
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

#ifndef QMVDBCONNECTLIST_H
#define QMVDBCONNECTLIST_H 1

#include <QtGui/QDialog>
#include "qmvdbconnectmodel.h"
#include "ui_qmvdbconnectlist.h"

class QmvDBConnectList : public QDialog
{

    Q_OBJECT

public:
    QmvDBConnectList();
    ~QmvDBConnectList();

private:
    Ui::QmvDBConnectListUI ui;
    QmvDBConnectModel * connection_model;
    int selectedRow() const;

private slots:
    void on_pbEdit_clicked();
    void on_pbDelete_clicked();
    void on_pbAdd_clicked();
};

#endif // QMVDBCONNECTLIST_H

// end qmvdbconnectlist.h
