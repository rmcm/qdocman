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
      settings_array("db"),
      available(":/icons/tango-icon-theme/32x32/status/network-transmit-receive.png"),
      unavailable(":/icons/tango-icon-theme/32x32/status/network-offline.png")
{
    qDebug() << "QmvDBConnectModel Constructor";

    // These must match enum dbConnectAttribute
    dbAttTags = (QStringList() // Tags/labels
                 << "Label"
                 << "Name"
                 << "Host"
                 << "Port"
                 << "User"
                 << "Password"
                 << "Options");
    dbAttDefs = (QStringList() // defaults
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

    for ( int row = 0; row < count; row++ ) {
        while (!db.isEmpty())
            db.takeFirst();

        settings.setArrayIndex(row);
        for (int col = DBLabel; col < DBAttCount; col++ ) {
            QString value = settings.value(dbAttTags.at(col), dbAttDefs.at(col)).toString();
            QStandardItem *db_item = new QStandardItem(value);
            // list is read-only
            db_item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            db << db_item;
            qDebug() << "Adding " << db_item;
        }
        parentItem->appendRow(db);
        qDebug() << row << db.at(DBHost)->text() << db.at(DBName)->text();
        // check connection
        if (testConnection(row))
            db.at(DBLabel)->setIcon(available);
        else
            db.at(DBLabel)->setIcon(unavailable);
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

QmvDBConnectModel::DBConnectionPrefs QmvDBConnectModel::connectionPrefs( int row )
{
    dbAttVals.clear();
    if (row >= 0 && row < rowCount()) {
        for (int col = DBLabel; col < DBAttCount; col++)
            {
                dbAttVals << item(row, col)->text();
            }
    }
    return dbAttVals;
}

void QmvDBConnectModel::setConnectionPrefs( int row, DBConnectionPrefs prefs)
{
    qDebug() << "QmvDBConnectModel::setConnectionPrefs" << prefs;
    if (row >= 0 && row < rowCount()) {
        dbAttVals << item(row, DBLabel)->text();
        dbAttVals << item(row, DBName)->text();
        for (int col = DBLabel; col < DBAttCount; col++) {
            item(row, col)->setText(prefs.at(col));
        }
        if (testConnection(row))
            item(row, DBLabel)->setIcon(available);
        else
            item(row, DBLabel)->setIcon(unavailable);
    }
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
    qDebug() << "QmvDBConnectModel::deleteConnection() row=" << row;
    if (row >= 0 && row < rowCount())
        takeRow(row);
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

