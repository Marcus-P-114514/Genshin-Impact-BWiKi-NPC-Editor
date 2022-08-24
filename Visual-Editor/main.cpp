#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "NPC-Handler_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    int fontId = QFontDatabase::addApplicationFont("E:/interface.ttc");
        QString target_font = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont app_font(target_font);
        QApplication::setFont(app_font);

    MainWindow w;
    w.show();
    return a.exec();
}
