/********************************************************************************
** Form generated from reading ui file 'qmvdocman.ui'
**
** Created: Mon Mar 3 11:06:38 2008
**      by: Qt User Interface Compiler version 4.3.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QMVDOCMAN_H
#define UI_QMVDOCMAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_qmvdocmanClass
{
public:
    QAction *actionFax;
    QAction *actionEmail;
    QAction *actionAbout_QDocMan;
    QAction *actionPrint;
    QAction *actionQuit;
    QAction *actionWhatsThis;
    QAction *actionPreferences;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *twBatchTree;
    QWidget *tabPatients;
    QVBoxLayout *vboxLayout;
    QComboBox *cbPatientSearch;
    QLabel *labelPatientSearch;
    QTreeView *treePatientView;
    QWidget *tabBatches;
    QVBoxLayout *vboxLayout1;
    QComboBox *cbBatchSearch;
    QLabel *labelBatchSearch;
    QTreeView *treeBatchView;
    QTabWidget *tabViewBatches;
    QWidget *allTab;
    QGridLayout *gridLayout1;
    QTreeView *treeAllDocumentsView;
    QWidget *tabText;
    QGridLayout *gridLayout2;
    QTreeView *treeTextDocumentsView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *qmvdocmanClass)
    {
    if (qmvdocmanClass->objectName().isEmpty())
        qmvdocmanClass->setObjectName(QString::fromUtf8("qmvdocmanClass"));
    qmvdocmanClass->resize(800, 600);
    actionFax = new QAction(qmvdocmanClass);
    actionFax->setObjectName(QString::fromUtf8("actionFax"));
    actionEmail = new QAction(qmvdocmanClass);
    actionEmail->setObjectName(QString::fromUtf8("actionEmail"));
    actionEmail->setShortcutContext(Qt::WindowShortcut);
    actionAbout_QDocMan = new QAction(qmvdocmanClass);
    actionAbout_QDocMan->setObjectName(QString::fromUtf8("actionAbout_QDocMan"));
    actionPrint = new QAction(qmvdocmanClass);
    actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
    actionQuit = new QAction(qmvdocmanClass);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionWhatsThis = new QAction(qmvdocmanClass);
    actionWhatsThis->setObjectName(QString::fromUtf8("actionWhatsThis"));
    actionPreferences = new QAction(qmvdocmanClass);
    actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
    centralwidget = new QWidget(qmvdocmanClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    twBatchTree = new QTabWidget(centralwidget);
    twBatchTree->setObjectName(QString::fromUtf8("twBatchTree"));
    twBatchTree->setTabPosition(QTabWidget::North);
    twBatchTree->setElideMode(Qt::ElideNone);
    tabPatients = new QWidget();
    tabPatients->setObjectName(QString::fromUtf8("tabPatients"));
    vboxLayout = new QVBoxLayout(tabPatients);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    cbPatientSearch = new QComboBox(tabPatients);
    cbPatientSearch->setObjectName(QString::fromUtf8("cbPatientSearch"));
    cbPatientSearch->setEditable(true);

    vboxLayout->addWidget(cbPatientSearch);

    labelPatientSearch = new QLabel(tabPatients);
    labelPatientSearch->setObjectName(QString::fromUtf8("labelPatientSearch"));

    vboxLayout->addWidget(labelPatientSearch);

    treePatientView = new QTreeView(tabPatients);
    treePatientView->setObjectName(QString::fromUtf8("treePatientView"));

    vboxLayout->addWidget(treePatientView);

    twBatchTree->addTab(tabPatients, QString());
    tabBatches = new QWidget();
    tabBatches->setObjectName(QString::fromUtf8("tabBatches"));
    vboxLayout1 = new QVBoxLayout(tabBatches);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    cbBatchSearch = new QComboBox(tabBatches);
    cbBatchSearch->setObjectName(QString::fromUtf8("cbBatchSearch"));
    cbBatchSearch->setEditable(true);
    cbBatchSearch->setMaxVisibleItems(14);

    vboxLayout1->addWidget(cbBatchSearch);

    labelBatchSearch = new QLabel(tabBatches);
    labelBatchSearch->setObjectName(QString::fromUtf8("labelBatchSearch"));

    vboxLayout1->addWidget(labelBatchSearch);

    treeBatchView = new QTreeView(tabBatches);
    treeBatchView->setObjectName(QString::fromUtf8("treeBatchView"));

    vboxLayout1->addWidget(treeBatchView);

    twBatchTree->addTab(tabBatches, QString());

    gridLayout->addWidget(twBatchTree, 0, 0, 1, 1);

    tabViewBatches = new QTabWidget(centralwidget);
    tabViewBatches->setObjectName(QString::fromUtf8("tabViewBatches"));
    allTab = new QWidget();
    allTab->setObjectName(QString::fromUtf8("allTab"));
    gridLayout1 = new QGridLayout(allTab);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    treeAllDocumentsView = new QTreeView(allTab);
    treeAllDocumentsView->setObjectName(QString::fromUtf8("treeAllDocumentsView"));

    gridLayout1->addWidget(treeAllDocumentsView, 0, 0, 1, 1);

    tabViewBatches->addTab(allTab, QString());
    tabText = new QWidget();
    tabText->setObjectName(QString::fromUtf8("tabText"));
    gridLayout2 = new QGridLayout(tabText);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    treeTextDocumentsView = new QTreeView(tabText);
    treeTextDocumentsView->setObjectName(QString::fromUtf8("treeTextDocumentsView"));

    gridLayout2->addWidget(treeTextDocumentsView, 0, 0, 1, 1);

    tabViewBatches->addTab(tabText, QString());

    gridLayout->addWidget(tabViewBatches, 0, 1, 1, 1);

    qmvdocmanClass->setCentralWidget(centralwidget);
    menubar = new QMenuBar(qmvdocmanClass);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 27));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    qmvdocmanClass->setMenuBar(menubar);
    statusbar = new QStatusBar(qmvdocmanClass);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    qmvdocmanClass->setStatusBar(statusbar);
    toolBar = new QToolBar(qmvdocmanClass);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    qmvdocmanClass->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuFile->addSeparator();
    menuFile->addSeparator();
    menuFile->addAction(actionPrint);
    menuFile->addAction(actionFax);
    menuFile->addAction(actionEmail);
    menuFile->addSeparator();
    menuFile->addAction(actionPreferences);
    menuFile->addAction(actionQuit);
    menuHelp->addAction(actionAbout_QDocMan);
    menuHelp->addAction(actionWhatsThis);
    toolBar->addAction(actionPrint);
    toolBar->addAction(actionFax);
    toolBar->addAction(actionEmail);
    toolBar->addSeparator();
    toolBar->addAction(actionWhatsThis);

    retranslateUi(qmvdocmanClass);
    QObject::connect(actionQuit, SIGNAL(activated()), qmvdocmanClass, SLOT(close()));

    twBatchTree->setCurrentIndex(1);
    tabViewBatches->setCurrentIndex(1);


    QMetaObject::connectSlotsByName(qmvdocmanClass);
    } // setupUi

    void retranslateUi(QMainWindow *qmvdocmanClass)
    {
    qmvdocmanClass->setWindowTitle(QApplication::translate("qmvdocmanClass", "QDocMan - Document Management", 0, QApplication::UnicodeUTF8));
    actionFax->setText(QApplication::translate("qmvdocmanClass", "&Fax", 0, QApplication::UnicodeUTF8));
    actionFax->setToolTip(QApplication::translate("qmvdocmanClass", "Fax the selected documents", 0, QApplication::UnicodeUTF8));
    actionFax->setStatusTip(QApplication::translate("qmvdocmanClass", "Fax the selected documents", 0, QApplication::UnicodeUTF8));
    actionFax->setWhatsThis(QApplication::translate("qmvdocmanClass", "Fax the selected documents", 0, QApplication::UnicodeUTF8));
    actionFax->setShortcut(QApplication::translate("qmvdocmanClass", "Alt+F", 0, QApplication::UnicodeUTF8));
    actionEmail->setText(QApplication::translate("qmvdocmanClass", "&Email", 0, QApplication::UnicodeUTF8));
    actionEmail->setToolTip(QApplication::translate("qmvdocmanClass", "Email the selected documents", 0, QApplication::UnicodeUTF8));
    actionEmail->setStatusTip(QApplication::translate("qmvdocmanClass", "Email the selected documents", 0, QApplication::UnicodeUTF8));
    actionEmail->setWhatsThis(QApplication::translate("qmvdocmanClass", "Email the selected documents", 0, QApplication::UnicodeUTF8));
    actionEmail->setShortcut(QApplication::translate("qmvdocmanClass", "Alt+E", 0, QApplication::UnicodeUTF8));
    actionAbout_QDocMan->setText(QApplication::translate("qmvdocmanClass", "&About QDocMan", 0, QApplication::UnicodeUTF8));
    actionPrint->setText(QApplication::translate("qmvdocmanClass", "&Print", 0, QApplication::UnicodeUTF8));
    actionPrint->setToolTip(QApplication::translate("qmvdocmanClass", "Print the selected documents", 0, QApplication::UnicodeUTF8));
    actionPrint->setStatusTip(QApplication::translate("qmvdocmanClass", "Print the selected documents", 0, QApplication::UnicodeUTF8));
    actionPrint->setWhatsThis(QApplication::translate("qmvdocmanClass", "Print the selected documents", 0, QApplication::UnicodeUTF8));
    actionPrint->setShortcut(QApplication::translate("qmvdocmanClass", "Alt+P", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("qmvdocmanClass", "&Quit", 0, QApplication::UnicodeUTF8));
    actionQuit->setToolTip(QApplication::translate("qmvdocmanClass", "Quit from QDocMan", 0, QApplication::UnicodeUTF8));
    actionQuit->setStatusTip(QApplication::translate("qmvdocmanClass", "Quit from QDocMan", 0, QApplication::UnicodeUTF8));
    actionQuit->setWhatsThis(QApplication::translate("qmvdocmanClass", "Quit from QDocMan", 0, QApplication::UnicodeUTF8));
    actionQuit->setShortcut(QApplication::translate("qmvdocmanClass", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
    actionWhatsThis->setText(QApplication::translate("qmvdocmanClass", "&Whats This?", 0, QApplication::UnicodeUTF8));
    actionWhatsThis->setShortcut(QApplication::translate("qmvdocmanClass", "F1", 0, QApplication::UnicodeUTF8));
    actionPreferences->setText(QApplication::translate("qmvdocmanClass", "Preferences", 0, QApplication::UnicodeUTF8));
    labelPatientSearch->setText(QApplication::translate("qmvdocmanClass", "Enter Surname,Firstname,DOB", 0, QApplication::UnicodeUTF8));
    twBatchTree->setTabText(twBatchTree->indexOf(tabPatients), QApplication::translate("qmvdocmanClass", "Patients", 0, QApplication::UnicodeUTF8));
    twBatchTree->setTabToolTip(twBatchTree->indexOf(tabPatients), QApplication::translate("qmvdocmanClass", "Documents grouped by patients", 0, QApplication::UnicodeUTF8));
    labelBatchSearch->setText(QApplication::translate("qmvdocmanClass", "Enter a batch label", 0, QApplication::UnicodeUTF8));
    twBatchTree->setTabText(twBatchTree->indexOf(tabBatches), QApplication::translate("qmvdocmanClass", "Document Batches", 0, QApplication::UnicodeUTF8));
    twBatchTree->setTabToolTip(twBatchTree->indexOf(tabBatches), QApplication::translate("qmvdocmanClass", "View Document Batches", 0, QApplication::UnicodeUTF8));
    tabViewBatches->setTabText(tabViewBatches->indexOf(allTab), QApplication::translate("qmvdocmanClass", "All Documents", 0, QApplication::UnicodeUTF8));
    tabViewBatches->setTabText(tabViewBatches->indexOf(tabText), QApplication::translate("qmvdocmanClass", "Text Documents", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("qmvdocmanClass", "File", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("qmvdocmanClass", "Help", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("qmvdocmanClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qmvdocmanClass: public Ui_qmvdocmanClass {};
} // namespace Ui

#endif // UI_QMVDOCMAN_H
