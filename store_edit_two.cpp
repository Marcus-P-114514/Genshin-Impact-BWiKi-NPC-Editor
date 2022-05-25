#include "store_edit_two.h"
#include "ui_store_edit_two.h"

#include "QDialog"
#include "QMessageBox"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"

Store_Edit_Two::Store_Edit_Two(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Store_Edit_Two)
{
    ui->setupUi(this);
}

Store_Edit_Two::~Store_Edit_Two()
{
    delete ui;
}

void Store_Edit_Two::on_write_multi_price_clicked()
{
    QString exchange_one = ui->exchange_edit_1->text();
    QString exchange_two = ui->exchange_edit_2->text();
    QString exchange_three = ui->exchange_edit_3->text();
    QString exchange_four = ui->exchange_edit_4->text();
    QString exchange_five = ui->exchange_edit_5->text();

    QString price_one = ui->price_edit_1->text();
    QString price_two = ui->price_edit_2->text();
    QString price_three = ui->price_edit_3->text();
    QString price_four = ui->price_edit_4->text();
    QString price_five = ui->price_edit_5->text();

    if (exchange_one==""){
        QMessageBox::critical(this, tr("严重错误！"), tr("要使用本模板，请至少填满两个槽位。\n关闭此对话框以继续填写。"));
    }
    else{
        if (exchange_three==""){
            QString store_edit_two_out = exchange_one + "*" + price_one + "、" + exchange_two + "*" + price_two;
            QFile save_cache_for_store_two_one ("./cache/store_two.npceditor");
            if (save_cache_for_store_two_one.open(QFile::WriteOnly|QFile::Text)){
                QTextStream changes_to_be_saved_from_store_two_one (&save_cache_for_store_two_one);
                changes_to_be_saved_from_store_two_one << store_edit_two_out;
            }
        }
        else{
            if (exchange_four==""){
                QString store_edit_two_out = exchange_one + "*" + price_one + "、" + exchange_two + "*" + price_two + "、" + exchange_three + "*" + price_three;
                QFile save_cache_for_store_two_two ("./cache/store_two.npceditor");
                if (save_cache_for_store_two_two.open(QFile::WriteOnly|QFile::Text)){
                    QTextStream changes_to_be_saved_from_store_two_two (&save_cache_for_store_two_two);
                    changes_to_be_saved_from_store_two_two << store_edit_two_out;
                }
            }
            else{
                if (exchange_five==""){
                    QString store_edit_two_out = exchange_one + "*" + price_one + "、" + exchange_two + "*" + price_two + "、" + exchange_three + "*" + price_three + "、" + exchange_four + "*" + price_four;
                    QFile save_cache_for_store_two_three ("./cache/store_two.npceditor");
                    if (save_cache_for_store_two_three.open(QFile::WriteOnly|QFile::Text)){
                        QTextStream changes_to_be_saved_from_store_two_three (&save_cache_for_store_two_three);
                        changes_to_be_saved_from_store_two_three << store_edit_two_out;
                    }
                }
                else{
                    QString store_edit_two_out = exchange_one + "*" + price_one + "、" + exchange_two + "*" + price_two + "、" + exchange_three + "*" + price_three + "、" + exchange_four + "*" + price_four + "、" + exchange_five + "*" + price_five;
                    QFile save_cache_for_store_two_four ("./cache/store_two.npceditor");
                    if (save_cache_for_store_two_four.open(QFile::WriteOnly|QFile::Text)){
                        QTextStream changes_to_be_saved_from_store_two_four (&save_cache_for_store_two_four);
                        changes_to_be_saved_from_store_two_four << store_edit_two_out;
                    }
                }
            }
        }
    }
}

