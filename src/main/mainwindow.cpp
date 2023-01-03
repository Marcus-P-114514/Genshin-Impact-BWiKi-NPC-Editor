#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**
    @brief: Set up titlebar UI
    @brief: 设定标题栏界面
    **/
    int getTitleBarFont = QFontDatabase::addApplicationFont("./font/SourceHanSansSC-Regular.ttf");
    QStringList titleBarTargetList = QFontDatabase::applicationFontFamilies(getTitleBarFont);
    QFont titleBarFont(titleBarTargetList.first());

    int getFontSerif = QFontDatabase::addApplicationFont("./font/SourceHanSerifCN-Regular.ttf");
    QStringList serifList = QFontDatabase::applicationFontFamilies(getFontSerif);
    QFont fontSerif(serifList.first());

    ui->appTitle->setFont(titleBarFont);
    ui->versionDisp->setFont(titleBarFont);

    /**
    @brief: Set up card shadow
    @brief: 设定卡片阴影
    **/
    QGraphicsDropShadowEffect *cardShadow = new QGraphicsDropShadowEffect(this);
    cardShadow->setOffset(0, 0);
    cardShadow->setColor(QColor(178,115,43));
    cardShadow->setBlurRadius(10);
    ui->visualEditorApp->setGraphicsEffect(cardShadow);
    ui->codeEditorApp->setGraphicsEffect(cardShadow);

    /**
    @brief: Set up working area
    @brief: 设定卡工作区域
    **/
    ui->appInnerBoxL->setParent(ui->appOutterBoxL);

    /**
    @brief: Hide NPC Gift Edit
    @brief: 隐藏NPC多重赠礼编辑框
    **/
    ui->npcDialogGiftNameEdit->setVisible(0);
    ui->npcGiftEditLabel->setVisible(0);
    ui->npcDialogGiftAmountEdit->setVisible(0);
    ui->npcMultipleGiftEdit->setVisible(0);

    /**
    @brief: Hide NPC Store
    @brief: 隐藏NPC商店
    **/
    ui->npcStoreEdit->setVisible(0);

    /**
    @brief: Setup visual editor
    @brief: 设置可视化编辑器
    **/
    ui->visualEditor->setCurrentIndex(1);

    /**
    @brief: Setup code editor
    @brief: 设置代码编辑器
    **/
    ui->workingAreaR->setCurrentIndex(1);
    ui->logOut->setFont(fontSerif);
}


MainWindow::~MainWindow()
{
    delete ui;
}

/**
@brief: Switch Sidebar / 切换侧边栏状态
@params: void
**/
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

/**
@brief: Resize Event / 窗口缩放
@params: systemResize
**/
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
    if (npcGiftExist == "存在"){
        ui->npcDialogGiftNameEdit->setVisible(1);
        ui->npcGiftEditLabel->setVisible(1);
        ui->npcDialogGiftAmountEdit->setVisible(1);
        ui->npcMultipleGiftEdit->setVisible(1);
    }
    else{
        ui->npcDialogGiftNameEdit->setVisible(0);
        ui->npcGiftEditLabel->setVisible(0);
        ui->npcDialogGiftAmountEdit->setVisible(0);
        ui->npcMultipleGiftEdit->setVisible(0);
    }
}

/**
@brief: Switch to previous page for visual editor / 可视化编辑·上一页
@params: void
**/
void MainWindow::on_visualEditorSwitchPreviousPage_clicked()
{
    int visualEditorCurrentIndex = ui->visualEditor->currentIndex();
    //if Visual Editor @Basic Info
    if (visualEditorCurrentIndex == 1){

    }
    //if Visual Editor @Store
    else if (visualEditorCurrentIndex == 0){
        ui->visualEditor->setCurrentIndex(1);
        ui->visualEditorTitle->setText("可视化编辑 · 基本信息");
    }
}

/**
@brief: Switch to next page for visual editor / 可视化编辑·下一页
@params: void
**/
void MainWindow::on_visualEditorSwitchNextPage_clicked()
{
    int visualEditorCurrentIndexN = ui->visualEditor->currentIndex();
    //if Visual Editor @Basic Info
    if (visualEditorCurrentIndexN == 1){
        ui->visualEditor->setCurrentIndex(0);
        ui->visualEditorTitle->setText("可视化编辑 · 商店");
    }
}

/**
@brief: Enable multiple gift editor / NPC有多重赠礼
@params: void
**/
void MainWindow::on_npcMultipleGiftEdit_clicked()
{
    ui->npcDialogGiftNameEdit->setText("[MULTIPLE]");
    ui->npcDialogGiftAmountEdit->setText("[MULTIPLE]");
    npcGiftEditor *multipleGiftEditor = new npcGiftEditor;
    connect(multipleGiftEditor, SIGNAL(sendGiftLog(QString)), this, SLOT(receiveGiftLog(QString)));
    multipleGiftEditor->show();
}

/**
@brief: Gift Editor log receiver / NPC赠礼编辑器的日志接收器
@params: giftLogReceived
**/
void MainWindow::receiveGiftLog(QString giftLogReceived)
{
    ui->logOut->insertPlainText(giftLogReceived);
}

/**
@brief: Enable NPC store editor / 启用NPC商店编辑器
@params: void
**/
void MainWindow::on_npcStoreExistEdit_currentTextChanged(const QString &arg1)
{
    npcStoreExist = ui->npcStoreExistEdit->currentText();
    if (npcStoreExist == "不存在"){
        ui->npcStoreEdit->setVisible(0);
    }
    else{
        ui->npcStoreEdit->setVisible(1);
    }
}

