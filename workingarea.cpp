#include "workingarea.h"
#include "ui_workingarea.h"
#include "license.h"

WorkingArea::WorkingArea(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkingArea)
{
    ui->setupUi(this);
}

WorkingArea::~WorkingArea()
{
    delete ui;
}


void WorkingArea::on_show_license_triggered()
{
    License *license_show = new License;
    license_show->show();
}

