#include "workingarea.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFontDatabase>
#include <QIODevice>
#include <QFile>

void FontsSerif() {
    int index = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/SourceHanSerifSC-Regular.otf");
    qDebug()<<"index="<<index;
    if(index != -1) {
        QStringList fontList(QFontDatabase::applicationFontFamilies(index));
        if(fontList.count() > 0) {
            //思源宋体Font Family：Source Han Serif SC
        }
    }
}

void FontsSans() {
    int index = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/SourceHanSansCN-Regular.otf");
    qDebug()<<"index="<<index;
    if(index != -1) {
        QStringList fontList(QFontDatabase::applicationFontFamilies(index));
        if(fontList.count() > 0) {
            //思源黑体Font Family：Source Han Sans CN
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Load Fonts
    FontsSerif();
    FontsSans();

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "NPC-Handler_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    WorkingArea w;
    w.show();
    return a.exec();
}
