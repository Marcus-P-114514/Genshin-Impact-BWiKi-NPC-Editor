#include "license.h"
#include "ui_license.h"
#include "QFile"
#include "QTextStream"

license::license(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::license)
{
    ui->setupUi(this);
    QFile open_license("./LICENSE");
    if (open_license.open(QFile::ReadOnly | QIODevice::Truncate))
    {
        QTextStream license_content(&open_license);
        ui->licenseBrowser->setText(license_content.readAll());
    }
    open_license.close();
}

license::~license()
{
    delete ui;
}

void license::on_closeLicenseWindow_clicked()
{
    QWidget::close();
}

