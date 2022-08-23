#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QGraphicsDropShadowEffect"
#include "QSettings"
#include "QColor"

//预定义字段 - 仅供读取主题
QString primary_current = "";
QString background_current = "";
QString toolbar_current;
QString text_color_current = "";
QString primary_current_16 = "";
QString toolbar_shade_current = "";
QString ui_stylesheet_general = "";
QString ui_btn_default = "";
QString ui_btn_frameless = "";
QString ui_btn_suggested = "";
QString ui_sidebar_selected = "";
QString ui_sidebar_released = "";
QString ui_lineedit = "";
QString ui_combobox = "";
QString ui_radio_selected = "";
QString ui_radio_released = "";

//预定义字段 - 仅供生成代码
QString npc_gender = "未知";
QString npc_name;
QString npc_nickname;
QString npc_job;
QString npc_location;
QString npc_country = "未知";
QString npc_organization = "未知";
QString npc_system = "[[无]]";

//预定义字段 - 用于程序运行
int current_section = 0;
QString window_title_default = "原神 BWIKI NPC图鉴第三方编辑器 REL 2.0.1";

void config_theme_for_this_application(){
    //预设的主题
    //浅色
    QString primary_light = "#E7BF9F";
    QString background_light = "#F6F0E5";
    QString text_color_selected_light = "#FFFFFF";
    QString theme_pref = "";
    QString toolbar_light="rgb(46,47,48)";

    //深色

    //黑色

    //读取主题
    QSettings *config_theme = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    QString theme_pref_read = config_theme -> value ( "theme/type").toString();
    theme_pref_read = theme_pref;
    delete config_theme;

    //应用预设
    if (theme_pref == "light"){
        primary_current = primary_light;
        background_current = background_light;
        text_color_current = text_color_selected_light;
        toolbar_current = toolbar_light;
        toolbar_shade_current = "border-image: url(:/ui/resources/images/toolbar_with_backgrounds_light_version_one.png);";
    }
    else if (theme_pref == "dark"){

    }
    else if (theme_pref == "black"){

    }
    else{
        primary_current = primary_light;
        background_current = background_light;
        text_color_current = text_color_selected_light;
        toolbar_current = toolbar_light;
        toolbar_shade_current = "border-image: url(:/ui/resources/images/toolbar_with_backgrounds_light_version_one.png);";
    }

    //生成样式表
    //primary_current_16 = converRGB16HexStr(primary_current);
    //ui_stylesheet_general = "QMenu::item:selected{background-color:" + background_current  + ";color:" + primary_current + ";}QMenu::item{background-color:" + primary_current + ";color:" + text_color_current + ";}QMenu::item:disabled{background-color:" + primary_current + ";color: #ddd" + "}QMenu{background-color:" +  primary_current + ";}" + "QWidget{background-color:" +  background_current + "; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color:" + primary_current + " ;}" + "QMenuBar{background-color:" + primary_current + "; color: " + text_color_current +";}";
    ui_stylesheet_general = "QMenu::item:selected{background-color:" + background_current  + ";color:" + primary_current + ";}QMenu::item{background-color:" + primary_current + ";color:" + text_color_current + ";}QMenu::item:disabled{background-color:" + primary_current + ";color: #ddd" + "}QMenu{background-color:" +  toolbar_current + "; color: " + primary_current + ";}" + "QWidget{background-color:" +  background_current + "; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color:" + primary_current + " ;}" + "QMenuBar{background-color:" + toolbar_current + "; color: " + primary_current +";}";
    ui_btn_frameless = "QPushButton{border-radius: 5px; background-color: " + background_current + "; color:" + primary_current + ";border: 6px;}";
    ui_btn_suggested = "QPushButton{border-radius: 5px; background-color: " + primary_current + "; color:" + text_color_current + ";border: 6px;}";
    ui_radio_selected = ui_btn_suggested;
    ui_radio_released = ui_btn_frameless;
    ui_sidebar_selected = "QPushButton{text-align : left;padding: 7px;}" + ui_btn_suggested;
    ui_sidebar_released = "QPushButton{text-align : left;padding: 7px;}" + ui_btn_frameless;
    ui_lineedit = "padding: 3px; border: 2px solid " + primary_current + "; border-radius: 5px;";
    ui_combobox = "QComboBox::down-arrow{border: 2px solid "+ primary_current + "; border-radius: 5px; background-color: "+ primary_current + "; color:" + text_color_current + "; min-width: 10px;} QComboBox{border-radius: 5px; background-color: "+ primary_current + "; color:" + text_color_current + ";}";


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化界面
    //this->setStyleSheet("QMenu::item:selected{background-color:#E7BF9F;color:#FFFFFF;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd}QMenu{border-bottom-color: rgb(44, 44, 44); border-bottom: 2px; border-style: solid; background-color: #FFFFF}QWidget{background: #F6F0E5; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color: #E7BF9F;}");
    config_theme_for_this_application();
    this->setStyleSheet(ui_stylesheet_general);
    ui->toolbar_shade->setStyleSheet(toolbar_shade_current);
    ui->project_name->setStyleSheet(ui_sidebar_selected);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);
    ui->visual_editor_selected->setStyleSheet(ui_sidebar_selected);
    ui->visual_editor_released->setStyleSheet(ui_sidebar_released);
    ui->code_editor_released->setStyleSheet(ui_sidebar_released);
    ui->code_editor_selected->setStyleSheet(ui_sidebar_selected);
    ui->conf_panel_one->setStyleSheet(ui_sidebar_released);
    ui->conf_panel_two->setStyleSheet(ui_sidebar_released);
    ui->npcname_input->setStyleSheet(ui_lineedit);
    ui->nickname_input->setStyleSheet(ui_lineedit);
    ui->npc_gender_option_unknown->setStyleSheet(ui_radio_selected);
    ui->npc_gender_male->setStyleSheet(ui_radio_released);
    ui->npc_gender_female->setStyleSheet(ui_radio_released);
    ui->job_input->setStyleSheet(ui_lineedit);
    ui->location_input->setStyleSheet(ui_lineedit);
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);
    ui->organization_input->setStyleSheet(ui_lineedit);
    ui->npc_system_option_none->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);

    ui->editor_selecter->setCurrentIndex(0);
    ui->tree_holder->setVisible(0);
    ui->gift_single_edit_name->setVisible(0);
    ui->gift_single_edit_amount->setVisible(0);
    ui->multiple_gift_edit->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_code_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(1);
}


void MainWindow::on_visual_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(0);
}

void MainWindow::on_basic_info_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_selected);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(1);

    //页面记录
    current_section = 1;
}


void MainWindow::on_project_name_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_selected);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(0);

    //页面记录
    current_section = 0;
}


void MainWindow::on_npc_store_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_selected);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(2);

    //页面记录
    current_section = 2;
}


void MainWindow::on_npc_dialog_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_selected);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(3);

    //页面记录
    current_section = 3;
}


void MainWindow::on_cv_table_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_selected);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(4);

    //页面记录
    current_section = 4;
}


void MainWindow::on_npc_location_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_selected);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(5);

    //页面记录
    current_section = 5;
}


void MainWindow::on_extra_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_selected);
    ui->file_switcher->setStyleSheet(ui_sidebar_released);

    //页面跳转
    ui->working_area->setCurrentIndex(6);

    //页面记录
    current_section = 6;
}


void MainWindow::on_file_switcher_clicked()
{
    //应用样式表
    ui->project_name->setStyleSheet(ui_sidebar_released);
    ui->basic_info_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_store_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_dialog_switcher->setStyleSheet(ui_sidebar_released);
    ui->cv_table_switcher->setStyleSheet(ui_sidebar_released);
    ui->npc_location_switcher->setStyleSheet(ui_sidebar_released);
    ui->extra_switcher->setStyleSheet(ui_sidebar_released);
    ui->file_switcher->setStyleSheet(ui_sidebar_selected);

    //页面跳转
    ui->working_area->setCurrentIndex(7);

    //页面记录
    current_section = 7;
}


void MainWindow::on_npc_gender_option_unknown_clicked()
{
    //应用样式表
    ui->npc_gender_option_unknown->setStyleSheet(ui_radio_selected);
    ui->npc_gender_male->setStyleSheet(ui_radio_released);
    ui->npc_gender_female->setStyleSheet(ui_radio_released);

    //更改字段
    npc_gender = "未知";
}


void MainWindow::on_npc_gender_male_clicked()
{
    //应用样式表
    ui->npc_gender_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_gender_male->setStyleSheet(ui_radio_selected);
    ui->npc_gender_female->setStyleSheet(ui_radio_released);

    //更改字段
    npc_gender = "男";
}


void MainWindow::on_npc_gender_female_clicked()
{
    //应用样式表
    ui->npc_gender_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_gender_male->setStyleSheet(ui_radio_released);
    ui->npc_gender_female->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_gender = "女";
}


void MainWindow::on_npcname_input_textEdited(const QString &arg1)
{
    QString npc_name_input_received = ui->npcname_input->text();
    ui->project_name->setText(npc_name_input_received);
    QString new_window_title = npc_name_input_received + " - " + window_title_default;
    this->setWindowTitle(new_window_title);
    npc_name = npc_name_input_received;
}


void MainWindow::on_nickname_input_cursorPositionChanged(int arg1, int arg2)
{
    QString npc_nickname_current = ui->nickname_input->text();
    npc_nickname = npc_nickname_current;
}


void MainWindow::on_job_input_textEdited(const QString &arg1)
{
    QString npc_job_current = ui->job_input->text();
    npc_job = npc_job_current;
}


void MainWindow::on_location_input_textEdited(const QString &arg1)
{
    QString npc_location_current = ui->location_input->text();
    npc_location = npc_location_current;
}


void MainWindow::on_npc_country_option_unknown_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "未知";
}


void MainWindow::on_npc_country_option_mondstadt_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "蒙德";
}


void MainWindow::on_npc_country_option_liyue_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "璃月";
}


void MainWindow::on_npc_country_option_inazuman_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "稻妻";
}


void MainWindow::on_npc_country_option_sumeru_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "须弥";
}


void MainWindow::on_npc_country_option_fortaine_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "枫丹";
}


void MainWindow::on_npc_country_option_nata_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_selected);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_country = "纳塔";
}


void MainWindow::on_npc_country_option_snezhnayan_clicked()
{
    //应用样式表
    ui->npc_country_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_option_mondstadt->setStyleSheet(ui_radio_released);
    ui->npc_country_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_option_snezhnayan->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_country = "至冬";
}

