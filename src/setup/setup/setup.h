#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_setup.h"

#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QSettings>
#include <QProcess>
#include <QButtonGroup>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QProcess>

class setup : public QMainWindow
{
    Q_OBJECT

public:
    setup(QWidget *parent = nullptr);
    ~setup();

private:
    Ui::setupClass ui;
    QString documentPath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, QString(), QStandardPaths::LocateDirectory);
    QString configPath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, "BWIKI/ys/NPC-Editor/preferences.npcedit");
    QString actualScale;
    QString previewScale = "default";
    QString configImportPath;

private slots:
    void on_startSetup_clicked();
    void on_acceptLicense_clicked();
    void on_denyLicense_clicked();
    void on_startCleanSetup_clicked();
    void on_DPISlider_sliderMoved();
    void on_previewWindow_clicked();
    void on_switchToEditorFont_clicked();
    void on_switchToScale_clicked();
    void on_writeConfig_clicked();
    void on_finishConf_clicked();
    void on_startImportManager_clicked();
};
