#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QDialog"
#include "QMessageBox"
#include "QInputDialog"
#include "QDesktopServices"
#include "QUrl"
#include "QSettings"

#include "basic_info.h"
#include "store.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MainWindow *mw;
    //mw.setWindowTitle("无标题 - NPC图鉴可视化编辑工具 第二版");
    ui->working_paper->insertHtml("{{面包屑|NPC图鉴}}");
    ui->working_paper->insertHtml("<br/>");
    ui->working_paper->insertHtml("{{NPC");
    ui->working_paper->insertHtml("<br/>");
}

//定义的变量
QString file_name_and_path_for_save="";
QString placeholder_if_cannot_return="Lorem ipsum";
bool changes_saved=1;   //1=未变更/已保存；0=已变更，未保存
QString current_file_name_for_read="";
QString npc_name="";

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_npc_file_triggered()
{

}


void MainWindow::on_open_pain_text_triggered()
{
    QString read_pain_text_default_path="%HOME%/";
    QString read_pain_text_from_target = QFileDialog::getOpenFileName(this, tr("Open NPC Dialog"), read_pain_text_default_path);
    file_name_and_path_for_save=read_pain_text_from_target;
    QFile target_file(file_name_and_path_for_save);
    if (!target_file.open(QIODevice::ReadOnly | QIODevice::Text))
            placeholder_if_cannot_return="Returned false";
    ui->working_paper->setText(target_file.readAll());
    target_file.close();
}


void MainWindow::on_create_file_triggered()
{
    if (changes_saved==0){
        QString dlgTitle="文件被修改";
           QString strInfo="似乎您还没有保存您最新的编辑，请问是否要返回保存？\n如果您需要返回并保存，请点击Yes\n如果您要放弃您所作出的更改，请点击No";
           QMessageBox::StandardButton user_action_file_not_saved;//返回选择的按钮
           user_action_file_not_saved=QMessageBox::question(this, "文件被修改", "似乎您还没有保存您最新的编辑，请问是否要返回保存？\n如果您需要返回并保存，请点击Yes\n如果您要放弃您所作出的更改，请点击No",
                             QMessageBox::Yes|QMessageBox::No,
                             QMessageBox::NoButton);
           if (user_action_file_not_saved==QMessageBox::Yes)
               placeholder_if_cannot_return="Returned true";
           else if(user_action_file_not_saved==QMessageBox::No)
               ui->working_paper->clear();
               ui->working_paper->insertHtml("{{面包屑|NPC图鉴}}");
               ui->working_paper->insertHtml("<br/>");
               ui->working_paper->insertHtml("{{NPC");
               ui->working_paper->insertHtml("<br/>");
    }
    else{
        ui->working_paper->clear();
        changes_saved=1;
    }
    QString npc_name="";
}


void MainWindow::on_working_paper_textChanged()
{
    changes_saved=0;
}


void MainWindow::on_save_file_triggered()
{
    if (file_name_and_path_for_save==""){
        file_name_and_path_for_save=QFileDialog::getSaveFileName(this, tr("Save As..."), "", tr("NPC Info (*.npc *.txt *.*)"));
        QFile save_file_for_first_time (file_name_and_path_for_save);
        if (save_file_for_first_time.open(QFile::WriteOnly|QFile::Text)){
            QTextStream to_be_saved_from_save_section (&save_file_for_first_time);
            to_be_saved_from_save_section << ui->working_paper->toPlainText();
        }
        changes_saved=1;

    }
    else{
        QFile save_target_from_section_save (file_name_and_path_for_save);
        if (save_target_from_section_save.open(QFile::WriteOnly|QFile::Text)){
            QTextStream changes_to_be_saved_from_save_section (&save_target_from_section_save);
            changes_to_be_saved_from_save_section << ui->working_paper->toPlainText();
        }
    }
    changes_saved=1;

}


void MainWindow::on_save_as_triggered()
{
    file_name_and_path_for_save=QFileDialog::getSaveFileName(this, tr("Save As..."), "", tr("NPC Info (*.npc *.txt *.*)"));
    QFile save_file_as_another (file_name_and_path_for_save);
    if (save_file_as_another.open(QFile::WriteOnly|QFile::Text)){
        QTextStream to_be_saved_from_save_as_section (&save_file_as_another);
        to_be_saved_from_save_as_section << ui->working_paper->toPlainText();
    }
    changes_saved=1;
}


void MainWindow::on_upload_avatar_triggered()
{
    if (npc_name==""){
            QLineEdit::EchoMode npc_name_input_from_upload_interface_avatar=QLineEdit::Normal;
            bool ok=false;
            QString npc_name_entered_from_upload_interface_avatar = QInputDialog::getText(this, "发现问题","似乎您还没有指定NPC姓名，要开始，请指定NPC姓名\n如果您刚刚在“NPC基本信息”窗口中输入完毕，请先按下更新->刷新缓存\n请在一会上传.png格式的文件\n这是另一条提示：您需要在默认浏览器中登录BWIKI", npc_name_input_from_upload_interface_avatar, "例：黑田", &ok);
            if (ok && !npc_name_entered_from_upload_interface_avatar.isEmpty()){
                npc_name=npc_name_entered_from_upload_interface_avatar;
                QString npc_avatar_upload_adress_no_name="https://wiki.biligame.com/ys/"+npc_name+".png";
                QDesktopServices::openUrl(QUrl(npc_avatar_upload_adress_no_name));

                QSettings *write_name = new QSettings("./cache/cache.ini", QSettings::IniFormat);
                write_name->setValue("basic/name",npc_name);
                delete write_name;
            }
    }
    else{
        QString npc_avatar_upload_adress="https://wiki.biligame.com/ys/"+npc_name+".png";
        QDesktopServices::openUrl(QUrl(npc_avatar_upload_adress));
    }
}


void MainWindow::on_upload_model_triggered()
{
    if (npc_name==""){
            QLineEdit::EchoMode npc_name_input_from_upload_interface_model=QLineEdit::Normal;
            bool ok=false;
            QString npc_name_entered_from_upload_interface_model = QInputDialog::getText(this, "发现问题","似乎您还没有指定NPC姓名，要开始，请指定NPC姓名\n如果您刚刚在“NPC基本信息”窗口中输入完毕，请先按下更新->刷新缓存\n请在一会上传.png格式的文件\n这是另一条提示：您需要在默认浏览器中登录BWIKI", npc_name_input_from_upload_interface_model, "例：黑田", &ok);
            if (ok && !npc_name_entered_from_upload_interface_model.isEmpty()){
                npc_name=npc_name_entered_from_upload_interface_model;
                QString npc_model_upload_adress_no_name="https://wiki.biligame.com/ys/"+npc_name+"建模.png";
                QDesktopServices::openUrl(QUrl(npc_model_upload_adress_no_name));

                QSettings *write_name = new QSettings("./cache/cache.ini", QSettings::IniFormat);
                write_name->setValue("basic/name",npc_name);
                delete write_name;
            }
    }
    else{
        QString npc_model_upload_adress="https://wiki.biligame.com/ys/"+npc_name+"建模.png";
        QDesktopServices::openUrl(QUrl(npc_model_upload_adress));
    }
}


void MainWindow::on_upload_location_triggered()
{
    if (npc_name==""){
            QLineEdit::EchoMode npc_name_input_from_upload_interface_location=QLineEdit::Normal;
            bool ok=false;
            QString npc_name_entered_from_upload_interface_location = QInputDialog::getText(this, "发现问题","似乎您还没有指定NPC姓名，要开始，请指定NPC姓名\n如果您刚刚在“NPC基本信息”窗口中输入完毕，请先按下更新->刷新缓存\n请在一会上传.png格式的文件\n这是另一条提示：您需要在默认浏览器中登录BWIKI", npc_name_input_from_upload_interface_location, "例：黑田", &ok);
            if (ok && !npc_name_entered_from_upload_interface_location.isEmpty()){
                npc_name=npc_name_entered_from_upload_interface_location;
                QString npc_model_upload_location_no_name="https://wiki.biligame.com/ys/"+npc_name+"位置.png";
                QDesktopServices::openUrl(QUrl(npc_model_upload_location_no_name));

                QSettings *write_name = new QSettings("./cache/cache.ini", QSettings::IniFormat);
                write_name->setValue("basic/name",npc_name);
                delete write_name;
            }
    }
    else{
        QString npc_location_upload_adress="https://wiki.biligame.com/ys/"+npc_name+"位置.png";
        QDesktopServices::openUrl(QUrl(npc_location_upload_adress));
    }
}


void MainWindow::on_genshin_map_triggered()
{
    QDesktopServices::openUrl(QUrl("https://wiki.biligame.com/ys/原神地图工具_全地标位置点"));
}


void MainWindow::on_npc_basic_info_triggered()
{
    Basic_Info *basic_info = new Basic_Info;
    basic_info->show();
}


void MainWindow::on_refresh_basic_info_triggered()
{
    changes_saved=0;

    QSettings *read_basic_info = new QSettings("./cache/cache.ini", QSettings::IniFormat);
    QString npc_name_final_one = read_basic_info->value("basic/name").toString();
    ui->working_paper->insertPlainText("|名称=");
    ui->working_paper->insertPlainText(npc_name_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_nickname_final_one = read_basic_info->value("basic/nickname").toString();
    ui->working_paper->insertPlainText("|称号=");
    ui->working_paper->insertPlainText(npc_nickname_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_gender_final_one = read_basic_info->value("basic/gender").toString();
    ui->working_paper->insertPlainText("|性别=");
    ui->working_paper->insertPlainText(npc_gender_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_job_final_one = read_basic_info->value("basic/job").toString();
    ui->working_paper->insertPlainText("|职业=");
    ui->working_paper->insertPlainText(npc_job_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_location_final_one = read_basic_info->value("basic/location").toString();
    ui->working_paper->insertPlainText("|位置=");
    ui->working_paper->insertPlainText(npc_location_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_country_final_one = read_basic_info->value("basic/country").toString();
    ui->working_paper->insertPlainText("|所属国家=");
    ui->working_paper->insertPlainText(npc_country_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_if_gift_exist_read = read_basic_info->value("basic/gift_exist").toString();
    if (npc_if_gift_exist_read=="无"){
        ui->working_paper->insertPlainText("|对话赠礼=无");
        ui->working_paper->insertHtml("<br/>");
    }
    else{
        QString npc_gift_final_one = read_basic_info->value("basic/gift_content").toString();
        QString npc_gift_num_final_one = read_basic_info->value("basic/gift_num").toString();
        QString npc_gift_status_final_one = "{{图标|"+npc_gift_final_one+"|"+npc_gift_num_final_one+"}}";
        ui->working_paper->insertPlainText(npc_gift_status_final_one);
        ui->working_paper->insertHtml("<br/>");

    }
    QString npc_version_final_one = read_basic_info->value("basic/version").toString();
    ui->working_paper->insertPlainText("|实装版本=");
    ui->working_paper->insertPlainText(npc_version_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_org_final_one = read_basic_info->value("basic/org").toString();
    ui->working_paper->insertPlainText("|所属组织=");
    ui->working_paper->insertPlainText(npc_org_final_one);
    ui->working_paper->insertHtml("<br/>");
    QString npc_system_final_one = read_basic_info->value("basic/system").toString();
    ui->working_paper->insertPlainText("|相关系统=");
    ui->working_paper->insertPlainText(npc_system_final_one);
    ui->working_paper->insertHtml("<br/>");
}


void MainWindow::on_edit_npc_store_content_triggered()
{
    Store *store_edit = new Store;
    store_edit->show();
}

