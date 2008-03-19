/*
 *
 *   Copyright 2008 X=X Computer Software Trust
 *                   Kangaroo Ground Australia 3097
 *
 *
 *  This is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *

 */

#ifndef QMVDBCONNECTCONF_H
#define QMVDBCONNECTCONF_H

#include <QtGui/QDialog>
#include <QtCore/QSettings>
#include <QtCore/QHash>
#include "ui_qmvdbconnectconf.h"

class QmvDBConnectConf : public QDialog {
Q_OBJECT

public:
    QmvDBConnectConf(QWidget *parent = 0, const char * conn_name = 0);
    ~QmvDBConnectConf();

private:
    struct Database {
        int index;
        QString label;
        QString name;
        QString host;
        QString port;
        QString user;
        QString password;
        QString options;
    };
    QHash<QString, Database *> connection_list;
    void initDBList();
    void loadConnectionSettings();
    void storeConnectionSettings();
    void addConnection( QString );
    QSettings *settings;
    Ui::qmvdbconnectClass ui;
    QString connection_label;
    QString db_prefix;
    QPushButton *pb_apply, *pb_discard;

private slots:
    void on_testButton_clicked();
    void on_exitControls_clicked(QAbstractButton * button);
    void on_addConnection_clicked();
    void on_remConnection_clicked();
};

#endif // QMVDBCONNECTCONF_H
