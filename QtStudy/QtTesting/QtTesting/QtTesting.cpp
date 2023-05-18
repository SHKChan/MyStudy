#include "QtTesting.h"

QtTesting::QtTesting(QWidget *parent)
    : QWidget(parent)
	, m_bIsPressed(false)
{
	ui.setupUi(this);
	//È¥³ý"?", Ìí¼Ó"-"&"¡õ"
	Qt::WindowFlags windowFlag = Qt::Dialog;
	windowFlag |= Qt::WindowMinimizeButtonHint;
	windowFlag |= Qt::WindowMaximizeButtonHint;
	windowFlag |= Qt::WindowCloseButtonHint;
	setWindowFlags(windowFlag);
}

void QtTesting::on_pushButton_clicked()
{
	if (m_bIsPressed)
	{
		ui.label->setVisible(false);
	}
	else
	{
		ui.label->setVisible(true);
	}
	m_bIsPressed = !m_bIsPressed;
}
