#ifndef NPC_STORE_MULTI_EXCHANGE_H
#define NPC_STORE_MULTI_EXCHANGE_H

#include <QDialog>

namespace Ui {
class npc_store_multi_exchange;
}

class npc_store_multi_exchange : public QDialog
{
    Q_OBJECT

public:
    explicit npc_store_multi_exchange(QWidget *parent = nullptr);
    ~npc_store_multi_exchange();

private slots:
    void update_multi_exchange();

    void on_npc_store_multi_exchanger_input_1_textChanged(const QString &arg1);

    void on_npt_store_multi_price_input_1_textChanged(const QString &arg1);

    void on_npc_store_multi_exchanger_input_2_textChanged(const QString &arg1);

    void on_npt_store_multi_price_input_2_textChanged(const QString &arg1);

    void on_npc_store_multi_exchanger_input_3_textChanged(const QString &arg1);

    void on_npt_store_multi_price_input_3_textChanged(const QString &arg1);

    void on_npc_store_multi_exchanger_input_4_textChanged(const QString &arg1);

    void on_npt_store_multi_price_input_4_textChanged(const QString &arg1);

    void on_npc_store_multi_exchanger_input_5_textChanged(const QString &arg1);

    void on_npt_store_multi_price_input_5_textChanged(const QString &arg1);

private:
    Ui::npc_store_multi_exchange *ui;
};

#endif // NPC_STORE_MULTI_EXCHANGE_H
