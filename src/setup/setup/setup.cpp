#include "setup.h"

setup::setup(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    int getFontHeavy = QFontDatabase::addApplicationFont(":/fonts/resources/font-Heavy.otf");
    QStringList targetListHeavy = QFontDatabase::applicationFontFamilies(getFontHeavy);
    QFont fontHeavy(targetListHeavy.first());
    ui.title->setFont(fontHeavy);

    QGraphicsDropShadowEffect* dialogShadow = new QGraphicsDropShadowEffect(this);
    dialogShadow->setOffset(0, 0);
    dialogShadow->setColor(QColor(178, 115, 43, 109));
    dialogShadow->setBlurRadius(25);
    ui.frameContainer->setGraphicsEffect(dialogShadow);

    setWindowTitle(QString::fromLocal8Bit("NPC编辑器 · 初始化"));
    QFileInfo detectConf(documentPath + "/BWIKI/ys/NPC-Editor/preferences.npcedit");
    if (detectConf.isFile()) {
        return;
    }
    else {
        QDir homeFolder(documentPath + "/BWIKI/ys/NPC-Editor/");
        homeFolder.mkpath(documentPath + "/BWIKI/ys/NPC-Editor/");
        QFile createConf(documentPath + "/BWIKI/ys/NPC-Editor/preferences.npcedit");
        createConf.open(QIODevice::ReadWrite);
    }

    QSettings* configHDPI = new QSettings(configPath, QSettings::IniFormat);
    QString getDisplayMode = configHDPI->value("Scale/Mode").toString();
    if (getDisplayMode == "Preview") {
        ui.dialogBox->setCurrentIndex(3);
        actualScale = configHDPI->value("Scale/Preview").toString();
        configHDPI->setValue("Scale/Mode", "Display");
    }
    else {
        ui.dialogBox->setCurrentIndex(0);
        actualScale = configHDPI->value("Scale/Display").toString();
    }
    if (actualScale == "") {
        ui.currentDPIResult->setText(QString::fromLocal8Bit("默认"));
    }
    else if (actualScale == "default") {
        ui.currentDPIResult->setText(QString::fromLocal8Bit("默认"));
    }
    else {
        QString DPIDisplay = actualScale + "x";
        ui.currentDPIResult->setText(DPIDisplay);
    }
    delete configHDPI;

    QButtonGroup* editorFont = new QButtonGroup(this);
    editorFont->addButton(ui.switchSerif);
    editorFont->addButton(ui.switchSans);
    ui.switchSerif->setChecked(1);

    QButtonGroup* syntaxHighlight = new QButtonGroup(this);
    syntaxHighlight->addButton(ui.openSyntanHighLighter);
    syntaxHighlight->addButton(ui.closeSyntaxHighlighter);
    ui.openSyntanHighLighter->setChecked(1);

    QButtonGroup* syntaxTip = new QButtonGroup(this);
    syntaxTip->addButton(ui.syntaxTipOn);
    syntaxTip->addButton(ui.syntaxTipOff);
    ui.syntaxTipOn->setChecked(1);

    ui.dialogBox->setCurrentIndex(0);
}

setup::~setup()
{}

void setup::on_startSetup_clicked() {
    ui.dialogBox->setCurrentIndex(1);
}

void setup::on_acceptLicense_clicked() {
    ui.dialogBox->setCurrentIndex(3);
}

void setup::on_denyLicense_clicked() {
    QApplication::exit();
}

void setup::on_startCleanSetup_clicked() {
    ui.dialogBox->setCurrentIndex(3);
}

void setup::on_DPISlider_sliderMoved() {
    int DPIInput = ui.DPISlider->sliderPosition();
    if (DPIInput == 0) {
        ui.sliderDPIResult->setText(QString::fromLocal8Bit("默认"));
    }
    else if (DPIInput == 1) {
        ui.sliderDPIResult->setText("1x");
        previewScale = "1";
    }
    else if (DPIInput == 2) {
        ui.sliderDPIResult->setText("1.25x");
        previewScale = "1.25";
    }
    else if (DPIInput == 3) {
        ui.sliderDPIResult->setText("1.5x");
        previewScale = "1.5";
    }
    else if (DPIInput == 4) {
        ui.sliderDPIResult->setText("1.75x");
        previewScale = "1.75";
    }
    else if (DPIInput == 5) {
        ui.sliderDPIResult->setText("2x");
        previewScale = "2";
    }
    else if (DPIInput == 6) {
        ui.sliderDPIResult->setText("2.25x");
        previewScale = "2.25";
    }
    else if (DPIInput == 7) {
        ui.sliderDPIResult->setText("2.5x");
        previewScale = "2.5";
    }
    else if (DPIInput == 8) {
        ui.sliderDPIResult->setText("2.75x");
        previewScale = "2.75";
    }
    else if (DPIInput == 9) {
        ui.sliderDPIResult->setText("3x");
        previewScale = "3";
    }
}

void setup::on_previewWindow_clicked() {
    QSettings* configHDPI = new QSettings(configPath, QSettings::IniFormat);
    configHDPI->setValue("Basic/type", "Settings");
    configHDPI->setValue("Basic/Section", "NPC-Editor");
    configHDPI->setValue("Basic/Minimun-Version", "3.2.0");
    configHDPI->setValue("Scale/Mode", "Preview");
    configHDPI->setValue("Scale/Preview", previewScale);
    delete configHDPI;

    QString appPath = QApplication::applicationFilePath();
    QProcess::startDetached(appPath);
    QApplication::exit();
}

void setup::on_switchToEditorFont_clicked() {
    QSettings* configHDPI = new QSettings(configPath, QSettings::IniFormat);
    configHDPI->setValue("Basic/type", "Settings");
    configHDPI->setValue("Basic/Section", "NPC-Editor");
    configHDPI->setValue("Basic/Minimun-Version", "3.2.0");
    configHDPI->setValue("Scale/Mode", "Display");
    configHDPI->setValue("Scale/Display", previewScale);
    delete configHDPI;
    ui.dialogBox->setCurrentIndex(4);
}

void setup::on_switchToScale_clicked() {
    ui.dialogBox->setCurrentIndex(3);
}

void setup::on_writeConfig_clicked() {
    QSettings* configSettings = new QSettings(configPath, QSettings::IniFormat);
    configSettings->setValue("Basic/type", "Settings");
    configSettings->setValue("Basic/Section", "NPC-Editor");
    configSettings->setValue("Basic/Minimun-Version", "3.2.0");
    configSettings->setValue("Export/Full-Info", "False");
    configSettings->setValue("Display/HDPI-Scale", "Enabled");
    configSettings->setValue("Display/Scale-Factor", "Override");
    if (ui.switchSerif->isChecked() == 1) {
        configSettings->setValue("Editor/Font", "Serif");
    }
    else {
        configSettings->setValue("Editor/Font", "Sans");
    }
    if (ui.openSyntanHighLighter->isChecked() == 1) {
        configSettings->setValue("Editor/SyntaxHighlighter", "Enabled");
    }
    else {
        configSettings->setValue("Editor/SyntaxHighlighter", "Disabled");
    }
    if (ui.syntaxTipOn->isChecked() == 1) {
        configSettings->setValue("Editor/SyntaxHint", "Enabled");
    }
    else {
        configSettings->setValue("Editor/SyntaxHint", "Disabled");
    }
    configSettings->setValue("Setup/Status", "Finished");
    ui.dialogBox->setCurrentIndex(5);
}

void setup::on_finishConf_clicked() {
    QApplication::exit();
}

void setup::on_startImportManager_clicked() {
    configImportPath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("导入配置"),"./", tr("Config(*.npcedit);;All files (*.*)"));
    if (configImportPath.isEmpty()) {
        return;
    }
    else {
        ui.dialogBox->setCurrentIndex(6);
    }
}