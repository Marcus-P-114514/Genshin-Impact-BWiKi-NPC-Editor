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
#include <QtWidgets/QVBoxLayout>
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
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QGridLayout *gridLayout_6;
    QLabel *label_10;
    QLineEdit *npcname_input;
    QLabel *label_11;
    QLineEdit *nickname_input;
    QGridLayout *gridLayout_8;
    QLabel *label_12;
    QPushButton *npc_gender_option_unknown;
    QPushButton *npc_gender_male;
    QPushButton *npc_gender_female;
    QGridLayout *gridLayout_7;
    QLabel *label_13;
    QLineEdit *job_input;
    QLabel *label_14;
    QLineEdit *location_input;
    QGridLayout *gridLayout_9;
    QLabel *label_15;
    QPushButton *npc_country_option_unknown;
    QPushButton *npc_country_option_mondstadt;
    QPushButton *npc_country_option_liyue;
    QPushButton *npc_country_option_inazuman;
    QPushButton *npc_country_option_sumeru;
    QPushButton *npc_country_option_fortaine;
    QPushButton *npc_country_option_nata;
    QPushButton *npc_country_option_snezhnayan;
    QGridLayout *gridLayout_10;
    QLabel *label_16;
    QLineEdit *organization_input;
    QGridLayout *gridLayout_11;
    QLabel *label_17;
    QPushButton *npc_system_option_none;
    QPushButton *npc_system_option_commission;
    QPushButton *npc_system_option_frame;
    QPushButton *npc_system_option_activity;
    QPushButton *npc_system_option_store;
    QPushButton *npc_system_option_cook;
    QPushButton *npc_system_option_serenitea_pot;
    QGridLayout *gridLayout_12;
    QLabel *label_18;
    QPushButton *npc_gift_option_none;
    QPushButton *npc_gift_option_exist;
    QPushButton *multiple_gift_edit;
    QLineEdit *gift_single_edit_name;
    QLineEdit *gift_single_edit_amount;
    QGridLayout *gridLayout_13;
    QLabel *label_19;
    QLineEdit *version_input;
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
        MainWindow->resize(809, 600);
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
        verticalLayout = new QVBoxLayout(page_6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(page_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt;"));

        verticalLayout->addWidget(label_2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_10 = new QLabel(page_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 0, 0, 1, 1);

        npcname_input = new QLineEdit(page_6);
        npcname_input->setObjectName(QString::fromUtf8("npcname_input"));

        gridLayout_6->addWidget(npcname_input, 0, 1, 1, 1);

        label_11 = new QLabel(page_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 1, 0, 1, 1);

        nickname_input = new QLineEdit(page_6);
        nickname_input->setObjectName(QString::fromUtf8("nickname_input"));
        nickname_input->setStyleSheet(QString::fromUtf8(""));

        gridLayout_6->addWidget(nickname_input, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_12 = new QLabel(page_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_8->addWidget(label_12, 0, 0, 1, 1);

        npc_gender_option_unknown = new QPushButton(page_6);
        npc_gender_option_unknown->setObjectName(QString::fromUtf8("npc_gender_option_unknown"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(npc_gender_option_unknown->sizePolicy().hasHeightForWidth());
        npc_gender_option_unknown->setSizePolicy(sizePolicy3);
        npc_gender_option_unknown->setMinimumSize(QSize(50, 30));
        npc_gender_option_unknown->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(npc_gender_option_unknown, 0, 1, 1, 1);

        npc_gender_male = new QPushButton(page_6);
        npc_gender_male->setObjectName(QString::fromUtf8("npc_gender_male"));
        sizePolicy3.setHeightForWidth(npc_gender_male->sizePolicy().hasHeightForWidth());
        npc_gender_male->setSizePolicy(sizePolicy3);
        npc_gender_male->setMinimumSize(QSize(50, 30));
        npc_gender_male->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(npc_gender_male, 0, 2, 1, 1);

        npc_gender_female = new QPushButton(page_6);
        npc_gender_female->setObjectName(QString::fromUtf8("npc_gender_female"));
        sizePolicy3.setHeightForWidth(npc_gender_female->sizePolicy().hasHeightForWidth());
        npc_gender_female->setSizePolicy(sizePolicy3);
        npc_gender_female->setMinimumSize(QSize(50, 30));
        npc_gender_female->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(npc_gender_female, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_8);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_13 = new QLabel(page_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_7->addWidget(label_13, 0, 0, 1, 1);

        job_input = new QLineEdit(page_6);
        job_input->setObjectName(QString::fromUtf8("job_input"));
        job_input->setStyleSheet(QString::fromUtf8(""));

        gridLayout_7->addWidget(job_input, 0, 1, 1, 1);

        label_14 = new QLabel(page_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_7->addWidget(label_14, 1, 0, 1, 1);

        location_input = new QLineEdit(page_6);
        location_input->setObjectName(QString::fromUtf8("location_input"));
        location_input->setStyleSheet(QString::fromUtf8(""));

        gridLayout_7->addWidget(location_input, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_7);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_15 = new QLabel(page_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_9->addWidget(label_15, 0, 0, 1, 1);

        npc_country_option_unknown = new QPushButton(page_6);
        npc_country_option_unknown->setObjectName(QString::fromUtf8("npc_country_option_unknown"));
        sizePolicy3.setHeightForWidth(npc_country_option_unknown->sizePolicy().hasHeightForWidth());
        npc_country_option_unknown->setSizePolicy(sizePolicy3);
        npc_country_option_unknown->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_unknown, 0, 1, 1, 1);

        npc_country_option_mondstadt = new QPushButton(page_6);
        npc_country_option_mondstadt->setObjectName(QString::fromUtf8("npc_country_option_mondstadt"));
        sizePolicy3.setHeightForWidth(npc_country_option_mondstadt->sizePolicy().hasHeightForWidth());
        npc_country_option_mondstadt->setSizePolicy(sizePolicy3);
        npc_country_option_mondstadt->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_mondstadt, 0, 2, 1, 1);

        npc_country_option_liyue = new QPushButton(page_6);
        npc_country_option_liyue->setObjectName(QString::fromUtf8("npc_country_option_liyue"));
        sizePolicy3.setHeightForWidth(npc_country_option_liyue->sizePolicy().hasHeightForWidth());
        npc_country_option_liyue->setSizePolicy(sizePolicy3);
        npc_country_option_liyue->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_liyue, 0, 3, 1, 1);

        npc_country_option_inazuman = new QPushButton(page_6);
        npc_country_option_inazuman->setObjectName(QString::fromUtf8("npc_country_option_inazuman"));
        sizePolicy3.setHeightForWidth(npc_country_option_inazuman->sizePolicy().hasHeightForWidth());
        npc_country_option_inazuman->setSizePolicy(sizePolicy3);
        npc_country_option_inazuman->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_inazuman, 0, 4, 1, 1);

        npc_country_option_sumeru = new QPushButton(page_6);
        npc_country_option_sumeru->setObjectName(QString::fromUtf8("npc_country_option_sumeru"));
        sizePolicy3.setHeightForWidth(npc_country_option_sumeru->sizePolicy().hasHeightForWidth());
        npc_country_option_sumeru->setSizePolicy(sizePolicy3);
        npc_country_option_sumeru->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_sumeru, 0, 5, 1, 1);

        npc_country_option_fortaine = new QPushButton(page_6);
        npc_country_option_fortaine->setObjectName(QString::fromUtf8("npc_country_option_fortaine"));
        sizePolicy3.setHeightForWidth(npc_country_option_fortaine->sizePolicy().hasHeightForWidth());
        npc_country_option_fortaine->setSizePolicy(sizePolicy3);
        npc_country_option_fortaine->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_fortaine, 0, 6, 1, 1);

        npc_country_option_nata = new QPushButton(page_6);
        npc_country_option_nata->setObjectName(QString::fromUtf8("npc_country_option_nata"));
        sizePolicy3.setHeightForWidth(npc_country_option_nata->sizePolicy().hasHeightForWidth());
        npc_country_option_nata->setSizePolicy(sizePolicy3);
        npc_country_option_nata->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_nata, 0, 7, 1, 1);

        npc_country_option_snezhnayan = new QPushButton(page_6);
        npc_country_option_snezhnayan->setObjectName(QString::fromUtf8("npc_country_option_snezhnayan"));
        sizePolicy3.setHeightForWidth(npc_country_option_snezhnayan->sizePolicy().hasHeightForWidth());
        npc_country_option_snezhnayan->setSizePolicy(sizePolicy3);
        npc_country_option_snezhnayan->setMinimumSize(QSize(50, 30));

        gridLayout_9->addWidget(npc_country_option_snezhnayan, 0, 8, 1, 1);


        verticalLayout->addLayout(gridLayout_9);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_16 = new QLabel(page_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_10->addWidget(label_16, 0, 0, 1, 1);

        organization_input = new QLineEdit(page_6);
        organization_input->setObjectName(QString::fromUtf8("organization_input"));
        organization_input->setStyleSheet(QString::fromUtf8(""));

        gridLayout_10->addWidget(organization_input, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_10);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_17 = new QLabel(page_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_11->addWidget(label_17, 0, 0, 1, 1);

        npc_system_option_none = new QPushButton(page_6);
        npc_system_option_none->setObjectName(QString::fromUtf8("npc_system_option_none"));
        sizePolicy3.setHeightForWidth(npc_system_option_none->sizePolicy().hasHeightForWidth());
        npc_system_option_none->setSizePolicy(sizePolicy3);
        npc_system_option_none->setMinimumSize(QSize(50, 30));

        gridLayout_11->addWidget(npc_system_option_none, 0, 1, 1, 1);

        npc_system_option_commission = new QPushButton(page_6);
        npc_system_option_commission->setObjectName(QString::fromUtf8("npc_system_option_commission"));
        sizePolicy3.setHeightForWidth(npc_system_option_commission->sizePolicy().hasHeightForWidth());
        npc_system_option_commission->setSizePolicy(sizePolicy3);
        npc_system_option_commission->setMinimumSize(QSize(50, 30));

        gridLayout_11->addWidget(npc_system_option_commission, 0, 2, 1, 1);

        npc_system_option_frame = new QPushButton(page_6);
        npc_system_option_frame->setObjectName(QString::fromUtf8("npc_system_option_frame"));
        sizePolicy3.setHeightForWidth(npc_system_option_frame->sizePolicy().hasHeightForWidth());
        npc_system_option_frame->setSizePolicy(sizePolicy3);
        npc_system_option_frame->setMinimumSize(QSize(50, 30));

        gridLayout_11->addWidget(npc_system_option_frame, 0, 3, 1, 1);

        npc_system_option_activity = new QPushButton(page_6);
        npc_system_option_activity->setObjectName(QString::fromUtf8("npc_system_option_activity"));
        sizePolicy3.setHeightForWidth(npc_system_option_activity->sizePolicy().hasHeightForWidth());
        npc_system_option_activity->setSizePolicy(sizePolicy3);
        npc_system_option_activity->setMinimumSize(QSize(50, 30));

        gridLayout_11->addWidget(npc_system_option_activity, 0, 4, 1, 1);

        npc_system_option_store = new QPushButton(page_6);
        npc_system_option_store->setObjectName(QString::fromUtf8("npc_system_option_store"));
        sizePolicy3.setHeightForWidth(npc_system_option_store->sizePolicy().hasHeightForWidth());
        npc_system_option_store->setSizePolicy(sizePolicy3);
        npc_system_option_store->setMinimumSize(QSize(50, 30));

        gridLayout_11->addWidget(npc_system_option_store, 0, 5, 1, 1);

        npc_system_option_cook = new QPushButton(page_6);
        npc_system_option_cook->setObjectName(QString::fromUtf8("npc_system_option_cook"));
        sizePolicy3.setHeightForWidth(npc_system_option_cook->sizePolicy().hasHeightForWidth());
        npc_system_option_cook->setSizePolicy(sizePolicy3);
        npc_system_option_cook->setMinimumSize(QSize(50, 30));

        gridLayout_11->addWidget(npc_system_option_cook, 0, 6, 1, 1);

        npc_system_option_serenitea_pot = new QPushButton(page_6);
        npc_system_option_serenitea_pot->setObjectName(QString::fromUtf8("npc_system_option_serenitea_pot"));
        sizePolicy3.setHeightForWidth(npc_system_option_serenitea_pot->sizePolicy().hasHeightForWidth());
        npc_system_option_serenitea_pot->setSizePolicy(sizePolicy3);

        gridLayout_11->addWidget(npc_system_option_serenitea_pot, 0, 7, 1, 1);


        verticalLayout->addLayout(gridLayout_11);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_18 = new QLabel(page_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_12->addWidget(label_18, 0, 0, 1, 1);

        npc_gift_option_none = new QPushButton(page_6);
        npc_gift_option_none->setObjectName(QString::fromUtf8("npc_gift_option_none"));
        sizePolicy3.setHeightForWidth(npc_gift_option_none->sizePolicy().hasHeightForWidth());
        npc_gift_option_none->setSizePolicy(sizePolicy3);
        npc_gift_option_none->setMinimumSize(QSize(50, 30));

        gridLayout_12->addWidget(npc_gift_option_none, 0, 1, 2, 1);

        npc_gift_option_exist = new QPushButton(page_6);
        npc_gift_option_exist->setObjectName(QString::fromUtf8("npc_gift_option_exist"));
        sizePolicy3.setHeightForWidth(npc_gift_option_exist->sizePolicy().hasHeightForWidth());
        npc_gift_option_exist->setSizePolicy(sizePolicy3);
        npc_gift_option_exist->setMinimumSize(QSize(50, 30));

        gridLayout_12->addWidget(npc_gift_option_exist, 0, 2, 2, 2);

        multiple_gift_edit = new QPushButton(page_6);
        multiple_gift_edit->setObjectName(QString::fromUtf8("multiple_gift_edit"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(30);
        sizePolicy4.setHeightForWidth(multiple_gift_edit->sizePolicy().hasHeightForWidth());
        multiple_gift_edit->setSizePolicy(sizePolicy4);

        gridLayout_12->addWidget(multiple_gift_edit, 1, 4, 2, 1);

        gift_single_edit_name = new QLineEdit(page_6);
        gift_single_edit_name->setObjectName(QString::fromUtf8("gift_single_edit_name"));
        gift_single_edit_name->setStyleSheet(QString::fromUtf8(""));

        gridLayout_12->addWidget(gift_single_edit_name, 2, 1, 1, 2);

        gift_single_edit_amount = new QLineEdit(page_6);
        gift_single_edit_amount->setObjectName(QString::fromUtf8("gift_single_edit_amount"));
        gift_single_edit_amount->setStyleSheet(QString::fromUtf8(""));

        gridLayout_12->addWidget(gift_single_edit_amount, 2, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_12);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_19 = new QLabel(page_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_13->addWidget(label_19, 0, 0, 1, 1);

        version_input = new QLineEdit(page_6);
        version_input->setObjectName(QString::fromUtf8("version_input"));
        version_input->setStyleSheet(QString::fromUtf8(""));

        gridLayout_13->addWidget(version_input, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_13);

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
        menuBar->setGeometry(QRect(0, 0, 809, 22));
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
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260\357\274\232", nullptr));
        npcname_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\270\272NPC\345\244\264\351\241\266\347\232\204\347\231\275\350\211\262\351\203\250\345\210\206", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\347\247\260\345\217\267\357\274\232", nullptr));
        nickname_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "<>\344\270\255\351\227\264\347\232\204\345\206\205\345\256\271\357\274\214\346\262\241\346\234\211\350\257\267\347\225\231\347\251\272", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        npc_gender_option_unknown->setText(QCoreApplication::translate("MainWindow", "\346\234\252\347\237\245", nullptr));
        npc_gender_male->setText(QCoreApplication::translate("MainWindow", "\347\224\267", nullptr));
        npc_gender_female->setText(QCoreApplication::translate("MainWindow", "\345\245\263", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\201\214\344\270\232\357\274\232", nullptr));
        job_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\224\256\345\215\226\344\270\234\350\245\277\347\232\204\344\275\277\347\224\250\342\200\234\345\225\206\344\272\272\342\200\235\346\217\217\350\277\260\350\201\214\344\270\232\343\200\202\345\201\232\350\217\234\347\232\204\344\275\277\347\224\250\342\200\234\345\216\250\345\270\210\342\200\235\346\217\217\350\277\260\350\201\214\344\270\232", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        location_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\241\253\345\206\231NPC\346\211\200\345\234\250\347\232\204\345\234\260\347\220\206\344\275\215\347\275\256\357\274\214\344\275\277\347\224\250\345\234\260\345\220\215\357\274\214\345\234\260\345\220\215\344\271\213\351\227\264\344\275\277\347\224\250\342\200\234\302\267\342\200\235\350\277\236\346\216\245\357\274\214\345\260\275\351\207\217\344\270\215\347\224\250\346\226\271\344\275\215\350\257\215", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\346\211\200\345\261\236\345\233\275\345\256\266\357\274\232", nullptr));
        npc_country_option_unknown->setText(QCoreApplication::translate("MainWindow", "\346\234\252\347\237\245", nullptr));
        npc_country_option_mondstadt->setText(QCoreApplication::translate("MainWindow", "\350\222\231\345\276\267", nullptr));
        npc_country_option_liyue->setText(QCoreApplication::translate("MainWindow", "\347\222\203\346\234\210", nullptr));
        npc_country_option_inazuman->setText(QCoreApplication::translate("MainWindow", "\347\250\273\345\246\273", nullptr));
        npc_country_option_sumeru->setText(QCoreApplication::translate("MainWindow", "\351\241\273\345\274\245", nullptr));
        npc_country_option_fortaine->setText(QCoreApplication::translate("MainWindow", "\346\236\253\344\270\271", nullptr));
        npc_country_option_nata->setText(QCoreApplication::translate("MainWindow", "\347\272\263\345\241\224", nullptr));
        npc_country_option_snezhnayan->setText(QCoreApplication::translate("MainWindow", "\350\207\263\345\206\254", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\346\211\200\345\261\236\347\273\204\347\273\207\357\274\232", nullptr));
        organization_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\346\240\271\346\215\256\346\270\270\346\210\217\345\206\205\345\257\271\350\257\235\344\270\216\345\220\204\347\247\215\350\265\204\346\226\231\345\241\253\345\206\231\357\274\214\344\271\237\345\217\257\345\241\253\345\206\231\345\267\245\344\275\234\345\215\225\344\275\215", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\205\263\347\263\273\347\273\237\357\274\232", nullptr));
        npc_system_option_none->setText(QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        npc_system_option_commission->setText(QCoreApplication::translate("MainWindow", "\345\247\224\346\211\230", nullptr));
        npc_system_option_frame->setText(QCoreApplication::translate("MainWindow", "\345\243\260\346\234\233", nullptr));
        npc_system_option_activity->setText(QCoreApplication::translate("MainWindow", "\346\264\273\345\212\250", nullptr));
        npc_system_option_store->setText(QCoreApplication::translate("MainWindow", "\345\225\206\345\272\227", nullptr));
        npc_system_option_cook->setText(QCoreApplication::translate("MainWindow", "\347\203\271\351\245\252", nullptr));
        npc_system_option_serenitea_pot->setText(QCoreApplication::translate("MainWindow", "\345\260\230\346\255\214\345\243\266", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\345\257\271\350\257\235\350\265\240\347\244\274\357\274\232", nullptr));
        npc_gift_option_none->setText(QCoreApplication::translate("MainWindow", "\344\270\215\345\255\230\345\234\250", nullptr));
        npc_gift_option_exist->setText(QCoreApplication::translate("MainWindow", "\345\255\230\345\234\250", nullptr));
        multiple_gift_edit->setText(QCoreApplication::translate("MainWindow", "NPC\346\234\211\345\244\232\347\247\215\350\265\240\347\244\274", nullptr));
        gift_single_edit_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\265\240\347\244\274\345\206\205\345\256\271", nullptr));
        gift_single_edit_amount->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\265\240\347\244\274\346\225\260\351\207\217", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\256\236\350\243\205\347\211\210\346\234\254\357\274\232", nullptr));
        version_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\241\253\345\206\231\344\270\216NPC\347\232\204\345\256\236\350\243\205\347\211\210\346\234\254", nullptr));
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
