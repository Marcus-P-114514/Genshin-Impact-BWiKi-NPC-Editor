#ifndef ERRALREADYRUNNING_H
#define ERRALREADYRUNNING_H

#include "QDialog"
#include "QGraphicsDropShadowEffect"
#include "QFontDatabase"

namespace Ui {
class errAlreadyRunning;
}

class errAlreadyRunning : public QDialog
{
    Q_OBJECT

public:
    explicit errAlreadyRunning(QWidget *parent = nullptr);
    ~errAlreadyRunning();

private slots:
    void on_quitApplication_clicked();

private:
    Ui::errAlreadyRunning *ui;
};

#endif // ERRALREADYRUNNING_H
