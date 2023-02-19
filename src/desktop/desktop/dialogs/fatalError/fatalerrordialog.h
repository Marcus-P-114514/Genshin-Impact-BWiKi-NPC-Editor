#pragma once

#include <QWidget>
#include <QFontDatabase>
#include <QGraphicsDropShadowEffect>
#include "ui_fatalerrordialog.h"


class fatalErrorDialog : public QWidget
{
	Q_OBJECT

public:
	fatalErrorDialog(QWidget *parent = nullptr);
	~fatalErrorDialog();
	void getFatalErrorTitle(QString titleText);
	void getFatalErrorContent(QString contentText);

private:
	Ui::fatalErrorDialogClass ui;

private slots:
	void on_forceExit_clicked();
};
