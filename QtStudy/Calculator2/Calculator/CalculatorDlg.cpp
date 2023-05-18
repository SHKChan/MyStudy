#include "CalculatorDlg.h"

CalculatorDlg::CalculatorDlg(void)
	: m_pUi(new Ui::CalculatorDlg)
{
	/************************************************************************/
	/*界面初始化                                                                      */
	/************************************************************************/
	m_pUi->setupUi(this);
	m_pUi->m_EditX->setValidator(new QDoubleValidator(this));
	m_pUi->m_EditY->setValidator(new QDoubleValidator(this));

	/************************************************************************/
	/*信号与槽的连接                                                                      */
	/************************************************************************/
	//左右操作数文本改变时, 发送信号textChanged
	connect(m_pUi->m_EditX, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	connect(m_pUi->m_EditY, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	//"="按钮点击时, 发送信号clicked
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
	//text():获取输入文本(QString)
	//toDouble():QString转换为double, 参数保存转换是否成功
	m_pUi->m_EditX->text().toDouble(&bXOK);
	m_pUi->m_EditY->text().toDouble(&bYOK);
	//若都为真, 使能等号按钮
	m_pUi->m_Button->setEnabled(bXOK && bYOK);
}

void CalculatorDlg::calcClicked(void)
{
	double res = m_pUi->m_EditX->text().toDouble() + \
		m_pUi->m_EditY->text().toDouble();
	//number()::将double转换为QString
	QString str = QString::number(res);
	//显示QString结果
	m_pUi->m_EditZ->setText(str);
}
