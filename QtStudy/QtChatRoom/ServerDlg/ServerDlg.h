#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ServerDlg.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

class ServerDlg : public QMainWindow
{
    Q_OBJECT

public:
    ServerDlg(QWidget *parent = Q_NULLPTR);

private:
	void sendMessage(QByteArray buf);

private slots:
	void on_pushButtonCreate_clicked();
	void onNewConnection();
	void onReadyRead();
	void onTimeout();

private:
    Ui::ServerDlgClass ui;
	QTcpServer m_server;
	QList<QTcpSocket*> m_clientList;
	QTimer m_timer;
};
