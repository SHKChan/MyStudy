#include <QApplication>
#include "CalculatorDlg.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	CalculatorDlg calcDlg;
	calcDlg.show();

	return app.exec();
}