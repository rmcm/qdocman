// TODO: Documentation - Class description (incl. methods)
#include <QSqlDatabase>
#include "qmvdbconnectconf.h"

QmvDBConnectConf::QmvDBConnectConf(QWidget *parent) :
    QDialog(parent) {
    // Setup the form
    ui.setupUi(this);

    // get current db settings from qsettings
    // and set the fields
    settings = new QSettings();
    settings->beginGroup("qmvdbconnect");
    ui.hostEdit->setText(settings->value("host", "localhost").toString());
    ui.databaseEdit->setText(settings->value("database", "qdocman").toString());
    ui.userEdit->setText(settings->value("user", "").toString());
    ui.passwordEdit->setText(settings->value("password", "").toString());
    settings->endGroup();
}

QmvDBConnectConf::~QmvDBConnectConf() {

}

void QmvDBConnectConf::on_testButton_clicked() {
    ui.connectLabel->setText("Attempting connection ...");

    // TODO: Refactor to new connection class
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL",
                "qmvdbconnect_test");
        db.setHostName(ui.hostEdit->text());
        db.setDatabaseName(ui.databaseEdit->text());
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
    QSqlDatabase::removeDatabase("qmvdbconnect_test");
}
void QmvDBConnectConf::on_buttonBox_accepted() {
    // save the connection settings
    settings->beginGroup("qmvdbconnect");
    settings->setValue("host", ui.hostEdit->text());
    settings->setValue("database", ui.databaseEdit->text());
    settings->setValue("user", ui.userEdit->text());
    settings->setValue("password", ui.passwordEdit->text());
    settings->endGroup();

    accept();
}
