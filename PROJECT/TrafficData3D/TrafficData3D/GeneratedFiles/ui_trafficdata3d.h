/********************************************************************************
** Form generated from reading UI file 'trafficdata3d.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFICDATA3D_H
#define UI_TRAFFICDATA3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrafficData3DClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrafficData3DClass)
    {
        if (TrafficData3DClass->objectName().isEmpty())
            TrafficData3DClass->setObjectName(QStringLiteral("TrafficData3DClass"));
        TrafficData3DClass->resize(1109, 864);
        centralWidget = new QWidget(TrafficData3DClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TrafficData3DClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TrafficData3DClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1109, 23));
        TrafficData3DClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrafficData3DClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TrafficData3DClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TrafficData3DClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrafficData3DClass->setStatusBar(statusBar);

        retranslateUi(TrafficData3DClass);

        QMetaObject::connectSlotsByName(TrafficData3DClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrafficData3DClass)
    {
        TrafficData3DClass->setWindowTitle(QApplication::translate("TrafficData3DClass", "TrafficData3D", 0));
    } // retranslateUi

};

namespace Ui {
    class TrafficData3DClass: public Ui_TrafficData3DClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICDATA3D_H
