/********************************************************************************
** Form generated from reading ui file 'qmvdbconnectconf.ui'
**
** Created: Fri Feb 29 17:50:04 2008
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QMVDBCONNECTCONF_H
#define UI_QMVDBCONNECTCONF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

class Ui_qmvdbconnectClass
{
public:
    QGridLayout *gridLayout;
    QLabel *panelLabel;
    QLabel *hostLabel;
    QLineEdit *hostEdit;
    QLabel *databaseLabel;
    QLineEdit *databaseEdit;
    QLabel *userLabel;
    QLineEdit *userEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QPushButton *testButton;
    QLabel *connectLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *qmvdbconnectClass)
    {
    if (qmvdbconnectClass->objectName().isEmpty())
        qmvdbconnectClass->setObjectName(QString::fromUtf8("qmvdbconnectClass"));
    qmvdbconnectClass->setWindowModality(Qt::ApplicationModal);
    qmvdbconnectClass->resize(288, 237);
    qmvdbconnectClass->setMinimumSize(QSize(288, 237));
    qmvdbconnectClass->setMaximumSize(QSize(288, 237));
    gridLayout = new QGridLayout(qmvdbconnectClass);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    panelLabel = new QLabel(qmvdbconnectClass);
    panelLabel->setObjectName(QString::fromUtf8("panelLabel"));
    QFont font;
    font.setFamily(QString::fromUtf8("Sans Serif"));
    font.setPointSize(12);
    font.setBold(true);
    font.setWeight(75);
    panelLabel->setFont(font);
    panelLabel->setTextFormat(Qt::RichText);
    panelLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(panelLabel, 0, 0, 1, 2);

    hostLabel = new QLabel(qmvdbconnectClass);
    hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

    gridLayout->addWidget(hostLabel, 1, 0, 1, 1);

    hostEdit = new QLineEdit(qmvdbconnectClass);
    hostEdit->setObjectName(QString::fromUtf8("hostEdit"));

    gridLayout->addWidget(hostEdit, 1, 1, 1, 1);

    databaseLabel = new QLabel(qmvdbconnectClass);
    databaseLabel->setObjectName(QString::fromUtf8("databaseLabel"));

    gridLayout->addWidget(databaseLabel, 2, 0, 1, 1);

    databaseEdit = new QLineEdit(qmvdbconnectClass);
    databaseEdit->setObjectName(QString::fromUtf8("databaseEdit"));

    gridLayout->addWidget(databaseEdit, 2, 1, 1, 1);

    userLabel = new QLabel(qmvdbconnectClass);
    userLabel->setObjectName(QString::fromUtf8("userLabel"));

    gridLayout->addWidget(userLabel, 3, 0, 1, 1);

    userEdit = new QLineEdit(qmvdbconnectClass);
    userEdit->setObjectName(QString::fromUtf8("userEdit"));

    gridLayout->addWidget(userEdit, 3, 1, 1, 1);

    passwordLabel = new QLabel(qmvdbconnectClass);
    passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

    gridLayout->addWidget(passwordLabel, 4, 0, 1, 1);

    passwordEdit = new QLineEdit(qmvdbconnectClass);
    passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
    passwordEdit->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(passwordEdit, 4, 1, 1, 1);

    testButton = new QPushButton(qmvdbconnectClass);
    testButton->setObjectName(QString::fromUtf8("testButton"));

    gridLayout->addWidget(testButton, 5, 0, 1, 1);

    connectLabel = new QLabel(qmvdbconnectClass);
    connectLabel->setObjectName(QString::fromUtf8("connectLabel"));
    connectLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(connectLabel, 5, 1, 1, 1);

    buttonBox = new QDialogButtonBox(qmvdbconnectClass);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 6, 0, 1, 2);


    retranslateUi(qmvdbconnectClass);
    QObject::connect(buttonBox, SIGNAL(rejected()), qmvdbconnectClass, SLOT(reject()));

    QMetaObject::connectSlotsByName(qmvdbconnectClass);
    } // setupUi

    void retranslateUi(QDialog *qmvdbconnectClass)
    {
    qmvdbconnectClass->setWindowTitle(QApplication::translate("qmvdbconnectClass", "Dialog", 0, QApplication::UnicodeUTF8));
    panelLabel->setText(QApplication::translate("qmvdbconnectClass", "Configure Database Connection", 0, QApplication::UnicodeUTF8));
    hostLabel->setToolTip(QApplication::translate("qmvdbconnectClass", "Database Hostname", 0, QApplication::UnicodeUTF8));
    hostLabel->setStatusTip(QApplication::translate("qmvdbconnectClass", "Database Hostname", 0, QApplication::UnicodeUTF8));
    hostLabel->setWhatsThis(QApplication::translate("qmvdbconnectClass", "The Hostname or IP address of the database host", 0, QApplication::UnicodeUTF8));
    hostLabel->setText(QApplication::translate("qmvdbconnectClass", "Host", 0, QApplication::UnicodeUTF8));
    databaseLabel->setToolTip(QApplication::translate("qmvdbconnectClass", "Database Name", 0, QApplication::UnicodeUTF8));
    databaseLabel->setStatusTip(QApplication::translate("qmvdbconnectClass", "Database Name", 0, QApplication::UnicodeUTF8));
    databaseLabel->setWhatsThis(QApplication::translate("qmvdbconnectClass", "The name of the database", 0, QApplication::UnicodeUTF8));
    databaseLabel->setText(QApplication::translate("qmvdbconnectClass", "Database", 0, QApplication::UnicodeUTF8));
    userLabel->setToolTip(QApplication::translate("qmvdbconnectClass", "User Name", 0, QApplication::UnicodeUTF8));
    userLabel->setStatusTip(QApplication::translate("qmvdbconnectClass", "User Name", 0, QApplication::UnicodeUTF8));
    userLabel->setWhatsThis(QApplication::translate("qmvdbconnectClass", "The Hostname or IP address of the database host", 0, QApplication::UnicodeUTF8));
    userLabel->setText(QApplication::translate("qmvdbconnectClass", "User", 0, QApplication::UnicodeUTF8));
    passwordLabel->setToolTip(QApplication::translate("qmvdbconnectClass", "User Password", 0, QApplication::UnicodeUTF8));
    passwordLabel->setStatusTip(QApplication::translate("qmvdbconnectClass", "User Password", 0, QApplication::UnicodeUTF8));
    passwordLabel->setWhatsThis(QApplication::translate("qmvdbconnectClass", "The Hostname or IP address of the database host", 0, QApplication::UnicodeUTF8));
    passwordLabel->setText(QApplication::translate("qmvdbconnectClass", "Password", 0, QApplication::UnicodeUTF8));
    testButton->setWhatsThis(QApplication::translate("qmvdbconnectClass", "Test the connection to the database", 0, QApplication::UnicodeUTF8));
    testButton->setText(QApplication::translate("qmvdbconnectClass", "Test", 0, QApplication::UnicodeUTF8));
    connectLabel->setToolTip(QApplication::translate("qmvdbconnectClass", "Connection Status", 0, QApplication::UnicodeUTF8));
    connectLabel->setStatusTip(QApplication::translate("qmvdbconnectClass", "Connection Status", 0, QApplication::UnicodeUTF8));
    connectLabel->setWhatsThis(QApplication::translate("qmvdbconnectClass", "Status of database connection", 0, QApplication::UnicodeUTF8));
    connectLabel->setText(QApplication::translate("qmvdbconnectClass", "Not Connected", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(qmvdbconnectClass);
    } // retranslateUi

};

namespace Ui {
    class qmvdbconnectClass: public Ui_qmvdbconnectClass {};
} // namespace Ui

#endif // UI_QMVDBCONNECTCONF_H
