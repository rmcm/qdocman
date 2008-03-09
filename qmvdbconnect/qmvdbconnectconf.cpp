/*
sed: can't read /home/source/templates/CopyLeft: No such file or directory

 */
// TODO: Documentation - Class description (incl. methods)
#include <QSqlDatabase>
#include <QDebug>
//#include <QPushButton>
#include "qmvdbconnectconf.h"

QmvDBConnectConf::QmvDBConnectConf(QWidget *parent, const char * conn_name) :
    QDialog(parent),
    connection_label(conn_name) {

    qDebug() << "QmvDBConnectConf constructor";
    // Setup the form
    ui.setupUi(this);

    // Disable Enter/escape on Save/Cancel buttons
    // QPushButton *pb;
    // pb = ui.exitControls->button(QDialogButtonBox::Save);
    // if (pb) {
    //     qDebug() << pb->isDefault() << pb->autoDefault() << " -> disabling default";
    //     pb->setDefault(false);
    //     pb->setAutoDefault(false);
    //     qDebug() << pb->isDefault() << pb->autoDefault();
    // }

    //    ui.testButton->setDefault(true);
    ui.exitControls->button(QDialogButtonBox::Apply)->setDefault(true);

    // Use application name if no connetion name specified
    if (connection_label.isEmpty())
        connection_label = QCoreApplication::applicationName();

    // get current db settings from qsettings
    // and set the fields
    settings = new QSettings();
    initDBList();
    loadConnectionSettings();
}

QmvDBConnectConf::~QmvDBConnectConf() {
    qDebug() << "QmvDBConnectConf::destructor";
    QHashIterator<QString, Database *> i_conn(connection_list);
    Database *db;
    while( i_conn.hasNext() ) {
        i_conn.next();
        db = i_conn.value();
        delete db;
    }
    connection_list.clear();
}

void QmvDBConnectConf::initDBList() {
    //db_prefix = QString("databases/%1").arg(connection_label);

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
        qDebug() << i << db->label << db->name;
    }
    settings->endArray();
    // other database settings here
    settings->endGroup();

    // // TODO: fix boundary error -> init first entry
    // ui.labelList->setCurrentIndex(0);
    // connection_label = ui.labelList->currentText();

}

// Load current connection settings into form
void QmvDBConnectConf::loadConnectionSettings() {
    if (!connection_list.contains(connection_label)) {
        addConnection(connection_label);
    }
    Database *db = connection_list.value(connection_label);
    // ui.labelEdit->setText(db->label);
    ui.nameEdit->setText(db->name);
    ui.hostEdit->setText(db->host);
    ui.portEdit->setText(db->port);
    ui.userEdit->setText(db->user);
    ui.passwordEdit->setText(db->password);
    ui.optionsEdit->setText(db->options);

    // Set the combobox
    // - this will trigger QComboBox::currentIndexChanged()
    //   but not QComboBox::activated()
    ui.labelList->setCurrentIndex(db->index);
    qDebug() << "loadConnectionSettings::" << db->index << db->label;
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
        qDebug() << "storeConnectionSettings::" << db->index << db->label;
    }
    settings->endArray();
    settings->endGroup();
}

// switch to selected connection
// - update previous connection to connection_list
// - inserting if connection doesn't exist.
void QmvDBConnectConf::on_labelList_activated() {
    qDebug() << "on_labelList_activated() old=" << connection_label;
    Database *db = connection_list.value(connection_label);
    db->label = ui.labelList->itemText(db->index);
    db->name = ui.nameEdit->text();
    db->host = ui.hostEdit->text();
    db->port = ui.portEdit->text();
    db->user = ui.userEdit->text();
    db->password = ui.passwordEdit->text();
    db->options = ui.optionsEdit->text();
    qDebug() << " >> current index/label =" << db->index << db->label;
    if (db->label != connection_label) {
        qDebug() << " >> label has changed to " << db->label;
        connection_list.insert(db->label, db);
        connection_list.remove(connection_label);
    }

    // Save previous edit session
    // Start new edit session
    connection_label = ui.labelList->currentText();
    qDebug() << " >> switching to label " << connection_label;
    while ( !connection_list.contains(connection_label) ) {
        qDebug() << " >> !!! non-existent";
        addConnection(connection_label);
    }
    db = connection_list.value(connection_label);
    loadConnectionSettings();
}

// // update label edits
// void QmvDBConnectConf::on_labelList_editTextChanged( const QString &newtext) {
//     qDebug() << "labelEdit::" << connection_label << " ->" << newtext;
//     int j = connection_list.size();
//     Database *db = connection_list.take(connection_label);
//     db->label = newtext;
//     connection_list.insert( newtext, db);
//     connection_label = newtext;
//     qDebug() << "old/new size = " << connection_list.size() << j;
// }

// Add new connection
void QmvDBConnectConf::addConnection( QString label ) {
    qDebug() << "addConnection";
    Database *db;
    // already exists
    if ( connection_list.contains(label) )
         return;
    db = new Database;
    db->index = connection_list.size();
    db->label = connection_label;
    db->name = connection_label;
    db->host = "localhost";
    db->port = "5432";
    connection_list.insert(connection_label, db);
}

// Test the connection and report status
void QmvDBConnectConf::on_testButton_clicked() {
    qDebug() << "on_testButton_clicked";
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
    qDebug() << "on_exitControls_accepted";
    storeConnectionSettings();
    accept();
}

// Cancel and close
void QmvDBConnectConf::on_exitControls_rejected() {
    qDebug() << "on_exitControls_rejected";
    reject();
}

// Add connection
void QmvDBConnectConf::on_addConnection_clicked() {
    qDebug() << "on_addConnection_clicked";
    connection_label = "New Connection";
    loadConnectionSettings();
}


// Remove connection
void QmvDBConnectConf::on_remConnection_clicked() {

}
