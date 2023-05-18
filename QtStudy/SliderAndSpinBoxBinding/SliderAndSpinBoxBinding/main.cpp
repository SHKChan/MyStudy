#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	//父窗口
	QDialog parentWnd;
	parentWnd.resize(200, 50);
	//滑块
	QSlider slider(Qt::Horizontal, &parentWnd);
	slider.setRange(0, 99);
	slider.setValue(0);
	slider.move(25, 15);
	//数值框
	QSpinBox spinBox(&parentWnd);
	spinBox.setRange(0, 99);
	spinBox.setValue(0);
	spinBox.move(125, 15);
	//绑定两者
	QObject::connect(&slider, SIGNAL(valueChanged(int)), &spinBox, SLOT(setValue(int)));
	QObject::connect(&spinBox, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));

	parentWnd.show();

	return app.exec();
}