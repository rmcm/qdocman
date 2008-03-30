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

#include <QtCore/QDebug>
//#include <QtGui/QStandardItemModel>
#include "qmvdocman.h"
#include "../qmvpmi/qmvpmi.h"

qmvdocman::qmvdocman(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "qmvdocman constructor";
    ui.setupUi(this);
    qDebug() << "qmvdocman ui setup";

    // TODO: extend the db specification:
    // - remember in QSettings
    // - popup selector if not remembered and > 1 option


    connection_model = new QmvDBConnectModel();
    qDebug() << "qmvdocman QmvDBConnectModel setup";
    db_current = connection_model->dbConnection();
    while (!db_current.isValid()) {
        on_actionPreferences_activated();
    }
    Q_ASSERT_X(db_current.isValid(), "qmvdocman::db", "invalid connection");

    qDebug() << "qmvdocman dbConnection setup";

    QmvPMI * pmi = new QmvPMI(db_current, ui.treePatientView, ui.cbPatientSearch);

    // QDirModel *model = new QDirModel();
    // ui.treeBatchView->setModel(model);
    // ui.treeBatchView->setRootIndex(model->index(QDir::currentPath()));

    // // second example
    // QStandardItemModel *model2 = new QStandardItemModel();
    // QStandardItem *parentItem = model2->invisibleRootItem();
    // for (int i = 0; i < 4; ++i) {
    //     QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
    //     item->setEditable(false);
    //     parentItem->appendRow(item);
    //     //parentItem = item;
    // }
    // parentItem->insertColumns(1,2);
    // parentItem->child(1,0)->setCheckable(true);
    // parentItem->child(2,0)->setDragEnabled(true);
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
    QString appname = QCoreApplication::applicationName().toLatin1();
    QmvDBConnectList *db_list = new QmvDBConnectList(connection_model);
    db_list->exec();
    db_current = connection_model->dbConnection();
    delete db_list;
}


// end qmvdocman.cpp
