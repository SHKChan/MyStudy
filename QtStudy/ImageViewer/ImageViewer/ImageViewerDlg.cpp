#include "ImageViewerDlg.h"
//#include <QMessageBox>
//#include <QDebug>
#include <QPainter>

ImageViewerDlg::ImageViewerDlg(QWidget *parent)
    : QDialog(parent)
	, m_idx(1)
{
    ui.setupUi(this);
	// ȥ��"?", ���"-"&"��"
	Qt::WindowFlags windowFlag = Qt::Dialog;
	windowFlag |= Qt::WindowMinimizeButtonHint;
	windowFlag |= Qt::WindowMaximizeButtonHint;
	windowFlag |= Qt::WindowCloseButtonHint;
	setWindowFlags(windowFlag);
	ui.frame->installEventFilter(this);        //��װ�¼�������������
}

void ImageViewerDlg::on_pushButtonNext_clicked()
{
	//QMessageBox::information(this, "Debug","", QMessageBox::Ok);
	if (++m_idx > 20)
		m_idx = 1;
	update();
}

void ImageViewerDlg::on_pushButtonPrev_clicked()
{
	//QMessageBox::information(this, "Debug", "", QMessageBox::Ok);
	if (--m_idx <= 0)
		m_idx = 20;
	update();
}

void ImageViewerDlg::paintEvent(QPaintEvent *event)
{
	//qDebug("paintEvent");
	//1)
	QPainter painter(ui.frame);
	//2)
	QRect rect = ui.frame->frameRect();
	//rect.translate(ui.frame->pos());
	//3)
	QImage image("bmp\\"+QString::number(m_idx)+".bmp");
	//4)
	painter.drawImage(rect, image);
}

bool ImageViewerDlg::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == ui.frame  && event->type() == QEvent::Paint)
	{
		paintEvent((QPaintEvent *)event); //��Ӧ����
		return true;
	}

	return QWidget::eventFilter(watched, event);
}