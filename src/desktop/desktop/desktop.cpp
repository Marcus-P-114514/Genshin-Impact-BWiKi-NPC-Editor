#include "desktop.h"

desktop::desktop(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

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
}

desktop::~desktop()
{}
