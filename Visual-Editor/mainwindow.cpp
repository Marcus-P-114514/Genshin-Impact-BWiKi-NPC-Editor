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
QString ui_textedit;

//预定义字段 - 仅供生成代码
QString npc_gender = "未知";
QString npc_name;
QString npc_nickname;
QString npc_job;
QString npc_location;
QString npc_country = "未知";
QString npc_organization = "未知";
QString npc_system = "无";
QString npc_gift = "无";
QString npc_version = "未知";

//预定义字段 - 用于程序运行
int current_section = 0;
QString window_title_default = "原神 BWIKI NPC图鉴第三方编辑器 REL 2.0.2";

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
    ui_textedit = ui_lineedit;


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
    ui->npc_gift_option_none->setStyleSheet(ui_radio_selected);
    ui->npc_gift_option_exist->setStyleSheet(ui_radio_released);
    ui->gift_single_edit_name->setStyleSheet(ui_lineedit);
    ui->gift_single_edit_amount->setStyleSheet(ui_lineedit);
    ui->multiple_gift_edit->setStyleSheet(ui_btn_suggested);
    ui->version_input->setStyleSheet(ui_lineedit);
    ui->code_output->setStyleSheet(ui_textedit);

    ui->editor_selecter->setCurrentIndex(0);
    ui->tree_holder->setVisible(0);
    ui->gift_single_edit_name->setVisible(0);
    ui->gift_single_edit_amount->setVisible(0);
    ui->multiple_gift_edit->setVisible(0);

    ui->working_area->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generate_code(){
    ui->code_output->clear();
    ui->code_output->insertPlainText("{{NPC");
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|名称=");
    ui->code_output->insertPlainText(npc_name);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|称号=");
    ui->code_output->insertPlainText(npc_nickname);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|性别=");
    ui->code_output->insertPlainText(npc_gender);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|职业=");
    ui->code_output->insertPlainText(npc_job);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|位置=");
    ui->code_output->insertPlainText(npc_location);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|所属国家=");
    ui->code_output->insertPlainText(npc_country);
    ui->code_output->insertPlainText("\n");
    if (npc_gift !="multi") {
        ui->code_output->insertPlainText("|对话赠礼=");
        ui->code_output->insertPlainText(npc_gift);
        ui->code_output->insertPlainText("\n");
    }
    else{
        QSettings *config_commit_id = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
        QString slot_commit_read = config_commit_id -> value ( "generate/npc_gift").toString();
        QString npc_gift_target_cache_read = "./commit/npc_gift/commit_" + slot_commit_read + ".commit";
        delete config_commit_id;
        QSettings *config_multi_gift = new QSettings (npc_gift_target_cache_read, QSettings::IniFormat);
        npc_gift = config_multi_gift -> value ( "npc_gift/current").toString();
        delete config_multi_gift;
        ui->code_output->insertPlainText("|对话赠礼=");
        ui->code_output->insertPlainText(npc_gift);
        ui->code_output->insertPlainText("\n");
    }
    ui->code_output->insertPlainText("|实装版本=");
    ui->code_output->insertPlainText(npc_version);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|所属组织=");
    ui->code_output->insertPlainText(npc_organization);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|相关系统=");
    ui->code_output->insertPlainText(npc_system);
    ui->code_output->insertPlainText("\n");
}

void MainWindow::on_code_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(1);
    ui->working_area->setCurrentIndex(9);
    generate_code();
}


void MainWindow::on_visual_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(0);
    ui->working_area->setCurrentIndex(current_section);
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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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
    ui->editor_selecter->setCurrentIndex(0);

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


void MainWindow::on_npc_system_option_none_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);

    //更改字段
    npc_system = "无";
}

void MainWindow::on_npc_system_option_commission_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);

    //更改字段
    npc_system = "[[委托]]";
}

void MainWindow::on_npc_system_option_frame_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);

    //更改字段
    npc_system = "[[声望]]";
}

void MainWindow::on_npc_system_option_activity_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);

    //更改字段
    npc_system = "[[活动]]";
}

void MainWindow::on_npc_system_option_store_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);

    //更改字段
    npc_system = "[[商店]]";
}

void MainWindow::on_npc_system_option_cook_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_selected);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_released);

    //更改字段
    npc_system = "[[烹饪]]";
}

void MainWindow::on_npc_system_option_serenitea_pot_clicked()
{
    //应用样式表
    ui->npc_system_option_none->setStyleSheet(ui_radio_released);
    ui->npc_system_option_commission->setStyleSheet(ui_radio_released);
    ui->npc_system_option_frame->setStyleSheet(ui_radio_released);
    ui->npc_system_option_activity->setStyleSheet(ui_radio_released);
    ui->npc_system_option_store->setStyleSheet(ui_radio_released);
    ui->npc_system_option_cook->setStyleSheet(ui_radio_released);
    ui->npc_system_option_serenitea_pot->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_system = "[[尘歌壶]]";
}

void MainWindow::on_organization_input_textChanged(const QString &arg1)
{
    QString npc_organization_read = ui->organization_input->text();
    npc_organization = npc_organization_read;
}

void MainWindow::on_npcname_input_textChanged(const QString &arg1)
{
    QString npc_name_input_received = ui->npcname_input->text();
    ui->project_name->setText(npc_name_input_received);
    QString new_window_title = npc_name_input_received + " - " + window_title_default;
    this->setWindowTitle(new_window_title);
    npc_name = npc_name_input_received;
}

void MainWindow::on_nickname_input_textChanged(const QString &arg1)
{
    QString npc_nickname_current = ui->nickname_input->text();
    npc_nickname = npc_nickname_current;
}

void MainWindow::on_job_input_textChanged(const QString &arg1)
{
    QString npc_job_current = ui->job_input->text();
    npc_job = npc_job_current;
}

void MainWindow::on_location_input_textChanged(const QString &arg1)
{
    QString npc_location_current = ui->location_input->text();
    npc_location = npc_location_current;
}

void MainWindow::on_npc_gift_option_none_clicked()
{
    //应用样式表
    ui->npc_gift_option_none->setStyleSheet(ui_radio_selected);
    ui->npc_gift_option_exist->setStyleSheet(ui_radio_released);

    //更改字段
    npc_gift = "无";

    //更改界面
    ui->gift_single_edit_name->setVisible(0);
    ui->gift_single_edit_amount->setVisible(0);
    ui->multiple_gift_edit->setVisible(0);
}

void MainWindow::on_npc_gift_option_exist_clicked()
{
        //应用样式表
        ui->npc_gift_option_none->setStyleSheet(ui_radio_released);
        ui->npc_gift_option_exist->setStyleSheet(ui_radio_selected);

        //更改界面
        ui->gift_single_edit_name->setVisible(1);
        ui->gift_single_edit_amount->setVisible(1);
        ui->multiple_gift_edit->setVisible(1);

        //更改字段
        QString npc_gift_name_received_3 = ui->gift_single_edit_name->text();
        if (npc_gift_name_received_3 == "<SEPARATE_WINDOW>") {
            npc_gift = "multi";
        }
        else {
            QString npc_gift_amount_received_3 = ui->gift_single_edit_amount->text();
            npc_gift = "{{NPC图标|" + npc_gift_name_received_3 + "|" + npc_gift_amount_received_3 + "}}";
        }
}

void MainWindow::on_gift_single_edit_name_textChanged(const QString &arg1)
{
    QString npc_gift_name_received = ui->gift_single_edit_name->text();
    if (npc_gift_name_received == "<SEPARATE_WINDOW>") {
        npc_gift = "multi";
    }
    else {
        QString npc_gift_amount_received = ui->gift_single_edit_amount->text();
        npc_gift = "{{NPC图标|" + npc_gift_name_received + "|" + npc_gift_amount_received + "}}";
    }
}

void MainWindow::on_gift_single_edit_amount_textChanged(const QString &arg1)
{
    QString npc_gift_name_received_2 = ui->gift_single_edit_name->text();
    if (npc_gift_name_received_2 == "<SEPARATE_WINDOW>") {
        npc_gift = "multi";
    }
    else {
        QString npc_gift_amount_received_2 = ui->gift_single_edit_amount->text();
        npc_gift = "{{NPC图标|" + npc_gift_name_received_2 + "|" + npc_gift_amount_received_2 + "}}";
    }
}

void MainWindow::on_multiple_gift_edit_clicked()
{
    //更改界面
    ui->gift_single_edit_name->setText("<SEPARATE_WINDOW>");
    ui->gift_single_edit_amount->setText("<SEPARATE_WINDOW>");
    npc_gift = "multi";

    //调用窗体
    npc_gift_option *npc_gift_option_window = new npc_gift_option;
    npc_gift_option_window->show();
}

void MainWindow::on_version_input_textChanged(const QString &arg1)
{
    QString npc_version_received = ui->version_input->text();
    npc_version = npc_version_received;
}
