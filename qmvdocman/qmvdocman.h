#ifndef QMVDOCMAN_H
#define QMVDOCMAN_H

#include <QtGui/QMainWindow>
#include "ui_qmvdocman.h"

class qmvdocman : public QMainWindow
{
    Q_OBJECT

public:
    qmvdocman(QWidget *parent = 0);
    ~qmvdocman();

private:
    Ui::qmvdocmanClass ui;
    
private slots:
    void on_actionPrint_activated();
    void on_actionFax_activated();
    void on_actionEmail_activated();
    void on_actionPreferences_activated();
};

#endif // QMVDOCMAN_H
