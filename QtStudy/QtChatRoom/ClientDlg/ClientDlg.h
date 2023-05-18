#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClientDlg.h"
#include <QTcpSocket>
#include <QHostAddress>

class ClientDlg : public QMainWindow
{
    Q_OBJECT

public:
    ClientDlg(QWidget *parent = Q_NULLPTR);

private slots:
	void on_pushButtonConnect_clicked();
	void on_pushButtonSend_clicked();
	void onConnected();
	void onDisconnected();
	void onReadyRead();
	void onError();

private:
    Ui::ClientDlgClass ui;
	QTcpSocket m_socket;
	QString m_strNickname;
	QHostAddress m_serverIP;
	quint16 m_serverPort;
	bool m_bState;	//Client online or offline
};
