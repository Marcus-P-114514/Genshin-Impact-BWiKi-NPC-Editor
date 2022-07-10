#include "npceditor.h"
#include "ui_npceditor.h"
#include "code_highlight.h"
#include "QFocusEvent"
#include "QMessageBox"

NPCEditor::NPCEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NPCEditor)
{
    ui->setupUi(this);
    this->setStyleSheet("QMenu::item:selected{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd");

    //应用高亮
    highlighter=new code_highlight (ui->code_preview->document());
}

NPCEditor::~NPCEditor()
{
    delete ui;
}

