#ifndef __SYSTEMTIMERDLG_H__
#define __SYSTEMTIMERDLG_H__

#pragma once
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>	//��ֱ�������ؼ�
#include <QTime>	//ʱ��
#include <QDebug>	//��ӡ����
#include <QFont>	//����

class SystemTimerDlg :
	public QDialog
{
	Q_OBJECT	//moc
public:
	SystemTimerDlg();
	~SystemTimerDlg();
public slots:
	void acquireSysTime(); //��ȡϵͳʱ��
private:
	QLabel* m_Label;	//��ʾʱ��label
	QPushButton* m_Button;	//��ʾʱ��button
};

#endif  //__SYSTEMTIMERDLG_H__

