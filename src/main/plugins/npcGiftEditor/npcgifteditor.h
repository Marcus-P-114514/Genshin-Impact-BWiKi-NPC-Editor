#ifndef NPCGIFTEDITOR_H
#define NPCGIFTEDITOR_H

#include "QDialog"
#include "QGraphicsDropShadowEffect"
#include "QFontDatabase"
#include "QString"
#include "QSettings"
#include "QDateTime"

namespace Ui {
class npcGiftEditor;
}

class npcGiftEditor : public QDialog
{
    Q_OBJECT

public:
    explicit npcGiftEditor(QWidget *parent = nullptr);
    ~npcGiftEditor();

private slots:
    void on_clearGift_clicked();

    void on_insertGift_clicked();

    void on_discardGift_clicked();

    void on_commitGift_clicked();

private:
    QString currentGiftName;
    QString currentGiftAmount;
    QString npcGiftLog;
    Ui::npcGiftEditor *ui;

signals:
    void sendGiftLog(QString logSent);
};

#endif // NPCGIFTEDITOR_H
