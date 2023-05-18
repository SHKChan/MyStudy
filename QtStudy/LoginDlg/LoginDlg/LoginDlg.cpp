#include "LoginDlg.h"

LoginDlg::LoginDlg(QString username, QString password)
	: m_pUi(new Ui_LoginDlg)
{
	//Ui and Layout
	m_pUi->setupUi(this);
	m_strUsername = username;
	m_strPassword = password;
	//Connect
	connect(m_pUi->m_buttonBox, SIGNAL(accepted()), this, SLOT(onAccepted()));
	connect(m_pUi->m_buttonBox, SIGNAL(rejected()), this, SLOT(onRejected()));
}

LoginDlg::LoginDlg()
	: m_pUi(new Ui_LoginDlg)
{
	//Ui and Layout
	m_pUi->setupUi(this);
	m_strUsername = "";
	m_strPassword = "";
}

LoginDlg::~LoginDlg()
{
	delete m_pUi;
}

void LoginDlg::onAccepted(void)
{
	if (m_strPassword == m_pUi->m_editPassword->text() && m_strUsername == m_pUi->m_editUsername->text())
	{
		qDebug("Login success.");
		QMessageBox msgBox(QMessageBox::Information, "Login", "Login success.", QMessageBox::Ok, this);
		msgBox.exec();
		close();
	}
	else
	{
		//Icon, Title, Message, Button, Parent Window
		QMessageBox msgBox(QMessageBox::Critical, "Error", "Username or password do not matched!", QMessageBox::Ok, this);
		if (QMessageBox::Ok == msgBox.exec())
		{
			qDebug("Username or password error.");
			msgBox.exec();
		}
	}
}

void LoginDlg::onRejected(void)
{
	QMessageBox msgBox(QMessageBox::Question, "Login", "Exit login?", QMessageBox::Yes | QMessageBox::No, this);
	if (QMessageBox::Yes == msgBox.exec())
	{
		qDebug("Exit login");
		close();
	}
}