#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <npc_gift_option.h>
#include <npc_store_multi_exchange.h>
#include <theme.h>

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

    //void on_npcname_input_textEdited(const QString &arg1);

    //void on_nickname_input_cursorPositionChanged(int arg1, int arg2);

    //void on_job_input_textEdited(const QString &arg1);

    //void on_location_input_textEdited(const QString &arg1);

    void on_npc_country_option_unknown_clicked();

    void on_npc_country_option_mondstadt_clicked();

    void on_npc_country_option_liyue_clicked();

    void on_npc_country_option_inazuman_clicked();

    void on_npc_country_option_sumeru_clicked();

    void on_npc_country_option_fortaine_clicked();

    void on_npc_country_option_nata_clicked();

    void on_npc_country_option_snezhnayan_clicked();

    void on_npc_system_option_none_clicked();

    void on_npc_system_option_commission_clicked();

    void on_npc_system_option_frame_clicked();

    void on_npc_system_option_activity_clicked();

    void on_npc_system_option_store_clicked();

    void on_npc_system_option_cook_clicked();

    void on_npc_system_option_serenitea_pot_clicked();

    void on_organization_input_textChanged(const QString &arg1);

    void on_npcname_input_textChanged(const QString &arg1);

    void on_nickname_input_textChanged(const QString &arg1);

    void on_job_input_textChanged(const QString &arg1);

    void on_location_input_textChanged(const QString &arg1);

    void on_npc_gift_option_none_clicked();

    void on_npc_gift_option_exist_clicked();

    void on_gift_single_edit_name_textChanged(const QString &arg1);

    void on_gift_single_edit_amount_textChanged(const QString &arg1);

    void on_multiple_gift_edit_clicked();

    void on_version_input_textChanged(const QString &arg1);

    void generate_code();

    void on_npc_store_isexist_clicked();

    void on_npc_store_none_clicked();

    void on_npc_store_clear_list_clicked();

    void on_npc_store_submit_current_clicked();

    void on_npc_store_multi_exchanger_clicked();

    void on_open_mapview_triggered();

    void on_npc_dialog_none_clicked();

    void on_npc_dialog_isexist_clicked();

    void on_npc_dialog_islast_line_clicked();

    void on_npc_dialog_insert_clicked();

    void on_npc_dialog_append_npc_dialog_clicked();

    void on_npc_dialog_append_npc_option_clicked();

    void on_Chinese_cv_edit_textChanged(const QString &arg1);

    void on_Japanese_cv_edit_textChanged(const QString &arg1);

    void on_English_cv_edit_textChanged(const QString &arg1);

    void on_Korean_cv_edit_textChanged(const QString &arg1);

    void on_npc_appear_isfull_day_clicked();

    void on_npc_appear_isday_clicked();

    void on_npc_appear_isnight_clicked();

    void on_npc_location_usemap_clicked();

    void on_npc_location_usepic_clicked();

    void on_npc_location_map_edit_textChanged(const QString &arg1);

    void on_upload_npc_pic_location_clicked();

    void on_npc_activity_yes_clicked();

    void on_npc_activity_no_clicked();

    void on_npc_frame_sys_edit_textChanged(const QString &arg1);

    void on_npc_commision_sys_edit_textChanged(const QString &arg1);

    void on_npc_trounce_edit_textChanged(const QString &arg1);

    void on_last_edit_ver_edit_textChanged(const QString &arg1);

    void on_file_iscompleted_clicked();

    void on_file_requires_work_clicked();

    void on_submit_npc_avatar_clicked();

    void on_submit_npc_model_clicked();

    void on_submit_npc_location_not_detailed_clicked();

    void on_generate_wiki_content_triggered();

    void on_new_project_triggered();

    void save_project_ini();

    void on_save_project_triggered();

    void on_save_project_as_triggered();

    void on_open_project_triggered();

    void open_project_ini();

    void on_release_to_WIKI_triggered();

    void on_welcome_screen_linkActivated(const QString &link);

    void dropEvent(QDropEvent *drop_event_1);

    void dragEnterEvent(QDragEnterEvent *drop_event_1);

    void on_insert_templates_triggered();

    void on_insert_brackets_triggered();

    void on_insert_bold_triggered();

    void on_insert_italic_triggered();

    void on_insert_underline_triggered();

    void on_apply_font_color_triggered();

    void on_close_quick_insert_triggered();

    void on_config_theme_triggered();

    void on_about_triggered();

    void on_about_Qt_triggered();

    void on_changelog_triggered();

    void on_license_triggered();

    void on_update_check_triggered();

    void on_patch_avatar_false_clicked();

    void on_patch_avatar_true_clicked();

    void on_patch_avatar_intro_clicked();

    void on_npc_country_current_option_unknown_clicked();

    void on_npc_country_current_option_mondstat_clicked();

    void on_npc_country_current_option_liyue_clicked();

    void on_npc_country_current_option_inazuman_clicked();

    void on_npc_country_current_option_sumeru_clicked();

    void on_npc_country_current_option_fortaine_clicked();

    void on_npc_country_current_option_nata_clicked();

    void on_npc_country_current_option_snezhnayan_clicked();

    void on_conf_panel_two_clicked();

protected:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
