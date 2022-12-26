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

#include "errsidebarstatus.h"

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

protected:
private slots:
    void on_sideBarSwitcher_clicked();
};
#endif // MAINWINDOW_H
