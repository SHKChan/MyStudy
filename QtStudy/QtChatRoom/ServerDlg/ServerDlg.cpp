#include "ServerDlg.h"

ServerDlg::ServerDlg(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(&m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void ServerDlg::on_pushButtonCreate_clicked()
{
	//Read port and create server
	QString port = ui.lineEditPort->text();
	if (m_server.listen(QHostAddress::Any, port.toShort()))
	{
		ui.listWidget->addItem("System: Server created.");
		QString address = m_server.serverAddress().toString() + " : " + port;
		ui.listWidget->addItem("System: Server address: " + address);

		m_timer.start(5000);
		ui.lineEditPort->setEnabled(false);
		ui.labelPort->setEnabled(false);
	}
	else
		ui.listWidget->addItem("System:  Server creation fail.");

}

void ServerDlg::sendMessage(QByteArray buf)
{
	//Loop the server list to send message
	for (int i = 0; i < m_clientList.size(); i++)
		m_clientList.at(i)->write(buf);
}

void ServerDlg::onNewConnection()
{
	QTcpSocket* clientSocket = m_server.nextPendingConnection();
	m_clientList.append(clientSocket);
	QString address = clientSocket->peerAddress().toString();
	quint16 port = clientSocket->localPort();
	ui.listWidget->addItem(QString("System: New client connected: " + address + ": %1").arg(port));
	connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void ServerDlg::onReadyRead()
{
	//Loop the server list to receive message
	for (int i = 0; i < m_clientList.size(); i++)
	{
		if (m_clientList.at(i)->bytesAvailable())
		{
			QByteArray buf = m_clientList.at(i)->readAll();
			ui.listWidget->addItem(buf);
			ui.listWidget->scrollToBottom();
			sendMessage(buf);
		}
	}
}

void ServerDlg::onTimeout()
{
	//Loop the server list to receive message
	for (int i = m_clientList.size()-1; i > 0 ; i--)
	{
		if (QAbstractSocket::UnconnectedState == m_clientList.at(i)->state())
			m_clientList.removeAt(i);
	}
}
