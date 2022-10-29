#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Started." << endl;
    char* inputPath = argv[1];
    QString targetPath = QString::fromLocal8Bit(inputPath);
    qDebug() << "Target Path: " << targetPath << "." << endl;

    QFile openDefault("./config/arguments.conf");
    if(openDefault.open(QIODevice::WriteOnly |QIODevice::Text)){
        QTextStream targetContent(&openDefault);
        targetContent << targetPath;
        openDefault.close();
        qDebug() << "Finished: Writing arguments." << endl;

        qDebug() << "Opening application..." << endl;
        QProcess startApp;
        startApp.startDetached("./NPC图鉴编辑器.exe");
        startApp.startDetached("./refresh.cmd");
    }
    else{
        qDebug() << "Failed: Writing arguments.\nAborted." << endl;
    }
    QCoreApplication::exit();
    return a.exec();
}
