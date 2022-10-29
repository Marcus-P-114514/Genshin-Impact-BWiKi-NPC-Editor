#ifndef NPC_GIFT_OPTION_H
#define NPC_GIFT_OPTION_H

#include <QDialog>

namespace Ui {
class npc_gift_option;
}

class npc_gift_option : public QDialog
{
    Q_OBJECT

public:
    explicit npc_gift_option(QWidget *parent = nullptr);
    ~npc_gift_option();

private slots:
    void on_npc_multi_insert_gift_clicked();

    void on_npc_multi_clear_gift_clicked();

    void on_npc_gift_mult_submit_final_clicked();

private:
    Ui::npc_gift_option *ui;
};

#endif // NPC_GIFT_OPTION_H
