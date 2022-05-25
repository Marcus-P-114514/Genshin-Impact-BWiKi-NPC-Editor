#include "file_not_saved.h"
#include "ui_file_not_saved.h"
#include "mainwindow.h"

File_Not_Saved::File_Not_Saved(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::File_Not_Saved)
{
    ui->setupUi(this);
}

File_Not_Saved::~File_Not_Saved()
{
    delete ui;
}

void File_Not_Saved::on_return_to_editor_from_file_no_saved_dialog_clicked()
{
    this->hide();
}


void File_Not_Saved::on_discard_changes_from_file_not_saved_dialog_clicked()
{
    this->hide();
    MainWindow *mw = new MainWindow;
    mw->working_paper
}

