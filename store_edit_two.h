#ifndef STORE_EDIT_TWO_H
#define STORE_EDIT_TWO_H

#include <QWidget>

namespace Ui {
class Store_Edit_Two;
}

class Store_Edit_Two : public QWidget
{
    Q_OBJECT

public:
    explicit Store_Edit_Two(QWidget *parent = nullptr);
    ~Store_Edit_Two();

private slots:
    void on_write_multi_price_clicked();

private:
    Ui::Store_Edit_Two *ui;
};

#endif // STORE_EDIT_TWO_H
