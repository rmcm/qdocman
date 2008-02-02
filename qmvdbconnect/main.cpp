#include "qmvdbconnect.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("compsoft");
    QCoreApplication::setOrganizationDomain("compsoft.com.au");
    QCoreApplication::setApplicationName("qdocman");
    qmvdbconnect *w = new qmvdbconnect();
    w->show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}
