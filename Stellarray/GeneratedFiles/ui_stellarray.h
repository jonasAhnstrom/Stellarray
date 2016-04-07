/********************************************************************************
** Form generated from reading UI file 'stellarray.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STELLARRAY_H
#define UI_STELLARRAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StellarrayClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_newGame;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StellarrayClass)
    {
        if (StellarrayClass->objectName().isEmpty())
            StellarrayClass->setObjectName(QStringLiteral("StellarrayClass"));
        StellarrayClass->resize(944, 573);
        centralWidget = new QWidget(StellarrayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_newGame = new QPushButton(centralWidget);
        pushButton_newGame->setObjectName(QStringLiteral("pushButton_newGame"));
        pushButton_newGame->setGeometry(QRect(360, 200, 191, 51));
        StellarrayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StellarrayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 944, 21));
        StellarrayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StellarrayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StellarrayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StellarrayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StellarrayClass->setStatusBar(statusBar);

        retranslateUi(StellarrayClass);

        QMetaObject::connectSlotsByName(StellarrayClass);
    } // setupUi

    void retranslateUi(QMainWindow *StellarrayClass)
    {
        StellarrayClass->setWindowTitle(QApplication::translate("StellarrayClass", "Stellarray", 0));
        pushButton_newGame->setText(QApplication::translate("StellarrayClass", "New game", 0));
    } // retranslateUi

};

namespace Ui {
    class StellarrayClass: public Ui_StellarrayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STELLARRAY_H
