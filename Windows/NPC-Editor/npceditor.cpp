#include "npceditor.h"
#include "ui_npceditor.h"
#include "code_highlight.h"
#include "QFocusEvent"
#include "QMessageBox"
#include "QFile"
#include "QDomDocument"
#include "QSettings"
#include "QDir"
#include "QDomDocument"
#include "QFileDialog"


QString version = "1.0";
int read_progress = 0;
QString filepath="";
int saveprogress = 0;
int save_emptylinenum = 0;

NPCEditor::NPCEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NPCEditor)
{
    ui->setupUi(this);
    //解决背景为白色时菜单栏选中字体问题
    this->setStyleSheet("QMenu::item:selected{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd");

    //应用高亮
    highlighter=new code_highlight (ui->code_preview->document());

    //窗体标题
    setWindowTitle("无标题 - 原神BWIKI NPC图鉴第三方编辑工具");
}

NPCEditor::~NPCEditor()
{
    delete ui;
}


void NPCEditor::on_open_code_triggered()
{
    QString open_target = QFileDialog::getOpenFileName(this,
                                      tr("打开NPC图鉴"),
                                      "./",
                                      tr("NPC图鉴 (*.npcedit);;all (*.*)")
                                      );
    filepath = open_target;
    QSettings *read_doc = new QSettings(open_target, QSettings::IniFormat);
    QString type = read_doc->value("manifest/type").toString();
    QString sector = read_doc->value("manifest/sector").toString();
    QString min_required_version = read_doc->value("manifest/min_version").toString();
    QString npc_name_for_windowtitle = read_doc->value("manifest/name").toString();
    if (npc_name_for_windowtitle == ""){
        setWindowTitle("无标题 - 原神BWIKI NPC图鉴第三方编辑工具");
    }
    else{
        QString windowtitle = npc_name_for_windowtitle + " - 原神BWIKI NPC图鉴第三方编辑工具";
        setWindowTitle(windowtitle);
    }
    if (type != "npcedit"){
        QMessageBox::critical(NULL, "打开文件失败", "错误：所选文件似乎不是此编辑器所支持的类型。\n错误#1", QMessageBox::Ok);
    }
    else{
        if (sector != "npc"){
            QMessageBox::critical(NULL, "打开文件失败", "错误：所选文件不是NPC图鉴中的一员，其可能是其他类型的图鉴。\n错误#2", QMessageBox::Ok);
        }
        else{
            if (min_required_version != "1.0"){
                QMessageBox::critical(NULL, "打开文件失败", "错误：打开所选文件需要更新版本的工具，请考虑检查更新。\n错误#3", QMessageBox::Ok);
            }
            else{
                bool read_done = false;
                ui->code_preview->clear();
                    while (read_done != true) {
                        QString read_progress_string = QString::number(read_progress);
                        QString current_target = "content/line"+read_progress_string;
                        QString read_current_line = read_doc->value(current_target).toString();
                        if (read_current_line == "this_is_the_end_of_content"){
                            read_done = true;
                        }
                        else{
                            ui->code_preview->insertPlainText(read_current_line);
                            ui->code_preview->insertHtml("<br/>");
                            read_progress = read_progress + 1;
                        }
                    }
            }
        }
    }
    read_progress = 0;
    delete read_doc;


}


void NPCEditor::on_save_code_triggered()
{
    QString save_target;
    if (filepath == ""){
        save_target = QFileDialog::getSaveFileName(this,
            tr("保存NPC图鉴"), "",
            tr("NPC图鉴 (*.npcedit);;all (*.*)"));
        filepath = save_target;
    }
    else{
        QSettings *write_doc = new QSettings(filepath, QSettings::IniFormat);
        write_doc->setValue("manifest/type", "npcedit");
        write_doc->setValue("manifest/sector", "npc");
        write_doc->setValue("manifest/min_version", version);


                QPalette palette = ui->code_preview->palette();
                palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
                ui->code_preview->setPalette(palette);
                QTextCursor tc = ui->code_preview->textCursor();
                int name_row_num = tc. blockNumber()+1;
                QString line_npc_name = ui->code_preview->document()->findBlockByLineNumber(name_row_num).text();
                QString npc_name = line_npc_name.replace("|名称=", "");
                write_doc->setValue("manifest/name", npc_name);
                QString windowtitle = npc_name + " - 原神BWIKI NPC图鉴第三方编辑工具";
                setWindowTitle(windowtitle);

                bool save_done = false;
                while (save_done == false){
                    QString save_current_line = ui->code_preview->document()->findBlockByLineNumber(saveprogress).text();
                    if (save_emptylinenum == 5){
                        save_done = true;
                        saveprogress = saveprogress + 1;
                        QString linenum_string = QString::number(saveprogress);
                        QString linetitle = "line" + linenum_string;
                        QString write_target = "content/" + linetitle;
                        write_doc->setValue(write_target, "this_is_the_end_of_content");
                    }
                    else{
                        if (save_current_line == ""){
                            //saveprogress = saveprogress + 1;
                            save_emptylinenum = save_emptylinenum + 1;
                        }
                        else{
                            save_emptylinenum = 0;

                            QString linenum_string = QString::number(saveprogress);
                            QString linetitle = "line" + linenum_string;
                            QString write_target = "content/" + linetitle;
                            write_doc->setValue(write_target, save_current_line);

                            saveprogress = saveprogress + 1;
                        }
                    }


                }

            }

}

