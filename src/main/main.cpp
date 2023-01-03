#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QScreen>
#include <QString>
#include <QByteArray>
#include <QSettings>

int main(int argc, char *argv[])
{
    /**
    @brief: HDPI Scaling
    @brief: ����HDPI����
    **/
    QString configPath = "./config/global.conf";
    QSettings *HDPISettings = new QSettings (configPath, QSettings::IniFormat);
    QString HDPIOverrideStatus = HDPISettings->value ("HDPI/OverrideHDPI").toString();

    //Set fallback to "false", if the config file is missing then the return value is null so that it will fall back to no override HDPI by default.
    //把else设为“false”，如果配置文件不可用读取会返回空值，这么设置就可以默认不覆盖默认DPI设置
    if (HDPIOverrideStatus == "true") {
        QString HDPIScaleFactorRaw = HDPISettings->value("HDPI/CustomScaleFactor").toString();
        QByteArray HDPIScaleFactor = HDPIScaleFactorRaw.toLatin1();
        qputenv("QT_SCALE_FACTOR", HDPIScaleFactor);
        qDebug()<<HDPIScaleFactorRaw;
    }
    else {
        QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    delete HDPISettings;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /**
    @brief: Setup application font
    @brief: 设定程序字体
    **/
    int getFont = QFontDatabase::addApplicationFont("./font/SourceHanSansSC-Regular.ttf");
    QStringList targetList = QFontDatabase::applicationFontFamilies(getFont);
    QFont font(targetList.first());
    a.setFont(font);

    return a.exec();
}
