#include "npc_store_multi_exchange.h"
#include "ui_npc_store_multi_exchange.h"
#include "QSettings"

QString npc_store_target_cache;
int slot_commit_current_store;
QString commit_slot_write_store;
QString npc_store_multi_exchanger_received_1;
QString npc_store_multi_price_received_1;
QString npc_store_multi_exchanger_received_2;
QString npc_store_multi_price_received_2;
QString npc_store_multi_exchanger_received_3;
QString npc_store_multi_price_received_3;
QString npc_store_multi_exchanger_received_4;
QString npc_store_multi_price_received_4;
QString npc_store_multi_exchanger_received_5;
QString npc_store_multi_price_received_5;
QString npc_store_multi_price_out;

npc_store_multi_exchange::npc_store_multi_exchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::npc_store_multi_exchange)
{
    ui->setupUi(this);

    QSettings *config_lck_npc_store = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
    QString npc_store_lck_check = config_lck_npc_store -> value ( "verification/npc_store").toString();
    if (npc_store_lck_check == "yes") {
        //读取缓存目标
        QSettings *config_commit_id = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
        QString slot_commit_read = config_commit_id -> value ( "generate/npc_store").toString();
        npc_store_target_cache = "./commit/npc_store/commit_" + slot_commit_read + ".commit";
        delete config_commit_id;
    }
    else {
        //处理缓存文件
        QSettings *config_commit_id = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
        QString slot_commit_read = config_commit_id -> value ( "generate/npc_store").toString();
        if (slot_commit_read == "") { //文件不存在
            config_commit_id->setValue("generate/npc_store", "1");
            slot_commit_current_store = 1;
            commit_slot_write_store = "1";
        }
        else {
            slot_commit_current_store = slot_commit_read.toInt();
            slot_commit_current_store = slot_commit_current_store + 1;
            commit_slot_write_store = QString::number(slot_commit_current_store);
            config_commit_id->setValue("generate/npc_store", commit_slot_write_store);
        }
        npc_store_target_cache = "./commit/npc_store/commit_" + commit_slot_write_store + ".commit";
        delete config_commit_id;
    }
    delete config_lck_npc_store;
}

void npc_store_multi_exchange::update_multi_exchange() {
    npc_store_multi_exchanger_received_1 = ui->npc_store_multi_exchanger_input_1->text();
    npc_store_multi_exchanger_received_2 = ui->npc_store_multi_exchanger_input_2->text();
    npc_store_multi_exchanger_received_3 = ui->npc_store_multi_exchanger_input_3->text();
    npc_store_multi_exchanger_received_4 = ui->npc_store_multi_exchanger_input_4->text();
    npc_store_multi_exchanger_received_5 = ui->npc_store_multi_exchanger_input_5->text();

    npc_store_multi_price_received_1 = ui->npt_store_multi_price_input_1->text();
    npc_store_multi_price_received_2 = ui->npt_store_multi_price_input_2->text();
    npc_store_multi_price_received_3 = ui->npt_store_multi_price_input_3->text();
    npc_store_multi_price_received_4 = ui->npt_store_multi_price_input_4->text();
    npc_store_multi_price_received_5 = ui->npt_store_multi_price_input_5->text();

    if (npc_store_multi_exchanger_received_2 == "") {
        npc_store_multi_price_out = npc_store_multi_exchanger_received_1 + "*" + npc_store_multi_price_received_1;
    }
    else {
        if (npc_store_multi_exchanger_received_3 == "") {
            npc_store_multi_price_out = npc_store_multi_exchanger_received_1 + "*" + npc_store_multi_price_received_1 + "、" + npc_store_multi_exchanger_received_2 + "*" + npc_store_multi_price_received_2;
        }
        else {
            if (npc_store_multi_exchanger_received_4 == "") {
                npc_store_multi_price_out = npc_store_multi_exchanger_received_1 + "*" + npc_store_multi_price_received_1 + "、" + npc_store_multi_exchanger_received_2 + "*" + npc_store_multi_price_received_2 + "、" + npc_store_multi_exchanger_received_3 + "*" + npc_store_multi_price_received_3;
            }
            else {
                if (npc_store_multi_exchanger_received_5 == "") {
                    npc_store_multi_price_out = npc_store_multi_exchanger_received_1 + "*" + npc_store_multi_price_received_1 + "、" + npc_store_multi_exchanger_received_2 + "*" + npc_store_multi_price_received_2 + "、" + npc_store_multi_exchanger_received_3 + "*" + npc_store_multi_price_received_3 + "、" + npc_store_multi_exchanger_received_4 + "*" + npc_store_multi_price_received_4;
                }
                else {
                    npc_store_multi_price_out = npc_store_multi_exchanger_received_1 + "*" + npc_store_multi_price_received_1 + "、" + npc_store_multi_exchanger_received_2 + "*" + npc_store_multi_price_received_2 + "、" + npc_store_multi_exchanger_received_3 + "*" + npc_store_multi_price_received_3 + "、" + npc_store_multi_exchanger_received_4 + "*" + npc_store_multi_price_received_4 + "、" + npc_store_multi_exchanger_received_5 + "*" + npc_store_multi_price_received_5;
                }
            }
        }
    }
    ui->npc_store_multi_exchange_code_out->clear();
    ui->npc_store_multi_exchange_code_out->setText(npc_store_multi_price_out);


}

npc_store_multi_exchange::~npc_store_multi_exchange()
{
    delete ui;
}

void npc_store_multi_exchange::on_npc_store_multi_exchanger_input_1_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npt_store_multi_price_input_1_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npc_store_multi_exchanger_input_2_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npt_store_multi_price_input_2_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npc_store_multi_exchanger_input_3_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npt_store_multi_price_input_3_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npc_store_multi_exchanger_input_4_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npt_store_multi_price_input_4_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npc_store_multi_exchanger_input_5_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npt_store_multi_price_input_5_textChanged(const QString &arg1)
{
    update_multi_exchange();
}

void npc_store_multi_exchange::on_npc_gift_multi_price_submit_clicked()
{
    QSettings *config_npc_store = new QSettings (npc_store_target_cache, QSettings::IniFormat);
    config_npc_store->setValue("npc_store/current", npc_store_multi_price_out);
    delete config_npc_store;
    QSettings *config_lck_npc_store = new QSettings ( "./config/commits.conf", QSettings::IniFormat);
    config_lck_npc_store->setValue("verification/npc_store", "no");
    delete config_lck_npc_store;
    QWidget::close();
}
