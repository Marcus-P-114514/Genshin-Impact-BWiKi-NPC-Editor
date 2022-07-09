#include "workingarea.h"
#include "ui_workingarea.h"
#include "license.h"
#include "code_highlight.h"
#include "QFocusEvent"
#include "QMessageBox"

WorkingArea::WorkingArea(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkingArea)
{
    ui->setupUi(this);

    /**
    //ui->toolbox->removeTab(0);
    ui->toolbox->removeTab(1);
    ui->toolbox->removeTab(2);
    ui->toolbox->setTabBarAutoHide(1);
    ui->toolbox->setCurrentIndex(0);

    **/

    //初始化文本
    ui->code_output->insertPlainText("{{NPC");
    ui->code_output->insertHtml("<br/>");

    //高亮语法
   // code_highlight *ch = new code_highlight;
    //code_highlight(ui->code_output->document());

    highlighter=new code_highlight (ui->code_output->document());
}

//定义变量
double overall_progress = 0.00;
QString npc_gift_exist_bool="yes";
QString npc_store_exist_bool="no";
QString experimental_function_npc_store_exchange_enabled="no";
QString npc_basic_info_completed = "no";
QString npc_name_completed = "no";
QString cache_exchanger_norm = "";
QString cache_price_norm = "";
QString write_known_store_status = "Not yet";

WorkingArea::~WorkingArea()
{
    delete ui;
}


void WorkingArea::on_show_license_triggered()
{
    License *license_show = new License;
    license_show->show();
}


void WorkingArea::on_write_basic_info_clicked()
{
    //写入NPC基本信息
    QString npc_name = ui->name_input->text();
    QString npc_name_output = "|名称="+npc_name;
    ui->code_output->insertPlainText(npc_name_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_nickname = ui->nickname_input->text();
    QString npc_nickname_output = "|称号="+npc_nickname;
    ui->code_output->insertPlainText(npc_nickname_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_gender = ui->gender_input->currentText();
    QString npc_gender_output = "|性别="+npc_gender;
    ui->code_output->insertPlainText(npc_gender_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_job = ui->job_input->text();
    QString npc_job_output = "|职业="+npc_job;
    ui->code_output->insertPlainText(npc_job_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_location = ui->location_input->text();
    QString npc_location_output = "|位置="+npc_location;
    ui->code_output->insertPlainText(npc_location_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_country = ui->country_input->currentText();
    QString npc_country_output = "|所属国家="+npc_country;
    ui->code_output->insertPlainText(npc_country_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_org = ui->org_input->text();
    QString npc_org_output = "|所属组织="+npc_org;
    ui->code_output->insertPlainText(npc_org_output);
    ui->code_output->insertHtml("<br/>");
    QString npc_system = ui->system_input->currentText();
    if (npc_system=="无"){
        ui->code_output->insertPlainText("|相关系统=无");
        ui->code_output->insertHtml("<br/>");
    }
    else{
        QString npc_system_output = "|相关系统=[["+npc_system+"]]";
        ui->code_output->insertPlainText(npc_system_output);
        ui->code_output->insertHtml("<br/>");
    }
    bool npc_gift_exist_trigged = ui->exist_dialog_judge->isChecked();
    if (npc_gift_exist_trigged==0){
        ui->code_output->insertPlainText("|对话赠礼=无");
        ui->code_output->insertHtml("<br/>");
    }
    else{
        QString npc_gift = ui->gift_name_input->text();
        QString npc_gift_num = ui->gift_num_input->text();
        QString npc_gift_output = "|对话赠礼={{NPC图标|"+npc_gift+"|"+npc_gift_num+"}}";
        ui->code_output->insertPlainText(npc_gift_output);
        ui->code_output->insertHtml("<br/>");
    }
    QString npc_version = ui->version_input->text();
    QString npc_version_output = "|实装版本="+npc_version;
    ui->code_output->insertPlainText(npc_version_output);
    ui->code_output->insertHtml("<br/>");
}



void WorkingArea::on_exist_dialog_judge_clicked(bool checked)
{
    bool npc_gift_exist_trig = ui->exist_dialog_judge->isChecked();
    if (npc_gift_exist_trig==0){
        ui->gift_name_input->setEnabled(0);
        ui->gift_num_input->setEnabled(0);
    }
    else{
        ui->gift_name_input->setEnabled(1);
        ui->gift_num_input->setEnabled(1);
    }
}





void WorkingArea::on_store_exist_normal_toggled(bool checked)
{
    bool npc_store_exist_trig = ui->store_exist_normal->isChecked();
    if  (npc_store_exist_trig==0){
        npc_store_exist_bool="no";
        ui->commodity_name_input->setEnabled(0);
        ui->min_sale_unit_input->setEnabled(0);
        ui->exchanger_norm_input->setEnabled(0);
        ui->price_norm_input->setEnabled(0);
        ui->limit_quantity_input->setEnabled(0);
        ui->refresh_time_input->setEnabled(0);
        ui->etc_limit_input->setEnabled(0);
        ui->store_write_and_enter->setEnabled(0);
    }
    else{
        npc_store_exist_bool="yes";
        ui->commodity_name_input->setEnabled(1);
        ui->min_sale_unit_input->setEnabled(1);
        ui->exchanger_norm_input->setEnabled(1);
        ui->price_norm_input->setEnabled(1);
        ui->limit_quantity_input->setEnabled(1);
        ui->refresh_time_input->setEnabled(1);
        ui->etc_limit_input->setEnabled(1);
        ui->store_write_and_enter->setEnabled(1);
    }
}

void WorkingArea::on_store_end_task_clicked()
{
    if  (npc_store_exist_bool=="no"){
        ui->code_output->insertPlainText("|存在商店=否");
        ui->code_output->insertHtml("<br/>");
    }
    else{
        if (write_known_store_status == "Not yet"){
            ui->code_output->insertPlainText("|存在商店=是");
            ui->code_output->insertHtml("<br/>");
            ui->code_output->insertPlainText("|商店内容=");
        }
        else{
            bool ok;
        }
        bool cache_mult_exchange_mod = ui->multi_mod_support_on->isChecked();
        if (cache_mult_exchange_mod == 0){
            QString commodity_cache = ui->commodity_name_input->text();
            QString cache_min_sale_unit = ui->min_sale_unit_input->text();
            QString cache_exchange_norm_input = ui->exchanger_norm_input->text();
            QString cache_price_input = ui->price_norm_input->text();
            QString cache_limit_quantity_input = ui->limit_quantity_input->text();
            QString cache_refresh_time_input = ui->refresh_time_input->text();
            QString cache_etc_limit_input = ui->etc_limit_input->text();
            QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_exchange_norm_input + "*" + cache_price_input + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input;
            ui->code_output->insertPlainText(cache_single_line_out_one);
            ui->code_output->insertHtml("<br/>");
            write_known_store_status = "Not yet"; //重置“是否已经写入存在商店”
        }
        else{
            QString cache_multi_exchange_one_input = ui->multi_exchange_one_input->text();
            QString cache_multi_exchange_two_input = ui->multi_exchange_two_input->text();
            QString cache_multi_exchange_three_input = ui->multi_exchange_three_input->text();
            QString cache_multi_exchange_four_input = ui->multi_price_four_input->text();
            QString cache_multi_price_one_input = ui->multi_price_one_input->text();
            QString cache_multi_price_two_input = ui->multi_price_two_input->text();
            QString cache_multi_price_three_input = ui->multi_price_three_input->text();
            QString cache_multi_price_four_input = ui->multi_price_four_input->text();
            if (cache_multi_exchange_one_input == ""){
                QMessageBox::StandardButton result = QMessageBox::critical(this, "严重错误", "您已经启用了「多交换物模式」，但您似乎将多交换物模式表格留空了，请从交换物1开始依次往下填写，不足4请留空对应序号。错误#114");
            }
            else{

                if (cache_multi_exchange_two_input == ""){
                    QMessageBox::StandardButton result = QMessageBox::critical(this, "严重错误", "您已经启用了「多交换物模式」，但您似乎仅提供了一种交换物信息，这种情况下请关闭「多交换物模式」且打开常规模式填写。如果您已经填入不止一个交换物，请检查您是否交换物1开始依次往下填写。错误#514");
                }
                else{
                    if (cache_multi_exchange_three_input == ""){
                        QString commodity_cache = ui->commodity_name_input->text();
                        QString cache_min_sale_unit = ui->min_sale_unit_input->text();
                        QString cache_limit_quantity_input = ui->limit_quantity_input->text();
                        QString cache_refresh_time_input = ui->refresh_time_input->text();
                        QString cache_etc_limit_input = ui->etc_limit_input->text();
                        QString cache_price_info = cache_multi_exchange_one_input + "*" + cache_multi_price_one_input + "、" + cache_multi_exchange_two_input + "*" + cache_multi_price_two_input;
                        QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_price_info + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input;
                        ui->code_output->insertPlainText(cache_single_line_out_one);
                        ui->code_output->insertHtml("<br/>");
                        write_known_store_status = "Not yet"; //重置“是否已经写入存在商店”
                    }
                    else{
                        if (cache_multi_exchange_four_input == ""){
                            QString commodity_cache = ui->commodity_name_input->text();
                            QString cache_min_sale_unit = ui->min_sale_unit_input->text();
                            QString cache_limit_quantity_input = ui->limit_quantity_input->text();
                            QString cache_refresh_time_input = ui->refresh_time_input->text();
                            QString cache_etc_limit_input = ui->etc_limit_input->text();
                            QString cache_price_info = cache_multi_exchange_one_input + "*" + cache_multi_price_one_input + "、" + cache_multi_exchange_two_input + "*" + cache_multi_price_two_input + "、" + cache_multi_exchange_three_input + "*" + cache_multi_price_three_input;
                            QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_price_info + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input;
                            ui->code_output->insertPlainText(cache_single_line_out_one);
                            ui->code_output->insertHtml("<br/>");
                            write_known_store_status = "Not yet"; //重置“是否已经写入存在商店”
                        }
                        else{
                            QString commodity_cache = ui->commodity_name_input->text();
                            QString cache_min_sale_unit = ui->min_sale_unit_input->text();
                            QString cache_limit_quantity_input = ui->limit_quantity_input->text();
                            QString cache_refresh_time_input = ui->refresh_time_input->text();
                            QString cache_etc_limit_input = ui->etc_limit_input->text();
                            QString cache_price_info = cache_multi_exchange_one_input + "*" + cache_multi_price_one_input + "、" + cache_multi_exchange_two_input + "*" + cache_multi_price_two_input + "、" + cache_multi_exchange_three_input + "*" + cache_multi_price_three_input + "、" + cache_multi_exchange_four_input + "*" + cache_multi_price_four_input;
                            QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_price_info + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input;
                            ui->code_output->insertPlainText(cache_single_line_out_one);
                            ui->code_output->insertHtml("<br/>");
                            write_known_store_status = "Not yet"; //重置“是否已经写入存在商店”
                        }
                    }

                }

            }
        }
    }
}





void WorkingArea::on_store_exist_normal_stateChanged(int arg1)
{

}


void WorkingArea::on_multi_mod_support_on_stateChanged(int arg1)
{
    bool special_store_mode_isenabled = ui->multi_mod_support_on->isChecked();
    if (special_store_mode_isenabled==0){
        ui->exchanger_norm_input->setText(cache_exchanger_norm);
        ui->price_norm_input->setText(cache_price_norm);
        ui->multi_exchange_one_input->setEnabled(0);
        ui->multi_price_one_input->setEnabled(0);
        ui->multi_exchange_two_input->setEnabled(0);
        ui->multi_price_two_input->setEnabled(0);
        ui->multi_exchange_three_input->setEnabled(0);
        ui->multi_price_three_input->setEnabled(0);
        ui->multi_exchange_four_input->setEnabled(0);
        ui->multi_price_four_input->setEnabled(0);
        ui->back_to_npc_store_normal_mode->setEnabled(0);
    }
    else{
        bool cache_store_exist = ui->store_exist_normal->isChecked();
        if (cache_store_exist == 0){
            QMessageBox::StandardButton result = QMessageBox::critical(this, "严重错误", "若要使用多交换物模式，需要该NPC存在商店");
            ui->multi_mod_support_on->setChecked(0);
        }
        else{
            QString cache_exchanger_norm_read = ui->exchanger_norm_input->text();
            cache_exchanger_norm = cache_exchanger_norm_read;
            QString cache_price_norm_read = ui->price_norm_input->text();
            cache_price_norm = cache_price_norm_read;
            ui->exchanger_norm_input->setText("请使用「多交换物模式」");
            ui->price_norm_input->setText("请使用「多交换物模式」");
            ui->multi_exchange_one_input->setEnabled(1);
            ui->multi_price_one_input->setEnabled(1);
            ui->multi_exchange_two_input->setEnabled(1);
            ui->multi_price_two_input->setEnabled(1);
            ui->multi_exchange_three_input->setEnabled(1);
            ui->multi_price_three_input->setEnabled(1);
            ui->multi_exchange_four_input->setEnabled(1);
            ui->multi_price_four_input->setEnabled(1);
            ui->back_to_npc_store_normal_mode->setEnabled(1);
        }
    }
}


void WorkingArea::on_store_write_and_enter_clicked()
{
    if (write_known_store_status == "Not yet"){
        ui->code_output->insertPlainText("|存在商店=是");
        ui->code_output->insertHtml("<br/>");
        ui->code_output->insertPlainText("|商店内容=");
        write_known_store_status = "written";
    }
    else{
        bool ok;
    }
    bool cache_mult_exchange_mod = ui->multi_mod_support_on->isChecked();
    if (cache_mult_exchange_mod == 0){
        QString commodity_cache = ui->commodity_name_input->text();
        QString cache_min_sale_unit = ui->min_sale_unit_input->text();
        QString cache_exchange_norm_input = ui->exchanger_norm_input->text();
        QString cache_price_input = ui->price_norm_input->text();
        QString cache_limit_quantity_input = ui->limit_quantity_input->text();
        QString cache_refresh_time_input = ui->refresh_time_input->text();
        QString cache_etc_limit_input = ui->etc_limit_input->text();
        QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_exchange_norm_input + "*" + cache_price_input + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input + "+";
        ui->code_output->insertPlainText(cache_single_line_out_one);
        ui->code_output->insertHtml("<br/>");
    }
    else{
        QString cache_multi_exchange_one_input = ui->multi_exchange_one_input->text();
        QString cache_multi_exchange_two_input = ui->multi_exchange_two_input->text();
        QString cache_multi_exchange_three_input = ui->multi_exchange_three_input->text();
        QString cache_multi_exchange_four_input = ui->multi_price_four_input->text();
        QString cache_multi_price_one_input = ui->multi_price_one_input->text();
        QString cache_multi_price_two_input = ui->multi_price_two_input->text();
        QString cache_multi_price_three_input = ui->multi_price_three_input->text();
        QString cache_multi_price_four_input = ui->multi_price_four_input->text();
        if (cache_multi_exchange_one_input == ""){
            QMessageBox::StandardButton result = QMessageBox::critical(this, "严重错误", "您已经启用了「多交换物模式」，但您似乎将多交换物模式表格留空了，请从交换物1开始依次往下填写，不足4请留空对应序号。错误#114");
        }
        else{

            if (cache_multi_exchange_two_input == ""){
                QMessageBox::StandardButton result = QMessageBox::critical(this, "严重错误", "您已经启用了「多交换物模式」，但您似乎仅提供了一种交换物信息，这种情况下请关闭「多交换物模式」且打开常规模式填写。如果您已经填入不止一个交换物，请检查您是否交换物1开始依次往下填写。错误#514");
            }
            else{
                if (cache_multi_exchange_three_input == ""){
                    QString commodity_cache = ui->commodity_name_input->text();
                    QString cache_min_sale_unit = ui->min_sale_unit_input->text();
                    QString cache_limit_quantity_input = ui->limit_quantity_input->text();
                    QString cache_refresh_time_input = ui->refresh_time_input->text();
                    QString cache_etc_limit_input = ui->etc_limit_input->text();
                    QString cache_price_info = cache_multi_exchange_one_input + "*" + cache_multi_price_one_input + "、" + cache_multi_exchange_two_input + "*" + cache_multi_price_two_input;
                    QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_price_info + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input + "+";
                    ui->code_output->insertPlainText(cache_single_line_out_one);
                    ui->code_output->insertHtml("<br/>");
                }
                else{
                    if (cache_multi_exchange_four_input == ""){
                        QString commodity_cache = ui->commodity_name_input->text();
                        QString cache_min_sale_unit = ui->min_sale_unit_input->text();
                        QString cache_limit_quantity_input = ui->limit_quantity_input->text();
                        QString cache_refresh_time_input = ui->refresh_time_input->text();
                        QString cache_etc_limit_input = ui->etc_limit_input->text();
                        QString cache_price_info = cache_multi_exchange_one_input + "*" + cache_multi_price_one_input + "、" + cache_multi_exchange_two_input + "*" + cache_multi_price_two_input + "、" + cache_multi_exchange_three_input + "*" + cache_multi_price_three_input;
                        QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_price_info + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input + "+";
                        ui->code_output->insertPlainText(cache_single_line_out_one);
                        ui->code_output->insertHtml("<br/>");
                    }
                    else{
                        QString commodity_cache = ui->commodity_name_input->text();
                        QString cache_min_sale_unit = ui->min_sale_unit_input->text();
                        QString cache_limit_quantity_input = ui->limit_quantity_input->text();
                        QString cache_refresh_time_input = ui->refresh_time_input->text();
                        QString cache_etc_limit_input = ui->etc_limit_input->text();
                        QString cache_price_info = cache_multi_exchange_one_input + "*" + cache_multi_price_one_input + "、" + cache_multi_exchange_two_input + "*" + cache_multi_price_two_input + "、" + cache_multi_exchange_three_input + "*" + cache_multi_price_three_input + "、" + cache_multi_exchange_four_input + "*" + cache_multi_price_four_input;
                        QString cache_single_line_out_one = commodity_cache + "*" + cache_min_sale_unit + "," + cache_price_info + "," + cache_limit_quantity_input + "," + cache_refresh_time_input + "," + cache_etc_limit_input + "+";
                        ui->code_output->insertPlainText(cache_single_line_out_one);
                        ui->code_output->insertHtml("<br/>");
                    }
                }

            }

        }
    }
}


void WorkingArea::on_back_to_npc_store_normal_mode_clicked()
{
    ui->npc_store_container->setCurrentIndex(0);
}

