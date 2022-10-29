#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QGraphicsDropShadowEffect"
#include "QSettings"
#include "QColor"
#include "QDesktopServices"
#include "QFileDialog"
#include "QFile"
#include "iostream"
#include "QTextStream"
#include "QProcess"
#include "QMimeData"
#include "QClipboard"
#include "QInputDialog"
#include "QDebug"
#include "QDialog"
#include "QMessageBox"
#include "QTextStream"

using namespace std;

//预定义字段 - 仅供读取主题
QString theme_pref;
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
QString ui_quickinsert;

//预定义字段 - 仅供生成代码
QString npc_gender = "未知";
QString npc_name = "未命名";
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
QString npc_dialog_received_2;
QString npc_avatar_patch = "否";
QString npc_current_country = "未知";

//预定义字段 - 用于生成判定
QString npc_store_prices;
QString npc_dialog_current_line_islast_line = "否";
QString npc_location_disp_approach = "地图";

//预定义字段 - 用于程序运行
int current_section = 0;
QString window_title_default = "原神 BWIKI NPC图鉴第三方编辑器 REL 2.3.6";
QString target_url_for_open;
QString save_file_target;
QString argument_received;

void MainWindow::open_project_ini() {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QSettings *config_open = new QSettings ( save_file_target, QSettings::IniFormat);
    //读取：文件头
        QString file_section_read = config_open->value("File/Section").toString();
        QString file_version_read = config_open->value("File/Version").toString();
        //读取：基本信息
        QString file_name_read = config_open->value("Basic/Name").toString();
        QString file_nickname_read = config_open->value("Basic/Nickname").toString();
        QString file_gender_read = config_open->value("Basic/Gender").toString();
        QString file_job_read = config_open->value("Basic/Job").toString();
        QString file_location_read = config_open->value("Basic/Location").toString();
        QString file_country_read = config_open->value("Basic/Country").toString();
        QString file_org_read = config_open->value("Basic/Organization").toString();
        QString file_system_read = config_open->value("Basic/System").toString();
        QString file_gift_read = config_open->value("Basic/Gift").toString();
        QString file_version_npc_read = config_open->value("Basic/Version").toString();

        //读取：商店
        QString file_store_exist_read = config_open->value("Store/Exist").toString();
        QString file_store_content_read = config_open->value("Store/Content").toString();

        //读取：对话
        QString file_dialog_exist_read = config_open->value("Dialog/Exist").toString();
        QString file_dialog_content_read = config_open->value("Dialog/Content").toString();

        //读取：CV表
        QString file_CV_Chinese_read = config_open->value("CV_Table/Chinese").toString();
        QString file_CV_Japanese_read = config_open->value("CV_Table/Japanese").toString();
        QString file_CV_English_read = config_open->value("CV_Table/English").toString();
        QString file_CV_Korean_read = config_open->value("CV_Table/Korean").toString();

        //读取：位置
        QString file_time_read = config_open->value("Location/Time").toString();
        QString file_type_read = config_open->value("Location/Type").toString();
        QString file_coordinate_read = config_open->value("Location/Coordinate").toString();

        //读取：杂项
        QString file_activity_read = config_open->value("Extras/Activity").toString();
        QString file_frame_read = config_open->value("Extras/Frame").toString();
        QString file_commision_read = config_open->value("Extras/Commision").toString();
        QString file_trounce_read = config_open->value("Extras/Trounce").toString();
        QString file_last_edit_read = config_open->value("Extras/Last_Edited").toString();
        QString file_iscompleted_read = config_open->value("Extras/IsCompleted").toString();

    delete config_open;
        //处理：界面
        ui->npcname_input->setText(file_name_read);
        ui->nickname_input->setText(file_nickname_read);
        if (file_gender_read == "女") {
            //应用样式表
            ui->npc_gender_option_unknown->setStyleSheet(ui_radio_released);
            ui->npc_gender_male->setStyleSheet(ui_radio_released);
            ui->npc_gender_female->setStyleSheet(ui_radio_selected);

            //更改字段
            npc_gender = "女";
        }
        else if (file_gender_read == "男") {
            //应用样式表
            ui->npc_gender_option_unknown->setStyleSheet(ui_radio_released);
            ui->npc_gender_male->setStyleSheet(ui_radio_selected);
            ui->npc_gender_female->setStyleSheet(ui_radio_released);

            //更改字段
            npc_gender = "男";
        }
        else {
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
        ui->job_input->setText(file_job_read);
        ui->location_input->setText(file_location_read);
        if (file_country_read == "蒙德") {
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
        else if (file_country_read == "璃月") {
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
        else if (file_country_read == "稻妻") {
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
        else if (file_country_read == "须弥") {
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
        else if (file_country_read == "枫丹") {
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
        else if (file_country_read == "纳塔") {
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
        else if (file_country_read == "至冬") {
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
        else{
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
        ui->organization_input->setText(file_org_read);
        if (file_gift_read == "无") {
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
        else {
            //应用样式表
            ui->npc_gift_option_none->setStyleSheet(ui_radio_released);
            ui->npc_gift_option_exist->setStyleSheet(ui_radio_selected);

            //更改界面
            ui->gift_single_edit_name->setVisible(1);
            ui->gift_single_edit_amount->setVisible(1);
            ui->multiple_gift_edit->setVisible(1);
            ui->gift_single_edit_amount->setText("<READ_FROM_FILE>");
            ui->gift_single_edit_name->setText("<READ_FROM_FILE>");

            //更改字段
            npc_gift = file_gift_read;
        }
        if (file_system_read == "[[委托]]") {
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
        else if (file_system_read == "[[声望]]") {
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
        else if (file_system_read == "[[活动]]") {
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
        else if (file_system_read == "[[商店]]") {
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
        else if (file_system_read == "[[烹饪]]") {
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
        else if (file_system_read == "[[尘歌壶]]") {
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
        else {
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
        ui->version_input->setText(file_version_npc_read);
        if (file_store_exist_read == "否") {
            //应用样式表
            ui->npc_store_isexist->setStyleSheet(ui_radio_released);
            ui->npc_store_none->setStyleSheet(ui_radio_selected);

            //更改字段
            npc_store_exist = "否";

            //启用组件
            ui->hide_store_info->setCurrentIndex(1);
        }
        else {
            //应用样式表
            ui->npc_store_isexist->setStyleSheet(ui_radio_selected);
            ui->npc_store_none->setStyleSheet(ui_radio_released);

            //更改字段
            npc_store_exist = "是";

            //启用组件
            ui->hide_store_info->setCurrentIndex(0);
        }
        ui->npc_store_list->clear();
        ui->npc_store_list->insertPlainText(file_store_content_read);
        if (file_dialog_exist_read == "否") {
            //应用样式表
            ui->npc_dialog_isexist->setStyleSheet(ui_radio_released);
            ui->npc_dialog_none->setStyleSheet(ui_radio_selected);

            //更改字段
            npc_dialog_exist = "否";

            //显示面板
            ui->npc_dialog_mainframe->setCurrentIndex(0);
        }
        else {
            //应用样式表
            ui->npc_dialog_isexist->setStyleSheet(ui_radio_selected);
            ui->npc_dialog_none->setStyleSheet(ui_radio_released);

            //更改字段
            npc_dialog_exist = "是";

            //显示面板
            ui->npc_dialog_mainframe->setCurrentIndex(1);
        }
        ui->npc_dialog_content_edit->clear();
        ui->npc_dialog_content_edit->insertPlainText(file_dialog_content_read);
        ui->Chinese_cv_edit->setText(file_CV_Chinese_read);
        ui->Japanese_cv_edit->setText(file_CV_Japanese_read);
        ui->English_cv_edit->setText(file_CV_English_read);
        ui->Korean_cv_edit->setText(file_CV_Korean_read);
        if (file_time_read == "白天") {
            //应用样式表
            ui->npc_appear_isfull_day->setStyleSheet(ui_radio_released);
            ui->npc_appear_isday->setStyleSheet(ui_radio_selected);
            ui->npc_appear_isnight->setStyleSheet(ui_radio_released);

            //更改字段
            npc_exist_time = "白天";
        }
        else if (file_time_read == "夜晚") {
            //应用样式表
            ui->npc_appear_isfull_day->setStyleSheet(ui_radio_released);
            ui->npc_appear_isday->setStyleSheet(ui_radio_released);
            ui->npc_appear_isnight->setStyleSheet(ui_radio_selected);

            //更改字段
            npc_exist_time = "夜晚";
        }
        else {
            //应用样式表
            ui->npc_appear_isfull_day->setStyleSheet(ui_radio_selected);
            ui->npc_appear_isday->setStyleSheet(ui_radio_released);
            ui->npc_appear_isnight->setStyleSheet(ui_radio_released);

            //更改字段
            npc_exist_time = "全天";
        }
        if (file_type_read == "地图") {
            //应用样式表
            ui->npc_location_usemap->setStyleSheet(ui_radio_selected);
            ui->npc_location_usepic->setStyleSheet(ui_radio_released);

            //更新界面
            ui->npc_map_main_frame->setCurrentIndex(0);

            //更改字段
            npc_location_disp_approach = "地图";
        }
        else {
            //应用样式表
            ui->npc_location_usemap->setStyleSheet(ui_radio_released);
            ui->npc_location_usepic->setStyleSheet(ui_radio_selected);

            //更新界面
            ui->npc_map_main_frame->setCurrentIndex(1);

            //更改字段
            npc_location_disp_approach = "图片";
        }
        ui->npc_location_map_edit->setText(file_coordinate_read);
        if (file_activity_read == "是") {
            //应用样式表
            ui->npc_activity_yes->setStyleSheet(ui_radio_selected);
            ui->npc_activity_no->setStyleSheet(ui_radio_released);

            //更改字段
            npc_activity = "是";
        }
        else {
            //应用样式表
            ui->npc_activity_yes->setStyleSheet(ui_radio_released);
            ui->npc_activity_no->setStyleSheet(ui_radio_selected);

            //更改字段
            npc_activity = "否";
        }
        ui->npc_frame_sys_edit->setText(file_frame_read);
        ui->npc_commision_sys_edit->setText(file_commision_read);
        ui->npc_trounce_edit->setText(file_trounce_read);
        ui->last_edit_ver_edit->setText(file_last_edit_read);
        if (file_iscompleted_read =="是") {
            //应用样式表
            ui->file_iscompleted->setStyleSheet(ui_radio_selected);
            ui->file_requires_work->setStyleSheet(ui_radio_released);

            //更改字段
            document_iscompleted = "是";
        }
        else {
            //应用样式表
            ui->file_iscompleted->setStyleSheet(ui_radio_released);
            ui->file_requires_work->setStyleSheet(ui_radio_selected);

            //更改字段
            document_iscompleted = "否";
        }

        //处理：代码
        generate_code();

        QApplication::restoreOverrideCursor();
}

void config_theme_for_this_application(){}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //预设的主题
    //浅色
    QString primary_light = "#E7BF9F";
    QString background_light = "#F6F0E5";
    QString text_color_selected_light = "#FFFFFF";
    QString toolbar_light="#E7BF9F";

    //深色
    QString primary_dark = "#E7BF9F";
    QString background_dark = "rgb(69,69,69)";
    QString text_color_selected_dark = "#FFFFFF";
    QString toolbar_dark="#E7BF9F";

    //黑色
    QString primary_black = "#E7BF9F";
    QString background_black = "rgb(0,0,0)";
    QString text_color_selected_black = "#FFFFFF";
    QString toolbar_black="#rgb(0,0,0)";

    //读取主题
    QSettings *config_theme = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    //QString theme_pref_read = config_theme -> value ( "theme/name").toString();
    //theme_pref_read = theme_pref;
    //qDebug()<<theme_pref_read;

    QSettings *config_theme_n = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    theme_pref = config_theme -> value ( "theme/name").toString();
    delete config_theme_n;


    //应用预设
    if (theme_pref == "light"){
        primary_current = primary_light;
        background_current = background_light;
        text_color_current = text_color_selected_light;
        toolbar_current = toolbar_light;
        toolbar_shade_current = "border-image: url(:/ui/resources/images/toolbar_with_backgrounds_light_version_one.png);";
    }
    else if (theme_pref == "dark"){
        primary_current = primary_dark;
        background_current = background_dark;
        text_color_current = text_color_selected_dark;
        toolbar_current = toolbar_dark;
    }
    else if (theme_pref == "black"){
        primary_current = primary_black;
        background_current = background_black;
        text_color_current = text_color_selected_black;
        toolbar_current = toolbar_black;
    }
    else if (theme_pref == "custom"){
        QString primary_custom = config_theme -> value ( "custom/primary").toString();
        QString background_custom = config_theme -> value ( "custom/background").toString();
        QString text_color_selected_custom = config_theme -> value ( "custom/text_color").toString();
        QString toolbar_custom = config_theme -> value ( "custom/toolbar").toString();
        primary_current = primary_custom;
        background_current = background_custom;
        text_color_current = text_color_selected_custom;
        toolbar_current = toolbar_custom;
    }
    else{
        primary_current = primary_light;
        background_current = background_light;
        text_color_current = text_color_selected_light;
        toolbar_current = toolbar_light;
        toolbar_shade_current = "border-image: url(:/ui/resources/images/toolbar_with_backgrounds_light_version_one.png);";
    }

    delete config_theme;

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
    ui_quickinsert = "background: " + primary_current + "; color: " + text_color_current + ";";

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
    ui->quickinsert->setStyleSheet(ui_quickinsert);
    ui->patch_avatar_false->setStyleSheet(ui_radio_selected);
    ui->patch_avatar_true->setStyleSheet(ui_radio_released);
    ui->patch_avatar_intro->setStyleSheet(ui_btn_frameless);
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);


    ui->editor_selecter->setCurrentIndex(0);
    ui->tree_holder->setVisible(0);
    ui->gift_single_edit_name->setVisible(0);
    ui->gift_single_edit_amount->setVisible(0);
    ui->multiple_gift_edit->setVisible(0);
    ui->quickinsert->setVisible(0);

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

    setAcceptDrops(true);

    QFile open_default("./config/arguments.conf");
    if (open_default.open(QFile::ReadOnly | QIODevice::Truncate))
    {
        QTextStream arg_input(&open_default);
        argument_received = arg_input.readAll();
    }
    open_default.close();
    QFile clear_default("./config/arguments.conf");
    clear_default.open(QFile::WriteOnly | QIODevice::Truncate);
    clear_default.resize(0);
    clear_default.close();


    if (argument_received != ""){
        save_file_target = argument_received;
        setWindowTitle(save_file_target);
        open_project_ini();
    }
    else{
        bool ok;
    }
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
    ui->code_output->insertPlainText("|所在国家=");
    ui->code_output->insertPlainText(npc_current_country);
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
        npc_dialog_received_2 = ui->npc_dialog_content_edit->document()->toPlainText();
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
    if (npc_avatar_patch=="是"){
       ui->code_output->insertPlainText("\n");
       ui->code_output->insertPlainText("|修补头像=是");
    }
    else{
        bool ok;
    }
    ui->code_output->insertPlainText("\n");
    ui->code_output->insertPlainText("}}");

}

void MainWindow::save_project_ini() {
    generate_code();
    QSettings *config_save = new QSettings ( save_file_target, QSettings::IniFormat);
    //处理：文件头
    config_save->setValue("File/Section", "NPC");
    config_save->setValue("File/Version", "2.0");
    //处理：基本信息
    config_save->setValue("Basic/Name", npc_name);
    config_save->setValue("Basic/Nickname", npc_nickname);
    config_save->setValue("Basic/Gender", npc_gender);
    config_save->setValue("Basic/Job", npc_job);
    config_save->setValue("Basic/Location", npc_location);
    config_save->setValue("Basic/Country", npc_country);
    config_save->setValue("Basic/Organization", npc_organization);
    config_save->setValue("Basic/System", npc_system);
    config_save->setValue("Basic/Gift", npc_gift);
    config_save->setValue("Basic/Version", npc_version);

    //处理：商店
    config_save->setValue("Store/Exist", npc_store_exist);
    QString save_store_content = ui->npc_store_list->document()->toPlainText();
    config_save->setValue("Store/Content", save_store_content);

    //处理：对话
    config_save->setValue("Dialog/Exist", npc_dialog_exist);
    config_save->setValue("Dialog/Content", npc_dialog_received_2);

    //处理：CV表
    config_save->setValue("CV_Table/Chinese", npc_cv_Chinese);
    config_save->setValue("CV_Table/Japanese", npc_cv_Japanese);
    config_save->setValue("CV_Table/English", npc_cv_English);
    config_save->setValue("CV_Table/Korean", npc_cv_Korean);

    //处理：位置
    config_save->setValue("Location/Time", npc_exist_time);
    config_save->setValue("Location/Type", npc_location_disp_approach);
    config_save->setValue("Location/Coordinate", npc_coordinate);

    //处理：杂项
    config_save->setValue("Extras/Activity", npc_activity);
    config_save->setValue("Extras/Frame", npc_frame_sys);
    config_save->setValue("Extras/Commision", npc_commision_sys);
    config_save->setValue("Extras/Trounce", npc_trounce_sys);
    config_save->setValue("Extras/Last_Edited", user_last_edited);
    config_save->setValue("Extras/IsCompleted", document_iscompleted);

    delete config_save;
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
    QDesktopServices::openUrl(QUrl("https://wiki.biligame.com/ys/%E5%8E%9F%E7%A5%9E%E5%9C%B0%E5%9B%BE%E5%B7%A5%E5%85%B7_%E5%85%A8%E5%9C%B0%E6%A0%87%E4%BD%8D%E7%BD%AE%E7%82%B9"));
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
    generate_code();
    QString wiki_file_name = npc_name + ".txt";
    QString wiki_file_dir = QFileDialog::getSaveFileName(this, tr("保存文件为WIKI可识别格式"), wiki_file_name, tr("纯文本文件 (*.txt)"));
    QFile wiki_file_target(wiki_file_dir);
    if(wiki_file_target.open(QIODevice::WriteOnly | QIODevice::Text) ) {
            QTextStream out(&wiki_file_target);
             out << ui->code_output->document()->toPlainText() << endl;
            wiki_file_target.close();
    }
}

void MainWindow::on_new_project_triggered()
{
    qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}

void MainWindow::on_save_project_triggered()
{
    if (save_file_target == "") {
        QString save_file_name = npc_name + ".npcedit";
        save_file_target = QFileDialog::getSaveFileName(this, tr("保存工程..."), save_file_name, tr("NPC文件 (*.npcedit)"));
    }
    else {
        bool ok;
    }
    save_project_ini();
}

void MainWindow::on_save_project_as_triggered()
{
    QString save_file_name = npc_name + ".npcedit";
    save_file_target = QFileDialog::getSaveFileName(this, tr("工程另存为..."), save_file_name, tr("NPC文件 (*.npcedit)"));
    save_project_ini();
}

void MainWindow::on_open_project_triggered()
{
    save_file_target = QFileDialog::getOpenFileName(this, tr("打开工程..."), "", tr("NPC文件 (*.npcedit)"));
    open_project_ini();
}

void MainWindow::on_release_to_WIKI_triggered()
{
    target_url_for_open = "https://wiki.biligame.com/ys/index.php?title=" + npc_name + "&action=edit";
    QDesktopServices::openUrl(QUrl(target_url_for_open));
}

void MainWindow::on_welcome_screen_linkActivated(const QString &link)
{
    save_file_target = QFileDialog::getOpenFileName(this, tr("打开工程..."), "", tr("NPC文件 (*.npcedit)"));
    open_project_ini();
}

void MainWindow::dragEnterEvent(QDragEnterEvent *drop_event_1)
{
    if(drop_event_1->mimeData()->hasFormat("text/uri-list"))
        drop_event_1->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *drop_event_1)
{
    QList<QUrl> dropped_file = drop_event_1->mimeData()->urls();
    if (dropped_file.isEmpty()) {
        bool ok;
    }
    else {
        QString save_file_target = dropped_file.first().toLocalFile();
        open_project_ini();
    }

}

void MainWindow::on_insert_templates_triggered()
{
    ui->quickinsert->setVisible(1);
}

void MainWindow::on_insert_brackets_triggered()
{
    QClipboard* clip_brackets = QApplication::clipboard();
    clip_brackets->setText("「」");
}

void MainWindow::on_insert_bold_triggered()
{
    QString bold_progress = QInputDialog::getText(this, "加粗", "输入要加粗的内容，将会自动复制到剪切板。");
    QString bold_progress_2 = "'''" + bold_progress + "'''";
    QClipboard* clip_bold = QApplication::clipboard();
    clip_bold->setText(bold_progress_2);
}

void MainWindow::on_insert_italic_triggered()
{
    QString italic_progress = QInputDialog::getText(this, "斜体", "输入要转换为斜体的内容，将会自动复制到剪切板。");
    QString italic_progress_2 = "''" + italic_progress + "''";
    QClipboard* clip_italic = QApplication::clipboard();
    clip_italic->setText(italic_progress_2);
}

void MainWindow::on_insert_underline_triggered()
{
    QString underline_progress = QInputDialog::getText(this, "下划线", "输入要添加下划线的内容，将会自动复制到剪切板。");
    QString underline_progress_2 = "<u>" + underline_progress + "</u>";
    QClipboard* clip_underline = QApplication::clipboard();
    clip_underline->setText(underline_progress_2);
}

void MainWindow::on_apply_font_color_triggered()
{
    QString color_input = QInputDialog::getText(this, "颜色", "期望的颜色，将会自动复制到剪切板。\n支持原神BWIKI所支持的颜色，例如：火，详细情况请移步详见：https://wiki.biligame.com/ys/原神WIKI编辑教程/#模板:颜色\n亦可输入CSS支持的颜色");
    QString color_progress = QInputDialog::getText(this, "文本", "输入要添加颜色的内容，将会自动复制到剪切板。");
    QString color_text = "{{颜色|" + color_input + "|" + color_progress + "}}";
    QClipboard* clip_color = QApplication::clipboard();
    clip_color->setText(color_text);
}

void MainWindow::on_close_quick_insert_triggered()
{
    ui->quickinsert->setVisible(0);
}

void MainWindow::on_config_theme_triggered()
{
    theme *theme_cfg = new theme;
    theme_cfg->show();
}

void MainWindow::on_about_triggered()
{
    QString about_title="关于";
    QString about_content="原神BWIKI NPC图鉴编辑器 ver. 2.3.2\n这个项目是给原神BWiKi开发的，其目的为降低NPC图鉴编辑门槛，提供了一个编辑向导。\nby：屑机主\n许可：GPL v.2";
    QMessageBox::information(this, about_title,about_content, QMessageBox::Ok,QMessageBox::NoButton);
}

void MainWindow::on_about_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_changelog_triggered()
{
    QString about_title="关于";
    QString about_content="v.1.0 这个版本仅提供纯文本编辑（外加代码高亮），以及继承了一些额外小工具来帮助您快速在本地编辑NPC图鉴。\nv.1.1 更新界面、支持拖拽读取文件\nv.1.2 现在可以插入特殊字符了\nv.1.2.1-b 此版本允许您在安卓平板上快速编辑原神BWIKI的NPC图鉴\nv.2.2.3 此版本提供了更好的图形化界面";
    QMessageBox::information(this, about_title,about_content, QMessageBox::Ok,QMessageBox::NoButton);
}

void MainWindow::on_license_triggered()
{
    license *read_license = new license;
    read_license->show();
}

void MainWindow::on_update_check_triggered()
{
    QDesktopServices::openUrl(QUrl("https://wiki.biligame.com/ys/NPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3/%E6%9B%B4%E6%96%B0/2.3.2"));
}

void MainWindow::on_patch_avatar_false_clicked()
{
    //应用样式表
    ui->patch_avatar_false->setStyleSheet(ui_radio_selected);
    ui->patch_avatar_true->setStyleSheet(ui_radio_released);

    //更改字段
    npc_avatar_patch = "否";
}

void MainWindow::on_patch_avatar_true_clicked()
{
    //应用样式表
    ui->patch_avatar_true->setStyleSheet(ui_radio_selected);
    ui->patch_avatar_false->setStyleSheet(ui_radio_released);

    //更改字段
    npc_avatar_patch = "是";
}

void MainWindow::on_patch_avatar_intro_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wiki.biligame.com/ys/NPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3/%E4%BF%AE%E8%A1%A5%E5%A4%B4%E5%83%8F"));
}

void MainWindow::on_npc_country_current_option_unknown_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "未知";
}

void MainWindow::on_npc_country_current_option_mondstat_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "蒙德";
}

void MainWindow::on_npc_country_current_option_liyue_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "璃月";
}

void MainWindow::on_npc_country_current_option_inazuman_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "稻妻";
}

void MainWindow::on_npc_country_current_option_sumeru_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "须弥";
}

void MainWindow::on_npc_country_current_option_fortaine_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "枫丹";
}

void MainWindow::on_npc_country_current_option_nata_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_selected);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_released);

    //更改字段
    npc_current_country = "纳塔";
}

void MainWindow::on_npc_country_current_option_snezhnayan_clicked()
{
    //应用样式表
    ui->npc_country_current_option_unknown->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_mondstat->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_liyue->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_inazuman->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_sumeru->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_fortaine->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_nata->setStyleSheet(ui_radio_released);
    ui->npc_country_current_option_snezhnayan->setStyleSheet(ui_radio_selected);

    //更改字段
    npc_current_country = "至冬";
}

void MainWindow::on_conf_panel_two_clicked()
{
    theme *theme_cfg_n = new theme;
    theme_cfg_n->show();
}

