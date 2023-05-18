#ifndef __CALCULATORDLG_H__
#define __CALCULATORDLG_H__

#pragma once
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>	//�б༭�ؼ�
#include <QHBoxLayout>	//ˮƽ���ֿؼ�
#include <QDoubleValidator>	//��֤���ؼ�

class CalculatorDlg :
	public QDialog
{
	Q_OBJECT	//moc
public:
	CalculatorDlg(void);
	~CalculatorDlg(void);
public slots:	//�ۺ���
	//ʹ�ܵȺŰ�ť
	void enableButton(void);
	//����������ʾ
	void calcClicked(void);
private:
	QLineEdit* m_EditX;	//�������
	QLineEdit* m_EditY;	//�Ҳ�����
	QLineEdit* m_EditZ;	//���
	QLabel* m_Label; //"+"
	QPushButton* m_Button; //"="
};

#endif  //__CALCULATORDLG_H__

