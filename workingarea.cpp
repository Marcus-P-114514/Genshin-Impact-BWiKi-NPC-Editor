#include "workingarea.h"
#include "ui_workingarea.h"
#include "license.h"
#include "code_highlight.h"

WorkingArea::WorkingArea(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorkingArea)
{
    ui->setupUi(this);

    /**
    //ui->toolbox->removeTab(0);
    ui->toolbox->removeTab(1);
    ui->toolbox->removeTab(2);
    ui->toolbox->setTabBarAutoHide(1);
    ui->toolbox->setCurrentIndex(0);

    **/

    //高亮语法
   // code_highlight *ch = new code_highlight;
    //code_highlight(ui->code_output->document());

    highlighter=new code_highlight (ui->code_output->document());
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

