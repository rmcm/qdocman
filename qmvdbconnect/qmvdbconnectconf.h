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
#include "qmvdbconnectmodel.h"

class QmvDBConnectConf : public QDialog {
Q_OBJECT

public:
    QmvDBConnectConf(QWidget *parent, QmvDBConnectModel::DBConnectionPrefs prefs);
    ~QmvDBConnectConf();

    QmvDBConnectModel::DBConnectionPrefs getPreferences();

private:
    Ui::qmvdbconnectClass ui;
    QmvDBConnectModel::DBConnectionPrefs connect_prefs;
    int connect_row;
    QPushButton *pb_apply, *pb_discard;

private slots:
    void on_testButton_clicked();
    void on_exitControls_clicked(QAbstractButton * button);
};

#endif // QMVDBCONNECTCONF_H
