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
    QAction *save_code_as;
    QAction *insert_template;
    QAction *clear_all;
    QAction *upload_avatar;
    QAction *upload_model;
    QAction *upload_location;
    QAction *open_map;
    QAction *about_this_application;
    QAction *about_qt;
    QAction *upload_log;
    QAction *check_update;
    QAction *open_license;
    QAction *assign_npc_name;
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
        save_code_as = new QAction(NPCEditor);
        save_code_as->setObjectName(QString::fromUtf8("save_code_as"));
        insert_template = new QAction(NPCEditor);
        insert_template->setObjectName(QString::fromUtf8("insert_template"));
        clear_all = new QAction(NPCEditor);
        clear_all->setObjectName(QString::fromUtf8("clear_all"));
        upload_avatar = new QAction(NPCEditor);
        upload_avatar->setObjectName(QString::fromUtf8("upload_avatar"));
        upload_model = new QAction(NPCEditor);
        upload_model->setObjectName(QString::fromUtf8("upload_model"));
        upload_location = new QAction(NPCEditor);
        upload_location->setObjectName(QString::fromUtf8("upload_location"));
        open_map = new QAction(NPCEditor);
        open_map->setObjectName(QString::fromUtf8("open_map"));
        about_this_application = new QAction(NPCEditor);
        about_this_application->setObjectName(QString::fromUtf8("about_this_application"));
        about_qt = new QAction(NPCEditor);
        about_qt->setObjectName(QString::fromUtf8("about_qt"));
        upload_log = new QAction(NPCEditor);
        upload_log->setObjectName(QString::fromUtf8("upload_log"));
        check_update = new QAction(NPCEditor);
        check_update->setObjectName(QString::fromUtf8("check_update"));
        open_license = new QAction(NPCEditor);
        open_license->setObjectName(QString::fromUtf8("open_license"));
        assign_npc_name = new QAction(NPCEditor);
        assign_npc_name->setObjectName(QString::fromUtf8("assign_npc_name"));
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
        menu->addAction(save_code_as);
        menu_2->addAction(insert_template);
        menu_2->addAction(clear_all);
        menu_3->addAction(assign_npc_name);
        menu_3->addSeparator();
        menu_3->addAction(upload_avatar);
        menu_3->addAction(upload_model);
        menu_3->addAction(upload_location);
        menu_4->addAction(open_map);
        menu_5->addAction(about_this_application);
        menu_5->addAction(about_qt);
        menu_5->addSeparator();
        menu_5->addAction(upload_log);
        menu_5->addAction(check_update);
        menu_5->addSeparator();
        menu_5->addAction(open_license);

        retranslateUi(NPCEditor);

        QMetaObject::connectSlotsByName(NPCEditor);
    } // setupUi

    void retranslateUi(QMainWindow *NPCEditor)
    {
        NPCEditor->setWindowTitle(QCoreApplication::translate("NPCEditor", "\345\216\237\347\245\236BWIKI NPC\345\233\276\351\211\264\347\254\254\344\270\211\346\226\271\347\274\226\350\276\221\345\267\245\345\205\267", nullptr));
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
        save_code_as->setText(QCoreApplication::translate("NPCEditor", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(tooltip)
        save_code_as->setToolTip(QCoreApplication::translate("NPCEditor", "\344\277\235\345\255\230\346\202\250\346\226\207\344\273\266\347\232\204\345\211\257\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        save_code_as->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        insert_template->setText(QCoreApplication::translate("NPCEditor", "\346\217\222\345\205\245\347\211\271\346\256\212\345\255\227\347\254\246", nullptr));
#if QT_CONFIG(tooltip)
        insert_template->setToolTip(QCoreApplication::translate("NPCEditor", "\346\217\222\345\205\245\347\211\271\346\256\212\345\255\227\347\254\246", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        insert_template->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+I", nullptr));
#endif // QT_CONFIG(shortcut)
        clear_all->setText(QCoreApplication::translate("NPCEditor", "\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        clear_all->setToolTip(QCoreApplication::translate("NPCEditor", "\345\275\273\345\272\225\346\270\205\347\251\272\346\225\264\344\273\275\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        clear_all->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        upload_avatar->setText(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240\345\244\264\345\203\217", nullptr));
#if QT_CONFIG(tooltip)
        upload_avatar->setToolTip(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240NPC\345\244\264\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        upload_avatar->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        upload_model->setText(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240\345\273\272\346\250\241", nullptr));
#if QT_CONFIG(tooltip)
        upload_model->setToolTip(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240NPC\345\273\272\346\250\241", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        upload_model->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+M", nullptr));
#endif // QT_CONFIG(shortcut)
        upload_location->setText(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240\344\275\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        upload_location->setToolTip(QCoreApplication::translate("NPCEditor", "\344\270\212\344\274\240NPC\344\275\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        upload_location->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        open_map->setText(QCoreApplication::translate("NPCEditor", "\346\211\223\345\274\200\345\244\247\345\234\260\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        open_map->setToolTip(QCoreApplication::translate("NPCEditor", "\346\211\223\345\274\200\345\244\247\345\234\260\345\233\276\357\274\214\346\202\250\347\250\215\345\220\216\345\217\257\344\273\245\345\210\251\347\224\250\345\244\247\345\234\260\345\233\276\346\211\223\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        open_map->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        about_this_application->setText(QCoreApplication::translate("NPCEditor", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", nullptr));
#if QT_CONFIG(tooltip)
        about_this_application->setToolTip(QCoreApplication::translate("NPCEditor", "\346\234\211\345\205\263\346\234\254\347\250\213\345\272\217\347\232\204\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        about_this_application->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+Alt+I", nullptr));
#endif // QT_CONFIG(shortcut)
        about_qt->setText(QCoreApplication::translate("NPCEditor", "\345\205\263\344\272\216Qt", nullptr));
#if QT_CONFIG(tooltip)
        about_qt->setToolTip(QCoreApplication::translate("NPCEditor", "\345\205\263\344\272\216\347\224\250\344\272\216\346\236\204\345\273\272\346\255\244\347\250\213\345\272\217\347\232\204Qt\347\232\204\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        about_qt->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        upload_log->setText(QCoreApplication::translate("NPCEditor", "\346\233\264\346\226\260\346\227\245\345\277\227", nullptr));
#if QT_CONFIG(tooltip)
        upload_log->setToolTip(QCoreApplication::translate("NPCEditor", "\346\255\244\347\211\210\346\234\254\347\232\204\346\233\264\346\226\260\346\227\245\345\277\227", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        upload_log->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+U", nullptr));
#endif // QT_CONFIG(shortcut)
        check_update->setText(QCoreApplication::translate("NPCEditor", "\346\243\200\346\237\245\346\233\264\346\226\260", nullptr));
#if QT_CONFIG(tooltip)
        check_update->setToolTip(QCoreApplication::translate("NPCEditor", "\346\243\200\346\237\245\346\230\257\345\220\246\346\234\211\346\233\264\346\226\260\357\274\214\351\200\232\345\270\270\345\273\272\350\256\256\344\277\235\346\214\201\346\234\200\346\226\260\347\211\210\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        check_update->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        open_license->setText(QCoreApplication::translate("NPCEditor", "\350\256\270\345\217\257\350\257\201", nullptr));
#if QT_CONFIG(tooltip)
        open_license->setToolTip(QCoreApplication::translate("NPCEditor", "\346\211\223\345\274\200\350\256\270\345\217\257\350\257\201", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        open_license->setShortcut(QCoreApplication::translate("NPCEditor", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        assign_npc_name->setText(QCoreApplication::translate("NPCEditor", "\346\214\207\345\256\232NPC\345\220\215\347\247\260", nullptr));
#if QT_CONFIG(tooltip)
        assign_npc_name->setToolTip(QCoreApplication::translate("NPCEditor", "\346\214\207\345\256\232\345\275\223\345\211\215NPC\347\232\204\345\220\215\347\247\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        assign_npc_name->setShortcut(QCoreApplication::translate("NPCEditor", "Ctrl+N", nullptr));
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
