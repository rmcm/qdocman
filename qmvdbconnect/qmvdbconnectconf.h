// TODO: Documentation, header

#ifndef QMVDBCONNECT_H
#define QMVDBCONNECT_H

#include <QtGui/QDialog>
#include <QSettings>
#include "ui_qmvdbconnectconf.h"

class QmvDBConnectConf : public QDialog {
Q_OBJECT

public:
    QmvDBConnectConf(QWidget *parent = 0);
    ~QmvDBConnectConf();

private:
    QSettings *settings;
    Ui::qmvdbconnectClass ui;

private slots:
    void on_testButton_clicked();
    void on_buttonBox_accepted();
};

#endif // QMVDBCONNECT_H
