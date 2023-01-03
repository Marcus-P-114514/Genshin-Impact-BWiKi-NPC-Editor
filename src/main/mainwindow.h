#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "QPainter"
#include "QBitmap"
#include "QMouseEvent"
#include "QPoint"
#include "QDebug"
#include "QGraphicsDropShadowEffect"
#include "QScreen"
#include "QFile"
#include "QFileInfo"
#include "QSettings"
#include "QDateTime"

#include "errors/errsidebarstatus.h"
#include "plugins/npcGiftEditor/npcgifteditor.h"
#include "errors/erralreadyrunning.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initSideBar();
    QString sideBarStatus = "active";
    void resizeEvent(QResizeEvent* systemResize);
    QString npcGiftExist = "不存在";
    QString currentLog;
    QString npcStoreExist = "不存在";

protected:
private slots:
    void on_sideBarSwitcher_clicked();
    void on_npcDialogGiftExist_currentTextChanged(const QString &arg1);
    void on_visualEditorSwitchPreviousPage_clicked();
    void on_visualEditorSwitchNextPage_clicked();
    void on_npcMultipleGiftEdit_clicked();
    void receiveGiftLog(QString giftLogReceived);
    void on_npcStoreExistEdit_currentTextChanged(const QString &arg1);
};


#endif // MAINWINDOW_H
