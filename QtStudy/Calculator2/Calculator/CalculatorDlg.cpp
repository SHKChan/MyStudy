#include "CalculatorDlg.h"

CalculatorDlg::CalculatorDlg(void)
	: m_pUi(new Ui::CalculatorDlg)
{
	/************************************************************************/
	/*�����ʼ��                                                                      */
	/************************************************************************/
	m_pUi->setupUi(this);
	m_pUi->m_EditX->setValidator(new QDoubleValidator(this));
	m_pUi->m_EditY->setValidator(new QDoubleValidator(this));

	/************************************************************************/
	/*�ź���۵�����                                                                      */
	/************************************************************************/
	//���Ҳ������ı��ı�ʱ, �����ź�textChanged
	connect(m_pUi->m_EditX, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	connect(m_pUi->m_EditY, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	//"="��ť���ʱ, �����ź�clicked
	connect(m_pUi->m_Button, SIGNAL(clicked(void)), this, SLOT(calcClicked(void)));
}

CalculatorDlg::~CalculatorDlg(void)
{
	delete m_pUi;
	m_pUi = NULL;
}

void CalculatorDlg::enableButton(void)
{
	bool bXOK = false, bYOK = false;
	//text():��ȡ�����ı�(QString)
	//toDouble():QStringת��Ϊdouble, ��������ת���Ƿ�ɹ�
	m_pUi->m_EditX->text().toDouble(&bXOK);
	m_pUi->m_EditY->text().toDouble(&bYOK);
	//����Ϊ��, ʹ�ܵȺŰ�ť
	m_pUi->m_Button->setEnabled(bXOK && bYOK);
}

void CalculatorDlg::calcClicked(void)
{
	double res = m_pUi->m_EditX->text().toDouble() + \
		m_pUi->m_EditY->text().toDouble();
	//number()::��doubleת��ΪQString
	QString str = QString::number(res);
	//��ʾQString���
	m_pUi->m_EditZ->setText(str);
}
