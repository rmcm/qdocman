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
};

#endif // QMVDOCMAN_H
