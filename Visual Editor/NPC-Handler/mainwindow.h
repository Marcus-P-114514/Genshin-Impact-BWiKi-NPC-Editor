#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_code_editor_released_clicked();

    void on_visual_editor_released_clicked();

protected:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
