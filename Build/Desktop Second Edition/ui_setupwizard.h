/********************************************************************************
** Form generated from reading UI file 'setupwizard.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPWIZARD_H
#define UI_SETUPWIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupWizard
{
public:
    QWidget *centralwidget;
    QTabWidget *container;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QPushButton *debug_exit;

    void setupUi(QMainWindow *SetupWizard)
    {
        if (SetupWizard->objectName().isEmpty())
            SetupWizard->setObjectName(QString::fromUtf8("SetupWizard"));
        SetupWizard->resize(800, 600);
        SetupWizard->setStyleSheet(QString::fromUtf8("border-image: url(:/ui/resources/image/frame.png);"));
        centralwidget = new QWidget(SetupWizard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        container = new QTabWidget(centralwidget);
        container->setObjectName(QString::fromUtf8("container"));
        container->setGeometry(QRect(50, 50, 691, 461));
        container->setStyleSheet(QString::fromUtf8("border-image: url(:/ui/resources/image/bg.png);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 361, 41));
        label->setStyleSheet(QString::fromUtf8("font: 87 13pt \"Source Han Serif SC Heavy\";"));
        container->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        container->addTab(tab_2, QString());
        debug_exit = new QPushButton(centralwidget);
        debug_exit->setObjectName(QString::fromUtf8("debug_exit"));
        debug_exit->setGeometry(QRect(528, 40, 221, 24));
        SetupWizard->setCentralWidget(centralwidget);

        retranslateUi(SetupWizard);

        QMetaObject::connectSlotsByName(SetupWizard);
    } // setupUi

    void retranslateUi(QMainWindow *SetupWizard)
    {
        SetupWizard->setWindowTitle(QCoreApplication::translate("SetupWizard", "SetupWizard", nullptr));
        label->setText(QCoreApplication::translate("SetupWizard", "\345\255\227\345\217\267\345\212\240\345\244\247\345\212\240\347\262\227 \346\215\242\350\211\262 \346\200\235\346\272\220\345\256\213\344\275\223 Heavy", nullptr));
        container->setTabText(container->indexOf(tab), QCoreApplication::translate("SetupWizard", "\346\213\277\345\261\236\346\200\247\351\232\220\350\227\217\346\216\211Tab\346\240\217\357\274\201\357\274\201", nullptr));
        container->setTabText(container->indexOf(tab_2), QCoreApplication::translate("SetupWizard", "Tab 2", nullptr));
        debug_exit->setText(QCoreApplication::translate("SetupWizard", "\351\200\200\345\207\272\346\214\211\351\222\256 \346\255\243\345\274\217\345\217\221\345\270\203\346\227\266\345\216\273\346\216\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetupWizard: public Ui_SetupWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPWIZARD_H
