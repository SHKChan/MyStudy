#include "ErnieDlg.h"

ErnieDlg::ErnieDlg(QWidget *parent)
    : QDialog(parent)
	, m_bIsGo(false)
	//, m_nIdx(0)
	//, m_timerIdx(0)
{
    ui.setupUi(this);
	//去除"?", 添加"-"&"□"
	Qt::WindowFlags windowFlag = Qt::Dialog;
	windowFlag |= Qt::WindowMinimizeButtonHint;
	windowFlag |= Qt::WindowMaximizeButtonHint;
	windowFlag |= Qt::WindowCloseButtonHint;
	setWindowFlags(windowFlag);

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

	//Random seed
	qsrand(QTime::currentTime().msec());
	loadImages("./Anime");
	qDebug("Loaded image number: %d", m_imgVector.size());
	m_nIdx = qrand() % m_imgVector.size();
}

void ErnieDlg::loadImages(const QString &path)
{
	QDir dir(path);

	//Loop all images under current folder
	QStringList mainList = dir.entryList(QDir::Files);
	for (int i = 0; i< mainList.size(); i++)
	{
		QImage image(path + "/" + mainList[i]);
		m_imgVector.push_back(image);
	}
	//Loop all images under sub-folder
	QStringList subList = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
	for (int i = 0; i < subList.size(); i++)
	{
		loadImages(path + "/" + subList[i]);
	}
}

//void ErnieDlg::timerEvent(QTimerEvent *event)
//{
//	m_nIdx = qrand() % m_imgVector.size();
//	update();
//}

void ErnieDlg::paintEvent(QPaintEvent *event)
{
	ui.frame->installEventFilter(this);        //安装事件过滤器到窗口
	QPainter painter(ui.frame);
	QRect rect = ui.frame->frameRect();
	painter.drawImage(rect, m_imgVector[m_nIdx]);
}

void ErnieDlg::onTimeout()
{
	m_nIdx = qrand() % m_imgVector.size();
	update();
}

bool ErnieDlg::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == ui.frame  && event->type() == QEvent::Paint)
	{
		paintEvent((QPaintEvent *)event); //响应函数
	}
	return QWidget::eventFilter(watched, event);
}

void ErnieDlg::on_pushButton_clicked()
{
	m_bIsGo = !m_bIsGo;
	//if (m_bIsGo)
	//{
	//	m_timerIdx = startTimer(25);
	//	ui.pushButton->setText("Stop");
	//}
	//else
	//	killTimer(m_timerIdx);

	if (m_bIsGo)
	{
		m_timer.start(25);
	}
	else
		m_timer.stop();
}
