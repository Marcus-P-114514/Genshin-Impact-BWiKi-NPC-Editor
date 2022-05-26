#include "store.h"
#include "ui_store.h"
#include "QFile"
#include "QTextStream"
#include "store_edit_two.h"

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);

    ui->store_code_output->insertPlainText("|存在商店=是");
    ui->store_code_output->insertHtml("<br/>");
}

QString use_this_if_returned_nothing_for_store = "";

Store::~Store()
{
    delete ui;
}

void Store::on_store_write_enter_clicked()
{
    QString commodity_name_input = ui->commodity_name_edit->text();
    QString min_sale_unit_input = ui->min_sale_unit_edit->text();
    QString currency_input = ui->currency_edit->text();
    QString price_input = ui->price_edit->text();
    QString limit_quantity_input = ui->limited_quantity_edit->text();
    QString refresh_time_input = ui->refresh_time_edit->text();
    QString limit_input = ui->limit_edit->text();

    QString code_output_stoe_one = commodity_name_input + "*" + min_sale_unit_input + "," + currency_input + "*" + price_input + "," + limit_quantity_input + "," + refresh_time_input + "," + limit_input + "+";
    ui->store_code_output->insertPlainText(code_output_stoe_one);
    ui->store_code_output->insertHtml("<br/>");

    ui->commodity_name_edit->setText("");
    ui->min_sale_unit_edit->setText("");
    ui->currency_edit->setText("");
    ui->price_edit->setText("");
    ui->limited_quantity_edit->setText("");
    ui->refresh_time_edit->setText("");
    ui->limit_edit->setText("");

    QFile clear_store_cache_one ("./cache/store_two.npchandler");
    if (clear_store_cache_one.open(QFile::WriteOnly|QFile::Text)){
        QTextStream wipe_cache_store_one (&clear_store_cache_one);
        wipe_cache_store_one << "";
    }

    ui->currency_edit->setDisabled(0);
    ui->price_edit->setDisabled(0);

}


void Store::on_no_store_clicked()
{
    ui->store_code_output->clear();
    ui->store_code_output->insertPlainText("|存在商店=否");
    QFile finish_store_page_without_store ("./cache/store_cache.npchandler");
    if (finish_store_page_without_store.open(QFile::WriteOnly|QFile::Text)){
        QTextStream finish_store_page_without_store_content (&finish_store_page_without_store);
        finish_store_page_without_store_content << ui->store_code_output->toPlainText();
        this->hide();
    }
}


void Store::on_write_last_line_clicked()
{
    QString commodity_name_input_fin = ui->commodity_name_edit->text();
    QString min_sale_unit_input_fin = ui->min_sale_unit_edit->text();
    QString currency_input_fin = ui->currency_edit->text();
    QString price_input_fin = ui->price_edit->text();
    QString limit_quantity_input_fin = ui->limited_quantity_edit->text();
    QString refresh_time_input_fin = ui->refresh_time_edit->text();
    QString limit_input_fin = ui->limit_edit->text();

    QString code_output_stoe_two = commodity_name_input_fin + "*" + min_sale_unit_input_fin + "," + currency_input_fin + "*" + price_input_fin + "," + limit_quantity_input_fin + "," + refresh_time_input_fin + "," + limit_input_fin;
    ui->store_code_output->insertPlainText(code_output_stoe_two);
    ui->store_code_output->insertHtml("<br/>");

    ui->commodity_name_edit->setText("");
    ui->min_sale_unit_edit->setText("");
    ui->currency_edit->setText("");
    ui->price_edit->setText("");
    ui->limited_quantity_edit->setText("");
    ui->refresh_time_edit->setText("");
    ui->limit_edit->setText("");

    QFile clear_store_cache_two ("./cache/store_two.npchandler");
    if (clear_store_cache_two.open(QFile::WriteOnly|QFile::Text)){
        QTextStream wipe_cache_store_two (&clear_store_cache_two);
        wipe_cache_store_two << "";
    }

    ui->currency_edit->setDisabled(0);
    ui->price_edit->setDisabled(0);
}


void Store::on_multi_exchange_opener_clicked()
{
    ui->currency_edit->setText("把特殊模板插入到");
    ui->price_edit->setText("这里");
    ui->currency_edit->setDisabled(1);
    ui->price_edit->setDisabled(1);
    Store_Edit_Two *store_edit_two_open = new Store_Edit_Two;
    store_edit_two_open->show();
}





void Store::on_clear_clicked()
{
    ui->store_code_output->clear();
    ui->currency_edit->setDisabled(0);
    ui->price_edit->setDisabled(0);

    ui->store_code_output->insertPlainText("|存在商店=是");
    ui->store_code_output->insertHtml("<br/>");
}


void Store::on_insert_cache_two_clicked()
{
    QFile target_file_insert_cache_two ("./cache/store_two.npchandler");
    if (!target_file_insert_cache_two.open(QIODevice::ReadOnly | QIODevice::Text))
            use_this_if_returned_nothing_for_store = "Ok";
    ui->store_code_output->insertPlainText (target_file_insert_cache_two.readAll());
    target_file_insert_cache_two.close();

    ui->currency_edit->setDisabled(0);
    ui->price_edit->setDisabled(0);
}


void Store::on_update_store_clicked()
{
    QFile update_store_info ("./cache/store_cache.npchandler");
    if (update_store_info.open(QFile::WriteOnly|QFile::Text)){
        QTextStream write_store_cache (&update_store_info);
        write_store_cache << ui->store_code_output->toPlainText();
    }
    this->hide();
}

