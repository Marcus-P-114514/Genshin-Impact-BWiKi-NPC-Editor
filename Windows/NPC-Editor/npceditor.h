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

private:
    Ui::NPCEditor *ui;
    code_highlight *highlighter;
};
#endif // NPCEDITOR_H
