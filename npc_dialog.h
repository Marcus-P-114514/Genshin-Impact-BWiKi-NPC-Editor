#ifndef NPC_DIALOG_H
#define NPC_DIALOG_H

#include <QWidget>

namespace Ui {
class NPC_Dialog;
}

class NPC_Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit NPC_Dialog(QWidget *parent = nullptr);
    ~NPC_Dialog();

private:
    Ui::NPC_Dialog *ui;
};

#endif // NPC_DIALOG_H
