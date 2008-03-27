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
#include <QtGui/QMessageBox>

#include "qmvdbconnectlist.h"
#include "qmvdbconnectconf.h"

QmvDBConnectList::QmvDBConnectList()
{
    // qDebug() << "QmvDBConnectList Constructor";
    connection_model = new QmvDBConnectModel();
    QItemSelectionModel *selection_model = new QItemSelectionModel(connection_model);
    ui.setupUi(this);
    ui.treeView->setModel(connection_model);
    ui.treeView->setSelectionModel(selection_model);
    setCurrentRow(0);
}

QmvDBConnectList::~QmvDBConnectList()
{
    // qDebug() << "QmvDBConnectList Destructor";
}

void QmvDBConnectList::on_pbAdd_clicked()
{
    // qDebug() << "QmvDBConnectList::on_pbAdd_clicked()";
    connection_model->addConnection();
    setCurrentRow(connection_model->rowCount() - 1);
    //ui.pbEdit->setFocus();
    on_pbEdit_clicked();
}
void QmvDBConnectList::on_pbDelete_clicked()
{
    // qDebug() << "QmvDBConnectList::on_pbDelete_clicked()";
    int row = selectedRow();
    if (row < 0)
        return;
    if (QMessageBox::warning(0, "Confirm Deletion",
                             tr("Are you sure you want to delete this row ?<BR>"
                                "<BR>%1")
                             .arg(connection_model->rowLabel(row)),
                             QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        connection_model->deleteConnection(row);
        connection_model->saveModel();
        setCurrentRow(connection_model->rowCount() - 1);
    }
}
void QmvDBConnectList::on_pbEdit_clicked()
{
    // qDebug() << "QmvDBConnectList::on_pbEdit_clicked()";
    int row = selectedRow();
    QmvDBConnectModel::DBConnectionPrefs prefs = connection_model->connectionPrefs(row);
    QmvDBConnectConf *editor = new QmvDBConnectConf(this, prefs);
    if (editor->exec() == QDialog::Accepted)
        {
            connection_model->setConnectionPrefs(row, editor->getPreferences());
            connection_model->saveModel();
        }
    delete editor;
    //ui.treeView->setFocus();
}

int QmvDBConnectList::selectedRow() const
{
    // qDebug() << "QmvDBConnectList::on_pbEdit_clicked()";
    QModelIndexList selected  = ui.treeView->selectionModel()->selectedRows();
    if (selected.count() < 1) {
        QMessageBox::warning(0, "Nothing selected",
                             tr("No row has been selected<BR> ... please select a row to edit"),
                             QMessageBox::Ok,0);
        return -1;
    }
    // qDebug() << "rows selected = " << selected.first().row();
    return selected.first().row();
}

void QmvDBConnectList::setCurrentRow( int row )
{
    if (row < 0)
        row = 0;
    if (row > connection_model->rowCount() -1)
        row = connection_model->rowCount() -1;
    QModelIndex idx = connection_model->indexFromItem(connection_model->item(row, 0));
    QItemSelectionModel::SelectionFlags flags
        = QItemSelectionModel::ClearAndSelect|QItemSelectionModel::Rows;
    ui.treeView->selectionModel()->setCurrentIndex(idx, flags);
}





