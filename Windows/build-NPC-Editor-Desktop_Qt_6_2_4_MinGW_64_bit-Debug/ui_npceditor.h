/********************************************************************************
** Form generated from reading UI file 'npceditor.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NPCEDITOR_H
#define UI_NPCEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NPCEditor
{
public:
    QAction *open_code;
    QAction *save_code;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *code_preview;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;

    void setupUi(QMainWindow *NPCEditor)
    {
        if (NPCEditor->objectName().isEmpty())
            NPCEditor->setObjectName(QString::fromUtf8("NPCEditor"));
        NPCEditor->resize(800, 600);
        NPCEditor->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        open_code = new QAction(NPCEditor);
        open_code->setObjectName(QString::fromUtf8("open_code"));
        save_code = new QAction(NPCEditor);
        save_code->setObjectName(QString::fromUtf8("save_code"));
        centralwidget = new QWidget(NPCEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        code_preview = new QTextEdit(centralwidget);
        code_preview->setObjectName(QString::fromUtf8("code_preview"));

        gridLayout->addWidget(code_preview, 0, 0, 1, 1);

        NPCEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NPCEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        NPCEditor->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menu->addAction(open_code);
        menu->addAction(save_code);

        retranslateUi(NPCEditor);

        QMetaObject::connectSlotsByName(NPCEditor);
    } // setupUi

    void retranslateUi(QMainWindow *NPCEditor)
    {
        NPCEditor->setWindowTitle(QCoreApplication::translate("NPCEditor", "NPCEditor", nullptr));
        open_code->setText(QCoreApplication::translate("NPCEditor", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        open_code->setToolTip(QCoreApplication::translate("NPCEditor", "\346\211\223\345\274\200\347\211\271\345\256\232\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        open_code->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save_code->setText(QCoreApplication::translate("NPCEditor", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        save_code->setToolTip(QCoreApplication::translate("NPCEditor", "\344\277\235\345\255\230\345\275\223\345\211\215\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        save_code->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("NPCEditor", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("NPCEditor", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240", nullptr));
        menu_4->setTitle(QCoreApplication::translate("NPCEditor", "\346\211\223\347\202\271", nullptr));
        menu_5->setTitle(QCoreApplication::translate("NPCEditor", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NPCEditor: public Ui_NPCEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NPCEDITOR_H
