#ifndef THEME_H
#define THEME_H

#include <QDialog>

namespace Ui {
class theme;
}

class theme : public QDialog
{
    Q_OBJECT

public:
    explicit theme(QWidget *parent = nullptr);
    ~theme();

private slots:
    void on_setTheme_light_clicked();

    void on_setTheme_Dark_clicked();

    void on_setTheme_Black_clicked();

private:
    Ui::theme *ui;
};

#endif // THEME_H
