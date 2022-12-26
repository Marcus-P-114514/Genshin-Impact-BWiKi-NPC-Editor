#include "errsidebarstatus.h"
#include "ui_errsidebarstatus.h"

errSideBarStatus::errSideBarStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errSideBarStatus)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *dialogShadow = new QGraphicsDropShadowEffect(this);
    dialogShadow->setOffset(0, 0);
    dialogShadow->setColor(QColor(178,115,43,109));
    dialogShadow->setBlurRadius(25);
    ui->frame->setGraphicsEffect(dialogShadow);
}

errSideBarStatus::~errSideBarStatus()
{
    delete ui;
}

void errSideBarStatus::on_quitApp_clicked()
{
    QApplication::quit();
}

