#include "erralreadyrunning.h"
#include "ui_erralreadyrunning.h"

errAlreadyRunning::errAlreadyRunning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errAlreadyRunning)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint);

    setWindowTitle("运行错误");
}

errAlreadyRunning::~errAlreadyRunning()
{
    delete ui;
}

void errAlreadyRunning::on_quitApplication_clicked()
{
    QApplication::quit();
}

