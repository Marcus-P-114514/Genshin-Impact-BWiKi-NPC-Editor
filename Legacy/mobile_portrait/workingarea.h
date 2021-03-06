#ifndef WORKINGAREA_H
#define WORKINGAREA_H

#include <QMainWindow>
#include "code_highlight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WorkingArea; }
QT_END_NAMESPACE

class WorkingArea : public QMainWindow
{
    Q_OBJECT

public:
    WorkingArea(QWidget *parent = nullptr);
    ~WorkingArea();

private slots:
    void on_show_license_triggered();

    void on_write_basic_info_clicked();

    void on_exist_dialog_judge_clicked(bool checked);

    void on_store_exist_normal_toggled(bool checked);

    void on_store_end_task_clicked();

    void on_store_exist_normal_stateChanged(int arg1);

    void on_multi_mod_support_on_stateChanged(int arg1);

    void on_store_write_and_enter_clicked();

    void on_back_to_npc_store_normal_mode_clicked();

private:
    Ui::WorkingArea *ui;
    code_highlight *highlighter;
};
#endif // WORKINGAREA_H
