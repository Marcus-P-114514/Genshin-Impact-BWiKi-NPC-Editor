#ifndef SETUPWIZARD_H
#define SETUPWIZARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SetupWizard; }
QT_END_NAMESPACE

class SetupWizard : public QMainWindow
{
    Q_OBJECT

public:
    SetupWizard(QWidget *parent = nullptr);
    ~SetupWizard();

private slots:
    void on_debug_exit_clicked();

private:
    Ui::SetupWizard *ui;
};
#endif // SETUPWIZARD_H
