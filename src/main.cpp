#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QScreen>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int getFont = QFontDatabase::addApplicationFont("./font/SourceHanSansSC-Regular.ttf");
    QStringList targetList = QFontDatabase::applicationFontFamilies(getFont);
    QFont font(targetList.first());
    a.setFont(font);

    return a.exec();
}
