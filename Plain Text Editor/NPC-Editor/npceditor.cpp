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
#include "QClipboard"
#include "QApplication"
#include "QDialog"
#include "QInputDialog"
#include "QDesktopServices"
#include "QDragEnterEvent"
#include "QMimeData"

QString version = "1.0";
int read_progress = 0;
QString filepath="";
int saveprogress = 0;
int save_emptylinenum = 0;
QString nonrelated_info = "";
QString npc_name_for_upload = "";
QString theme_light = "QMenu::item:selected{background-color:#E7BF9F;color:#FFFFFF;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd}QWidget{background: #F6F0E5;}QWidget{color: #E7BF9F;}";
QString theme_dark = "QMenu::item:selected{background-color:#E7BF9F;color:#FFFFFF;}QMenu::item{background-color:#F000000;color:#E7BF9F;}QMenu::item:disabled{background-color:#F000000;color:#ddd}QWidget{background: #000000;}QWidget{color: #E7BF9F;}";
QString custom_theme = "";

NPCEditor::NPCEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NPCEditor)
{
    ui->setupUi(this);
    //解决背景为白色时菜单栏选中字体问题
    QSettings *read_config = new QSettings("./config/global.conf", QSettings::IniFormat);
    QString theme_selection = read_config->value("global/theme").toString();
    QString custom_stylesheet = read_config->value("theme/custom").toString();
    custom_theme = custom_stylesheet;
    if (theme_selection == "light"){
        this->setStyleSheet(theme_light);
    }
    else if (theme_selection == "dark"){
        this->setStyleSheet(theme_dark);
    }
    else{
        this->setStyleSheet(custom_theme);
    }

    //应用高亮
    highlighter=new code_highlight (ui->code_preview->document());

    //窗体标题
    setWindowTitle("无标题 - 原神BWIKI NPC图鉴第三方编辑工具");

    //窗口接受拖拽
    setAcceptDrops(true);

    //默认隐藏快速插入
    ui->insert_special->setEnabled(0);
    ui->insert_special->setVisible(0);
}

NPCEditor::~NPCEditor()
{
    delete ui;
}

void NPCEditor::dragEnterEvent(QDragEnterEvent* event)
{
    if(!event->mimeData()->urls()[0].fileName().right(7).compare("npcedit"))
           event->acceptProposedAction();
        else
           event->ignore();
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
        npc_name_for_upload = npc_name_for_windowtitle;
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
                write_doc->setValue("manifest/name", npc_name_for_upload);
                QString windowtitle = npc_name_for_upload + " - 原神BWIKI NPC图鉴第三方编辑工具";
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
                delete write_doc;
            }

}


void NPCEditor::on_save_code_as_triggered()
{
    QString save_target = QFileDialog::getSaveFileName(this,
        tr("保存NPC图鉴"), "",
        tr("NPC图鉴 (*.npcedit);;all (*.*)"));
    QSettings *write_doc = new QSettings(save_target, QSettings::IniFormat);
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
            delete write_doc;
}


void NPCEditor::on_clear_all_triggered()
{
    if (ui->code_preview->document()->isEmpty()){
        nonrelated_info = "There is no need to clear, the document is already empty";
    }
    else{
        QClipboard *tempsave = QApplication::clipboard();
        tempsave -> setText(ui->code_preview->document()->toPlainText());
        ui->code_preview->clear();
        QMessageBox::information(NULL, "文本操作", "已经将您的工作区域清空。\n如果您无意这么做，请不用担心，我们已经把您的代码备份到了您的剪贴板内，下面是部分平台上用于粘贴的快捷键：\nWindows：同时按住ctrl+V\nmacOS：同时按住command+V", QMessageBox::Ok);
    }
}


void NPCEditor::on_assign_npc_name_triggered()
{
    QString npc_name_input = QInputDialog::getText(this, "指定NPC名称", "在上传文件之前，请指定NPC名称。");
        if (!npc_name_input.isEmpty())
            npc_name_for_upload = npc_name_input;
        QString windowtitle = npc_name_for_upload + " - 原神BWIKI NPC图鉴第三方编辑工具";
        setWindowTitle(windowtitle);
}


void NPCEditor::on_upload_avatar_triggered()
{
    if (npc_name_for_upload == ""){
        QString npc_name_input = QInputDialog::getText(this, "指定NPC名称", "在上传文件之前，请指定NPC名称。");
            if (!npc_name_input.isEmpty())
                npc_name_for_upload = npc_name_input;
            QString windowtitle = npc_name_for_upload + " - 原神BWIKI NPC图鉴第三方编辑工具";
            setWindowTitle(windowtitle);
            QString target_url = "https://wiki.biligame.com/ys/文件:" + npc_name_for_upload + ".png";
            QDesktopServices::openUrl(QUrl(QString(target_url)));
    }
    else{
        QString target_url = "https://wiki.biligame.com/ys/文件:" + npc_name_for_upload + ".png";
        QDesktopServices::openUrl(QUrl(QString(target_url)));
    }
}


void NPCEditor::on_upload_model_triggered()
{
    if (npc_name_for_upload == ""){
        QString npc_name_input = QInputDialog::getText(this, "指定NPC名称", "在上传文件之前，请指定NPC名称。");
            if (!npc_name_input.isEmpty())
                npc_name_for_upload = npc_name_input;
            QString windowtitle = npc_name_for_upload + " - 原神BWIKI NPC图鉴第三方编辑工具";
            setWindowTitle(windowtitle);
            QString target_url = "https://wiki.biligame.com/ys/文件:" + npc_name_for_upload + "建模.png";
            QDesktopServices::openUrl(QUrl(QString(target_url)));
    }
    else{
        QString target_url = "https://wiki.biligame.com/ys/文件:" + npc_name_for_upload + "建模.png";
        QDesktopServices::openUrl(QUrl(QString(target_url)));
    }
}


void NPCEditor::on_upload_location_triggered()
{
    if (npc_name_for_upload == ""){
        QString npc_name_input = QInputDialog::getText(this, "指定NPC名称", "在上传文件之前，请指定NPC名称。");
            if (!npc_name_input.isEmpty())
                npc_name_for_upload = npc_name_input;
            QString windowtitle = npc_name_for_upload + " - 原神BWIKI NPC图鉴第三方编辑工具";
            setWindowTitle(windowtitle);
            QString target_url = "https://wiki.biligame.com/ys/文件:" + npc_name_for_upload + "位置.png";
            QDesktopServices::openUrl(QUrl(QString(target_url)));
    }
    else{
        QString target_url = "https://wiki.biligame.com/ys/文件:" + npc_name_for_upload + "位置.png";
        QDesktopServices::openUrl(QUrl(QString(target_url)));
    }
}


void NPCEditor::on_open_map_triggered()
{
    QDesktopServices::openUrl(QUrl(QString("https://wiki.biligame.com/ys/%E5%8E%9F%E7%A5%9E%E5%9C%B0%E5%9B%BE%E5%B7%A5%E5%85%B7_%E5%85%A8%E5%9C%B0%E6%A0%87%E4%BD%8D%E7%BD%AE%E7%82%B9")));
}


void NPCEditor::on_about_this_application_triggered()
{
    QMessageBox::information(NULL, "关于", "版本：1.0\nby：屑机主\n许可证：GPL v3", QMessageBox::Ok);
}


void NPCEditor::on_about_qt_triggered()
{
    QApplication::aboutQt();
}


void NPCEditor::on_upload_log_triggered()
{
    QMessageBox::information(NULL, "更新日志", "这是初次提交。", QMessageBox::Ok);
}


void NPCEditor::on_check_update_triggered()
{
    QDesktopServices::openUrl(QUrl(QString("https://xjz.rth.app/NPC%E5%9B%BE%E9%89%B4%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7/%E6%9B%B4%E6%96%B0%E6%A3%80%E6%9F%A5/1.0")));
}

void NPCEditor::on_open_license_triggered()
{
    QDesktopServices::openUrl(QUrl(QString("https://github.com/Marcus-P-114514/Genshin-Impact-BWiKi-NPC-Editor/blob/main/LICENSE")));
}

void NPCEditor::dropEvent(QDropEvent*event){
    const QMimeData *droppeddoc = event->mimeData();
    QString droppath = droppeddoc ->urls()[0].toLocalFile();

    filepath = droppath;
    QSettings *read_doc = new QSettings(droppath, QSettings::IniFormat);
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
        npc_name_for_upload = npc_name_for_windowtitle;
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



void NPCEditor::on_insert_template_triggered()
{
    ui->insert_special->setEnabled(1);
    ui->insert_special->setVisible(1);
}


void NPCEditor::on_insert_brackets_triggered()
{
    QString process_brackets = ui->code_preview->textCursor().selectedText();
    QString brackets_applied = "「" + process_brackets + "」";
    if (process_brackets == ""){
        QTextCursor handleCursor = ui->code_preview->textCursor();
        handleCursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 1);
        ui->code_preview->setTextCursor(handleCursor);
    }
    ui->code_preview->insertPlainText(brackets_applied);

}


void NPCEditor::on_bold_triggered()
{
    QString process_bold = ui->code_preview->textCursor().selectedText();
    QString bold_applied = "'''" + process_bold + "'''";
    if (process_bold == ""){
        QTextCursor handleCursor = ui->code_preview->textCursor();
        handleCursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 3);
        ui->code_preview->setTextCursor(handleCursor);
    }
    ui->code_preview->insertPlainText(bold_applied);
}


void NPCEditor::on_italic_triggered()
{
    QString process_italic = ui->code_preview->textCursor().selectedText();
    QString italic_applied = "''" + process_italic + "''";
    if (process_italic == ""){
        QTextCursor handleCursor = ui->code_preview->textCursor();
        handleCursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 3);
        ui->code_preview->setTextCursor(handleCursor);
    }
    ui->code_preview->insertPlainText(italic_applied);
}


void NPCEditor::on_underline_triggered()
{
    QString process_underline = ui->code_preview->textCursor().selectedText();
    QString underline_applied = "<u>" + process_underline + "</u>";
    if (process_underline == ""){
        QTextCursor handleCursor = ui->code_preview->textCursor();
        handleCursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 4);
        ui->code_preview->setTextCursor(handleCursor);
    }
    ui->code_preview->insertPlainText(underline_applied);
}


void NPCEditor::on_color_triggered()
{
    QString color_selected = QInputDialog::getText(this, "输入要显示的颜色","在这里输入文字颜色，示例：火\n详见：https://wiki.biligame.com/ys/原神WIKI编辑教程/#模板:颜色");
    QString process_color = ui->code_preview->textCursor().selectedText();
    if (process_color == ""){
        QString colored_text = QInputDialog::getText(this, "输入要显示的文字","在这里输入的文字会以选定的颜色显示");
        QString color_output = "{{颜色|" + color_selected + "|" + colored_text + "}}";
        ui->code_preview->insertPlainText(color_output);
    }
    else{
        QString color_output = "{{颜色|" + color_selected + "|" + process_color + "}}";
        ui->code_preview->insertPlainText(color_output);
    }
}


void NPCEditor::on_close_toolbar_triggered()
{
    ui->insert_special->setEnabled(0);
    ui->insert_special->setVisible(0);
}

