/** qmvdbconnectlist.cpp ---

 * Copyright (C) 2008 Rex McMaster

 * Author: Rex McMaster <rex@mcmaster.id.au>

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <QtCore/QDebug>
#include <QtCore/QSettings>
#include "qmvdbconnectlist.h"

QmvDBConnectList::QmvDBConnectList()
{
    qDebug() << "QmvDBConnectList Constructor";
    connection_list = new QmvDBConnectModel();
    ui.setupUi(this);
    ui.treeView->setModel(connection_list);
}

QmvDBConnectList::~QmvDBConnectList()
{
    qDebug() << "QmvDBConnectList Destructor";
}

void QmvDBConnectList::on_pbAdd_clicked()
{
    qDebug() << "QmvDBConnectList::on_pbAdd_clicked()";
    connection_list->addConnection();
}
void QmvDBConnectList::on_pbDelete_clicked()
{
}
void QmvDBConnectList::on_pbEdit_clicked()
{
}







