#include "npcgifteditor.h"
#include "ui_npcgifteditor.h"

npcGiftEditor::npcGiftEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::npcGiftEditor)
{
    ui->setupUi(this);

    QDateTime currentTime1 = QDateTime::currentDateTime();
    QString CurrentTimeOut1 = currentTime1.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut1 + "] NPC Gift Editor: Try to initialize dialog...\n";

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *dialogShadow = new QGraphicsDropShadowEffect(this);
    dialogShadow->setOffset(0, 0);
    dialogShadow->setColor(QColor(178,115,43,109));
    dialogShadow->setBlurRadius(25);
    ui->frame->setGraphicsEffect(dialogShadow);

    QDateTime currentTime2 = QDateTime::currentDateTime();
    QString CurrentTimeOut2 = currentTime2.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut2 + "] NPC Gift Editor: Try to load font...\n";

    int getFontSerif = QFontDatabase::addApplicationFont("./font/SourceHanSerifCN-Regular.ttf");
    QStringList serifList = QFontDatabase::applicationFontFamilies(getFontSerif);
    QFont fontSerif(serifList.first());
    ui->npcGiftCodeOut->setFont(fontSerif);
    ui->label_3->setFont(fontSerif);
    ui->label_4->setFont(fontSerif);
    ui->npcGiftNameEdit->setFont(fontSerif);
    ui->npcGiftAmountEdit->setFont(fontSerif);
    ui->insertGift->setFont(fontSerif);
    ui->clearGift->setFont(fontSerif);

    QDateTime currentTime3 = QDateTime::currentDateTime();
    QString CurrentTimeOut3 = currentTime3.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut3 + "] NPC Gift Editor: Initialization finish, waiting user response...\n";

}

npcGiftEditor::~npcGiftEditor()
{
    QDateTime currentTime4 = QDateTime::currentDateTime();
    QString CurrentTimeOut4 = currentTime4.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut4 + "] NPC Gift Editor: Closing dialog...\n";

    delete ui;
}

void npcGiftEditor::on_clearGift_clicked()
{
    ui->npcGiftCodeOut->clear();

    QDateTime currentTime5 = QDateTime::currentDateTime();
    QString CurrentTimeOut5 = currentTime5.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut5 + "] NPC Gift Editor: Code Area Cleared...\n";
}


void npcGiftEditor::on_insertGift_clicked()
{
    currentGiftName = ui->npcGiftNameEdit->text();
    currentGiftAmount = ui->npcGiftAmountEdit->text();
    if (currentGiftAmount == "" || currentGiftName == ""){
        ui->npcGiftStatus->setText("插入数据失败：请检查NPC礼物名称和数量输入框 - 检测到留空");
        ui->npcGiftStatus->setStyleSheet("color: #F44336;");

        QDateTime currentTime6 = QDateTime::currentDateTime();
        QString CurrentTimeOut6 = currentTime6.toString("hh:mm:ss");
        npcGiftLog = npcGiftLog + "[" + CurrentTimeOut6 + "] NPC Gift Editor: Error detected. Either gift name or amount is blank, aborting inserting data...\n";
    }
    else{
        ui->npcGiftStatus->setText("请注意：使用NPC赠礼编辑器保存后赠礼栏将会显示[MULTIPLE]，此后该工程的NPC赠礼部分将只能由\"NPC赠礼编辑器\"处理。");
        ui->npcGiftStatus->setStyleSheet("color: #202122;");
        ui->npcGiftCodeOut->insertPlainText("{{NPC图标|");
        ui->npcGiftCodeOut->insertPlainText(currentGiftName);
        ui->npcGiftCodeOut->insertPlainText("|");
        ui->npcGiftCodeOut->insertPlainText(currentGiftAmount);
        ui->npcGiftCodeOut->insertPlainText("}} ");
        QDateTime currentTime7 = QDateTime::currentDateTime();
        QString CurrentTimeOut7 = currentTime7.toString("hh:mm:ss");
        npcGiftLog = npcGiftLog + "[" + CurrentTimeOut7 + "] NPC Gift Editor: Successfully get data from the form, inserting...\n";
    }
}


void npcGiftEditor::on_discardGift_clicked()
{
    ui->npcGiftCodeOut->clear();
    ui->npcGiftNameEdit->clear();
    ui->npcGiftAmountEdit->clear();
    npcGiftEditor::close();

    QDateTime currentTime8 = QDateTime::currentDateTime();
    QString CurrentTimeOut8 = currentTime8.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut8 + "] NPC Gift Editor: User abort. Discarding changes...\n";

    emit sendGiftLog(npcGiftLog);
}


void npcGiftEditor::on_commitGift_clicked()
{
    QDateTime currentTime9 = QDateTime::currentDateTime();
    QString CurrentTimeOut9 = currentTime9.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut9 + "] NPC Gift Editor: Writing cache files...\n";

    QSettings *configID = new QSettings ("./config/global.conf", QSettings::IniFormat);
    QString cacheID = configID->value("Cache/ID").toString();
    delete configID;
    QString cacheTarget = "./cache/plugins/giftEditor/npc_gift_edit_" + cacheID + ".npcedit";
    QString currentOutput = ui->npcGiftCodeOut->toPlainText();
    QSettings *configCache = new QSettings (cacheTarget, QSettings::IniFormat);
    configCache->setValue("Info/Editor", "NPC-Editor");
    configCache->setValue("Info/Type", "Cache");
    configCache->setValue("Cache/Gift",currentOutput);
    configCache->setValue("Log/Out", npcGiftLog);
    delete configCache;

    QDateTime currentTime10 = QDateTime::currentDateTime();
    QString CurrentTimeOut10 = currentTime10.toString("hh:mm:ss");
    npcGiftLog = npcGiftLog + "[" + CurrentTimeOut10 + "] NPC Gift Editor: Finished writing, closing dialog...\n";

    emit sendGiftLog(npcGiftLog);

    this->hide();
}

