#pragma once

#include <QtWidgets/QDialog>
#include "ui_ErnieDlg.h"
#include <QTimer>
#include <QPainter>
#include <QDir>
#include <QTime>
#include <QVector>
#include <QImage>
#include <QDebug>

class ErnieDlg : public QDialog
{
    Q_OBJECT

public:
    ErnieDlg(QWidget *parent = Q_NULLPTR);

private:
	bool eventFilter(QObject *watched, QEvent *event);
	void loadImages(const QString &path);
	//void timerEvent(QTimerEvent *event);
	void paintEvent(QPaintEvent *event);

private slots:
	void on_pushButton_clicked();
	void onTimeout();

private:
    Ui::ErnieDlgClass ui;
	bool m_bIsGo;
	QVector<QImage> m_imgVector;	//Container to store images\
	dynamic size.
	int m_nIdx;	// Image's index within container
	QTimer m_timer;
	//int m_timerIdx;
};
