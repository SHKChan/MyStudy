#include "CalculatorDlg.h"

CalculatorDlg::CalculatorDlg(void)
{
	/************************************************************************/
	/*�����ʼ��                                                                      */
	/************************************************************************/
	setWindowTitle("Calculator");	//���ô��ڱ���
	//�������, thisΪ��ǰ������ָ��
	m_EditX = new QLineEdit(this);
	//�����ı����뷽ʽ
	m_EditX->setAlignment(Qt::AlignRight);
	//����������֤��, ֻ������������ʽ����
	m_EditX->setValidator(new QDoubleValidator(this));

	//�Ҳ�����
	m_EditY = new QLineEdit(this);
	m_EditY->setAlignment(Qt::AlignRight);
	m_EditY->setValidator(new QDoubleValidator(this));
	
	//���
	m_EditZ = new QLineEdit(this);
	m_EditZ->setAlignment(Qt::AlignRight);
	//����ֻ��
	m_EditZ->setReadOnly(true);
	
	//"+"
	m_Label = new QLabel("+");
	//"="
	m_Button = new QPushButton("=");
	//���ý���
	m_Button->setEnabled(false);

	//�����������ؼ����Զ��������ؼ���С��λ��
	QHBoxLayout* layout = new QHBoxLayout(this);
	//��ˮƽ���� ������ӿؼ�
	layout->addWidget(m_EditX);
	layout->addWidget(m_Label);
	layout->addWidget(m_EditY);
	layout->addWidget(m_Button);
	layout->addWidget(m_EditZ);
	//���ò�����
	setLayout(layout);

	/************************************************************************/
	/*�ź���۵�����                                                                      */
	/************************************************************************/
	//���Ҳ������ı��ı�ʱ, �����ź�textChanged
	connect(m_EditX, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	connect(m_EditY, SIGNAL(textChanged(QString)), this, SLOT(enableButton(void)));
	//"="��ť���ʱ, �����ź�clicked
	connect(m_Button, SIGNAL(clicked(void)), this, SLOT(calcClicked(void)));
}

CalculatorDlg::~CalculatorDlg(void)
{
}

void CalculatorDlg::enableButton(void)
{
	bool bXOK = false, bYOK = false;
	//text():��ȡ�����ı�(QString)
	//toDouble():QStringת��Ϊdouble, ��������ת���Ƿ�ɹ�
	m_EditX->text().toDouble(&bXOK);
	m_EditY->text().toDouble(&bYOK);
	//����Ϊ��, ʹ�ܵȺŰ�ť
	m_Button->setEnabled(bXOK && bYOK);
}

void CalculatorDlg::calcClicked(void)
{
	double res = m_EditX->text().toDouble() + \
		m_EditY->text().toDouble();
	//number()::��doubleת��ΪQString
	QString str = QString::number(res);
	//��ʾQString���
	m_EditZ->setText(str);
}
