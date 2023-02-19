#include "desktop.h"

desktop::desktop(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);

    QGraphicsDropShadowEffect* dialogShadow = new QGraphicsDropShadowEffect(this);
    dialogShadow->setOffset(0, 0);
    dialogShadow->setColor(QColor(178, 115, 43, 109));
    dialogShadow->setBlurRadius(25);
    ui.frameContainer->setGraphicsEffect(dialogShadow);

    int getFontSansRegular = QFontDatabase::addApplicationFont(":/fonts/resources/SourceHanSansCN-Regular.otf");
    QStringList targetListSansRegular = QFontDatabase::applicationFontFamilies(getFontSansRegular);
    QFont sansRegular(targetListSansRegular.first());

    int getFontSansBold = QFontDatabase::addApplicationFont(":/fonts/resources/SourceHanSansCN-Bold.otf");
    QStringList targetListSansBold = QFontDatabase::applicationFontFamilies(getFontSansBold);
    QFont sansBold(targetListSansBold.first());

    int getFontSansHeavy = QFontDatabase::addApplicationFont(":/fonts/resources/SourceHanSansCN-Heavy.otf");
    QStringList targetListSansHeavy = QFontDatabase::applicationFontFamilies(getFontSansHeavy);
    QFont sansHeavy(targetListSansHeavy.first());

    ui.appTitle->setFont(sansHeavy);

    QSettings* configSetup = new QSettings(configPath, QSettings::IniFormat);
    QString setupStatus = configSetup->value("Setup/Status").toString();
    if (setupStatus != "Finished") {
        reportFatalError(QString::fromLocal8Bit("初始化错误"), QString::fromLocal8Bit("没有检测到有效的配置，可能是您没有初始化。\n请运行“配置程序”，Windows版通常可以在安装目录找到。Mac版可以在dmg文件内找到，Linux版则需要自行编译。"));
    }

    ui.SideBarContent->setCurrentIndex(0);
    ui.VEApp->setCurrentIndex(0);

}

desktop::~desktop()
{}

void desktop::reportFatalError(QString titleTextSend, QString contentTextSend) {
    ui.visualEditorApp->hide();
    ui.codeEditorApp->hide();
    fatalErrorDialog* fatalErr = new fatalErrorDialog(this);
    connect(this, &desktop::sendFatalErrorTitle, fatalErr, &fatalErrorDialog::getFatalErrorTitle);
    connect(this, &desktop::sendFatalErrorContent, fatalErr, &fatalErrorDialog::getFatalErrorContent);
    emit sendFatalErrorTitle(titleTextSend);
    emit sendFatalErrorContent(contentTextSend);
    fatalErr->show();
    int dialogX = this->width() / 2 - (448 / 2);
    int dialogY = this->height() / 2 - (180 / 2);
    fatalErr->move(dialogX, dialogY);
}

void desktop::on_trigMultipleGift_clicked() {
    giftEditor* editGift = new giftEditor(this);
    editGift->show();
    int giftEditorX = this->width() / 2 - (600 / 2);
    int giftEditorY = this->height() / 2 - (400 / 2);
    editGift->move(giftEditorX, giftEditorY);
}

void desktop::updateVisualEditorPage() {
    if (visualEditorPage == 1) {
        ui.VEApp->setCurrentIndex(0);
        ui.basicInfoSwitcherIcon->setChecked(1);
        ui.basicInfoSwitcher->setChecked(1);
    }
    else {
        ui.basicInfoSwitcherIcon->setChecked(0);
        ui.basicInfoSwitcher->setChecked(0);
    }

    if (visualEditorPage == 2) {
        ui.VEApp->setCurrentIndex(1);
        ui.storeSwitcherIcon->setChecked(1);
        ui.storeSwitcher->setChecked(1);
    }
    else {
        ui.storeSwitcherIcon->setChecked(0);
        ui.storeSwitcher->setChecked(0);
    }
}

void desktop::on_basicInfoSwitcherIcon_clicked(){
    visualEditorPage = 1;
    updateVisualEditorPage();
}

void desktop::on_basicInfoSwitcher_clicked() {
    visualEditorPage = 1;
    updateVisualEditorPage();
}

void desktop::on_storeSwitcherIcon_clicked() {
    visualEditorPage = 2;
    updateVisualEditorPage();
}

void desktop::on_storeSwitcher_clicked() {
    visualEditorPage = 2;
    updateVisualEditorPage();
}