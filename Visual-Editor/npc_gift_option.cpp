#include "npc_gift_option.h"
#include "ui_npc_gift_option.h"
#include "QSettings"
#include "QString"

int slot_commit_current;
QString commit_slot_write;
QString npc_gift_target_cache = "";

npc_gift_option::npc_gift_option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::npc_gift_option)
{
    ui->setupUi(this);

    QSettings *config_lck_npc_gift = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
    QString npc_gift_lck_check = config_lck_npc_gift -> value ( "verification/npc_gift").toString();
    if (npc_gift_lck_check == "yes") {
        //读取缓存目标
        QSettings *config_commit_id = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
        QString slot_commit_read = config_commit_id -> value ( "generate/npc_gift").toString();
        npc_gift_target_cache = "./commit/npc_gift/commit_" + slot_commit_read + ".commit";
        delete config_commit_id;
    }
    else {
        //处理缓存文件
        QSettings *config_commit_id = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
        QString slot_commit_read = config_commit_id -> value ( "generate/npc_gift").toString();
        if (slot_commit_read == "") { //文件不存在
            config_commit_id->setValue("generate/npc_gift", "1");
            slot_commit_current = 1;
            commit_slot_write = "1";
        }
        else {
            slot_commit_current = slot_commit_read.toInt();
            slot_commit_current = slot_commit_current + 1;
            commit_slot_write = QString::number(slot_commit_current);
            config_commit_id->setValue("generate/npc_gift", commit_slot_write);
        }
        npc_gift_target_cache = "./commit/npc_gift/commit_" + commit_slot_write + ".commit";
        delete config_commit_id;
    }
    delete config_lck_npc_gift;
}

npc_gift_option::~npc_gift_option()
{
    delete ui;
}

void npc_gift_option::on_npc_multi_insert_gift_clicked()
{
    QString npc_multi_gift_name_received = ui->npc_multi_gift->text();
    QString npc_multi_gift_amount_received = ui->npc_multi_amount->text();
    QString npc_gift_code_current = ui->gift_code_output->text();
    QString npc_multi_gift_current_line = npc_gift_code_current + "{{NPC图标|" + npc_multi_gift_name_received + "|" + npc_multi_gift_amount_received + "}}";
    ui->gift_code_output->setText(npc_multi_gift_current_line);
    ui->npc_multi_gift->clear();
    ui->npc_multi_amount->clear();
    QString npc_gift_multi_result = ui->gift_code_output->text();
    QSettings *config_npc_gift = new QSettings (npc_gift_target_cache, QSettings::IniFormat);
    config_npc_gift->setValue("npc_gift/current", npc_gift_multi_result);
    delete config_npc_gift;
    QSettings *config_lck_npc_gift = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
    config_lck_npc_gift->setValue("verification/npc_gift", "no");
    delete config_lck_npc_gift;
}

void npc_gift_option::on_npc_multi_clear_gift_clicked()
{
    ui->gift_code_output->clear();
}
