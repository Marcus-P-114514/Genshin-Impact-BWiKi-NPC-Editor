#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QGraphicsDropShadowEffect"
#include "QSettings"
#include "QColor"
#include "QDesktopServices"
#include "QFileDialog"
#include "QFile"

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
QString npc_nickname = "无";
QString npc_job = "未知";
QString npc_location = "未知";
QString npc_country = "未知";
QString npc_organization = "未知";
QString npc_system = "无";
QString npc_gift = "无";
QString npc_version = "未知";
QString npc_store_exist = "否";
QString npc_dialog_exist = "否";
QString npc_cv_Chinese = "未知";
QString npc_cv_Japanese = "未知";
QString npc_cv_English = "未知";
QString npc_cv_Korean = "未知";
QString npc_exist_time = "全天";
QString npc_coordinate;
QString npc_activity = "否";
QString npc_frame_sys;
QString npc_commision_sys;
QString npc_trounce_sys;
QString user_last_edited;
QString document_iscompleted = "否";


//预定义字段 - 用于生成判定
QString npc_store_prices;
QString npc_dialog_current_line_islast_line = "否";
QString npc_location_disp_approach = "地图";

//预定义字段 - 用于程序运行
int current_section = 0;
QString window_title_default = "原神 BWIKI NPC图鉴第三方编辑器 REL 2.1.0";
QString target_url_for_open;

void config_theme_for_this_application(){
    //预设的主题
    //浅色
    QString primary_light = "#E7BF9F";
    QString background_light = "#F6F0E5";
    QString text_color_selected_light = "#FFFFFF";
    QString theme_pref = "";
    QString toolbar_light="#E7BF9F";

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
    ui_stylesheet_general = "QMenu::item:selected{background-color:" + background_current  + ";color:" + primary_current + ";}QMenu::item{background-color:" + primary_current + ";color:" + text_color_current + ";}QMenu::item:disabled{background-color:" + primary_current + ";color: #ddd" + "}QMenu{background-color:" +  toolbar_current + "; color: " + primary_current + ";}" + "QWidget{background-color:" +  background_current + "; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color:" + primary_current + " ;}" + "QMenuBar{background-color:" + toolbar_current + "; color: " + text_color_current +";}";
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
    ui->npc_store_list->setStyleSheet(ui_textedit);
    ui->npc_store_commodity_name_input->setStyleSheet(ui_lineedit);
    ui->npc_store_min_sale_unit->setStyleSheet(ui_lineedit);
    ui->npc_store_exchanger_input->setStyleSheet(ui_lineedit);
    ui->npc_store_price_input->setStyleSheet(ui_lineedit);
    ui->npc_store_limit_input->setStyleSheet(ui_lineedit);
    ui->npc_store_refresh_input->setStyleSheet(ui_lineedit);
    ui->npc_store_etc_input->setStyleSheet(ui_lineedit);
    ui->npc_store_multi_exchanger->setStyleSheet(ui_btn_suggested);
    ui->npc_store_submit_current->setStyleSheet(ui_btn_suggested);
    ui->npc_store_clear_list->setStyleSheet(ui_btn_suggested);
    ui->npc_store_isexist->setStyleSheet(ui_radio_released);
    ui->npc_store_none->setStyleSheet(ui_radio_selected);
    ui->npc_dialog_isexist->setStyleSheet(ui_radio_released);
    ui->npc_dialog_none->setStyleSheet(ui_radio_selected);
    ui->npc_dialog_content_edit->setStyleSheet(ui_textedit);
    ui->npc_dialog_speaker_edit->setStyleSheet(ui_lineedit);
    ui->npc_dialog_line_edit->setStyleSheet(ui_lineedit);
    ui->npc_dialog_islast_line->setStyleSheet(ui_radio_released);
    ui->npc_dialog_insert->setStyleSheet(ui_btn_suggested);
    ui->npc_dialog_append_npc_dialog->setStyleSheet(ui_btn_suggested);
    ui->npc_dialog_append_npc_option->setStyleSheet(ui_btn_suggested);
    ui->Chinese_cv_edit->setStyleSheet(ui_lineedit);
    ui->Japanese_cv_edit->setStyleSheet(ui_lineedit);
    ui->English_cv_edit->setStyleSheet(ui_lineedit);
    ui->Korean_cv_edit->setStyleSheet(ui_lineedit);
    ui->npc_appear_isfull_day->setStyleSheet(ui_radio_selected);
    ui->npc_appear_isday->setStyleSheet(ui_radio_released);
    ui->npc_appear_isnight->setStyleSheet(ui_radio_released);
    ui->npc_location_usemap->setStyleSheet(ui_radio_selected);
    ui->npc_location_usepic->setStyleSheet(ui_radio_released);
    ui->npc_location_map_edit->setStyleSheet(ui_lineedit);
    ui->upload_npc_pic_location->setStyleSheet(ui_btn_suggested);
    ui->npc_activity_yes->setStyleSheet(ui_radio_released);
    ui->npc_activity_no->setStyleSheet(ui_radio_selected);
    ui->npc_frame_sys_edit->setStyleSheet(ui_lineedit);
    ui->npc_commision_sys_edit->setStyleSheet(ui_lineedit);
    ui->npc_trounce_edit->setStyleSheet(ui_lineedit);
    ui->last_edit_ver_edit->setStyleSheet(ui_lineedit);
    ui->file_iscompleted->setStyleSheet(ui_radio_released);
    ui->file_requires_work->setStyleSheet(ui_radio_selected);
    ui->submit_npc_avatar->setStyleSheet(ui_btn_suggested);
    ui->submit_npc_model->setStyleSheet(ui_btn_suggested);
    ui->submit_npc_location_not_detailed->setStyleSheet(ui_btn_suggested);

    ui->editor_selecter->setCurrentIndex(0);
    ui->tree_holder->setVisible(0);
    ui->gift_single_edit_name->setVisible(0);
    ui->gift_single_edit_amount->setVisible(0);
    ui->multiple_gift_edit->setVisible(0);

    ui->working_area->setCurrentIndex(0);
    ui->hide_store_info->setCurrentIndex(1);
    ui->npc_dialog_mainframe->setCurrentIndex(0);
    ui->npc_map_main_frame->setCurrentIndex(0);

    ui->npc_dialog_content_edit->insertPlainText("{{NPC对话");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|标题=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|内容=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|待机语音=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("}}");
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
    if  (npc_store_exist == "否") {
        ui->code_output->insertPlainText("|存在商店=否");
        ui->code_output->insertPlainText("\n");
    }
    else{
        ui->code_output->insertPlainText("|存在商店=是");
        ui->code_output->insertPlainText("\n");
        ui->code_output->insertPlainText("|商店内容=");
        ui->code_output->insertPlainText(ui->npc_store_list->document()->toPlainText());
        QTextCursor npc_store_handle_last_line = ui->code_output->textCursor();
        npc_store_handle_last_line.deletePreviousChar();
        npc_store_handle_last_line.deletePreviousChar();
        ui->code_output->insertPlainText("\n");
    }
    if (npc_dialog_exist == "否") {
        ui->code_output->insertPlainText("|存在对话=否");
        ui->code_output->insertPlainText("\n");
    }
    else {
        ui->code_output->insertPlainText("|存在对话=是");
        ui->code_output->insertPlainText("\n");
        ui->code_output->insertPlainText("|对话内容=");
        QString npc_dialog_received_2 = ui->npc_dialog_content_edit->document()->toPlainText();
        ui->code_output->insertPlainText(npc_dialog_received_2);
        ui->code_output->insertPlainText("\n");
    }
    ui->code_output->insertPlainText("|中文CV=");
    ui->code_output->insertPlainText(npc_cv_Chinese);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|日文CV=");
    ui->code_output->insertPlainText(npc_cv_Japanese);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|英文CV=");
    ui->code_output->insertPlainText(npc_cv_English);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|韩文CV=");
    ui->code_output->insertPlainText(npc_cv_Korean);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|出现时间=");
    ui->code_output->insertPlainText(npc_exist_time);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|出现地点={{NPC位置|出现时间：");
    ui->code_output->insertPlainText(npc_exist_time);
    ui->code_output->insertPlainText("|");
    ui->code_output->insertPlainText(npc_location_disp_approach);
    ui->code_output->insertPlainText("|");
    if (npc_location_disp_approach == "地图") {
        ui->code_output->insertPlainText(npc_coordinate);
    }
    else {
        QString npc_get_location_pic_detailed = "NPC-具体位置-" + npc_name + "-" + npc_exist_time;
        ui->code_output->insertPlainText(npc_get_location_pic_detailed);
    }
    ui->code_output->insertPlainText("|");
    ui->code_output->insertPlainText(npc_name);
    ui->code_output->insertPlainText("位置}}");
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|活动限定=");
    ui->code_output->insertPlainText(npc_activity);
    ui->code_output->insertPlainText("\n");
    if (npc_frame_sys != "") {
        ui->code_output->insertPlainText("|声望系统=");
        ui->code_output->insertPlainText(npc_frame_sys);
        ui->code_output->insertPlainText("\n");
    }
    else {
        bool ok;
    }
    if (npc_commision_sys != "") {
        ui->code_output->insertPlainText("|居民委托=");
        ui->code_output->insertPlainText(npc_commision_sys);
        ui->code_output->insertPlainText("\n");
    }
    else {
        bool ok;
    }
    if (npc_trounce_sys != "") {
        ui->code_output->insertPlainText("|讨伐悬赏=");
        ui->code_output->insertPlainText(npc_trounce_sys);
        ui->code_output->insertPlainText("\n");
    }
    else {
        bool ok;
    }
    ui->code_output->insertPlainText("|最后编辑版本=");
    ui->code_output->insertPlainText(user_last_edited);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("|是否完善=");
    ui->code_output->insertPlainText(document_iscompleted);
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("}}");

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

void MainWindow::on_npc_store_isexist_clicked()
{
    //应用样式表
    ui->npc_store_isexist->setStyleSheet(ui_radio_selected);
    ui->npc_store_none->setStyleSheet(ui_radio_released);

    //更改字段
    npc_store_exist = "是";

    //启用组件
    ui->hide_store_info->setCurrentIndex(0);
}

void MainWindow::on_npc_store_none_clicked()
{
    //应用样式表
    ui->npc_store_isexist->setStyleSheet(ui_radio_released);
    ui->npc_store_none->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_store_exist = "否";

    //启用组件
    ui->hide_store_info->setCurrentIndex(1);
}

void MainWindow::on_npc_store_clear_list_clicked()
{
    ui->npc_store_list->clear();
    ui->npc_store_commodity_name_input->clear();
    ui->npc_store_min_sale_unit->clear();
    ui->npc_store_exchanger_input->clear();
    ui->npc_store_price_input->clear();
    ui->npc_store_limit_input->clear();
    ui->npc_store_refresh_input->clear();
    ui->npc_store_etc_input->clear();
}

void MainWindow::on_npc_store_submit_current_clicked()
{
    QString npc_store_commodity_name_received = ui->npc_store_commodity_name_input->text();
    QString npc_store_min_sale_unit_received = ui->npc_store_min_sale_unit->text();
    QString npc_store_exchanger_received = ui->npc_store_exchanger_input->text();
    QString npc_store_price_received = ui->npc_store_price_input->text();
    QString npc_store_limit_received = ui->npc_store_limit_input->text();
    QString npc_store_refresh_received = ui->npc_store_refresh_input->text();
    QString npc_store_etc_received = ui->npc_store_etc_input->text();
    if (npc_store_exchanger_received != "<SEPARATE_WINDOW>") {
        QString store_list_current_line = npc_store_commodity_name_received + "*" + npc_store_min_sale_unit_received + "," + npc_store_exchanger_received + "*" + npc_store_price_received + "," + npc_store_limit_received + "," + npc_store_refresh_received + "," + npc_store_etc_received  + "+";
        ui->npc_store_list->insertPlainText(store_list_current_line);
        ui->npc_store_list->insertPlainText("\n");
    }
    else {
        QSettings *config_commit_id_2 = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
        QString slot_commit_read_3 = config_commit_id_2 -> value ( "generate/npc_store").toString();
        QString npc_store_target_cache_read = "./commit/npc_store/commit_" + slot_commit_read_3 + ".commit";
        delete config_commit_id_2;
        QSettings *config_multi_store = new QSettings (npc_store_target_cache_read, QSettings::IniFormat);
        npc_store_prices = config_multi_store -> value ( "npc_store/current").toString();
        delete config_multi_store;
        QString store_list_current_line = npc_store_commodity_name_received + "*" + npc_store_min_sale_unit_received + "," + npc_store_prices + "," + npc_store_limit_received + "," + npc_store_refresh_received + "," + npc_store_etc_received  + "+";
        ui->npc_store_list->insertPlainText(store_list_current_line);
        ui->npc_store_list->insertPlainText("\n");
    }
    ui->npc_store_commodity_name_input->clear();
    ui->npc_store_min_sale_unit->clear();
    ui->npc_store_exchanger_input->clear();
    ui->npc_store_price_input->clear();
    ui->npc_store_limit_input->clear();
    ui->npc_store_refresh_input->clear();
    ui->npc_store_etc_input->clear();
}

void MainWindow::on_npc_store_multi_exchanger_clicked()
{
    ui->npc_store_exchanger_input->setText("<SEPARATE_WINDOW>");
    ui->npc_store_price_input->setText("<SEPARATE_WINDOW>");
    npc_store_multi_exchange *store_multi_exchange = new npc_store_multi_exchange;
    store_multi_exchange->show();
}

void MainWindow::on_open_mapview_triggered()
{

}

void MainWindow::on_npc_dialog_none_clicked()
{
    //应用样式表
    ui->npc_dialog_isexist->setStyleSheet(ui_radio_released);
    ui->npc_dialog_none->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_dialog_exist = "否";

    //显示面板
    ui->npc_dialog_mainframe->setCurrentIndex(0);
}

void MainWindow::on_npc_dialog_isexist_clicked()
{
    //应用样式表
    ui->npc_dialog_isexist->setStyleSheet(ui_radio_selected);
    ui->npc_dialog_none->setStyleSheet(ui_radio_released);

    //更改字段
    npc_dialog_exist = "是";

    //显示面板
    ui->npc_dialog_mainframe->setCurrentIndex(1);
}

void MainWindow::on_npc_dialog_islast_line_clicked()
{
    if (npc_dialog_current_line_islast_line == "否") {
        npc_dialog_current_line_islast_line = "是";
        ui->npc_dialog_islast_line->setStyleSheet(ui_radio_selected);
    }
    else {
        npc_dialog_current_line_islast_line = "否";
        ui->npc_dialog_islast_line->setStyleSheet(ui_radio_released);
    }
}

void MainWindow::on_npc_dialog_insert_clicked()
{
    ui->npc_dialog_content_edit->insertPlainText("'''");
    QString npc_dialog_speaker_received = ui->npc_dialog_speaker_edit->text();
    ui->npc_dialog_content_edit->insertPlainText(npc_dialog_speaker_received);
    ui->npc_dialog_content_edit->insertPlainText("'''");
    ui->npc_dialog_content_edit->insertPlainText("：");
    QString npc_dialog_line_received = ui->npc_dialog_line_edit->text();
    ui->npc_dialog_content_edit->insertPlainText(npc_dialog_line_received);
    if (npc_dialog_current_line_islast_line == "是") {
        bool ok;
    }
    else {
        ui->npc_dialog_content_edit->insertPlainText("<br/>");
        ui->npc_dialog_content_edit->insertPlainText("\n");
    }
}

void MainWindow::on_npc_dialog_append_npc_dialog_clicked()
{
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("{{NPC对话");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|标题=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|内容=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|待机语音=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("}}");
}

void MainWindow::on_npc_dialog_append_npc_option_clicked()
{
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("{{NPC剧情");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项1=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项1图标=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|剧情1=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项2=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项2图标=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|剧情2=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项3=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项3图标=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|剧情3=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项4=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|选项4图标=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("|剧情4=");
    ui->npc_dialog_content_edit->insertPlainText("\n");
    ui->npc_dialog_content_edit->insertPlainText("}}");
}

void MainWindow::on_Chinese_cv_edit_textChanged(const QString &arg1)
{
    npc_cv_Chinese = ui->Chinese_cv_edit->text();
}

void MainWindow::on_Japanese_cv_edit_textChanged(const QString &arg1)
{
    npc_cv_Japanese = ui->Japanese_cv_edit->text();
}

void MainWindow::on_English_cv_edit_textChanged(const QString &arg1)
{
    npc_cv_English = ui->English_cv_edit->text();
}

void MainWindow::on_Korean_cv_edit_textChanged(const QString &arg1)
{
    npc_cv_Korean = ui->Korean_cv_edit->text();
}

void MainWindow::on_npc_appear_isfull_day_clicked()
{
    //应用样式表
    ui->npc_appear_isfull_day->setStyleSheet(ui_radio_selected);
    ui->npc_appear_isday->setStyleSheet(ui_radio_released);
    ui->npc_appear_isnight->setStyleSheet(ui_radio_released);

    //更改字段
    npc_exist_time = "全天";
}

void MainWindow::on_npc_appear_isday_clicked()
{
    //应用样式表
    ui->npc_appear_isfull_day->setStyleSheet(ui_radio_released);
    ui->npc_appear_isday->setStyleSheet(ui_radio_selected);
    ui->npc_appear_isnight->setStyleSheet(ui_radio_released);

    //更改字段
    npc_exist_time = "白天";
}

void MainWindow::on_npc_appear_isnight_clicked()
{
    //应用样式表
    ui->npc_appear_isfull_day->setStyleSheet(ui_radio_released);
    ui->npc_appear_isday->setStyleSheet(ui_radio_released);
    ui->npc_appear_isnight->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_exist_time = "夜晚";
}

void MainWindow::on_npc_location_usemap_clicked()
{
    //应用样式表
    ui->npc_location_usemap->setStyleSheet(ui_radio_selected);
    ui->npc_location_usepic->setStyleSheet(ui_radio_released);

    //更新界面
    ui->npc_map_main_frame->setCurrentIndex(0);

    //更改字段
    npc_location_disp_approach = "地图";
}

void MainWindow::on_npc_location_usepic_clicked()
{
    //应用样式表
    ui->npc_location_usemap->setStyleSheet(ui_radio_released);
    ui->npc_location_usepic->setStyleSheet(ui_radio_selected);

    //更新界面
    ui->npc_map_main_frame->setCurrentIndex(1);

    //更改字段
    npc_location_disp_approach = "图片";
}

void MainWindow::on_npc_location_map_edit_textChanged(const QString &arg1)
{
    npc_coordinate = ui->npc_location_map_edit->text();
}

void MainWindow::on_upload_npc_pic_location_clicked()
{
    QString npc_location_pic_target = "https://wiki.biligame.com/ys/文件:NPC-具体位置-" + npc_name + "-" + npc_exist_time + ".png";
    QDesktopServices::openUrl(QUrl(npc_location_pic_target));
}

void MainWindow::on_npc_activity_yes_clicked()
{
    //应用样式表
    ui->npc_activity_yes->setStyleSheet(ui_radio_selected);
    ui->npc_activity_no->setStyleSheet(ui_radio_released);

    //更改字段
    npc_activity = "是";
}

void MainWindow::on_npc_activity_no_clicked()
{
    //应用样式表
    ui->npc_activity_yes->setStyleSheet(ui_radio_released);
    ui->npc_activity_no->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_activity = "否";
}

void MainWindow::on_npc_frame_sys_edit_textChanged(const QString &arg1)
{
    npc_frame_sys = ui->npc_frame_sys_edit->text();
}

void MainWindow::on_npc_commision_sys_edit_textChanged(const QString &arg1)
{
    npc_commision_sys = ui->npc_commision_sys_edit->text();
}

void MainWindow::on_npc_trounce_edit_textChanged(const QString &arg1)
{
    npc_trounce_sys = ui->npc_trounce_edit->text();
}

void MainWindow::on_last_edit_ver_edit_textChanged(const QString &arg1)
{
    user_last_edited = ui->last_edit_ver_edit->text();
}

void MainWindow::on_file_iscompleted_clicked()
{
    //应用样式表
    ui->file_iscompleted->setStyleSheet(ui_radio_selected);
    ui->file_requires_work->setStyleSheet(ui_radio_released);

    //更改字段
    document_iscompleted = "是";
}

void MainWindow::on_file_requires_work_clicked()
{
    //应用样式表
    ui->file_iscompleted->setStyleSheet(ui_radio_released);
    ui->file_requires_work->setStyleSheet(ui_radio_selected);

    //更改字段
    document_iscompleted = "否";
}

void MainWindow::on_submit_npc_avatar_clicked()
{
    target_url_for_open = "https://wiki.biligame.com/ys/文件:" + npc_name + ".png";
    QDesktopServices::openUrl(QUrl(target_url_for_open));
}

void MainWindow::on_submit_npc_model_clicked()
{
    target_url_for_open = "https://wiki.biligame.com/ys/文件:" + npc_name + "建模.png";
    QDesktopServices::openUrl(QUrl(target_url_for_open));
}

void MainWindow::on_submit_npc_location_not_detailed_clicked()
{
    target_url_for_open = "https://wiki.biligame.com/ys/文件:" + npc_name + "位置.png";
    QDesktopServices::openUrl(QUrl(target_url_for_open));
}

void MainWindow::on_generate_wiki_content_triggered()
{
    QString wiki_file_name = npc_name + ".txt";
    QString wiki_file_dir = QFileDialog::getSaveFileName(this, tr("保存文件为WIKI可识别格式"), wiki_file_name, tr("纯文本文件 (*.txt)"));
}
