#include "store.h"
#include "ui_store.h"
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
}

