#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QGraphicsDropShadowEffect"

int window_height;
int window_width;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground,true);

    this->setStyleSheet("QMenu::item:selected{background-color:#E7BF9F;color:#FFFFFF;}QMenu::item{background-color:#F6F0E5;color:#E7BF9F;}QMenu::item:disabled{background-color:#F6F0E5;color:#ddd}QMenu{border-bottom-color: rgb(44, 44, 44); border-bottom: 2px; border-style: solid; background-color: #FFFFF}QWidget{background: #F6F0E5; border-top-left-radius: 0px; border-top-right-radius: 0px;}QWidget{color: #E7BF9F;}");
    //this->setStyleSheet("QWidget{border-top-left-radius:15px;border-top-right-radius:5px;}");

    window_height = this->geometry().height();
    window_width = this->geometry().width();


    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
        shadow_effect->setOffset(0, 0);
        shadow_effect->setColor(QColor(150,150,150));
        shadow_effect->setBlurRadius(8);
        this->setGraphicsEffect(shadow_effect);

    //隐藏Tab
    ui->editor_selecter->setCurrentIndex(0);
    ui->tree_holder->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取窗口大小

QString window_is_maxiumized = "false";

void MainWindow::on_code_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(1);
}


void MainWindow::on_visual_editor_released_clicked()
{
    ui->editor_selecter->setCurrentIndex(0);
}

/**
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_point = event->globalPos()-frameGeometry().topLeft();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    move(event->pos() - m_point + pos());
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}




void MainWindow::mouseDoubleClickEvent(QMouseEvent* e)
{
    //双击最大化
    if (window_is_maxiumized == "false"){
        setWindowState(Qt::WindowMaximized);
        window_is_maxiumized = "true";
        //qDebug() <<window_is_maxiumized;
    }
    else{
        this->showNormal();
        //resize(window_width, window_height);
        window_is_maxiumized = "false";
        //qDebug() <<window_is_maxiumized;
    }
}
**/
