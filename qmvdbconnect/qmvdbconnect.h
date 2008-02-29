#ifndef QMVDBCONNECT_H
#define QMVDBCONNECT_H

#include <QSqlDatabase>
#include <QtGui/QDialog>
#include <QSettings>

class QmvDBConnect : QObject
{
    Q_OBJECT

public:
    QmvDBConnect(const char * name);
    ~QmvDBConnect();

private:
        QSettings *settings;;
};

#endif // QMVDBCONNECT_H
