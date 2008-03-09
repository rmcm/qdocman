#include <QSqlDatabase>
#include "qmvdbconnect.h"

QmvDBConnect::QmvDBConnect(const char *name)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", name);
    // get current db settings from qsettings
    // and set the fields
    settings = new QSettings();
    settings->beginGroup(name);
    db.setHostName(settings->value("host", "localhost").toString());
    db.setDatabaseName(settings->value("database", "qdocman").toString());
    db.setUserName(settings->value("user", "").toString());
    db.setPassword(settings->value("password", "").toString());
    settings->endGroup();
}

QmvDBConnect::~QmvDBConnect() {
    QSqlDatabase::removeDatabase("qmvdbconnect_test");
}
