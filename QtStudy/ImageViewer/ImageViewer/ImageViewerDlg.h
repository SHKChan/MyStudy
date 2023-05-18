#pragma once

#include <QtWidgets/QDialog>
#include "ui_ImageViewerDlg.h"

class ImageViewerDlg : public QDialog
{
    Q_OBJECT

public:
    ImageViewerDlg(QWidget *parent = Q_NULLPTR);

private slots:
	//信号与槽可自动根据名字进行链接,\
	格式为:\
	on_<object_name>_<signal_name>(<signal parameters>);
	void on_pushButtonPrev_clicked();
	void on_pushButtonNext_clicked();

private:
	//绘图时间处理函数(虚函数)
	void paintEvent(QPaintEvent *event);
	//通过过滤器，实现在窗口子部件上直接绘图
	bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::ImageViewerDlgClass ui;
	int m_idx;
};
