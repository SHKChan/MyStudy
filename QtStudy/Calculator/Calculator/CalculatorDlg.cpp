#include "CalculatorDlg.h"

CalculatorDlg::CalculatorDlg(void)
{
	/************************************************************************/
	/*界面初始化                                                                      */
	/************************************************************************/
	setWindowTitle("Calculator");	//设置窗口标题
	//左操作数, this为当前父窗口指针
	m_EditX = new QLineEdit(this);
	//设置文本对齐方式
	m_EditX->setAlignment(Qt::AlignRight);
	//设置数字验证器, 只能输入数字形式内容
	m_EditX->setValidator(new QDoubleValidator(this));

	//右操作数
	m_EditY = new QLineEdit(this);
	m_EditY->setAlignment(Qt::AlignRight);
	m_EditY->setValidator(new QDoubleValidator(this));
	
	//结果
	m_EditZ = new QLineEdit(this);
	m_EditZ->setAlignment(Qt::AlignRight);
	//设置只读
	m_EditZ->setReadOnly(true);
	
	//"+"
	m_Label = new QLabel("+");
	//"="
	m_Button = new QPushButton("=");
	//设置禁用
	m_Button->setEnabled(false);

	//创建布局器控件：自动调整各控件大小和位置
	QHBoxLayout* layout = new QHBoxLayout(this);
	//按水平方向， 依次添加控件
	layout->addWidget(m_EditX);
	layout->addWidget(m_Label);
	layout->addWidget(m_EditY);
	layout->addWidget(m_Button);
	layout->addWidget(m_EditZ);
	//设置布局器
	setLayout(layout);

	/************************************************************************/
	/*信号与槽的连接                                                                      */
	/************************************************************************/
	//左右操作数文本改变时, 发送信号textChanged
	connect(m_EditX, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	connect(m_EditY, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	//"="按钮点击时, 发送信号clicked
	connect(m_Button, SIGNAL(clicked(void)), this, SLOT(calcClicked(void)));
}

CalculatorDlg::~CalculatorDlg(void)
{
}

void CalculatorDlg::enableButton(void)
{
	bool bXOK = false, bYOK = false;
	//text():获取输入文本(QString)
	//toDouble():QString转换为double, 参数保存转换是否成功
	m_EditX->text().toDouble(&bXOK);
	m_EditY->text().toDouble(&bYOK);
	//若都为真, 使能等号按钮
	m_Button->setEnabled(bXOK && bYOK);
}

void CalculatorDlg::calcClicked(void)
{
	double res = m_EditX->text().toDouble() + \
		m_EditY->text().toDouble();
	//number()::将double转换为QString
	QString str = QString::number(res);
	//显示QString结果
	m_EditZ->setText(str);
}
