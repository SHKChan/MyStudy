#pragma once

#include <QtWidgets/QDialog>
#include "ui_ImageViewerDlg.h"

class ImageViewerDlg : public QDialog
{
    Q_OBJECT

public:
    ImageViewerDlg(QWidget *parent = Q_NULLPTR);

private slots:
	//�ź���ۿ��Զ��������ֽ�������,\
	��ʽΪ:\
	on_<object_name>_<signal_name>(<signal parameters>);
	void on_pushButtonPrev_clicked();
	void on_pushButtonNext_clicked();

private:
	//��ͼʱ�䴦����(�麯��)
	void paintEvent(QPaintEvent *event);
	//ͨ����������ʵ���ڴ����Ӳ�����ֱ�ӻ�ͼ
	bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::ImageViewerDlgClass ui;
	int m_idx;
};
