#include "ClientDlg.h"

ClientDlg::ClientDlg(QWidget *parent)
	: QMainWindow(parent)
	, m_strNickname("Anonymous")
	, m_bState(false)
{
    ui.setupUi(this);
	connect(&m_socket, SIGNAL(connected()), this, SLOT(onConnected()));
	connect(&m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
	connect(&m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
	connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError()));
}

void ClientDlg::on_pushButtonConnect_clicked()
{
	//Disconnect from server
	if (m_bState)
	{
		QString msg = "System: " + m_strNickname + " disconnects to server.";
		m_socket.write(msg.toUtf8());
		m_socket.disconnectFromHost();
		return;
	}

	//Read server IP, port and do connection
	m_serverIP.setAddress(ui.lineEditIP->text());
	m_serverPort= ui.lineEditPort->text().toShort();
	if (!(ui.lineEditNickname->text().isEmpty()))
		m_strNickname= ui.lineEditNickname->text();

	//signal connected when connect success, 
	//signal error when connect fail, 
	m_socket.connectToHost(m_serverIP, m_serverPort);
}

void ClientDlg::on_pushButtonSend_clicked()
{
	if (ui.lineEditSend->text().isEmpty())
		return;
	QString msg = m_strNickname + ": " + ui.lineEditSend->text();
	m_socket.write(msg.toUtf8());
	ui.lineEditSend->clear();
}

void ClientDlg::onConnected()
{
	m_bState = true;
	ui.listWidget->addItem("Server connected.");
	ui.lineEditIP->setEnabled(false);
	ui.lineEditPort->setEnabled(false);
	ui.lineEditNickname->setEnabled(false);
	ui.pushButtonSend->setEnabled(true);
	ui.pushButtonConnect->setText("DisconnectFromServer");
	QString msg = "System: " + m_strNickname + " connects to server.";
	m_socket.write(msg.toUtf8());
}

void ClientDlg::onDisconnected()
{
	m_bState = false;
	ui.listWidget->addItem("Server disconnected.");
	ui.lineEditIP->setEnabled(true);
	ui.lineEditPort->setEnabled(true);
	ui.lineEditNickname->setEnabled(true);
	ui.pushButtonSend->setEnabled(false);
	ui.pushButtonConnect->setText("ConnectToServer");
}

void ClientDlg::onReadyRead()
{
	if (m_socket.bytesAvailable())
	{
		QByteArray buf = m_socket.readAll();
		ui.listWidget->addItem(buf);
		ui.listWidget->scrollToBottom();
	}
}

void ClientDlg::onError()
{
	ui.listWidget->addItem("System: " + m_socket.errorString());
	ui.listWidget->scrollToBottom();
}