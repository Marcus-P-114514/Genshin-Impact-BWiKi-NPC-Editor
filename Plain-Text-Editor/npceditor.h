#ifndef NPCEDITOR_H
#define NPCEDITOR_H

#include <QMainWindow>
#include "code_highlight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NPCEditor; }
QT_END_NAMESPACE

extern QString version;

class NPCEditor : public QMainWindow
{
    Q_OBJECT

public:
    NPCEditor(QWidget *parent = nullptr);
    ~NPCEditor();

private slots:
    void on_open_code_triggered();

    void on_save_code_triggered();

    void on_save_code_as_triggered();

    void on_clear_all_triggered();

    void on_assign_npc_name_triggered();

    void on_upload_avatar_triggered();

    void on_upload_model_triggered();

    void on_upload_location_triggered();

    void on_open_map_triggered();

    void on_about_this_application_triggered();

    void on_about_qt_triggered();

    void on_upload_log_triggered();

    void on_check_update_triggered();

    void on_open_license_triggered();

private:
    Ui::NPCEditor *ui;
    code_highlight *highlighter;

protected:
    void dragEnterEvent(QDragEnterEvent*event);
    void dropEvent(QDropEvent*event);
};
#endif // NPCEDITOR_H
