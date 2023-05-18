#include "SystemTimerDlg.h"
#include <QApplication>

int main(int argv, char** argc)
{
	QApplication app(argv, argc);

	SystemTimerDlg sysTimerDlg;
	sysTimerDlg.show();

	return app.exec();
}