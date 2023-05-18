#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDialog>

int main(int argc, char *argv[])
{
	//argc 命令行参数个数, argv 命令行参数值
	
	//创建Qt应用程序对象
	QApplication app(argc, argv);
	
	//QWidget partentWnd;
	QDialog partentWnd;
	//QMainWindow partentWnd;
	partentWnd.move(50, 50);
	partentWnd.resize(320, 240);

	//创建标签控件
	// new对象若指定了父窗口子针, 可以不写delete, 会随父窗口自\
	动销毁
	QLabel label("Hello, Qt!", &partentWnd);
	//显示标签控件
	//label.show();
	label.move(20, 40);
	//label.resize(80, 80);

	//按键控件
	QPushButton pushButton("This is a button.", &partentWnd);
	//pushButton.show();
	pushButton.move(20, 100);
	pushButton.resize(150, 40);
	
	//当父窗口显示时, 其上的子控件也将一并显示
	partentWnd.show();
	
	//让应用程序进入事件循环
	return app.exec();	
}
