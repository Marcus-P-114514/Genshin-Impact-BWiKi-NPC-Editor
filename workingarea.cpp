#include "workingarea.h"
#include "ui_workingarea.h"
#include "license.h"
#include "code_highlight.h"
#include "QFocusEvent"

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
QString npc_gift_exist_bool="yes";
QString npc_store_exist_bool="no";
QString experimental_function_npc_store_exchange_enabled="no";

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
        ui->exchanger_norn_input->setEnabled(0);
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
        ui->exchanger_norn_input->setEnabled(1);
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
        ui->code_output->insertPlainText("|存在商店=是");
        ui->code_output->insertHtml("<br/>");
    }
}




