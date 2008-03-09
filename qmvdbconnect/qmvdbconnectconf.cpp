// TODO: Documentation - Class description (incl. methods)
#include <QSqlDatabase>
#include <QDebug>
#include "qmvdbconnectconf.h"

QmvDBConnectConf::QmvDBConnectConf(QWidget *parent, const char * conn_name) :
    QDialog(parent),
    connection_name(conn_name) {

    // Setup the form
    ui.setupUi(this);

    // Use application name if no connetion name specified
    if (connection_name.isEmpty())
        connection_name = QCoreApplication::applicationName();

    // get current db settings from qsettings
    // and set the fields
    settings = new QSettings();
    initDBList();
    loadConnectionSettings();
}

QmvDBConnectConf::~QmvDBConnectConf() {
    // nothing
}

void QmvDBConnectConf::initDBList() {
    //db_prefix = QString("databases/%1").arg(connection_name);

    settings->beginGroup("databases");
    // settings->beginWriteArray("xx");
    // settings->setArrayIndex(0);
    // settings->setValue("name", "db0");
    // settings->setValue("host", "localhost");
    // settings->setArrayIndex(1);
    // settings->setValue("name", "db1");
    // settings->setValue("host", "localhost");
    // settings->setArrayIndex(2);
    // settings->setValue("name", "db2");
    // settings->setValue("host", "localhost");
    // settings->setArrayIndex(3);
    // settings->setValue("name", "db3");
    // settings->setValue("host", "localhost");
    // settings->endArray();

    int count = settings->beginReadArray("xx");
    qDebug("status=%d count=%d", settings->status(), count);
    for ( int i = 0; i < count; i++ ) {
        settings->setArrayIndex(i);
        qDebug(">> %d", i);
        Database *db = new Database;
        db->index   = i;
        db->label   = settings->value("label", QString("label-%1").arg(i)).toString();
        db->name    = settings->value("name").toString();
        db->host    = settings->value("host", "localhost").toString();
        db->port    = settings->value("port", "5432").toString();
        db->user    = settings->value("user").toString();
        db->options = settings->value("options").toString();
        connection_list.insert(db->label, db);
        ui.labelList->addItem(db->label, i);
    }
    settings->endArray();
    // other database settings here
    settings->endGroup();

    // TODO: fix boundary error -> init first entry
    ui.labelList->setCurrentIndex(0);
    connection_name = ui.labelList->currentText();

}

// Load current connection settings into form
void QmvDBConnectConf::loadConnectionSettings() {
    if (!connection_list.contains(connection_name)) {
        addConnection(connection_name);
    }
    Database *db = connection_list.value(connection_name);
    // ui.labelEdit->setText(db->label);
    ui.nameEdit->setText(db->name);
    ui.hostEdit->setText(db->host);
    ui.portEdit->setText(db->port);
    ui.userEdit->setText(db->user);
    ui.passwordEdit->setText(db->password);
    ui.optionsEdit->setText(db->options);

}

// Save the connection list to settings db
void QmvDBConnectConf::storeConnectionSettings() {

    settings->beginGroup("databases");
    settings->beginWriteArray("xx");
    QHashIterator<QString, Database *> i_conn(connection_list);
    Database *db;
    while( i_conn.hasNext() ) {
        i_conn.next();
        db = i_conn.value();
        int i = db->index;
        settings->setArrayIndex(i);
        settings->setValue("label", db->label);
        settings->setValue("name", db->name);
        settings->setValue("host", db->host);
        settings->setValue("port", db->port);
        settings->setValue("user", db->user);
        settings->setValue("password", db->password);
        settings->setValue("options", db->options);
    }
    settings->endArray();
    settings->endGroup();
}

// switch to selected connection, inserting if not exists.
void QmvDBConnectConf::on_labelList_activated() {
    Database *db;
    connection_name = ui.labelList->currentText();
    while ( !connection_list.contains(connection_name) ) {
        addConnection(connection_name);
    }
    db = connection_list.value(connection_name);

    loadConnectionSettings();
}

// Add new connection
void QmvDBConnectConf::addConnection( QString label ) {
    Database *db;
    // already exists
    if ( connection_list.contains(label) )
         return;
    db = new Database;
    db->index = connection_list.size();
    db->label = connection_name;
    db->name = connection_name;
    db->host = "localhost";
    db->port = "5432";
    connection_list.insert(connection_name, db);
}

// Test the connection and report status
void QmvDBConnectConf::on_testButton_clicked() {
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
void QmvDBConnectConf::on_exitControls_accepted() {
    storeConnectionSettings();
    accept();
}

// Cancel and close
void QmvDBConnectConf::on_exitControls_rejected() {
    reject();
}

// Add connection
void QmvDBConnectConf::on_addConnection_clicked() {
    connection_name = "New Connection";
    loadConnectionSettings();
    //    ui.labelList->setCurrentIndex(??);
}


// Remove connection
void QmvDBConnectConf::on_remConnection_clicked() {

}
