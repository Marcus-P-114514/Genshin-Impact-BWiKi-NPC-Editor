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
#include <QtWidgets/QLineEdit>
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
    QGraphicsView *toolbar_shade;
    QStackedWidget *project_tree;
    QWidget *page_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *project_name;
    QPushButton *npc_location_switcher;
    QPushButton *npc_store_switcher;
    QPushButton *extra_switcher;
    QFrame *tree_holder;
    QPushButton *basic_info_switcher;
    QPushButton *npc_dialog_switcher;
    QPushButton *cv_table_switcher;
    QPushButton *file_switcher;
    QWidget *page_4;
    QStackedWidget *editor_selecter;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *visual_editor_selected;
    QPushButton *code_editor_released;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *conf_panel_one;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *visual_editor_released;
    QPushButton *code_editor_selected;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *conf_panel_two;
    QStackedWidget *working_area;
    QWidget *page_5;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QWidget *page_6;
    QLabel *label_2;
    QLabel *label_10;
    QLineEdit *npcname_input;
    QLabel *label_11;
    QLineEdit *nickname_input;
    QLabel *label_12;
    QPushButton *npc_gender_option_unknown;
    QPushButton *npc_gender_male;
    QPushButton *npc_gender_female;
    QWidget *page_7;
    QLabel *label_3;
    QWidget *page_8;
    QLabel *label_4;
    QWidget *page_9;
    QLabel *label_5;
    QWidget *page_10;
    QLabel *label_6;
    QWidget *page_11;
    QLabel *label_7;
    QWidget *page_12;
    QLabel *label_8;
    QWidget *page_13;
    QLabel *label_9;
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

        npc_location_switcher = new QPushButton(layoutWidget);
        npc_location_switcher->setObjectName(QString::fromUtf8("npc_location_switcher"));
        npc_location_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(npc_location_switcher, 5, 1, 1, 1);

        npc_store_switcher = new QPushButton(layoutWidget);
        npc_store_switcher->setObjectName(QString::fromUtf8("npc_store_switcher"));
        npc_store_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(npc_store_switcher, 2, 1, 1, 1);

        extra_switcher = new QPushButton(layoutWidget);
        extra_switcher->setObjectName(QString::fromUtf8("extra_switcher"));
        extra_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(extra_switcher, 6, 1, 1, 1);

        tree_holder = new QFrame(layoutWidget);
        tree_holder->setObjectName(QString::fromUtf8("tree_holder"));
        tree_holder->setFrameShape(QFrame::VLine);
        tree_holder->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(tree_holder, 1, 0, 6, 1);

        basic_info_switcher = new QPushButton(layoutWidget);
        basic_info_switcher->setObjectName(QString::fromUtf8("basic_info_switcher"));
        basic_info_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(basic_info_switcher, 1, 1, 1, 1);

        npc_dialog_switcher = new QPushButton(layoutWidget);
        npc_dialog_switcher->setObjectName(QString::fromUtf8("npc_dialog_switcher"));
        npc_dialog_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(npc_dialog_switcher, 3, 1, 1, 1);

        cv_table_switcher = new QPushButton(layoutWidget);
        cv_table_switcher->setObjectName(QString::fromUtf8("cv_table_switcher"));
        cv_table_switcher->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(cv_table_switcher, 4, 1, 1, 1);

        file_switcher = new QPushButton(layoutWidget);
        file_switcher->setObjectName(QString::fromUtf8("file_switcher"));

        gridLayout_2->addWidget(file_switcher, 7, 1, 1, 1);

        project_tree->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        project_tree->addWidget(page_4);

        gridLayout->addWidget(project_tree, 1, 0, 1, 1);

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
        visual_editor_selected->setStyleSheet(QString::fromUtf8(""));
        visual_editor_selected->setFlat(true);

        horizontalLayout_3->addWidget(visual_editor_selected);

        code_editor_released = new QPushButton(page);
        code_editor_released->setObjectName(QString::fromUtf8("code_editor_released"));
        code_editor_released->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(code_editor_released);

        horizontalSpacer_3 = new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        conf_panel_one = new QPushButton(page);
        conf_panel_one->setObjectName(QString::fromUtf8("conf_panel_one"));
        conf_panel_one->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(conf_panel_one);


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
        visual_editor_released->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(visual_editor_released);

        code_editor_selected = new QPushButton(page_2);
        code_editor_selected->setObjectName(QString::fromUtf8("code_editor_selected"));
        code_editor_selected->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(code_editor_selected);

        horizontalSpacer_4 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        conf_panel_two = new QPushButton(page_2);
        conf_panel_two->setObjectName(QString::fromUtf8("conf_panel_two"));
        conf_panel_two->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(conf_panel_two);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        editor_selecter->addWidget(page_2);

        gridLayout->addWidget(editor_selecter, 2, 2, 1, 1);

        working_area = new QStackedWidget(centralwidget);
        working_area->setObjectName(QString::fromUtf8("working_area"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_3 = new QGridLayout(page_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(page_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 18pt ;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        working_area->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        label_2 = new QLabel(page_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 591, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        label_10 = new QLabel(page_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 50, 31, 21));
        npcname_input = new QLineEdit(page_6);
        npcname_input->setObjectName(QString::fromUtf8("npcname_input"));
        npcname_input->setGeometry(QRect(50, 50, 181, 21));
        label_11 = new QLabel(page_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 80, 31, 21));
        nickname_input = new QLineEdit(page_6);
        nickname_input->setObjectName(QString::fromUtf8("nickname_input"));
        nickname_input->setGeometry(QRect(50, 80, 181, 21));
        nickname_input->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(page_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 110, 31, 31));
        npc_gender_option_unknown = new QPushButton(page_6);
        npc_gender_option_unknown->setObjectName(QString::fromUtf8("npc_gender_option_unknown"));
        npc_gender_option_unknown->setGeometry(QRect(50, 110, 61, 32));
        npc_gender_male = new QPushButton(page_6);
        npc_gender_male->setObjectName(QString::fromUtf8("npc_gender_male"));
        npc_gender_male->setGeometry(QRect(120, 110, 61, 32));
        npc_gender_female = new QPushButton(page_6);
        npc_gender_female->setObjectName(QString::fromUtf8("npc_gender_female"));
        npc_gender_female->setGeometry(QRect(190, 110, 61, 32));
        working_area->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        label_3 = new QLabel(page_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 591, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        label_4 = new QLabel(page_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 591, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        label_5 = new QLabel(page_9);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 591, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        label_6 = new QLabel(page_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 591, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        label_7 = new QLabel(page_11);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 591, 21));
        label_7->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        label_8 = new QLabel(page_12);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 591, 21));
        label_8->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        label_9 = new QLabel(page_13);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 591, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 18pt;"));
        working_area->addWidget(page_13);

        gridLayout->addWidget(working_area, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuqqq = new QMenu(menuBar);
        menuqqq->setObjectName(QString::fromUtf8("menuqqq"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuqqq->menuAction());
        menuqqq->addAction(actionccc_2);

        retranslateUi(MainWindow);

        project_tree->setCurrentIndex(0);
        editor_selecter->setCurrentIndex(0);
        working_area->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\216\237\347\245\236 BWIKI NPC\345\233\276\351\211\264\347\254\254\344\270\211\346\226\271\347\274\226\350\276\221\345\231\250 REL 1.4.5 B", nullptr));
        actionccc->setText(QCoreApplication::translate("MainWindow", "ccc", nullptr));
        actionccc_2->setText(QCoreApplication::translate("MainWindow", "ccc", nullptr));
        project_name->setText(QCoreApplication::translate("MainWindow", "\346\234\252\345\221\275\345\220\215", nullptr));
        npc_location_switcher->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256", nullptr));
        npc_store_switcher->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\272\227", nullptr));
        extra_switcher->setText(QCoreApplication::translate("MainWindow", "\346\235\202\351\241\271", nullptr));
        basic_info_switcher->setText(QCoreApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        npc_dialog_switcher->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235", nullptr));
        cv_table_switcher->setText(QCoreApplication::translate("MainWindow", "CV\350\241\250", nullptr));
        file_switcher->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\344\270\212\344\274\240", nullptr));
        visual_editor_selected->setText(QCoreApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226\347\274\226\350\276\221", nullptr));
        code_editor_released->setText(QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201", nullptr));
        conf_panel_one->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        visual_editor_released->setText(QCoreApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226\347\274\226\350\276\221", nullptr));
        code_editor_selected->setText(QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201", nullptr));
        conf_panel_two->setText(QCoreApplication::translate("MainWindow", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\257\267\346\211\223\345\274\200\344\270\200\344\270\252NPCEDIT\346\226\207\344\273\266\n"
"\346\210\226\350\200\205\350\257\267\344\275\277\347\224\250\344\276\247\350\276\271\345\267\245\345\205\267\346\240\217\350\267\263\350\275\254\345\210\260\346\202\250\351\234\200\350\246\201\347\274\226\350\276\221\347\232\204\351\203\250\345\210\206", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        npcname_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\270\272NPC\345\244\264\351\241\266\347\232\204\347\231\275\350\211\262\351\203\250\345\210\206", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\247\260\345\217\267", nullptr));
        nickname_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "<>\344\270\255\351\227\264\347\232\204\345\206\205\345\256\271\357\274\214\346\262\241\346\234\211\350\257\267\347\225\231\347\251\272", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253", nullptr));
        npc_gender_option_unknown->setText(QCoreApplication::translate("MainWindow", "\346\234\252\347\237\245", nullptr));
        npc_gender_male->setText(QCoreApplication::translate("MainWindow", "\347\224\267", nullptr));
        npc_gender_female->setText(QCoreApplication::translate("MainWindow", "\345\245\263", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\272\227", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "CV\350\241\250", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\235\202\351\241\271", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\344\270\212\344\274\240", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\344\270\212\344\274\240", nullptr));
        menuqqq->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
