// TODO: Documentation, header

#ifndef QMVDBCONNECTCONF_H
#define QMVDBCONNECTCONF_H

#include <QtGui/QDialog>
#include <QSettings>
#include <QHash>
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

private slots:
    void on_testButton_clicked();
    void on_exitControls_accepted();
    void on_exitControls_rejected();
    void on_labelList_activated();
//    void on_labelList_editTextChanged(const QString &newtext);
    void on_addConnection_clicked();
    void on_remConnection_clicked();
};

#endif // QMVDBCONNECTCONF_H
