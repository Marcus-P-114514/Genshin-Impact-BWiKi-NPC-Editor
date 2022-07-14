#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //QPoint m_point;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_code_editor_released_clicked();

    void on_visual_editor_released_clicked();

protected:
    //void mouseDoubleClickEvent(QMouseEvent* e);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
