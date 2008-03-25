/** qmvdbconnectmodel.cpp ---

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
#include <QtSql/QSqlDatabase>
#include "qmvdbconnectmodel.h"

QmvDBConnectModel::QmvDBConnectModel()
    : settings_group("databases"),
      settings_array("db")
{
    qDebug() << "QmvDBConnectModel Constructor";

    // This must match enum dbConnectAttribute
    dbAttTags = (QStringList()
                 << "Accessible"
                 << "Label"
                 << "Name"
                 << "Host"
                 << "Port"
                 << "User"
                 << "Password"
                 << "Options");
    dbAttDefs = (QStringList()
                 << ""
                 << ""
                 << ""
                 << "localhost"
                 << "5432"
                 << ""
                 << ""
                 << "");

    setHorizontalHeaderLabels(dbAttTags);
    loadModel();
}

QmvDBConnectModel::~QmvDBConnectModel()
{
    qDebug() << "QmvDBConnectModel Destructor";
    // TODO: clear items ??
}

int QmvDBConnectModel::loadModel()
{
    qDebug() << "QmvDBConnectModel loadList";
    QStandardItem *parentItem = invisibleRootItem();
    QSettings settings;
    settings.beginGroup(settings_group);
    int count = settings.beginReadArray(settings_array);
    qDebug("status=%d count=%d", settings.status(), count);
    QList<QStandardItem *> db;
    QIcon available  = QIcon(":/icons/tango-icon-theme/32x32/status/network-transmit-receive.png");
    QIcon unavailable =  QIcon(":/icons/tango-icon-theme/32x32/status/network-offline.png");

    for ( int i = 0; i < count; i++ ) {
        while (!db.isEmpty())
            db.takeFirst();

        settings.setArrayIndex(i);
        QStandardItem *db_status = new QStandardItem(unavailable, "");
        db_status->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled); //read-only
        db << db_status;
        for (int col = DBLabel; col < DBAttCount; col++ ) {
            QString value = settings.value(dbAttTags.at(col), dbAttDefs.at(col)).toString();
            QStandardItem *db_item = new QStandardItem(value);
            // list is read-only
            db_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            db << db_item;
        }
        parentItem->appendRow(db);
        qDebug() << i << db.at(DBHost)->text() << db.at(DBName)->text();
        // check connection
        if (testConnection(i))
                db_status->setIcon(available);
    }
    settings.endArray();
    // TODO: load other database settings here
    settings.endGroup();
    qDebug() << " >> loaded " << count << " rows. Model is " << rowCount() << "/" << columnCount();

    return count;
}


int QmvDBConnectModel::saveModel()
{
    qDebug() << "QmvDBConnectModel saveList";

    QSettings settings;
    settings.beginGroup(settings_group);
    settings.beginWriteArray(settings_array);

    int count = rowCount();
    for (int row = 0; row < count; row++ ) {
        settings.setArrayIndex(row);
        for (int col = DBLabel; col < DBAttCount; col++ )
            {
                qDebug() << "  >> " << row << "/" << col;
                if (!item(row, col))
                    continue;
                settings.setValue(dbAttTags.at(col), item(row, col)->text());
                qDebug() << "saveList::" << item(row, col)->text();
            }
    }
    settings.endArray();
    // TODO: save other database settings here
    settings.endGroup();
    return count;
}

void QmvDBConnectModel::addConnection()
{
    qDebug() << "QmvDBConnectModel::addConnection()";
    QList<QStandardItem *> db;
    for (int col = DBLabel; col < DBAttCount; col++ ) {
        db << new QStandardItem(dbAttDefs.at(col));
    }
    invisibleRootItem()->appendRow(db);
    saveModel();
}

void QmvDBConnectModel::deleteConnection(int row)
{
    if (row < 0)
        return;
}

bool QmvDBConnectModel::testConnection(int row)
{
    // Create a dummy connection to test provided DB preferences
    bool ok = false;
    QString dummy_connection("qmvdbconnectmodel_test");
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL",
                                                    dummy_connection);
        if (item(row, DBHost) && item(row, DBName)
            && item(row, DBUser) && item(row, DBPassword))
            {
                db.setHostName(item(row, DBHost)->text());
                db.setDatabaseName(item(row, DBName)->text());
                db.setUserName(item(row,DBUser)->text());
                db.setPassword(item(row,DBPassword)->text());
                ok = db.open();
                db.close();
                qDebug() << "testConnection status " << ok;
            } else {
                qDebug() << "testConnection failed - item(s) missing";
            }
    }

    QSqlDatabase::removeDatabase(dummy_connection);
    return ok;
}

