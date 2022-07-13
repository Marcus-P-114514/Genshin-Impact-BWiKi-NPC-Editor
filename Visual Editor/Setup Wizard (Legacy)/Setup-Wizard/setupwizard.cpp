#include "setupwizard.h"
#include "ui_setupwizard.h"

SetupWizard::SetupWizard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SetupWizard)
{
    ui->setupUi(this);

    //设置背景
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //设置字体
    QFont font;
    font.setFamily("Source Han Serif SC Heavy");
    font.setPixelSize(16);
    font.setBold(1);

    ui->label->setFont(font);
}

SetupWizard::~SetupWizard()
{
    delete ui;
}


void SetupWizard::on_debug_exit_clicked()
{
    QApplication::exit();
}

