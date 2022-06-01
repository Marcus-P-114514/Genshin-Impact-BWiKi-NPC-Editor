#include "workingarea.h"
#include "ui_workingarea.h"
#include "license.h"

WorkingArea::WorkingArea(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkingArea)
{
    ui->setupUi(this);

    //ui->toolbox->removeTab(0);
    ui->toolbox->removeTab(1);
    ui->toolbox->removeTab(2);
    ui->toolbox->setTabBarAutoHide(1);
    ui->toolbox->setCurrentIndex(0);
}

//Define var

WorkingArea::~WorkingArea()
{
    delete ui;
}


void WorkingArea::on_show_license_triggered()
{
    License *license_show = new License;
    license_show->show();
}

