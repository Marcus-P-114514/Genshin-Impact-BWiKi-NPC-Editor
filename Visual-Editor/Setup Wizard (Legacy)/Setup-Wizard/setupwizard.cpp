#include "setupwizard.h"
#include "ui_setupwizard.h"
#include "QFontDatabase"

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
    int font_Id = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/Heavy.otf");
        QStringList font_list = QFontDatabase::applicationFontFamilies(font_Id);
    QFont f;
            f.setFamily(font_list[0]);

    ui->label->setFont(f);
}

SetupWizard::~SetupWizard()
{
    delete ui;
}


void SetupWizard::on_debug_exit_clicked()
{
    QApplication::exit();
}

