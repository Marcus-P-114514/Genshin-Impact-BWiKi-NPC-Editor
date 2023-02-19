#include "gifteditor.h"

giftEditor::giftEditor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);

	int getFontSansRegular = QFontDatabase::addApplicationFont(":/fonts/resources/SourceHanSansCN-Regular.otf");
	QStringList targetListSansRegular = QFontDatabase::applicationFontFamilies(getFontSansRegular);
	QFont sansRegular(targetListSansRegular.first());
	this->setFont(sansRegular);

	QGraphicsDropShadowEffect* dialogShadow = new QGraphicsDropShadowEffect(this);
	dialogShadow->setOffset(0, 0);
	dialogShadow->setColor(QColor(178, 115, 43, 109));
	dialogShadow->setBlurRadius(25);
	ui.pluginContainer->setGraphicsEffect(dialogShadow);
}

giftEditor::~giftEditor()
{}
