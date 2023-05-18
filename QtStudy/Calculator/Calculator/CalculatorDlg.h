#ifndef __CALCULATORDLG_H__
#define __CALCULATORDLG_H__

#pragma once
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>	//行编辑控件
#include <QHBoxLayout>	//水平布局控件
#include <QDoubleValidator>	//验证器控件

class CalculatorDlg :
	public QDialog
{
	Q_OBJECT	//moc
public:
	CalculatorDlg(void);
	~CalculatorDlg(void);
public slots:	//槽函数
	//使能等号按钮
	void enableButton(void);
	//计算结果并显示
	void calcClicked(void);
private:
	QLineEdit* m_EditX;	//左操作数
	QLineEdit* m_EditY;	//右操作数
	QLineEdit* m_EditZ;	//结果
	QLabel* m_Label; //"+"
	QPushButton* m_Button; //"="
};

#endif  //__CALCULATORDLG_H__

