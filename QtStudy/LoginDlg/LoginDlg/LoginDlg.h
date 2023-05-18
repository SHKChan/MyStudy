#ifndef __LOGINDLG_H__
#define __LOGINDLG_H__

#pragma once

#include <QMessageBox>
#include <QDebug>
#include "Ui_LoginDlg.h"

class LoginDlg :
	public QDialog
{
	Q_OBJECT
public:
	LoginDlg(QString username, QString password);
	LoginDlg();
	~LoginDlg();
public slots:
	void onAccepted(void);
	void onRejected(void);
private:
	Ui_LoginDlg* m_pUi;
	QString m_strUsername;
	QString m_strPassword;
};

#endif  //__LOGINDLG_H__