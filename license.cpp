#include "license.h"
#include "ui_license.h"

License::License(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::License)
{
    ui->setupUi(this);
}

License::~License()
{
    delete ui;
}

void License::on_close_license_framework_clicked()
{

}

