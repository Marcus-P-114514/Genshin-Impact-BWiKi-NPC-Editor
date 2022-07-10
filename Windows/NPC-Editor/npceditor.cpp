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

NPCEditor::NPCEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NPCEditor)
{
    ui->setupUi(this);
    //解决背景为白色时菜单栏选中字体问题
    this->setStyleSheet("QMenu::item:selected{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd");

    //应用高亮
    highlighter=new code_highlight (ui->code_preview->document());
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
    QSettings *read_doc = new QSettings(open_target, QSettings::IniFormat);
    QString type = read_doc->value("manifest/type").toString();
    QString sector = read_doc->value("manifest/sector").toString();
    QString min_required_version = read_doc->value("manifest/min_version").toString();
    ui->code_preview->insertPlainText(type);
    ui->code_preview->insertHtml("<br/>");
    ui->code_preview->insertPlainText(sector);
    ui->code_preview->insertHtml("<br/>");
    ui->code_preview->insertPlainText(min_required_version);
    ui->code_preview->insertHtml("<br/>");


}

