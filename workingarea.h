#ifndef WORKINGAREA_H
#define WORKINGAREA_H

#include <QMainWindow>

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
};
#endif // WORKINGAREA_H
