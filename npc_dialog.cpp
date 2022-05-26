#include "npc_dialog.h"
#include "ui_npc_dialog.h"

NPC_Dialog::NPC_Dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NPC_Dialog)
{
    ui->setupUi(this);
}

NPC_Dialog::~NPC_Dialog()
{
    delete ui;
}
