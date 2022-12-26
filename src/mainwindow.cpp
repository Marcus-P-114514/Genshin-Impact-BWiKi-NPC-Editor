#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateTime currentTime1 = QDateTime::currentDateTime();
    QString CurrentTimeOut1 = currentTime1.toString("hh:mm:ss");
    currentLog = "[" + CurrentTimeOut1 + "] NPC Editor: Initializing...\n";
    ui->logOut->insertPlainText(currentLog);

    //Windows下解决HDPI问题
    //qputenv("QT_SCALE_FACTOR", "1.5");

    //Detect .lck file and initialize config
    QDateTime currentTime2 = QDateTime::currentDateTime();
    QString CurrentTimeOut2 = currentTime2.toString("hh:mm:ss");
    currentLog = "[" + CurrentTimeOut2 + "] NPC Editor: Checking application.lck...\n";
    ui->logOut->insertPlainText(currentLog);

    QFileInfo lckInfo("./application.lck");
    if(lckInfo.isFile()){
        ui->visualEditorSwitchPreviousPage->setVisible(0);
        ui->visualEditorTitle->setVisible(0);
        ui->visualEditorSwitchNextPage->setVisible(0);
        ui->visualEditorSpacer->setVisible(0);
        ui->visualEditor->setVisible(0);
        errAlreadyRunning *applicationAlreadyRunning = new errAlreadyRunning;
        applicationAlreadyRunning->show();

        QDateTime currentTime3 = QDateTime::currentDateTime();
        QString CurrentTimeOut3 = currentTime3.toString("hh:mm:ss");
        currentLog = "[" + CurrentTimeOut3 + "] NPC Editor: Error: Application already running. Aborting...\n";
        ui->logOut->insertPlainText(currentLog);
    }
    else{
        QDateTime currentTime4 = QDateTime::currentDateTime();
        QString CurrentTimeOut4 = currentTime4.toString("hh:mm:ss");
        currentLog = "[" + CurrentTimeOut4 + "] NPC Editor: Creating application.lck...\n";
        ui->logOut->insertPlainText(currentLog);

        QFile appendLck("./application.lck");
        appendLck.open(QIODevice::WriteOnly);
        appendLck.close();

        QDateTime currentTime5 = QDateTime::currentDateTime();
        QString CurrentTimeOut5 = currentTime5.toString("hh:mm:ss");
        currentLog = "[" + CurrentTimeOut5 + "] NPC Editor: Getting cache ID...\n";
        ui->logOut->insertPlainText(currentLog);

        QSettings *configProfile = new QSettings ("./config/global.conf", QSettings::IniFormat);
        QString cacheIDOldRead = configProfile->value("Cache/ID").toString();
        int cacheID;
        if (cacheIDOldRead == ""){
            cacheID = 1;
        }
        else{
            int cacheIDOld = cacheIDOldRead.toInt();
            cacheID = cacheIDOld + 1;
        }
        QString cacheIDWrite = QString::number(cacheID);
        configProfile->setValue("Cache/ID", cacheIDWrite);

        delete configProfile;
    }

    //Set up Titlebar UI
    QDateTime currentTime6 = QDateTime::currentDateTime();
    QString CurrentTimeOut6 = currentTime6.toString("hh:mm:ss");
    currentLog = "[" + CurrentTimeOut6 + "] NPC Editor: Loading Font...\n";
    ui->logOut->insertPlainText(currentLog);

    int getTitleBarFont = QFontDatabase::addApplicationFont("./font/SourceHanSansSC-Regular.ttf");
    QStringList titleBarTargetList = QFontDatabase::applicationFontFamilies(getTitleBarFont);
    QFont titleBarFont(titleBarTargetList.first());

    int getFontSerif = QFontDatabase::addApplicationFont("./font/SourceHanSerifCN-Regular.ttf");
    QStringList serifList = QFontDatabase::applicationFontFamilies(getFontSerif);
    QFont fontSerif(serifList.first());

    ui->appTitle->setFont(titleBarFont);
    ui->versionDisp->setFont(titleBarFont);

    //Setup Card Shadow
    QDateTime currentTime7 = QDateTime::currentDateTime();
    QString CurrentTimeOut7 = currentTime7.toString("hh:mm:ss");
    currentLog = "[" + CurrentTimeOut7 + "] NPC -Editor: Setting up working area...\n";
    ui->logOut->insertPlainText(currentLog);

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
    ui->npcMultipleGiftEdit->setVisible(0);

    //Hide NPC Store Edit
    ui->npcStoreEdit->setVisible(0);

    //Setup Visual Editor
    ui->visualEditor->setCurrentIndex(1);

    //Setup Code Editor
    ui->workingAreaR->setCurrentIndex(1);
    ui->logOut->setFont(fontSerif);

    QDateTime currentTime8 = QDateTime::currentDateTime();
    QString CurrentTimeOut8 = currentTime8.toString("hh:mm:ss");
    currentLog = "[" + CurrentTimeOut8 + "] NPC Editor: Initializing finished, waiting user response...\n";
    ui->logOut->insertPlainText(currentLog);
}


MainWindow::~MainWindow()
{
    QFile removeLck("./application.lck");
    removeLck.remove();
    removeLck.close();
    delete ui;
}

void MainWindow::appendLog(QString logContent)
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString CurrentTimeOut = currentTime.toString("hh:mm:ss");
    currentLog = "[" + CurrentTimeOut + "] NPC Editor: " + logContent + "\n";
    ui->logOut->insertPlainText(currentLog);
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
        appendLog("Showing NPC dialog gift options...");
        ui->npcDialogGiftNameEdit->setVisible(1);
        ui->npcGiftEditLabel->setVisible(1);
        ui->npcDialogGiftAmountEdit->setVisible(1);
        ui->npcMultipleGiftEdit->setVisible(1);
    }
    else{
        appendLog("Hiding NPC gift options...");
        ui->npcDialogGiftNameEdit->setVisible(0);
        ui->npcGiftEditLabel->setVisible(0);
        ui->npcDialogGiftAmountEdit->setVisible(0);
        ui->npcMultipleGiftEdit->setVisible(0);
    }
}


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
        appendLog("Visual Editor - Page switched to Page 1.");
    }
}


void MainWindow::on_visualEditorSwitchNextPage_clicked()
{
    int visualEditorCurrentIndexN = ui->visualEditor->currentIndex();
    //if Visual Editor @Basic Info
    if (visualEditorCurrentIndexN == 1){
        ui->visualEditor->setCurrentIndex(0);
        ui->visualEditorTitle->setText("可视化编辑 · 商店");
        appendLog("Visual Editor - Page switched to Page 2.");
    }
}


void MainWindow::on_npcMultipleGiftEdit_clicked()
{
    ui->npcDialogGiftNameEdit->setText("[MULTIPLE]");
    ui->npcDialogGiftAmountEdit->setText("[MULTIPLE]");
    appendLog("Setting NPC Gift as \"multiple\"...");
    npcGiftEditor *multipleGiftEditor = new npcGiftEditor;
    connect(multipleGiftEditor, SIGNAL(sendGiftLog(QString)), this, SLOT(receiveGiftLog(QString)));
    multipleGiftEditor->show();
}

void MainWindow::receiveGiftLog(QString giftLogReceived)
{
    ui->logOut->insertPlainText(giftLogReceived);
}

void MainWindow::on_npcStoreExistEdit_currentTextChanged(const QString &arg1)
{
    npcStoreExist = ui->npcStoreExistEdit->currentText();
    if (npcStoreExist == "不存在"){
        appendLog("Hiding NPC Store options...");
        ui->npcStoreEdit->setVisible(0);
    }
    else{
        appendLog("Showing NPC Store options...");
        ui->npcStoreEdit->setVisible(1);
    }
}

