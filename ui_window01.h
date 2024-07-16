/********************************************************************************
** Form generated from reading UI file 'window01.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW01_H
#define UI_WINDOW01_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window01
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;

    void setupUi(QMainWindow *Window01)
    {
        if (Window01->objectName().isEmpty())
            Window01->setObjectName(QString::fromUtf8("Window01"));
        Window01->resize(800, 600);
        centralwidget = new QWidget(Window01);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        if (tableWidget->rowCount() < 40)
            tableWidget->setRowCount(40);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

        verticalLayout->addWidget(pushButton1);

        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));

        verticalLayout->addWidget(pushButton2);

        pushButton3 = new QPushButton(centralwidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));

        verticalLayout->addWidget(pushButton3);

        pushButton4 = new QPushButton(centralwidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));

        verticalLayout->addWidget(pushButton4);

        Window01->setCentralWidget(centralwidget);

        retranslateUi(Window01);

        QMetaObject::connectSlotsByName(Window01);
    } // setupUi

    void retranslateUi(QMainWindow *Window01)
    {
        Window01->setWindowTitle(QCoreApplication::translate("Window01", "Window01", nullptr));
        pushButton1->setText(QCoreApplication::translate("Window01", "\351\200\211\346\213\2511", nullptr));
        pushButton2->setText(QCoreApplication::translate("Window01", "\351\200\211\346\213\2512", nullptr));
        pushButton3->setText(QCoreApplication::translate("Window01", "\351\200\211\346\213\2513", nullptr));
        pushButton4->setText(QCoreApplication::translate("Window01", "\351\200\211\346\213\2514", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window01: public Ui_Window01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW01_H
