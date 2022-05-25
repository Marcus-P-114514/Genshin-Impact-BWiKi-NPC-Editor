#ifndef STORE_H
#define STORE_H

#include <QWidget>

namespace Ui {
class Store;
}

class Store : public QWidget
{
    Q_OBJECT

public:
    explicit Store(QWidget *parent = nullptr);
    ~Store();

private slots:
    void on_store_write_enter_clicked();

    void on_no_store_clicked();


    void on_write_last_line_clicked();

    void on_multi_exchange_opener_clicked();

private:
    Ui::Store *ui;
};

#endif // STORE_H
