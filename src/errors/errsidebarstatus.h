#ifndef ERRSIDEBARSTATUS_H
#define ERRSIDEBARSTATUS_H

#include <QDialog>
#include "QGraphicsDropShadowEffect"
#include "QFontDatabase"

namespace Ui {
class errSideBarStatus;
}

class errSideBarStatus : public QDialog
{
    Q_OBJECT

public:
    explicit errSideBarStatus(QWidget *parent = nullptr);
    ~errSideBarStatus();

private slots:
    void on_quitApp_clicked();

private:
    Ui::errSideBarStatus *ui;
};

#endif // ERRSIDEBARSTATUS_H
