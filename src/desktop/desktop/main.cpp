#include "desktop.h"
#include <QtWidgets/QApplication>
#include <QFontDatabase>
#include <QStandardPaths>
#include <QSettings>

QString configPath = QStandardPaths::locate(QStandardPaths::DocumentsLocation, "BWIKI/ys/NPC-Editor/preferences.npcedit");

int main(int argc, char *argv[])
{
    QSettings* configDPI = new QSettings(configPath, QSettings::IniFormat);
    QString displayMode = configDPI->value("Scale/Mode").toString();
    QString targetDPI;
    if (displayMode == "Preview") {
        targetDPI = configDPI->value("Scale/Preview").toString();
    }
    else {
        targetDPI = configDPI->value("Scale/Display").toString();
    }
    if (targetDPI == "default") {
        QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    else if (targetDPI == "1") {
        qputenv("QT_SCALE_FACTOR", "1");
    }
    else if (targetDPI == "1.25") {
        qputenv("QT_SCALE_FACTOR", "1.25");
    }
    else if (targetDPI == "1.5") {
        qputenv("QT_SCALE_FACTOR", "1.5");
    }
    else if (targetDPI == "1.75") {
        qputenv("QT_SCALE_FACTOR", "1.75");
    }
    else if (targetDPI == "2") {
        qputenv("QT_SCALE_FACTOR", "2");
    }
    else if (targetDPI == "2.25") {
        qputenv("QT_SCALE_FACTOR", "2.25");
    }
    else if (targetDPI == "2.5") {
        qputenv("QT_SCALE_FACTOR", "2.5");
    }
    else if (targetDPI == "2.75") {
        qputenv("QT_SCALE_FACTOR", "2.75");
    }
    else if (targetDPI == "3") {
        qputenv("QT_SCALE_FACTOR", "3");
    }
    else {
        QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    delete configDPI;

    QApplication a(argc, argv);
    desktop w;
    w.show();

    int getFont = QFontDatabase::addApplicationFont(":/fonts/resources/SourceHanSansCN-Regular.otf");
    QStringList targetList = QFontDatabase::applicationFontFamilies(getFont);
    QFont font(targetList.first());
    a.setFont(font);

    return a.exec();
}
