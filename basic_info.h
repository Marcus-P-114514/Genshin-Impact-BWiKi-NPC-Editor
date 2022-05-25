#ifndef BASIC_INFO_H
#define BASIC_INFO_H

#include <QWidget>

namespace Ui {
class Basic_Info;
}

class Basic_Info : public QWidget
{
    Q_OBJECT

public:
    explicit Basic_Info(QWidget *parent = nullptr);
    ~Basic_Info();

private slots:

    void on_gift_exist_clicked();

    void on_update_basic_info_clicked();

private:
    Ui::Basic_Info *ui;
};

#endif // BASIC_INFO_H
