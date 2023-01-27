#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_desktop.h"

#include <QFontDatabase>

class desktop : public QMainWindow
{
    Q_OBJECT

public:
    desktop(QWidget *parent = nullptr);
    ~desktop();

private:
    Ui::desktopClass ui;
};
