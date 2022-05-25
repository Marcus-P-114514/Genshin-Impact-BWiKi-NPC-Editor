#include "store.h"
#include "ui_store.h"
#include "store_edit_two.h"'

#include "QFile"
#include "QTextStream"

Store::Store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store)
{
    ui->setupUi(this);

    ui->store_code_output->insertPlainText("|存在商店=是");
    ui->store_code_output->insertHtml("<br/>");
}

Store::~Store()
{
    delete ui;
}

void Store::on_store_write_enter_clicked()
{
    QString commodity_name_input = ui->commodity_name_edit->text();
    QString min_sale_unit_input = ui->min_sale_unit_edit->text();
    QString currency_type_input = ui->commodity_name_edit->text();
    QString price_input = ui->price_edit->text();
    QString limit_quantity_input = ui->limited_quantity_edit->text();
    QString refresh_time_input = ui->refresh_time_edit->text();
    QString limit_input = ui->limit_edit->text();
    QString store_content_input = commodity_name_input + "*" + min_sale_unit_input + "," + currency_type_input + "*" + price_input + "," + limit_quantity_input + "," + refresh_time_input + "," + limit_input + "+";
    ui->store_code_output->insertPlainText(store_content_input);
    ui->store_code_output->insertHtml("<br/>");
}


void Store::on_no_store_clicked()
{
    ui->store_code_output->clear();
    ui->store_code_output->insertPlainText("|存在商店=否");
    QFile finish_store_page_without_store ("./cache/store_cache.npchandler");
    if (finish_store_page_without_store.open(QFile::WriteOnly|QFile::Text)){
        QTextStream finish_store_page_without_store_content (&finish_store_page_without_store);
        finish_store_page_without_store_content << ui->store_code_output->toPlainText();
    }
    this->hide();
}





void Store::on_write_last_line_clicked()
{
    QString commodity_name_input_fin = ui->commodity_name_edit->text();
    QString min_sale_unit_input_fin = ui->min_sale_unit_edit->text();
    QString currency_type_input_fin = ui->commodity_name_edit->text();
    QString price_input_fin = ui->price_edit->text();
    QString limit_quantity_input_fin = ui->limited_quantity_edit->text();
    QString refresh_time_input_fin = ui->refresh_time_edit->text();
    QString limit_input_fin = ui->limit_edit->text();
    QString store_content_input_fin = commodity_name_input_fin + "*" + min_sale_unit_input_fin + "," + currency_type_input_fin + "*" + price_input_fin + "," + limit_quantity_input_fin + "," + refresh_time_input_fin + "," + limit_input_fin;
    ui->store_code_output->insertPlainText(store_content_input_fin);
    ui->store_code_output->insertHtml("<br/>");
}


void Store::on_multi_exchange_opener_clicked()
{
    Store_Edit_Two *mult_exchange_open_two = new Store_Edit_Two;
    mult_exchange_open_two->show();
}

