#include "qmvdocman.h"
#include "qmvdbconnectconf.h"

qmvdocman::qmvdocman(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
}

qmvdocman::~qmvdocman()
{

}
void qmvdocman::on_actionPrint_activated()
{
    ui.statusbar->showMessage("Printing selected documents ...", 5000);
}

void qmvdocman::on_actionFax_activated()
{
    ui.statusbar->showMessage("Faxing selected documents ...", 5000);
}

void qmvdocman::on_actionEmail_activated()
{
    ui.statusbar->showMessage("Emailing selected documents ...", 5000);
}

void qmvdocman::on_actionPreferences_activated()
{
    ui.statusbar->showMessage("Setting Preferences ...", 5000);
    QmvDBConnectConf *w = new QmvDBConnectConf();
    w->exec();
}
