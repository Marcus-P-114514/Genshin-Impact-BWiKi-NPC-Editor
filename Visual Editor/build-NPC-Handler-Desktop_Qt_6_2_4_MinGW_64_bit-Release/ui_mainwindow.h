/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionccc;
    QAction *actionccc_2;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QStackedWidget *project_tree;
    QWidget *page_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *project_name;
    QFrame *tree_holder;
    QPushButton *basic_info_switcher;
    QPushButton *npc_store_switcher;
    QPushButton *npc_dialog_switcher;
    QPushButton *cv_table_switcher;
    QPushButton *npc_location_switcher;
    QPushButton *extra_switcher;
    QWidget *page_4;
    QStackedWidget *working_area;
    QWidget *page_5;
    QGridLayout *gridLayout_3;
    QLabel *welcome;
    QWidget *page_6;
    QGraphicsView *toolbar_shade;
    QStackedWidget *editor_selecter;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *visual_editor_selected;
    QPushButton *code_editor_released;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_9;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *visual_editor_released;
    QPushButton *code_editor_selected;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_12;
    QMenuBar *menuBar;
    QMenu *menuqqq;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionccc = new QAction(MainWindow);
        actionccc->setObjectName(QString::fromUtf8("actionccc"));
        actionccc_2 = new QAction(MainWindow);
        actionccc_2->setObjectName(QString::fromUtf8("actionccc_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        project_tree = new QStackedWidget(centralwidget);
        project_tree->setObjectName(QString::fromUtf8("project_tree"));
        project_tree->setMaximumSize(QSize(125, 16777215));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        layoutWidget = new QWidget(page_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 111, 316));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        project_name = new QPushButton(layoutWidget);
        project_name->setObjectName(QString::fromUtf8("project_name"));
        project_name->setStyleSheet(QString::fromUtf8(""));
        project_name->setFlat(true);

        gridLayout_2->addWidget(project_name, 0, 0, 1, 2);

        tree_holder = new QFrame(layoutWidget);
        tree_holder->setObjectName(QString::fromUtf8("tree_holder"));
        tree_holder->setFrameShape(QFrame::VLine);
        tree_holder->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(tree_holder, 1, 0, 6, 1);

        basic_info_switcher = new QPushButton(layoutWidget);
        basic_info_switcher->setObjectName(QString::fromUtf8("basic_info_switcher"));
        basic_info_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(basic_info_switcher, 1, 1, 1, 1);

        npc_store_switcher = new QPushButton(layoutWidget);
        npc_store_switcher->setObjectName(QString::fromUtf8("npc_store_switcher"));
        npc_store_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(npc_store_switcher, 2, 1, 1, 1);

        npc_dialog_switcher = new QPushButton(layoutWidget);
        npc_dialog_switcher->setObjectName(QString::fromUtf8("npc_dialog_switcher"));
        npc_dialog_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(npc_dialog_switcher, 3, 1, 1, 1);

        cv_table_switcher = new QPushButton(layoutWidget);
        cv_table_switcher->setObjectName(QString::fromUtf8("cv_table_switcher"));
        cv_table_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(cv_table_switcher, 4, 1, 1, 1);

        npc_location_switcher = new QPushButton(layoutWidget);
        npc_location_switcher->setObjectName(QString::fromUtf8("npc_location_switcher"));
        npc_location_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(npc_location_switcher, 5, 1, 1, 1);

        extra_switcher = new QPushButton(layoutWidget);
        extra_switcher->setObjectName(QString::fromUtf8("extra_switcher"));
        extra_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(extra_switcher, 6, 1, 1, 1);

        project_tree->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        project_tree->addWidget(page_4);

        gridLayout->addWidget(project_tree, 1, 0, 1, 1);

        working_area = new QStackedWidget(centralwidget);
        working_area->setObjectName(QString::fromUtf8("working_area"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_3 = new QGridLayout(page_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        welcome = new QLabel(page_5);
        welcome->setObjectName(QString::fromUtf8("welcome"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(14);
        welcome->setFont(font);
        welcome->setAlignment(Qt::AlignCenter);
        welcome->setWordWrap(true);

        gridLayout_3->addWidget(welcome, 1, 0, 1, 1);

        working_area->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        working_area->addWidget(page_6);

        gridLayout->addWidget(working_area, 1, 2, 1, 1);

        toolbar_shade = new QGraphicsView(centralwidget);
        toolbar_shade->setObjectName(QString::fromUtf8("toolbar_shade"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(15);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolbar_shade->sizePolicy().hasHeightForWidth());
        toolbar_shade->setSizePolicy(sizePolicy1);
        toolbar_shade->setMaximumSize(QSize(45, 16777215));
        toolbar_shade->setAutoFillBackground(true);
        toolbar_shade->setStyleSheet(QString::fromUtf8(""));
        toolbar_shade->setLineWidth(0);
        toolbar_shade->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);

        gridLayout->addWidget(toolbar_shade, 1, 1, 2, 1);

        editor_selecter = new QStackedWidget(centralwidget);
        editor_selecter->setObjectName(QString::fromUtf8("editor_selecter"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editor_selecter->sizePolicy().hasHeightForWidth());
        editor_selecter->setSizePolicy(sizePolicy2);
        editor_selecter->setMaximumSize(QSize(16777215, 75));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_5 = new QGridLayout(page);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        visual_editor_selected = new QPushButton(page);
        visual_editor_selected->setObjectName(QString::fromUtf8("visual_editor_selected"));
        visual_editor_selected->setStyleSheet(QString::fromUtf8("padding: 7px;\n"
"border-radius: 5px;\n"
"background-color: rgb(231, 191, 159);\n"
"color: rgb(246, 240, 229);\n"
"border: 6px;"));
        visual_editor_selected->setFlat(true);

        horizontalLayout_3->addWidget(visual_editor_selected);

        code_editor_released = new QPushButton(page);
        code_editor_released->setObjectName(QString::fromUtf8("code_editor_released"));
        code_editor_released->setStyleSheet(QString::fromUtf8("padding: 7px;\n"
"border-radius: 5px;\n"
"background-color: rgb(246, 240, 229);\n"
"color: rgb(231, 191, 159);\n"
"border: 6px;\n"
""));

        horizontalLayout_3->addWidget(code_editor_released);

        horizontalSpacer_3 = new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_9 = new QPushButton(page);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setStyleSheet(QString::fromUtf8("padding: 7px;\n"
"border-radius: 5px;\n"
"background-color: rgb(246, 240, 229);\n"
"color: rgb(231, 191, 159);\n"
"border: 6px;\n"
""));

        horizontalLayout_3->addWidget(pushButton_9);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        editor_selecter->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_5 = new QHBoxLayout(page_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        visual_editor_released = new QPushButton(page_2);
        visual_editor_released->setObjectName(QString::fromUtf8("visual_editor_released"));
        visual_editor_released->setStyleSheet(QString::fromUtf8("padding: 7px;\n"
"border-radius: 5px;\n"
"background-color: rgb(246, 240, 229);\n"
"color: rgb(231, 191, 159);\n"
"border: 6px;\n"
""));

        horizontalLayout_4->addWidget(visual_editor_released);

        code_editor_selected = new QPushButton(page_2);
        code_editor_selected->setObjectName(QString::fromUtf8("code_editor_selected"));
        code_editor_selected->setStyleSheet(QString::fromUtf8("padding: 7px;\n"
"border-radius: 5px;\n"
"background-color: rgb(231, 191, 159);\n"
"color: rgb(246, 240, 229);\n"
"border: 6px;"));

        horizontalLayout_4->addWidget(code_editor_selected);

        horizontalSpacer_4 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pushButton_12 = new QPushButton(page_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setStyleSheet(QString::fromUtf8("padding: 7px;\n"
"border-radius: 5px;\n"
"background-color: rgb(246, 240, 229);\n"
"color: rgb(231, 191, 159);\n"
"border: 6px;\n"
""));

        horizontalLayout_4->addWidget(pushButton_12);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        editor_selecter->addWidget(page_2);

        gridLayout->addWidget(editor_selecter, 2, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        menuqqq = new QMenu(menuBar);
        menuqqq->setObjectName(QString::fromUtf8("menuqqq"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuqqq->menuAction());
        menuqqq->addAction(actionccc_2);

        retranslateUi(MainWindow);

        project_tree->setCurrentIndex(0);
        working_area->setCurrentIndex(1);
        editor_selecter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\216\237\347\245\236 BWIKI NPC\345\233\276\351\211\264\347\254\254\344\270\211\346\226\271\347\274\226\350\276\221\345\231\250 REL 1.4.5 B", nullptr));
        actionccc->setText(QCoreApplication::translate("MainWindow", "ccc", nullptr));
        actionccc_2->setText(QCoreApplication::translate("MainWindow", "ccc", nullptr));
        project_name->setText(QCoreApplication::translate("MainWindow", "\346\234\252\345\221\275\345\220\215", nullptr));
        basic_info_switcher->setText(QCoreApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        npc_store_switcher->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\272\227", nullptr));
        npc_dialog_switcher->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235", nullptr));
        cv_table_switcher->setText(QCoreApplication::translate("MainWindow", "CV", nullptr));
        npc_location_switcher->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256", nullptr));
        extra_switcher->setText(QCoreApplication::translate("MainWindow", "\346\235\202\351\241\271", nullptr));
        welcome->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\347\274\226\350\276\221\347\232\204\351\203\250\345\210\206\343\200\202\n"
"\346\210\226\350\200\205\346\202\250\345\217\257\344\273\245\345\234\250\343\200\220\346\211\223\345\274\200\343\200\221\351\200\211\351\241\271\345\215\241\344\270\255\346\211\223\345\274\200\347\216\260\345\255\230\346\226\207\344\273\266\343\200\202", nullptr));
        visual_editor_selected->setText(QCoreApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226\347\274\226\350\276\221", nullptr));
        code_editor_released->setText(QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        visual_editor_released->setText(QCoreApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226\347\274\226\350\276\221", nullptr));
        code_editor_selected->setText(QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        menuqqq->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
