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

    void on_basic_info_switcher_clicked();

    void on_project_name_clicked();

    void on_npc_store_switcher_clicked();

    void on_npc_dialog_switcher_clicked();

    void on_cv_table_switcher_clicked();

    void on_npc_location_switcher_clicked();

    void on_extra_switcher_clicked();

    void on_file_switcher_clicked();

    void on_npc_gender_option_unknown_clicked();

    void on_npc_gender_male_clicked();

    void on_npc_gender_female_clicked();

    void on_npcname_input_textEdited(const QString &arg1);

    void on_nickname_input_cursorPositionChanged(int arg1, int arg2);

    void on_job_input_textEdited(const QString &arg1);

    void on_location_input_textEdited(const QString &arg1);

    void on_npc_country_option_unknown_clicked();

    void on_npc_country_option_mondstadt_clicked();

    void on_npc_country_option_liyue_clicked();

    void on_npc_country_option_inazuman_clicked();

    void on_npc_country_option_sumeru_clicked();

    void on_npc_country_option_fortaine_clicked();

    void on_npc_country_option_nata_clicked();

    void on_npc_country_option_snezhnayan_clicked();

protected:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
