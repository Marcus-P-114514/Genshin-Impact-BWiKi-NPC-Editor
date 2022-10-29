#include "changelog.h"
#include "ui_changelog.h"
#include "QFile"
#include "QTextStream"

changelog::changelog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changelog)
{
    ui->setupUi(this);
    QFile open_changelog("./changelog");
    if (open_changelog.open(QFile::ReadOnly | QIODevice::Truncate))
    {
        QTextStream changelog_content(&open_changelog);
        ui->changelogBrowser->setText(changelog_content.readAll());
    }
    open_changelog.close();
}

changelog::~changelog()
{
    delete ui;
}

void changelog::on_close_changelog_clicked()
{
    QWidget::close();
}

