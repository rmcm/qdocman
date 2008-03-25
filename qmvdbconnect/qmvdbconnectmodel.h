/** qmvdbconnectmodel.h ---

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

#ifndef QMVDBCONNECTMODEL_H
#define QMVDBCONNECTMODEL_H 1

#include <QtGui/QStandardItemModel>

class QmvDBConnectModel : public QStandardItemModel
{

    Q_OBJECT

public:
    QmvDBConnectModel();
    ~QmvDBConnectModel();
    enum dbConnectAttribute {
        DBConnected = 0,
        DBLabel,
        DBName,
        DBHost,
        DBPort,
        DBUser,
        DBPassword,
        DBOptions,
        DBAttCount
    };
    int loadModel();
    int saveModel();
    void addConnection();
    void deleteConnection( int row = -1);
    bool testConnection(int row);

private:
    QString settings_group, settings_array;
    QStringList dbAttTags;
    QStringList dbAttDefs;
};

#endif // QMVDBCONNECTMODEL_H
