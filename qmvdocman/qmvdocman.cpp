// qmvdocman.cpp ---
//
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

#include <QtGui/QDirModel>
#include <QtGui/QStandardItemModel>
#include "qmvdocman.h"
#include "qmvdbconnectconf.h"
#include "qmvdbconnectlist.h"

qmvdocman::qmvdocman(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QDirModel *model = new QDirModel();
    ui.treeBatchView->setModel(model);
    ui.treeBatchView->setRootIndex(model->index(QDir::currentPath()));

    // second example
    QStandardItemModel *model2 = new QStandardItemModel();
    QStandardItem *parentItem = model2->invisibleRootItem();
    for (int i = 0; i < 4; ++i) {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        item->setEditable(false);
        parentItem->appendRow(item);
        //parentItem = item;
    }
    parentItem->insertColumns(1,2);
    parentItem->child(1,0)->setCheckable(true);
    parentItem->child(2,0)->setDragEnabled(true);
    ui.treeAllDocumentsView->setModel(new QmvDBConnectList());
}

qmvdocman::~qmvdocman()
{

}

void qmvdocman::on_actionPrint_activated()
{
    ui.statusbar->showMessage("Printing selected documents ...", 5000);
}

void qmvdocman::on_actionFax_activated()
{
    ui.statusbar->showMessage("Faxing selected documents ...", 5000);
}

void qmvdocman::on_actionEmail_activated()
{
    ui.statusbar->showMessage("Emailing selected documents ...", 5000);
}

void qmvdocman::on_actionPreferences_activated()
{
    ui.statusbar->showMessage("Setting Preferences ...", 5000);
    QmvDBConnectConf *w = new QmvDBConnectConf(0, QCoreApplication::applicationName().toLatin1());
    w->exec();
    delete w;
}


// end qmvdocman.cpp
