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
    void on_open_npc_file_triggered();

    void on_open_pain_text_triggered();

    void on_create_file_triggered();

    void on_working_paper_textChanged();

    void on_save_file_triggered();

    void on_save_as_triggered();

    void on_upload_avatar_triggered();


    void on_upload_model_triggered();

    void on_upload_location_triggered();

    void on_genshin_map_triggered();

    void on_npc_basic_info_triggered();

    void on_refresh_basic_info_triggered();

    void on_edit_npc_store_content_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
