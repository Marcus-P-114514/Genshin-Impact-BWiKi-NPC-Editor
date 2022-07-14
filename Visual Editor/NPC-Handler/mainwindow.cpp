#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QGraphicsDropShadowEffect"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化界面
    this->setStyleSheet("QMenu::item:selected{background-color:#E7BF9F;color:#FFFFFF;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd}QMenu{border-bottom-color: rgb(44, 44, 44); border-bottom: 2px; border-style: solid; background-color: #FFFFF}QWidget{background: #F6F0E5; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color: #E7BF9F;}");
    ui->editor_selecter->setCurrentIndex(0);
    ui->tree_holder->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_code_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(1);
}


void MainWindow::on_visual_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(0);
}
