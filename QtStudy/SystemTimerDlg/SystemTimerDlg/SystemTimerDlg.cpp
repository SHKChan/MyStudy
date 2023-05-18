#include "SystemTimerDlg.h"

SystemTimerDlg::SystemTimerDlg()
{
	//////////////////////////////////////////////////////////////////////////
	//Initialize UI
	m_Label = new QLabel(this);
	//Set label display effect
	m_Label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
	m_Label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	
	//Set font style
	QFont font;
	font.setPointSize(20);
	m_Label->setFont(font);

	//Button to acquire system time
	m_Button = new QPushButton("Acquire Current Time", this);
	m_Button->setFont(font);
	//Set vertical Layout
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(m_Label);
	layout->addWidget(m_Button);
	setLayout(layout);

	//////////////////////////////////////////////////////////////////////////
	//Signal and slot
	connect(m_Button, SIGNAL(clicked()), this, SLOT(acquireSysTime()));
}

SystemTimerDlg::~SystemTimerDlg()
{
}

void SystemTimerDlg::acquireSysTime()
{
	qDebug("Acquire Time");
	//qDebug() << "Acquire Time";
	//Acquire current time
	QTime time = QTime::currentTime();
	//Transform QTime to QString
	QString str = time.toString("HH:mm:ss ap");
	m_Label->setText(str);
}
