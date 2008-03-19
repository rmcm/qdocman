#include "qmvdocman.h"

#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Define QSettings scope
    QCoreApplication::setOrganizationName("compsoft");
    QCoreApplication::setOrganizationDomain("compsoft.com.au");
    QCoreApplication::setApplicationName("qdocman");

    qmvdocman w;
    w.show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}
