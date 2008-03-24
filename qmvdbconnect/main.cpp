// TODO: add header text, documentation
#include "qmvdbconnectconf.h"

#include <QtGui>
#include <QtGui/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // Define QSettings scope
    QCoreApplication::setOrganizationName("compsoft");
    QCoreApplication::setOrganizationDomain("compsoft.com.au");
    QCoreApplication::setApplicationName("qdocman");
    QmvDBConnectConf *w = new QmvDBConnectConf();

    // TODO: define and parse arguments
    w->show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}
