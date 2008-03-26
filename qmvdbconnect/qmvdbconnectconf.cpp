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

#include <QtSql/QSqlDatabase>
#include <QtGui/QDialogButtonBox>
#include <QtCore/QDebug>
#include "qmvdbconnectconf.h"
#include "qmvdbconnectlist.h"

QmvDBConnectConf::QmvDBConnectConf(QWidget *parent, QmvDBConnectModel::DBConnectionPrefs prefs) :
    QDialog(parent),
    connect_prefs(prefs) {

    // qDebug() << "QmvDBConnectConf constructor";
    // Setup the form
    ui.setupUi(this);
    // We need to configure the dialogbuttons explicitly
    ui.exitControls->clear();
    pb_apply = ui.exitControls->addButton(QDialogButtonBox::Apply);
    pb_apply->setText("&Apply");
    pb_apply->setDefault(true);
    // pb_apply->setEnabled(false);
    pb_discard = ui.exitControls->addButton(QDialogButtonBox::Discard);
    pb_discard->setText("&Discard");
    pb_discard->setDefault(false);
    // pb_discard->setEnabled(false);

    // TODO: set editable data
    // qDebug() << "QmvDBConnectConf:: prefs.count() " << prefs.count();
    ui.labelEdit->setText(connect_prefs.at(QmvDBConnectModel::DBLabel));
    ui.nameEdit->setText(connect_prefs.at(QmvDBConnectModel::DBName));
    ui.hostEdit->setText(connect_prefs.at(QmvDBConnectModel::DBHost));
    ui.portEdit->setText(connect_prefs.at(QmvDBConnectModel::DBPort));
    ui.userEdit->setText(connect_prefs.at(QmvDBConnectModel::DBUser));
    ui.passwordEdit->setText(connect_prefs.at(QmvDBConnectModel::DBPassword));
    ui.optionsEdit->setText(connect_prefs.at(QmvDBConnectModel::DBOptions));

    // qDebug() << "loadConnectionSettings::" << ui.labelEdit->text();
}

QmvDBConnectConf::~QmvDBConnectConf() {
}


// Test the connection and report status
void QmvDBConnectConf::on_testButton_clicked() {
    // qDebug() << "on_testButton_clicked";
    ui.connectLabel->setText("Attempting connection ...");

    // Create a dummy connection to test provided DB preferences
    QString dummy_connection("qmvdbconnect_test");
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL",
                dummy_connection);
        db.setHostName(ui.hostEdit->text());
        db.setDatabaseName(ui.nameEdit->text());
        db.setUserName(ui.userEdit->text());
        db.setPassword(ui.passwordEdit->text());
        bool ok = db.open();
        if (ok) {
            ui.connectLabel->setForegroundRole(QPalette::Text);
            ui.connectLabel->setText("Connection is ok");
        } else {
            ui.connectLabel->setForegroundRole(QPalette::Highlight);
            ui.connectLabel->setText("<b>Connection failed</b>");
        }
        db.close();
    }
    QSqlDatabase::removeDatabase(dummy_connection);
}

// Save and close
void QmvDBConnectConf::on_exitControls_clicked(QAbstractButton * button) {
    // qDebug() << "on_exitControls_clicked";
    // qDebug() << " >> " << button->text();
    // qDebug() << " >> " << ui.exitControls->buttonRole(button);
    // qDebug() << " >> " << ui.exitControls->standardButton(button);
    ui.exitControls->standardButton(button);

    switch(ui.exitControls->standardButton(button))
        {
        case QDialogButtonBox::Apply:
            // Apply
            connect_prefs.clear();
            connect_prefs << ui.labelEdit->text()
                          << ui.nameEdit->text()
                          << ui.hostEdit->text()
                          << ui.portEdit->text()
                          << ui.userEdit->text()
                          << ui.passwordEdit->text()
                          << ui.optionsEdit->text();
            accept();
            break;
        case QDialogButtonBox::Discard:
            reject();
            break;
        default:
            break;
        }
}

QmvDBConnectModel::DBConnectionPrefs QmvDBConnectConf::getPreferences()
{
    return connect_prefs;
}
