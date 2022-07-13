#include "setupwizard.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QStyleFactory>
#include <QFontDatabase>
#include <QIODevice>
#include <QFile>

void FontsSerif() {
    int index = QFontDatabase::addApplicationFont(":/fonts/resources/fonts/Heavy.otf");
    if(index != -1) {
        QStringList fontList(QFontDatabase::applicationFontFamilies(index));
        if(fontList.count() > 0) {
            qDebug()<<"font family: "<<fontList.at(0);
            //思源宋体Font Family：Source Han Serif SC
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Setup-Wizard_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    FontsSerif();
    SetupWizard w;
    w.show();
    return a.exec();
}
