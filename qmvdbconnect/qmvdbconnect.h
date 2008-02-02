#ifndef QMVDBCONNECT_H
#define QMVDBCONNECT_H

#include <QtGui/QDialog>
#include <QSettings>
#include "ui_qmvdbconnect.h"

class qmvdbconnect : public QDialog
{
    Q_OBJECT

public:
    qmvdbconnect(QWidget *parent = 0);
    ~qmvdbconnect();

private:
	QSettings *settings;
    Ui::qmvdbconnectClass ui;
    
private slots:
	void on_testButton_clicked();
	void on_buttonBox_accepted();
};

#endif // QMVDBCONNECT_H
