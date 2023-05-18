#include <QtWidgets\QApplication>
#include <QtWidgets\QLabel>
#include <QtWidgets\QPushButton>
#include <QtWidgets\QDialog>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QDialog parentWnd;
	parentWnd.resize(320, 240);

	QLabel label("I am label.", &parentWnd);
	label.move(50, 40);
	QPushButton pushButton("I am button.", &parentWnd);
	pushButton.move(50, 100);
	
	QPushButton pushButton2("I am exit button.", &parentWnd);
	pushButton2.move(150, 100);
	parentWnd.show();

	//���ź���۽��а� 
	//ʵ�ֵ����ť�رձ�ǩ�Ĺ���
	QObject::connect(&pushButton, SIGNAL(clicked(void)), &label, SLOT(close(void)));
	//�����ť�˳�Ӧ�ó���
	QObject::connect(&pushButton2, SIGNAL(clicked(void)), &app, SLOT(closeAllWindows(void)));

	return app.exec();
}