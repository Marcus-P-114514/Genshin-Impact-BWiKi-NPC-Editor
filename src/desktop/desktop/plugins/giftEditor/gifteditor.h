#pragma once

#include <QWidget>
#include "ui_gifteditor.h"

#include <QFontDatabase>
#include <QGraphicsDropShadowEffect>

class giftEditor : public QWidget
{
	Q_OBJECT

public:
	giftEditor(QWidget *parent = nullptr);
	~giftEditor();

private:
	Ui::giftEditorClass ui;
};
