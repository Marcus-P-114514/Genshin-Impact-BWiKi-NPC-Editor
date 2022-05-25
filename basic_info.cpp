#include "basic_info.h"
#include "ui_basic_info.h"
#include "QSettings"

Basic_Info::Basic_Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Basic_Info)
{
    ui->setupUi(this);
    QSettings *init_value = new QSettings("./cache/cache.ini", QSettings::IniFormat);
    QString init_name = init_value->value("basic/name").toString();
    ui->name_edit->setText(init_name);
    QString init_nickname = init_value->value("basic/nickname").toString();
    ui->nickname_edit->setText(init_nickname);
    QString init_gender = init_value->value("basic/gender").toString();
    ui->gender_edit->setCurrentText(init_gender);
    QString init_job = init_value->value("basic/job").toString();
    ui->job_edit->setText(init_job);
    QString init_location = init_value->value("basic/location").toString();
    ui->location_edit->setText(init_location);
    QString init_country = init_value->value("basic/country").toString();
    ui->country_edit->setCurrentText(init_country);
    QString init_gift_name = init_value->value("basic/gift_content").toString();
    ui->gift_name_edit->setText(init_gift_name);
    QString init_gift_num = init_value->value("basic/gift_num").toString();
    ui->gift_num_edit->setText(init_gift_num);
    QString init_gift_exist_bool = init_value->value("basic/gift_exist").toString();
    if (init_gift_exist_bool=="无"){
        ui->gift_name_label->setDisabled(1);
        ui->gift_name_edit->setDisabled(1);
        ui->gift_num_label->setDisabled(1);
        ui->gift_num_edit->setDisabled(1);
        ui->gift_exist->setChecked(1);
    }
    else{
        ui->gift_name_label->setDisabled(0);
        ui->gift_name_edit->setDisabled(0);
        ui->gift_num_label->setDisabled(0);
        ui->gift_num_edit->setDisabled(0);
        ui->gift_exist->setChecked(1);
    }
    QString init_version = init_value->value("basic/version").toString();
    ui->version_edit->setCurrentText(init_version);
    QString init_org = init_value->value("basic/org").toString();
    ui->org_edit->setText(init_org);
    QString init_system = init_value->value("basic/system").toString();
    ui->system_edit->setCurrentText(init_system);
    delete init_value;
}


Basic_Info::~Basic_Info()
{
    delete ui;
}





void Basic_Info::on_gift_exist_clicked()
{
    bool is_gift_avaliable = ui->gift_exist->isChecked();
    if (is_gift_avaliable==0){
        ui->gift_name_label->setDisabled(1);
        ui->gift_name_edit->setDisabled(1);
        ui->gift_num_label->setDisabled(1);
        ui->gift_num_edit->setDisabled(1);

    }
    else{
        ui->gift_name_label->setDisabled(0);
        ui->gift_name_edit->setDisabled(0);
        ui->gift_num_label->setDisabled(0);
        ui->gift_num_edit->setDisabled(0);
    }
}


void Basic_Info::on_update_basic_info_clicked()
{
    QSettings *write_basic_info = new QSettings("./cache/cache.ini", QSettings::IniFormat);
    QString npc_name_input = ui->name_edit->text();
    write_basic_info->setValue("basic/name", npc_name_input);
    QString npc_nickname_input = ui->nickname_edit->text();
    write_basic_info->setValue("basic/nickname", npc_nickname_input);
    QString npc_gender_input = ui->gender_edit->currentText();
    write_basic_info->setValue("basic/gender", npc_gender_input);
    QString npc_job_input = ui->job_edit->text();
    write_basic_info->setValue("basic/job", npc_job_input);
    QString npc_location_input = ui->location_edit->text();
    write_basic_info->setValue("basic/location", npc_location_input);
    QString npc_country_input = ui->country_edit->currentText();
    write_basic_info->setValue("basic/country", npc_country_input);
    bool npc_gift_exist_input_for_process = ui->gift_exist->isChecked();
    if (npc_gift_exist_input_for_process==0){
        write_basic_info->setValue("basic/gift_exist", "无");
    }
    else{
        write_basic_info->setValue("basic/gift_exist", "存在");
        QString gift_content_input = ui->gift_name_edit->text();
        write_basic_info->setValue("basic/gift_content", gift_content_input);
        QString gift_num_input = ui->gift_num_edit->text();
        write_basic_info->setValue("basic/gift_num", gift_num_input);
    }
    QString npc_version_input = ui->version_edit->currentText();
    write_basic_info->setValue("basic/version", npc_version_input);
    QString npc_org_input = ui->org_edit->text();
    write_basic_info->setValue("basic/org", npc_org_input);
    QString npc_system_input_for_progress = ui->system_edit->currentText();
    if (npc_system_input_for_progress=="无"){
        write_basic_info->setValue("basic/system", "无");
    }
    else{
        QString npc_system_input = "[["+npc_system_input_for_progress+"]]";
        write_basic_info->setValue("basic/system", npc_system_input);
    }
    delete write_basic_info;
    this->hide();
}

