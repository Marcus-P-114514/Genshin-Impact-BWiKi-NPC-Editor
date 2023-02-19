#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_desktop.h"
#include "dialogs/fatalError/fatalerrordialog.h"
#include "plugins/giftEditor/gifteditor.h"

#include <QFontDatabase>
#include <QStandardPaths>
#include <QSettings>
#include <QGraphicsDropShadowEffect>

class desktop : public QMainWindow
{
    Q_OBJECT

public:
    desktop(QWidget *parent = nullptr);
    ~desktop();

public slots:
    void reportFatalError(QString titleTextSend, QString contentTextSend);

private:
    Ui::desktopClass ui;
    QString configPath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, "BWIKI/ys/NPC-Editor/preferences.npcedit");
    int visualEditorPage = 1;
    void updateVisualEditorPage();

private slots:
    void on_trigMultipleGift_clicked();
    void on_basicInfoSwitcherIcon_clicked();
    void on_basicInfoSwitcher_clicked();
    void on_storeSwitcherIcon_clicked();
    void on_storeSwitcher_clicked();

signals:
    void sendFatalErrorTitle(QString titleText);
    void sendFatalErrorContent(QString contentText);
};
