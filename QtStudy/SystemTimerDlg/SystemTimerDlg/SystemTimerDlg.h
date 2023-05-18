#ifndef __SYSTEMTIMERDLG_H__
#define __SYSTEMTIMERDLG_H__

#pragma once
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>	//垂直布局器控件
#include <QTime>	//时间
#include <QDebug>	//打印调试
#include <QFont>	//字体

class SystemTimerDlg :
	public QDialog
{
	Q_OBJECT	//moc
public:
	SystemTimerDlg();
	~SystemTimerDlg();
public slots:
	void acquireSysTime(); //获取系统时间
private:
	QLabel* m_Label;	//显示时间label
	QPushButton* m_Button;	//显示时间button
};

#endif  //__SYSTEMTIMERDLG_H__

