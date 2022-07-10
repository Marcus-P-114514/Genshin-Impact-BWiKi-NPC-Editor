#ifndef NPCEDITOR_H
#define NPCEDITOR_H

#include <QMainWindow>
#include "code_highlight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NPCEditor; }
QT_END_NAMESPACE

class NPCEditor : public QMainWindow
{
    Q_OBJECT

public:
    NPCEditor(QWidget *parent = nullptr);
    ~NPCEditor();

private slots:
    void on_open_code_triggered();

private:
    Ui::NPCEditor *ui;
    code_highlight *highlighter;
};
#endif // NPCEDITOR_H
