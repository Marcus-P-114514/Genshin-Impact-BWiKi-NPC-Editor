#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Windows下解决HDPI问题
    //qputenv("QT_SCALE_FACTOR", "1.5");

    //Set up Titlebar UI
    int getTitleBarFont = QFontDatabase::addApplicationFont("./font/SourceHanSansSC-Regular.ttf");
    QStringList titleBarTargetList = QFontDatabase::applicationFontFamilies(getTitleBarFont);
    QFont titleBarFont(titleBarTargetList.first());
    ui->appTitle->setFont(titleBarFont);
    ui->versionDisp->setFont(titleBarFont);

    //Setup Card Shadow
    QGraphicsDropShadowEffect *cardShadow = new QGraphicsDropShadowEffect(this);
    cardShadow->setOffset(0, 0);
    cardShadow->setColor(QColor(178,115,43));
    cardShadow->setBlurRadius(10);
    ui->visualEditorApp->setGraphicsEffect(cardShadow);
    ui->codeEditorApp->setGraphicsEffect(cardShadow);

    //Setup Working Area
    ui->appInnerBoxL->setParent(ui->appOutterBoxL);

    //Hide NPC Gift Edit
    ui->npcDialogGiftNameEdit->setVisible(0);
    ui->npcGiftEditLabel->setVisible(0);
    ui->npcDialogGiftAmountEdit->setVisible(0);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void initSideBar(){
}

void MainWindow::on_sideBarSwitcher_clicked()
{
    if (sideBarStatus == "active"){
        ui->sideBar->setVisible(0);
        ui->sideBarInnerBox->setVisible(0);
        ui->sideBarOutterBox->setVisible(0);
        sideBarStatus = "hidden";
    }
    else if (sideBarStatus == "hidden"){
        ui->sideBar->setVisible(1);
        ui->sideBarInnerBox->setVisible(1);
        ui->sideBarOutterBox->setVisible(1);
        sideBarStatus = "active";
    }
    else {
        errSideBarStatus *errForm1 = new errSideBarStatus;
        errForm1->show();
    }
}

void MainWindow::resizeEvent(QResizeEvent *systemResize)
{
    if (ui->centralwidget->geometry().width()>1024){
        ui->codeEditorApp->setVisible(1);
    }
    else{
        ui->codeEditorApp->setVisible(0);
    }
}

void MainWindow::on_npcDialogGiftExist_currentTextChanged(const QString &arg1)
{
    npcGiftExist = ui->npcDialogGiftExist->currentText();
    //if NPC Gift exists
    if (npcGiftExist == "存在"){
        ui->npcDialogGiftNameEdit->setVisible(1);
        ui->npcGiftEditLabel->setVisible(1);
        ui->npcDialogGiftAmountEdit->setVisible(1);
    }
    else{
        ui->npcDialogGiftNameEdit->setVisible(0);
        ui->npcGiftEditLabel->setVisible(0);
        ui->npcDialogGiftAmountEdit->setVisible(0);
    }
}

