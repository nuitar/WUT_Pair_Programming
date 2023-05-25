/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gridmap.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    gridMap *widget;
    QWidget *widgetBtns;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *btnRandom;
    QPushButton *btnStart;
    QPushButton *btnNext;
    QPushButton *btnReset;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(828, 677);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new gridMap(centralwidget);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(800, 520));

        verticalLayout->addWidget(widget);

        widgetBtns = new QWidget(centralwidget);
        widgetBtns->setObjectName("widgetBtns");
        widgetBtns->setMaximumSize(QSize(16777215, 100));
        horizontalLayout = new QHBoxLayout(widgetBtns);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widgetBtns);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        btnRandom = new QPushButton(widgetBtns);
        btnRandom->setObjectName("btnRandom");

        horizontalLayout->addWidget(btnRandom);

        btnStart = new QPushButton(widgetBtns);
        btnStart->setObjectName("btnStart");
        btnStart->setMinimumSize(QSize(150, 50));

        horizontalLayout->addWidget(btnStart);

        btnNext = new QPushButton(widgetBtns);
        btnNext->setObjectName("btnNext");

        horizontalLayout->addWidget(btnNext);

        btnReset = new QPushButton(widgetBtns);
        btnReset->setObjectName("btnReset");

        horizontalLayout->addWidget(btnReset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widgetBtns);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 828, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        btnRandom->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
