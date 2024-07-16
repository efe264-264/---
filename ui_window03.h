/********************************************************************************
** Form generated from reading UI file 'window03.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW03_H
#define UI_WINDOW03_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window03
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QWidget *tab3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_3;
    QWidget *tab8;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_8;
    QWidget *tab7;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_7;
    QWidget *tab6;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableWidget_6;
    QWidget *tab5;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_5;
    QWidget *tab4;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget41;
    QWidget *tab2;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *Window03)
    {
        if (Window03->objectName().isEmpty())
            Window03->setObjectName(QString::fromUtf8("Window03"));
        Window03->resize(800, 600);
        centralwidget = new QWidget(Window03);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_9 = new QVBoxLayout(centralwidget);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        verticalLayout = new QVBoxLayout(tab1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(tab1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab1, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        verticalLayout_2 = new QVBoxLayout(tab3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_3 = new QTableWidget(tab3);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));

        verticalLayout_2->addWidget(tableWidget_3);

        tabWidget->addTab(tab3, QString());
        tab8 = new QWidget();
        tab8->setObjectName(QString::fromUtf8("tab8"));
        verticalLayout_3 = new QVBoxLayout(tab8);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_8 = new QTableWidget(tab8);
        tableWidget_8->setObjectName(QString::fromUtf8("tableWidget_8"));

        verticalLayout_3->addWidget(tableWidget_8);

        tabWidget->addTab(tab8, QString());
        tab7 = new QWidget();
        tab7->setObjectName(QString::fromUtf8("tab7"));
        verticalLayout_8 = new QVBoxLayout(tab7);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableWidget_7 = new QTableWidget(tab7);
        tableWidget_7->setObjectName(QString::fromUtf8("tableWidget_7"));

        verticalLayout_8->addWidget(tableWidget_7);

        tabWidget->addTab(tab7, QString());
        tab6 = new QWidget();
        tab6->setObjectName(QString::fromUtf8("tab6"));
        verticalLayout_7 = new QVBoxLayout(tab6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tableWidget_6 = new QTableWidget(tab6);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));

        verticalLayout_7->addWidget(tableWidget_6);

        tabWidget->addTab(tab6, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QString::fromUtf8("tab5"));
        verticalLayout_6 = new QVBoxLayout(tab5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tableWidget_5 = new QTableWidget(tab5);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));

        verticalLayout_6->addWidget(tableWidget_5);

        tabWidget->addTab(tab5, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QString::fromUtf8("tab4"));
        verticalLayout_5 = new QVBoxLayout(tab4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableWidget41 = new QTableWidget(tab4);
        tableWidget41->setObjectName(QString::fromUtf8("tableWidget41"));

        verticalLayout_5->addWidget(tableWidget41);

        tabWidget->addTab(tab4, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        verticalLayout_4 = new QVBoxLayout(tab2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableWidget_2 = new QTableWidget(tab2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_4->addWidget(tableWidget_2);

        tabWidget->addTab(tab2, QString());

        verticalLayout_9->addWidget(tabWidget);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_9->addWidget(pushButton);

        Window03->setCentralWidget(centralwidget);

        retranslateUi(Window03);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(Window03);
    } // setupUi

    void retranslateUi(QMainWindow *Window03)
    {
        Window03->setWindowTitle(QCoreApplication::translate("Window03", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("Window03", " 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("Window03", "2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab8), QCoreApplication::translate("Window03", "3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab7), QCoreApplication::translate("Window03", "4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab6), QCoreApplication::translate("Window03", "5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab5), QCoreApplication::translate("Window03", "6", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QCoreApplication::translate("Window03", "7", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("Window03", "8", nullptr));
        pushButton->setText(QCoreApplication::translate("Window03", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window03: public Ui_Window03 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW03_H
