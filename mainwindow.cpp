/**
 * 无聊！
 * 无能！
 * 无用！
 **/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QApplication"
#include "QProcess"
#include "QFile"
#include "QTextStream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings *clear_cache = new QSettings("./cache/cache.ini", QSettings::IniFormat);
    clear_cache->setValue("basic/name", "");
    clear_cache->setValue("basic/nickname", "");
    clear_cache->setValue("basic/gender", "未知");
    clear_cache->setValue("basic/job", "");
    clear_cache->setValue("basic/location", "");
    clear_cache->setValue("basic/country", "未知");
    clear_cache->setValue("basic/gift_exist", "无");
    clear_cache->setValue("basic/gift_content", "");
    clear_cache->setValue("basic/gift_num", "");
    clear_cache->setValue("basic/version", "未知");
    clear_cache->setValue("basic/org", "");
    clear_cache->setValue("basic/system", "无");
    delete clear_cache;

    QFile clear_store_two_target ("./cache/store_two.npchandler");
    if (clear_store_two_target.open(QFile::WriteOnly|QFile::Text)){
        QTextStream clear_store_two (&clear_store_two_target);
        clear_store_two << "";
    }

    //强制退出

    QProcess p(0);
        p.start("cmd", QStringList()<<"/c"<<"taskkill /IM clear-cache.exe /F");
        p.waitForStarted();
        p.waitForFinished();
}

MainWindow::~MainWindow()
{
    delete ui;
}
