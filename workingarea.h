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

private:
    Ui::WorkingArea *ui;
    code_highlight *highlighter;
};
#endif // WORKINGAREA_H
