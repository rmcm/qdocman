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
    : settings_group("databases"),
      settings_array("db")
{
    qDebug() << "QmvDBConnectList Constructor";

    // This must match enum dbConnectAttribute
    dbAttTags = (QStringList()
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
                 << "localhost"
                 << "5432"
                 << ""
                 << ""
                 << "");
    loadList();
    saveList();
}

QmvDBConnectList::~QmvDBConnectList()
{
    qDebug() << "QmvDBConnectList Destructor";
}

int QmvDBConnectList::loadList()
{
    qDebug() << "QmvDBConnectList loadList";
    QStandardItem *parentItem = invisibleRootItem();
    QSettings settings;
    settings.beginGroup(settings_group);
    int count = settings.beginReadArray(settings_array);
    qDebug("status=%d count=%d", settings.status(), count);
    QList<QStandardItem *> db;

    for ( int i = 0; i < count; i++ ) {
        while (!db.isEmpty())
            db.takeFirst();

        settings.setArrayIndex(i);
        for (int col = DBLabel; col < DBAttCount; col++ ) {
            db << new QStandardItem(settings.value(dbAttTags.at(col),
                                                   dbAttDefs.at(col)).toString());
        }

        parentItem->appendRow(db);
        qDebug() << i << db.at(DBHost)->text() << db.at(DBName)->text();
    }
    settings.endArray();
    // TODO: load other database settings here
    settings.endGroup();
    qDebug() << " >> loaded " << count << " rows. Model is " << rowCount() << "/" << columnCount();

    return count;
}


int QmvDBConnectList::saveList()
{
    qDebug() << "QmvDBConnectList saveList";

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



